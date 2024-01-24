#include <QtCompraContenedor2.h>


#include <IMP_SeleccionaCompraImp.h>

#include <zProductoImportado.h>
#include <zProductosImportados.h>
#include <zContenedor.h>
#include <zSiscomElectronica.h>

#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>


#include <qpushbutton.h>
#include <qtable.h>
QtCompraContenedor2::QtCompraContenedor2(char **pchrPtrArgumentos,
					 zSiscomConexion *pzSisConexion,
					 QWidget *pQWParent,
					 const char *pchrPtrName,
					 WFlags pWFlags):
					 CompraContenedor2(pQWParent,
					 		   pchrPtrName,
							   pWFlags),
					chrPtrArgumentos(pchrPtrArgumentos),
					zSisConexion(pzSisConexion)
{
  IniciaVariables();
}
void QtCompraContenedor2::ConectaSlots()
{
connect(QPBAgregaFactura,SIGNAL(clicked()),SLOT(SlotAgregaFactura()));
}
void QtCompraContenedor2::SlotAgregaFactura()
{
 	zComImportacion.CostoEnvio(zSiscomQt3::Texto(QLECostoEnvio));
	zComImportacion.CostoDolar(zSiscomQt3::Texto(QLECostoDolar));
	zComImportacion.CostoAdministrativo(zSiscomQt3::Texto(QLECostoAdministrativo));
	CargandoCompra();
}
void QtCompraContenedor2::ActualizaNumeroPartidas()
{
char lchrArrNumPartidas[120];
sprintf(lchrArrNumPartidas, "%d",zComImportacion.Productos()->NNodos());
zComImportacion.NumPartidas(lchrArrNumPartidas);
}
void QtCompraContenedor2::IniciaVariables()
{
  IniciaContenedor();
  ConectaSlots();
}
void QtCompraContenedor2::CargandoCompra()
{
QSeleccionaCompraImp lQSelComImp(chrPtrArgumentos);
if(lQSelComImp.Aceptar())
ConsultandoCompra(lQSelComImp.CompraImportacion()->IdCompraImportacion());
}
void QtCompraContenedor2::ConsultandoCompra(const char *pchrPtrIdCompra)
{
char lchrArrMensaje[256];
zCompraImportacion *lzComImportacion;
  if(!ConsultaCompra(pchrPtrIdCompra,lchrArrMensaje,&lzComImportacion))
  {
   	AgregandoFacturaContenedor(lzComImportacion,&zComImportacion);	
	ActualizaNumeroPartidas();
  	Calculando();
  }
}
void QtCompraContenedor2::AgregaFacturaContenedor(zCompraImportacion *pzComImportacion)
{
zSiscomElectronica lzSisElectronica(zSisConexion,"AgregaFacturaContenedor");
lzSisElectronica.AgregaFacturaContenedor(Contenedor(),pzComImportacion);
}
int QtCompraContenedor2::ConsultaCompra(const char *pchrPtrIdCompra,
					char *pchrPtrMensaje,
					zCompraImportacion **pzComImportacion)
{
*pzComImportacion=new zCompraImportacion;
zSiscomElectronica lzSisElectronica(zSisConexion,"ConsultaCompraImportacion");
return lzSisElectronica.ConsultaCompraImportacion(pchrPtrIdCompra,
                                                  *pzComImportacion,
                                                  pchrPtrMensaje);
}
void QtCompraContenedor2::MuestraProductos()
{
int lintContadorI;
zProductoImportado *lzProdImportado;
if(zComImportacion.Productos())
{
QTProductos->setNumRows(zComImportacion.Productos()->NNodos());
for(lzProdImportado=(zProductoImportado *)zComImportacion.Productos()->Primer(),
    lintContadorI=0;
    lzProdImportado;
    lzProdImportado=(zProductoImportado *)zComImportacion.Productos()->Siguiente(),
    lintContadorI++)
{
  QTProductos->setText(lintContadorI,0,lzProdImportado->Clave());
  QTProductos->setText(lintContadorI,1,lzProdImportado->CveProveedor());
  QTProductos->setText(lintContadorI,2,lzProdImportado->Cantidad());
  QTProductos->setText(lintContadorI,3,lzProdImportado->Peso());
  QTProductos->setText(lintContadorI,4,lzProdImportado->PesoTotal());
  QTProductos->setText(lintContadorI,5,lzProdImportado->CostoEnvio());
  QTProductos->setText(lintContadorI,6,lzProdImportado->CostoUnitarioDolares());
  QTProductos->setText(lintContadorI,7,lzProdImportado->PrecioMasCostoEnvio());
  QTProductos->setText(lintContadorI,8,lzProdImportado->CostoFinalPesos());
  QTProductos->setText(lintContadorI,9,lzProdImportado->CostoFinalMasCosAdm());
  QTProductos->setText(lintContadorI,10,lzProdImportado->CostoPartida());
}
zSiscomQt3::AjustaColumnasTabla(QTProductos);
}
}
int QtCompraContenedor2::EnviaDatos(char *pchrPtrMensaje)
{
zSiscomElectronica lzSisElectronica(zSisConexion,"CompraImportacion");
return lzSisElectronica.CalculaProductoImportacion(&zComImportacion,pchrPtrMensaje); 
}
void QtCompraContenedor2::Calculando()
{
char lchrArrMensaje[128];
  if(zComImportacion.Productos())
  {
  if(EnviaDatos(lchrArrMensaje))
  MostrandoCalculos();
  else
  { 

  }
  }

}
void QtCompraContenedor2::MostrandoCalculos()
{
 MuestraProductos(); 
}
zContenedor *QtCompraContenedor2::Contenedor()
{
   return zConteC;
}
void QtCompraContenedor2::IniciaContenedor()
{
  zConteC=new zContenedor;
}
void QtCompraContenedor2::AgregandoFacturaContenedor(zCompraImportacion *pzComImportacion,
						     zCompraImportacion *pzComImpC)
{
   Contenedor()->AgregaCompra(pzComImportacion); 
   AgregaFacturaContenedor(pzComImpC);       

}
