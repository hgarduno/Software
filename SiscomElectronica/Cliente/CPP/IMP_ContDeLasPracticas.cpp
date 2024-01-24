#include <IMP_ContDeLasPracticas.h>

#include <Escuelas.h>
#include <Materias.h>

#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QContDeLasPracticas::QContDeLasPracticas(Escuela *pEscuela,
					   Materia *pMateria,
					   SiscomDatCom *pSisDatCom,
					   char **pchrPtrArgumentos,
					   QWidget* parent,
					   const char* name,
					   bool modal,
					   WFlags fl )
    : ContDeLasPracticas( parent, name, modal, fl ),
    SisDatCom(pSisDatCom),
    chrPtrArgumentos(pchrPtrArgumentos),
    EEscuela(pEscuela),
    MMateria(pMateria)
{
	ConsultaLasPracticas();	
	ConectaSlots();
	exec();
}

QContDeLasPracticas::~QContDeLasPracticas()
{
}

void QContDeLasPracticas::ConsultaLasPracticas()
{
PPracticas.clear();
ConsultaPracticas lCnsPracticas(SisDatCom,
				MMateria->SRegistrosPro2["IdMateria"],
				PPracticas);

Practica *lPractica;
int lintContador;
	QTDatos->setNumRows(PPracticas.count());
	for(lintContador=0,
	    lPractica=PPracticas.first();
	    lPractica;
	    lPractica=PPracticas.next(),
	    lintContador++)
	 SiscomAnexarRegistroALaTabla(lintContador,
	 			      QTDatos,
				      QStringList() <<
				      lPractica->SRegistrosPro2["Nombre"] <<
				      lPractica->SRegistrosPro2["EdoRegistro"]);
	
}
Practica *QContDeLasPracticas::ObtenPractica()
{
	return PPractica;
}
void QContDeLasPracticas::ConectaSlots()
{
	connect(QPBSelEscuela,
		SIGNAL(clicked()),
		SLOT(S_SelPractica()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_Registrar()));
}
void QContDeLasPracticas::S_SelPractica()
{
	PPractica=PPracticas.at(QTDatos->currentRow());
	done(1);
}
void QContDeLasPracticas::S_Anexar()
{
int lintNumFilas;
	PPracticas << new Practica("",
				   MMateria->SRegistrosPro2["IdMateria"],
				   (const char *)QLEPractica->text(),
				   "Insertar");
	lintNumFilas=PPracticas.count();
	QTDatos->setNumRows(lintNumFilas);
	SiscomAnexarRegistroALaTabla(lintNumFilas-1,
				     QTDatos,
				     QStringList() <<
				     QLEPractica->text() <<
				     "Nuevo");

	
}
void QContDeLasPracticas::S_Registrar()
{
ConsultaPracticas lCnsPracticas;
		lCnsPracticas.RegistraPracticas(SisDatCom,
						PPracticas);
	ConsultaLasPracticas();
}
