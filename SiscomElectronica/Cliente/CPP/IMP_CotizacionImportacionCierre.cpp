#include <IMP_CotizacionImportacionCierre.h>

#include <zSiscomDesarrollo4.h>
#include <qpushbutton.h>
QCotizacionImportacionCierre::QCotizacionImportacionCierre(
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CotizacionImportacionCierre(pQWParent,pchrPtrName,pWFlags)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCotizacionImportacionCierre::~QCotizacionImportacionCierre()
{

}

void QCotizacionImportacionCierre::ConectaSlots()
{
connect(QPBCerrar,SIGNAL(clicked()),SLOT(SlotCerrar()));
connect(QPBOtraCotizacion,SIGNAL(clicked()),SLOT(SlotOtraCotizacion()));
connect(QPBRegistrarCotizacion,SIGNAL(clicked()),SLOT(SlotRegistraCotizacion()));
}
void QCotizacionImportacionCierre::SlotRegistraCotizacion()
{
    QCotImpCerrando=RegistraOtraCotizacion;
  done(1);
}
void QCotizacionImportacionCierre::SlotOtraCotizacion()
{
	QCotImpCerrando=SeleccionaOtraCotizacion;
	done(1);
}
void QCotizacionImportacionCierre::SlotCerrar()
{
  QCotImpCerrando=Cierre; 
  done(1);
}
void QCotizacionImportacionCierre::IniciaVariables()
{

}
QCotizacionImportacionCierre::QCotImpCierre QCotizacionImportacionCierre::ComoCierro()
{
         return QCotImpCerrando; 
}
void QCotizacionImportacionCierre::reject()
{
	
}
