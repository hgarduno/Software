#include <QtImpMantenimientoProductos.h>
#include <QCtrlProveedoresSS.h>
#include <QCtrlDepartamentosSS.h>
#include <QCtrlProductosSS.h>

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
#include <zDescuento.h>
#include <zPrecio.h>
#include <zProducto.h>

#include <qpushbutton.h>
#include <qlineedit.h>
QtImpMantenimientoProductos::QtImpMantenimientoProductos(QWidget *pQWParent,
					       const char *pchrPtrName):
					   MantenimientoProductos(pQWParent,pchrPtrName),
					   zCostoP(0),
					   zDescuentoP(0),
					   zPrecioP(0),
					   zPrecioForaneo(0)

{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpMantenimientoProductos::IniciaVariables()
{
QCtrProveedores->Servidor(zSisConexion);
QCtrDepartamentos->Servidor(zSisConexion);
QCtrProductos->Servidor(zSisConexion);
QCtrProveedores->IniciaControl();
QCtrDepartamentos->IniciaControl();

zSiscomQt3::Foco(QCtrProveedores);
}
void QtImpMantenimientoProductos::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpMantenimientoProductos::ConectaSlots()
{
	connect(QCtrProveedores,
		SIGNAL(SignalProveedor(zSiscomRegistro *)),
		SLOT(SlotProveedor(zSiscomRegistro *)));
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAModelo()));
	connect(QCtrDepartamentos,
		 SIGNAL(SignalDepartamento(zSiscomRegistro *)),
		 SLOT(SlotDepartamento(zSiscomRegistro *)));
	connect(QLECosto,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAIva()));
	connect(QLEModelo, SIGNAL(returnPressed()),
		SLOT(SlotFocoADepartamento()));
	connect(QLEPorUtilidadPrecio,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAPorUtilidadForaneo()));
	connect(QLEPrecioForaneo,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAPorUtilidadForaneo()));
	connect(QLEIva,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoADescuento1()));
	connect(QLEDescuento1,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoADescuento2()));
	connect(QLEDescuento2,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoADescuento3()));
	connect(QLEDescuento3,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoADescuento4()));
	connect(QLEDescuento4,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoAPrecio()));
	connect(QLEPrecio,
		SIGNAL(returnPressed()),
		SLOT(SlotUtilidad()));
	connect(QLEPrecioForaneo,
		SIGNAL(returnPressed()),
		SLOT(SlotGananciaPrecioForaneo()));
	connect(QPBRegistrar,
		 SIGNAL(clicked()),
		 SLOT(SlotRegistrar()));
	connect(QLEPrecioForaneo,
		SIGNAL(returnPressed()),
		SLOT(SlotFocoARegistrar()));
	connect(QCtrProductos,
		SIGNAL(SignalNuevoProducto(const QString &)),
		SLOT(SlotNuevoProducto(const QString &)));
	
}
void QtImpMantenimientoProductos::SlotNuevoProducto(const QString &pQStrProducto)
{
  LogSiscom("Es un nuevo producto");
       QStrNumProducto=pQStrProducto;
       zSiscomQt3::Foco(QLENombre);
}
void QtImpMantenimientoProductos::SlotFocoARegistrar()
{
	zSiscomQt3::Foco(QPBRegistrar);
}
void QtImpMantenimientoProductos::SlotRegistrar()
{
   Registrando();

}
void QtImpMantenimientoProductos::SlotGananciaPrecioForaneo()
{
char lchrArrGanancia[28];
if(zSiscomQt3::TextoValido(QLEPrecioForaneo))
{
CalculandoPorcentajeGanancia(zSiscomQt3::Texto(QLEPrecioForaneo),lchrArrGanancia);
QLEPorUtilidadForaneo->setText(lchrArrGanancia);
}
}
void QtImpMantenimientoProductos::SlotFocoAPrecio()
{
	zSiscomQt3::Foco(QLEPrecio);
}
void QtImpMantenimientoProductos::SlotUtilidad()
{
char lchrArrGanancia[28];
if(zSiscomQt3::TextoValido(QLEPrecio))
{
CalculandoPorcentajeGanancia(zSiscomQt3::Texto(QLEPrecio),lchrArrGanancia);
QLEPorUtilidadPrecio->setText(lchrArrGanancia);
zSiscomQt3::Foco(QLEPrecioForaneo);
}
}
void QtImpMantenimientoProductos::SlotFocoADescuento2()
{
	CalculandoCosto();
  zSiscomQt3::Foco(QLEDescuento2);
}
void QtImpMantenimientoProductos::SlotFocoADescuento3()
{

	CalculandoCosto();
  zSiscomQt3::Foco(QLEDescuento3);
}
void QtImpMantenimientoProductos::SlotFocoADescuento4()
{
	CalculandoCosto();
  zSiscomQt3::Foco(QLEDescuento4);
}
void QtImpMantenimientoProductos::SlotFocoADescuento1()
{
	CalculandoCosto();
	zSiscomQt3::Foco(QLEDescuento1);
}
void QtImpMantenimientoProductos::SlotFocoAPorUtilidadForaneo()
{
	zSiscomQt3::Foco(QLEPorUtilidadForaneo);
}
void QtImpMantenimientoProductos::SlotFocoAPrecioForaneo()
{
	zSiscomQt3::Foco(QLEPrecioForaneo);
}
void QtImpMantenimientoProductos::SlotFocoADepartamento()
{
	zSiscomQt3::Foco(QCtrDepartamentos);
}
void QtImpMantenimientoProductos::SlotFocoAPorUtilidad()
{
	zSiscomQt3::Foco(QLEPorUtilidadPrecio);
}
void QtImpMantenimientoProductos::SlotFocoAModelo()
{
	zSiscomQt3::Foco(QLEModelo);
}
void QtImpMantenimientoProductos::SlotFocoANombreProducto()
{
	zSiscomQt3::Foco(QLENombre);
}
void QtImpMantenimientoProductos::SlotProveedor(zSiscomRegistro *pzSisRegProveedor)
{
	zSisRegProveedor=pzSisRegProveedor;
	zSiscomQt3::Foco(QCtrProductos);
	ProductosProveedor();
	MuestraProveedor();
}
void QtImpMantenimientoProductos::SlotDepartamento(zSiscomRegistro *pzSisRegDepartamento)
{
	zSisRegDepartamento=pzSisRegDepartamento;
	zSiscomQt3::Foco(QLECosto);
}
void QtImpMantenimientoProductos::SlotFocoAIva()
{
	zSiscomQt3::Foco(QLEIva);
}
void QtImpMantenimientoProductos::MuestraProveedor()
{
char lchrArrProveedor[128];
sprintf(lchrArrProveedor,
	"%s-%s",
	(*zSisRegProveedor)["idempresa"],
	(*zSisRegProveedor)["razonsocial"]);
QLERazonSocial->setText(lchrArrProveedor);
}
void QtImpMantenimientoProductos::Precios()
{
   if(zSiscomQt3::TextoValido(QLEPorUtilidadPrecio) &&
      zSiscomQt3::TextoValido(QLEPorUtilidadForaneo))
   {
       if(zPrecioP)
       delete zPrecioP;
       if(zPrecioForaneo)
       delete zPrecioForaneo;
	zPrecioP=new zPrecio(0,
			     0,
			     zSiscomQt3::Texto(QLEPorUtilidadPrecio));

	zPrecioForaneo=new zPrecio(0,
				   0,
				   zSiscomQt3::Texto(QLEPorUtilidadForaneo));
   }

}
void QtImpMantenimientoProductos::Descuentos()
{
   if(zSiscomQt3::TextoValido(QLEDescuento1) ||
      zSiscomQt3::TextoValido(QLEDescuento2) ||
      zSiscomQt3::TextoValido(QLEDescuento3) ||
      zSiscomQt3::TextoValido(QLEDescuento4))
   {
	if(zDescuentoP)
	delete zDescuentoP;

	zDescuentoP=new zDescuento(0,
				    zSiscomQt3::Texto(QLEDescuento1),
				    zSiscomQt3::Texto(QLEDescuento2),
				    zSiscomQt3::Texto(QLEDescuento3),
				    zSiscomQt3::Texto(QLEDescuento4),
				    0);
					
   }

}
void QtImpMantenimientoProductos::Costo()
{
	if(!QLECosto->text().isEmpty()	&&
	   !QLECosto->text().isNull()   &&
	   !QLEIva->text().isEmpty()    &&
	   !QLEIva->text().isNull())
	 {
	     if(!zCostoP)
	     zCostoP=new zCosto(0,
	     			zSiscomQt3::Texto(QLECosto),
				0,
				0,
				zSiscomQt3::Texto(QLEIva),
				0);
	     else
	     {
		 delete zCostoP;
	     	zCostoP=new zCosto(0,
	     			zSiscomQt3::Texto(QLECosto),
				0,
				0,
				zSiscomQt3::Texto(QLEIva),
				0);
	     }
	 }
}
void QtImpMantenimientoProductos::CalculaCostoPrecio()
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"CalculaCostoProveedor");
lzOpeServiSNTE.CalculaCostoProveedor(zCostoP,zDescuentoP);
}
void QtImpMantenimientoProductos::MuestraCalculoCosto()
{
QLECostoNeto->setText(zCostoP->CostoNeto());
}
void QtImpMantenimientoProductos::CalculandoCosto()
{
 Costo();
 Descuentos();
 CalculaCostoPrecio();
 MuestraCalculoCosto();
}
void QtImpMantenimientoProductos::CalculaPrecios()
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"CalculaPrecios");
lzOpeServiSNTE.CalculaPrecios(zPrecioP,
			      zPrecioForaneo,
			      zCostoP);
}
void QtImpMantenimientoProductos::CalculandoPrecios()
{
  Precios();
  CalculaPrecios();
  MostrandoPrecios();
}
void QtImpMantenimientoProductos::MostrandoPrecios()
{
  QLEPrecio->setText(zPrecioP->Precio());
  QLEPrecioForaneo->setText(zPrecioForaneo->Precio());
}
void QtImpMantenimientoProductos::CalculandoPorcentajeGanancia(const char *pchrPtrPrecio,
								char *pchrPtrGanancia)
{
  CalculaPorcentajeGanancia(pchrPtrPrecio,pchrPtrGanancia);
}
void QtImpMantenimientoProductos::CalculaPorcentajeGanancia(const char *pchrPtrPrecio,
							    char *pchrPtrGanancia)
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"CalculaPorcentajeGanancia");
lzOpeServiSNTE.CalculaPorcentajeGanancia(zCostoP,
					pchrPtrPrecio,
					pchrPtrGanancia);
}
void QtImpMantenimientoProductos::Registrando()
{
  Registra();
  QCtrProductos->ReIniciaControl();

}
void QtImpMantenimientoProductos::Registra()
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"RegistraProducto");
lzOpeServiSNTE.RegistraProducto(Producto());

}
zProducto *QtImpMantenimientoProductos::Producto()
{
zProducto *lzProducto;

lzProducto=new zProducto(zSisRegProveedor,
			 zSisRegDepartamento,
			 0,
			 zSiscomQt3::Texto(QLENombre),
			 zSiscomQt3::Texto(QLEModelo),
			 (const char *)QStrNumProducto,
			 zSiscomQt3::Texto(QLEPrecio),
			 zDescuentoP,
			 zCostoP);
SiscomRegistroLog2(zDescuentoP);
return lzProducto;
}
void QtImpMantenimientoProductos::ProductosProveedor()
{
   QCtrProductos->Proveedor(zSisRegProveedor);
   QCtrProductos->IniciaControl();
}
