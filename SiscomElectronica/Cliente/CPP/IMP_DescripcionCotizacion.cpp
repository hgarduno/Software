#include <IMP_DescripcionCotizacion.h>
#include <zSiscomQt3.h> 
#include <zSiscomDesarrollo4.h>

#include <zCotizacion.h> 

#include <qpushbutton.h>
#include <qtextedit.h>

QDescripcionCotizacion::QDescripcionCotizacion(
				   zCotizacion *pzCotizacion,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				DescripcionCotizacion(pQWParent,pchrPtrName,pbModal,pWFlags)
				,intAceptar(0),
				zCotOrden(pzCotizacion)


{
if(pQWParent)
setFont(pQWParent->font());
IniciaVariables();
ConectaSlots();
}

QDescripcionCotizacion::~QDescripcionCotizacion()
{

}

void QDescripcionCotizacion::ConectaSlots()
{
  connect(QPBAceptar,
  	  SIGNAL(clicked()),
	  SLOT(SlotAceptar()));
}
void QDescripcionCotizacion::SlotAceptar()
{
 FormaCotizacion();
  emit SignalCotizacion(zCotOrden);
}
void QDescripcionCotizacion::IniciaVariables()
{
}
void QDescripcionCotizacion::FormaCotizacion()
{
  if(!zCotOrden)
  zCotOrden=new zCotizacion;

  zCotOrden->Descripcion(zSiscomQt3::Texto(QTEDescripcion));
}
void QDescripcionCotizacion::setFocus()
{
   zSiscomQt3::Foco(QTEDescripcion);
}
void QDescripcionCotizacion::Cierra()
{
	done(1);
}
void QDescripcionCotizacion::Ejecutando()
{
 Descripcion();
  exec();
}
void QDescripcionCotizacion::reject()
{
  accept();
  intAceptar=0;
}
int QDescripcionCotizacion::Aceptar()
{
  return intAceptar;
}
void QDescripcionCotizacion::Descripcion()
{
  if(zCotOrden && zCotOrden->DescripcionValida())
    QTEDescripcion->append(zCotOrden->Descripcion()); 
  else
  LogSiscom("Aun no se captura la descripcion");
}
