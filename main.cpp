//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//INCLUDES Y HEADERS Q OCUPO

#include <fstream>
#include <ctype.h>
#include <iomanip>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cstring>

using std::stringstream;
using std::string;
using namespace std;

//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//ESTRUCTURAS

struct Index_client{
   int pos;
   char id_index[13];
};

struct Index_city{
   int pos;
   int ciudad;
};

struct Index_lineas{
   int pos;
   char linea[8];
   char id_cliente[13];
};

struct Llamadas{
   char lin_emisor[8];
   char lin_receptor[8];
   char inicio[14];
   char end[14];
   int seconds;
};

struct Cliente{
   char id[13];
	int acno;
	char name[40];
	char gender;
	int id_city;
};

struct Ciudad{
	char name[40];
	int id;
};

struct Lineast{
	char id[13];
	char numero[8];
};

//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//METODOS DE CADA COSA

//Métodos de texto a binarios
void Cliente_txt_bin(); 
void City_txt_bin();
void Lineas_txt_bin();

//Metodos relacionados con ciudades
void Agregar_Ciudad();
void Listar_Ciudades();
void Eliminar_Ciudad(int);
void Modificar_Ciudades(int);
void Busqueda_No_Indexada_Ciudad(int);

//Metodos relacionados con el cliente
void Agregar_Cliente();
void Busqueda_Indexada(int);
void buscar_id_cliente(string);
void modify_Cliente(int);
void delete_Cliente(int);
void Listar_Clientes();

//Metodos relacionados con lineas de clientes
void Listar_Lineas();
void Agregar_Linea();
void Busqueda_No_Indexada_Lineas(string);

//Metodos relacionados con las transacciones
void Listar_Todo();
void Generar_Factura_Ineficiente(string);

//Metodos relacionados con menues
void Administrar_Clientela();
void Administrar_Ciudades();
void Administrar_Lineas();

//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//MAIN ABSOULTO

int main(int argc,char*argv[]){
   Cliente_txt_bin();
   City_txt_bin();
   Lineas_txt_bin();
   //Eliminar_Ciudad(int);
   //Administrar_Clientela();
   //Modificar_Ciudades(int);
   //Agregar_Ciudad();
   //Agregar_Cliente();
   //Busqueda_No_Indexada_Ciudad(int);
   //Listar_Ciudades();
   //Listar_Todo();
   //Listar_Lineas();
   //Agregar_Linea();
   //Busqueda_No_Indexada_Lineas("1010198810499");
   //Generar_Factura_Ineficiente("1010198810499");
   
   remove("binary_client.dat");
   remove("binary_cities.dat");
   remove("binary_lineas.dat");
   return 0;
}


//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//PARSEOS A BINARIO

//Clientes a binario
void Cliente_txt_bin(){
    ifstream text_clientes("clientes.txt");
	ofstream outFile;
	outFile.open("binary_client.dat",ios::binary|ios::app);
    for(int i = 0; i < 500; i++){
      Cliente client;
      string idd, nom, apel, sex, nom_com = "";
      int id_city_str;
      text_clientes >> idd;
      text_clientes >> nom;
      text_clientes >> apel;
      text_clientes >> sex;
      text_clientes >> id_city_str;
      nom_com+=nom;
      nom_com+=" ";
      nom_com+=apel;
      strcpy(client.name, nom_com.c_str());//nombre str to nombre c-40
      strcpy(client.id, idd.c_str());
      client.gender = sex[0];
      client.id_city = id_city_str;
      client.acno = i;
      outFile.write((char*)&client, sizeof(Cliente));
    }
    text_clientes.close();
	outFile.close();
}

//para ciudades
void City_txt_bin(){
    ifstream text_ciudades("ciudades.txt");
	ofstream outFile;
	outFile.open("binary_cities.dat",ios::binary|ios::app);
    for(int i = 0; i < 30; i++){
        Ciudad city;
        string nom = "";
        int id;
        text_ciudades >> nom;
        text_ciudades >> id;
        for(int j = 0; j < 40; j++){
           if(nom[j]!='_'){
             city.name[j] = nom[j];
           }else{
             city.name[j] = ' ';
        }       
      }
      city.id = id;
      outFile.write((char*)&city, sizeof(Ciudad));
    }
    text_ciudades.close();
	outFile.close();
}

