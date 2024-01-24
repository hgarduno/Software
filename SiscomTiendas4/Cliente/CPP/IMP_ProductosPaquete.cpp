#include <IMP_ProductosPaquete.h>
#include <IMP_AnexarProducto.h>
#include<SISCOMComunicaciones++.h>
#include <CQSisPaquetes.h>
#include <SiscomDesarrollo3Qt++.h>

#include <qpushbutton.h>
#include <qmessagebox.h>
QProductosPaquete::QProductosPaquete(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    const char *pchrPtrIdPaquete,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ProductosPaquete(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				chrPtrIdPaquete(pchrPtrIdPaquete),
				chrPtrIdProducto(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QProductosPaquete::~QProductosPaquete()
{

}

void QProductosPaquete::ConectaSlots()
{
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(SlotElimina()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(SlotAnexar()));
	connect(QPBCCantidad,
		SIGNAL(clicked()),
		SLOT(SlotCambiarCantidad()));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionaProducto(int,int,int,const QPoint &)));

}
void QProductosPaquete::SlotSeleccionaProducto(int pintProducto,
					       int,
					       int,
					       const QPoint &)
{
  if(pintProducto!=-1)
  {
  chrPtrIdProducto=(*SReg3LstProductos[pintProducto])["idproducto"];
  QTDatos->selectRow(pintProducto);
  }
}
void QProductosPaquete::SlotElimina()
{
if(chrPtrIdProducto)
{
CQSisOpPaquetes lCQSOPaquetes(SisDatCom);
lCQSOPaquetes.EliminaProducto(chrPtrIdPaquete,chrPtrIdProducto);
chrPtrIdProducto=0;
Consultando();
}
else
QMessageBox::information(this,
			 "Aviso Del Sistema",
			 "No se ha seleccionado un producto del");
				
}
void QProductosPaquete::SlotAnexar()
{
CQSisPaqueteProducto *lCQSPProducto;
QAnexarProducto lQAProducto(SisDatCom,
			    chrPtrArgumentos,
			    chrPtrIdPaquete);
lCQSPProducto=lQAProducto.Producto();
CQSisOpPaquetes lCQSOPaquetes(SisDatCom);
lCQSOPaquetes.AnexarProducto(lCQSPProducto);
Consultando();
}
void QProductosPaquete::SlotCambiarCantidad()
{

}
void QProductosPaquete::IniciaVariables()
{
Consultando();
}
void QProductosPaquete::Consultando()
{
Consulta();
Muestra();

}
void QProductosPaquete::Consulta()
{
SReg3LstProductos.clear();
CQSisOpPaquetes lCQSOPaquete(SisDatCom);
lCQSOPaquete.ProductosDelPaquete(chrPtrIdPaquete,
				 &SReg3LstProductos);
}
void QProductosPaquete::Muestra()
{
const char *lchrPtrCampos[]={"clave",
		       "dsc",
		       "cantidad",
		       0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,QTDatos,&SReg3LstProductos);
SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
SiscomDesarrollo3Qt::AjustaFilas(QTDatos);
}

