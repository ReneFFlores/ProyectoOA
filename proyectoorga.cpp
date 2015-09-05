#include <iostream>

using namespace std;

/*------------------------------------------------------------------------------*/
/*--------------------------Métodos del proyecto--------------------------------*/
//netodos para cliente
void agregar_cliente();
void eliminar_cliente();
void modificar_cliente();
void listar_sin_indice_cliente();
void listar_con_indice_cliente();
void busqueda();

//metodos para llamadas
void agregar_llamada();
void busqueda_con_indice_transaccion();
void busqueda_sin_indice_transaccion();

//agregar una linea
void agregar_linea();
void busqueda_con_indice_lineas();
void busqueda_sin_indice_lineas();


/*------------------------------------------------------------------------------*/
/*--------------------------"Clases" del proyecto-------------------------------*/
//atributos de clientes
struct Cliente{
   int IdCliente;//de 13 digitos
   char NombreCliente[40];
   char Genero[1];
   int ciudad;//de 4 bytes    
};

//atributos de lineas
struct Lineas{
   int IdCliente;
   int Teleforno;   
};

//atributos de ciudad
struct Ciudad{
   int IdCiudad;
   char NombreCiudad[40];   
};

//atributos de Llamadas
struct Llamadas{
      
};

int main (char*argc, char*argv[]){
    cout << "int: " << sizeof(int);
    system("Pause");
    return 0;
}
