#include <iostream>
#include <vector>
#include <fstream>
#include "../model/Personal.h"
using namespace std;

class PersonalController
{
	private: 
		vector<Personal> vectorPersonal; //Crear arreglo de objetos
	public:
		PersonalController()
		{
			cargarDatosDelArchivoAlVector();
		}
		//Agregar objetos al Arreglo
		void add(Personal obj)
		{
			vectorPersonal.push_back(obj);
		}
		
		Personal get(int pos)
		{
			return vectorPersonal[pos];
		}
		
		int size()
		{
			return vectorPersonal.size();
		}
		
		int getCorrelativo()
		{
			if(size() == 0)
			{
				return 1;
			}
			else
			{
				return 	vectorPersonal[size() - 1].getCodPersonal() + 1;
			}
		}
		
		Personal buscarPorCodigo(int codPersonal)
		{
			Personal objError;
			objError.setNomApePer("Error");
			for(int i = 0;i<vectorPersonal.size();i++)	
			{
				if(codPersonal == vectorPersonal[i].getCodPersonal())
				{
					return vectorPersonal[i];
				}
			}
			return objError;
		}	
		
		Personal buscarPorCodigo2(int codPersonal)
		{
			Personal objError;
			objError.setNomApePer("Error");
			for(Personal x:vectorPersonal)	
			{
				if(codPersonal == x.getCodPersonal())
				{
					return x;
				}
			}
			return objError;
		}
		
		bool modificar(Personal obj1EsElQueSeModifica,string nomApePer,string usuPer,string passPer,int codTipPer)
		{
			for(int i=0;i<vectorPersonal.size();i++)
			{
				if(obj1EsElQueSeModifica.getCodPersonal() == vectorPersonal[i].getCodPersonal())
				{
					vectorPersonal[i].setNomApePer(nomApePer);		
					vectorPersonal[i].setUsuPer(usuPer);
					vectorPersonal[i].setPassPer(passPer);
					vectorPersonal[i].setCodTipPer(codTipPer);
					return true;
				}
			}
			return false;
		}
		
		bool modificar2(Personal obj1EsElQueSeModifica,Personal DatosModificados)
		{
			for(int i=0;i<vectorPersonal.size();i++)
			{
				if(obj1EsElQueSeModifica.getCodPersonal() == vectorPersonal[i].getCodPersonal())
				{
					vectorPersonal[i].setNomApePer(DatosModificados.getNomApePer());		
					vectorPersonal[i].setUsuPer(DatosModificados.getUsuPer());
					vectorPersonal[i].setPassPer(DatosModificados.getPassPer());
					vectorPersonal[i].setCodTipPer(DatosModificados.getCodTipPer());
					return true;
				}
			}
			return false;
		}
		
		int getPostArray(Personal obj)
		{
			for(int i=0;i<vectorPersonal.size();i++)		
			{
				if(obj.getCodPersonal() == vectorPersonal[i].getCodPersonal())	
				{
					return i;
				}
			}
			return -1;
		}
		
		void eliminar(Personal obj)
		{
			vectorPersonal.erase(vectorPersonal.begin() + getPostArray(obj));
		}
		
		void grabarEnArchivo(Personal obj)
		{
			try
			{
				fstream archivoPersonal;
				archivoPersonal.open("personal.csv",ios::app);
				if(archivoPersonal.is_open())
				{
					archivoPersonal<<obj.getCodPersonal()<<";"<<obj.getNomApePer()<<";"<<obj.getUsuPer()<<";"<<obj.getPassPer()<<";"<<obj.getCodTipPer()<<";"<<endl;
					archivoPersonal.close();					
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
				fstream archivoPersonal;
				archivoPersonal.open("personal.csv",ios::out);
				if(archivoPersonal.is_open())
				{
					for(Personal x:vectorPersonal)
					{
						archivoPersonal<<x.getCodPersonal()<<";"<<x.getNomApePer()<<";"<<x.getUsuPer()<<";"<<x.getPassPer()<<";"<<x.getCodTipPer()<<";"<<endl;					
					}
					archivoPersonal.close();					
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
				fstream	archivoPersonal;
				archivoPersonal.open("personal.csv",ios::in);
				if(archivoPersonal.is_open())
				{
					while(!archivoPersonal.eof() && getline(archivoPersonal,linea))
					{
						i = 0;
						while((posi = linea.find(";")) != string::npos)
						{
							temporal[i] = linea.substr(0,posi);
							linea.erase(0,posi+1);
							++i;
						}
						
						Personal objPersonal(stoi(temporal[0]),temporal[1],
										 temporal[2],temporal[3],stoi(temporal[4]));
						
						add(objPersonal);
					}
				}
			}
			catch(exception e)
			{
				cout<<"Ocurrio un error al grabar el archivo";
			}
		}
		
		Personal buscar(int);
		int busquedaPersonal(string);
		bool verificarDatos(string, string);
};

Personal PersonalController::buscar(int dato)
{
	Personal objError;
	objError.setUsuPer("Error");
	for (int i = 0; i < vectorPersonal.size(); i++)
	{
		if (dato == vectorPersonal[i].getCodPersonal())
		{
			return vectorPersonal[i];
		}
	}
	return objError;
}
int PersonalController::busquedaPersonal(string dato)
{
	for (int i = 0; i < vectorPersonal.size(); i++)
	{
		if (dato == vectorPersonal[i].getUsuPer())
		{
			return vectorPersonal[i].getCodPersonal();
		}
	}
	return -1;
}
bool PersonalController::verificarDatos(string user, string contra)
{
	for (int i = 0; i < vectorPersonal.size(); i++)
	{
		if (user == vectorPersonal[i].getUsuPer() && contra == vectorPersonal[i].getPassPer()) // verifica si la contrase�a y el usuario son iguales
		{
			return true;
		}
	}
	return false;
}