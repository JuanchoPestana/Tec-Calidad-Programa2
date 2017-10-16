//
//  Control.h
//  PROGRAMA 2
//
//  Created by Juan Pestana on 9/18/17.
//  Copyright © 2017 DPSoftware. All rights reserved.
//
//=p-Control
// Clase de Control. Tiene metodos para revisar, imprimr y pegar.
//=b-60

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Parte.h"

using namespace std;

#ifndef Control_h
#define Control_h


class Control
{
    
    
public:

    // CONSTRUCTORES
    Control();
    Control(Parte parte);//=m
    
    // METODOS
    void revisar(string sNombre);
    void imprimir();
    void pegar();
    
private:
    
    // VARIABLES
    vector<Parte> vLista;//=m
    int iTotal;
    ifstream ArchivoEntrada;
    
};


// CONSTRUCTOR DEFAULT
Control :: Control()
{
    vLista.push_back(*new Parte);
    iTotal = 0;
    
}

// CONSTRUCTOR CON OBJETO
Control :: Control(Parte parte)//=m
{
    vLista.push_back(parte);//=m
}


// FUNCION QUE HACE LAS CUENTAS
//=i
void Control :: revisar(string sNombre)
{
    
    
    ArchivoEntrada.open(sNombre);
    
    if (ArchivoEntrada.is_open())
    {
        Parte parte = *new Parte();
        string p;
        
        string sNombre = "";
        int iBase = 0;
        int iDeleted = 0;
        int iModified = 0;
        int iItems = 0;
        int added = 0;
        int iTotalp = 0;//=m

        
        
        bool comentario = false;

        // WHILE QUE VA LINEA POR LINEA
        while (getline(ArchivoEntrada, p))
        {
            p.erase(std::remove(p.begin(), p.end(), ' '), p.end());
            p.erase(std::remove(p.begin(), p.end(), '\n'), p.end());
            p.erase(std::remove(p.begin(), p.end(), '\r'), p.end());
            p.erase(std::remove(p.begin(), p.end(), '\t'), p.end());
            p.erase(std::remove(p.begin(), p.end(), '{'), p.end());
            p.erase(std::remove(p.begin(), p.end(), '}'), p.end());
            
            
            size_t comilla1 = p.find('"');
            if(p[0] == '/' && p[1] == '*')
            {
                comentario= true;
            }
            
         
            while(comilla1 != string::npos)
            {
                p.erase(comilla1,1);
                size_t comilla2 = p.find('"');
                p.erase(comilla1,comilla2-comilla1+1);
                comilla1 = p.find('"');
            }
            
            
            if(!comentario)
            {
                if(!p.empty())
                {
                    
                    size_t encontroParte = p.find("//=p-");
                    size_t encontroItem = p.find("//=i");
                    size_t encontroBase = p.find("//=b-");
                    size_t encontroDeleted = p.find("//=d-");
                    size_t encontroIteModified = p.find("//=m");
                    
                    if(encontroItem != string::npos)
                    {
                        iItems++;
                    }else if(encontroIteModified != string::npos)
                    {
                        iModified++;
                    }else if(encontroDeleted != string::npos)
                    {
                        string sTemporal = "";
                        std::size_t i = encontroDeleted + 5;
                        
                        
                        while(p[i] == '0' || p[i] == '1' || p[i] == '2' || p[i] == '3' || p[i] == '4' || p[i] == '5' || p[i] == '6' || p[i] == '7' || p[i] == '8' || p[i] == '9' )
                        {
                            sTemporal+= p[i];
                            i++;
                        }
                        
                        iDeleted+= stoi(sTemporal);
                        
                    }else if(encontroBase != string::npos)
                    {
                        string sTemporal = "";
                        std::size_t i = encontroBase + 5;
                        
                        
                        while(p[i] == '0' || p[i] == '1' || p[i] == '2' || p[i] == '3' || p[i] == '4' || p[i] == '5' || p[i] == '6' || p[i] == '7' || p[i] == '8' || p[i] == '9' )
                        {
                            sTemporal+= p[i];
                            i++;
                        }
                        iBase+= stoi(sTemporal);
                        
                    }else if(encontroParte != string::npos)
                    {
                        
                        string sTemporal = p.substr(encontroParte + 5);
                        
                        
                        if(sNombre == "")
                        {
                            sNombre = sTemporal;
                        
                        }else if(sNombre != sTemporal)
                        {
                            parte.setNombre(sNombre);
                            parte.setBase(iBase);
                            parte.setDeleted(iDeleted);
                            parte.setTotal(iTotalp);
                            parte.setItems(iItems);
                            parte.setModified(iModified);
                            
                            added = iTotalp - iBase + iDeleted;
                            parte.setAdded(added);
                            
                            
                            vLista.push_back(parte);
                            
                            sNombre=sTemporal;
                            iBase = 0;
                            iDeleted = 0;
                            added = 0;
                            iItems = 0;
                            iModified = 0;
                            iTotalp = 0;
                        }
                        
                    }
                    
                    if(p[0] != '/' && p[1] != '/')
                    {
                        iTotal++;
                        
                        if(sNombre != "")
                        {
                            iTotalp++;
                            
                        }
                    }
                }
            }else{
                
                size_t encontroC = p.find("*/");
                if(encontroC != string::npos)
                {
                    comentario = false;
                }
            }
        }
        
        parte.setNombre(sNombre);
        parte.setBase(iBase);
        parte.setDeleted(iDeleted);
        parte.setTotal(iTotalp);
        parte.setItems(iItems);
        parte.setModified(iModified);
        added = iTotalp - iBase + iDeleted;
        parte.setAdded(added);
        
        vLista.push_back(parte);
        ArchivoEntrada.close();
    
    
    }else
    {
        cout << "EL ARCHIVO SOLICITADO NO EXISTE" << endl;
    }
}


