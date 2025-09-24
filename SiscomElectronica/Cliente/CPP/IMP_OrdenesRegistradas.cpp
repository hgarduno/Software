#include <IMP_OrdenesRegistradas.h>
#include <IMP_QControlFecha.h>
#include <IMP_VendiendoOrden.h>
#include <IMP_CapturaDescripcionCotizacion.h>

#include <IMP_ConExpendiosVenta.h>

#include <zSiscomElectronica.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>
#include <zSiscomDesarrollo4.h>
#include <zOrdenVenta.h>

#include <zSiscomConexion.h>
#include <zOrdenes.h>
#include <zCotizacion.h>
#include <zProductoCotizar.h>
#include <zClienteSiscom.h>
#include <zConexionExpendio.h>

#include <qpushbutton.h>
#include <qtable.h>
#include <qpushbutton.h>

QOrdenesRegistradas *InstanciaOrdenesRegistradas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QOrdenesRegistradas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QOrdenesRegistradas::QOrdenesRegistradas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				QtOrdenesRegistradas((zSiscomConexion *)gzSiscomConexion,
						     pchrPtrArgumentos,
						     pQWParent,
						     pchrPtrName,
						     pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)

{
QtOrdenesRegistradas::IniciaVariables();
QtOrdenesRegistradas::IniciaIdsTiposOrdenes();
QtOrdenesRegistradas::IniciaTiposOrdenes();
QtOrdenesRegistradas::IniciaDescripcionOrdenes();
QtOrdenesRegistradas::IniciaTipoEntrega();
QtOrdenesRegistradas::ConectaSlots();
}

QOrdenesRegistradas::~QOrdenesRegistradas()
{

}
void QOrdenesRegistradas::SlotSeReflejo()
{
  YaSeReflejoTransferencia();
  Consultando();
}
void QOrdenesRegistradas::SlotDevolucion()
{
  Devolucion();
  Consultando();
}
void QOrdenesRegistradas::SlotImprimir()
{
  ImprimeTicketOrden();
}
void QOrdenesRegistradas::SlotVender()
{
  QtOrdenesRegistradas::MarcaCotizacionComoVendida();
  VendeOrden(); 
  Consultando();
}
void QOrdenesRegistradas::SlotConsulta()
{
    Consultando();
}
void QOrdenesRegistradas::Consultando()
{
 Consulta();
 QtOrdenesRegistradas::Ordenes(zOrdsRegistradas);
 QtOrdenesRegistradas::Muestra();
 MuestraOrden(0);
}
void QOrdenesRegistradas::Consulta()
{
zSiscomElectronica lzSisElecOrdenes(Conexion(),"OrdenesVendidas2");
zOrdsRegistradas=lzSisElecOrdenes.Ordenes2((const char *)QCtrFechaIni->ObtenFecha(),
					   (const char *)QCtrFechaFin->ObtenFecha(),
					   QtOrdenesRegistradas::IdTipoOrden());
}
void QOrdenesRegistradas::Devuelve()
{
 zSiscomElectronica lzSisElec(Conexion(),"DevolucionOrden");
 lzSisElec.Devolucion(&zDevOrden);
}
void QOrdenesRegistradas::Devolucion()
{
   zDevOrden.IdVenta(QtOrdenesRegistradas::Orden()->IdVenta());
   zDevOrden.Productos(Orden()->Productos());
   Devuelve(); 
}
void QOrdenesRegistradas::VendeOrden()
{
QVendiendoOrden lQVenOrden(Conexion(),QtOrdenesRegistradas::Orden(),chrPtrArgumentos);  
}
void QOrdenesRegistradas::ImprimeTicketOrden()
{
 zSiscomElectronica lzSisElectronica(Conexion(),"ImprimeTicketVenta4");
 QtOrdenesRegistradas::Orden()->IdExpendio(QtOrdenesRegistradas::IdExpendio());
 lzSisElectronica.ImprimeTicketVenta(QtOrdenesRegistradas::Orden());
}
void QOrdenesRegistradas::YaSeReflejoTransferencia()
{
  zSiscomElectronica lzSisElectronica(Conexion(),"YaSeReflejoTransferencia");
  lzSisElectronica.SeReflejoTransferencia("1",
  					  QtOrdenesRegistradas::Orden()->IdVenta());
}
