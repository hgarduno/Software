#include <IMP_CapturaRangoHora.h>
#include <zSiscomQt3.h>

#include <qlineedit.h> 
#include <qpushbutton.h>
QCapturaRangoHora::QCapturaRangoHora(char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaRangoHora(pQWParent,pchrPtrName,pbModal,pWFlags),
				chrPtrArgumentos(pchrPtrArgumentos),
				intAceptar(1)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaRangoHora::~QCapturaRangoHora()
{

}

void QCapturaRangoHora::ConectaSlots()
{
connect(QLEHoraInicio,SIGNAL(returnPressed()),SLOT(SlotFocoAHoraFin()));
connect(QLEHoraFin,SIGNAL(returnPressed()),SLOT(SlotFocoAAceptar()));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));

}
void QCapturaRangoHora::SlotAceptar()
{
  intAceptar=1;
   done(1);
}
void QCapturaRangoHora::SlotFocoAHoraFin()
{
  zSiscomQt3::Foco(QLEHoraFin);
}
void QCapturaRangoHora::SlotFocoAAceptar()
{
  zSiscomQt3::Foco(QPBAceptar);
}
void QCapturaRangoHora::IniciaVariables()
{
 zSiscomQt3::Foco(QLEHoraInicio);
}

int QCapturaRangoHora::Aceptar()
{
   return intAceptar;
}
void QCapturaRangoHora::Horas(char *pchrPtrHoraInicio,
			      char *pchrPtrHoraFin)
{

  strcpy(pchrPtrHoraInicio,(const char *)QLEHoraInicio->text());
  strcpy(pchrPtrHoraFin,(const char *)QLEHoraFin->text());
}
  	
