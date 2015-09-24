#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <sstream>

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
    char op;;
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
        char op_interno;
        cout << "Ingrese que desea hacer con sus clientes" << endl;
        cin >> op_interno;
        if(op_interno=='1'){
          cout << "Listando clientes" << endl;
          listar_clientes();
        }else if(op_interno=='2'){
          cout << "Agregar cliente" << endl;
          agregar_cliente();          
        }else if(op_interno=='3'){

        }else if(op_interno=='4'){

        }else if(op_interno=='5'){

        }else if(op_interno=='6'){

        }else{

        }
      }else if(op=='2'){
        char op_interno;
        cout << "Ingrese que desea hacer con sus ciudades" << endl;
        cout << "1.- Listar" << endl;
        cout << "2.- Agregar" << endl;
        cin >> op_interno;
        if(op_interno=='1'){
          cout << "Listando ciudades" << endl;
          listar_ciudad();
        }else if(op_interno=='2'){
          cout << "Agregar ciudad" << endl;
          agregar_ciudad();          
        }else if(op_interno=='3'){

        }else if(op_interno=='4'){

        }else if(op_interno=='5'){

        }else if(op_interno=='6'){

        }else{

        }
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
   string nombre_string = "", apel_string = "",ciudad_string, sex, birth_year;
   stringstream ss;
   string id_temp;
   ofstream cliente_mas("personas.txt",std::ios::app);
   char Id_cliente[14];
   char Nombre_cliente[40];
   char Sexo[2];
   char Id_ciudad[4];

   cout << "Ingrese primer nombre del cliente(a)" << endl;
   cin >> nombre_string;
   cout << "Ingrese segundo nombre del cliente(a)" << endl;
   cin >> apel_string;
   cout << "Ingrese año de nacimiento del cliente(a)" << endl;
   cin >> birth_year;
   cout << "Ingrese código de la ciudad del cliente(a)" << endl;
   cin >> ciudad_string;
   cout << "Ingrese sexo de su cliente(a)" << endl;
   cin >> sex;

   string nombre_cliente_definitivo = "";
   nombre_cliente_definitivo += nombre_string;
   nombre_cliente_definitivo += " ";
   nombre_cliente_definitivo += apel_string;

   for(int i = 0; i < sizeof(Nombre_cliente); i++){
      Nombre_cliente[i] = nombre_cliente_definitivo[i];
   }

   for(int i = 0; i < sizeof(Sexo); i++){
      Sexo[i] = sex[i];
   }

   for(int i = 0; i < sizeof(Id_ciudad); i++){
      Id_ciudad[i] = ciudad_string[i];
   }

   id_temp += ciudad_string;
   id_temp += birth_year;
   id_temp += "10505";//poner este dato aun binario

   for(int i = 0; i < sizeof(Id_cliente); i++){
      Id_cliente[i] = id_temp[i];
   }

   cliente_mas << endl << id_temp << ',' << Nombre_cliente << ',' << Sexo << ',' << ciudad_string << ',';
   cliente_mas.close();
   cout << "Exito al ingresar cliente" << endl;
}

void eliminar_cliente(){

}

void modificar_cliente(){

}

void listar_clientes(){
   //Se resuelve en QT
   ifstream listar("personas.txt");
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
   string nombre_string = "";
   ifstream avail_city("final_4_id_city.txt",std::ios::app);
   char cit[40];
   int final_city_avail_int_form;// = stoi(final_city_avail_string);
   avail_city >> final_city_avail_int_form;
   cout << final_city_avail_int_form << endl;
   avail_city.close();

   //ida de lleno de ciudaad
   ofstream ciudad_mas("ciudades.txt",std::ios::app);
   cout << "Ingrese nombre de la ciudad" << endl;
   cin >> cit;

   nombre_string = string(cit);

   ciudad_mas << endl;

   //ciudad_mas << endl << final_city_avail << ',';
   for(int i = 0; i < nombre_string.length(); i++){
       ciudad_mas << nombre_string[i];
   }

   ciudad_mas << ',';
   final_city_avail_int_form++;
   ciudad_mas << final_city_avail_int_form;
   ciudad_mas << ',';

   remove("final_4_id_city.txt");

   ofstream nuevo_final("final_4_id_city.txt");
   nuevo_final << final_city_avail_int_form;
   nuevo_final.close();
   ciudad_mas.close();
   cout << "Exito al ingresar ciudad" << endl;
}

void eliminar_ciudad(){

}

void modificar_ciudad(){

}

void listar_ciudad(){
   ifstream listar("ciudades.txt");
   int rrn = -1;
   int cantidad_registros = 35;
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