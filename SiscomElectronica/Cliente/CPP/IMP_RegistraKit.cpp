#include <IMP_RegistraKit.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisKits.h>
#include <ProductosE.h>
QRegistraKit::QRegistraKit(const char *pchrPtrIdTipoProducto,
			SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				RegistraKit(pQWParent,pchrPtrName,pbModal,pWFlags),
				chrPtrIdTipoProducto(pchrPtrIdTipoProducto),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QRegistraKit::~QRegistraKit()
{

}

void QRegistraKit::ConectaSlots()
{
	connect(QMProductos,
		SIGNAL(SignalProducto(ProductoE *)),
		SLOT(S_Producto(ProductoE *)));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(S_Registra()));

}
void QRegistraKit::S_Registra()
{
Registra();
ValidandoRegreso();
}
void QRegistraKit::S_Producto(ProductoE *pProductoE)
{
   if(pProductoE)
   {
     ProdSeleccionado=pProductoE;
     SiscomPasaFocoControl(QPBAceptar);
   }

}
void QRegistraKit::IniciaVariables()
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
void QRegistraKit::Registra()
{
CQSisKitsOp lCQSKOpRegistra(SisDatCom);
chrPtrIdProducto=lCQSKOpRegistra.RegistraKit(ProdSeleccionado, chrPtrIdTipoProducto);
}
void QRegistraKit::ValidandoRegreso()
{
/* Domingo 15 de Noviembre del 2015
 * Se debe integrar la validacion del regreso
 * para evaluar si el registro se realizo en todos los
 * expendio
 */
	done(1);
}
ProductoE *QRegistraKit::ProductoAsignado()
{
return ProdSeleccionado;
}
const char *QRegistraKit::IdProducto()
{
  return chrPtrIdProducto;
}
