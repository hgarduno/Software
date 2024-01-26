#include <QtImpFoliosCancelados.h>


#include <QCtrlTiendasEntrega.h>
#include <QCtrlTiposFolio.h>
#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zOperacionesServiSNTE.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <zFolio.h>

#include <qlineedit.h> 
#include <qpushbutton.h>


QtImpFoliosCancelados::QtImpFoliosCancelados(
					 QWidget *pQWParent,
				     	 const char *pchrPtrName,
				    	 WFlags pWFlags):
				     FoliosCancelados(pQWParent,pchrPtrName),
				     zSisRegTienda(0)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 ConectaSlots();
 IniciaVariables();

}


void QtImpFoliosCancelados::IniciaVariables()
{
	QCtrTiendas->Servidor(zSisConexion);	
	QCtrTiendas->IniciaControl();
	zSiscomQt3::Foco(QCtrTiendas);
}

void QtImpFoliosCancelados::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpFoliosCancelados::ConectaSlots()
{
	connect(QCtrTiendas,
		SIGNAL(SignalTienda(zSiscomRegistro *)),
		SLOT(SlotTienda(zSiscomRegistro *)));
	connect(QLEFechaInicio,
		SIGNAL(returnPressed()),
		SLOT(SlotFechaInicio()));
	connect(QLEFechaFinal,
		SIGNAL(returnPressed()),
		SLOT(SlotFechaFinal()));
	connect(QPBMostrar,
		SIGNAL(clicked()),
		SLOT(SlotMostrar()));
}

void QtImpFoliosCancelados::SlotTienda(zSiscomRegistro *pzSisRegTienda)
{
    zSisRegTienda=pzSisRegTienda;
   LogSiscom("Se selecciono la tienda %s",(*pzSisRegTienda)["nombre"]);
    zSiscomQt3::Foco(QLEFechaInicio);
}

void QtImpFoliosCancelados::SlotMostrar()
{
	LogSiscom("Se dio click en el boton mostrar");	
	Consultando();
	zSiscomQt3::Foco(QCtrTiendas);
}

void QtImpFoliosCancelados::SlotFechaInicio()
{
	zSiscomQt3::Foco(QLEFechaFinal);
}

void QtImpFoliosCancelados::SlotFechaFinal()
{
	zSiscomQt3::Foco(QPBMostrar);
}

void QtImpFoliosCancelados::Consultando()
{
 Consulta();
 Muestra();
}
void QtImpFoliosCancelados::Consulta()
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"ConsultaFoliosCancelados");
zSisRegsFoliosCancelados=lzOpeServiSNTE.FoliosCanceladosPorTienda(zSisRegTienda,
									zSiscomQt3::Texto(QLEFechaInicio),
									zSiscomQt3::Texto(QLEFechaFinal));
}
void QtImpFoliosCancelados::Muestra()
{
const char *lchrPtrCampos[]={"folio","folionuevo","motivo","fecha",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,
			zSisRegsFoliosCancelados,
			QTFoliosCancelados);
}
