#include <iostream>
using namespace std;

class Producto
{
	private:
		int codProducto;
		string nomPro;
		float prePro;
		int stkPro;
		int codCategoria;
	public:
		Producto()
		{
			
		}
		~Producto()
		{
			
		}
		Producto(int codigoP,string product,float precio,int stock,int codigoC)
		{
			this->codProducto=codigoP;
			this->nomPro=product;
			this->prePro=precio;
			this->stkPro=stock;
			this->codCategoria=codigoC;
		}
		//Setters
		void setCodProducto(int codProducto)
		{
			this->codProducto=codProducto;
		}
		void setNomPro(string nomPro)
		{
			this->nomPro=nomPro;
		}
		void setPrePro(float prePro)
		{
			this->prePro=prePro;
		}
		void setStkPro(int stkPro)
		{
			this->stkPro=stkPro;
		}
		void setCodCategoria(int codCategoria)
		{
			this->codCategoria=codCategoria;
		}
		//Getters
		int getCodProducto()
		{
			return this->codProducto;
		}
		string getNomPro()
		{
			return this->nomPro;
		}
		float getPrePro()
		{
			return this->prePro;
		}
		int getStkPro()
		{
			return this->stkPro;
		}
		int getCodCategoria()
		{
			return this->codCategoria;
		}
};
