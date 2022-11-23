#include <iostream>
#include <vector>
#include <fstream>
#include "../model/TipoPersonal.h"
using namespace std;

class TipoPersonalController
{
private:
	vector<TipoPersonal> vectorTipoPersonal;
public:
	TipoPersonalController()
	{
		cargarDatosDelArchivoAlVector();
	}
	//Agregar objetos al arreglo
	void add(TipoPersonal obj)
	{
		vectorTipoPersonal.push_back(obj);
	}
	
	TipoPersonal get(int posicion)
	{
		return vectorTipoPersonal[posicion];
	}
	
	int size()
	{
		return vectorTipoPersonal.size();
	}
	
	int getCorrelativo()
	{
		if(size() == 0)
		{
			return 1;
		}
		else
		{
			return 	vectorTipoPersonal[size() - 1].getCodTipPer() + 1;
		}
	}
	
	TipoPersonal buscarPorCodigo(int codigo)
	{
		TipoPersonal objError;
		objError.setNomTipPer("Error");
		for(int i = 0;i<vectorTipoPersonal.size();i++)	
		{
			if(codigo == vectorTipoPersonal[i].getCodTipPer())
			{
				return vectorTipoPersonal[i];
			}
		}
		return objError;
	}	
	
	bool modificar2(TipoPersonal obj1EsElQueSeModifica,TipoPersonal DatosModificados)
	{
		for(int i=0;i<vectorTipoPersonal.size();i++)
		{
			if(obj1EsElQueSeModifica.getCodTipPer() == vectorTipoPersonal[i].getCodTipPer())
			{
				vectorTipoPersonal[i].setNomTipPer(DatosModificados.getNomTipPer());		
				return true;
			}
		}
		return false;
	}
	int getPostArray(TipoPersonal obj)
	{
		for(int i=0;i<vectorTipoPersonal.size();i++)		
		{
			if(obj.getCodTipPer() == vectorTipoPersonal[i].getCodTipPer())	
			{
				return i;
			}
		}
		return -1;
	}
	void eliminar(TipoPersonal obj)
	{
		vectorTipoPersonal.erase(vectorTipoPersonal.begin() + getPostArray(obj));
	}
	void grabarEnArchivo(TipoPersonal obj)
	{
		try
		{
			fstream archivoTipoPersonal;
			archivoTipoPersonal.open("tipopersonal.csv",ios::app);
			if(archivoTipoPersonal.is_open())
			{
				archivoTipoPersonal<<obj.getCodTipPer()<<";"<<obj.getNomTipPer()<<";"<<endl;
				archivoTipoPersonal.close();					
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
			fstream archivoTipoPersonal;
			archivoTipoPersonal.open("tipopersonal.csv",ios::out);
			if(archivoTipoPersonal.is_open())
			{
				for(TipoPersonal x:vectorTipoPersonal)
				{
					archivoTipoPersonal<<x.getCodTipPer()<<";"<<x.getNomTipPer()<<";"<<endl;					
				}
				archivoTipoPersonal.close();					
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
			string 	temporal[2];
			fstream	archivoTipoPersonal;
			archivoTipoPersonal.open("tipopersonal.csv",ios::in);
			if(archivoTipoPersonal.is_open())
			{
				while(!archivoTipoPersonal.eof() && getline(archivoTipoPersonal,linea))
				{
					i = 0;
					while((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0,posi);
						linea.erase(0,posi+1);
						++i;
					}
					
					TipoPersonal objTipoPersonal(stoi(temporal[0]),temporal[1]);
					
					add(objTipoPersonal);
				}
			}
		}
		catch(exception e)
		{
			cout<<"Ocurrio un error al grabar el archivo";
		}
	}
};
