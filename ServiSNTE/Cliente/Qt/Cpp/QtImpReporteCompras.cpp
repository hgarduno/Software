#include <QtImpReporteCompras.h>
#include <QtImpCapturaPrecioIva.h>
#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>


#include <zOperacionesServiSNTE.h>
#include <zCosto.h>

#include <qlineedit.h>
#include <qtable.h>
QtImpReporteCompras::QtImpReporteCompras(QWidget *pQWParent,
					       const char *pchrPtrName):
					   ReporteCompras(pQWParent,pchrPtrName)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpReporteCompras::IniciaVariables()
{
zSiscomQt3::Foco(QLERangoFechas);
}
void QtImpReporteCompras::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpReporteCompras::ConectaSlots()
{
connect(QLERangoFechas,
	SIGNAL(returnPressed()),
	SLOT(SlotRangoFecha()));
connect(QTCompras,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionaCompra(int,int,int,const QPoint &)));
connect(QTCompras,
	SIGNAL(currentChanged(int,int)),
	SLOT(SlotSeleecionaProducto(int,int)));
connect(QTDetalleCompras,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionaProducto(int,int,int,const QPoint &)));

}
void QtImpReporteCompras::SlotSeleccionaProducto(int pintNProducto,
						 int)
{
}
void QtImpReporteCompras::SlotSeleccionaProducto(int pintNProducto,
						  int,
						  int,
						  const QPoint &)
{
QtImpCapturaPrecioIva lQtImpCapturaC;
zCosto *lzCosto;
zSiscomRegistro *lzSisRegistro=(*zSisRegsProductos)[pintNProducto];
QString lQSCantidad,lQSIva;
if(lQtImpCapturaC.Aceptar())
{ 
       lQtImpCapturaC.PrecioIva(&lQSCantidad,&lQSIva);
      lzCosto=Costo(lQSCantidad,lQSIva);
      CalculandoCosto(lzCosto);
      RegistrandoPrecioCompra(lzSisRegistro,lzCosto);
      SlotSeleccionaCompra(intNumeroCompra,0,0,QPoint());
}
}
void QtImpReporteCompras::SlotSeleccionaCompra(int pintNCompra,
						int,
						int,
						const QPoint &)
{
    zSisRegCompra=(*zSisRegsCompras)[pintNCompra];	
    ConsultandoDetalleCompra(zSisRegCompra);
    intNumeroCompra=pintNCompra;

}
void QtImpReporteCompras::SlotRangoFecha()
{
   Consultando();
}
void QtImpReporteCompras::Consultando()
{
  Consulta();
  Muestra();
}
void QtImpReporteCompras::Consulta()
{
zOperacionesServiSNTE lzSisOpeServiSNTE(zSisConexion,"ReporteCompras");
zSisRegsCompras=lzSisOpeServiSNTE.ReporteCompras((const char *)QLERangoFechas->text());
}
void QtImpReporteCompras::Muestra()
{
const char *lchrPtrCampos[]={"razonsocial","nombre","conceptos","seriefactura","fecha","folio",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,zSisRegsCompras,QTCompras);
}
zSiscomRegistros *QtImpReporteCompras::ConsultaDetalleCompra(zSiscomRegistro *pzSisRegCompra)
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"ReporteDetalleCompra");
return lzOpeServiSNTE.ReporteComprasDetalle(pzSisRegCompra);
}
void QtImpReporteCompras::MostrandoDetalleCompra()
{
const char *lchrPtrCampos[]={"nombreproducto",
			"modelo",
			"serie",
			"cantidad",
			"preciocompra",
			"ivacompra",
			"total",
			0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,zSisRegsProductos,QTDetalleCompras);
}
void QtImpReporteCompras::ConsultandoDetalleCompra(zSiscomRegistro *pzSisRegCompra)
{
if((zSisRegsProductos=ConsultaDetalleCompra(pzSisRegCompra)))
 MostrandoDetalleCompra();
}
void QtImpReporteCompras::CalculandoCosto(zCosto *pzCosto)
{
/*
 zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"CalculaCostoCantidad");
 lzOpServiSNTE.CalculaCostos(pzCosto);
 */
}
zCosto *QtImpReporteCompras::Costo(const QString &pQSCantidad,
				     const QString &pQSIva)
{
   return new zCosto(0,
   		     strdup((const char *)pQSCantidad),
		     0,
		     0,
		     strdup((const char *)pQSIva),
		     0);
}
void QtImpReporteCompras::RegistrandoPrecioCompra(zSiscomRegistro *pzSisRegProducto,
						  zCosto *pzCosto)
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"RegistraPrecioCompra");
zSiscomRegistro *lzSisRegActCosto=new zSiscomRegistro;
(*lzSisRegActCosto) 			<< 
new zSiscomCampo("IdCompra") 		<<
new zSiscomCampo("IdProducto")  	<<
new zSiscomCampo("Costo");

lzSisRegActCosto->ActualizaCampo("IdCompra",(*zSisRegCompra)["idcompra"]);
lzSisRegActCosto->ActualizaCampo("IdProducto",(*pzSisRegProducto)["idproducto"]);
lzSisRegActCosto->AsociadoAlCampo("Costo",pzCosto);
lzOpeServiSNTE.ActualizaPrecioCompra(lzSisRegActCosto);
}
