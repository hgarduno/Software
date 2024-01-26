#include <QtImpCapturaProductos.h>
#include <QtImpSeleccionaProducto.h>
#include <QtImpCapturaPrecioIva.h>
#include <QtImpCapturaCantidad.h>
#include <QtImpCapturaDescuentos.h>

#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>

#include <QCtrlProveedoresSS.h>
#include <QCtrlDepartamentosSS.h>

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
#include <zProducto.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtable.h>
QtImpCapturaProductos::QtImpCapturaProductos(QWidget *pQWParent,
				     const char *pchrPtrName):
				     CapturaProductos(pQWParent,pchrPtrName),
				     intCreando(0),
				     intConsultando(0),
				     zDescuentoP(0)
{
 Conexion((zSiscomConexion *)gzSiscomConexion);
 ConectaSlots();
 IniciaControles();
}

void QtImpCapturaProductos::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}

void QtImpCapturaProductos::ConectaSlots()
{
   connect(QPBCCBruto,
   	   SIGNAL(clicked()),
	   SLOT(SlotCCBruto()));
   connect(QPBCPGeneral,
   	   SIGNAL(clicked()),
	   SLOT(SlotCPGeneral()));
   connect(QPBCPForaneo,
   	   SIGNAL(clicked()),
	   SLOT(SlotCPForaneo()));
   connect(QPBCDescuento,
   	   SIGNAL(clicked()),
	   SLOT(SlotCDescuento()));
   connect(QPBActualizar,
   	   SIGNAL(clicked()),
	   SLOT(SlotAgregarPrecios()));
   connect(QPBCrear,
   	   SIGNAL(clicked()),
	   SLOT(SlotCrear()));
   connect(QPBConsultar,
   	   SIGNAL(clicked()),
	   SLOT(SlotConsulta()));
}

