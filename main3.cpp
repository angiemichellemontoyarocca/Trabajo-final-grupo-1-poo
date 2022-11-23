#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <cstring>
#include <conio.h>
#include <vector>
#include <algorithm> 
#include "controller/PersonalController.h"
#include "controller/TipoPersonalController.h"
#include "controller/ClienteController.h"
#include "controller/ProductoController.h"
#include "controller/CategoriaController.h"
#include "controller/VentaController.h"
#include "controller/DetalleVentaController.h"

using namespace std;

//Variables Globales
PersonalController*  perController = new PersonalController();
ClienteController*	 cliController = new ClienteController();
ProductoController*  proController = new ProductoController();
TipoPersonalController*	  tipController = new TipoPersonalController();
CategoriaController*	  catController = new CategoriaController();
VentaController*	 venController = new VentaController();
DetalleVentaController*		detController = new DetalleVentaController();

string users;

//Prototipos
void menuPrincipal();
void salidaSistema();
void vistaPersonal();
void vistaCliente();
void vistaProducto();
void vistaVenta();

//Cliente
void nuevoCliente();
void modificarCliente();
void eliminarCliente();
void buscarCliente();
void listarCliente();

//Personal
void nuevoPersonal();
void modificarPersonal();
void eliminarPersonal();
void buscarPersonal();
void listarPersonal();
void editarTipos();

//Tipos
void nuevoTipoPersonal();
void modificarTipoPersonal();
void eliminarTipoPersonal();
void buscarTipoPersonal();
void listarTipoPersonal();

//Producto
void nuevoProducto();
void modificarProducto();
void eliminarProducto();
void buscarProducto();
void listarProducto();
void editarCategoria();

//Categoria
void nuevaCategoria();
void modificarCategoria();
void eliminarCategoria();
void buscarCategoria();
void listarCategoria();

