#include <IMP_Facturacion.h>
#include <qlcdnumber.h>
#include <qpushbutton.h>
#include <ControladorOrdenes.h>
#include <QImprimeFactura.h>
#include<SISCOMComunicaciones++.h>

#include <IMP_Facturando.h>

QFacturacion::QFacturacion(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    GeneralesOrden *pGOrden,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				Facturacion(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				GenOrdenes(pGOrden)
{
IniciaVariables();
ConectaSlots();
MuestraDatosOrdenes();
CalculaFacturacion();
MuestraCalculoFacturacion();
	exec();
}

QFacturacion::~QFacturacion()
{

}

void QFacturacion::ConectaSlots()
{
	connect(QPBImprime,
		SIGNAL(clicked()),
		SLOT(S_ImprimeFactura()));

}
void QFacturacion::S_ImprimeFactura()
{
QFacturando *lQFacturando=new QFacturando(SiscomObtenInformacionDelEdit(QLECliente),
					  SiscomObtenInformacionDelEdit(QLERFC),
					  PProductos);
	
/*
	setExtension(lQFacturando);
	showExtension(true);
*/
	lQFacturando->exec();
}
void QFacturacion::IniciaVariables()
{

}
void QFacturacion::CalculaFacturacion()
{
SiscomParametrosConsulta lSPConsulta;
GeneralOrden *lGOrden;

	lSPConsulta << new SiscomParametroConsulta("ProductosDeLasOrdenes");
	for(lGOrden=GenOrdenes->first();
	    lGOrden;
	    lGOrden=GenOrdenes->next())
	     lSPConsulta << new SiscomParametroConsulta(lGOrden->SRegistrosPro2["IdOrden"]);
	     PProductos.clear();
OpProductosOrdenes lOPOrdenes(SisDatCom,&lSPConsulta);

		lOPOrdenes.SiscomConsulta("ConsultaControladorOrdenes",
					  (QPtrList<SiscomInformacion> *)&PProductos);
}
void QFacturacion::MuestraDatosOrdenes()
{

}
void QFacturacion::MuestraCalculoFacturacion()
{
ProductoE *lProducto;
int lintContador;
int lintNPRegreso=PProductos.count()-2;
	QTDatos->setNumRows(lintNPRegreso);
	for(lProducto=PProductos.first(),
	    lintContador=0;
	    lintContador<lintNPRegreso;
	    lProducto=PProductos.next(),
	    lintContador++)
	 SiscomAnexarRegistroALaTabla(lintContador,
	 			      QTDatos,
				      QStringList() 				<<
				      lProducto->SRegistrosPro2["CveProducto"]  <<
				      lProducto->SRegistrosPro2["Cantidad"]	<<
				      lProducto->SRegistrosPro2["Precio"]	<<
				      lProducto->SRegistrosPro2["Importe"]);
	    QLCDImpTotal->display(PProductos.at(lintNPRegreso)->SRegistrosPro2["Importe"]);
	    QLCImpMIVA->display(PProductos.at(lintNPRegreso+1)->SRegistrosPro2["Importe"]);
}