void QtImpCapturaProductos::SlotCrear()
{
 if(!intCreando)
 Creando();
 else
 Creado();

}
void QtImpCapturaProductos::SlotAgregarPrecios()
{
 RegistraPrecios();
 //LimpiandoInterfaz();
 //ConsultandoProducto();
}
void QtImpCapturaProductos::SlotCCBruto()
{
QtImpCapturaPrecioIva lQtImpCapturaC;
const char *lchrPtrPrecioBruto[]={"costobruto","costoneto","iva","fecha",0};

QString lQSCantidad,lQSIva;
if(lQtImpCapturaC.Aceptar())
{ 
       lQtImpCapturaC.PrecioIva(&lQSCantidad,&lQSIva);
	zCostoP=Costo(lQSCantidad,lQSIva);
	CalculandoCostoProveedor(zCostoP);
        AnexaCosto(lchrPtrPrecioBruto,QTCostoBruto,zCostoP,&zCostosBruto);
}
}
void QtImpCapturaProductos::SlotCPGeneral()
{
QtImpCapturaCantidad lQtImpCapturaC;
const char *lchrPtrPrecioGeneral[]={"preciogeneral","fecha",0};
zCosto *lzCosto;
zSiscomRegistro *lzSisRegistro;
QString lQSCantidad;
if(lQtImpCapturaC.Aceptar())
{ 
      lQtImpCapturaC.Cantidad(&lQSCantidad);
      lzCosto=Costo(lQSCantidad);
      lzSisRegistro=PrecioGeneral(lzCosto);
      AnexaCosto(lchrPtrPrecioGeneral,QTPrecioGeneral,lzSisRegistro,&zCostosGeneral);
}
}
void QtImpCapturaProductos::SlotCPForaneo()
{
const char *lchrPtrPrecioForaneo[]={"precioforaneo","fecha",0};
QtImpCapturaCantidad lQtImpCapturaC;
zCosto *lzCosto;
zSiscomRegistro *lzSisRegistro;
QString lQSCantidad;
if(lQtImpCapturaC.Aceptar())
{ 
       lQtImpCapturaC.Cantidad(&lQSCantidad);
      lzCosto=Costo(lQSCantidad);
      lzSisRegistro=PrecioForaneo(lzCosto);
      AnexaCosto(lchrPtrPrecioForaneo,QTPrecioForaneo,lzSisRegistro,&zCostosForaneo);
}
}
void QtImpCapturaProductos::SlotCDescuento()
{
QtImpCapturaDescuentos lQtImpCaptDescuentos;
zDescuentoP=lQtImpCaptDescuentos.Descuento();
CalculandoCostoProveedor(zCostoP);
zDescuentosDesc<<zDescuentoP;
MuestraDescuentos();
}
void QtImpCapturaProductos::SlotProveedorCrear(zSiscomRegistro *pzSisRegistro)
{
      zSisProveedor=pzSisRegistro;
      zSiscomQt3::Foco(QLENumeroProducto);
}
void QtImpCapturaProductos::SlotProveedor(zSiscomRegistro *pzSisRegistro)
{
   zSisProveedor=pzSisRegistro;
   QPBConsultar->setEnabled(true);
   zSiscomQt3::Foco(QPBConsultar);
}
void QtImpCapturaProductos::SlotConsulta()
{
  LimpiandoInterfaz();
  Consultando();
}
void QtImpCapturaProductos::IniciaControles()
{
 QCtrProveedores->Servidor(zSisConexion);
 QCtrProveedores->IniciaControl();
 QCtrDepartamentos->Servidor(zSisConexion);
 QCtrDepartamentos->IniciaControl();
}
void QtImpCapturaProductos::SeleccionaProducto()
{
QtImpSeleccionaProducto lQtImpSelProducto(zSisConexion,zSisProveedor);
if(lQtImpSelProducto.Aceptar())
{
 zSisProducto=lQtImpSelProducto.Producto();
 QLENombre->setText((const char *)(*zSisProducto)["nombreproducto"]);
 QLENumeroProducto->setText((const char *)(*zSisProducto)["numproducto"]);
 QLEModelo->setText((const char *)(*zSisProducto)["modelo"]);
}
}
void QtImpCapturaProductos::ConsultandoProducto()
{
  if(ConsultaProducto())
  MuestraProducto();
}
int QtImpCapturaProductos::ConsultaProducto()
{
 zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"PreciosDescuentosProducto");
return lzOpServiSNTE.PreciosDescuentosProducto(zSisProducto,
 					 &zCostosBruto,
					 &zCostosGeneral,
					 &zCostosForaneo,
					 &zDescuentosDesc);
}
void QtImpCapturaProductos::MuestraProducto()
{
 MuestraCostos();
}

void QtImpCapturaProductos::AnexaCosto(const char *pchrPtrCampos[],
				       QTable *pQTabla,
				       zSiscomRegistro *pzSisRegistro,
				       zCostos *pzCostos)
{

  (*pzCostos) << pzSisRegistro;
  zSiscomQt3::LlenaTabla(pchrPtrCampos,pzCostos,pQTabla);
}

zCosto *QtImpCapturaProductos::Costo(const QString &pQSCantidad)
{
const char *lchrPtrCantidad=strdup((const char *)pQSCantidad);
   return new zCosto(0,
   			lchrPtrCantidad,
			lchrPtrCantidad,
		     0,
		     0,
		     0);
}
zCosto *QtImpCapturaProductos::Costo(const QString &pQSCantidad,
				     const QString &pQSIva)
{
   return new zCosto(0,
   		     strdup((const char *)pQSCantidad),
		     0,
		     0,
		     strdup((const char *)pQSIva),
		     0);
}

