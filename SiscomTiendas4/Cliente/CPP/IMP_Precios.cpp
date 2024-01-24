#include <IMP_Precios.h>
#include<SISCOMComunicaciones++.h>
#include <CQSisOpTiendas4.h>
#include <CQSisPrecios.h>

#include <qpushbutton.h>
QPrecios *InstanciaPrecios(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QPrecios((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QPrecios::QPrecios(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Precios(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QPrecios::~QPrecios()
{

}

void QPrecios::ConectaSlots()
{
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoDsc()));
	connect(QPBRegistra,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));

}
void QPrecios::SlotPasaFocoDsc()
{
	SiscomPasaFocoControl(QTEDsc);
}
void QPrecios::SlotRegistra()
{
    AnexaPrecio(FormaPrecio());
    ConsultandoPrecios();
}
void QPrecios::IniciaVariables()
{
	ConsultandoPrecios();
	SiscomPasaFocoControl(QLENombre);

}

void QPrecios::ConsultandoPrecios()
{
	ConsultaPrecios();
	MuestraPrecios();
}
void QPrecios::ConsultaPrecios()
{
CQSisOpTiendas4 lCQSOT4Precios(SisDatCom);
lCQSOT4Precios.Precios(&CQSLPrecio);
}
void QPrecios::MuestraPrecios()
{
int lintContador;
CQSisPrecio *lCQSPrecio;
QTDatos->setNumRows(CQSLPrecio.count());
for(lCQSPrecio=CQSLPrecio.first(),
    lintContador=0;
    lCQSPrecio;
    lCQSPrecio=CQSLPrecio.next(),
    lintContador++)
SiscomAnexarRegistroALaTabla(lintContador,
			      QTDatos,
			      QStringList()	<<
			      lCQSPrecio->SRegistrosPro2["Nombre"]	<<
			      lCQSPrecio->SRegistrosPro2["Dsc"]);
SiscomAjustaColumnas(QTDatos);
SiscomAjustaFilas(QTDatos);
}

void QPrecios::AnexaPrecio(CQSisPrecio *pCQPrecio)
{
CQSisOpTiendas4 lCQSOT4Precio(SisDatCom);
	lCQSOT4Precio.AnexaPrecio(pCQPrecio);

}
CQSisPrecio *QPrecios::FormaPrecio()
{
return new CQSisPrecio("",	
			SiscomObtenInformacionDelEdit(QLENombre),
			SiscomObtenInformacionDelEdit(QTEDsc));

}

void QPrecios::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
