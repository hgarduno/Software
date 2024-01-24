#include <IMP_OrdenCompras.h>
#include <IMP_ProductosFaltantes4.h>
#include <ProductosE.h>
#include <CQSisOrdenCompra.h>
#include<SiscomDesarrollo3Qt++.h>


#include <zSiscomElectronica.h>
#include <zOrdenCompra.h>

#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

QOrdenCompras *InstanciaOrdenCompras(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QOrdenCompras((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QOrdenCompras::QOrdenCompras(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				OrdenCompras(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
IniciaVariables();
ConectaSlots();
}

QOrdenCompras::~QOrdenCompras()
{

}

void QOrdenCompras::ConectaSlots()
{
	connect(QMProductos,
		SIGNAL(SignalProducto(ProductoE *)),
		SLOT(S_Producto(ProductoE *)));
	connect(QTDatos,
		SIGNAL(doubleClicked(int,int,int,const QPoint &)),
		SLOT(S_SeleccionaProducto(int,int,int,const QPoint &)));
	connect(QPBProductosFaltantes,SIGNAL(clicked()),SLOT(SlotProductosFaltantes()));
}
void QOrdenCompras::SlotProductosFaltantes()
{
QProductosFaltantes4 lQProdFaltantes(chrPtrArgumentos);
}
void QOrdenCompras::S_SeleccionaProducto(int pintProducto,
					 int,
					 int,
					 const QPoint &)
{
SeleccionoProducto(pintProducto);
AgregaProductoALaOrden(pintProducto);
MuestraOrdenCompra();
SiscomPasaFocoControl(QLECProductos);
}
void QOrdenCompras::S_Producto(ProductoE *pProductoE)
{
    ProdSeleccionado=pProductoE;
    ComprasProducto();           
}
void QOrdenCompras::IniciaVariables()
{

	QLECProductos=SiscomColocaEditAlCombo(QCBProductos,"QLECProductos");
	QMProductos=new QManProductos(SisDatCom,
					chrPtrArgumentos[0],
					QCBProductos,
					QLECProductos,
					QTEDescripcion,
					this,
					"QMProductos");
	SiscomPasaFocoControl(QLECProductos);
}
void QOrdenCompras::ComprasProducto()
{
ConsultaComprasProducto();
MuestraComprasProducto();
}
void QOrdenCompras::ConsultaComprasProducto()
{
CQSComprasProducto.SiscomLimpia();
CQSisOrdenCompraOp lCQSOrdCompra(SisDatCom);
lCQSOrdCompra.ComprasProducto(chrPtrArgumentos[0],
			      (*ProdSeleccionado)["CveProducto"],
			      &CQSComprasProducto);
}
void QOrdenCompras::MuestraComprasProducto()
{
const char *lchrPtrCampos[]={"fecha",
			     "precio",
			     "preciosiniva",
			     "cantidad",
			     "numfactura",
			     "razonsocial",
			     "cveproveedor",
			     0};
const char *lchrPtrTransferencias[]={"sum","razonsocial",0};
QLEPrecioVenta->setText(CQSComprasProducto.PrecioVenta());
QLEExistencia->setText(CQSComprasProducto.Existencia());
QLEExBodega->setText(CQSComprasProducto.ExBodegas());
QLETransferencias->setText(CQSComprasProducto.Transferencias());
QLEComSemAnterior->setText(CQSComprasProducto.ComprasSemAnterior());
QLEVenSemAnterior->setText(CQSComprasProducto.VentasSemAnterior());
QLEComSemActual->setText(CQSComprasProducto.ComprasSemActual());
QLEVenSemActual->setText(CQSComprasProducto.VentasSemActual());
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
				       QTDatos,
				       CQSComprasProducto.HistoricoCompras());
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrTransferencias,
				       QTTransferencias,
				       CQSComprasProducto.TransferenciasExpendios());
SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
SiscomDesarrollo3Qt::AjustaColumnas(QTTransferencias);
}
void QOrdenCompras::SeleccionoProducto(int pintProducto)
{
QTDatos->selectRow(pintProducto);
}
void QOrdenCompras::AgregaProductoALaOrden(int pintDia)
{
     CQSOrdenCompra.Producto(CQSComprasProducto.DiaCompra(pintDia));
}
void QOrdenCompras::MuestraOrdenCompra()
{
const  char *lchrPtrCampos[]={"cveproducto",
 			"cveproveedor",
			"cantidad",
			"preciosiniva",
			"precio", 
			"razonsocial",
			0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
					QTOrdenCompra,
					CQSOrdenCompra.Productos());
}
