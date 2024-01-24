#include <IMP_RondasCompetencia.h>
#include <QRotaciones.h>

#include <qpushbutton.h>
#include <qlayout.h>
#include <qbuttongroup.h>
#include <qtoolbutton.h>
#include <CQSisCompetencias.h>
#include <CQSisRotaciones.h>
QRotaciones::QRotaciones(SiscomDatCom *pSisDatCom,
			 QWidget *pQWParent,
			 const char *pchrPtrName):
		QWidget(pQWParent,pchrPtrName),
		SisDatCom(pSisDatCom)
{
IniciaInterfaz();
IniciaVariables();
}

void QRotaciones::IniciaInterfaz()
{
QVBoxLayout *lQVBox;
QButtonGroup *lQBGBotones;
lQVBox=new QVBoxLayout(this);
lQVBox->setMargin(0);

lQBGBotones=new QButtonGroup(1,Horizontal,this);
lQBGBotones->setFrameStyle(QFrame::NoFrame);
lQBGBotones->setEraseColor(green);
lQBGBotones->setBackgroundMode(PaletteBase);
QTBERotacion=CreaBoton(lQBGBotones,"Ejecuta Rotacion");
QTBERotacion1=CreaBoton(lQBGBotones,"Otra Operacion");
QTBERotacion2=CreaBoton(lQBGBotones,"Otra Operacion 1");
lQBGBotones->insert(QTBERotacion,0);
lQBGBotones->insert(QTBERotacion1,1);
lQBGBotones->insert(QTBERotacion2,2);
connect(lQBGBotones,SIGNAL(clicked(int)),SLOT(SlotSeleccion(int)));
lQVBox->addWidget(lQBGBotones);
}
void QRotaciones::SlotSeleccion(int pintNBoton)
{
/*

*/
(this->*Operaciones[pintNBoton])();
}
QToolButton *QRotaciones::CreaBoton(QButtonGroup *pQBGBotones,
				    const char *pchrPtrEtiqueta)
{
QToolButton *lQTBERotacion=new QToolButton(pQBGBotones);
lQTBERotacion->setBackgroundMode(PaletteBase);
lQTBERotacion->setTextLabel(pchrPtrEtiqueta);
lQTBERotacion->setAutoRaise(true);
lQTBERotacion->setTextPosition(QToolButton::Right);
lQTBERotacion->setUsesTextLabel(true);
return lQTBERotacion;
}
void QRotaciones::Competencia(CQSisCompetencia *pCQSCompetencia)
{
  CQSCompetencia=pCQSCompetencia;
}
void QRotaciones::IniciaVariables()
{
Operaciones[0]=&QRotaciones::EjecutaRotacion;
Operaciones[1]=&QRotaciones::EnConstruccion;
Operaciones[2]=&QRotaciones::EnConstruccion;
Operaciones[3]=&QRotaciones::EnConstruccion;

}
void QRotaciones::EjecutaRotacion()
{
if(CQSCompetencia)
{
ObtenRonda();
if(chrPtrIdRonda)
{
CQSisOpRotaciones lCQSORotaciones(SisDatCom);
lCQSORotaciones.EjecutaRotacion(CQSCompetencia,chrPtrIdRonda);
}
}
}
void QRotaciones::EnConstruccion()
{
printf("La Operacion se encuentra enc onstruccion\n");
}
void QRotaciones::ObtenRonda()
{
QRondasCompetencia lQRCompetencia(SisDatCom,
				  (*CQSCompetencia)["IdCompetencia"]);
chrPtrIdRonda=lQRCompetencia.IdRonda();
}
