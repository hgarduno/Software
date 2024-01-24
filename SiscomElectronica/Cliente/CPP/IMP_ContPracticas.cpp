#include <IMP_ContPracticas.h>
#include <IMP_ContEscuelas.h>
#include <IMP_ContMaterias.h>
#include <IMP_ContDeLasPracticas.h>
#include <IMP_MaterialPractica.h>

#include <Materias.h>
#include <Practicas.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>


QContPracticas *InstanciaContPracticas(void *pSisDatCom,
				       char **pchrPtrArgumentos,
				       void *pQWParent,
				       const char *pchrPtrName,
				       int pWFlags)
{
	return new QContPracticas((SiscomDatCom *)pSisDatCom,
				  pchrPtrArgumentos,
				  (QWidget *)pQWParent,
				  pchrPtrName,
				  pWFlags);

}
QContPracticas::QContPracticas(SiscomDatCom *pSisDatCom,
			       char **pchrPtrArgumentos,
			       QWidget* parent, 
			       const char* name,
			       WFlags fl )
    : ContPracticas( parent, name, fl ),
    	SisDatCom(pSisDatCom),
	chrPtrArgumentos(pchrPtrArgumentos)
{
	ConectaSlots();
}

QContPracticas::~QContPracticas()
{
}
void QContPracticas::ConectaSlots()
{
	connect(QPBCEscuelas,
		SIGNAL(clicked()),
		SLOT(S_ContEscuelas()));
	connect(QPBConMaterias,
		SIGNAL(clicked()),
		SLOT(S_ContMaterias()));
	connect(QPBContPracticas,
		SIGNAL(clicked()),
		SLOT(S_SelLasPracticas()));
	connect(QPBMatPracticas,
		SIGNAL(clicked()),
		SLOT(S_MaterialPracticas()));
}
void QContPracticas::S_MaterialPracticas()
{
QMaterialPractica lQMatPractica(EEscuela,
				MMateria,
				PPractica,
				SisDatCom,
				chrPtrArgumentos);
}
void QContPracticas::S_SelLasPracticas()
{
QContDeLasPracticas lContLasPracticas(EEscuela,
				    MMateria,
				    SisDatCom,
				    chrPtrArgumentos);
	if((PPractica=lContLasPracticas.ObtenPractica()))
	{
		QPBContPracticas->setText(QPBContPracticas->text() +
					  "\n___________________\n"+
					  PPractica->SRegistrosPro2["Nombre"]);
	}
}
void QContPracticas::S_ContEscuelas()
{
QContEscuelas lQCntEscuelas(SisDatCom,
			    chrPtrArgumentos);
	if((EEscuela=lQCntEscuelas.ObtenEscuela()))
	{
	   setCaption(QString("Trabajando Con la Escuela:") +
	   	      EEscuela->SRegistrosPro2["Nombre"]);
	   QPBCEscuelas->setText(QPBCEscuelas->text() +
	   			 "\n________________\n"   +
	   			 "\n"		      +
				 EEscuela->SRegistrosPro2["Nombre"]);

	}
}
void QContPracticas::S_ContMaterias()
{
QContMaterias lCntMaterias(EEscuela,
			   SisDatCom,
			   chrPtrArgumentos);
	if((MMateria=lCntMaterias.ObtenMateria()))
	{
	   QPBConMaterias->setText(QPBConMaterias->text() +
	   			 "\n________________\n"   +
	   			   "\n" 		  +
				   MMateria->SRegistrosPro2["Nombre"]);
	}

}
void QContPracticas::closeEvent(QCloseEvent *)
{
	emit SignalTerminar(this);
}
