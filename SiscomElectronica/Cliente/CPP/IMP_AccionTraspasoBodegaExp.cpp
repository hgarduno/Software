#include <IMP_AccionTraspasoBodegaExp.h>
#include <qpushbutton.h>
#include <qlineedit.h>

#include <zSiscomRegistro.h>
QAccionTraspasoBodegaExp::QAccionTraspasoBodegaExp(
				   zSiscomRegistro *pzSisRegRespuesta,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				AccionTraspasoBodegaExp(pQWParent,pchrPtrName,pbModal,pWFlags),
				intOpcion(0),
				zSisRegRespuesta(pzSisRegRespuesta)
{
IniciaVariables();
ConectaSlots();
exec();
}

QAccionTraspasoBodegaExp::~QAccionTraspasoBodegaExp()
{

}

void QAccionTraspasoBodegaExp::ConectaSlots()
{
connect(QPBPasarEB,
	SIGNAL(clicked()),
	SLOT(SlotTraspasoExistenciaBodegaExpendio()));
connect(QPBCancelar,SIGNAL(clicked()),SLOT(SlotCancelar()));
}
void QAccionTraspasoBodegaExp::SlotCancelar()
{
   intOpcion=0;
   done(intOpcion);
}
void QAccionTraspasoBodegaExp::SlotTraspasoExistenciaBodegaExpendio()
{
   intOpcion=1;
   done(intOpcion);
}
void QAccionTraspasoBodegaExp::IniciaVariables()
{
   Muestra();
}
int QAccionTraspasoBodegaExp::Opcion()
{

   return intOpcion;
}
void QAccionTraspasoBodegaExp::Muestra()
{
QLECveProducto->setText((const char *)(*zSisRegRespuesta)["CveProducto"]);
QLEExistenciaE->setText((const char *)(*zSisRegRespuesta)["ExistenciaE"]);
QLEExistenciaB->setText((const char *)(*zSisRegRespuesta)["ExistenciaB"]);
}

void QAccionTraspasoBodegaExp::closeEvent(QCloseEvent *)
{

}
