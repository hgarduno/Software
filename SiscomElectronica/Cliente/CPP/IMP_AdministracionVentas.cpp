#include <IMP_AdministracionVentas.h>

#include <QCtrlProductosSE.h>
#include <zSiscomElectronica.h>
#include <zProductoCotizar.h>
#include <zOrdenVenta.h>


#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>
#include <qpushbutton.h>
#include <qtextbrowser.h>
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qtable.h>

QAdministracionVentas *InstanciaAdministracionVentas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QAdministracionVentas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QAdministracionVentas::QAdministracionVentas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				AdministracionVentas(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zOrdVenta(0)
{
Conexion((zSiscomConexion *)gzSiscomConexion);
IniciaVariables();
ConectaSlots();
}

QAdministracionVentas::~QAdministracionVentas()
{

}
void QAdministracionVentas::Conexion(zSiscomConexion *pzSiscomConexion)
{
 zSisConexion=pzSiscomConexion;
}
void QAdministracionVentas::ConectaSlots()
{
connect(QLECantidad,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoAProductos()));
connect(QCtrProductos,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotSeleccionoProducto(zSiscomRegistro *)));
connect(QPBAnexarOrden,
	SIGNAL(clicked()),
	SLOT(SlotAnexarOrden()));
}
void QAdministracionVentas::SlotAnexarOrden()
{

    if(!zOrdVenta)
    IniciaOrden();
 CotizandoOrden();
  zSiscomQt3::Foco(QLECantidad);
}
void QAdministracionVentas::SlotFocoAProductos()
{
   zSiscomQt3::Foco(QCtrProductos);
}
void QAdministracionVentas::SlotSeleccionoProducto(zSiscomRegistro *pzSisRegProducto)
{
zSisRegProducto=pzSisRegProducto;
CotizandoProducto(pzSisRegProducto);
}
void QAdministracionVentas::IniciaVariables()
{
  QCtrProductos->Servidor(zSisConexion);  
  QCtrProductos->IniciaControl();
  zSiscomQt3::Foco(QLECantidad);
}

void QAdministracionVentas::CotizandoProducto(zSiscomRegistro *pzSisRegProducto)
{
zSiscomElectronica lzSiscomE(zSisConexion,"CotizandoProductos4");
zOrdCotProducto=new zOrdenVenta(0,chrPtrArgumentos[0]);
zProductoCotizar *lzProdCotizar=new zProductoCotizar(zSiscomQt3::Texto(QLECantidad),
						     0,
						     pzSisRegProducto);
	zOrdCotProducto->AgregaProducto(lzProdCotizar);
	lzSiscomE.CotizaOrden(zOrdCotProducto,0);
	MuestraCotizacionProducto(zOrdCotProducto);
	zProdCotizar=zOrdCotProducto->Producto(0);
	delete zOrdCotProducto;
zSiscomQt3::Foco(QPBAnexarOrden);
}
void QAdministracionVentas::MuestraCotizacionProducto(zOrdenVenta *pzOrdVenta)
{
QLCDPrecio->display(pzOrdVenta->Precio(0));
QLEExistencia->setText(pzOrdVenta->Existencia(0));
QLEExistenciaBodega->setText(pzOrdVenta->ExBodega(0));
QTEDescripcion->setText(pzOrdVenta->Descripcion(0));
}

void QAdministracionVentas::CotizaOrden()
{
zSiscomElectronica lzSiscomE(zSisConexion,"CotizandoProductos4");
      zOrdVenta->AgregaProducto(zProdCotizar); 
      lzSiscomE.CotizaOrden(zOrdVenta,0);
}

void QAdministracionVentas::MuestraOrdenCotizada(zOrdenVenta *pzOrdVenta)
{
char lchrArrProductos[16132];
int lintContador;
QLCNImporteOrden->display(pzOrdVenta->ImporteOrden());
QTOrden->setNumRows(pzOrdVenta->ProductosCotizados());
for(lintContador=0;
    lintContador<pzOrdVenta->ProductosCotizados();
    lintContador++)
{
  QTOrden->setText(lintContador,0,pzOrdVenta->Cantidad(lintContador));
  QTOrden->setText(lintContador,1,pzOrdVenta->Clave(lintContador));
  QTOrden->setText(lintContador,2,pzOrdVenta->Precio(lintContador));
  QTOrden->setText(lintContador,3,pzOrdVenta->Importe(lintContador));
}
}

void QAdministracionVentas::CotizandoOrden()
{
    CotizaOrden();
    MuestraOrdenCotizada(zOrdVenta);
}

void QAdministracionVentas::IniciaOrden()
{
     zOrdVenta=new zOrdenVenta(0,chrPtrArgumentos[0]);
}
