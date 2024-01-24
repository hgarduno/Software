#include <IMP_CapturaNoCotizacion.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include<SISCOMComunicaciones++.h>
#include <ControladorOrdenes.h>
QCapturaNoCotizacion::QCapturaNoCotizacion(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    const char *pchrPtrTipo,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaNoCotizacion(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				chrPtrTipo(pchrPtrTipo),
				intBoton(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaNoCotizacion::~QCapturaNoCotizacion()
{

}
int QCapturaNoCotizacion::ObtenBotonPulsado()
{
	return intBoton;
}
void QCapturaNoCotizacion::ConectaSlots()
{
	connect(QLENoCtizacion,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAceptar()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Aceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(S_Cancelar()));

}
void QCapturaNoCotizacion::S_Cancelar()
{
	intBoton=1;
	done(1);
}
void QCapturaNoCotizacion::S_PasaFocoAceptar()
{
	SiscomPasaFocoControl(QPBAceptar);
}
void QCapturaNoCotizacion::S_Aceptar()
{
	if(!strcmp(chrPtrTipo,"Cotizacion"))
	 Cotizacion();
	if(!strcmp(chrPtrTipo,"OrdenVendida"))
	Orden();

	done(1);

}
void QCapturaNoCotizacion::Cotizacion()
{
IdentificadorOrdenes lIdOrdenes;

	lIdOrdenes << 
	new IdentificadorOrden("","ProductosCotizacion") <<
	new IdentificadorOrden("",
				SiscomObtenInformacionDelEdit(QLENoCtizacion));
				
OpProductosOrdenes lOpProdOrdenes(SisDatCom,
				  &lIdOrdenes);

	lOpProdOrdenes.SiscomConsulta("ConsultaControladorOrdenes",
				      (QPtrList<SiscomInformacion> *)&PProductos);
}
void QCapturaNoCotizacion::Orden()
{
IdentificadorOrdenes lIdOrdenes;

	lIdOrdenes << 
	new IdentificadorOrden("","ProductosOrdenVendida") <<
	new IdentificadorOrden("",
				SiscomObtenInformacionDelEdit(QLENoCtizacion));
				
OpProductosOrdenes lOpProdOrdenes(SisDatCom,
				  &lIdOrdenes);

	lOpProdOrdenes.SiscomConsulta("ConsultaControladorOrdenes",
				      (QPtrList<SiscomInformacion> *)&PProductos);
}
void QCapturaNoCotizacion::IniciaVariables()
{
 SiscomPasaFocoControl(QLENoCtizacion);
}
void QCapturaNoCotizacion::ObtenProductosCotizacion(ProductosE *pProductos)
{
	*pProductos=PProductos;
}
void QCapturaNoCotizacion::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