void QtImpCapturaProductos::RegistraPrecios()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"RegistraPrecio");
zProdPrecios=new zProducto(zSisProducto);
/*
zProdPrecios->AgregaCostos(&zCostosBruto,&zCostosGeneral,&zCostosForaneo); 
*/
lzOpServiSNTE.RegistraPrecios(zProdPrecios);
}
void QtImpCapturaProductos::ConectaSlotsCrear()
{
   connect(QCtrProveedores,
   	   SIGNAL(SignalProveedor(zSiscomRegistro *)),
	   SLOT(SlotProveedorCrear(zSiscomRegistro *)));
   connect(QLENumeroProducto,
   	   SIGNAL(returnPressed()),
	   SLOT(SlotFocoANombre()));
   connect(QLENombre,
   	   SIGNAL(returnPressed()),
	   SLOT(SlotFocoModelo()));
   connect(QLEModelo,
   	   SIGNAL(returnPressed()),
	   SLOT(SlotFocoDepartamento()));
   connect(QCtrDepartamentos,
   	   SIGNAL(SignalDepartamento(zSiscomRegistro *)),
	   SLOT(SlotDepartamentoCrear(zSiscomRegistro *)));
}
void QtImpCapturaProductos::ConectaSlotsConsultar()
{
   connect(QCtrProveedores,
   	   SIGNAL(SignalProveedor(zSiscomRegistro *)),
	   SLOT(SlotProveedor(zSiscomRegistro *)));

}
void QtImpCapturaProductos::SlotFocoANombre()
{
	zSiscomQt3::Foco(QLENombre);
}
void QtImpCapturaProductos::SlotDepartamentoCrear(zSiscomRegistro *pzSisRegDepartamento)
{
   zSisDepartamento=pzSisRegDepartamento;
   zSiscomQt3::Foco(QPBCrear);

}
void QtImpCapturaProductos::SlotFocoModelo()
{
  zSiscomQt3::Foco(QLEModelo);
}
void QtImpCapturaProductos::SlotFocoDepartamento()
{
  zSiscomQt3::Foco(QCtrDepartamentos);
}
void QtImpCapturaProductos::ActivaControlesCrea()
{
   QPBConsultar->setEnabled(false);
   QCtrProveedores->setEnabled(true);
   zSiscomQt3::Foco(QCtrProveedores);
}
void QtImpCapturaProductos::Creando()
{
 ActivaControlesCrea();
 ConectaSlotsCrear();
 intCreando=1;
}
void QtImpCapturaProductos::Creado()
{
zProducto *lzProducto;
LogSiscom("Creando El producto en el sistema, se registra");
if((lzProducto=CreaProducto()))
{
RegistraProducto(lzProducto);
ReIniciaCaptura();
}
}
void QtImpCapturaProductos::RegistraProducto(zProducto *pzProducto)
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"RegistraProducto");
lzOpServiSNTE.RegistraProducto(pzProducto);
}

zProducto *QtImpCapturaProductos::CreaProducto()
{
  return new zProducto(zSisProveedor,
  		       zSisDepartamento,
  		       0,
		       zSiscomQt3::Texto(QLENombre),
		       zSiscomQt3::Texto(QLEModelo),
		       zSiscomQt3::Texto(QLENumeroProducto));
}
void QtImpCapturaProductos::ReIniciaCaptura()
{
  QCtrProveedores->setEnabled(false);
  QPBCrear->setEnabled(true);
  QPBConsultar->setEnabled(true);
  intCreando=0;
}
void QtImpCapturaProductos::ControlesParaConsultar()
{
    QCtrProveedores->setEnabled(true);
    zSiscomQt3::Foco(QCtrProveedores);
    QPBCrear->setEnabled(false);

}
void QtImpCapturaProductos::Consultando()
{
   if(!intConsultando)
   {
   ConectaSlotsConsultar();
   ControlesParaConsultar();
   intConsultando=1;
   }
   else
   {
      SeleccionaProducto(); 
      ConsultandoProducto();
      QPBActualizar->setEnabled(false);
      QPBActualizar->setEnabled(true);
   }
}

