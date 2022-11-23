#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../model/Venta.h"
using namespace std;


class VentaController
{
	private:
		vector<Venta> vectorVenta;
	public:
		VentaController()
		{
			//cargarDatosDelArchivoAlVector();
		}
		void add(Venta obj)
		{
			vectorVenta.push_back(obj);
		}
		Venta get(int posicion)
		{
			return vectorVenta[posicion];
		}
		int size()
		{
			return vectorVenta.size();
		}
		int getCorrelativo()
		{
			int i = 1;
   			try
  			{
        		size_t posi;
        		string linea;
        		string temporal[7];
        		fstream archivoVenta;
        		archivoVenta.open("ventas.csv", ios::in);

        		if (archivoVenta.is_open())
        		{	
            		while (!archivoVenta.eof())
            		{
                		while (getline(archivoVenta, linea))
               			{
                    		i++;
                		}
            		}
            		archivoVenta.close();
        		}
    		}
    		catch(exception e)
    		{
        		cout << "OCURRIO UN ERROR AL LEER EL ARCHIVO\n";
   			}
    			return i;   
		}
		
		void grabarModificarEnArchivo()
		{
			try
			{
				fstream archivoVenta;
				archivoVenta.open("ventas.csv",ios::app);
				if(archivoVenta.is_open())
				{
					for(Venta x:vectorVenta)
					{
						archivoVenta<<x.getCodVenta()<<";"<<x.getCodPersonal()<<";"<<x.getCodCli()<<";"<<x.getFecVen()<<";"<<x.getTotVen()<<";"<<x.getEstVen()<<";"<<endl;					
					}
					archivoVenta.close();					
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
				string 	temporal[6];
				fstream	archivoVenta;
				archivoVenta.open("ventas.csv",ios::in);
				if(archivoVenta.is_open())
				{
					while(!archivoVenta.eof() && getline(archivoVenta,linea))
					{
						i = 0;
						while((posi = linea.find(";")) != string::npos)
						{
							temporal[i] = linea.substr(0,posi);
							linea.erase(0,posi+1);
							++i;
						}
						
						Venta objVenta(stoi(temporal[0]),stoi(temporal[1]),
									   stoi(temporal[2]),temporal[3],
									   stof(temporal[4]),stoi(temporal[5]));
						
						add(objVenta);
					}
				}
				archivoVenta.close();
			}
			catch(exception e)
			{
				cout<<"Ocurrio un error al grabar el archivo";
			}
		}
};
