#include <iostream>
using namespace std;

class Categoria
{
	private:
		int codCategoria;
		string nomCategoria;
	public:
		Categoria()
		{
			
		}
		~Categoria()
		{
			
		}
		Categoria(int codigo,string nombre)
		{
			this->codCategoria=codigo;
			this->nomCategoria=nombre;
		}
		//Setters
		void setCodCategoria(int codCategoria)
		{
			this->codCategoria=codCategoria;
		}
		void setNomCategoria(string nomCategoria)
		{
			this->nomCategoria=nomCategoria;
		}
		//Getters
		int getCodCategoria()
		{
			return this->codCategoria;
		}
		string getNomCategoria()
		{
			return this->nomCategoria;
		}
};
