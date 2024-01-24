#include <IMP_VentasElectronica.h>
#include <IMP_CNSClientes.h>
#include <IMP_CotizaDispositivos.h>
#include <IMP_OrdenElectronica.h>
#include <IMP_SelOrden.h>
#include <IMP_CotizaPractica.h>
#include <IMP_SelExpendios.h>
#include <IMP_RegProductoSinOrden.h>
#include <IMP_SelAlumno.h>
#include <IMP_Caja.h>


#include <ControladorOrdenes.h>
#include <SISCOMComunicaciones++.h>
#include <SISCOMVentanaPrincipal3.h>
#include <SiscomRegistros3.h>

#include <SiscomDesarrollo3Qt++.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qtoolbox.h>
#include <qiconview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qptrlist.h>
#include <qdockwindow.h>

/* Historico de Cambios
 * Miercoles 16 de Enero del 2013 
 * Se agrega la integracion con la caja central de cobro
 *
 *
 */
QVentasElectronica *CreaInstanciaVentasElectronica(void *pSDatCom,
						   char **pchrPtrArgumentos,
						   void *pQWParent,
						   const char *pchrPtrName,
						   int pintFlags)
{
	return new QVentasElectronica((SiscomDatCom *)pSDatCom,
				      pchrPtrArgumentos,
				      (QWidget *)pQWParent,
				      pchrPtrName,
				      pintFlags);
}
QVentasElectronica::QVentasElectronica(SiscomDatCom *pSisDatCom,
				       char **pchrPtrArgumentos,
				       QWidget* parent,
				       const char* name,
				       WFlags fl )
    : VentasElectronica( parent, name, fl ),
    SisDatCom(pSisDatCom),
    QWParent(parent),
    chrPtrArgumentos(pchrPtrArgumentos),
    SISCOMVenPrincipal((SISCOMVentanaPrincipal *)chrPtrArgumentos[3]),
    intModificaOrdenPorCajaCentral(0)
{
chrPtrIdExpendio=chrPtrArgumentos[0];
IniciaVariables();
ConectaSlots();
}

QVentasElectronica::~QVentasElectronica()
{
}

