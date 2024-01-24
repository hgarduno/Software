#include <IMP_Devoluciones.h>
#include <IMP_CapturaDato.h>
#include<SISCOMComunicaciones++.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisProductosE3Qt.h>
#include <CQSisDevoluciones.h>
/*
 * Para resolver la funcionalidad de este modulo se debera
 * revisar la forma en que se realiza la cotizacion de los
 * productos, en la ventana CotizaOrdenElectronica, para 
 * tomar esta funcionalidad y realizar practicamente 2 cotizaciones
 * la primera, despues de quitar los productos, y posteriormente
 * la del importe que se devolvera
 *
 */
QDevoluciones *InstanciaDevoluciones(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QDevoluciones((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QDevoluciones::QDevoluciones(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Devoluciones(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QDevoluciones::~QDevoluciones()
{

}

void QDevoluciones::ConectaSlots()
{
	connect(QLENoOrden,
		SIGNAL(returnPressed()),
		SLOT(SlotObtenOrden()));
	connect(QTPOrden,
		SIGNAL(doubleClicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionando(int,int,int,const QPoint &)));
	connect(QTPDevolver,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotCambiandoCantidadADevolver(int,int,int,const QPoint &)));
	connect(QPBDevuelve,
		SIGNAL(clicked()),
		SLOT(SlotDevuelve()));
}
void QDevoluciones::SlotCambiandoCantidadADevolver(int pintNProducto,
						   int pintColumna,
						   int,
						   const QPoint &)
{
  if(pintColumna==1)
  {
	QCapturaDato lQCDato("Introduce Cantidad","Cantidad");
	char lchrArrCantidad[10];
	lQCDato.ObtenDato(lchrArrCantidad);
  }
}
void QDevoluciones::SlotDevuelve()
{
CQSisDevolviendo lCQSDevolviendo(SisDatCom);
lCQSDevolviendo.Devuelve(&SisReg3CalDevolucion);
EjecutoDevolucion();

}
void QDevoluciones::SlotSeleccionando(int pintNProducto,
				      int,
				      int,
				      const QPoint &)
{
	if(pintNProducto!=-1)
	EliminandoProducto(pintNProducto);
}
void QDevoluciones::SlotObtenOrden()
{
	ConsultaOrden();
	CotizandoOrden();
	QLENoOrden->setEnabled(false);
}

void QDevoluciones::IniciaVariables()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QLENoOrden);
	QPBDevuelve->setEnabled(false);
}

void QDevoluciones::ConsultaOrden()
{
CQSisOrdenesElectronica lCQSisOrElectronica(SisDatCom);
lCQSisOrElectronica.ProductosOrden(
	chrPtrArgumentos[0],
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLENoOrden),
	&SisReg3ProductosE);
 QPBDevuelve->setEnabled(SisReg3ProductosE.count());
}
void QDevoluciones::CotizandoOrden()
{
	CotizaOrden();
	MuestraOrden();
}
void QDevoluciones::MuestraOrden()
{
SiscomRegistro3 *lSisReg3Producto;
int lintNRegistros=SisReg3ProductosE.count()-1;
int lintContador;
if(lintNRegistros>0)
{
QTPOrden->setNumRows(lintNRegistros);
for(lSisReg3Producto=SisReg3ProductosE.first(),
    lintContador=0;	
    lintContador<lintNRegistros;
    lSisReg3Producto=SisReg3ProductosE.next(),
    lintContador++)
{
SiscomDesarrollo3Qt::RegistroALaTabla(lintContador,
				      QTPOrden,
				      QStringList() 				<<
				      (*lSisReg3Producto)["CveProducto"] 	<<
				      (*lSisReg3Producto)["Cantidad"] 		<<
				      (*lSisReg3Producto)["Precio"]	 	<<
				      (*lSisReg3Producto)["ImporteCantidad"]);
}
QLCDNTOrden->display((*lSisReg3Producto)["ImporteTotal"]);
}
else
QTPOrden->setNumRows(0);
}
void QDevoluciones::CotizaOrden()
{
CQSisOrdenesElectronica lCQSisOrElectronica(SisDatCom);
lCQSisOrElectronica.CotizaDispositivos(&SisReg3ProductosE);
}

void QDevoluciones::EliminaProducto(int pintNProducto)
{
SiscomRegistro3 *lSisReg3Producto;
SiscomRegistro3 *lSisReg3Paso;
	lSisReg3Producto=SisReg3ProductosE[pintNProducto];
	SisReg3DevuelveE << (lSisReg3Paso=new SiscomRegistro3(lSisReg3Producto));
	lSisReg3Paso->SiscomActualizaCampo("IdCaja",getenv("IdCaja"));
	SisReg3ProductosE.remove(pintNProducto);
	MuestraProductoADevolver(lSisReg3Paso);
	CotizandoOrden();
}
void QDevoluciones::EliminandoProducto(int pintNProducto)
{
	EliminaProducto(pintNProducto);
	CalculaTotalADevolver();
	MuestraDevolucion();
}
void QDevoluciones::CalculaTotalADevolver()
{
CQSisDevolviendo lCQSisDevol(SisDatCom);
lCQSisDevol.CalculaDevolucion(&SisReg3DevuelveE,
			      &SisReg3CalDevolucion);
}
void QDevoluciones::MuestraDevolucion()
{
int lintURegistro=SisReg3CalDevolucion.count()-1;
QLCDNTDevolver->display((*(SisReg3CalDevolucion)[lintURegistro])["TotalADevolver"]);
}
void QDevoluciones::MuestraProductoADevolver(SiscomRegistro3 *pSisReg3Producto)
{
int lintNFilas=SisReg3DevuelveE.count();
  QTPDevolver->setNumRows(lintNFilas);
  SiscomDesarrollo3Qt::RegistroALaTabla(lintNFilas-1,
  					QTPDevolver,
					QStringList() 				<<
					(*pSisReg3Producto)["CveProducto"]	<<
					(*pSisReg3Producto)["Cantidad"]		<<
					(*pSisReg3Producto)["Precio"]		<<
					(*pSisReg3Producto)["ImporteCantidad"]);
}
void QDevoluciones::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
void QDevoluciones::EjecutoDevolucion()
{
	QTPOrden->setNumRows(0);
	SisReg3ProductosE.clear();
	SisReg3DevuelveE.clear();
	SisReg3CalDevolucion.clear();
	QLENoOrden->setEnabled(true);
	SiscomDesarrollo3Qt::PasaFocoControl(QLENoOrden);
	QPBDevuelve->setEnabled(false);
	QTPDevolver->setNumRows(0);
}
