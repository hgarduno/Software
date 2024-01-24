#include <IMP_ClavesProveedores.h>
#include <IMP_CapturaDato.h>
#include <CQSis3QtOperaciones.h>
#include<SiscomDesarrollo3Qt++.h>
#include <ProductosE.h>
QClavesProveedores *InstanciaClavesProveedores(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QClavesProveedores((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QClavesProveedores::QClavesProveedores(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ClavesProveedores(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QClavesProveedores::~QClavesProveedores()
{

}

void QClavesProveedores::ConectaSlots()
{

	connect(QMProductos,
		SIGNAL(SignalProducto(ProductoE *)),
		SLOT(S_Producto(ProductoE *)));
	connect(QTClavesProveedor,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(S_Proveedor(int,int,int,const QPoint &)));
}
void QClavesProveedores::S_Proveedor(int pintProveedor,
				     int,
				     int,
				     const QPoint &)
{
SeleccionaProveedor(pintProveedor);
CapturaClave(pintProveedor);
ActualizaClave(pintProveedor);
ConsultandoClaves();
}
void QClavesProveedores::S_Producto(ProductoE *pProducto)
{
 ProdSeleccionado=pProducto;
 ConsultandoClaves();
}
void QClavesProveedores::IniciaVariables()
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
void QClavesProveedores::ConsultandoClaves()
{
	SisReg4Claves.SiscomLimpia();
 ConsultaClaves();
 MuestraClaves();
}
void QClavesProveedores::ConsultaClaves()
{
CQSis3QtOperaciones lCQS3QtClavesProv(SisDatCom);
lCQS3QtClavesProv.ClavesProveedor((*ProdSeleccionado)["CveProducto"],
				  &SisReg4Claves);
}
void QClavesProveedores::MuestraClaves()
{
const char *lchrPtrCampos[]={"razonsocial","cveproveedor",0};
SiscomDesarrollo3Qt::RegsPrincipal4ALaTabla(lchrPtrCampos,QTClavesProveedor,&SisReg4Claves);
SiscomDesarrollo3Qt::AjustaColumnas(QTClavesProveedor);
}
void QClavesProveedores::SeleccionaProveedor(int pintProveedor)
{
  QTClavesProveedor->selectRow(pintProveedor);
}
void QClavesProveedores::CapturaClave(int pintProveedor)
{
QCapturaDato lCQCClave("Clave Proveedor", "Clave");
lCQCClave.ObtenDato(chrArrCveProducto);
SiscomEscribeLog3Qt("La Clave %s",chrArrCveProducto);
}
void QClavesProveedores::ActualizaClave(int pintProveedor)
{
CQSis3QtOperaciones lCQSis3QtActClave(SisDatCom);
lCQSis3QtActClave.ActualizaClaveProveedor(
			chrPtrArgumentos[0],
			SisReg4Claves.CampoRegistroPrincipal(pintProveedor,"idempresa"),
			chrArrCveProducto,
			(*ProdSeleccionado)["CveProducto"]);
}
