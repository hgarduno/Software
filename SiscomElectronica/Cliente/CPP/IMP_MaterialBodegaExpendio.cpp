#include <IMP_MaterialBodegaExpendio.h>

#include <QCtrlExpendios.h>
#include <QCtrlProdSiscomElectronica.h>
#include <QCtrlBodegas.h>
#include <CQSis3QtOperaciones.h>
#include <SiscomDesarrollo3Qt++.h>

#include <SiscomRegistros3.h>

#include <CQSisProdBodExpendio.h>

#include <qtextedit.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qmessagebox.h>
#include <stdlib.h>
/*
 * Para el caso de la transferencia de material, como ahorita se tiene
 * esta mal planteado, de una bodega se puede transferir el material 
 * al cualquiera de los expendios, por lo tanto se debera cambiar 
 * los IconView, para que primero se seleccione la bodega, y despues
 * el expendio al que se desea transferir el material.
 *
 * De cualquier bodega se podra transferir el material a cualquier
 * expendio, entonces se debe eliminar la dependencia de la bodega
 * y el expendio
 */
QMaterialBodegaExpendio *InstanciaMaterialBodegaExpendio(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QMaterialBodegaExpendio((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QMaterialBodegaExpendio::QMaterialBodegaExpendio(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				MaterialBodegaExpendio(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)

{
IniciaVariables();
ConectaSlots();
}

QMaterialBodegaExpendio::~QMaterialBodegaExpendio()
{
 
}

void QMaterialBodegaExpendio::ConectaSlots()
{
	connect(QCtrBodegas,
		SIGNAL(SignalBodega(SiscomRegistro3 *)),
		SLOT(SlotBodega(SiscomRegistro3 *)));
	connect(QCtrExpendios,
		SIGNAL(SignalExpendio(SiscomRegistro3 *)),
		SLOT(SlotExpendio(SiscomRegistro3 *)));
	connect(QCtrProductos,
		SIGNAL(SignalSeleccionando(SiscomRegistro3 *)),
		SLOT(SlotSeleccionando(SiscomRegistro3 *)));
	connect(QCtrProductos,
		SIGNAL(SignalSelecciono(SiscomRegistro3 *)),
		SLOT(SlotSelecciono(SiscomRegistro3 *)));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAnexar()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(SlotAnexar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionaProducto(int,int,int,const QPoint &)));
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(SlotEliminar()));


}
void QMaterialBodegaExpendio::SlotEliminar()
{
/*
 * Sabado 13 De Agosto 2011 
 * Se requiere implementar el codigo para eliminar los 
 * productos de la lista ya que esto, al no estar terminado
 * ha dado muchos problemas en la operacion diaria 
 *
*/
EliminaProductosLista();
}
void QMaterialBodegaExpendio::SlotSeleccionaProducto(int pintNFila,
						     int,
						     int,
						     const QPoint &)
{
QTDatos->selectRow(pintNFila);
}
void QMaterialBodegaExpendio::SlotRegistra()
{
SiscomRegistro3Lst lSisReg3LstRegreso;
CQSis3QtOperaciones lCQSis3QtOpTransfiere(SisDatCom);
lCQSis3QtOpTransfiere.TransfiereMaterialBodegaExpendio(&SisReg3LstProductos,
						       &lSisReg3LstRegreso);
ValidaEstadoOperacion(&lSisReg3LstRegreso);

ReIniciaDatos();
}
void QMaterialBodegaExpendio::SlotAnexar()
{
   AnexaProducto();
   SiscomDesarrollo3Qt::PasaFocoControl(QCtrProductos);
}
void QMaterialBodegaExpendio::SlotPasaFocoAnexar()
{
if(ValidacionExistenciaCantidad())
{
QPBAnexar->setEnabled(true);
SiscomDesarrollo3Qt::PasaFocoControl(QPBAnexar);
}
}
void QMaterialBodegaExpendio::SlotSelecciono(SiscomRegistro3 *pSisReg3Producto)
{
	if(pSisReg3Producto)
	{
	   SisReg3Producto=pSisReg3Producto;
	   DesHabilitaExpendiosBodegas(false);
	   SiscomDesarrollo3Qt::PasaFocoControl(QLECantidad);
	   ConsultandoExistenciaProducto();
	}

}
void QMaterialBodegaExpendio::SlotSeleccionando(SiscomRegistro3 *pSisReg3Producto)
{
	if(pSisReg3Producto)
	{
	   SisReg3Producto=pSisReg3Producto;
	   QTEDescripcion->setText((*SisReg3Producto)["dscproducto"]);
	}
}
void QMaterialBodegaExpendio::SlotBodega(SiscomRegistro3 *pSisReg3Bodega)
{
	
	SisReg3Bodega=pSisReg3Bodega;
	SiscomDesarrollo3Qt::PasaFocoControl(QCtrExpendios);
}
void QMaterialBodegaExpendio::SlotExpendio(SiscomRegistro3 *pSisReg3Expendio)
{
	SisReg3Expendio=pSisReg3Expendio;
	SiscomDesarrollo3Qt::PasaFocoControl(QCtrProductos);
}
void QMaterialBodegaExpendio::IniciaVariables()
{
  QCtrExpendios->Servidor(SisDatCom);
  QCtrExpendios->Expendio(chrPtrArgumentos[0]);
  QCtrExpendios->IniciaControl();

  QCtrProductos->Servidor(SisDatCom);
  QCtrProductos->IdExpendio(*chrPtrArgumentos);
  QCtrProductos->IniciaControl();
  ConsultandoBodegas();
  QPBAnexar->setEnabled(false);
  QPBRegistrar->setEnabled(false);
}
void QMaterialBodegaExpendio::closeEvent(QCloseEvent *)
{
	emit SignalTerminar(this);
}
void QMaterialBodegaExpendio::EliminaProductosLista()
{
int lintContador;
int lintContadorJ=0;
QMemArray<int> lQMAEliminados(QTDatos->numRows());
for(lintContador=0;
    lintContador<QTDatos->numRows();
    lintContador++)
if(QTDatos->isRowSelected(lintContador,true))
lQMAEliminados[lintContadorJ++]=lintContador;

/*
 * Sabado 13 Agosto 2011 
 * Es importante tener siempre presente, cuando al trabajar 
 * con QPtrList, y debemos eliminar de la lista varios registros
 * que cada que eliminamos un elemento el tamano del arreglo 
 * cambia, por lo que la forma correcta debemos eliminar los
 * elementos por referencia, en el caso de los productos para eliminar
 * debemos utilizar la nueva funcion SiscomEliminaRegistros, pasando
 * los numeros de las posiciones de los registros que debemos eliminar
 * y de manera interna la funcion obtendra las direcciones de los nodos
 * para eliminarlos
 */
if(lQMAEliminados.count())
SisReg3LstProductos=SisReg3LstProductos.SiscomEliminaRegistros(lQMAEliminados);
else
SiscomEscribeLog3Qt("No se ha seleccionado Productos Para eliminar");
/*
 * Sabado 13 Agosto 2011 
 * Cuando trabajemos con QMemArray, debemos considerar siempre la llamada
 * a resize, una vez que tengamos completos los datos con lo que trabajaremos
 */
lQMAEliminados.resize(lintContadorJ);
QTDatos->removeRows(lQMAEliminados);
}
void QMaterialBodegaExpendio::ConsultandoBodegas()
{

  QCtrBodegas->Servidor(SisDatCom);
  QCtrBodegas->Expendio(chrPtrArgumentos[0]);
  QCtrBodegas->IniciaControl();
}
void QMaterialBodegaExpendio::DesHabilitaExpendiosBodegas(bool pbolEstado)
{
	QCtrExpendios->setEnabled(pbolEstado);
	QCtrBodegas->setEnabled(pbolEstado);
}

void QMaterialBodegaExpendio::ConsultandoExistenciaProducto()
{
ConsultaExistenciaProducto();
MuestraExistenciaProducto();

}
void QMaterialBodegaExpendio::ConsultaExistenciaProducto()
{
CQSis3QtOperaciones lCQSis3QtOp(SisDatCom);
SisReg3LstExiProdBodega.clear();
lCQSis3QtOp.ExistenciaProductoBodega(chrPtrArgumentos[0],
				     SisReg3Bodega,
				     SisReg3Producto,
				     &SisReg3LstExiProdBodega);
}
void QMaterialBodegaExpendio::MuestraExistenciaProducto()
{
	if((SisReg3ProductoBodega=SisReg3LstExiProdBodega[0]))
	QLEExistencia->setText((*SisReg3ProductoBodega)["existencia"]);
}

void QMaterialBodegaExpendio::AnexaProducto()
{
const char *lchrPtrCampos[]={"cveproducto",
		       "Cantidad",
		       "existencia",
		       0};
CQSisProdBodExpendio *lCQSisProdBodExp;
int lintNFila;
	lintNFila=QTDatos->numRows();
	QTDatos->setNumRows(lintNFila+1);
	lCQSisProdBodExp=FormaProdBodExpendio();
	SisReg3LstProductos <<  lCQSisProdBodExp;
	SiscomDesarrollo3Qt::RegistroALaTabla(lintNFila,
					      QTDatos,
					      lchrPtrCampos,
					      lCQSisProdBodExp);
	QPBRegistrar->setEnabled(QTDatos->numRows());
}

CQSisProdBodExpendio *QMaterialBodegaExpendio::FormaProdBodExpendio()
{
return new CQSisProdBodExpendio(
	    SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLECantidad),
	    chrPtrArgumentos[0],
	    chrPtrArgumentos[1],
	    SisReg3ProductoBodega,
	    SisReg3Expendio,
	    SisReg3Bodega);

}
void QMaterialBodegaExpendio::ValidaEstadoOperacion(SiscomRegistro3Lst *pSisReg3LstEstado)

{
SiscomRegistro3 *lSisReg3Estado=(*pSisReg3LstEstado)[0];
if(lSisReg3Estado)
   if((*lSisReg3Estado)["Error"][0]=='0')
   QMessageBox::information(this,
   			    "Mensaje Del Sistema",
			    (*lSisReg3Estado)["Mensaje"]);
}
void QMaterialBodegaExpendio::ReIniciaDatos()
{
	QTDatos->setNumRows(0);
	SisReg3LstProductos.clear();
	DesHabilitaExpendiosBodegas(true);
}

int QMaterialBodegaExpendio::ValidacionExistenciaCantidad()
{

if(SisReg3ProductoBodega)
{
int lintExistencia=atoi((*SisReg3ProductoBodega)["existencia"]);
int lintCantidad=QLECantidad->text().toInt();

return lintExistencia	> 0 &&
       lintCantidad 	> 0       &&
       lintCantidad 	<= lintExistencia;
}
else
return 0;
}

