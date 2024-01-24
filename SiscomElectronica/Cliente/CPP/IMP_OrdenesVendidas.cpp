#include <IMP_OrdenesVendidas.h>
#include <IMP_OrdenesPorFecha.h>
#include <IMP_QControlFecha.h>
#include <IMP_Facturacion.h>
#include <SISCOMComunicaciones++.h>
#include <ControladorOrdenes.h>
#include <qlineedit.h>
#include <qpushbutton.h>
QOrdenesVendidas *InstanciaOrdenesVendidas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QOrdenesVendidas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QOrdenesVendidas::QOrdenesVendidas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				OrdenesVendidas(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QOrdenesVendidas::~QOrdenesVendidas()
{

}

void QOrdenesVendidas::ConectaSlots()
{
	connect(QLENoOrden,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAnexarOrden()));
	connect(QPBAOrden,
		SIGNAL(clicked()),
		SLOT(S_AnexarOrden()));
	connect(QPBNOrden,
		SIGNAL(clicked()),
		SLOT(S_NuevaOrden()));
	connect(QPBOFecha,
		SIGNAL(clicked()),
		SLOT(S_OrdenesPorFecha()));
	connect(QPBFacturar,
		SIGNAL(clicked()),
		SLOT(S_Facturacion()));


}
void QOrdenesVendidas::S_Facturacion()
{
QFacturacion lQFacturacion(SisDatCom,chrPtrArgumentos,&GOrdenes);

}
void QOrdenesVendidas::CopiaArgumentos(char ***pchrPtrArgumentos)
{
int lintContador;
	*pchrPtrArgumentos=(char **)malloc(sizeof(char *)*8);
	for(lintContador=0;
	    lintContador<5;
	    lintContador++)
	  (*pchrPtrArgumentos)[lintContador]=strdup(chrPtrArgumentos[lintContador]);
	  (*pchrPtrArgumentos)[lintContador]=strdup((const char *)QCFSFechaIni->ObtenFecha());
	  (*pchrPtrArgumentos)[lintContador+1]=strdup((const char *)QCFSFechaFin->ObtenFecha());
	  (*pchrPtrArgumentos)[lintContador+2]=0;
}
void QOrdenesVendidas::S_OrdenesPorFecha()
{
/*
 * El Ultimo indice del arreglo que tiene informacion 
 * es el no 4, y contiene el tipo de persona del empleado
 */
char **lchrPtrCopiaArgumentos;
CopiaArgumentos(&lchrPtrCopiaArgumentos);
QOrdenesPorFecha lQOPFecha(SisDatCom,lchrPtrCopiaArgumentos);
		lQOPFecha.ObtenOrdenesSeleccionadas(GOrdenes);
SiscomParametrosConsulta lSPConsulta;
GeneralOrden *lGOrden=GOrdenes.first();

	/*lGOrden->SiscomActualizaCampo("Parametro","ProductosDeLasOrdenes"); */
	lSPConsulta << new SiscomParametroConsulta("ProductosDeLasOrdenes");
	for(lGOrden=GOrdenes.first();
	    lGOrden;
	    lGOrden=GOrdenes.next())
	     lSPConsulta << new SiscomParametroConsulta(lGOrden->SRegistrosPro2["IdOrden"]);
	     PProductos.clear();
OpProductosOrdenes lOPOrdenes(SisDatCom,&lSPConsulta);

		lOPOrdenes.SiscomConsulta("ConsultaControladorOrdenes",
					  (QPtrList<SiscomInformacion> *)&PProductos);
		MuestraProductos(PProductos);
}
void QOrdenesVendidas::S_PasaFocoAnexarOrden()
{
	SiscomPasaFocoControl(QPBAOrden);
}
void QOrdenesVendidas::S_AnexarOrden()
{
ProductosE lProductos;
	ObtenProductosOrden(SiscomObtenInformacionDelEdit(QLENoOrden),
			    lProductos);
	PProductos+=lProductos;

	MuestraProductos(PProductos);
}
void QOrdenesVendidas::S_NuevaOrden()
{
PProductos.clear();
ObtenProductosOrden(SiscomObtenInformacionDelEdit(QLENoOrden),PProductos);
MuestraProductos(PProductos);
}
void QOrdenesVendidas::IniciaVariables()
{
	QCFSFechaFin->ColocaFechaHoy();
	QCFSFechaIni->ColocaFechaHoy();
}

void QOrdenesVendidas::ObtenProductosOrden(const char *pchrPtrIdOrden,
					   ProductosE &pProductos)
{
IdentificadorOrdenes lIdOrdenes;

	lIdOrdenes <<
	new IdentificadorOrden("","ProductosOrdenVendida") <<
	new IdentificadorOrden("",
			       pchrPtrIdOrden);

OpProductosOrdenes lOpProdOrdenes(SisDatCom,
				  &lIdOrdenes);
	lOpProdOrdenes.SiscomConsulta("ConsultaControladorOrdenes",
				      (QPtrList<SiscomInformacion> *)&pProductos);
}
void QOrdenesVendidas::ProductosLog(ProductosE pProductos)
{
ProductoE *lProducto;

	for(lProducto=pProductos.first();
	    lProducto;
	    lProducto=pProductos.next())
	  SiscomMensajesLog(gPtrFleArchivoLog,
	  		    "%s\t%s\t%s",
			    lProducto->SRegistrosPro2["CveProducto"],
			    lProducto->SRegistrosPro2["Cantidad"],
			    lProducto->SRegistrosPro2["Precio"]);

}
void QOrdenesVendidas::MuestraProductos(ProductosE pProductos)
{
ProductoE *lProducto;
int lintContador;
	QTDatos->setNumRows(pProductos.count());
	for(lProducto=pProductos.first(),
	    lintContador=0;
	    lProducto;
	    lProducto=pProductos.next(),
	    lintContador++)
	 SiscomAnexarRegistroALaTabla(lintContador,
	 			      QTDatos,
				      QStringList() 				<<
				      lProducto->SRegistrosPro2["IdPractica"]	<<
				      lProducto->SRegistrosPro2["CveProducto"]  <<
				      lProducto->SRegistrosPro2["Cantidad"]	<<
				      lProducto->SRegistrosPro2["Precio"]	<<
				      lProducto->SRegistrosPro2["Importe"]);
				     

}

void QOrdenesVendidas::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
