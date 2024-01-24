#include <IMP_SeleccionaOrdenFactura.h>
#include <IMP_ReEnvioFactura.h>
#include <IMP_QControlFecha.h>


#include <zOrdenes.h> 
#include <zSiscomElectronica.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qmessagebox.h>
QSeleccionaOrdenFactura::QSeleccionaOrdenFactura(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				SeleccionaOrdenFactura(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				intAceptar(0)
{
Conexion((zSiscomConexion *)gzSiscomConexion);
IniciaVariables();
ConectaSlots();
exec();
}

QSeleccionaOrdenFactura::~QSeleccionaOrdenFactura()
{

}

void QSeleccionaOrdenFactura::Conexion(zSiscomConexion *pzSiscomConexion)
{
   zSisConexion=pzSiscomConexion;
}
void QSeleccionaOrdenFactura::ConectaSlots()
{
connect(QLENoOrden,SIGNAL(returnPressed()),SLOT(SlotCapturoNoOrden()));
connect(QCtrFechaInicio,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAFechaFin()));
connect(QCtrFechaFin,SIGNAL(Signal_EnterA_o()),SLOT(SlotFocoAConsultar()));
connect(QPBConsultar,SIGNAL(clicked()),SLOT(SlotConsultar()));
connect(QTOrdenes,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotOrden(int,int,int,const QPoint &)));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));
connect(QPBReEnviar,SIGNAL(clicked()),SLOT(SlotReEnviar()));

connect(QLENoOrden,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoNoOrden(const QString &)));
}
void QSeleccionaOrdenFactura::SlotCapturoNoOrden()
{
bool lbEstado=zSiscomQt3::TextoValido(QLENoOrden);
      if(!lbEstado)
      {
        HabilitaRangoFecha(!lbEstado); 
      	SlotFocoAFechaInicio();
      }
      else
      SlotFocoAConsultar();
}
void QSeleccionaOrdenFactura::SlotCapturandoNoOrden(const QString &)
{
      HabilitaRangoFecha(!zSiscomQt3::TextoValido(QLENoOrden));
}
void QSeleccionaOrdenFactura::SlotReEnviar()
{
QReEnvioFactura lQReEnvioFactura(zOrdenesV->IdFactura(intOrdenActual),
				 chrPtrArgumentos);
						
}
void QSeleccionaOrdenFactura::SlotCancelar()
{
   intAceptar=0;
   done(1);
}

void QSeleccionaOrdenFactura::SlotAceptar()
{
   intAceptar=1;
   done(1);
}
void QSeleccionaOrdenFactura::SlotOrden(int pintOrden,
					int,
					int,
					const QPoint &)
{
	 QTOrdenes->selectRow(pintOrden);
	if(!zOrdenesV->OrdenFacturada(pintOrden))
	{
	QPBReEnviar->setEnabled(false); 
	zSisRegOrden=(*zOrdenesV)[pintOrden];
        MuestraOrden(zSisRegOrden->AsociadosDelCampo("Productos"));
	zSiscomQt3::Foco(QPBAceptar);
	}
	else
	{
	  QPBReEnviar->setEnabled(true); 
	  LogSiscom("Se Re Envia la Factura %s",
	  	     zOrdenesV->IdFactura(pintOrden));
	  intOrdenActual=pintOrden;
	  zSiscomQt3::Foco(QPBReEnviar);
	}

}
void QSeleccionaOrdenFactura::SlotConsultar()
{
 Consultando();
}
void QSeleccionaOrdenFactura::SlotFocoAFechaInicio()
{
   zSiscomQt3::Foco(QCtrFechaInicio);
}
void QSeleccionaOrdenFactura::SlotFocoAFechaFin()
{
  zSiscomQt3::Foco(QCtrFechaFin);
}
void QSeleccionaOrdenFactura::SlotFocoAConsultar()
{
  zSiscomQt3::Foco(QPBConsultar);
}
void QSeleccionaOrdenFactura::IniciaVariables()
{
QCtrFechaInicio->ColocaFechaHoy();
QCtrFechaFin->ColocaFechaHoy();
zSiscomQt3::Foco(QLENoOrden);
Consultando();
}

void QSeleccionaOrdenFactura::Consultando()
{
 Consulta();
 Muestra();
}
void QSeleccionaOrdenFactura::Consulta()
{
if(!zSiscomQt3::TextoValido(QLENoOrden))
{
zSiscomElectronica lzSisEOrdenes(zSisConexion,"OrdenesParaFacturar");
zOrdenesV=lzSisEOrdenes.OrdenesParaFacturar((const char *)QCtrFechaInicio->ObtenFecha(),
				            (const char *)QCtrFechaFin->ObtenFecha());
}
else
{
zSiscomElectronica lzSisEOrdenes(zSisConexion,"OrdenParaFacturar");
zOrdenesV=lzSisEOrdenes.OrdenParaFacturar(zSiscomQt3::Texto(QLENoOrden));
}

}
void QSeleccionaOrdenFactura::Muestra()
{
const char *lchrPtrCampos[]={"idventa","fechahora","totalorden","idfactura",0};
 zSiscomQt3::LlenaTabla(lchrPtrCampos,zOrdenesV,QTOrdenes);
}
void QSeleccionaOrdenFactura::MuestraOrden(zSiscomRegistros *pzSisRegsProductos)
{
const char *lchrPtrCampos[]={"cantidad","cveproducto","importe","precio",0};
 zSiscomQt3::LlenaTabla(lchrPtrCampos,pzSisRegsProductos,QTProductos);
}

zSiscomRegistro *QSeleccionaOrdenFactura::Orden()
{
	if(intAceptar)
	return zSisRegOrden;
	else
	return 0;
}
void QSeleccionaOrdenFactura::reject()
{

}
void QSeleccionaOrdenFactura::HabilitaRangoFecha(bool pbEstado)
{
   QCtrFechaInicio->setEnabled(pbEstado);
   QCtrFechaFin->setEnabled(pbEstado);
}
