//
//  main.cpp
//  PROGRAMA 2
//
//  Created by Juan Pestana on 9/18/17.
//  Copyright © 2017 DPSoftware. All rights reserved.
//
//=p-Main
// Clase de Main. Aqui se ingresan archivos y mandan a llamar funciones de las clases.
//=b-13

#include <iostream>
#include "Parte.h"
#include "Control.h"


int main() {

    int x;
    string nombreArchivo;
    Control *archivo = new Control();
    
    
    cout << "INTRODUCE NUMERO DE ARCHIVOS: " << endl;
    cin >> x;
    
    while (x != 0){
        
        cout << "INTRODUCE NOMBRE DE ARCHIVO: " << endl;
        cin >> nombreArchivo;
        
        archivo->revisar(nombreArchivo);
        x--;
    }// END WHILE
    
    
    archivo->imprimir();
    
    
    return 0;
}
