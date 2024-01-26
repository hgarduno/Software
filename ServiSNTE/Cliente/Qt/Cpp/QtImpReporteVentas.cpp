#include <QtImpReporteVentas.h>

#include <QCtrlTiendasEntrega.h>
#include <QCtrlTipoVentas.h>
#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>

#include <zOperacionesServiSNTE.h>

#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <qpushbutton.h>
#include <qlineedit.h>
QtImpReporteVentas::QtImpReporteVentas(QWidget *pQWParent,
				     const char *pchrPtrName):
				     ReporteVentas(pQWParent,pchrPtrName)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 IniciaVariables();
 ConectaSlots();

}
void QtImpReporteVentas::IniciaVariables()
{
IniciaControles();
zSiscomQt3::Foco(QLERangoFechas);
}
void QtImpReporteVentas::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpReporteVentas::ConectaSlots()
{
connect(QLERangoFechas,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoATiendas()));
connect(QCtrTiendas,
	SIGNAL(SignalTienda(zSiscomRegistro *)),
	SLOT(SlotTienda(zSiscomRegistro *)));
connect(QCtrTipoVentas,
	SIGNAL(SignalTipoVenta(zSiscomRegistro *)),
	SLOT(SlotTipoVenta(zSiscomRegistro *)));
connect(QPBConsultando,
	SIGNAL(clicked()),
	SLOT(SlotConsulta()));

}
void QtImpReporteVentas::SlotConsulta()
{
 Consultando();
}
void QtImpReporteVentas::SlotTipoVenta(zSiscomRegistro *pzSisRegTipoVenta)
{
  zSisRegTipoVenta=pzSisRegTipoVenta;
  zSiscomQt3::Foco(QPBConsultando);
}
void QtImpReporteVentas::SlotTienda(zSiscomRegistro *pzSisRegTienda)
{
  zSisRegTienda=pzSisRegTienda;
  zSiscomQt3::Foco(QCtrTipoVentas);
}
void QtImpReporteVentas::SlotFocoATiendas()
{
   zSiscomQt3::Foco(QCtrTiendas);
}
void QtImpReporteVentas::IniciaControles()
{
QCtrTiendas->Servidor(zSisConexion);
QCtrTiendas->IniciaControl();
QCtrTipoVentas->Servidor(zSisConexion);
QCtrTipoVentas->IniciaControl();
}
void QtImpReporteVentas::Consulta()
{
const char *lchrPtrRango=strdup((const char *)QLERangoFechas->text());
LogSiscom("%s",(const char *)QLERangoFechas->text());
zOperacionesServiSNTE lzOpServiSNTERepVentas(zSisConexion,"ReporteVentas");
zSisRegsRepVentas=lzOpServiSNTERepVentas.ReporteVentas(lchrPtrRango,
						      zSisRegTienda,
						      zSisRegTipoVenta);
}
void QtImpReporteVentas::Consultando()
{
 Consulta();
 Muestra();
}
void QtImpReporteVentas::Muestra()
{
const char *lchrPtrCampos[]={"fecha","importe",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,zSisRegsRepVentas,QTVentas);

}
