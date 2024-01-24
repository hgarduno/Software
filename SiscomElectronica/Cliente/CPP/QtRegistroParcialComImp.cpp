#include <QtRegistroParcialComImp.h>
#include <zCompraImportacion.h>
#include <zProductoImportado.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>

#include <qpushbutton.h>
QtRegistroParcialComImp::QtRegistroParcialComImp(QWidget *pQWParent,
						 const char *pchrPtrName,
						 WFlags pWFlags):
				  RegistroParcialComImp(pQWParent,pchrPtrName,pWFlags)
{


}
void QtRegistroParcialComImp::CompraImportacion(zCompraImportacion *pzComImportacion)
{
 zComImportacion=pzComImportacion;
}
void QtRegistroParcialComImp::ConectaSlots()
{
connect(QPBRegistroProdsFaltantes,SIGNAL(clicked()),SLOT(SlotRegistroProductos()));
}
void QtRegistroParcialComImp::SlotRegistroProductos()
{
}
zCompraImportacion *QtRegistroParcialComImp::CompraImportacion()
{
   return zComImportacion;
}
void QtRegistroParcialComImp::AgregaProducto(zProductoImportado *pzProdImportado)
{
   zProdsImportados << pzProdImportado; 
}
void QtRegistroParcialComImp::MuestraProductos()
{
const char *lchrPtrCampos[]={"CveProducto","CveProveedor",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,&zProdsImportados,QTProductos);
}
void QtRegistroParcialComImp::AgregandoProducto(zProductoImportado *pzProdImportado)
{
    AgregaProducto(pzProdImportado);
    MuestraProductos();
}
const zProductosImportados &QtRegistroParcialComImp::Productos()
{
     return zProdsImportados;
}
