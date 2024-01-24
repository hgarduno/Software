#include <IMP_TiposPrecios.h>
#include<SISCOMComunicaciones++.h>
#include <CQSisTipoPrecio.h>
#include <qpushbutton.h>
QTiposPrecios *InstanciaTiposPrecios(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QTiposPrecios((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QTiposPrecios::QTiposPrecios(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				TiposPrecios(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QTiposPrecios::~QTiposPrecios()
{

}

void QTiposPrecios::ConectaSlots()
{
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoDescripcion()));
	connect(QLEDescripcion,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoRegistra()));
	connect(QPBRegistra,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));
}
void QTiposPrecios::SlotPasaFocoDescripcion()
{
	SiscomPasaFocoControl(QLEDescripcion);
}
void QTiposPrecios::SlotPasaFocoRegistra()
{
	SiscomPasaFocoControl(QPBRegistra);
}
void QTiposPrecios::SlotRegistra()
{
	Registra();
}

void QTiposPrecios::IniciaVariables()
{
SiscomPasaFocoControl(QLENombre);
ConsultandoTipoPrecios();
}
void QTiposPrecios::Registra()
{
CQSisOpTipoPrecio lCQSOTPrecio(SisDatCom);
lCQSOTPrecio.TipoPrecio(TipoPrecio());
ConsultandoTipoPrecios();

}
void QTiposPrecios::ConsultandoTipoPrecios()
{
	ConsultaTipoPrecios();
	MuestraTipoPrecios();
}
void QTiposPrecios::ConsultaTipoPrecios()
{
CQSisOpTipoPrecio lCQSOTPrecio(SisDatCom);
lCQSOTPrecio.TipoPrecio(&CQSLTPrecio);
}
void QTiposPrecios::MuestraTipoPrecios()
{
CQSisTipoPrecio *lCQSTPrecio;
int lintContador;
QTDatos->setNumRows(CQSLTPrecio.count());
for(lintContador=0,
    lCQSTPrecio=CQSLTPrecio.first();
    lCQSTPrecio;
    lintContador++,
    lCQSTPrecio=CQSLTPrecio.next())
 SiscomAnexarRegistroALaTabla(
 	lintContador,
	QTDatos,
	QStringList () <<
	lCQSTPrecio->SRegistrosPro2["Nombre"] <<
	lCQSTPrecio->SRegistrosPro2["Descripcion"]);
SiscomAjustaColumnas(QTDatos);
}
CQSisTipoPrecio *QTiposPrecios::TipoPrecio()
{
return new CQSisTipoPrecio(
		"",
		SiscomObtenInformacionDelEdit(QLENombre),
		SiscomObtenInformacionDelEdit(QLEDescripcion));
}
