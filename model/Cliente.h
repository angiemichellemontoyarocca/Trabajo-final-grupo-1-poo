#include <iostream>
using namespace std;

class Cliente
{
	private:
		int codCliente;
		string nomApeCli;
		string dirCli;
		int rucCli;
	public:
		Cliente()
		{
			
		}
		~Cliente()
		{
			
		}
		Cliente (int codigo,string name,string direc,int ruc)
		{
			this->codCliente=codigo;
			this->nomApeCli=name;
			this->dirCli=direc;
			this->rucCli=ruc;
		}
		//Setter
		void setCodCliente(int codCliente)
		{
			this->codCliente=codCliente;
		}
		void setNomApeCli(string nomApeCli)
		{
			this->nomApeCli=nomApeCli;
		}
		void setDirCli(string dirCli)
		{
			this->dirCli=dirCli;
		}
		void setRucCli(int rucCli)
		{
			this->rucCli=rucCli;
		}
		//Getters
		int getCodCliente()
		{
			return this->codCliente;
		}
		string getNomApeCli()
		{
			return this->nomApeCli;
		}
		string getDirCli()
		{
			return this->dirCli;
		}
		int getRucCli()
		{
			return this->rucCli;
		}
};
