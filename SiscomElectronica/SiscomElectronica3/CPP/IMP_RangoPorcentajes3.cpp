#include <IMP_RangoPorcentajes3.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qpushbutton.h>
#include <qlineedit.h>
QRangoPorcentajes3::QRangoPorcentajes3(QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				RangoPorcentajes3(pQWParent,pchrPtrName,pbModal,pWFlags)
{
IniciaVariables();
ConectaSlots();
exec();
}

QRangoPorcentajes3::~QRangoPorcentajes3()
{

}

void QRangoPorcentajes3::ConectaSlots()
{
connect(QLEBajo,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoAlto()));
connect(QLEAlto,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoAceptar()));
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));
connect(QPBCancelar,
	SIGNAL(clicked()),
	SLOT(SlotCancelar()));

}
void QRangoPorcentajes3::SlotAceptar()
{
  strcpy(chrArrPBajo,
  	 SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEBajo));
   strcpy(chrArrPAlto,
   	  SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEAlto));
   intRegreso=1; 
   done(1);
}
void QRangoPorcentajes3::SlotCancelar()
{
  intRegreso=0;
  done(1);
}
void QRangoPorcentajes3::SlotPasaFocoAceptar()
{
SiscomDesarrollo3Qt::PasaFocoControl(QPBAceptar);
}
void QRangoPorcentajes3::SlotPasaFocoAlto()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLEAlto);
}
void QRangoPorcentajes3::IniciaVariables()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLEBajo);
}
int QRangoPorcentajes3::OpcionSeleccionada(char *pchrPtrPEBajo,
					   char *pchrPtrPEAlto)
{
strcpy(pchrPtrPEBajo,chrArrPBajo);
strcpy(pchrPtrPEAlto,chrArrPAlto);
}
