//
//  Parte.h
//  PROGRAMA 2
//
//  Created by Juan Pestana on 9/18/17.
//  Copyright © 2017 DPSoftware. All rights reserved.
//
//=p-Parte
// Clase de Parte. Tiene nombre, items, base, deleted, modified, added y total.
//=b-40



#ifndef Parte_h
#define Parte_h

using namespace std;


class Parte//=m
{
    
public:
    
    // CONSTRUCTORES
    Parte();//=m
    Parte(string sNombre, int iItems, int iBase, int iDeleted, int iModified, int iAdded, int iTotal);//=m
    
    // SETS
    void setNombre(string sNombre);
    void setItems(int iItems);//=m
    void setBase(int iBase);//=m
    void setDeleted(int iDeleted);
    void setModified(int iModified);
    void setAdded(int iAdded);
    void setTotal(int iTotal);

    
    // GETS
    string getNombre();
    int getItems();//=m
    int getBase();//=m
    int getDeleted();
    int getModified();
    int getAdded();
    int getTotal();

private:
    
    // VARIABLES
    string sNombre;
    int iItems;//=m
    int iBase;//=m
    int iDeleted;
    int iModified;
    int iAdded;
    int iTotal;

};



// CONSTRUCTOR DEFAULT
Parte :: Parte()//=m
{
    
    sNombre = "";
    iItems = 0;//=m
    iBase = 0;//=m
    iDeleted = 0;
    iModified = 0;
    iAdded = 0;
    iTotal = 0;

}// END CONSTRUCTOR DEFAULT


// CONSTRUCTOR CON PARAMETROS
Parte :: Parte(string sNombre, int iItems, int iBase, int iDeleted, int iModified, int iAdded, int iTotal)//=m
{
    
    this->sNombre = sNombre;
    this->iItems = iItems;//=m
    this->iBase = iBase;//=m
    this->iDeleted = iDeleted;
    this->iModified = iModified;
    this->iAdded = iAdded;
    this->iTotal = iTotal;

}// END CONSTRUCTOR CON PARAMETROS




// SETS
void Parte :: setNombre(string sNombre)
{
    
    this->sNombre = sNombre;
    
}// END NOMBRE


void Parte :: setItems(int iItems)//=m
{

    this->iItems = iItems;//=m

}// END ITEMS

void Parte :: setBase(int iBase)//=m
{

    this->iBase = iBase;//=m

}// END BASE

void Parte :: setDeleted(int iDeleted)
{
    
    this->iDeleted = iDeleted;
    
}// END DELETED

void Parte :: setAdded(int iAdded)
{
    
    this->iAdded = iAdded;
    
}// END ADDED

void Parte :: setModified(int iModified)
{
    
    this->iModified = iModified;
    
}// END MODIFIED

void Parte :: setTotal(int iTotal)
{

    this->iTotal = iTotal;

}// END TOTAL



// GETS
string Parte :: getNombre()
{
    return sNombre;
}

int Parte :: getItems()//=m
{
    return iItems;//=m
}

int Parte :: getBase()//=m
{
    return iBase;//=m
}

int Parte :: getDeleted()
{
    return iDeleted;
}

int Parte :: getModified()
{
    return iModified;
}


int Parte :: getAdded()
{
    return iAdded;
}

int Parte :: getTotal()
{
    return iTotal;
}

#endif /* Parte_h */