//Lineas a binario
void Lineas_txt_bin(){
    ifstream text_lineas("lineas.txt");
	ofstream outFile;
	outFile.open("binary_lineas.dat",ios::binary|ios::app);
    for(int i = 0; i < 500; i++){
      Lineast lxc;
      string numero_tel = "";
      string id_cliente = "";
      text_lineas >> id_cliente;
      text_lineas >> numero_tel;

      for(int j = 0; j < 13; j++){
        lxc.id[j] = id_cliente[j];        
      }

      for(int j = 0; j < 8; j++){
      	lxc.numero[j] = numero_tel[j];
      }

      outFile.write((char*)&lxc, sizeof(Lineast));
    }
    text_lineas.close();
	outFile.close();
}

//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//MENUS
 
void Administrar_Clientela(){
	char ch;
	int num;
	string identidad_busqueda = "";
	do{
		cout << "Administrando la clientela" << endl;
		cout << "1.- Agregar Clientes" << endl;
		cout << "2.- Buscar Clientes (Indexado)" << endl;
		cout << "3.- Buscar Clientes (ID)" << endl;
		cout << "4.- Listar Clientes" << endl;
		cout << "5.- Eliminar Cliente" << endl;
		cout << "6.- Modificar Cliente" << endl;
		cout << "7.- Salir" << endl;
		cin >> ch;
		switch(ch){
		case '1':
         	cout << "1.- Agregar Clientes" << endl;
			Agregar_Cliente();
			break;
		case '2':
         	cout << "2.- Buscar Clientes (Indexado)" << endl;
			cout<<"Ingrese posicion supuesta del usuario" << endl; 
         	cin >> num;
			Busqueda_Indexada(num);
			break;
		case '3':
			cout << "3.- Buscar Clientes (ID, osea no indexada)" << endl;
			cout << "Ingrese la identidad de la persona que busca" << endl;
         	cin >> identidad_busqueda;
			buscar_id_cliente(identidad_busqueda);
			break;
		case '4':
         	cout << "4.- Listar Clientes" << endl;
			Listar_Clientes();
			break;
		case '5':
			cout << "5.- Eliminar Cliente" << endl;
         	cin >> num;
			delete_Cliente(num);
			break;
		 case '6':
			cout << "6.- Modificar Cliente" << endl;
         	cin >> num;
			modify_Cliente(num);
			break;
		 case '7':
			cout << "Adios!";
			exit(0);
		 default:cout<<"\a";
		}
		//getch();
    }while(ch!='7');
}

void Administrar_Ciudades(){
	char ch;
	int num;
	string identidad_busqueda = "";

	do{
		cout << "Administrando las Ciudades" << endl;
		cout << "1.- Agregar Ciudades" << endl;
		cout << "2.- Buscar Ciudades (Indexado)" << endl;
		cout << "3.- Buscar Ciudades (ID)" << endl;
		cout << "4.- Listar Ciudades" << endl;
		cout << "5.- Eliminar Ciudades" << endl;
		cout << "6.- Modificar Ciudades" << endl;
		cout << "7.- Salir" << endl;
		cin >> ch;
		switch(ch){
		case '1':
            cout << "1.- Agregar Ciudades" << endl;
			Agregar_Ciudad();
			break;
		case '2':
            cout << "2.- Buscar Ciudades (Indexado)" << endl;
			cout<<"Ingrese posicion supuesta de la ciudad" << endl; 
            cin >> num;
			//Busqueda_Indexada_Ciudad(num);
			break;
		case '3':
			cout << "3.- Buscar Ciudades (ID, osea no indexada)" << endl;
			cout << "Ingrese la identidad de la ciudad que busca" << endl;
            cin >> num;
			Busqueda_No_Indexada_Ciudad(num);
			break;
		case '4':
            cout << "4.- Listar Ciudades" << endl;
			Listar_Ciudades();
			break;
		case '5':
			cout << "5.- Eliminar Ciudad" << endl;
			cout << "Ingrese codigo de ciudad a eliminar" << endl;
            cin >> num;
			Eliminar_Ciudad(num);
			break;
		 case '6':
			cout << "6.- Modificar Ciudad" << endl;
            cin >> num;
			Modificar_Ciudades(num);
			break;
		 case '7':
			cout << "Adios!";
			exit(0);
		 default:cout<<"\a";
		}
		//getch();
    }while(ch!='7');
}

