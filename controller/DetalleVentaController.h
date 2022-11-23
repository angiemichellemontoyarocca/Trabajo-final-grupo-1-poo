#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "../model/DetalleVenta.h"
using namespace std;

class DetalleVentaController
{
	private:
		vector<DetalleVenta> vectorDetalleVenta;
	public:
		DetalleVentaController()
		{
			
		}
		void add(DetalleVenta obj)
		{
			vectorDetalleVenta.push_back(obj);
		}
		DetalleVenta get(int posicion)
		{
			return vectorDetalleVenta[posicion];
		}
		int size()
		{
			return vectorDetalleVenta.size();
		}
		void grabarModificarEnArchivo()
		{
			try
			{
				fstream archivoDetalleVenta;
				archivoDetalleVenta.open("detalles.csv",ios::app);
				if(archivoDetalleVenta.is_open())
				{
					for(DetalleVenta x:vectorDetalleVenta)
					{
						archivoDetalleVenta<<x.getCodVenta()<<";"<<x.getCodProducto()<<";"<<x.getCantidad()<<";"<<x.getPrecioVenta()<<";"<<endl;					
					}
					archivoDetalleVenta.close();					
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
				string 	temporal[4];
				fstream	archivoDetalleVenta;
				archivoDetalleVenta.open("detalles.csv",ios::in);
				if(archivoDetalleVenta.is_open())
				{
					while(!archivoDetalleVenta.eof() && getline(archivoDetalleVenta,linea))
					{
						i = 0;
						while((posi = linea.find(";")) != string::npos)
						{
							temporal[i] = linea.substr(0,posi);
							linea.erase(0,posi+1);
							++i;
						}
						
						DetalleVenta objDetalleVenta(stoi(temporal[0]),stoi(temporal[1]),
									   stoi(temporal[2]),stof(temporal[3]));
						
						add(objDetalleVenta);
					}
				}
				archivoDetalleVenta.close();
			}
			catch(exception e)
			{
				cout<<"Ocurrio un error al grabar el archivo";
			}
		}
		
		void listarProVenta(DetalleVenta obj)
		{
			cout<<"\n\tCodigo de producto: "<<obj.getCodProducto()<<endl;
			cout<<"\tCantidad del producto: "<<obj.getCantidad()<<endl;
			cout<<"\tSubtotal: "<<obj.getTotalParcial()<<endl;
		}
};
