#include <QtImpVolteaContrato.h>
#include <QtImprimeBeneficiosIntegrales.h>
#include <zContratoBeneficios.h>
#include <qpushbutton.h>
QtImpVolteaContrato::QtImpVolteaContrato(QtImprimeBeneficiosIntegrales *pQtImpBenIntegrales,
					 zContratoBeneficios *pzConBeneficios,
				        QWidget *pQWParent,
					 const char *pchrPtrName,
					 bool pbModal,
					 WFlags pWFlags):
					 	VolteaContrato(pQWParent,
							       pchrPtrName,
							       pbModal,
							       pWFlags),
					QtImpBenIntegrales(pQtImpBenIntegrales),
					zConBeneficios(pzConBeneficios)

{
  ConectaSlots();
  IniciaVariables();
}
void QtImpVolteaContrato::IniciaVariables()
{

}
void QtImpVolteaContrato::ConectaSlots()
{
   connect(QPBSeVolteoElContrato,
   	  SIGNAL(clicked()),
	  SLOT(SlotSeVolteoElContrato()));
   connect(QPBImprimir,
   	   SIGNAL(clicked()),
	   SLOT(SlotImprimir()));
   connect(QPBTerminar,
   	   SIGNAL(clicked()),
	   SLOT(SlotTerminar()));
}
void QtImpVolteaContrato::SlotTerminar()
{
   done(1);
}
void QtImpVolteaContrato::SlotSeVolteoElContrato()
{
	QPBImprimir->setEnabled(true);
	QPBSeVolteoElContrato->setEnabled(false);
}
void QtImpVolteaContrato::SlotImprimir()
{
 QtImpBenIntegrales->imprimir(zConBeneficios);
 QPBTerminar->setEnabled(true);
 QPBImprimir->setEnabled(false);
}


int QtImpVolteaContrato::Ejecuta()
{
   exec();
}

void QtImpVolteaContrato::reject()
{


}
