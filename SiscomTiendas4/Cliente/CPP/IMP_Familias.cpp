#include <IMP_Familias.h>
#include<SISCOMComunicaciones++.h>

#include <qpushbutton.h>
#include <qlineedit.h>

#include <CQSisOpTiendas4.h>
#include <CQSisFamilias.h>
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
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Familias(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QFamilias::~QFamilias()
{

}

void QFamilias::ConectaSlots()
{
	connect(QLEFamilia,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoDsc()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(SlotAnexa()));
	connect(QTEDsc,
		SIGNAL(textChanged()),
		SLOT(SlotCapturandoDsc()));
	connect(QLEFamilia,
		SIGNAL(textChanged(const QString &)),
		SLOT(SlotCapturandoFamilia(const QString &)));

}
void QFamilias::SlotCapturandoFamilia(const QString &)
{
HabilitaAnexar();
}
void QFamilias::SlotCapturandoDsc()
{
HabilitaAnexar();
}
void QFamilias::SlotPasaFocoDsc()
{
	SiscomPasaFocoControl(QTEDsc);
	HabilitaAnexar();
}

void QFamilias::SlotAnexa()
{
	RegistraFamilia();
	ConsultandoFamilias();
	QPBAnexar->setEnabled(false);
	SiscomPasaFocoControl(QLEFamilia);

}
void QFamilias::MuestraFamilias()
{
CQSisFamilia *lCQSFamilia;
int lintContador ;

	QTDatos->setNumRows(CQSLFamilia.count());
for(lintContador=0,
    lCQSFamilia=CQSLFamilia.first();
    lCQSFamilia;
    lintContador++,
    lCQSFamilia=CQSLFamilia.next())
SiscomAnexarRegistroALaTabla(lintContador,
			     QTDatos,
			     QStringList() <<
			     lCQSFamilia->SRegistrosPro2["Familia"] <<
			     lCQSFamilia->SRegistrosPro2["Dsc"]);
SiscomAjustaFilas(QTDatos);
SiscomAjustaColumnas(QTDatos);
}
void QFamilias::RegistraFamilia()
{
CQSisOpTiendas4 lCQSOT4Anexa(SisDatCom);
		lCQSOT4Anexa.AnexaFamilia(FormaFamilia());
}
void QFamilias::ConsultaFamilias()
{
CQSisOpTiendas4 lCQSOT4Familias(SisDatCom);
	lCQSOT4Familias.Familias(&CQSLFamilia);	
}
void QFamilias::IniciaVariables()
{
	SiscomPasaFocoControl(QLEFamilia);
	ConsultandoFamilias();
}
void QFamilias::ConsultandoFamilias()
{
	ConsultaFamilias();
	MuestraFamilias();
}
CQSisFamilia *QFamilias::FormaFamilia()
{
	return new CQSisFamilia(
		"",
		SiscomObtenInformacionDelEdit(QLEFamilia),
		SiscomObtenInformacionDelEdit(QTEDsc));
}
void QFamilias::HabilitaAnexar()
{
	QPBAnexar->setEnabled(!QLEFamilia->text().isEmpty() &&
			      !QTEDsc->text().isEmpty());
			
}

void QFamilias::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
