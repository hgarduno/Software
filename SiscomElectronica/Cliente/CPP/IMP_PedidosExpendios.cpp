#include <IMP_PedidosExpendios.h>
#include <IMP_CapturaDato.h>
#include <IMP_QControlFecha.h>
#include <IMP_AccionTraspasoBodegaExp.h>
#include <CQSis3QtOperaciones.h>
#include <CQSisWidgetPedidoExpendio.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomRegistros3.h>
#include <SiscomRegistrosPro2.h>

#include <zSiscomElectronica.h> 
#include <zSiscomDesarrollo4.h>


#include <qtable.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <qtabwidget.h>
QPedidosExpendios *InstanciaPedidosExpendios(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QPedidosExpendios((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QPedidosExpendios::QPedidosExpendios(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				PedidosExpendios(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				intEstadoPedido(0),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				intDesactivaValidacionCantidad(0)
{
IniciaVariables();
ConectaSlots();
}

QPedidosExpendios::~QPedidosExpendios()
{

}

void QPedidosExpendios::ConectaSlots()
{
connect(QTPedidos,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionandoPedido(int,int,int,const QPoint &)));
connect(QPBTransfiere,
	SIGNAL(clicked()),
	SLOT(SlotTransfierePedido()));
connect(QPBConsultaPedidos,
	SIGNAL(clicked()),
	SLOT(SlotConsultaPedidos()));
connect(QTProductos,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionoProducto(int,int,int,const QPoint &)));


connect(QPBImprime,
	SIGNAL(clicked()),
	SLOT(SlotImprime()));
connect(QCtrFechaInicio,
	SIGNAL(Signal_EnterA_o()),
	SLOT(SlotFocoAFechaFin()));
connect(QCtrFechaFin,
	SIGNAL(Signal_EnterA_o()),
	SLOT(SlotFocoAConsultar()));

connect(QPBAInventario,SIGNAL(clicked()),SLOT(SlotActualizaInventario()));
connect(QPBDesactivaValCantidad,SIGNAL(clicked()),SLOT(SlotDesactivaValCantidad()));
connect(QPBTranBodegaExp,SIGNAL(clicked()),SLOT(SlotTranBodegaExpendio()));
}
void QPedidosExpendios::SlotTranBodegaExpendio()
{
	CQSPedidosExps.Observaciones(intPedidoSeleccionado,
				     intProductoSeleccionado,
				     "De Bodega a Expendio");
	TransfiriendoBodegaAExpendio();
	Consultando();
	SlotSeleccionandoPedido(intPedidoSeleccionado,0,0,QPoint());
	HabilitaTransfiereEInventario(false);


}
void QPedidosExpendios::SlotDesactivaValCantidad()
{
 DesactivaValidacionCantidad();
 QPBDesactivaValCantidad->setText(TextoEstadoValidacionCantidad());
}
void QPedidosExpendios::SlotActualizaInventario()
{
ActualizaInventario();
/*
ColoreaBlanco();
*/
Consultando();
SlotSeleccionandoPedido(intPedidoSeleccionado,0,0,QPoint());
HabilitaTransfiereEInventario(false);
}
void QPedidosExpendios::SlotFocoAFechaFin()
{
SiscomDesarrollo3Qt::PasaFoco(QCtrFechaFin);
}

void QPedidosExpendios::SlotFocoAConsultar()
{
SiscomDesarrollo3Qt::PasaFoco(QPBConsultaPedidos);
}
void QPedidosExpendios::SlotImprime()
{
Imprime();
}
void QPedidosExpendios::SlotSeleccionoProducto(int pintProducto,
					       int pintColumna,
					       int,
					       const QPoint &)
{

  if(pintProducto!=-1)
  {
    intProductoSeleccionado=pintProducto;
    QTProductos->selectRow(pintProducto);
    if(pintColumna==1)
    if(CambiaCantidad(pintProducto))
    {
     	if(ValidaExistencia())
	{
	}
    	Consultando();
    	SlotSeleccionandoPedido(intPedidoSeleccionado,0,0,QPoint());
    }
    HabilitaTransfiereEInventario(true);
    }
}
void QPedidosExpendios::SlotConsultaPedidos()
{
   Consultando();
}
void QPedidosExpendios::SlotTransfierePedido()
{
int lintEdoTransferencia;
if(!(intEstadoPedido=lintEdoTransferencia=TransfierePedido()))
ActualizaEstadoPedido("3");
else
if(lintEdoTransferencia==1)
{
ActualizaEstadoPedido("1");
QMessageBox::information(this,"Aviso del Sistema","Hay Productos Que no Alcanzan");
}
else
if(lintEdoTransferencia==2)
ActualizaEstadoPedido("2");
Consultando();
SiscomEscribeLog3Qt("El estado de la transferencia:%d",lintEdoTransferencia);
QPBTransfiere->setEnabled(false);
QPBImprime->setEnabled(false);
}
void QPedidosExpendios::SlotSeleccionandoPedido(int pintFila,
						int,
						int,
						const QPoint &)
{
SiscomRegistro3Lst *lSisReg3LstProductos;
char *lchrPtrCampos[]={"cveproducto","cantidad","existencia","exbodegas","observacion",0};
int lintEstadoPedido=1;
const char *lchrPtrIdEstado;
if(pintFila!=-1)
{
if((lSisReg3LstProductos=CQSPedidosExps.RegistrosSubGrupo(pintFila,1)))
{
lintEstadoPedido=HabilitaEnvio(CQSPedidosExps.IdEstado(pintFila));
QPBTransfiere->setEnabled(lintEstadoPedido);
QPBTransfiere->setEnabled(lintEstadoPedido);
//QPBImprime->setEnabled(lintEstadoPedido);
QPBImprime->setEnabled(true);

QTPedidos->selectRow(pintFila);
QTEObservaciones->setText(CQSPedidosExps.Observaciones(pintFila));
MuestraProductosPedido(0,lSisReg3LstProductos);
SiscomDesarrollo3Qt::AjustaFilas(QTProductos);
SiscomDesarrollo3Qt::AjustaColumnas(QTProductos);
intPedidoSeleccionado=pintFila;
}
else
QTProductos->setNumRows(0);
}
}

void QPedidosExpendios::IniciaVariables()
{
QCtrFechaInicio->ColocaFechaHoy();
QCtrFechaFin->ColocaFechaHoy();
QCtrFechaInicio->ColocaFechaHoy();
QCtrFechaFin->ColocaFechaHoy();
SiscomDesarrollo3Qt::PasaFoco(QCtrFechaInicio);
Consultando();
}
void QPedidosExpendios::Consultando()
{
CQSPedidosExps.SiscomLimpia();
Consulta();
Muestra();
}

void QPedidosExpendios::Consulta()
{
CQSisPedidoMaterialOp lCQSPedidoMatOp(SisDatCom);
lCQSPedidoMatOp.PedidosExpendios((const char *)QCtrFechaInicio->ObtenFecha(),
				 (const char *)QCtrFechaFin->ObtenFecha(),
				 "",
				 &CQSPedidosExps);
}
void QPedidosExpendios::Muestra()
{
const char *lchrPtrCampos[]={"razonsocial","fecha","descripcion",0};
SiscomDesarrollo3Qt::RegsPrincipal4ALaTabla(lchrPtrCampos,
					    QTPedidos,
					    &CQSPedidosExps);
SiscomDesarrollo3Qt::AjustaFilas(QTPedidos);
SiscomDesarrollo3Qt::AjustaColumnas(QTPedidos);
}
int QPedidosExpendios::EstadoTransferencia(const char *pchrPtrEdoConexion)
{
if(!strcmp(pchrPtrEdoConexion,"No Alcanza"))
return 1;
else
if(!strcmp(pchrPtrEdoConexion,"Expendio Sin Conexion"))
return 2;

}
/* Ciudad de Mexico a 29 de Septiembre del 2016 
 * Regresa: 
 * 	1 No Alcanza
 * 	2 NO hay conexion al Expendio
 *	0 Todo alcanza
 */
int QPedidosExpendios::TransfierePedido()
{
SiscomRegistro3Lst *lSisReg3LstProdPedido;
SiscomRegistro3 *lSisReg3Registro;
const char *lchrPtrEdoEnvio;
int lintEdoTransferencia;

if((lSisReg3LstProdPedido=CQSPedidosExps.RegistrosSubGrupo(intPedidoSeleccionado,1)))
{
RegsProTransfiere.clear();
for(lSisReg3Registro=lSisReg3LstProdPedido->first();
    lSisReg3Registro;
    lSisReg3Registro=lSisReg3LstProdPedido->next())
RegsProTransfiere << new RegProductoTransfiere(
			   (*lSisReg3Registro)["cveproducto"],
			   (*lSisReg3Registro)["cantidad"],
			   chrPtrArgumentos[0],
			   CQSPedidosExps.CampoRegistroPrincipal(intPedidoSeleccionado,"idexpendio"),
			   chrPtrArgumentos[1]);
OpTransfiereProductos lOpTransProds(SisDatCom);
lOpTransProds.EjecutaTransferencia(RegsProTransfiere);
if((lchrPtrEdoEnvio=lOpTransProds.ObtenEdoEnvio()))
{
SiscomEscribeLog3Qt("Hubo un error al transferir :%s",lchrPtrEdoEnvio);
if((lintEdoTransferencia=EstadoTransferencia(lchrPtrEdoEnvio))==1)
MuestraProductosPedido(lOpTransProds.ProductosNoAlcanza(),lSisReg3LstProdPedido);
return lintEdoTransferencia;
}

}
return 0;
}
void QPedidosExpendios::ActualizaEstadoPedido(const char *pchrPtrIdEstado)
{
CQSisPedidoMaterialOp lCQSPedMaterial(SisDatCom);
lCQSPedMaterial.ActualizaEstadoPedido(
		CQSPedidosExps.CampoRegistroPrincipal(intPedidoSeleccionado,"idpedido"),
		pchrPtrIdEstado);
}
int QPedidosExpendios::ValidaCantidadExistencia(const char *pchrPtrCveProducto,
						 char *pchrPtrCantidad)
{
QCapturaDato lQCDato("Introduce Cantidad",
		     "Cantidad");
lQCDato.ObtenDato(pchrPtrCantidad);
CQSisPedidoMaterialOp lCQSPedidoMaterial(SisDatCom);
if(!EstadoValidacionCantidad())
return lCQSPedidoMaterial.ValidaExistenciaExpendio(chrPtrArgumentos[0],
					    pchrPtrCveProducto,
					    pchrPtrCantidad);
else
return 1;
}
int QPedidosExpendios::CambiaCantidad(int pintProducto)
{
const char *lchrPtrIdPedido,*lchrPtrCveProducto,*lchrPtrIdProducto;
char lchrArrCantidad[10];
lchrPtrCveProducto=CQSPedidosExps.CveProducto(intPedidoSeleccionado,pintProducto);
lchrPtrIdProducto=CQSPedidosExps.IdProducto(intPedidoSeleccionado,pintProducto);
if(ValidaCantidadExistencia(lchrPtrCveProducto,lchrArrCantidad))
{
SiscomEscribeLog3Qt("La Cantidad a actualizar %s",lchrArrCantidad);
lchrPtrIdPedido=CQSPedidosExps.IdPedido(intPedidoSeleccionado);
CQSPedidosExps.Cantidad(intPedidoSeleccionado,pintProducto,lchrArrCantidad);
CQSisPedidoMaterialOp lCQSPedidoMaterial(SisDatCom);
lCQSPedidoMaterial.ActualizaCantidadProducto(lchrPtrIdPedido,
					     lchrPtrIdProducto,
					     lchrPtrCveProducto,
					     lchrArrCantidad);
return 1;
}
else
{
QMessageBox::information(this,"Aviso Del Sistema","Cantidad mayor que Existencia");
return 0;
}
}
void QPedidosExpendios::Imprime()
{
CQSis3QtOperaciones lCQS3QtImprime(SisDatCom);
lCQS3QtImprime.ImprimePedido(CQSPedidosExps.IdPedido(intPedidoSeleccionado));
}
int QPedidosExpendios::SiAlcanza(SiscomRegistrosPro2 *pSisRegsPro2,
				 SiscomRegistro3 *pSisReg3Producto)
{
pSisRegsPro2->SiscomColocaPrimerRegistro();
     while(!pSisRegsPro2->SiscomEsElUltimoRegistro())
     {
       SiscomEscribeLog3Qt("%s ? %s",
       			   (*pSisRegsPro2)["CveProducto"],
			   (*pSisReg3Producto)["cveproducto"]);
  	if(!strcmp((*pSisRegsPro2)["CveProducto"],(*pSisReg3Producto)["cveproducto"]))
	{
	   SiscomEscribeLog3Qt("El producto %s ? EdoConexion:%s",
	   			(*pSisRegsPro2)["CveProducto"],
	   			(*pSisRegsPro2)["EdoConexion"]);
	   return !strcmp((*pSisRegsPro2)["EdoConexion"],"No Alcanza");  
	}
	++(*pSisRegsPro2);
     }
 return 0;
}
void QPedidosExpendios::MuestraProductosPedido(SiscomRegistrosPro2 *pSisRegsPro2NoAlcanza,
					       SiscomRegistro3Lst *pSisReg3LstProductos)
{
int lintContador,
	lintContadorNA=0;
SiscomRegistro3 *lSisReg3Producto;
if(pSisRegsPro2NoAlcanza)
SiscomEscribeLog3Qt("Registros Regreso:(%d)",
		     pSisRegsPro2NoAlcanza->SiscomObtenNumRegistros());
QMemArray<int> lQMANoAlcanzan(pSisRegsPro2NoAlcanza ? 
			      pSisRegsPro2NoAlcanza->SiscomObtenNumRegistros():0);
QTProductos->setNumRows(pSisReg3LstProductos->count());
for(lSisReg3Producto=pSisReg3LstProductos->first(),
    lintContador=0;
    lSisReg3Producto;
    lSisReg3Producto=pSisReg3LstProductos->next(),
    lintContador++)
{
	if(pSisRegsPro2NoAlcanza &&
	   SiAlcanza(pSisRegsPro2NoAlcanza,lSisReg3Producto))
	 lQMANoAlcanzan[lintContadorNA++]=lintContador;
	  
	QTProductos->setText(lintContador,0,(*lSisReg3Producto)["cveproducto"]);
	QTProductos->setText(lintContador,1,(*lSisReg3Producto)["cantidad"]);
	QTProductos->setText(lintContador,2,(*lSisReg3Producto)["existencia"]);
	QTProductos->setText(lintContador,3,(*lSisReg3Producto)["exbodegas"]);
}
if(lintContadorNA)
{
Colorea(lQMANoAlcanzan,pSisReg3LstProductos->count());
QPBImprime->setEnabled(false);
QPBTransfiere->setEnabled(false);
}
}
void QPedidosExpendios::EliminaTablaProductos()
{
int lintContadorI,
    lintContadorJ,
    lintNFilas=QTProductos->numRows(),
    lintNColumnas=QTProductos->numCols();
for(lintContadorI=0;
    lintContadorI<lintNFilas;
    lintContadorI++)
 for(lintContadorJ=0;
     lintContadorJ<lintNColumnas;
     lintContadorJ++)
   QTProductos->clearCell(lintContadorI,lintContadorJ);

}
int QPedidosExpendios::HabilitaEnvio(const char *pchrPtrIdEstado)
{
   SiscomEscribeLog3Qt("IdEstado:%s",pchrPtrIdEstado);
   if(!strcmp(pchrPtrIdEstado,"3"))
   return 0;
   if(!strcmp(pchrPtrIdEstado,"2"))
   return 1;
   else
   return 1;
}
void QPedidosExpendios::ColoreaBlanco()
{
QMemArray<int> lQMemAActuales(QTProductos->numRows());
int lintContador;
for(lintContador=0;lintContador<QTProductos->numRows();lintContador++)
lQMemAActuales[lintContador]=lintContador;
SiscomDesarrollo3Qt::ColoreaFilasSeleccionadas(QTProductos,QColor("White"),lQMemAActuales);
}
void QPedidosExpendios::Colorea(const QMemArray<int> &pQMNoAlcanza, int pintNProductos)
{
ColoreaBlanco();
SiscomDesarrollo3Qt::ColoreaFilasSeleccionadas(QTProductos,QColor("Red"),pQMNoAlcanza);
}

int QPedidosExpendios::ValidaExistencia()
{
SiscomRegistro3Lst *lSisReg3LstProdPedido;
SiscomRegistro3 *lSisReg3Registro;
const char *lchrPtrEdoEnvio;
int lintEdoTransferencia;

if((lSisReg3LstProdPedido=CQSPedidosExps.RegistrosSubGrupo(intPedidoSeleccionado,1)))
{
RegsProTransfiere.clear();
for(lSisReg3Registro=lSisReg3LstProdPedido->first();
    lSisReg3Registro;
    lSisReg3Registro=lSisReg3LstProdPedido->next())
RegsProTransfiere << new RegProductoTransfiere(
			   (*lSisReg3Registro)["cveproducto"],
			   (*lSisReg3Registro)["cantidad"],
			   chrPtrArgumentos[0],
			   CQSPedidosExps.CampoRegistroPrincipal(intPedidoSeleccionado,"idexpendio"),
			   chrPtrArgumentos[1]);
OpTransfiereProductos lOpTransProds(SisDatCom);
lOpTransProds.ValidaExistencia(RegsProTransfiere);
if((lchrPtrEdoEnvio=lOpTransProds.ObtenEdoEnvio()))
{
SiscomEscribeLog3Qt("Productos No Alcanzan:%s",lchrPtrEdoEnvio);
if((lintEdoTransferencia=EstadoTransferencia(lchrPtrEdoEnvio))==1)
MuestraProductosPedido(lOpTransProds.ProductosNoAlcanza(),lSisReg3LstProdPedido);
return lintEdoTransferencia;
}

}
return 0;
}
void QPedidosExpendios::ActualizaInventario()
{
const char *lchrPtrCveProducto,*lchrPtrCantidad;
ProductoCantidad(intPedidoSeleccionado,
	         intProductoSeleccionado,
		 &lchrPtrCveProducto,
		 &lchrPtrCantidad);
zSiscomElectronica lzSisElectronica(zSisConexion,"ActualizaInventarioParaPedido");
lzSisElectronica.ActualizaInventarioParaPedido(chrPtrArgumentos[0],
					       lchrPtrCveProducto,
					       lchrPtrCantidad);
}

void QPedidosExpendios::ProductoCantidad(int pintPedido,
					 int pintProducto,
					 const char **pchrPtrCveProducto,
					 const char **pchrPtrCantidad)
{
  *pchrPtrCveProducto=CQSPedidosExps.CveProducto(pintPedido,pintProducto);
  *pchrPtrCantidad=CQSPedidosExps.Cantidad(pintPedido,pintProducto);
}

void QPedidosExpendios::DesactivaValidacionCantidad()
{
     if(!intDesactivaValidacionCantidad)
     intDesactivaValidacionCantidad=1;
     else
     if(intDesactivaValidacionCantidad==1)
     intDesactivaValidacionCantidad=0;
}
int QPedidosExpendios::EstadoValidacionCantidad()
{
  LogSiscom("Estado intDesactivaValidacionCantidad=%d",intDesactivaValidacionCantidad);
  return  intDesactivaValidacionCantidad ;
}
const char *QPedidosExpendios::TextoEstadoValidacionCantidad()
{
 const char *lchrPtrTextoEstadoValCantidad[]={ "Desactiva \nValidacion Cantidad",
 					       "Activa \n Validacion Cantidad",
					       0};
  return lchrPtrTextoEstadoValCantidad[intDesactivaValidacionCantidad];
}

int QPedidosExpendios::TransfiereBodegaAExpendio(const char *pchrPtrCantidad,
						 const char *pchrPtrCveProducto,
						 zSiscomRegistro **pzSisRegRegreso)
{
zSiscomRegistro *lzSisRegRegreso;
zSiscomElectronica lzSisElectronica(zSisConexion,"TransfiereBodegaExpendioParaPedido");
return lzSisElectronica.TransfiereBodegaAExpendioParaPedido(chrPtrArgumentos[0],
						     chrPtrArgumentos[1],
						     "0",
						     pchrPtrCveProducto,
						     pchrPtrCantidad,
						     pzSisRegRegreso);
}

void QPedidosExpendios::TransfiriendoBodegaAExpendio()
{
zSiscomRegistro *lzSisRegRegreso;
const char *lchrPtrCveProducto,
	   *lchrPtrCantidad,
	   *lchrPtrDescripcion;

ProductoCantidad(intPedidoSeleccionado,
		 intProductoSeleccionado,
		 &lchrPtrCveProducto,
		 &lchrPtrCantidad);

if(TransfiereBodegaAExpendio(lchrPtrCantidad,
			     lchrPtrCveProducto,
			     &lzSisRegRegreso)==1)
{
QAccionTraspasoBodegaExp lQATBodegaExp(lzSisRegRegreso);
CQSPedidosExps.Observaciones(intPedidoSeleccionado,
			     intProductoSeleccionado,
			     "Bodega Expendio");
   if(lQATBodegaExp.Opcion()==1)
     ExistenciaQueQuedaBodegaAExpendio(lchrPtrCveProducto,lzSisRegRegreso);
}
}
void QPedidosExpendios::ExistenciaQueQuedaBodegaAExpendio(const char *pchrPtrCveProducto,
							  zSiscomRegistro *pzSisRegRegreso)
{
zSiscomRegistro *lzSisRegRegreso;
   if(TransfiereBodegaAExpendio((const char *)(*pzSisRegRegreso)["ExistenciaB"],
   				 pchrPtrCveProducto,
				 &lzSisRegRegreso))
    {

    }
}
void QPedidosExpendios::HabilitaTransfiereEInventario(bool pbModal)
{
 LogSiscom("El estado del pedido %d",intEstadoPedido); 

   QPBAInventario->setEnabled(pbModal );
   QPBTranBodegaExp->setEnabled(pbModal );
}