//GOTOXY
void gotoxy(int x, int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void title()
{
	system("cls");
	gotoxy(8,1);cout << "__      __        _          __  __" << endl;
	gotoxy(8,2);cout << "\\ \\    / /       | |        |  \\/  |" << endl;
	gotoxy(8,3);cout << " \\ \\  / /__ _ __ | |_ __ _  | \\  / | __ _ ___ " << endl;
	gotoxy(8,4);cout << "  \\ \\/ / _ \\ '_ \\| __/ _` | | |\\/| |/ _` / __|" << endl;
	gotoxy(8,5);cout << "   \\  /  __/ | | | || (_| | | |  | | (_| \\__ \"" << endl;
	gotoxy(8,6);cout << "    \\/ \\___|_| |_|\\__\\__,_| |_|  |_|\\__,_|___/\n"
	<< endl;
	cout << endl;
}

void inicioSesion()
{	
	string contra;
	int contador = 0;
	bool intento;
	char caracter;
	
	do
	{
		system("cls");
		title();
		gotoxy(8,8); cout<<"**********************************************";
		gotoxy(8,9); cout<<"||                                          ||";
		gotoxy(8,10); cout<<"||               Bienvenido                 ||";
		gotoxy(8,11); cout<<"||                                          ||";
		gotoxy(8,12); cout<<"||      Usuario:                            ||";
		gotoxy(8,13);cout<<"||      Contrasenia:                        ||";
		gotoxy(8,14);cout<<"||                                          ||";
		gotoxy(8,15);cout<<"**********************************************";
		gotoxy(26,12); getline(cin,users);
		gotoxy(30,13); caracter = getch();
		contra = "";
		while(caracter != 13)
		{
			if (caracter != 8)
			{
				contra.push_back(caracter);
				cout<<"*";
			}
			else
			{
				if (contra.length()>0)
				{
					cout<<"\b \b";
					contra = contra.substr(0, contra.length()-1);
				}
			}
			caracter = getch();
		}
		if (perController->verificarDatos(users,contra) == true)
		{
			intento = true;
		}
		else
		{
			cout<<"Contrasenia incorrecta, aún tienes"<<contador<<"de 3"<<endl;
			intento = false;
			contador++;
		}
	} while(contador < 3 && intento == false);
	if (intento == true)
	{
		gotoxy(8,17);cout<<"\tIngreso satisfactorio\n"<<endl;
		system("pause");
		system ("cls");
		menuPrincipal();
	}
	else
	{
		cout<<"Has pasado el límite de intentos (MAXIMO 3)"<<endl;
		salidaSistema();
	}
}

void menuPrincipal()
{
	int opt;
	do
	{
		title();
		gotoxy(10,8);cout<<"********************************************************";
		gotoxy(10,9);cout<<"||                                                    ||";
		gotoxy(10,10);cout<<"||                     OPCIONES                       ||";
		gotoxy(10,11);cout<<"||    1. Registro de Clientes-------------------[1]   ||";
		gotoxy(10,12);cout<<"||    2. Registro de Productos------------------[2]   ||";
		gotoxy(10,13);cout<<"||    3. Registro de Personal de la empresa-----[3]   ||";
		gotoxy(10,14);cout<<"||    4. Generar Venta--------------------------[4]   ||";
		gotoxy(10,15);cout<<"||    5. Salida del Sistema---------------------[5]   ||";
		gotoxy(10,16);cout<<"||                                                    ||";
		gotoxy(10,17);cout<<"*******************************************************";
		
		gotoxy(10,18);cout<<"_____________________________________";
		gotoxy(10,19);cout<<"|                                   |";
		gotoxy(10,20);cout<<"|    Ingrese una opcion:            |";
		gotoxy(10,21);cout<<"|___________________________________|";
		gotoxy(35,20);cin>>opt;
		switch(opt)
		{
		case 1:system("cls");vistaCliente();break;
		case 2:system("cls");vistaProducto();break;
		case 3:system("cls");vistaPersonal();break;
		case 4:system("cls");vistaVenta();break;
		case 5:system("cls");salidaSistema();break;
		default:system("cls");cout<<"\n\tIngresa una opción correcta[1-5]\n";
		}
	}
	while(opt!=5);
}

void salidaSistema()
{
	system ("cls");
	exit(0);
}

void vistaPersonal()
{

	int opt;
	do
	{
		title();
		gotoxy(10,8);cout<<"********************************************************";
		gotoxy(10,9);cout<<"||                                                    ||";
		gotoxy(10,10);cout<<"||                     OPCIONES                       ||";
		gotoxy(10,11);cout<<"||    1. Nuevo Personal-------------------------[1]   ||";
		gotoxy(10,12);cout<<"||    2. Modificar Personal---------------------[2]   ||";
		gotoxy(10,13);cout<<"||    3. Eliminar Personal----------------------[3]   ||";
		gotoxy(10,14);cout<<"||    4. Buscar Personal------------------------[4]   ||";
		gotoxy(10,15);cout<<"||    5. Listar Personal------------------------[5]   ||";
		gotoxy(10,16);cout<<"||    6. Editar Tipos de Personal----------------[6]  ||";
		gotoxy(10,17);cout<<"||    7. Volver a Menu Principal-----------------[7]  ||";
		gotoxy(10,18);cout<<"||                                                    ||";
		gotoxy(10,19);cout<<"*******************************************************";
		
		gotoxy(10,21);cout<<"_____________________________________";
		gotoxy(10,22);cout<<"|                                   |";
		gotoxy(10,23);cout<<"|    Ingrese una opcion:            |";
		gotoxy(10,24);cout<<"|___________________________________|";
		gotoxy(35,23);cin>>opt;
		switch(opt)
		{
		case 1:system("cls");nuevoPersonal();break;
		case 2:system("cls");modificarPersonal();break;
		case 3:system("cls");eliminarPersonal();break;
		case 4:system("cls");buscarPersonal();break;
		case 5:system("cls");listarPersonal();break;
		case 6:system("cls");editarTipos();break;
		case 7:system("cls");menuPrincipal();break;
		default:system("cls");cout<<"Ingresa una opción correcta[1-7]\n";
		}
	}
	while(opt!=6);
}

void nuevoPersonal()
{
	string 	flag;
	int 	codigo;
	string 	nomPer;
	string	usuPer;
	string 	password;
	string 	contra;
	int 	codCate;
	char 	caracter;
	char    conf;
	do
	{
		codigo = perController->getCorrelativo();
		gotoxy(4,4);cout<<"        ******("<<codigo<<")*******\n";
		cin.ignore();
		gotoxy(4,6);cout<<"Nombres y Apellidos del Personal:";
		getline(cin,nomPer);
		gotoxy(4,7);cout<<"Usuario personal:";
		getline(cin,usuPer);
		gotoxy(4,8);cout<<"Password personal:";
		caracter = getch();
		password = "";
		while(caracter != 13)
		{
			if (caracter != 8)
			{
				password.push_back(caracter);
				cout<<"*";
			}
			else
			{
				if (password.length()>0)
				{
					cout<<"\b \b";
					password = password.substr(0, password.length()-1);
				}
			}
			caracter = getch();
		}
		
		do
		{
			cout<<"\n    Confirmar Password: ";
			conf = getch();
			contra = "";
			while(conf != 13)
			{
				if (conf != 8)
				{
					contra.push_back(conf);
					cout<<"*";
				}
				else
				{
					if (contra.length()>0)
					{
						cout<<"\b \b";
						contra = contra.substr(0, contra.length()-1);
					}
				}
				conf = getch();
			}
			
			if (password != contra)
			{
				cout<<"\n\tConfirmacion de Password errada. Intentelo nuevamente\n";
			}
		}
		while(password != contra);
		
		cout<<"\n";
		cout<<"\n     CODIGO"<<"\t"<<"TIPO DE PERSONAL"<<"\n";
		for(int i = 0;i<tipController->size();i++)
		{
			cout<<"\        ["<<tipController->get(i).getCodTipPer()<<"]\t"<<"\t"<<tipController->get(i).getNomTipPer()<<endl;
		}
		cout<<"\n    Codigo de la categoria del personal:";
		cin>>codCate;
		cout<<"    Continuar(S/s):";
		cin>>flag;
		/*Crear el objeto de tipo alumno*/
		Personal objPersonal(codigo,nomPer,usuPer,password,codCate);
		/*Agregar el objeto alarreglo*/
		perController->add(objPersonal);
		//grabar en archivo
		perController->grabarEnArchivo(objPersonal);
		system("cls");
	} 
	while(flag == "S" || flag == "s");
}

void modificarPersonal()
{
	int codigo;
	gotoxy(4,4);cout<<"Ingrese el codigo a buscar:";
	cin>>codigo;
	Personal objAModificar = perController->buscarPorCodigo(codigo);
	if(objAModificar.getNomApePer() != "Error")
	{
		gotoxy(4,6);cout<<"Codigo:"<<objAModificar.getCodPersonal()<<endl;
		gotoxy(4,7);cout<<"Nombre y Apellidos:"<<objAModificar.getNomApePer()<<endl;
		gotoxy(4,8);cout<<"Usuario:"<<objAModificar.getUsuPer()<<endl;
		gotoxy(4,9);cout<<"Password:"<<objAModificar.getPassPer()<<endl;	
		gotoxy(4,10);cout<<"Categoria:"<<objAModificar.getCodTipPer()<<endl;
		cin.ignore();
		
		string  nomApe,
				usuario,
				password,
				contra;
		int 	categoria;
		char 	caracter,
				conf;  
		gotoxy(4,11);cout<<"---------------------------------------------\n";
		gotoxy(4,12);cout<<"Modificar Nombres y Apellidos:";
		getline(cin,nomApe);
		gotoxy(4,13);cout<<"Modificar Usuario:";
		getline(cin,usuario);
		gotoxy(4,14);cout<<"Modificar Password:";
		caracter = getch();
		password = "";
		while(caracter != 13)
		{
			if (caracter != 8)
			{
				password.push_back(caracter);
				cout<<"*";
			}
			else
			{
				if (password.length()>0)
				{
					cout<<"\b \b";
					password = password.substr(0, password.length()-1);
				}
			}
			caracter = getch();
		}
		do
		{
			cout<<"\n    Confirmar Nueva Password: ";
			conf = getch();
			contra = "";
			while(conf != 13)
			{
				if (conf != 8)
				{
					contra.push_back(conf);
					cout<<"*";
				}
				else
				{
					if (contra.length()>0)
					{
						cout<<"\b \b";
						contra = contra.substr(0, contra.length()-1);
					}
				}
				conf = getch();
			}
			
			if (password != contra)
			{
				cout<<"\n\tConfirmacion de Password errada. Intentelo nuevamente\n";
			}
		}
		while(password != contra);
		cout<<"\n     CODIGO"<<"\t"<<"TIPO DE PERSONAL"<<"\n";
		for(int i = 0;i<tipController->size();i++)
		{
			cout<<"\      ["<<tipController->get(i).getCodTipPer()<<"]\t"<<"\t"<<tipController->get(i).getNomTipPer()<<endl;
		}
		cout<<"        Modificar Categoria:";
		cin>>categoria;
		Personal objNuevosDatos(objAModificar.getCodPersonal(),
							   nomApe,
							   usuario,
							   password,
							   categoria);
		bool estadoModificado = perController->modificar2(objAModificar,objNuevosDatos);
		if(estadoModificado = true)
		{
			cout<<"\n\n        Registro modificado satisfactoriamente\n";
			/*Grabar en archivo*/
			perController->grabarModificarEnArchivo();
		}
		else
		{
			cout<<"No se modifico el registro\n";				
		}
	}
	else
	{
		cout<<"No se encontro el codigo a buscar";			
	}
	system("pause");
	system("cls");
}

void eliminarPersonal()
{
	int codigo;
	gotoxy(4,4);cout<<"Ingrese el codigo a buscar:";
	cin>>codigo;
	Personal objAEliminar = perController->buscarPorCodigo(codigo);
	if(objAEliminar.getNomApePer()!="Error")
	{
		perController->eliminar(objAEliminar);
		gotoxy(4,6);cout<<"Registro eliminado satisfactoriamente\n";
		perController->grabarModificarEnArchivo();
	}
	else
	{
		gotoxy(4,6);cout<<"No se encontro el codigo a buscar\n";		
	}
	system("pause");
	system("cls");
}

void buscarPersonal()
{
	int codigo;
	gotoxy(4,4);cout<<"Ingrese el codigo a buscar:";
	cin>>codigo;
	
	Personal objPersonal = perController->buscarPorCodigo(codigo);	
	if(objPersonal.getNomApePer()!="Error")
	{
		gotoxy(4,6);cout<<"Codigo: "<<objPersonal.getCodPersonal()<<endl;
		gotoxy(4,7);cout<<"Nombre y Apellidos: "<<objPersonal.getNomApePer()<<endl;
		gotoxy(4,8);cout<<"Usuario: "<<objPersonal.getUsuPer()<<endl;
		gotoxy(4,9);cout<<"Categoria: "<<objPersonal.getCodTipPer()<<endl;
	}
	else
	{
		gotoxy(4,6);cout<<"No se encontro el codigo a buscar\n";		
	}
	system("pause");
	system("cls");
}

void listarPersonal()
{
	gotoxy(4,5);cout<<"CODIGO"<<"\t"<<"NOMBRES"<<"\t\t"<<"USUARIO"<< "\t\t" << "TIPO DE PERSONAL" << "\n";
	for(int i = 0;i<perController->size();i++)
	{
		int Nombre;
		cout<<"     "<<perController->get(i).getCodPersonal()<<"\t\t"<<perController->get(i).getNomApePer()<<"\t"
			<<perController->get(i).getUsuPer();
		Nombre = perController->get(i).getCodTipPer();
		
		TipoPersonal objTipoPersonal = tipController->buscarPorCodigo(Nombre);	
		if(objTipoPersonal.getNomTipPer()!="Error")
		{
			cout<<"         "<<objTipoPersonal.getNomTipPer()<<endl;
		}
	}
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	system("pause");
	system("cls");
}

void editarTipos()
{

	int opt;
	do
	{
		title();
		gotoxy(10,8);cout<<"********************************************************";
		gotoxy(10,9);cout<<"||                                                    ||";
		gotoxy(10,10);cout<<"||                     OPCIONES                       ||";
		gotoxy(10,11);cout<<"||    1. Nuevo Tipo de Personal-----------------[1]   ||";
		gotoxy(10,12);cout<<"||    2. Modificar Tipo de Personal-------------[2]   ||";
		gotoxy(10,13);cout<<"||    3. Eliminar Tipo de Personal--------------[3]   ||";
		gotoxy(10,14);cout<<"||    4. Buscar Tipo de Personal----------------[4]   ||";
		gotoxy(10,15);cout<<"||    5. Listar Tipo de Personal----------------[5]   ||";
		gotoxy(10,16);cout<<"||    6. Volver al Menu del Personal-----------[6]    ||";
		gotoxy(10,17);cout<<"||    7. Volver a Menu Principal---------------[7]    ||";
		gotoxy(10,18);cout<<"||                                                    ||";
		gotoxy(10,19);cout<<"*******************************************************";
		
		gotoxy(10,21);cout<<"_____________________________________";
		gotoxy(10,22);cout<<"|                                   |";
		gotoxy(10,23);cout<<"|    Ingrese una opcion:            |";
		gotoxy(10,24);cout<<"|___________________________________|";
		gotoxy(35,23);cin>>opt;
		
		switch(opt)
		{
		case 1:system("cls");nuevoTipoPersonal();break;
		case 2:system("cls");modificarTipoPersonal();break;
		case 3:system("cls");eliminarTipoPersonal();break;
		case 4:system("cls");buscarTipoPersonal();break;
		case 5:system("cls");listarTipoPersonal();break;
		case 6:system("cls");vistaPersonal();break;
		case 7:system("cls");menuPrincipal();break;
		default:system("cls");cout<<"Ingresa una opción correcta[1-7]\n";
		}
	}
	while(opt!=6);
}

void nuevoTipoPersonal()
{
	string flag;
	int 	codigo;
	string 	nomTipo;
	do
	{
		codigo = tipController->getCorrelativo();
		gotoxy(4,4);cout<<"        ******("<<codigo<<")*******\n";
		cin.ignore();
		gotoxy(4,5);cout<<"Tipo de Personal:";
		getline(cin,nomTipo);
		gotoxy(4,7);cout<<"Continuar(S/s):";
		cin>>flag;
		/*Crear el objeto de tipo alumno*/
		TipoPersonal objTipoPersonal(codigo,nomTipo);
		/*Agregar el objeto alarreglo*/
		tipController->add(objTipoPersonal);
		//grabar en archivo
		tipController->grabarEnArchivo(objTipoPersonal);
		system("cls");
	} 
	while(flag == "S" || flag == "s");
}

void modificarTipoPersonal()
{
	int codigo;
	gotoxy(4,4);cout<<"Ingrese el codigo a buscar:";
	cin>>codigo;
	TipoPersonal objAModificar = tipController->buscarPorCodigo(codigo);
	if(objAModificar.getNomTipPer() != "Error")
	{
		gotoxy(4,6);cout<<"Codigo:"<<objAModificar.getCodTipPer()<<endl;
		gotoxy(4,7);cout<<"Tipo de Personal:"<<objAModificar.getNomTipPer()<<endl;		
		cin.ignore();
		
		string  tipo;
		gotoxy(4,9);cout<<"---------------------------------------------\n";
		gotoxy(4,10);cout<<"Modificar Tipo de Personal:";
		TipoPersonal objNuevosDatos(objAModificar.getCodTipPer(),
									tipo);
		bool estadoModificado = tipController->modificar2(objAModificar,objNuevosDatos);
		if(estadoModificado = true)
		{
			cout<<"\n\n          Registro modificado satisfactoriamente\n";
			/*Grabar en archivo*/
			tipController->grabarModificarEnArchivo();
		}
		else
		{
			cout<<"No se modifico el registro\n";				
		}
	}
	else
	{
		cout<<"No se encontro el codigo a buscar";			
	}
	system("pause");
	system("cls");
}

void eliminarTipoPersonal()
{
	int codigo;
	gotoxy(4,4);cout<<"Ingrese el codigo a buscar:";
	cin>>codigo;
	TipoPersonal objAEliminar = tipController->buscarPorCodigo(codigo);
	if(objAEliminar.getNomTipPer()!="Error")
	{
		tipController->eliminar(objAEliminar);
		gotoxy(4,6);cout<<"Registro eliminado satisfactoriamente\n";
		tipController->grabarModificarEnArchivo();
	}
	else
	{
		gotoxy(4,6);cout<<"No se encontro el codigo a buscar\n";		
	}
	system("pause");
	system("cls");
}

void buscarTipoPersonal()
{
	int codigo;
	gotoxy(4,4);cout<<"Ingrese el codigo a buscar:";
	cin>>codigo;
	
	TipoPersonal objTipoPersonal = tipController->buscarPorCodigo(codigo);	
	if(objTipoPersonal.getNomTipPer()!="Error")
	{
		gotoxy(4,6);cout<<"Codigo: "<<objTipoPersonal.getCodTipPer()<<endl;
		gotoxy(4,7);cout<<"Tipo de Personal: "<<objTipoPersonal.getNomTipPer()<<endl;
	}
	else
	{
		gotoxy(4,6);cout<<"No se encontro el codigo a buscar\n";		
	}
	system("pause");
	system("cls");
}

void listarTipoPersonal()
{
	gotoxy(4,5);cout<<"\n     CODIGO"<<"\t"<<"TIPO DE PERSONAL"<<"\n";
		for(int i = 0;i<tipController->size();i++)
		{
			gotoxy(4,7+i);cout<<"    ["<<tipController->get(i).getCodTipPer()<<"]\t"<<"\t"<<tipController->get(i).getNomTipPer()<<endl;
		}
	system("pause");
	system("cls");
}

void editarCategoria()
{
	int opt;
	do
	{
		title();
		gotoxy(10,8);cout<<"********************************************************";
		gotoxy(10,9);cout<<"||                                                    ||";
		gotoxy(10,10);cout<<"||                     OPCIONES                       ||";
		gotoxy(10,11);cout<<"||    1. Nueva Categoria------------------------[1]   ||";
		gotoxy(10,12);cout<<"||    2. Modificar Categoria--------------------[2]   ||";
		gotoxy(10,13);cout<<"||    3. Eliminar Categoria---------------------[3]   ||";
		gotoxy(10,14);cout<<"||    4. Buscar Categoria-----------------------[4]   ||";
		gotoxy(10,15);cout<<"||    5. Listar Categorias----------------------[5]   ||";
		gotoxy(10,16);cout<<"||    6. Volver al Menu del Producto------------[6]   ||";
		gotoxy(10,17);cout<<"||    7. Volver a Menu Principal----------------[7]   ||";
		gotoxy(10,18);cout<<"||                                                    ||";
		gotoxy(10,19);cout<<"*******************************************************";
		
		gotoxy(10,21);cout<<"_____________________________________";
		gotoxy(10,22);cout<<"|                                   |";
		gotoxy(10,23);cout<<"|    Ingrese una opcion:            |";
		gotoxy(10,24);cout<<"|___________________________________|";
		gotoxy(35,23);cin>>opt;
		
		switch(opt)
		{
		case 1:system("cls");nuevaCategoria();break;
		case 2:system("cls");modificarCategoria();break;
		case 3:system("cls");eliminarCategoria();break;
		case 4:system("cls");buscarCategoria();break;
		case 5:system("cls");listarCategoria();break;
		case 6:system("cls");vistaProducto();break;
		case 7:system("cls");menuPrincipal();break;
		default:system("cls");cout<<"Ingresa una opción correcta[1-7]\n";
		}
	}
	while(opt!=6);
}

void nuevaCategoria()
{
	string flag;
	int 	codigo;
	string 	nomCategoria;
	do
	{
		codigo = catController->getCorrelativo();
		gotoxy(4,4);cout<<"        ******("<<codigo<<")*******\n";
		cin.ignore();
		gotoxy(4,5);cout<<"Categoria para producto:";
		getline(cin,nomCategoria);
		gotoxy(4,7);cout<<"Continuar(S/s):";
		cin>>flag;
		/*Crear el objeto de tipo alumno*/
		Categoria objCategoria(codigo,nomCategoria);
		/*Agregar el objeto alarreglo*/
		catController->add(objCategoria);
		//grabar en archivo
		catController->grabarEnArchivo(objCategoria);
		system("cls");
	} 
	while(flag == "S" || flag == "s");
}

void modificarCategoria()
{
	int codigo;
	gotoxy(4,4);cout<<"Ingrese el codigo a buscar:";
	cin>>codigo;
	Categoria objAModificar = catController->buscarPorCodigo(codigo);
	if(objAModificar.getNomCategoria() != "Error")
	{
		gotoxy(4,6);cout<<"Codigo:"<<objAModificar.getCodCategoria()<<endl;
		gotoxy(4,7);cout<<"Categoria:"<<objAModificar.getNomCategoria()<<endl;		
		cin.ignore();
		
		string  cate;
		gotoxy(4,9);cout<<"---------------------------------------------\n";
		gotoxy(4,10);cout<<"Modificar Categoria de productos:";
		getline(cin,cate);
		Categoria objNuevosDatos(objAModificar.getCodCategoria(),
									cate);
		bool estadoModificado = catController->modificar2(objAModificar,objNuevosDatos);
		if(estadoModificado = true)
		{
			cout<<"\n\n          Registro modificado satisfactoriamente\n";
			/*Grabar en archivo*/
			catController->grabarModificarEnArchivo();
		}
		else
		{
			cout<<"No se modifico el registro\n";				
		}
	}
	else
	{
		cout<<"No se encontro el codigo a buscar";			
	}
	system("pause");
	system("cls");
}

void eliminarCategoria()
{
	int codigo;
	gotoxy(4,4);cout<<"Ingrese el codigo a buscar:";
	cin>>codigo;
	Categoria objAEliminar = catController->buscarPorCodigo(codigo);
	if(objAEliminar.getNomCategoria()!="Error")
	{
		catController->eliminar(objAEliminar);
		gotoxy(4,6);cout<<"Registro eliminado satisfactoriamente\n";
		catController->grabarModificarEnArchivo();
	}
	else
	{
		gotoxy(4,6);cout<<"No se encontro el codigo a buscar\n";		
	}
	system("pause");
	system("cls");
}

void buscarCategoria()
{
	int codigo;
	gotoxy(4,4);cout<<"Ingrese el codigo a buscar:";
	cin>>codigo;
	
	Categoria objCategoria = catController->buscarPorCodigo(codigo);	
	if(objCategoria.getNomCategoria()!="Error")
	{
		gotoxy(4,6);cout<<"Codigo: "<<objCategoria.getCodCategoria()<<endl;
		gotoxy(4,7);cout<<"Tipo de Categoria: "<<objCategoria.getNomCategoria()<<endl;
	}
	else
	{
		gotoxy(4,6);cout<<"No se encontro el codigo a buscar\n";		
	}
	system("pause");
	system("cls");
}

void listarCategoria()
{
	gotoxy(4,5);cout<<"     CODIGO"<<"\t"<<"CATEGORIA"<<"\n";
	for(int i = 0;i<catController->size();i++)
	{
		gotoxy(4,6+i);cout<<"        ["<<catController->get(i).getCodCategoria()<<"]"<<"\t"<<catController->get(i).getNomCategoria()<<endl;
	}
	system("pause");
	system("cls");
}

void vistaCliente()
{
	int opt;
	do
	{
		title();
		gotoxy(10,8);cout<<"********************************************************";
		gotoxy(10,9);cout<<"||                                                    ||";
		gotoxy(10,10);cout<<"||                     OPCIONES                       ||";
		gotoxy(10,11);cout<<"||    1. Nuevo Cliente--------------------------[1]   ||";
		gotoxy(10,12);cout<<"||    2. Modificar Cliente----------------------[2]   ||";
		gotoxy(10,13);cout<<"||    3. Eliminar Cliente-----------------------[3]   ||";
		gotoxy(10,14);cout<<"||    4. Buscar Cliente-------------------------[4]   ||";
		gotoxy(10,15);cout<<"||    5. Listar Cliente-------------------------[5]   ||";
		gotoxy(10,16);cout<<"||    6. Volver a Menu Principal----------------[6]   ||";
		gotoxy(10,17);cout<<"||                                                    ||";
		gotoxy(10,18);cout<<"*******************************************************";
		
		gotoxy(10,20);cout<<"_____________________________________";
		gotoxy(10,21);cout<<"|                                   |";
		gotoxy(10,22);cout<<"|    Ingrese una opcion:            |";
		gotoxy(10,23);cout<<"|___________________________________|";
		gotoxy(35,22);cin>>opt;
		switch(opt)
		{
		case 1:system("cls");nuevoCliente();break;
		case 2:system("cls");modificarCliente();break;
		case 3:system("cls");eliminarCliente();break;
		case 4:system("cls");buscarCliente();break;
		case 5:system("cls");listarCliente();break;
		case 6:system("cls");menuPrincipal();break;
		default:system("cls");cout<<"Ingresa una opción correcta[1-6]\n";
		}
	}
	while(opt!=6);
}

void nuevoCliente()
{
	string flag;
	int 	codigo;
	string 	nomApe;
	string	direccion;
	int 	ruc;
	do
	{
		codigo = cliController->getCorrelativo();
		gotoxy(4,4);cout<<"        ******("<<codigo<<")*******\n";
		cin.ignore();
		gotoxy(4,5);cout<<"Nombres y Apellidos:";
		getline(cin,nomApe);
		gotoxy(4,6);cout<<"Direccion:";
		getline(cin,direccion);
		gotoxy(4,7);cout<<"RUC:";
		cin>>ruc;
		gotoxy(4,9);cout<<"Continuar(S/s):";
		cin>>flag;
		/*Crear el objeto de tipo alumno*/
		Cliente objCliente(codigo,nomApe,direccion,ruc);
		/*Agregar el objeto alarreglo*/
		cliController->add(objCliente);
		//grabar en archivo
		cliController->grabarEnArchivo(objCliente);
		system("cls");
	} 
	while(flag == "S" || flag == "s");
}

void modificarCliente()
{
	int codigo;
	gotoxy(4,4);cout<<"Ingrese el codigo a buscar:";
	cin>>codigo;
	Cliente objAModificar = cliController->buscarPorCodigo(codigo);
	if(objAModificar.getNomApeCli() != "Error")
	{
		gotoxy(4,6);cout<<"Codigo:"<<objAModificar.getCodCliente()<<endl;
		gotoxy(4,7);cout<<"Nombre y Apellidos:"<<objAModificar.getNomApeCli()<<endl;
		gotoxy(4,8);cout<<"Direccion:"<<objAModificar.getDirCli()<<endl;
		gotoxy(4,9);cout<<"RUC:"<<objAModificar.getRucCli()<<endl;		
		cin.ignore();
		
		string  nomApe,
				direccion;
		int 	ruc;
		gotoxy(4,11);cout<<"---------------------------------------------\n";
		gotoxy(4,12);cout<<"Modificar Nombres y Apellidos:";
		getline(cin,nomApe);
		gotoxy(4,13);cout<<"Modificar Direccion:";
		getline(cin,direccion);
		gotoxy(4,14);cout<<"Modificar RUC:";
		cin>>ruc;
		Cliente objNuevosDatos(objAModificar.getCodCliente(),
							  nomApe,
							  direccion,
							  ruc);
		bool estadoModificado = cliController->modificar2(objAModificar,objNuevosDatos);
		if(estadoModificado = true)
		{
			cout<<"\n\n          Registro modificado satisfactoriamente\n";
			/*Grabar en archivo*/
			cliController->grabarModificarEnArchivo();
		}
		else
		{
			cout<<"No se modifico el registro\n";				
		}
	}
	else
	{
		cout<<"No se encontro el codigo a buscar";			
	}
	system("pause");
	system("cls");
}

void eliminarCliente()
{
	int codigo;
	gotoxy(4,4);cout<<"Ingrese el codigo a buscar:";
	cin>>codigo;
	Cliente objAEliminar = cliController->buscarPorCodigo(codigo);
	if(objAEliminar.getNomApeCli()!="Error")
	{
		cliController->eliminar(objAEliminar);
		gotoxy(4,6);cout<<"Registro eliminado satisfactoriamente\n";
		cliController->grabarModificarEnArchivo();
	}
	else
	{
		cout<<"No se encontro el codigo a buscar\n";		
	}
	system("pause");
	system("cls");
}

void buscarCliente()
{
	int codigo;
	gotoxy(4,4);cout<<"Ingrese el codigo a buscar:";
	cin>>codigo;
	
	Cliente objCliente = cliController->buscarPorCodigo(codigo);	
	if(objCliente.getNomApeCli()!="Error")
	{
		gotoxy(4,6);cout<<"Codigo: "<<objCliente.getCodCliente()<<endl;
		gotoxy(4,7);cout<<"Nombre y Apellidos: "<<objCliente.getNomApeCli()<<endl;
		gotoxy(4,8);cout<<"Direccion: "<<objCliente.getDirCli()<<endl;
		gotoxy(4,9);cout<<"RUC: "<<objCliente.getRucCli()<<endl;
	}
	else
	{
		gotoxy(4,6);cout<<"No se encontro el codigo a buscar\n";		
	}
	system("pause");
	system("cls");
}

void listarCliente()
{
	gotoxy(4,5);cout<<"CODIGO"<<"\t"<<"NOMBRES"<<"\t\t"<<"DIRECCION"<< "\t" << "RUC" << "\t"<<"\n";
	for(int i = 0;i<cliController->size();i++)
	{
		cout<<"     "<<cliController->get(i).getCodCliente()<<"\t\t"<<cliController->get(i).getNomApeCli()<<"\t"
			<<cliController->get(i).getDirCli()
			<<"\t"<<cliController->get(i).getRucCli()<<endl;
	}
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	system("pause");
	system("cls");
}

int main()
{
	system("color 80");
	inicioSesion();
}

void vistaProducto()
{
	int opt;
	do
	{
		title();
		gotoxy(10,8);cout<<"********************************************************";
		gotoxy(10,9);cout<<"||                                                    ||";
		gotoxy(10,10);cout<<"||                     OPCIONES                       ||";
		gotoxy(10,11);cout<<"||    1. Nuevo Producto-------------------------[1]   ||";
		gotoxy(10,12);cout<<"||    2. Modificar Producto---------------------[2]   ||";
		gotoxy(10,13);cout<<"||    3. Eliminar Producto----------------------[3]   ||";
		gotoxy(10,14);cout<<"||    4. Buscar Producto------------------------[4]   ||";
		gotoxy(10,15);cout<<"||    5. Listar Producto------------------------[5]   ||";
		gotoxy(10,16);cout<<"||    6. Editar Categoria-----------------------[6]   ||";
		gotoxy(10,17);cout<<"||    7. Volver a Menu Principal----------------[7]   ||";
		gotoxy(10,18);cout<<"||                                                    ||";
		gotoxy(10,19);cout<<"*******************************************************";
		
		gotoxy(10,21);cout<<"_____________________________________";
		gotoxy(10,22);cout<<"|                                   |";
		gotoxy(10,23);cout<<"|    Ingrese una opcion:            |";
		gotoxy(10,24);cout<<"|___________________________________|";
		gotoxy(35,23);cin>>opt;
		switch(opt)
		{
		case 1:system("cls");nuevoProducto();break;
		case 2:system("cls");modificarProducto();break;
		case 3:system("cls");eliminarProducto();break;
		case 4:system("cls");buscarProducto();break;
		case 5:system("cls");listarProducto();break;
		case 6:system("cls");editarCategoria();break;
		case 7:system("cls");menuPrincipal();break;
		default:system("cls");cout<<"Ingresa una opción correcta[1-6]\n";
		}
	}
	while(opt!=6);
}

void nuevoProducto()
{
	string flag;
	int 	codigo;
	string 	producto;
	float	precio;
	int 	stock;
	int		categoria;
	do
	{
		codigo = proController->getCorrelativo();
		gotoxy(4,4);cout<<"        ******("<<codigo<<")*******\n";
		cin.ignore();
		gotoxy(4,6);cout<<"Producto:";
		getline(cin,producto);
		gotoxy(4,7);cout<<"Precio:";
		cin>>precio;
		gotoxy(4,8);cout<<"Stock:";
		cin>>stock;
		for(int i = 0;i<catController->size();i++)
		{
			cout<<"["<<catController->get(i).getCodCategoria()<<"]"<<"\t"<<catController->get(i).getNomCategoria()<<endl;
		}
		cout<<"\n    Categoria:";
		cin>>categoria;
		cout<<"    Continuar(S/s):";
		cin>>flag;
		/*Crear el objeto de tipo alumno*/
		Producto objProducto(codigo,producto,precio,stock,categoria);
		/*Agregar el objeto alarreglo*/
		proController->add(objProducto);
		//grabar en archivo
		proController->grabarEnArchivo(objProducto);
		system("cls");
	} 
	while(flag == "S" || flag == "s");
}

void modificarProducto()
{
	int codigo;
	gotoxy(4,4);cout<<"Ingrese el codigo a buscar:";
	cin>>codigo;
	Producto objAModificar = proController->buscarPorCodigo(codigo);
	if(objAModificar.getNomPro() != "Error")
	{
		gotoxy(4,6);cout<<"Codigo:"<<objAModificar.getCodProducto()<<endl;
		gotoxy(4,7);cout<<"Producto:"<<objAModificar.getNomPro()<<endl;
		gotoxy(4,8);cout<<"Precio:"<<objAModificar.getPrePro()<<endl;
		gotoxy(4,9);cout<<"Stock:"<<objAModificar.getStkPro()<<endl;
		gotoxy(4,10);cout<<"Categoria:"<<objAModificar.getCodCategoria()<<endl;
		cin.ignore();
		
		string  producto;
		float 	precio;
		int 	stock;
		int 	categoria;
		gotoxy(4,12);cout<<"---------------------------------------------\n";
		gotoxy(4,13);cout<<"Modificar Producto:";
		getline(cin,producto);
		gotoxy(4,14);cout<<"Modificar Precio:";
		cin>>precio;
		gotoxy(4,15);cout<<"Modificar Stock:";
		cin>>stock;
		gotoxy(4,17);cout<<"     CODIGO"<<"\t"<<"CATEGORIA"<<"\n";
		for(int i = 0;i<catController->size();i++)
		{
			gotoxy(4,18+i);cout<<"        ["<<catController->get(i).getCodCategoria()<<"]"<<"\t"<<catController->get(i).getNomCategoria()<<endl;
		}
		cout<<"        Modificar Categoria:";
		cin>>categoria;
		Producto objNuevosDatos(objAModificar.getCodProducto(),
								producto,
								precio,
								stock,
								categoria);
		bool estadoModificado = proController->modificar2(objAModificar,objNuevosDatos);
		if(estadoModificado = true)
		{
			cout<<"\n\n        Registro modificado satisfactoriamente\n";
			/*Grabar en archivo*/
			proController->grabarModificarEnArchivo();
		}
		else
		{
			cout<<"No se modifico el registro\n";				
		}
	}
	else
	{
		cout<<"No se encontro el codigo a buscar";			
	}
	system("pause");
	system("cls");
}

void eliminarProducto()
{
	int codigo;
	gotoxy(4,4);cout<<"Ingrese el codigo a buscar:";
	cin>>codigo;
	Producto objAEliminar = proController->buscarPorCodigo(codigo);
	if(objAEliminar.getNomPro()!="Error")
	{
		proController->eliminar(objAEliminar);
		gotoxy(4,6);cout<<"Registro eliminado satisfactoriamente\n";
		proController->grabarModificarEnArchivo();
	}
	else
	{
		gotoxy(4,6);cout<<"No se encontro el codigo a buscar\n";		
	}
	system("pause");
	system("cls");
}

void buscarProducto()
{
	int codigo;
	gotoxy(4,4);cout<<"Ingrese el codigo a buscar:";
	cin>>codigo;
	
	Producto objProducto = proController->buscarPorCodigo(codigo);	
	if(objProducto.getNomPro()!="Error")
	{
		gotoxy(4,6);cout<<"Codigo: "<<objProducto.getCodProducto()<<endl;
		gotoxy(4,7);cout<<"Producto: "<<objProducto.getNomPro()<<endl;
		gotoxy(4,8);cout<<"Precio: "<<objProducto.getPrePro()<<endl;
		gotoxy(4,9);cout<<"Stock: "<<objProducto.getStkPro()<<endl;
		gotoxy(4,10);cout<<"Categoria: "<<objProducto.getCodCategoria()<<endl;
	}
	else
	{
		gotoxy(4,6);cout<<"No se encontro el codigo a buscar\n";		
	}
	system("pause");
	system("cls");
}

void listarProducto()
{
	gotoxy(4,5);cout<<"CODIGO"<<"\t"<<"NOMBRE"<<"\t\t"<<"PRECIO"<< "\t" << "STOCK" <<"\tCATEGORIA"<<"\n";
	for(int i = 0;i<proController->size();i++)
	{
		int Nombre;
		cout<<"     "<<proController->get(i).getCodProducto()<<"\t\t"<<proController->get(i).getNomPro()<<"\t\t"
			<<proController->get(i).getPrePro()<<"\t"
			<<proController->get(i).getStkPro();
		Nombre = proController->get(i).getCodCategoria();
		
		Categoria objCategoria = catController->buscarPorCodigo(Nombre);
		if(objCategoria.getNomCategoria()!="Error")
		{
			cout<<"\t"<<objCategoria.getNomCategoria()<<endl;
		}
	}
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	system("pause");
	system("cls");
}

void vistaVenta()
{
	int cantidad;
	
	string rpta;
	string busPro;
	
	//Cliente
	int codCliente;
	//Personal
	int codPersonal;
	//Producto
	int codProducto;
	string fecha;
	//Factura
	float total=0;
	int state=0;

	
	title();
	
	gotoxy(15,9);cout<<"     Venta de Productos     "<<endl;
	gotoxy(13,10);cout<<"------------------------------"<<endl;
	gotoxy(14,12);cout<<"Venta ["<<venController->getCorrelativo()<<"]"<<endl;
	gotoxy(14,13);cout<<"Fecha de Venta: ";cin>>fecha;
	
	gotoxy(14,15);cout << "Codigo del cliente: ";cin >> codCliente;
	gotoxy(14,16);cout<<"---------------------------------------------\n"<<endl;
	
	Cliente cli = cliController->buscarPorCodigo(codCliente);
	gotoxy(14,17);cout<<"CLIENTE: "<<cli.getNomApeCli()<<endl;
	gotoxy(14,18);cout<<"RUC: "<<cli.getRucCli()<<"\tDIRECCION: "<<cli.getDirCli()<<endl;
	cout<<"\n";
	
	codPersonal = perController->busquedaPersonal(users);
	Personal vendedor;
	vendedor = perController->buscar(codPersonal);
	gotoxy(14,20);cout<<"VENDEDOR: "<<vendedor.getNomApePer()<<"\tCOD PERSONAL: "<<vendedor.getCodPersonal()<<endl;
	cout<<"\n";
	system("pause"); system("cls");
	
	do
	{
		title();
		cout << "\t\t   GENERANDO VENTA\n";
		cout << "\t--------------------------------------------\n";
		
		cin.ignore();
		gotoxy(5,11);cout << "Buscar producto por nombre: ";
		getline(cin, busPro); // espacio
		transform(busPro.begin(), busPro.end(), busPro.begin(), ::toupper);
		
		gotoxy(4,14);cout<<"\tCODIGO"<<"\tPRODUCTO"<<"\tPRECIO\n\n";
		proController->listarPorNombre(busPro);
		
		cout<<"\n\tCodigo de producto a comprar: ";
		cin>>codProducto;
		Producto pro = proController->buscarPorCodigo(codProducto);
		
		if (pro.getNomPro() != "ERROR")
		{
			cout<<"    ---------------------------------------";
			cout<<"\n\t***AGREGAR A SU LISTA DE COMPRAS***\n\n";
			cout<<"\t00"<<pro.getCodProducto()<<"\t"<<pro.getNomPro()<<"\t"<<pro.getPrePro()<<"\t"<<pro.getStkPro()<<endl;
		}
		else
		{
			cout<<"No se encontró el producto\n";break;
		}
		
		cout<<"\n\tCantidad a agregar: ";
		cin>>cantidad;
		
		while (cantidad>pro.getStkPro())
		{
			cout<<"\n\tStock Insuficiente, Ingrese cantidad nuevamente: "<<endl;
			cin>>cantidad;
		}
		
		DetalleVenta detail;
		detail.setCodVenta(venController->getCorrelativo());
		detail.setCodProducto(codProducto);
		detail.setCantidad(cantidad);
		detail.setPrecioVenta(pro.getPrePro());
		detController->add(detail);
		total += detail.getTotalParcial();
		cout<<"    ---------------------------------------\n";
		detController->listarProVenta(detail);
		
		cout<<"\n\tDesea seguir comprando? (S/N)   ";cin>>rpta;
		system ("cls");
	}
	while(rpta=="S" || rpta=="s");
	
	detController->grabarModificarEnArchivo();
	gotoxy(6,4);cout<<"____________________________"<<endl;
	gotoxy(6,5);cout<<"|                          |"<<endl;
	gotoxy(6,6);cout<<"|   ANULAR PEDIDOS? (0/1)  |"<<endl;
	gotoxy(6,7);cout<<"|__________________________|"<<endl;
	gotoxy(6,9);cin>>state;
	
	if (state==1)
	{
		Venta venta;
		venta.setCodVenta(venController->getCorrelativo());
		venta.setCodPersonal(codPersonal);
		venta.setCodCli(codCliente);
		venta.setFecVen(fecha);
		venta.setTotVen(total);
		venta.setEstVen(state);
		venController->add(venta);
		venController->grabarModificarEnArchivo();
	}
	else
	{
		Venta venta;
		venta.setCodVenta(venController->getCorrelativo());
		venta.setCodPersonal(codPersonal);
		venta.setCodCli(codCliente);
		venta.setFecVen(fecha);
		venta.setTotVen(total);
		venta.setEstVen(state);
		venController->add(venta);
		venController->grabarModificarEnArchivo();
	
		title();
		gotoxy(15,10);cout << "******** BOLETA VENTA MAS ********";
		gotoxy(8,12);cout<<"Fecha de Factura: "<<fecha<<endl;
		gotoxy(8,13);cout<<"Codigo de Venta: "<<venta.getCodVenta()<<endl;
		gotoxy(8,14);cout<<"Cliente: "<<cli.getNomApeCli()<<endl;
		gotoxy(35,14);cout<<"RUC Cliente: "<<cli.getRucCli()<<endl;
		gotoxy(8,15);cout<<"Vendedor: "<<vendedor.getNomApePer()<<endl;
	
		gotoxy(8,18);cout<<"Productos Comprados: "<<endl;
		cout<<"        --------------------------------------------------\n\n";
		for (int i=0; i<detController->size();i++)
		{
			cout<<"\tCOD. PRODUCTO: 000"<<detController->get(i).getCodProducto()<<endl;
			cout<<"\tCANTIDAD: "<<detController->get(i).getCantidad()<<endl;
			cout<<"\tPRECIO/UNIDAD: "<<detController->get(i).getPrecioVenta()<<endl;
			cout<<"        --------------------------------------------------\n\n";
		}
		cout<<"\t\tIMPORTE TOTAL: S/. "<<total<<"\n\n"<<endl;
		system("pause");
		system("cls");
	}
	
}