void Administrar_Lineas(){
	char ch;
	int num;
	string identidad_busqueda = "";

	do{
		cout << "Administrando las Lineas" << endl;
		cout << "1.- Agregar Lineas" << endl;
		cout << "2.- Buscar Lineas (Indexado)" << endl;
		cout << "3.- Buscar Lineas (ID)" << endl;
		cout << "4.- Listar Lineas" << endl;
		cout << "5.- Eliminar Lineas" << endl;
		cout << "6.- Salir del menu de lineas" << endl;
		cin >> ch;
		switch(ch){
		case '1':
            cout << "1.- Agregar Linea" << endl;
			Agregar_Linea();
			break;
		case '2':
            cout << "2.- Buscar Linea (Indexado)" << endl;
			cout<<"Ingrese posicion supuesta de la linea" << endl; 
            cin >> num;
			//Busqueda_Indexada_Ciudad(num);
			break;
		case '3':
			cout << "3.- Buscar Lineas (ID, osea no indexada)" << endl;
			cout << "Ingrese la identidad de la persona cuya(s) linea(s) que busca" << endl;
            cin >> identidad_busqueda;
			Busqueda_No_Indexada_Lineas(identidad_busqueda);
			break;
		case '4':
            cout << "4.- Listar Lineas" << endl;
			Listar_Lineas();
			break;
		case '5':
			cout << "5.- Eliminar Lineas" << endl;
			cout << "Ingrese el numero telefonico que va a eliminar" << endl;
            cin >> num;
			//Eliminar_Lineas();
			break;
		 case '6':
			cout << "Adios!";
			break;
		}
    }while(ch!='6');
}

//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//CLIENTELAS
 
//Esciba al binairo, cliente
void Agregar_Cliente(){
    Cliente client;
    //abrimos el archivo con el ultimo registro
    ifstream for_pos("last_index.txt");
    for_pos >> client.acno;
    for_pos.close();
   
    //jugamos con la posicion
    int pos = client.acno+1;
    client.acno-=10000;
    remove("last_index.txt");
    ofstream new_last_index;
    new_last_index.open("last_index.txt");
    new_last_index << pos;
    new_last_index.close();
   
   //agregamos
    stringstream ss;
	ofstream outFile;
	outFile.open("binary_client.dat",ios::binary|ios::app);
	string nom, apel, nom_com = "";
	int anio;
	cout << "Ingrese primer nombre del usuario" << endl;
	cin >> nom;
	cout << "Ingrese apellido nombre del usuario" << endl;
	cin >> apel;
	char sex_person;
	cout << "Ingrese anio de nacimiento de la persona" << endl;
	cin >> anio;
	cout << "Ingrese sexo del cliente(a):" << endl;
	cin >> sex_person;
	client.gender = toupper(sex_person);
	cout << "Ingrese numero de residencia de ciudad:" << endl;
	cin >> client.id_city;
	cout << "Usuario creado!" << endl;
	nom_com+=nom;
	nom_com+=" ";
	nom_com+=apel;
	ss << client.id_city;
	ss << anio;
	ss << (pos-1);
	strcpy(client.name, nom_com.c_str());
	strcpy(client.id, (ss.str()).c_str());
   outFile.write((char*)&client, sizeof(Cliente));
	outFile.close();
}
 
//Lee cliente del archivo
void Busqueda_Indexada(int n){
	Cliente client;
	int flag = 0;
	ifstream inFile;
    inFile.open("binary_client.dat",ios::binary);
	if(!inFile){
		cout << "Archivo no disponible :(" << endl;
		return;
	}
	cout << "Busqueda indexada" << endl;
    while(inFile.read((char*)&client, sizeof(Cliente))){
		if(client.acno==n){
			cout << "Cliente No.: " << client.acno << endl;
			cout << "ID: " << client.id << endl;
	      cout << "Nombre: " << client.name << endl;
	      cout << "Sexo: " << client.gender << endl;
	      cout << "City ID: " << client.id_city << endl;
			flag = 1;
			break;
		}
	}
    inFile.close();
	if(flag==0)
		cout << "Cliente en esa posición no existe" << endl;
}//FIN MOSTRAR
 