// FUNCION QUE DESPLIEEGA TOTALES
//=i
void Control :: imprimir()
{
    //=d-2
    
    ofstream outputFile("ConteoLDC.txt");
    pegar();
    
    cout << "PARTES BASE:" << endl;
    outputFile << "PARTES BASE:" << endl;
    
    for (int iC = 1; iC < vLista.size(); iC++)
    {
        //=d=1
        if (vLista[iC].getBase() > 0 && (vLista[iC].getModified() > 0 || vLista[iC].getDeleted() > 0 || vLista[iC].getAdded() > 0))
        {
            
            cout << vLista[iC].getNombre() << ": " << "T=" << vLista[iC].getTotal() << ", I=" << vLista[iC].getItems() << ", B=" << vLista[iC].getBase() << ", D=" << vLista[iC].getDeleted() <<  ", M=" << vLista[iC].getModified() <<  ", A=" << vLista[iC].getAdded() << endl;
            
            outputFile << vLista[iC].getNombre() << ": " << "T=" << vLista[iC].getTotal() << ", I=" << vLista[iC].getItems() << ", B=" << vLista[iC].getBase() << ", D=" << vLista[iC].getDeleted() <<  ", M=" << vLista[iC].getModified() <<  ", A=" << vLista[iC].getAdded() << endl;
            
            vLista.erase(vLista.begin()+iC);
            iC--;
            
        }
    }
    cout << "----------------------------------" << endl;
    outputFile << "----------------------------------" << endl;
    
    
    cout << "PARTES NUEVAS:" << endl;
    outputFile << "PARTES NUEVAS:" << endl;
    for (int iC = 1; iC < vLista.size(); iC++)
    {
        //=d=1
        if (vLista[iC].getBase() == 0 && vLista[iC].getModified() == 0 && vLista[iC].getDeleted() == 0 && vLista[iC].getAdded() > 0)
        {
            cout << vLista[iC].getNombre() << ": " << "T=" << vLista[iC].getTotal() << ", I=" << vLista[iC].getItems() << endl;
            outputFile << vLista[iC].getNombre() << ": " << "T=" << vLista[iC].getTotal() << ", I=" << vLista[iC].getItems() << endl;
            
            vLista.erase(vLista.begin()+iC);
            iC--;
            
        }
    }
    cout << "----------------------------------" << endl;
    outputFile << "----------------------------------" << endl;
    
    cout << "PARTES REUSADAS:" << endl;
    outputFile << "PARTES REUSADAS:" << endl;
    for (int iC = 1; iC < vLista.size(); iC++)
    {
        if (vLista[iC].getBase() > 0 && vLista[iC].getModified() == 0 && vLista[iC].getDeleted() == 0 && vLista[iC].getAdded() == 0)
        {
            cout << vLista[iC].getNombre() << ": " << "T=" << vLista[iC].getTotal() << ", I=" << vLista[iC].getItems() << ", B=" << vLista[iC].getBase() << endl;
            outputFile << vLista[iC].getNombre() << ": " << "T=" << vLista[iC].getTotal() << ", I=" << vLista[iC].getItems() << ", B=" << vLista[iC].getBase() << endl;
            
            vLista.erase(vLista.begin()+iC);
            iC--;
            
        }
    }
    cout << "----------------------------------" << endl;
    outputFile << "----------------------------------" << endl;
    
    
    
    cout << "Total de LDC=" << iTotal<< endl;
    outputFile << "Total de LDC=" << iTotal << endl;
}

// FUNCION QUE PEGA LAS PARTES PARA TENER UNA SOLA
//=i
void Control :: pegar()
{
    
    Parte parte = *new Parte();
    
    string sNombre = "";
    int iBase = 0;
    int iDeleted = 0;
    int iModified = 0;
    int iItems = 0;
    int added = 0;
    int iTotalp = 0;
    
    for (int ic = 1; ic<vLista.size(); ic++)
    {
        for (int iJ = ic+1; iJ<vLista.size(); iJ++)
        {
            if(vLista[ic].getNombre() == vLista[iJ].getNombre())
            {
                sNombre=vLista[ic].getNombre();
                iItems = vLista[ic].getItems() + vLista[iJ].getItems();
                iBase = vLista[ic].getBase() + vLista[iJ].getBase();
                iDeleted = vLista[ic].getDeleted() + vLista[iJ].getDeleted();
                iModified = vLista[ic].getModified() + vLista[iJ].getModified();
                iTotalp = vLista[ic].getTotal() + vLista[iJ].getTotal();
                added = vLista[ic].getAdded() + vLista[iJ].getAdded();
                
                parte.setNombre(sNombre);
                parte.setBase(iBase);
                parte.setDeleted(iDeleted);
                parte.setTotal(iTotalp);
                parte.setItems(iItems);
                parte.setModified(iModified);
                
                added = iTotalp - iBase + iDeleted;
                parte.setAdded(added);
                
                vLista[ic] = parte;
                
                vLista.erase(vLista.begin()+iJ);
                iJ--;
            }
        }
    }
}



#endif /* Control_h */
