#include <IMP_ContEscuelas.h> 
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


QContEscuelas::QContEscuelas(SiscomDatCom *pSisDatCom,
			   char **pchrPtrArgumentos,
			   QWidget* parent,
			   const char* name, 
			   bool modal,
			   WFlags fl )
    : ContEscuelas( parent, name, modal, fl ),
    SisDatCom(pSisDatCom),
    chrPtrArgumentos(pchrPtrArgumentos),
    EEscuela(0)
{
	ConsultaLasEscuelas();
	ConectaSlots();
	exec();
}

QContEscuelas::~QContEscuelas()
{

}
void QContEscuelas::ConectaSlots()
{
	connect(QPBSelEscuela,
		SIGNAL(clicked()),
		SLOT(S_SelEscuela()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_Registrar()));
}
void QContEscuelas::S_SelEscuela()
{
	EEscuela=EEscuelas.at(QTDatos->currentRow());
	done(1);
}
Escuela *QContEscuelas::ObtenEscuela()
{
	return EEscuela;
}
void QContEscuelas::ConsultaLasEscuelas()
{
EEscuelas.clear();
ConsultaEscuelas lCnsEscuelas(SisDatCom,
			      EEscuelas);
Escuela *lEscuela;
int lintContador;
	QTDatos->setNumRows(EEscuelas.count());
	for(lEscuela=EEscuelas.first(),
	    lintContador=0;
	    lEscuela;
	    lEscuela=EEscuelas.next(),
	    lintContador++)
	  SiscomAnexarRegistroALaTabla(lintContador,
	  			       QTDatos,
				       QStringList () <<
				       lEscuela->SRegistrosPro2["Nombre"] <<
				       lEscuela->SRegistrosPro2["EdoRegistro"]);

}
void QContEscuelas::S_Anexar()
{
int lintNFilas;
	EEscuelas << new Escuela("",
				 (const char *)QLEEscuela->text(),
				 "Insertar");
	lintNFilas=EEscuelas.count();
	QTDatos->setNumRows(lintNFilas);
	SiscomAnexarRegistroALaTabla(lintNFilas-1,
				     QTDatos,
				     QStringList() << 
				     QLEEscuela->text() <<
				     "Nuevo");
}
void QContEscuelas::S_Registrar()
{
ConsultaEscuelas lCnsEscuelas(SisDatCom,EEscuelas);
		lCnsEscuelas.RegistraEscuelas();

ConsultaLasEscuelas();
}