//Modifica al archivo
void modify_Cliente(int n){
	int encontrado = 0;
	Cliente client;
	fstream File;
   File.open("binary_client.dat",ios::binary|ios::in|ios::out);
	if(!File){
		cout << "Archivo no disponible :(" << endl;
		return;
	}
    while(File.read((char*)&client, sizeof(Cliente)) && encontrado == 0){
		if(client.acno==n){
	     cout << "Cliente No.: " << client.acno << endl;
	     cout << "Nombre: " << client.name << endl;
	     cout << "Sexo: " << client.gender << endl;
		  cout << "Editando cliente" << endl;
		  cout << endl << "--------------------------------Punto de edicion----------------------------" << endl;
		  string nom, apel, nom_comp = "";
	     cout << "Reingrese primer nombre del cliente" << endl;
	     cin >> nom;
	     cout << "Reingrese primer apellido del cliente" << endl;
	     cin >> apel;
	     nom_comp+=nom;
	     nom_comp+=" ";
	     nom_comp+=apel;
	     strcpy(client.name,nom_comp.c_str());
	     cout << "Reingrese el sexo de su cliente (Operado?)" << endl;
	     cin >> client.gender;
	     client.gender = toupper(client.gender);
	     cout << "Reingrese ciudad de residencia del cliente" << endl;
	     cin >> client.id_city;
		  int pos = (-1)*sizeof(Cliente);
		  File.seekp(pos,ios::cur);
	     File.write((char*) &client, sizeof(Cliente));
		  cout << "Cliente(a) Actualizado!" << endl;
		  encontrado = 1;
		}
	}
	File.close();
	if(encontrado ==0)
		cout<<"Registro no encontrado :(";
}//FIN MODIFICAR
 
 
//Borrar-deletear archivo
void delete_Cliente(int n){
	Cliente client;
	ifstream inFile;
	ofstream outFile;
	inFile.open("binary_client.dat",ios::binary);
	if(!inFile){
		cout << "Archivo no disponible :(" << endl;
		return;
	}
	outFile.open("temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char*)&client, sizeof(Cliente))){
		if(client.acno!=n){
			outFile.write((char*)&client, sizeof(Cliente));
		}
	}
   inFile.close();
	outFile.close();
	remove("binary_client.dat");
	rename("temp.dat","binary_client.dat");
	cout << "Cliente eliminado";
}//DELETEAR CLIENTE
 
//LISTAR 
void Listar_Clientes(){
	Cliente client;
	ifstream inFile;
	inFile.open("binary_client.dat",ios::binary);
 
	if(!inFile){
		cout << "Archivo no disponible :(" << endl;
		return;
	}
	cout << "  Identidad  *                Nombre                 * Sex * City";
	cout << "-----------------------------------------------------------------" << endl;
	while(inFile.read((char*)&client, sizeof(Cliente))){
	     cout << "ID: "<< client.id << " Nombre: " << client.name << 
            " Genero: " << client.gender << " City id: "<< client.id_city << endl;
	}
	inFile.close();
}//FIN LISTAR CLIENTES

//BUSQUEDA NO INDEXADA
void buscar_id_cliente(string identidad){
	Cliente client;
	bool flag = false;
	bool equals = false;
	ifstream inFile;
   inFile.open("binary_client.dat",ios::binary);
	if(!inFile){
		cout << "Archivo no disponible :(" << endl;
		return;
	}
	cout << "Busqueda no-indexada" << endl;
    while(inFile.read((char*)&client, sizeof(Cliente))){
      string temp(client.id);
		if(temp==identidad){
			cout << "Cliente No.: " << client.acno << endl;
			cout << "ID: " << client.id << endl;
	        cout << "Nombre: " << client.name << endl;
	        cout << "Sexo: " << client.gender << endl;
	        cout << "City ID: " << client.id_city << endl;
			flag = true;
			break;
		}
	}
    inFile.close();
	if(!flag)
		cout << "Cliente con esa identidad no existe" << endl;
}//FIN MOSTRAR

//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//CIUDADES

//Agregar ciudad
void Agregar_Ciudad(){
   Ciudad city;
   //abrimos el archivo con el ultimo registro
   ifstream for_pos("last_index_city.txt");
   for_pos >> city.id;
   for_pos.close();
   
   //jugamos con la posicion 
   remove("last_index_city.txt");
   ofstream new_last_index;
   new_last_index.open("last_index_city.txt");
   new_last_index << (city.id+1);
   new_last_index.close();
   
   //agregamos
	ofstream outFile;
	outFile.open("binary_cities.dat",ios::binary|ios::app);
	string nom;
	cout << "Ingrese primer nombre de la nueva ciudad" << endl;
	cin >> nom;
	cout << "Ciudad creada!" << endl;
	strcpy(city.name, nom.c_str());
    outFile.write((char*)&city, sizeof(Ciudad));
	outFile.close();
}

