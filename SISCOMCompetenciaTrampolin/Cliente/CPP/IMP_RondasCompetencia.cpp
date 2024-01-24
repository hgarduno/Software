#include <IMP_RondasCompetencia.h>
#include<SiscomDesarrollo3Qt++.h>
#include <SiscomDatCom.h>

#include <CQSisRotaciones.h>
#include <qcombobox.h>
QRondasCompetencia::QRondasCompetencia(SiscomDatCom *pSisDatCom, 
				    const char *pchrPtrIdCompetencia,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				RondasCompetencia(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrIdCompetencia(pchrPtrIdCompetencia),
				chrPtrIdRonda(0)
{
IniciaVariables();
ConectaSlots();
ConsultandoRondas();
exec();
}

QRondasCompetencia::~QRondasCompetencia()
{

}

void QRondasCompetencia::ConectaSlots()
{
connect(QCBRondas,
	SIGNAL(activated(int)),
	SLOT(SlotRonda(int)));

}
void QRondasCompetencia::SlotRonda(int pintNRonda)
{
   chrPtrIdRonda=(*SRegistros3Lst[pintNRonda])["idronda"];
   done(0);
}
const char *QRondasCompetencia::IdRonda()
{
return chrPtrIdRonda;
}
void QRondasCompetencia::IniciaVariables()
{
}
void QRondasCompetencia::ConsultandoRondas()
{
ConsultaRondas();
MuestraRondas();
}
void QRondasCompetencia::MuestraRondas()
{
SiscomDesarrollo3Qt::RegistrosAlCombo("nmbronda",QCBRondas,&SRegistros3Lst);
}
void QRondasCompetencia::ConsultaRondas()
{
CQSisOpRotaciones lCQSORotaciones(SisDatCom);
lCQSORotaciones.RondasCompetencia(chrPtrIdCompetencia,&SRegistros3Lst);
}
