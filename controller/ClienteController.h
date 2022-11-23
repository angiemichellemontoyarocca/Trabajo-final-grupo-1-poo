#include <iostream>
#include <vector>
#include <fstream>
#include "../model/Cliente.h"

class ClienteController
{
	private:
		vector<Cliente> vectorCliente;
	public:
		ClienteController()
		{
			cargarDatosAlVector();
		}
		void add(Cliente obj)
		{
			vectorCliente.push_back(obj);
		}
		Cliente get(int posicion)
		{
			return vectorCliente[posicion];
		}
		int size()
		{
			return vectorCliente.size();
		}
		
		int getCorrelativo()
		{
			if(size() == 0)
			{
				return 1;
			}
			else
			{
				return 	vectorCliente[size() - 1].getCodCliente() + 1;
			}
		}
		Cliente buscarPorCodigo(int codCliente)
		{
			Cliente objError;
			objError.setNomApeCli("Error");
			for(int i = 0;i<vectorCliente.size();i++)	
			{
				if(codCliente == vectorCliente[i].getCodCliente())
				{
					return vectorCliente[i];
				}
			}
			return objError;
		}	
		
		Cliente buscarPorCodigo2(int codCliente)
		{
			Cliente objError;
			objError.setNomApeCli("Error");
			for(Cliente x:vectorCliente)	
			{
				if(codCliente == x.getCodCliente())
				{
					return x;
				}
			}
			return objError;
		}
		
		bool modificar(Cliente obj1EsElQueSeModifica,string nomApeCli,string dirCli,int rucCli)
		{
			for(int i=0;i<vectorCliente.size();i++)
			{
				if(obj1EsElQueSeModifica.getCodCliente() == vectorCliente[i].getCodCliente())
				{
					vectorCliente[i].setNomApeCli(nomApeCli);		
					vectorCliente[i].setDirCli(dirCli);
					vectorCliente[i].setRucCli(rucCli);
					return true;
				}
			}
			return false;
		}
		
		bool modificar2(Cliente obj1EsElQueSeModifica,Cliente DatosModificados)
		{
			for(int i=0;i<vectorCliente.size();i++)
			{
				if(obj1EsElQueSeModifica.getCodCliente() == vectorCliente[i].getCodCliente())
				{
					vectorCliente[i].setNomApeCli(DatosModificados.getNomApeCli());		
					vectorCliente[i].setDirCli(DatosModificados.getDirCli());
					vectorCliente[i].setRucCli(DatosModificados.getRucCli());
					return true;
				}
			}
			return false;
		}
		
		int getPostArray(Cliente obj)
		{
			for(int i=0;i<vectorCliente.size();i++)		
			{
				if(obj.getCodCliente() == vectorCliente[i].getCodCliente())	
				{
					return i;
				}
			}
			return -1;
		}
		
		void eliminar(Cliente obj)
		{
			vectorCliente.erase(vectorCliente.begin() + getPostArray(obj));
		}
		
		void grabarEnArchivo(Cliente obj)
		{
			try
			{
				fstream archivoCliente;
				archivoCliente.open("clientes.csv",ios::app);
				if(archivoCliente.is_open())
				{
					archivoCliente<<obj.getCodCliente()<<";"<<obj.getNomApeCli()<<";"<<obj.getDirCli()<<";"<<obj.getRucCli()<<";"<<endl;
					archivoCliente.close();					
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
				fstream archivoCliente;
				archivoCliente.open("clientes.csv",ios::out);
				if(archivoCliente.is_open())
				{
					for(Cliente x:vectorCliente)
					{
						archivoCliente<<x.getCodCliente()<<";"<<x.getNomApeCli()<<";"<<x.getDirCli()<<";"<<x.getRucCli()<<";"<<endl;					
					}
					archivoCliente.close();					
				}
			}
			catch(exception e)
			{
				cout<<"Ocurrio un error al grabar el archivo";
			}		
		}
		
		void cargarDatosAlVector()
		{
			try
			{
				int 	i;
				size_t 	posi;
				string 	linea;
				string 	temporal[4];
				fstream	archivoCliente;
				archivoCliente.open("clientes.csv",ios::in);
				if(archivoCliente.is_open())
				{
					while(!archivoCliente.eof() && getline(archivoCliente,linea))
					{
						i = 0;
						while((posi = linea.find(";")) != string::npos)
						{
							temporal[i] = linea.substr(0,posi);
							linea.erase(0,posi+1);
							++i;
						}
						
						Cliente objCliente(stoi(temporal[0]),temporal[1],
											 temporal[2],stoi(temporal[3]));
						
						add(objCliente);
					}
				}
			}
			catch(exception e)
			{
				cout<<"Ocurrio un error al grabar el archivo";
			}
		}
};