//Borrar-deletear archivo
void Eliminar_Ciudad(int n){
	Ciudad city;
	ifstream inFile;
	ofstream outFile;
	inFile.open("binary_cities.dat",ios::binary);
	if(!inFile){
		cout << "Archivo no disponible :(" << endl;
		return;
	}
	outFile.open("temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char*)&city, sizeof(Ciudad))){
		if(city.id!=n){
			outFile.write((char*)&city, sizeof(Ciudad));
		}
	}
    inFile.close();
	outFile.close();
	remove("binary_cities.dat");
	rename("temp.dat","binary_cities.dat");
	cout << "Ciudad eliminada";
}//DELETEAR CIUDAD

//Listar
void Listar_Ciudades(){
	Ciudad city;
	ifstream inFile;
	inFile.open("binary_cities.dat",ios::binary);
 
	if(!inFile){
		cout << "Archivo no disponible :(" << endl;
		return;
	}

	while(inFile.read((char*)&city, sizeof(Ciudad))){
	     cout << "ID: " << city.id  << " Nombre: "<< city.name << endl;
	}
	inFile.close();
}//FIN LISTAR CIUDADES

void Busqueda_No_Indexada_Ciudad(int n){
	Ciudad city;
	int flag = 0;
	ifstream inFile;
    inFile.open("binary_cities.dat",ios::binary);
	if(!inFile){
		cout << "Archivo no disponible :(" << endl;
		return;
	}
	cout << "Busqueda no-indexada  de ciudades" << endl;
    while(inFile.read((char*)&city, sizeof(Ciudad))){
		if(city.id==n){
			cout << "Ciudad: " << city.name << endl;
			cout << "ID: " << city.id << endl;
			flag = 1;
			break;
		}
	}
    inFile.close();
	if(flag==0)
		cout << "Ciudad en esa posición no existe" << endl;
}

void Modificar_Ciudades(int codigo){
	int encontrado = 0;
	Ciudad city;
	fstream File;
    File.open("binary_cities.dat",ios::binary|ios::in|ios::out);
	if(!File){
		cout << "Archivo no disponible :(" << endl;
		return;
	}
    while(File.read((char*)&city, sizeof(Ciudad)) && encontrado == 0){
		if(city.id == codigo){
	     cout << "Cliente No.: " << city.id << endl;
	     cout << "Nombre: " << city.name << endl;
		  cout << endl << "--------------------------------Punto de edicion----------------------------" << endl;
		  string new_nom;
	     cout << "Reingrese nombre de la ciudad" << endl;
	     cin >> new_nom;
     	  strcpy(city.name,new_nom.c_str());
		  int pos = (-1)*sizeof(Ciudad);
		  File.seekp(pos,ios::cur);
	     File.write((char*) &city, sizeof(Ciudad));
		  cout << "Ciudad Actualizada!" << endl;
		  encontrado = 1;
	   }
	}
	File.close();
	if(encontrado ==0)
		cout<<"Registro no encontrado :(";
}

//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//LINEAS

//Agregar
void Agregar_Linea(){
   Lineast linea;
   int suffix;
   stringstream ss;

   //abrimos el archivo con el ultimo registro
   ifstream for_pos("last_number_suffix.txt");
   for_pos >> suffix;
   for_pos.close();

   string out = "90000";
   
   //jugamos con la posicion 
   remove("last_number_suffix.txt");
   ofstream new_last_index;
   new_last_index.open("last_number_suffix.txt");
   new_last_index << (suffix+1);
   new_last_index.close();
   
   //agregamos
	ofstream outFile;
	outFile.open("binary_lineas.dat",ios::binary|ios::app);
	string identidad;
	cout << "Ingrese identidad del usuario " << endl;
	cin >> identidad;

	for(int i = 0; i < 13; i++){
		linea.id[i] = identidad[i];
	}

	ss << out << suffix;
	string final_number = ss.str();

	for(int i = 0; i < 8; i++){
		linea.numero[i] = final_number[i];
	}


    outFile.write((char*)&linea, sizeof(Lineast));
	outFile.close();

	cout << "Linea creada!" << endl;
}

//Listar
void Listar_Lineas(){
	Lineast lxc;
	ifstream inFile;
	inFile.open("binary_lineas.dat",ios::binary);
	if(!inFile){
		cout << "Archivo no disponible :(" << endl;
		return;
	}

	while(inFile.read((char*) &lxc, sizeof(Lineast))){

	     cout << "ID: ";

	     for(int i = 0; i < 13; i++){
	     	cout << lxc.id[i];
	     }

	     cout << " numero telefonico: ";

	     for(int i = 0; i < 8; i++){
	     	cout << lxc.numero[i];
	     }

	     cout << endl;
	}
	inFile.close();
}//FIN LISTAR LINEAS


