#include <IMP_CapturaDescripcionCotizacion.h>


#include <zOrdenVenta.h>
#include <zCotizacionMediaCenter.h>

#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
QCapturaDescripcionCotizacion::QCapturaDescripcionCotizacion(
				   int pintSoloDescripcion,
				   const char *pchrPtrModo,
				   zOrdenVenta *pzOrdenVenta,
				   zSiscomConexion *pzSisConexion,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):
				QtCapturaDescripcionCotizacion(pzOrdenVenta,
							       pzSisConexion,
							      pQWParent,
							       pchrPtrName,
							       pbModal,
							       pWFlags),
				chrPtrModo(pchrPtrModo)
{
setFont(pQWParent->font());
QtCapturaDescripcionCotizacion::SoloDescripcion(pintSoloDescripcion);
IniciandoCotizacion();
exec();
}

QCapturaDescripcionCotizacion::~QCapturaDescripcionCotizacion()
{

}

void QCapturaDescripcionCotizacion::IniciandoCotizacion()
{
   QtCapturaDescripcionCotizacion::Modo(chrPtrModo);
   if(Orden() && !Orden()->Cotizacion()) 
   QtCapturaDescripcionCotizacion::IniciaVariables();
   else
   if(Orden() && Orden()->Cotizacion())
   QtCapturaDescripcionCotizacion::Cotizando();
}
