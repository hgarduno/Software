#include <QtImpTransferenciasEnviadas.h>

#include <zSiscomConexion.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>


#include <zOperacionesServiSNTE.h>


#include <qlineedit.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qapplication.h>
#include <qclipboard.h>
QtImpTransferenciasEnviadas::QtImpTransferenciasEnviadas(QWidget *pQWParent,
							 const char *pchrPtrName):
							 TransferenciasEnviadas(pQWParent,pchrPtrName)
{
Conexion((zSiscomConexion *)gzSiscomConexion);
IniciaVariables();
ConectaSlots();

}
void QtImpTransferenciasEnviadas::Conexion(zSiscomConexion *pzSiscomConexion)
{
	zSisConexion=pzSiscomConexion;
}

void QtImpTransferenciasEnviadas::ConectaSlots()
{
 connect(QLERangoFecha,
 	SIGNAL(returnPressed()),
	SLOT(SlotCapturoRangoFechas()));
 connect(QTTransferencias,
 	 SIGNAL(clicked(int,int,int,const QPoint &)),
	 SLOT(SlotSeleccionoTransferencia(int,int,int,const QPoint &)));
  connect(QPBCopiar,
  	  SIGNAL(clicked()),
	  SLOT(SlotCopiar()));
}
void QtImpTransferenciasEnviadas::SlotCopiar()
{
QString lQStrListaProductos;
	GeneraListaCodigosBarras(lQStrListaProductos);
	QApplication::clipboard()->setText(lQStrListaProductos);
}
void QtImpTransferenciasEnviadas::SlotSeleccionoTransferencia(int pintTransferencia,
							      int,
							      int,
							      const QPoint &)
{
zSiscomRegistro *lzSisRegTransferencia=(*zSisRegsTransferencias)[pintTransferencia];
ConsultandoTransferencia((const char *)(*lzSisRegTransferencia)["idtransferencia"]);
}
void QtImpTransferenciasEnviadas::SlotCapturoRangoFechas()
{
	Consultando();
}
void QtImpTransferenciasEnviadas::IniciaVariables()
{
	zSiscomQt3::Foco(QLERangoFecha);
}

void QtImpTransferenciasEnviadas::Consultando()
{
  Consulta();
  Muestra();
}

void QtImpTransferenciasEnviadas::Consulta()
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"TransferenciasEnviadas");
zSisRegsTransferencias=lzOpeServiSNTE.TransferenciasEnviadas((const char *)QLERangoFecha->text());
}
void QtImpTransferenciasEnviadas::Muestra()
{
const char *lchrPtrCampos[]={"fechahora",
			"idestado",
			"tienda",
			"almacenista",
			"chofer",
			"camion",
			0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,zSisRegsTransferencias,QTTransferencias);
}
void QtImpTransferenciasEnviadas::ConsultandoTransferencia(const char *pchrPtrIdTransferencia)
{
zSiscomRegistros *lzSisRegDetalleTransferencia;
  lzSisRegDetalleTransferencia=zSisRegsDetalleTransferencia=ConsultaTransferencia(pchrPtrIdTransferencia);

  MuestraTransferencia(lzSisRegDetalleTransferencia);
}
zSiscomRegistros *QtImpTransferenciasEnviadas::ConsultaTransferencia(const char *pchrPtrIdTransferencia)
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"DetalleTransferencia");
return lzOpeServiSNTE.DetalleTransferencia(pchrPtrIdTransferencia);
}
void QtImpTransferenciasEnviadas::MuestraTransferencia(zSiscomRegistros *pzSisRegsDetalleTransferencia)
{
const char *lchrPtrCampos[]={"cantidad",
			"modelo",
			"nombreproducto",
			"numproducto",
			"razonsocial",
			0
			};
zSiscomQt3::LlenaTabla(lchrPtrCampos,pzSisRegsDetalleTransferencia,QTDetalleTransferencia);
}
void QtImpTransferenciasEnviadas::GeneraListaCodigosBarras(QString &pQStrLista)
{
int lintContador;
zSiscomRegistro *lzSisRegProducto;
for(lintContador=0;
    lintContador<QTDetalleTransferencia->numRows();
    lintContador++)
{
   if(QTDetalleTransferencia->isRowSelected(lintContador))
   {
	 lzSisRegProducto=(*zSisRegsDetalleTransferencia)[lintContador];
	 pQStrLista+=(const char *)(*lzSisRegProducto)["codigobarras"];
	 pQStrLista+="\n";
   }
}
LogSiscom("%s",(const char *)pQStrLista);
}
