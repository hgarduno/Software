#include <IMP_CalificaGimnasta.h>
#include<SISCOMComunicaciones++.h>
#include <CQSisCompitiendo.h>
#include <CQSisClase.h>
#include <CQSisNivel.h>
#include <CQSisGrupo.h>
#include <CQSisEntrenadores.h>
#include <CQSisCalificaciones.h>
#include <CQSisJueces.h>
#include <CQSisAparato.h>

#include <qpushbutton.h>
#include <qlcdnumber.h>

QCalificaGimnasta::QCalificaGimnasta(QCalificaGimnasta::Juez pJuez,
				     SiscomDatCom *pSisDatCom, 	
				    CQSisCompitiendo *pCQSCompitiendo,
				    CQSisAparato *pCQSAparato,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CalificaGimnasta(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				CQSCompitiendo(pCQSCompitiendo),
				CQSAparato(pCQSAparato),
				JEvalua(pJuez)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCalificaGimnasta::QCalificaGimnasta(SiscomDatCom *pSisDatCom, 	
				    CQSisCompitiendo *pCQSCompitiendo,
				    CQSisAparato *pCQSAparato,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CalificaGimnasta(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				CQSCompitiendo(pCQSCompitiendo),
				CQSAparato(pCQSAparato),
				JEvalua(Ejecucion)
{
IniciaVariables();
ConectaSlots();
exec();
}
QCalificaGimnasta::~QCalificaGimnasta()
{

}

void QCalificaGimnasta::ConectaSlots()
{
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistrar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
}
void QCalificaGimnasta::SlotCancelar()
{
	done(1);
}
void QCalificaGimnasta::SlotRegistrar()
{
	(this->*ActualizaCalificacion[JEvalua])();
}
void QCalificaGimnasta::IniciaVariablesFueraCompetencia()
{
	MuestraDatosGimnasta();
CQSCalificacion=new CQSisCalificacion(
			CQSAparato,
			CQSCompitiendo->ObtenCompetencia(),
			CQSCompitiendo->ObtenGimnasta(),
			new CQSisJuez("","","","0"),
			new CQSisJuez("","","","0"));

}
void QCalificaGimnasta::IniciaVariables()
{
	PerfilJuez[0]=&QCalificaGimnasta::PerfilEjecucion;
	PerfilJuez[1]=&QCalificaGimnasta::PerfilDificultad;
	PerfilJuez[2]=&QCalificaGimnasta::PerfilNotaFinal;
	ActualizaCalificacion[0]=&QCalificaGimnasta::ActualizaEjecucion;
	ActualizaCalificacion[1]=&QCalificaGimnasta::ActualizaDificultad;
	ActualizaCalificacion[2]=&QCalificaGimnasta::ObtenNotaFinal;
	MuestraDatosGimnasta();
	QLEEjecucion->setEnabled(false);
	QLEDificultad->setEnabled(false);
	(this->*PerfilJuez[JEvalua])();
	CQSCalificacion=new CQSisCalificacion(
			CQSAparato,
			CQSCompitiendo->ObtenCompetencia(),
			CQSCompitiendo->ObtenGimnasta(),
			new CQSisJuez("","","","0"),
			new CQSisJuez("","","","0"));
	/*IniciaCalificacion(); */

}
void QCalificaGimnasta::ActualizaEjecucion()
{
CQSisOpCalificacion lCQSCalifica(SisDatCom);
SiscomRegistrosPro2 *lSRegistrosPro2;
	CQSCalificacion->PonEjecucion(
			SiscomObtenInformacionDelEdit(QLEEjecucion));
		lCQSCalifica.ActualizaEjecucion(
			CQSCalificacion,
			&lSRegistrosPro2);
	done(1);
}
void QCalificaGimnasta::ActualizaDificultad()
{
CQSisOpCalificacion lCQSCalifica(SisDatCom);
SiscomRegistrosPro2 *lSRegistrosPro2;
		CQSCalificacion->PonDificultad(
			SiscomObtenInformacionDelEdit(QLEDificultad));
		lCQSCalifica.ActualizaDificultad(
			CQSCalificacion,
			&lSRegistrosPro2);

	done(1);
}
void QCalificaGimnasta::ObtenNotaFinal()
{
	done(1);
}
void QCalificaGimnasta::ConsultaNotaFinal()
{
CQSisOpCalificacion lCQSCalifica(SisDatCom);
CQSisCalificacion *lCQSCalificando;
	lCQSCalifica.ObtenCalificaciones(CQSCompitiendo,
					 &lCQSCalificando);
	QLEEjecucion->setText(lCQSCalificando->SRegistrosPro2["Ejecucion"]);
	QLEDificultad->setText(lCQSCalificando->SRegistrosPro2["Dificultad"]);
	QLCNotaFinal->display(lCQSCalificando->SRegistrosPro2["NotaFinal"]);
}
void QCalificaGimnasta::IniciaCalificacion()
{
CQSisOpCalificacion lCQSCalifica(SisDatCom);
SiscomRegistrosPro2 *lSRegistrosPro2;
		lCQSCalifica.IniciaCalificacion(
			CQSCalificacion,
			&lSRegistrosPro2);
}
void QCalificaGimnasta::PerfilEjecucion()
{
	setCaption(caption()		+
		   " "			+
		   "[Evaluando Ejecucion]");
	QLEEjecucion->setEnabled(true);
	QLEDificultad->setEnabled(false);
	SiscomPasaFocoControl(QLEEjecucion);
	connect(QLEEjecucion,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoRegistrar()));
}
void QCalificaGimnasta::SlotPasaFocoRegistrar()
{
	SiscomPasaFocoControl(QPBRegistrar);
}
void QCalificaGimnasta::PerfilDificultad()
{
	setCaption(caption()		+
		   " "			+
		   "[Evaluando Dificultad]");
	
	QLEEjecucion->setEnabled(false);
	QLEDificultad->setEnabled(true);
	SiscomPasaFocoControl(QLEDificultad);

	connect(QLEDificultad,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoRegistrar()));
}
void QCalificaGimnasta::PerfilNotaFinal()
{
	setCaption(caption()		+
		   " "			+
		   "[NotaFinal]");
	QLEEjecucion->setEnabled(true);
	QLEDificultad->setEnabled(true);
	QLEEjecucion->setReadOnly(true);
	QLEDificultad->setReadOnly(true);
	ConsultaNotaFinal();
}
void QCalificaGimnasta::MuestraDatosGimnasta()
{
QLEClase->setText(CQSCompitiendo->ObtenClase()->SRegistrosPro2["Clase"]);
QLENivel->setText(CQSCompitiendo->ObtenNivel()->SRegistrosPro2["Nivel"]);
QLEGrupo->setText(CQSCompitiendo->ObtenGrupo()->SRegistrosPro2["Grupo"]);
QLEEntrenador->setText(
	QString(CQSCompitiendo->ObtenEntrenador()->SRegistrosPro2["Nombre"]) +
	" "								      +
	CQSCompitiendo->ObtenEntrenador()->SRegistrosPro2["APaterno"]	      +
	" "								      +
	CQSCompitiendo->ObtenEntrenador()->SRegistrosPro2["AMaterno"]);
QLEGimnasta->setText(
	QString(CQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["Nombre"]) +
	" "								      +
	CQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["APaterno"]	      +
	" "								      +
	CQSCompitiendo->ObtenGimnasta()->SRegistrosPro2["AMaterno"]);
}
void QCalificaGimnasta::closeEvent(QCloseEvent *)
{

}

