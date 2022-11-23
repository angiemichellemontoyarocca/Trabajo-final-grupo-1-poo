#include <iostream>
using namespace std;

class DetalleVenta
{
	private:
		int codVenta;
		int codProducto;
		int cantidad;
		float precioVenta;
	public:
		DetalleVenta()
		{
			
		}
		~DetalleVenta()
		{
			
		}
		DetalleVenta(int codigo,int codiProduct,int productos,float total)
		{
			this->codVenta=codigo;
			this->codProducto=codiProduct;
			this->cantidad=productos;
			this->precioVenta=total;
		}
		//Setters
		void setCodVenta(int codVenta)
		{
			this->codVenta=codVenta;
		}
		void setCodProducto(int codProducto)
		{
			this->codProducto=codProducto;
		}
		void setCantidad(int cantidad)
		{
			this->cantidad=cantidad;
		}
		void setPrecioVenta(float precioVenta)
		{
			this->precioVenta=precioVenta;
		}
		//Getters
		int getCodVenta()
		{
			return this->codVenta;
		}
		int getCodProducto()
		{
			return this->codProducto;
		}
		int getCantidad()
		{
			return this->cantidad;
		}
		float getPrecioVenta()
		{
			return this->precioVenta;
		}
		float getTotalParcial()
		{
			return getPrecioVenta()*getCantidad();
		}
};
