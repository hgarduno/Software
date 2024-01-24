#include <IMP_TiposPrecios.h>
#include <CQSiscomCom.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qcombobox.h>
QTiposPrecios *InstanciaTiposPrecios(void *pCSisDatCom,
				     void *pQWParent,
				     const char *pchrPtrName,
				     int pintWFlags)
{

	return new QTiposPrecios((CSISCOMDatComunicaciones *)pCSisDatCom,
				 (QWidget *)pQWParent,
				 pchrPtrName,
				 pintWFlags);
}


QTiposPrecios::QTiposPrecios(CSISCOMDatComunicaciones *pCSisDatCom,
			 QWidget* parent, const char* name, WFlags fl )
    : TiposPrecios( parent, name, fl ),
	CSisDatCom(pCSisDatCom)
{
	IniciaVariables();
	ConectaSlots();
}

QTiposPrecios::~QTiposPrecios()
{
}
void QTiposPrecios::IniciaVariables()
{
	ConsultaLosPrecios();
	PasaFocoControl(QLETipoPrecio);
}
void QTiposPrecios::ConectaSlots()
{
	connect(QLETipoPrecio,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoDescripcion()));
	connect(QLEDescripcion,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAnexar()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_Registrar()));

}
void QTiposPrecios::S_PasaFocoDescripcion()
{
	PasaFocoControl(QLEDescripcion);
}
void QTiposPrecios::S_PasaFocoAnexar()
{
	PasaFocoControl(QPBAnexar);
}
void QTiposPrecios::S_Anexar()
{
	AnexarRegistroALaTabla(QTDatos ,
				QStringList () <<
				QLETipoPrecio->text() <<
				QLEDescripcion->text());

	CQTPrecios.append(new TipoPrecio((const char *)QLETipoPrecio->text() ,
					 (const char *)QLEDescripcion->text(),
					 (const char *)QCBTipo->currentText()));
	PasaFocoControl(QLETipoPrecio);
}
void QTiposPrecios::S_Registrar()
{
CQCtrTiposPrecios lCQTPrecios(CSisDatCom,
			      CQCtrTiposPrecios::Registrar,
			      &CQTPrecios);
}

void QTiposPrecios::ConsultaLosPrecios()
{
CQCtrTiposPrecios lCQCTPrecios(CSisDatCom,
			       CQCtrTiposPrecios::Consultar,
			       &CQTPrecios);
TipoPrecio *lTPrecio;
int lintContador;

	QTDatos->setNumRows(CQTPrecios.count());
	for(lTPrecio=CQTPrecios.first(),
	    lintContador=0;
	    lTPrecio;
	    lTPrecio=CQTPrecios.next(),
	    lintContador++)
	{
	 lTPrecio->PonEdoRegistro("1");
	 SISCOMAnexarRegistroALaTabla(lintContador,
			 	      QTDatos,
			 	      QStringList () <<
				      lTPrecio->ObtenNmbTipoPrecio() <<
				      lTPrecio->ObtenDescripcion() );
	}


}
