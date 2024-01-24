#include <IMP_ActualizaProductoCotizacionImportacion.h>

#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <zProductoCotImp.h>

#include <qlineedit.h>
#include <qpushbutton.h>

QActualizaProductoCotizacionImportacion::QActualizaProductoCotizacionImportacion(
				    zProductoCotImp *pzProductoCotImp,
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ActualizaProductoCotizacionImportacion(pQWParent,
								       pchrPtrName,
								       pbModal,
								       pWFlags),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				zProdCotImp(pzProductoCotImp),
				intSeModificoCantidad(0),
				intSeModificoPrecio(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QActualizaProductoCotizacionImportacion::~QActualizaProductoCotizacionImportacion()
{

}

void QActualizaProductoCotizacionImportacion::ConectaSlots()
{
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));
connect(QLECantidad,SIGNAL(returnPressed()),SLOT(SlotFocoAPrecio()));
connect(QLEPrecio,SIGNAL(returnPressed()),SLOT(SlotFocoAAceptar()));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));

connect(QLECantidad,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoCantidad(const QString &)));
connect(QLEPrecio,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoPrecio(const QString &)));
}
void QActualizaProductoCotizacionImportacion::SlotCapturandoCantidad(const QString &)
{
   intSeModificoCantidad=1;
}
void QActualizaProductoCotizacionImportacion::SlotCapturandoPrecio(const QString &)
{
   intSeModificoPrecio=1;
}
void QActualizaProductoCotizacionImportacion::SlotAceptar()
{
   ActualizaDatos();
   done(1);
}
void QActualizaProductoCotizacionImportacion::SlotFocoAPrecio()
{
   zSiscomQt3::Foco(QLEPrecio);
}
void QActualizaProductoCotizacionImportacion::SlotFocoAAceptar()
{
  zSiscomQt3::Foco(QPBAceptar);
}
void QActualizaProductoCotizacionImportacion::SlotCancelar()
{
    done(1);
}
void QActualizaProductoCotizacionImportacion::IniciaVariables()
{
  MuestraProducto();
  zSiscomQt3::Foco(QLECantidad); 
}
void QActualizaProductoCotizacionImportacion::MuestraProducto()
{
  QLEClave->setText(zProdCotImp->Clave());
  QLECantidad->setText(zProdCotImp->Cantidad());
  QLEPrecio->setText(zProdCotImp->Precio());
}
void QActualizaProductoCotizacionImportacion::reject()
{
     LogSiscom("Cerrando ....");

}
void QActualizaProductoCotizacionImportacion::ActualizaDatos()
{
  if(intSeModificoCantidad)
   zProdCotImp->Cantidad(zSiscomQt3::Texto(QLECantidad));
   if(intSeModificoPrecio)
   zProdCotImp->Precio(zSiscomQt3::Texto(QLEPrecio));
}
int QActualizaProductoCotizacionImportacion::SeActualizoAlgo()
{
    return intSeModificoCantidad || intSeModificoPrecio;
}
