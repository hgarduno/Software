#include <QtCotizaciones.h>
#include <zSiscomQt3.h>
#include <zSiscomDesarrollo4.h>

#include <qlineedit.h>
QtCotizaciones::QtCotizaciones(QWidget *pQWParent,
				const char *pchrPtrName,
				bool pbModal,WFlags pWFlags ):
				Cotizaciones(pQWParent,pchrPtrName,pbModal,pWFlags)


{
}
void QtCotizaciones::Teclas(QKeyEvent *pQKEvent)
{
    if(pQKEvent->state()==Qt::ControlButton)
       VerificandoTeclasConCtrl(pQKEvent);
}
void QtCotizaciones::VerificandoTeclasConCtrl(QKeyEvent *pQKEvent)
{
    if(pQKEvent->key()==Qt::Key_F12)
      CtrlF12(pQKEvent);
}
void QtCotizaciones::CtrlF12(QKeyEvent *pQKEvent)
{
  
   zSiscomQt3::Foco(QLEIdOrden); 
   MascaraTelefonoIdOrden(true);
}
void QtCotizaciones::keyPressEvent(QKeyEvent *pQKETeclas)
{
	Teclas(pQKETeclas); 
}

void QtCotizaciones::MascaraTelefonoIdOrden(bool pbActiva)
{
   if(pbActiva)
   QLEIdOrden->setInputMask("##-####-####");
   else
   QLEIdOrden->setInputMask(QString::null);

}
