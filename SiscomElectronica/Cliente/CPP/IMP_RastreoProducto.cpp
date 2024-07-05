#include <IMP_RastreoProducto.h>
#include <IMP_TotalVentasProducto.h>
#include <IMP_TotalComprasProducto.h>
#include <IMP_TransferenciasBodegasExpendio.h>
#include <IMP_TransferenciasExpendioExpendio.h>
#include <IMP_ProductosConDesajuste.h>
#include <SiscomDesarrollo3Qt++.h>

#include <CQSisRastreoProducto.h>
#include <IMP_QControlFecha.h>
#include <QCtrlProdSiscomElectronica.h>

#include <qlineedit.h>
#include <qtable.h>
#include <qpushbutton.h>


QRastreoProducto *InstanciaRastreoProducto(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRastreoProducto((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRastreoProducto::QRastreoProducto(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RastreoProducto(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				CQSRastreoProducto(0)
{
IniciaVariables();
ConectaSlots();
}

QRastreoProducto::~QRastreoProducto()
{

}


void QRastreoProducto::RastreaProducto(SiscomRegistro3 *pSisReg3Producto)
{
  IniciaRastreoProducto(pSisReg3Producto);
  RastreandoProducto();
}
void QRastreoProducto::RastreandoProducto()
{
  EnviaRastreo();
  MuestraRastreo();
}
void QRastreoProducto::EnviaRastreo()
{
CQSisRastreandoProducto lCQSRastreandoP(SisDatCom);
lCQSRastreandoP.Rastrea(CQSRastreoProducto);
}
void QRastreoProducto::MuestraRastreo()
{
MuestraExistencia();
MuestraExistenciaBodegas();
MuestraVentasProducto();
MuestraActualizoInventario();
MuestraComprasProducto();
MuestraTransferenciasBodegasExpendio();
MuestraTransferenciasExpendioExpendio();
MuestraTransferenciaBodegaBodega();
SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
SiscomDesarrollo3Qt::AjustaFilas(QTDatos);
}
void QRastreoProducto::MuestraExistencia()
{
QLEEExpendio->setText(CQSRastreoProducto->ExistenciaExpendio());
QLEEBodegas->setText(CQSRastreoProducto->ExistenciaBodegas());	 
}

void QRastreoProducto::MuestraExistenciaBodegas()
{
 
 QTDatos->setCellWidget(1,0,ExistenciaBodegas());
}

void QRastreoProducto::MuestraVentasProducto()
{
QTDatos->setCellWidget(1,1,new QTotalVentasProducto(CQSRastreoProducto));
}
void QRastreoProducto::MuestraComprasProducto()
{
QTDatos->setCellWidget(3,0,new QTotalComprasProducto(CQSRastreoProducto));
}


void QRastreoProducto::MuestraTransferenciasBodegasExpendio()
{
QTDatos->setCellWidget(5,0,new QTransferenciasBodegasExpendio(CQSRastreoProducto));
}
void QRastreoProducto::MuestraTransferenciasExpendioExpendio()
{
QTDatos->setCellWidget(5,1,new QTransferenciasExpendioExpendio(CQSRastreoProducto));
}
void QRastreoProducto::MuestraTransferenciaBodegaBodega()
{
QTDatos->setCellWidget(7,0,TransferenciaBodegaBodega());
}
void QRastreoProducto::MuestraActualizoInventario()
{
QTDatos->setCellWidget(3,1,ActualizoInventario());
}
void QRastreoProducto::ConectaSlots()
{
   connect(QCtrFechaIni,
   	   SIGNAL(Signal_EnterA_o()),
	   SLOT(SlotPasaFocoFechaFin()));

   connect(QCtrFechaFin,
   	   SIGNAL(Signal_EnterA_o()),
	   SLOT(SlotPasaFocoProductos()));

   connect(QCtrProductos,
   	   SIGNAL(SignalSelecciono(SiscomRegistro3 *)),
	   SLOT(SlotProducto(SiscomRegistro3 *)));
   connect(QPBPCDesajuste,
   	   SIGNAL(clicked()),
	   SLOT(SlotProductosConDesajuste()));
}
void QRastreoProducto::SlotProductosConDesajuste()
{
QProductosConDesajuste lCQPCDesajuste(SisDatCom,chrPtrArgumentos);
					
}
void QRastreoProducto::SlotPasaFocoFechaFin()
{
SiscomDesarrollo3Qt::PasaFocoControl(QCtrFechaFin);

}
void QRastreoProducto::SlotProducto(SiscomRegistro3 *pSisReg3Producto)
{
SiscomEscribeLog3Qt("Iniciando El rastreo de:%s",
		    (*pSisReg3Producto)["cveproducto"]);
RastreaProducto(pSisReg3Producto);
MuestraEncabezados();
}
void QRastreoProducto::SlotPasaFocoProductos()
{
    SiscomDesarrollo3Qt::PasaFocoControl(QCtrProductos);
}
void QRastreoProducto::IniciaVariables()
{
QCtrProductos->Servidor(SisDatCom);
QCtrProductos->IdExpendio(*chrPtrArgumentos);
QCtrProductos->IniciaControl();
QCtrFechaIni->ColocaFechaHoy();
QCtrFechaFin->ColocaFechaHoy();
SiscomDesarrollo3Qt::PasaFocoControl(QCtrFechaIni);
QTDatos->setNumRows(8);
}

void QRastreoProducto::closeEvent(QCloseEvent *)
{
   emit SignalTerminar(this);
}
void QRastreoProducto::IniciaRastreoProducto(SiscomRegistro3 *pSisReg3Producto)
{
  if(CQSRastreoProducto)
     delete CQSRastreoProducto;
     CQSRastreoProducto=new CQSisRastreoProducto(
     			       (SiscomRegistro3 *)chrPtrArgumentos[5],
			       pSisReg3Producto,
			       (const char *)QCtrFechaIni->ObtenFecha(),
			       (const char *)QCtrFechaFin->ObtenFecha());
}
QTable *QRastreoProducto::ExistenciaBodegas()
{
QTable *lQTable=new QTable(0,0,this);
const char *lchrPtrCampos[]={"bodega","existencia",0};
lQTable->setNumCols(2);
lQTable->horizontalHeader()->setLabel(0,"Bodega");
lQTable->horizontalHeader()->setLabel(1,"Existencia");
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
				       lQTable,
				       CQSRastreoProducto->ExistenciasBodegas());
SiscomDesarrollo3Qt::AjustaColumnas(lQTable);
return lQTable;
}

QTable *QRastreoProducto::ActualizoInventario()
{
QTable *lQTable=new QTable(0,0,this);
const char *lchrPtrCampos[]={"idresponsable",
			"idexpendio",
			"fecharegistro",
			"hora",
			0};
lQTable->setNumCols(4);
lQTable->horizontalHeader()->setLabel(0,"idresponsable");
lQTable->horizontalHeader()->setLabel(1,"idexpendio");
lQTable->horizontalHeader()->setLabel(2,"fecharegistro");
lQTable->horizontalHeader()->setLabel(3,"hora");
if(!CQSRastreoProducto->EdoConsultaActualizoInventario())
{
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
				       lQTable,
				       CQSRastreoProducto->ActualizoInventario());
SiscomDesarrollo3Qt::AjustaColumnas(lQTable);
}
return lQTable;
}
QTable *QRastreoProducto::TransferenciaBodegaBodega()
{
QTable *lQTable=new QTable(0,0,this);
const char *lchrPtrCampos[]={"fecha",
			"bodegaorigen",
			"bodegadestino",
			"cantidad",
			"cveproducto",
			0};
lQTable->setNumCols(5);
lQTable->horizontalHeader()->setLabel(0,"Fecha");
lQTable->horizontalHeader()->setLabel(1,"Bodega Origen");
lQTable->horizontalHeader()->setLabel(2,"Bodega Destino");
lQTable->horizontalHeader()->setLabel(3,"Cantidad");
lQTable->horizontalHeader()->setLabel(4,"Producto");
if(!CQSRastreoProducto->EdoConsultaActualizoInventario())
{
SiscomRegistro3LstContenido(CQSRastreoProducto->TransferenciaBodegaBodega());
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
				       lQTable,
				       CQSRastreoProducto->TransferenciaBodegaBodega());
SiscomDesarrollo3Qt::AjustaColumnas(lQTable);
}
return lQTable;
}
void QRastreoProducto::MuestraEncabezados()
{
   QTDatos->setText(0,0,"Existencia Bodegas"); 
   QTDatos->setText(0,1,"Ventas del Producto");
   QTDatos->setText(2,0,"Compras del Producto");
   QTDatos->setText(2,1,"Actualizacion Inventario");
   QTDatos->setText(4,0,"Transferencias Bodega A Expendio");
   QTDatos->setText(4,1,"Transferencias Expendio A Expendio");
   QTDatos->setText(6,0,"Transferencias Bodega A Bodega");


}