void QtImpCapturaProductos::MuestraCostos(const char *pchrPtrCampos[],
					  QTable *pQTabla,
					  zCostos *pzCostos)
{
  zSiscomQt3::LlenaTabla(pchrPtrCampos,pzCostos,pQTabla);
}
void QtImpCapturaProductos::MuestraCostos()
{
const char *lchrPtrPrecioBruto[]={"costobruto","costoneto","iva","fecha",0};
const char *lchrPtrPrecioGeneral[]={"preciogeneral","fecha",0};
const char *lchrPtrPrecioForaneo[]={"precioforaneo","fecha",0};
   MuestraCostos(lchrPtrPrecioBruto,QTCostoBruto,&zCostosBruto);
   MuestraCostos(lchrPtrPrecioGeneral,QTPrecioGeneral,&zCostosGeneral);
   MuestraCostos(lchrPtrPrecioForaneo,QTPrecioForaneo,&zCostosForaneo);
}
zSiscomRegistro *QtImpCapturaProductos::PrecioGeneral(zCosto *pzCosto)
{
zSiscomRegistro *lzSisRegistro=new zSiscomRegistro;
 (*lzSisRegistro) << 
 new zSiscomCampo("idpreciogeneral")				<<
 new zSiscomCampo("preciogeneral",(*pzCosto)["costoneto"]) 	<<
 new zSiscomCampo("preciosiniva") 		<<
 new zSiscomCampo("iva")			<<
 new zSiscomCampo("fecha")			<<
 new zSiscomCampo("idproducto",(*zSisProducto)["idproducto"]);

 return lzSisRegistro;
}


zSiscomRegistro *QtImpCapturaProductos::PrecioForaneo(zCosto *pzCosto)
{
zSiscomRegistro *lzSisRegistro=new zSiscomRegistro;
 (*lzSisRegistro) << 
 new zSiscomCampo("idprecioforaneo")			 	<<
 new zSiscomCampo("precioforaneo",(*pzCosto)["costoneto"]) 	<<
 new zSiscomCampo("preciosiniva") 		<<
 new zSiscomCampo("iva")			<<
 new zSiscomCampo("fecha",(*pzCosto)["Fecha"])			<<
 new zSiscomCampo("idproducto",(*zSisProducto)["idproducto"]);
 return lzSisRegistro;
}
zSiscomRegistro *QtImpCapturaProductos::CostoBruto(zCosto *pzCosto)
{
zSiscomRegistro *lzSisRegistro=new zSiscomRegistro;
 (*lzSisRegistro) << 
 new zSiscomCampo("idcostobruto") 	<<
 new zSiscomCampo("costobruto",(*pzCosto)["CostoMIva"]) 	<<
 new zSiscomCampo("costoneto",(*pzCosto)["Costo"]) 		<<
 new zSiscomCampo("iva",(*pzCosto)["CostoIva"])			<<
 new zSiscomCampo("fecha",(*pzCosto)["Fecha"])			<<
 new zSiscomCampo("idproducto",(*zSisProducto)["idproducto"]);
 return lzSisRegistro;
}


void QtImpCapturaProductos::LimpiandoInterfaz()
{
zSiscomQt3::LimpiaTabla(QTCostoBruto);
zSiscomQt3::LimpiaTabla(QTPrecioGeneral);
zSiscomQt3::LimpiaTabla(QTPrecioForaneo);

zCostosBruto.Libera();
zCostosGeneral.Libera();
zCostosForaneo.Libera();
}

void QtImpCapturaProductos::CalculandoCostoProveedor(zCosto *pzCosto)
{
zOperacionesServiSNTE lzOpeServiSNTE(zSisConexion,"CalculaCostoProveedor");
lzOpeServiSNTE.CalculaCostoProveedor(pzCosto,zDescuentoP);
}
void QtImpCapturaProductos::MuestraDescuentos()
{
const char *lchrPtrCampos[]={"Fecha","D1","D2","D3","D4",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,&zDescuentosDesc,QTDescuento);
}
