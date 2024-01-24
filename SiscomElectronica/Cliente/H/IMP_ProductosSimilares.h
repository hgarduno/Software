#ifndef __IMP_PRODUCTOSSIMILARES_H__
#define __IMP_PRODUCTOSSIMILARES_H__
#include <UIC_H_ProductosSimilares.h>
class zSiscomConexion;
class zSiscomRegistros;
class zProductos;
class zSiscomRegistro;
class QProductosSimilares:public ProductosSimilares
{
 Q_OBJECT
public:
	QProductosSimilares(const  char *pchrPtrCriterio,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QProductosSimilares();
	int Producto(char *pchrPtrClave);
	zProductos *Seleccionados();
	int HayVariosSeleccionados();
	int Aceptar();
	int SiHayAlgunProducto();
private:
	zSiscomConexion *zSisConexion;
	const char *chrPtrCriterio;
	zSiscomRegistros *zSisRegsProductos;
	zProductos *zProdSeleccionados;
	
	int intAceptar;
	int intProducto;

	int intSiHayAlgunProducto;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void Muestra();
	void MostrandoDescripcion(int );
	void AgregaProductoSeleccionado(zSiscomRegistro *);
	void ProductosSeleccionados();
	void Selecciono();
private slots:
	void SlotMostrando(int,int);
	void SlotAceptar();
	void SlotSelecciono(int,int,int,const QPoint &);
	void SlotSeleccionando();
};
#endif
