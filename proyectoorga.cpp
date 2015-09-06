#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/
/*--------------------------Métodos del proyecto--------------------------------*/
//netodos para cliente
void agregar_cliente();
void eliminar_cliente();
void modificar_cliente();
void listar_clientes();
void busqueda_sin_indice_cliente();
void busqueda_con_indice_cliente();
void reindexar_clientes();

//metodos para llamadas
void agregar_llamada();
void listar_llamadas();

//agregar una linea
void agregar_linea();
void eliminar_linea();
void modificar_linea();
void listar_linea();
void busqueda_con_indice_lineas();
void busqueda_sin_indice_lineas();
void reindexar_linea();

//metodos para ciudad
void agregar_ciudad();
void eliminar_ciudad();
void modificar_ciudad();
void listar_ciudad();
void busqueda_sin_indice_ciudad();
void busqueda_con_indice_ciudad();
void reindexar_ciudad();


/*------------------------------------------------------------------------------*/
/*--------------------------"Clases" del proyecto-------------------------------*/
//atributos de clientes
struct Cliente{
   int IdCliente;//de 13 digitos
   char NombreCliente[40];
   char Genero[1];
   int IdCiudad;//de 4 bytes    
};

//atributos de lineas
struct Lineas{
   int IdCliente;
   int Telefono;   
};

//atributos de ciudad
struct Ciudad{
   int IdCiudad;
   char NombreCiudad[40];   
};

//atributos de Llamadas
struct Llamadas{
   int numero;//el que llama
   int destino;//el q recibe llamada
   char fecha_inicio[14];// YYYY-MM-DD-HH-MM-SS   
};


/*--------------------------------------------------------------------------*/
/*------------------------------MAIN----------------------------------------*/

int main (int argc, char*argv[]){
    char op;
    while(true){
      cout << "Ingrese su opcion" << endl;
      cout << "1.- Sobre clientes" << endl;
      cout << "2.- Sobre ciudades" << endl;
      cout << "3.- Sobre lineas" << endl;
      cout << "4.- Sobre transacciones" << endl;
      cout << "5.- Sobre tarifas" << endl;
      cout << "6.- Salir" << endl;
      cin >> op;

      if(op=='1'){
        listar_clientes();
      }else if(op=='2'){
        listar_ciudad();
      }else if(op=='3'){
        
      }else if(op=='4'){
        
      }else if(op=='5'){
        
      }else if(op=='6'){
        cout << "Adios!" << endl;
        break;
      }else {
        cout << "Ingrese numro del 1-6, segun sus opciones" << endl;
      }
    }//while true, sale al escoger salir
    return 0;
}


/*--------------------------------------------------------------------------*/
/*----------------------Implementacion de metodos---------------------------*/


//Implementacion de metodos para cliente
//esta es la base para los demas en cuanto a si funciona...de ahi trankilo todo
void agregar_cliente(){

}

void eliminar_cliente(){

  reindexar_clientes();
}

void modificar_cliente(){

}

void listar_clientes(){
   ifstream listar("personas.txt");
   int rrn = -1;
   int cantidad_registros = 500;
   int flag = 0;
   while(!listar.eof()){
      char IdCliente[15];
      char NombreCliente[40];
      char Genero[1];
      char IdCiudad[5];
      string str1 = "", str2 = "",str3 = "",str4 = "";
      getline(listar, str1, ',');
      getline(listar, str2, ',');
      getline(listar, str3, ',');
      getline(listar, str4, ',');
      for(int i = 0; i < sizeof(IdCliente);i++){
          IdCliente[i] = str1[i];
      }
      for(int i = 0; i < sizeof(NombreCliente); ++i){
          NombreCliente[i] = str2[i];
      }
      for(int i = 0; i < sizeof(Genero);i++){
          Genero[i] = str3[i];
      }
      for (int i = 0; i < sizeof(IdCiudad);i++){
          IdCiudad[i] = str4[i];
      }
      cout << "ID: " << IdCliente << ", Nombre: " << NombreCliente << ", Sexo: " << Genero << ", # de ciudad: " << IdCiudad << endl;
    }

    listar.close();
}//Listo
  

void busqueda_sin_indice_cliente(){

}

void busqueda_con_indice_cliente(){

}

void reindexar_clientes(){

}

/*------------------------------------------------------------------------------*/
/*------------------------------------Metodos de ciudad-------------------------*/
void agregar_ciudad(){

}

void eliminar_ciudad(){

}

void modificar_ciudad(){

}

void listar_ciudad(){
   ifstream listar("ciudades.txt");
   int rrn = -1;
   int cantidad_registros = 30;
   int flag = 0;
   while(!listar.eof()){
      char IdCiudad[5];
      char NombreCiudad[40];
      string str1 = "", str2 = "";
      getline(listar, str1, ',');
      getline(listar, str2, ',');
      for(int i = 0; i < sizeof(NombreCiudad);i++){
          NombreCiudad[i] = str1[i];
      }
      for (int i = 0; i < sizeof(IdCiudad);i++){
          IdCiudad[i] = str2[i];
      }
      cout << "ID: " << IdCiudad << ", Nombre: " << NombreCiudad<< endl;
    }

    listar.close();
}

void busqueda_sin_indice_ciudad(){

}

void busqueda_con_indice_ciudad(){

}

void reindexar_ciudad(){

}