void QVentasElectronica::SeleccionaExpendio()
{
QSelExpendios lQSelExpendio(SisDatCom);
EmpresaN *lExpendio=lQSelExpendio.ObtenExpendio();

	chrPtrIdExpendio=lExpendio->SRegistrosPro2["IdEmpresa"];
	
}
void QVentasElectronica::IniciaVariables()
{
EmpresaN *lExpendio=(EmpresaN *)chrPtrArgumentos[2];
	QCtzaDispositivo=new QCotizaDispositivos(SisDatCom,
						 chrPtrIdExpendio,
						 chrPtrArgumentos[4],
						 "DEFAULT",
						 QWParent);
	QDockWindow *dw=new QDockWindow( QDockWindow::InDock,QWParent);

	dw->setResizeEnabled( TRUE );
	dw->setVerticalStretchable( TRUE );
	SISCOMVenPrincipal->addDockWindow( dw, DockLeft );
	SISCOMVenPrincipal->setDockEnabled( dw, DockTop, FALSE );
	SISCOMVenPrincipal->setDockEnabled( dw, DockBottom, FALSE );
	dw->setCloseMode( QDockWindow::Always );
	QPoint lQPDonde(10,10);
	reparent(dw,lQPDonde);
	dw->setWidget(this);
	dw->setCaption(lExpendio->SRegistrosPro2["RazonSocial"]);
	/*
	 * Miercoles 16 de Enero del 2013 
	 * Se integra la caja central
	 */
	CargaCajaCentral();
}
int QVentasElectronica::SeDebeCargarLaCajaCentral()
{
const char *lchrPtrCajaCentral=getenv("CajaCentral");
return (lchrPtrCajaCentral &&
        !strcmp("Si",lchrPtrCajaCentral));
}
void QVentasElectronica::CargaCajaCentral()
{

  if(SeDebeCargarLaCajaCentral())
  {
    QCajaCentral=new QCaja(SisDatCom,
    			   chrPtrArgumentos,
			   QWParent,
			   "QCajaCentral");
    connect(QCajaCentral,
    	    SIGNAL(SignalModificaOrdenCaja(const char *,
	    				   ProductosE *,
					   Persona *)),
	    SLOT(S_ModificaOrdenCajaCentral(const char *,
	    				    ProductosE *,
					    Persona *)));
  }
}
void QVentasElectronica::S_ModificaOrdenCajaCentral(const char *pchrPtrIdVenta,
						    ProductosE *pProductos,
						    Persona *pPCliente)
{
CreaOrdenModificaPorCajaCentral(pchrPtrIdVenta,*pProductos,pPCliente);
}
void QVentasElectronica::ConectaSlots()
{
	connect(QPBNOrden,
		SIGNAL(clicked()),
		SLOT(S_NuevaOrden()));
	connect(QIVOrdenes,
		SIGNAL(clicked(QIconViewItem *)),
		SLOT(S_SelOrden(QIconViewItem *)));
	connect(QCtzaDispositivo,
		SIGNAL(SignalAnexarALaOrden(ProductoE *)),
		SLOT(S_AnexarALaOrden(ProductoE *)));
	connect(QPBCotizaPractica,
		SIGNAL(clicked()),
		SLOT(S_CotizaPractica()));
	connect(QPBVenderTodo,
		SIGNAL(clicked()),
		SLOT(S_VenderTodo()));
	connect(QPBRPSinOrden,
		SIGNAL(clicked()),
		SLOT(S_RegProductoSinOrden()));
}
void QVentasElectronica::S_RegProductoSinOrden()
{
QRegProductoSinOrden lQRProdSinOrden(SisDatCom,chrPtrArgumentos);

}
void QVentasElectronica::S_VenderTodo()
{
QIconViewItem *lQIVItem;
QPtrList<QIconVOrdenE> lQOrdenes;
QIconVOrdenE *lQIVOrdenE;
	for(lQIVItem=QIVOrdenes->firstItem();
	    lQIVItem;
	    lQIVItem=lQIVItem->nextItem())
	    lQOrdenes.append((QIconVOrdenE *)lQIVItem);
	 for(lQIVOrdenE=lQOrdenes.first();
	     lQIVOrdenE;
	     lQIVOrdenE=lQOrdenes.next())
	    EjecutaVenta(lQIVOrdenE); 
}
void QVentasElectronica::S_CotizaPractica()
{
QCotizaPractica lQCPractica(SisDatCom,
			    chrPtrIdExpendio,
                            "DEFAULT");
	if(lQCPractica.ObtenSeleccion()==1)
	{
		if(QIVOrdenes->count())
		if(QIVOrdenes->count()==1)
		{
		   ((QIconVOrdenE *)QIVOrdenes->firstItem())->ObtenOrdenElectronica()->AnexaProductosALaOrden(lQCPractica.ObtenProductos());
		   QCtzaDispositivo->setFocus();
		}
		else
		{

		QSelOrden lQSelOrden(QIVOrdenes);
		if(lQSelOrden.ObtenSeleccion())
		{
		   lQSelOrden.ObtenOrden()->AnexaProductosALaOrden(lQCPractica.ObtenProductos());
		   QCtzaDispositivo->setFocus();
		}
		}

	}
}
void QVentasElectronica::S_AnexarALaOrden(ProductoE *pProducto)
{
		if(QIVOrdenes->count())
		if(QIVOrdenes->count()==1)
		{
		   ((QIconVOrdenE *)QIVOrdenes->firstItem())->ObtenOrdenElectronica()->AnexaProductoALaOrden(pProducto);
		   QCtzaDispositivo->setFocus();
		}
		else
		{

		QSelOrden lQSelOrden(QIVOrdenes);
		if(lQSelOrden.ObtenSeleccion())
		{
		   lQSelOrden.ObtenOrden()->AnexaProductoALaOrden(pProducto);
		   QCtzaDispositivo->setFocus();
		}
		}

}
void QVentasElectronica::S_SelOrden(QIconViewItem *pQIVOrden)
{
if(pQIVOrden)
{
QOrdenElectronica *lQOElectronica=((QIconVOrdenE *)pQIVOrden)->ObtenOrdenElectronica();
	lQOElectronica->ActivaOrden();
}
}
void QVentasElectronica::S_NuevaOrden()
{
QOrdenElectronica *lQOElectronica;
QIconVOrdenE *lQIVOrdenE;
char lchrArrIdOrden[20];
	ObtenIdentificadorOrden(lchrArrIdOrden);
QSelAlumno lQSelAlumno(SisDatCom,
		       chrPtrArgumentos);
	if(lQSelAlumno.Selecciono())
	{
	   SisReg3Escuela=lQSelAlumno.Escuela();
	   SiscomEscribeLog3Qt("El identificador de la Venta(%s)",
	   			lchrArrIdOrden);
	    CreaOrden(lchrArrIdOrden,ProductosE(),lQSelAlumno.Alumno());
	   
	}
}
void QVentasElectronica::ObtenIdentificadorOrden(char *pchrPtrIdOrden)
{
IdentificadorOrdenes lIdOrdenes;

		lIdOrdenes << new IdentificadorOrden("","GeneraIdentificador");

OpIdentificadorOrdenes lOpIdOrdenes(SisDatCom,&lIdOrdenes);
		lOpIdOrdenes.SiscomConsulta("ConsultaControladorOrdenes",
					    (QPtrList<SiscomInformacion> *)&lIdOrdenes);

 strcpy(pchrPtrIdOrden,lIdOrdenes.at(1)->SRegistrosPro2["IdOrden"]);

}
/* Viernes 18 de Enero del 2013
 * Con la integracion de la caja central 
 * se requiere que al modificar la orden desde la
 * caja se indique al servidor que la venta que se
 * realizara es de la caja y que se ha modificado
 * para lo que se pasa en estado de venta 4
 */
