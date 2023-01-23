/*
Equipo: 2
Ingrid Michelle González Mendoza - A01641116
Jorge Esteban Madrigal Ramírez - A01641409
Jorge Germán Wolburg Trujillo - A01640826

Profesor: Edgar Gerardo Salinas Gurrión

Actividad Integral de BST
*/

#include "MyHashTable.cpp"
#include "MyLinkedList.cpp"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

string regString(vector<string> reg){ //Regresa el registro completo en un string 
    string completo;
    for (int i =0; i < reg.size() - 1 ; i++){
        completo  += reg[i] + " ";
    }
    completo = completo + reg[4];
    return completo;
}

int main(){
    //Se crea un vector de vectores que almacena los registros de la bitacora
    vector<vector<string> > bitacora;
    vector<string> registro;
    ifstream lector("bitacora3-1.txt");
    string linea, mes, hora, dirIP, razon, dia;
    int size = 0;
    while (getline(lector, linea)) //Recorre todas las lineas de la bitacora, separa y almacena sus contenidos 
    {
        registro.clear();

        stringstream ss(linea);
        getline(ss, mes, ' ');
        registro.push_back(mes);
        getline(ss, dia, ' ');
        registro.push_back(dia);
        getline(ss, hora, ' ');
        registro.push_back(hora);
        getline(ss, dirIP, ':');
        registro.push_back(dirIP);
        getline(ss, razon, '\n');
        registro.push_back(razon);
        bitacora[size];
        bitacora.push_back(registro);
        
        size++;

    }
    lector.close();

    MyHashTable hBitacora;

    for(int i = 0; i<bitacora.size(); i++){ // Se insertan los datos en la hashtable
        hBitacora.put(bitacora[i][3], bitacora[i][0] + " " + bitacora[i][1]+ " " + bitacora[i][2]);
    }

    MyLinkedList list; 

    string answer = "si";
    string entryIP;
    while(answer == "si"){
        cout << "Favor de ingresar la direccion IP sin puerto que desea acceder" << endl; // El usuario ingresa la direccion IP sin puerto deseada
        cin >> entryIP;

        int pos = hBitacora.getPosition(entryIP);
        list = hBitacora.getLinkL(pos);
        cout << "Llave:"<<list.first()->key << endl;
        cout << "La direccion IP: " << entryIP << " tiene " << list.length() << " accesos"<<endl;

        list.quickSort();
        hBitacora.getList(pos);
            
        cout << "Gusta ver los accesos de otra direccion IP? Responder: si / no" << endl;
        cin >> answer; // El usuario decide si quiere consultar otra direccion, en el caso de que no, el programa termina

    }
}