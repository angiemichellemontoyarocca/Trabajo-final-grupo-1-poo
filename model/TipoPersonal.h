#include <iostream>
using namespace std;

class TipoPersonal
{
	private:
		int codTipPer;
		string nomTipPer;
	public:
		TipoPersonal()
		{
			
		}
		~TipoPersonal()
		{
			
		}
		TipoPersonal (int codigo,string tipo)
		{
			this->codTipPer=codigo;
			this->nomTipPer=tipo;
		}
		//Setters
		void setCoDTipPer(int codTipPer)
		{
			this->codTipPer=codTipPer;
		}
		void setNomTipPer(string nomTipPer)
		{
			this->nomTipPer=nomTipPer;
		}
		//Getters
		int getCodTipPer()
		{
			return this->codTipPer;
		}
		string getNomTipPer()
		{
			return this->nomTipPer;
		}
};
