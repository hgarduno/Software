#include <IMP_PrecioProducto.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlPrecios.h>
#include <QCtrlProductos.h>
#include <CQSisPrecios.h>
#include <CQSisProductos.h>
#include <CQSisOpTiendas4.h>
#include <qpushbutton.h>
QPrecioProducto *InstanciaPrecioProducto(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QPrecioProducto((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QPrecioProducto::QPrecioProducto(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				PrecioProducto(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QPrecioProducto::~QPrecioProducto()
{

}

void QPrecioProducto::ConectaSlots()
{
		connect(QPBIniciaPrecios,
		SIGNAL(clicked()),
		SLOT(SlotIniciaPrecios()));
	connect(QLEPrecio,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoActualiza()));
	connect(QPBActualiza,
		SIGNAL(clicked()),
		SLOT(SlotActualiza()));

}
void QPrecioProducto::SlotActualiza()
{
	ActualizaPrecio();
	ConsultandoPreciosProducto();
	QCtrPrecios->setFocus();
}
void QPrecioProducto::SlotPasaFocoActualiza()
{
	SiscomPasaFocoControl(QPBActualiza);
}

void QPrecioProducto::SlotIniciaPrecios()
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisOpTiendas4 lCQSOT4IniPrecios(SisDatCom);
	lCQSOT4IniPrecios.IniciaPrecios(&lSRegistrosPro2);
}
void QPrecioProducto::SlotProducto(CQSisProducto *pCQSProducto)
{
	if(pCQSProducto)
	{
	CQSProducto=pCQSProducto;
	MuestraDescripcion();
	SiscomPasaFocoControl(QLEPrecio);
	ConsultandoPreciosProducto();
	}
}
void QPrecioProducto::SlotPrecio(CQSisPrecio *pCQSPrecio)
{
	if(pCQSPrecio)
	{
	CQSPrecio=pCQSPrecio;
	QCtrProductos->setFocus();
	MuestraDescripcionPrecio();
	}
}
void QPrecioProducto::IniciaVariables()
{
	connect(QCtrPrecios,
		SIGNAL(SignalPrecio(CQSisPrecio *)),
		SLOT(SlotPrecio(CQSisPrecio *)));
	connect(QCtrProductos,
		SIGNAL(SignalProductos(CQSisProducto *)),
		SLOT(SlotProducto(CQSisProducto *)));

	QCtrPrecios->PonServidor(SisDatCom);
	QCtrProductos->PonServidor(SisDatCom);
	QCtrPrecios->IniciaControl();
	QCtrProductos->IniciaControl();
	QCtrPrecios->setFocus();


}

void QPrecioProducto::MuestraDescripcion()
{
	QTEDscProducto->setText(CQSProducto->SRegistrosPro2["Dsc"]);
}
void QPrecioProducto::MuestraDescripcionPrecio()
{
	QTEDscPrecio->setText(CQSPrecio->SRegistrosPro2["Dsc"]);
}

void QPrecioProducto::ConsultandoPreciosProducto()
{
	ConsultaPreciosProducto();
	MuestraPreciosProducto();
}
void QPrecioProducto::ConsultaPreciosProducto()
{
CQSisOpTiendas4 lCQSOT4PProducto(SisDatCom);
	lCQSOT4PProducto.PreciosProducto(CQSProducto,&CQSLDPrecio);
}
void QPrecioProducto::MuestraPreciosProducto()
{
CQSisDatoPrecio *lCQSDPrecio;
int lintContador;
	QTDatos->setNumRows(CQSLDPrecio.count());
	for(lCQSDPrecio=CQSLDPrecio.first(),
	    lintContador=0;
	    lCQSDPrecio;
	    lCQSDPrecio=CQSLDPrecio.next(),
	    lintContador++)
	SiscomAnexarRegistroALaTabla(
		lintContador,
		QTDatos,
		QStringList()	<<
		lCQSDPrecio->ObtenPrecio()->SRegistrosPro2["Nombre"]	<<
		lCQSDPrecio->SRegistrosPro2["Valor"]			<<
		(*lCQSDPrecio)["Cantidad"]);
					
}
void QPrecioProducto::ActualizaPrecio()
{
CQSisOpTiendas4 lCQSOT4APrecio(SisDatCom);

lCQSOT4APrecio.ActualizaPrecioProducto(
		CQSProducto,
		new CQSisDatoPrecio(
		       CQSPrecio,
		       SiscomObtenInformacionDelEdit(QLEPrecio),
		       SiscomObtenInformacionDelEdit(QLECantidad)));
}

void QPrecioProducto::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
