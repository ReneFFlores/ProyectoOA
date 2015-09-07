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
void listar_clientes();//ya!
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
void listar_linea();//ya!
void busqueda_con_indice_lineas();
void busqueda_sin_indice_lineas();
void reindexar_linea();

//metodos para ciudad
void agregar_ciudad();
void eliminar_ciudad();
void modificar_ciudad();
void listar_ciudad();//ya!
void busqueda_sin_indice_ciudad();
void busqueda_con_indice_ciudad();
void reindexar_ciudad();


/*------------------------------------------------------------------------------*/
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
/*--------------------------------------------------------------------------*/
/*------------------------------MAIN----------------------------------------*/

int main (int argc, char*argv[]){
    char op;
    while(true){
      cout << "Ingrese su opcion" << endl;
      cout << "1.- Sobre clientes" << endl;
      cout << "2.- Sobre ciudades" << endl;
      cout << "3.- Sobre lineas" << endl;
      cout << "4.- Sobre transacciones/llamadas" << endl;
      cout << "5.- Consultar tarifas" << endl;
      cout << "6.- Salir" << endl;
      cin >> op;

      if(op=='1'){
        listar_clientes();//ya esta!
        //agregar_cliente();
      }else if(op=='2'){
        //listar_ciudad();
        agregar_cliente();
      }else if(op=='3'){
        //listar_linea();
      }else if(op=='4'){
        //eliminar_cliente();
      }else if(op=='5'){
        //busqueda_sin_indice_cliente();
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
   ofstream file;
   file.open("personas2.txt",std::ios::app);
   char anio[4];
   char nombre[20];
   char apellido[20];
   char genero[1];
   char id_ciudad[5];
   char taking_one_char_for_the_team[1];
 
   cout << "Agregando registro de un nuevo cliente" << endl;
   if(!(file))
    cout << "Error de apuertura del archivo" << endl;
   else{
    cout << "Ingrese el nombre del Cliente: " << endl;
    cin >> nombre;
    cout << "Ingrese apellido del cliente" << endl;
    cin >> apellido;
    cout << "Ingrese año de nacimiento" << endl;
    //cin >> taking_one_char_for_the_team;
    cin >> anio;
    cout << "Igrese el sexo de la persona: (M = masculino, F = femenino)" << anio << endl;
    cin >> genero;
    cout << "Ingrese identidad de ciudad de la persona: " << endl;
    cin >> id_ciudad;
   }

   file << endl << id_ciudad << anio << 10501 << ',' << nombre << ' ' << apellido << ',' << genero << ',' << id_ciudad << ',';
   file.close();
   cout << "Exito de adicion" << endl;
}

void eliminar_cliente(){

}

void modificar_cliente(){

}

void listar_clientes(){
   ifstream listar("personas2.txt");
   int rrn = -1;
   int cantidad_registros = 501;
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


/*--------------------------------------------------------------------*/
/*--------------------------------------------------------------------*/
/*----------------------Metods de lineas-----------------------------.*/
void agregar_linea(){

}

void eliminar_linea(){

}

void modificar_linea(){

}

void listar_linea(){
   ifstream listar("lineas.txt");
   int rrn = -1;
   int cantidad_registros = 500;
   int flag = 0;
   while(!listar.eof()){
      char IdCliente[15];
      char Telefono[9];
      string str1 = "", str2 = "";
      getline(listar, str1, ',');
      getline(listar, str2, ',');
      for(int i = 0; i < sizeof(IdCliente);i++){
          IdCliente[i] = str1[i];
      }
      for (int i = 0; i < sizeof(Telefono);i++){
          Telefono[i] = str2[i];
      }
      cout << "ID cliente: " << IdCliente << ", Numero telefonico: " << Telefono << endl;
    }

    listar.close();
}

void busqueda_con_indice_lineas(){

}

void busqueda_sin_indice_lineas(){

}

void reindexar_linea(){

}