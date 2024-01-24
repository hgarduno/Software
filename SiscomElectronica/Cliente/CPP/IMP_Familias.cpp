#include <IMP_Familias.h>


#include <IMP_CapturaDato.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
QFamilias *InstanciaFamilias(void *pSisDatCom,
			     char **pchrPtrArgumentos,
			     void *pQWParent,
			     const char *pchrPtrName,
			     int pintWFlags)
{

	return new QFamilias((SiscomDatCom *)pSisDatCom,
			     pchrPtrArgumentos,
			     (QWidget *)pQWParent,
			     pchrPtrName,
			     pintWFlags);
}
QFamilias::QFamilias(SiscomDatCom *pSisDatCom,
		     char **pchrPtrArgumentos,
		     QWidget* parent,
		     const char* name, 
		     WFlags fl )
    : FamiliasQ( parent, name, fl ),
     SisDatCom(pSisDatCom),
     chrPtrArgumentos(pchrPtrArgumentos)
{
	ConsultaFamilias();
	ConectaSlots();
}

QFamilias::~QFamilias()
{
}
void QFamilias::ConectaSlots()
{
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_Registrar()));
	connect(QTDatos,
		SIGNAL(doubleClicked(int,int,int,const QPoint &)),
		SLOT(S_CambiaDatosFamilia(int,int,int,const QPoint &)));
		
}
void QFamilias::S_CambiaDatosFamilia(int pintFila,
				     int pintColumna,
				     int,
				     const QPoint &)
{
	switch(pintColumna)
	{
	  case 0:
	  	{
	  	char lchrArrFamilia[128];
		Familia *lFamilia;
	  	QCapturaDato lQCDato("Cambia Familia","Familia");
		lQCDato.ObtenDato(lchrArrFamilia);
		QTDatos->setText(pintFila,pintColumna,lchrArrFamilia);
		QTDatos->setText(pintFila,2,"Actualiza");
		lFamilia=FFamilias.at(pintFila);
		lFamilia->SiscomActualizaCampo("NmbFamilia",lchrArrFamilia);
		lFamilia->SiscomActualizaCampo("EdoRegistro","Actualiza");
		}
	  break;
	  case 1:
	  	{
	  	char lchrArrDscFamilia[128];
		Familia *lFamilia;
		lFamilia=FFamilias.at(pintFila);
	  	QCapturaDato lQCDato("Cambia Descripcion","Descripcion");
		lQCDato.PonTextoInicial(lFamilia->SRegistrosPro2["DscFamilia"]);
		lQCDato.ObtenDato(lchrArrDscFamilia);
		QTDatos->setText(pintFila,pintColumna,lchrArrDscFamilia);
		QTDatos->setText(pintFila,2,"Actualiza");
		lFamilia->SiscomActualizaCampo("DscFamilia",lchrArrDscFamilia);
		lFamilia->SiscomActualizaCampo("EdoRegistro","Actualiza");
		}

	  break;

	}
	S_Registrar();
}
void QFamilias::S_Registrar()
{
OpFamilias lOpFamRegistrar(SisDatCom);

	lOpFamRegistrar.RegistraFamilias(FFamilias);
	ConsultaFamilias();

}
void QFamilias::S_Anexar()
{
int lintNFilas;

	FFamilias << new Familia("",
				 (const char *)QLEFamilia->text(),
				 (const char *)QLEDscFamilia->text(),
				 "Insertar");
	lintNFilas=FFamilias.count();
	QTDatos->setNumRows(lintNFilas);
	SiscomAnexarRegistroALaTabla(lintNFilas-1,
				     QTDatos,
				     QStringList() <<
				     (const char *)QLEFamilia->text() <<
				     (const char *)QLEDscFamilia->text() <<
				     "Insertar");
}
void QFamilias::ConsultaFamilias()
{
OpFamilias lOpFamConsulta(SisDatCom);
Familia *lFamilia;
int lintContador;
	FFamilias.clear();
	lOpFamConsulta.ConsultaFamilias(FFamilias);
	QTDatos->setNumRows(FFamilias.count());
	for(lFamilia=FFamilias.first(),
	    lintContador=0;
	    lFamilia;
	    lFamilia=FFamilias.next(),
	    lintContador++)
	 SiscomAnexarRegistroALaTabla(lintContador,
	 			      QTDatos,
				      QStringList() <<
				      lFamilia->SRegistrosPro2["NmbFamilia"] <<
				      lFamilia->SRegistrosPro2["DscFamilia"] <<
				      lFamilia->SRegistrosPro2["EdoRegistro"]);
				      
}
void QFamilias::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
