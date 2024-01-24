#include <IMP_ContMaterias.h>
#include <Escuelas.h>
#include <qvariant.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


QContMaterias::QContMaterias(Escuela *pEscuela,
			   SiscomDatCom *pSisDatCom,
			   char **pchrPtrArgumentos,
			   QWidget* parent, 
			   const char* name, 
			   bool modal,
			   WFlags fl )
    : ContMaterias( parent, name, modal, fl ),
    EEscuela(pEscuela),
    SisDatCom(pSisDatCom),
    chrPtrArgumentos(pchrPtrArgumentos)
    
{
  setCaption(QString("Materias De La Escuela:") +
  	     EEscuela->SRegistrosPro2["Nombre"]);
  ConsultaLasMaterias();
  ConectaSlots();
  exec();
}

QContMaterias::~QContMaterias()
{
}
void QContMaterias::ConsultaLasMaterias()
{
Materia *lMateria;
int lintContador;
ConsultaMaterias lCnsMaterias(SisDatCom,
			      EEscuela->SRegistrosPro2["IdEscuela"],
			      MMaterias);
	QTDatos->setNumRows(MMaterias.count());
	for(lintContador=0,
	    lMateria=MMaterias.first();
	    lMateria;
	    lMateria=MMaterias.next(),
	    lintContador++)
	  SiscomAnexarRegistroALaTabla(lintContador,
	  			       QTDatos,
				       QStringList () <<
				       lMateria->SRegistrosPro2["Nombre"]);
}
void QContMaterias::ConectaSlots()
{
	connect(QPBSelEscuela,
		SIGNAL(clicked()),
		SLOT(S_SelMateria()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_Registrar()));
}
void QContMaterias::S_Registrar()
{
ConsultaMaterias lCnsMaterias(SisDatCom,
			      "",
			      MMaterias);
		lCnsMaterias.RegistraMaterias();
}
void QContMaterias::S_Anexar()
{
	MMaterias << new Materia(EEscuela->SRegistrosPro2["IdEscuela"],
				 "",
				 (const char *)QLEMateria->text(),
				 "Insertar");
int lintNumFilas=MMaterias.count();
	QTDatos->setNumRows(lintNumFilas);
	SiscomAnexarRegistroALaTabla(lintNumFilas-1,
				     QTDatos,
				     (const char *)QLEMateria->text());

}
void QContMaterias::S_SelMateria()
{
	MMateria=MMaterias.at(QTDatos->currentRow());
	done(1);
}

Materia *QContMaterias::ObtenMateria()
{
	return MMateria;
}
