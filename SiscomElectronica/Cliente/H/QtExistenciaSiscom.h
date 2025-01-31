#ifndef __QTEXISTENCIASISCOM_H__
#define __QTEXISTENCIASISCOM_H__
#include <UIC_H_ExistenciaSiscom.h>


class zSiscomRegistro;
class zProductos;
class zProducto;
class QtExistenciaSiscom:public ExistenciaSiscom
{
Q_OBJECT
public:
	QtExistenciaSiscom(QWidget *pQWParent=0,
			   const char *pchrPtrName=0,
			   WFlags pWFlasg=0);
public:
	void ConectaSlots();
	void IniciaVariables();
	zProductos *Productos();
	zProducto *Producto();
	void MuestraProductos(zProductos *);
	FILE *Archivo();
	void AbreArchivo();
	void CierraArchivo();
 	
private:
	zSiscomRegistro *zSisRegProducto;
	zProductos *zProds;
	FILE *FlePtrArchivo;
private:
	void Producto(zSiscomRegistro *);
	void IniciaProductos();
	void IniciaFechas();


	virtual void ProductosSiscom();
	virtual void ConsultaProductos();
	virtual void ConsultaTodo();
	virtual void GuardaArchivo();
private slots:
	void SlotSeleccionoProducto(zSiscomRegistro *);
	void SlotFocoAFechaFin();
	void SlotFocoAProductos();
	void SlotConsultaT();
	void SlotGuardaArchivo();
};

#endif