void Busqueda_No_Indexada_Lineas(string identidad){
	Lineast phone;
	int flag = 0;
	ifstream inFile;
    inFile.open("binary_lineas.dat",ios::binary);
	if(!inFile){
		cout << "Archivo no disponible :(" << endl;
		return;
	}
	cout << "Busqueda no-indexada  de lineas" << endl;
    while(inFile.read((char*)&phone, sizeof(Lineast))){
    	string identidad_comrapable = "";
    	for(int i = 0; i < 13; i++){
			identidad_comrapable+=phone.id[i];
    	}
		if(identidad_comrapable==identidad){
			cout << "ID del cliente: ";

			for (int i = 0; i < 13;i++){
				cout << phone.id[i];;
			} 

			cout << " Numero: ";

			for (int i = 0; i < 8;i++){
				cout << phone.numero[i];;
			} 

			cout << endl;
			flag = 1;
		}
	}
    inFile.close();
	if(flag==0)
		cout << "Ciudad en esa posición no existe" << endl;
}

//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------
//TRANSACCIONES DE LLAMADAS
void Listar_Todo(){
	ifstream inFile;
	inFile.open("llamadas.txt",ios::binary);
 
	if(!inFile){
		cout << "Archivo no disponible :(" << endl;
		return;
	}	
   int i = 0;
	while(!inFile.eof()){
      string emisor_id, receptor_id, emisor_num, receptor_num, date_init, date_end;
      string seconds;
      inFile >> emisor_id;
      inFile >> emisor_num;
      inFile >> receptor_id;
      inFile >> receptor_num;
      inFile >> date_init;
      inFile >> date_end;
      inFile >> seconds;       
	   cout << i << ".- " << emisor_id << '(' << emisor_num << ") llamo al " << receptor_num << " por " << seconds << "segundos" << endl;
	   i++;
	   if(inFile.eof()){
         break;
      }
	}
	inFile.close();
}//FIN LISTAR TODAS LAS TRANSACCIONES


//Generar_Factura_Ineficiente
void Generar_Factura_Ineficiente(string cliente){
	ifstream inFile;
	inFile.open("llamadas.txt",ios::binary);
 
	if(!inFile){
		cout << "Archivo no disponible :(" << endl;
		return;
	}	

	float total = 0.00;

	while(!inFile.eof()){
		stringstream ss;
	    string emisor_id, receptor_id, emisor_num, receptor_num, date_init, date_end;
	    float seconds;
	    inFile >> emisor_id;
	    inFile >> emisor_num;
	    inFile >> receptor_id;
	    inFile >> receptor_num;
	    inFile >> date_init;
	    inFile >> date_end;
	    inFile >> seconds; 

		for(int i = 0; i < 13; i++){
		   if(emisor_id[i]!=cliente[i]){
		   	  break;
		   }else{
		   	  if(i==12 && emisor_id[i] == cliente[i]){
		   	  	 ss << emisor_id << '(' << emisor_num << ") llamo al " << receptor_num << " por " << seconds << " segundos";
		   	  	 cout << ss.str() << endl;
		   	  	 total+=seconds;
		   	  }
		   }
		}//fin for

		if(inFile.eof()){
            break;
        }
	}
	inFile.close();

	int op;
	float dollar_per_second;

	while(true){
		cout << "Ingrese modo de servicio general del cliente " << endl;
		cout << "1.- Basico, 0.01$ por minuto" << endl;
		cout << "2.- Normal, 0.04$ por minuto" << endl;
		cout << "3.- Excelente, 0.05$ por minuto" << endl;
		cout << "4.- Videollamada, 0.99$ por minuto" << endl;
		cin >> op;
		if(op<=4||op>=0){
			break;
		}
	}

	if(op==1){
	   dollar_per_second = 0.01;
	}else if(op==2){
		dollar_per_second = 0.04;
	}else if(op==3){
		dollar_per_second = 0.05;
	}else{
		dollar_per_second = 0.99;
	}

	cout << "Total factura (precio sin impuesto): " << (total/60.0)*dollar_per_second << " $" << endl;
	cout << "Total factura con impuestos: " << (total/60.0)*dollar_per_second*1.15 << " $" << endl;
}