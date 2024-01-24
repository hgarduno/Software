#include <IMP_VendiendoOrden.h>
#include <zOrdenVenta.h>
#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zConexionExpendio.h>
#include <qpushbutton.h>
QVendiendoOrden::QVendiendoOrden(zSiscomConexion *pzSisConexion,
			         zOrdenVenta *pzOrdVenta,
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				VendiendoOrden(pQWParent,pchrPtrName,pbModal,pWFlags),
				chrPtrArgumentos(pchrPtrArgumentos),
				zOrdVenta(pzOrdVenta),
				zSisConexion(pzSisConexion)
{
IniciaVariables();
ConectaSlots();
exec();
}

QVendiendoOrden::~QVendiendoOrden()
{

}

void QVendiendoOrden::ConectaSlots()
{
 connect(QPBImprimir,SIGNAL(clicked()),SLOT(SlotImprimir()));
 connect(QPBVender,SIGNAL(clicked()),SLOT(SlotVender()));
}
void QVendiendoOrden::SlotImprimir()
{
  Imprime();
}
void QVendiendoOrden::SlotVender()
{
   Vende(); 
   done(1);
}
void QVendiendoOrden::IniciaVariables()
{
  GeneraId();
  zOrdVenta->IdTipoOrden("0");
  zOrdVenta->IdExpendio(chrPtrArgumentos[0]);

}

void QVendiendoOrden::Vende()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"RegistraOrden");
lzSisElectronica.RegistraOrden(zOrdVenta);
}
void QVendiendoOrden::Imprime()
{
  zSiscomElectronica lzSisElectronica(zSisConexion,"ImprimeTicketVenta4");
  lzSisElectronica.ImprimeTicketVenta(zOrdVenta); 
}

void QVendiendoOrden::GeneraId()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ObtenIdOrden");
if(lzSisElectronica.IdNuevaOrden(&chrPtrIdOrden))
{
    zOrdVenta->IdVenta(chrPtrIdOrden);
}
}
