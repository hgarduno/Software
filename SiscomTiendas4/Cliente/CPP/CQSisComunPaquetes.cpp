#include <CQSisComunPaquetes.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisPaquetes.h>
#include <SiscomDatCom.h>
#include <qtable.h>
CQSisProductosPaquete::CQSisProductosPaquete(SiscomDatCom *pSisDatCom,
					     QTable *pQTProductos,
					     QObject *pQOParent,
					     const char *pchrPtrName):
				QObject(pQOParent,pchrPtrName),
				SisDatCom(pSisDatCom),
				QTProductos(pQTProductos)
{
ConectaSlots();
}

void CQSisProductosPaquete::ProductosPaquete(const char *pchrPtrIdPaquete)
{
	ConsultaProductosPaquete(pchrPtrIdPaquete);
	MuestraProductosPaquete();
}
void CQSisProductosPaquete::ConsultaProductosPaquete(const char *pchrPtrIdPaquete)
{
SReg3LstProductos.clear();
CQSisOpPaquetes lCQSOPaquete(SisDatCom);
lCQSOPaquete.ProductosDelPaquete(pchrPtrIdPaquete,
				 &SReg3LstProductos);
}
void CQSisProductosPaquete::MuestraProductosPaquete()
{
const char *lchrPtrCampos[]={"clave",
		       "dsc",
		       "cantidad",
		       0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,QTProductos,&SReg3LstProductos);
SiscomDesarrollo3Qt::AjustaColumnas(QTProductos);
SiscomDesarrollo3Qt::AjustaFilas(QTProductos);
}

void CQSisProductosPaquete::ConectaSlots()
{
	connect(QTProductos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotProducto(int,int,int,const QPoint &)));
}


void CQSisProductosPaquete::SlotProducto(int pintNProducto,
					 int,
					 int,
					 const QPoint &)
{
QTProductos->selectRow(pintNProducto);
emit SignalProducto(SReg3LstProductos[pintNProducto]);
}
