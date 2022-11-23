#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include"../model/Producto.h"
using namespace std;

class ProductoController
{
	private:
		vector<Producto> vectorProducto;
	public:
		ProductoController()
		{
			cargarDatosDelArchivoAlVector();
		}
		//Agregar objetos al arreglo
		void add(Producto obj)
		{
			vectorProducto.push_back(obj);
		}
		
		Producto get(int posicion)
		{
			return vectorProducto[posicion];
		}
		
		int size()
		{
			return vectorProducto.size();
		}
		
		int getCorrelativo()
		{
			if(size() == 0)
			{
				return 1;
			}
			else
			{
				return 	vectorProducto[size() - 1].getCodProducto() + 1;
			}
		}
		
		Producto buscarPorCodigo(int codigo)
		{
			Producto objError;
			objError.setNomPro("Error");
			for(int i = 0;i<vectorProducto.size();i++)	
			{
				if(codigo == vectorProducto[i].getCodProducto())
				{
					return vectorProducto[i];
				}
			}
			return objError;
		}	

		bool modificar2(Producto obj1EsElQueSeModifica,Producto DatosModificados)
		{
			for(int i=0;i<vectorProducto.size();i++)
			{
				if(obj1EsElQueSeModifica.getCodProducto() == vectorProducto[i].getCodProducto())
				{
					vectorProducto[i].setNomPro(DatosModificados.getNomPro());		
					vectorProducto[i].setPrePro(DatosModificados.getPrePro());
					vectorProducto[i].setStkPro(DatosModificados.getStkPro());
					vectorProducto[i].setCodCategoria(DatosModificados.getCodCategoria());
					return true;
				}
			}
			return false;
		}
		
		int getPostArray(Producto obj)
		{
			for(int i=0;i<vectorProducto.size();i++)		
			{
				if(obj.getCodProducto() == vectorProducto[i].getCodProducto())	
				{
					return i;
				}
			}
			return -1;
		}
		
		void eliminar(Producto obj)
		{
			vectorProducto.erase(vectorProducto.begin() + getPostArray(obj));
		}
		
		void grabarEnArchivo(Producto obj)
		{
			try
			{
				fstream archivoProducto;
				archivoProducto.open("productos.csv",ios::app);
				if(archivoProducto.is_open())
				{
					archivoProducto<<obj.getCodProducto()<<";"<<obj.getNomPro()<<";"<<obj.getPrePro()<<";"<<obj.getStkPro()<<";"<<obj.getCodCategoria()<<";"<<endl;
					archivoProducto.close();					
				}
			}
			catch(exception e)
			{
				cout<<"Ocurrio un error al grabar el archivo";
			}
		}
		
		void grabarModificarEnArchivo()
		{
			try
			{
				fstream archivoProducto;
				archivoProducto.open("productos.csv",ios::out);
				if(archivoProducto.is_open())
				{
					for(Producto x:vectorProducto)
					{
						archivoProducto<<x.getCodProducto()<<";"<<x.getNomPro()<<";"<<x.getPrePro()<<";"<<x.getStkPro()<<";"<<x.getCodCategoria()<<";"<<endl;					
					}
					archivoProducto.close();					
				}
			}
			catch(exception e)
			{
				cout<<"Ocurrio un error al grabar el archivo";
			}		
		}
		
		void cargarDatosDelArchivoAlVector()
		{
			try
			{
				int 	i;
				size_t 	posi;
				string 	linea;
				string 	temporal[5];
				fstream	archivoProducto;
				archivoProducto.open("productos.csv",ios::in);
				if(archivoProducto.is_open())
				{
					while(!archivoProducto.eof() && getline(archivoProducto,linea))
					{
						i = 0;
						while((posi = linea.find(";")) != string::npos)
						{
							temporal[i] = linea.substr(0,posi);
							linea.erase(0,posi+1);
							++i;
						}
						
						Producto objProducto(stoi(temporal[0]),temporal[1],
										 stof(temporal[2]),stoi(temporal[3]),stoi(temporal[4]));
						
						add(objProducto);
					}
				}
			}
			catch(exception e)
			{
				cout<<"Ocurrio un error al grabar el archivo";
			}
		}
		void listarPorNombre(string);
};

void ProductoController::listarPorNombre(string dato)
{	
	for (size_t i = 0; i < vectorProducto.size(); ++i)
	{
		const string& nombre = vectorProducto[i].getNomPro();

		if (std::string::size_type pos = nombre.find(dato); pos != std::string::npos)
		{
			cout	<< "\t000" << vectorProducto[i].getCodProducto() 
					<<"\t"<<vectorProducto[i].getNomPro()
					<<"\t\t"<<vectorProducto[i].getPrePro()<<endl;
		}
		else
		{
			cout << "\t----------------------\n";
		}
	}

}

