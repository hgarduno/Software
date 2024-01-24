#include <IMP_GimnastaCompetencia.h>
#include <IMP_BuscaPersonas.h>
#include<SISCOMComunicaciones++.h>
#include <SisPersonas.h>
#include <QCtrlClase.h>
#include <QCtrlGimnasios.h>
#include <QCtrlNivel.h>
#include <QCtrlGrupo.h>
#include <QCtrlCompetencias.h>
#include <QCtrlBuscaPersonas.h>
#include <QCtrlBuscaPersonas2.h>
#include <CQSisCompitiendo.h>
#include <qtabwidget.h>
#include <qpushbutton.h>
QGimnastaCompetencia *InstanciaGimnastaCompetencia(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QGimnastaCompetencia((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QGimnastaCompetencia::QGimnastaCompetencia(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				GimnastaCompetencia(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
if(chrPtrArgumentos[26])
{
CQSCompetencia=(CQSisCompetencia *)chrPtrArgumentos[26];
SlotCompetencia(CQSCompetencia);
}
}

QGimnastaCompetencia::~QGimnastaCompetencia()
{

}

void QGimnastaCompetencia::ConectaSlots()
{

	connect(QCtrClases,
		SIGNAL(SignalClase(CQSisClase *)),
		SLOT(SlotClase(CQSisClase *)));
	connect(QCtrNiveles,
		SIGNAL(SignalNivel(CQSisNivel *)),
		SLOT(SlotNivel(CQSisNivel *)));
	connect(QCtrGrupos,
		SIGNAL(SignalGrupo(CQSisGrupo *)),
		SLOT(SlotGrupo(CQSisGrupo *)));
/*
	connect(QCtrCompetencias,
		SIGNAL(SignalCompetencia(CQSisCompetencia *)),
		SLOT(SlotCompetencia(CQSisCompetencia *)));
*/
	connect(QCtrGimnasios,
		SIGNAL(SignalGimnasio(CQSisGimnasio *)),
		SLOT(SlotGimnasio(CQSisGimnasio *)));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));
	connect(QPBActualiza,
		SIGNAL(clicked()),
		SLOT(SlotActualizaPantalla()));
	connect(QCtrBuscaPersona,
		SIGNAL(SignalPersona(CQSisEntrenador *,const char *)),
		SLOT(SlotPersona(CQSisEntrenador *,const char *)));
	connect(QCtrEntrenador,
		SIGNAL(SignalPersona(CQSisEntrenador *,const char *)),
		SLOT(SlotEntrenador(CQSisEntrenador *,const char *)));

}
void QGimnastaCompetencia::SlotEntrenador(CQSisEntrenador *pCQSEEntrenador,
					  const char *)
{
	CQSEntrenador=pCQSEEntrenador;
	MuestraEntrenador();
	EstanTodosLosDatos();
	SiscomPasaFocoControl(QPBRegistrar);
}
void QGimnastaCompetencia::SlotPersona(CQSisEntrenador *pCQSEntrenador,
				       const char *)
{
	CQSPersona=pCQSEntrenador;
	MuestraGimnasta();
	EstanTodosLosDatos();
	QCtrGimnasios->setFocus();
}
void QGimnastaCompetencia::SlotActualizaPantalla()
{
/*
	QCtrCompetencias->IniciaControl();
*/
}
void QGimnastaCompetencia::SlotRegistra()
{
EstanTodosLosDatos();
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisCompitiendo lCQSCompitiendo(CQSCompetencia,
				 CQSPersona,
				 CQSGimnasio,
				 CQSClase,
				 CQSNivel,
				 CQSGrupo,
				 CQSEntrenador,
				 "");
CQSisOpCompitiendo lCQSOCompitiendo(SisDatCom);
		lCQSOCompitiendo.RegistraGimnasta(&lCQSCompitiendo,&lSRegistrosPro2);
	CQSPersona=0;	
EstanTodosLosDatos();
}
void QGimnastaCompetencia::SlotGimnasio(CQSisGimnasio *pCQSGimnasio)
{
	QTWDatos->setEnabled(true);
	CQSGimnasio=pCQSGimnasio;
	QCtrGimnasios->LimpiaSeleccion();
	QCtrClases->PonServidor(SisDatCom);
	QCtrClases->PonCompetencia(CQSCompetencia);
	QCtrClases->IniciaControl();
	QCtrClases->setFocus();

	
EstanTodosLosDatos();
}
void QGimnastaCompetencia::MuestraGimnasta()
{
QLEGimnasta->setText(QString(CQSPersona->SRegistrosPro2["Nombre"])	+
			     " "						+
			     CQSPersona->SRegistrosPro2["APaterno"]		+
			     " "						+
			     CQSPersona->SRegistrosPro2["AMaterno"]);
	QLEEdad->setText(CQSPersona->SRegistrosPro2["Edad"]);
	QTWDatos->setCurrentPage(0);
	QCtrGimnasios->setEnabled(true);
	QCtrGimnasios->PonServidor(SisDatCom);
	QCtrGimnasios->IniciaControl();

}
void QGimnastaCompetencia::MuestraEntrenador()
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
void QGimnastaCompetencia::SlotCompetencia(CQSisCompetencia *pCQSCompetencia)
{
	CQSCompetencia=pCQSCompetencia;
	EstanTodosLosDatos();
	QCtrBuscaPersona->setFocus();
	QCtrBuscaPersona->PonServidor(SisDatCom);
	QCtrBuscaPersona->IniciaControl();
	QCtrBuscaPersona->PonPersona("gimnasta");
}
void QGimnastaCompetencia::SlotGrupo(CQSisGrupo *pCQSGrupo)
{
char lchrArrFormateado[128];
	CQSGrupo=pCQSGrupo;
	QCtrGrupos->FormateaGrupo(pCQSGrupo,lchrArrFormateado);
	QLEGrupo->setText(QString(CQSGrupo->SRegistrosPro2["Grupo"])+
			  " "					    +
			  lchrArrFormateado);
	QTWDatos->setCurrentPage(3);	
	/*SiscomPasaFocoControl(QPBBusEntrenador); */
	QCtrEntrenador->setFocus();
	QCtrEntrenador->PonServidor(SisDatCom);
	QCtrEntrenador->IniciaControl();
	QCtrEntrenador->PonPersona("entrenador");
EstanTodosLosDatos();
}
void QGimnastaCompetencia::SlotNivel(CQSisNivel *pCQSNivel)
{
printf("Slot Nivel\n");
	CQSNivel=pCQSNivel;
	QLENivel->setText(CQSNivel->SRegistrosPro2["Descripcion"]);
	QTWDatos->setCurrentPage(2);
	QCtrGrupos->PonServidor(SisDatCom);
	QCtrGrupos->PonCompetencia(CQSCompetencia);
	QCtrGrupos->IniciaControl();
EstanTodosLosDatos();
}
void QGimnastaCompetencia::SlotClase(CQSisClase *pCQSClase)
{
	CQSClase=pCQSClase;
	QLEClase->setText(CQSClase->SRegistrosPro2["Clase"]);
	ConsultaNivelesClase();
EstanTodosLosDatos();
}
void QGimnastaCompetencia::ConsultaNivelesClase()
{
	QTWDatos->setCurrentPage(1);
	QCtrNiveles->PonServidor(SisDatCom);
	QCtrNiveles->PonClase(CQSClase);
	QCtrNiveles->Limpia();
	QCtrNiveles->IniciaControl();
}
void QGimnastaCompetencia::IniciaVariables()
{
/*
	QCtrCompetencias->PonServidor(SisDatCom);
	QCtrCompetencias->IniciaControl();
*/
}
void QGimnastaCompetencia::EstanTodosLosDatos()
{
	QPBRegistrar->setEnabled(CQSCompetencia &&
				 CQSPersona	&&
				 CQSGimnasio	&&
				 CQSClase	&&
				 CQSNivel	&&
				 CQSGrupo	&&
				 CQSEntrenador);
}

