#include <IMP_ActDatCompGimnasta.h>
#include <IMP_BuscaPersonas.h>
#include<SISCOMComunicaciones++.h>

#include <QCtrlGimnasios.h>
#include <QCtrlClase.h>
#include <QCtrlNivel.h>
#include <QCtrlGrupo.h>
#include <CQSisCompitiendo.h>
#include <CQSisEntrenadores.h>
#include <CQSisNivel.h>
#include <CQSisClase.h>
#include <CQSisGrupo.h>

#include <qtabwidget.h>
#include <qpushbutton.h>

QActDatCompGimnasta::QActDatCompGimnasta(SiscomDatCom *pSisDatCom, 
				    CQSisCompitiendo *pCQSCompitiendo,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ActDatCompGimnasta(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				CQSCompitiendo(pCQSCompitiendo)
{
IniciaVariables();
ConectaSlots();
exec();
}

QActDatCompGimnasta::~QActDatCompGimnasta()
{

}

void QActDatCompGimnasta::ConectaSlots()
{


	connect(QCtrGimnasios,
		SIGNAL(SignalGimnasio(CQSisGimnasio *)),
		SLOT(SlotGimnasio(CQSisGimnasio *)));
	connect(QCtrClases,
		SIGNAL(SignalClase(CQSisClase *)),
		SLOT(SlotClase(CQSisClase *)));
	connect(QCtrNiveles,
		SIGNAL(SignalNivel(CQSisNivel *)),
		SLOT(SlotNivel(CQSisNivel *)));
	connect(QCtrGrupos,
		SIGNAL(SignalGrupo(CQSisGrupo *)),
		SLOT(SlotGrupo(CQSisGrupo *)));
	
	connect(QPBBusEntrenador,
		SIGNAL(clicked()),
		SLOT(SlotBusEntrenador()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistrar()));
}
void QActDatCompGimnasta::SlotRegistrar()
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisCompitiendo lCQSCompitiendo(CQSCompitiendo->ObtenCompetencia(),
				 CQSCompitiendo->ObtenGimnasta(),
				 CQSGimnasio,
				 CQSClase,
				 CQSNivel,
				 CQSGrupo,
				 CQSEntrenador,
				 "");
CQSisOpCompitiendo lCQSOCompitiendo(SisDatCom);
		lCQSOCompitiendo.ActDatCompGimnasta(
			&lCQSCompitiendo,&lSRegistrosPro2);
	
}
void QActDatCompGimnasta::SlotCancelar()
{
	done(1);
}
void QActDatCompGimnasta::SlotBusEntrenador()
{

QBuscaPersonas lQBPersonas("entrenador",SisDatCom);
	if((CQSEntrenador=lQBPersonas.ObtenPersona()))
	{
	QLEEntrenador->setText(QString(CQSEntrenador->SRegistrosPro2["Nombre"])	+
			     " "						+
			     CQSEntrenador->SRegistrosPro2["APaterno"]		+
			     " "						+
			     CQSEntrenador->SRegistrosPro2["AMaterno"]);
	QLEEntrenadorS->setText(QString(CQSEntrenador->SRegistrosPro2["Nombre"])	+
			     " "						+
			     CQSEntrenador->SRegistrosPro2["APaterno"]		+
			     " "						+
			     CQSEntrenador->SRegistrosPro2["AMaterno"]);
	 SiscomPasaFocoControl(QPBRegistrar);
	}
}
void QActDatCompGimnasta::SlotGrupo(CQSisGrupo *pCQSGrupo)
{
char lchrArrFormateado[128];
	CQSGrupo=pCQSGrupo;
	QCtrGrupos->FormateaGrupo(pCQSGrupo,lchrArrFormateado);
	QLEGrupo->setText(QString(CQSGrupo->SRegistrosPro2["Grupo"])+
			  " "					    +
			  lchrArrFormateado);
	QTWDatos->setCurrentPage(3);	
	SiscomPasaFocoControl(QPBBusEntrenador);

}
void QActDatCompGimnasta::SlotNivel(CQSisNivel *pCQSNivel)
{
	CQSNivel=pCQSNivel;
	QLENivel->setText(CQSNivel->SRegistrosPro2["Descripcion"]);
	QTWDatos->setCurrentPage(2);
	/*
	QCtrGrupos->PonServidor(SisDatCom);
	QCtrGrupos->IniciaControl();
	*/
}
void QActDatCompGimnasta::SlotClase(CQSisClase *pCQSClase)
{
	CQSClase=pCQSClase;
	QLEClase->setText(CQSClase->SRegistrosPro2["Clase"]);
	ConsultaNivelesClase();
}
void QActDatCompGimnasta::SlotGimnasio(CQSisGimnasio *pCQSGimnasio)
{
	CQSGimnasio=pCQSGimnasio;
	QCtrGimnasios->LimpiaSeleccion();
	/*
	QCtrClases->PonServidor(SisDatCom);
	QCtrClases->IniciaControl();
	*/
	QCtrClases->setFocus();
}
void QActDatCompGimnasta::IniciaVariables()
{

	QCtrGimnasios->PonServidor(SisDatCom);
	QCtrGimnasios->IniciaControl();

	QCtrGrupos->PonServidor(SisDatCom);
	QCtrGrupos->PonCompetencia(CQSCompitiendo->ObtenCompetencia());
	QCtrGrupos->IniciaControl();

	QCtrClases->PonCompetencia(CQSCompitiendo->ObtenCompetencia());
	QCtrClases->PonServidor(SisDatCom);
	QCtrClases->IniciaControl();

	MuestraDatosCompetencia();
	CQSClase=CQSCompitiendo->ObtenClase();
	CQSNivel=CQSCompitiendo->ObtenNivel();
	CQSGrupo=CQSCompitiendo->ObtenGrupo();
	CQSGimnasio=CQSCompitiendo->ObtenGimnasio();
	CQSEntrenador=CQSCompitiendo->ObtenEntrenador();

}
void QActDatCompGimnasta::MuestraPersona(CQSisEntrenador *pCQSEPersona,
					 QLineEdit *pQLEPersona)
{
pQLEPersona->setText(QString(pCQSEPersona->SRegistrosPro2["Nombre"])	+
			     " "						+
			     pCQSEPersona->SRegistrosPro2["APaterno"]		+
			     " "						+
			     pCQSEPersona->SRegistrosPro2["AMaterno"]);


}
			
void QActDatCompGimnasta::MuestraDatosCompetencia()
{
	MuestraPersona(CQSCompitiendo->ObtenGimnasta(),QLEGimnasta);
	MuestraPersona(CQSCompitiendo->ObtenEntrenador(),QLEEntrenadorS);
			
	QLEClase->setText(CQSCompitiendo->ObtenClase()->SRegistrosPro2["Clase"]);
	QLEGrupo->setText(CQSCompitiendo->ObtenGrupo()->SRegistrosPro2["Grupo"]);
	QLENivel->setText(CQSCompitiendo->ObtenNivel()->SRegistrosPro2["Nivel"]);
	QLEREdad->setText(CQSCompitiendo->ObtenGrupo()->SRegistrosPro2["RangoEdad"]);

}
void QActDatCompGimnasta::ConsultaNivelesClase()
{
	QTWDatos->setCurrentPage(1);
	QCtrNiveles->PonServidor(SisDatCom);
	QCtrNiveles->PonClase(CQSClase);
	QCtrNiveles->Limpia();
	QCtrNiveles->IniciaControl();
}
void QActDatCompGimnasta::closeEvent(QCloseEvent *)
{

}
