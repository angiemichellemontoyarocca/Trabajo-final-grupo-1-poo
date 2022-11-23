#include <iostream>
using namespace std;
class Personal
{
	private:
		int codPersonal;
		string nomApePer;
		string usuPer;
		string passPer;
		int codTipPer;
	public:
		Personal()
		{

		}
		~Personal()
		{
		
		}
		Personal(int cod,string nombre,string usuario,string password,int codTipo)
		{
			this->codPersonal=cod;
			this->nomApePer=nombre;
			this->usuPer=usuario;
			this->passPer=password;
			this->codTipPer=codTipo;
		}
		//set
		void setCodPersonal(int codPersonal)
		{
			this->codPersonal=codPersonal;
		}
		void setNomApePer(string nomApePer)
		{
			this->nomApePer=nomApePer;
		}
		void setUsuPer(string usuPer)
		{
			this->usuPer=usuPer;
		}
		void setPassPer(string passPer)
		{
			this->passPer=passPer;
		}
		void setCodTipPer(int codTipPer)
		{
			this->codTipPer=codTipPer;
		}
		//get
		int getCodPersonal()
		{
			return this->codPersonal;
		}
		string getNomApePer()
		{
			return this->nomApePer;
		}
		string getUsuPer()
		{
			return this->usuPer;
		}
		string getPassPer()
		{
			return this->passPer;
		}
		int getCodTipPer()
		{
			return this->codTipPer;
		}
};
