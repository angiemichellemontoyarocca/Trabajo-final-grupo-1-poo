#include <iostream>
using namespace std;

class Venta
{
	private:
		int codVenta;
		int codPersonal;
		int codCli;
		string fecVen;
		float totVen;
		int estVen;
	public:
		Venta()
		{
			
		}
		~Venta()
		{
			
		}
		Venta(int venta,int personal,int cliente,string fecha,float total,int estado)
		{
			this->codVenta=venta;
			this->codPersonal=personal;
			this->codCli=cliente;
			this->fecVen=fecha;
			this->totVen=total;
			this->estVen=estado;
		}
		//Setters
		void setCodVenta(int codVenta)
		{
			this->codVenta=codVenta;
		}
		void setCodPersonal(int codPersonal)
		{
			this->codPersonal=codPersonal;
		}
		void setCodCli(int codCli)
		{
			this->codCli=codCli;
		}
		void setFecVen(string fecVen)
		{
			this->fecVen=fecVen;
		}
		void setTotVen(float totVen)
		{
			this->totVen=totVen;
		}
		void setEstVen(int estVen)
		{
			this->estVen=estVen;
		}
		//Getters
		int getCodVenta()
		{
			return this->codVenta;
		}
		int getCodPersonal()
		{
			return this->codPersonal;
		}
		int getCodCli()
		{
			return this->codCli;
		}
		string getFecVen()
		{
			return this->fecVen;
		}
		float getTotVen()
		{
			return this->totVen;
		}
		int getEstVen()
		{
			return this->estVen;
		}
};
