#include <IMP_ManejadorKits.h>
#include <IMP_RegistraKit.h>
#include <QCtrlTiposProductoSE.h>

#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include<SiscomDesarrollo3Qt++.h>
#include <ProductosE.h>
QManejadorKits *InstanciaManejadorKits(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QManejadorKits((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QManejadorKits::QManejadorKits(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ManejadorKits(pQWParent,pchrPtrName,pWFlags),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QManejadorKits::~QManejadorKits()
{

}

void QManejadorKits::ConectaSlots()
{

	connect(QMProductos,
		SIGNAL(SignalProducto(ProductoE *)),
		SLOT(S_Producto(ProductoE *)));
	connect(QPBRegistraKit,
		SIGNAL(clicked()),
		SLOT(S_RegistraKit()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(S_FocoAAnexar()));
	connect(QPBRegistraProductos,
		SIGNAL(clicked()),
		SLOT(S_RegistraProductos()));
	connect(QCtrTiposProducto,
		SIGNAL(SignalSelecciono(zSiscomRegistro *)),
		SLOT(S_SeleccionoTipoProducto(zSiscomRegistro *)));
	connect(QTProductos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(S_Producto(int,int,int,const QPoint &)));

	connect(QLECProductos,SIGNAL(returnPressed()),SLOT(S_FocoACantidad()));
	connect(QPBEliminaProducto,SIGNAL(clicked()),SLOT(S_EliminaProducto()));
	
}
void QManejadorKits::S_EliminaProducto()
{
int lintContador;
for(lintContador=0;lintContador<QTProductos->numRows();lintContador++)
if(QTProductos->isRowSelected(lintContador))
 CQSProductoPorTipo.EliminaProducto(lintContador);
MuestraProductosDelProducto();
}
void QManejadorKits::S_FocoACantidad()
{
    SiscomPasaFocoControl(QLECantidad);
}
void QManejadorKits::S_CambiaCantidad(int,int,int,const QPoint &)
{

}
void QManejadorKits::S_Producto(int pintNProducto,int,int,const QPoint &)
{
   QTProductos->selectRow(pintNProducto);  
}
void QManejadorKits::S_SeleccionoTipoProducto(zSiscomRegistro *pzSisRegTipoProducto)
{
  zSisRegTipoProducto=pzSisRegTipoProducto;
  QPBRegistraKit->setEnabled(true);
  zSiscomQt3::Foco(QPBRegistraKit);
}
void QManejadorKits::S_RegistraProductos()
{
RegistraProductos();
ReIniciandoRegistro();
}
void QManejadorKits::S_FocoAAnexar()
{
 SiscomPasaFocoControl(QPBAnexar);
}
void QManejadorKits::S_Anexar()
{
Anexar();
MuestraProductosDelProducto();
SiscomPasaFocoControl(QLECProductos);
HabilitaEliminaRegistra();
}
void QManejadorKits::S_RegistraKit()
{
ProductoE *lProdAsignado;

  QPBRegistraKit->setEnabled(false);
if((lProdAsignado=RegistraKit()))
{
CQSProductoPorTipo.Producto((*lProdAsignado)["CveProducto"],chrPtrIdProducto);
}
MuestraProductoAsignado(lProdAsignado);
QCBProductos->setEnabled(lProdAsignado);
QPBRegistraKit->setEnabled(!lProdAsignado);
QPBAnexar->setEnabled(lProdAsignado);
SiscomPasaFocoControl(QLECProductos);
}
void QManejadorKits::S_Producto(ProductoE *pProductoE)
{
   if(pProductoE)
   {
   QLECantidad->setEnabled(true);
  /*
   * SiscomPasaFocoControl(QLECantidad);
   *
   */
   ProdSeleccionado=pProductoE;
   }
   else
   LogSiscom("NO Se selecciono producto");
}
void QManejadorKits::IniciaVariables()
{
	QLECProductos=SiscomColocaEditAlCombo(QCBProductos,"QLECProductos");
	QMProductos=new QManProductos(SisDatCom,
					chrPtrArgumentos[0],
					QCBProductos,
					QLECProductos,
					QTEDescripcion,
					this,
					"QMProductos");
QCtrTiposProducto->Servidor(zSisConexion);
QCtrTiposProducto->IniciaControl();
zSiscomQt3::Foco(QCtrTiposProducto);
}
ProductoE *QManejadorKits::RegistraKit()
{
QRegistraKit lQRegKit((const char *)(*zSisRegTipoProducto)["idtipoproducto"],
		   SisDatCom,
		     chrPtrArgumentos);
chrPtrIdProducto=lQRegKit.IdProducto();
return lQRegKit.ProductoAsignado();
}
void QManejadorKits::MuestraProductoAsignado(ProductoE *pProdATipoProducto)
{
QLEProductoTipoProducto->setText((*pProdATipoProducto)["CveProducto"]); 
}
void QManejadorKits::Anexar()
{
  CQSProductoPorTipo.AgregaProducto(
  			(*ProdSeleccionado)["CveProducto"],			
  			SiscomDesarrollo3Qt::InformacionEdit(QLECantidad));

SiscomContenidoRegistro4Log(&CQSProductoPorTipo);
}
void QManejadorKits::MuestraProductosDelProducto()
{
const char *lchrPtrCampos[]={"CveProducto","Cantidad",0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
					QTProductos,
					CQSProductoPorTipo.Productos());
}
void QManejadorKits::HabilitaEliminaRegistra()
{
  QPBEliminaProducto->setEnabled(CQSProductoPorTipo.Productos()->count());
  QPBRegistraProductos->setEnabled(CQSProductoPorTipo.Productos()->count());
}
void QManejadorKits::RegistraProductos()
{
CQSisProductoPorTipoOp lCQSProdPorTipo(SisDatCom);
lCQSProdPorTipo.ProductosAlTipoProducto(&CQSProductoPorTipo);
}
void QManejadorKits::ReIniciandoRegistro()
{
QPBRegistraProductos->setEnabled(false);
QTProductos->setNumRows(0);
}
