#include <QtPuntosEntrega.h>

#include <IMP_PuntosEntrega.h>

#include <zSiscomQt3.h>


#include <qlineedit.h>
#include <qpushbutton.h>


QtPuntosEntrega::QtPuntosEntrega(QWidget *pQWParent,
				 const char *pchrPtrNombre,
				 WFlags pWFlags):
				 PuntosEntrega(pQWParent,pchrPtrNombre,pWFlags)
{


}
void QtPuntosEntrega::IniciaVariables()
{
zSiscomQt3::Foco(QLEPuntoEntrega);
}
void QtPuntosEntrega::ConectaSlots()
{
 ConectaEdits();
 ConectaBotones();
}
void QtPuntosEntrega::ConectaEdits()
{
connect(QLEPuntoEntrega,SIGNAL(returnPressed()),SLOT(SlotFocoACalle()));
connect(QLECalle,SIGNAL(returnPressed()),SLOT(SlotFocoANumExterior()));
connect(QLENumExterior,SIGNAL(returnPressed()),SLOT(SlotFocoANumInterior()));
connect(QLENumInterior,SIGNAL(returnPressed()),SLOT(SlotFocoAMunicipio()));
connect(QLEMunicipio,SIGNAL(returnPressed()),SLOT(SlotFocoAColonia()));
connect(QLEColonia,SIGNAL(returnPressed()),SLOT(SlotFocoACP()));
connect(QLECP,SIGNAL(returnPressed()),SLOT(SlotFocoAEstado()));
connect(QLEEstado,SIGNAL(returnPressed()),SLOT(SlotFocoAReferencias()));
}
void QtPuntosEntrega::ConectaBotones()
{
  connect(QPBRegistrar,SIGNAL(clicked()),SLOT(SlotRegistrar()));
}
void QtPuntosEntrega::SlotFocoACalle()
{
   zSiscomQt3::Foco(QLECalle);
}


void QtPuntosEntrega::SlotFocoANumExterior()
{
   zSiscomQt3::Foco(QLENumExterior);
}

void QtPuntosEntrega::SlotFocoANumInterior()
{
   zSiscomQt3::Foco(QLENumInterior);
}
void QtPuntosEntrega::SlotFocoAMunicipio()
{
   zSiscomQt3::Foco(QLEMunicipio);
}
void QtPuntosEntrega::SlotFocoAColonia()
{
   zSiscomQt3::Foco(QLEColonia);
}
void QtPuntosEntrega::SlotFocoACP()
{
   zSiscomQt3::Foco(QLECP);
}
void QtPuntosEntrega::SlotFocoAEstado()
{
   zSiscomQt3::Foco(QLEEstado);
}
void QtPuntosEntrega::SlotFocoAReferencias()
{
   zSiscomQt3::Foco(QTEReferencias);
}