void QVentasElectronica::CreaOrdenModificaPorCajaCentral(
				const char *pchrPtrIdOrden,
				ProductosE pProductos,
				Persona *pPersona)
{
intModificaOrdenPorCajaCentral=1;
CreaOrden(pchrPtrIdOrden,
	  pProductos,
	  pPersona);
}
void QVentasElectronica::CreaOrden(const char *pchrPtrIdOrden,
				   ProductosE pProductos,
				   Persona *pPersona)
{
QOrdenElectronica *lQOElectronica;
QIconVOrdenE *lQIVOrdenE;
	lQOElectronica=new QOrdenElectronica(
				SisDatCom,
				chrPtrArgumentos,
				pPersona,
				chrPtrArgumentos[1],
				pchrPtrIdOrden,
				chrPtrArgumentos[0],
				QWParent);
		lQOElectronica->AnexaProductosALaOrden(pProductos);
		lQOElectronica->Escuela(SisReg3Escuela);
		lQOElectronica->ModificaOrdenPorCajaCentral(intModificaOrdenPorCajaCentral);
		connect(lQOElectronica,
			SIGNAL(SignalVendeOrden(QOrdenElectronica *)),
			SLOT(S_VendeOrden(QOrdenElectronica *)));
		connect(lQOElectronica,
			SIGNAL(SignalJuegosSeparados(int,ProductosE &)),
			SLOT(S_JuegosSeparados(int,ProductosE &)));
		connect(lQOElectronica,
			SIGNAL(SignalCancelarVenta(QOrdenElectronica *)),
			SLOT(S_CancelarVenta(QOrdenElectronica *)));
		lQIVOrdenE=new QIconVOrdenE(lQOElectronica,QIVOrdenes);
		QIVOrdenes->insertItem(lQIVOrdenE); 
		lQOElectronica->PonQIconAsociado(lQIVOrdenE); 
		QCtzaDispositivo->setFocus();

}
void QVentasElectronica::S_CancelarVenta(QOrdenElectronica *pQOElectronica)
{
	QuitaOrden(pQOElectronica);
}
void QVentasElectronica::S_JuegosSeparados(int pintNJuegos,
					   ProductosE &pProductos)
{
int lintContador;
char lchrArrIdOrden[20];
long llngIdOrden;

	
Persona *lPersona=ConsultaPersonaRFC(SisDatCom,"GENERAL");

	ObtenIdentificadorOrden(lchrArrIdOrden);
	llngIdOrden=atol(lchrArrIdOrden);
	for(lintContador=0;
	    lintContador<pintNJuegos;
	    lintContador++,
	    llngIdOrden++)
	{
	  sprintf(lchrArrIdOrden,"%ld",llngIdOrden); 
	  CreaOrden(lchrArrIdOrden,pProductos,lPersona);
	}
}

void QVentasElectronica::S_VendeOrden(QOrdenElectronica *pQOElectronica)
{
	QuitaOrden(pQOElectronica);
}

void QVentasElectronica::EliminaOrden(QOrdenElectronica *pQOElectronica)
{
QIconVOrdenE *lQIVOrdenE;
	for(lQIVOrdenE=(QIconVOrdenE *)QIVOrdenes->firstItem();
	    lQIVOrdenE;
	    lQIVOrdenE=(QIconVOrdenE *)lQIVOrdenE->nextItem())
	{
	     if(lQIVOrdenE->ObtenOrdenElectronica()==pQOElectronica)
	     {
	      delete lQIVOrdenE;
	      return;
	     }
	}
}
void QVentasElectronica::QuitaOrden(QOrdenElectronica *pQOElectronica)
{

	EliminaOrden(pQOElectronica);
	delete pQOElectronica;
}
void QVentasElectronica::EjecutaVenta(QIconVOrdenE *pQIVOrden)
{
QOrdenElectronica *lQOrden;

	if((lQOrden=pQIVOrden->ObtenOrdenElectronica()))
	 lQOrden->S_RealizaVenta();

}
void QVentasElectronica::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
