#include <IMP_ProveedoresCompraImportacion.h>

#include <zSiscomQt3.h>
#include <zSiscomRegistros.h>

#include <zCompraImportacion.h>
#include <zEmpresa.h>

#include <qtable.h>
QProveedoresCompraImportacion::QProveedoresCompraImportacion(
				    zCompraImportacion *pzCompraImp,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ProveedoresCompraImportacion(pQWParent,
							     pchrPtrName,
							     pbModal,
							     pWFlags),
				zCompImp(pzCompraImp)
{
IniciaVariables();
exec();
}

QProveedoresCompraImportacion::~QProveedoresCompraImportacion()
{

}

void QProveedoresCompraImportacion::ConectaSlots()
{
connect(QTProveedores,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotProveedor(int,int,int,const QPoint &)));
}
void QProveedoresCompraImportacion::SlotProveedor(int pintProveedor,
						  int,
						  int,
						  const QPoint &)
{
   zEmpresaReg=(zEmpresa *)(*Compra()->Proveedores())[pintProveedor];
   done(1);
}
void QProveedoresCompraImportacion::IniciaVariables()
{
 	ConectaSlots();
	MuestraProveedores();
}

zCompraImportacion *QProveedoresCompraImportacion::Compra()
{
	return zCompImp;
}

void QProveedoresCompraImportacion::MuestraProveedores()
{
zEmpresa *lzEmpresa;
int lintContador;
QTProveedores->setNumRows(Compra()->Proveedores()->NNodos());
for(lzEmpresa=(zEmpresa *)Compra()->Proveedores()->Primer(),
    lintContador=0;
    lzEmpresa;
    lzEmpresa=(zEmpresa *)Compra()->Proveedores()->Siguiente(),
    lintContador++)
QTProveedores->setText(lintContador,0,lzEmpresa->RazonSocial());
zSiscomQt3::AjustaFilasTabla(QTProveedores);
}
zEmpresa *QProveedoresCompraImportacion::Proveedor()
{
   return zEmpresaReg;
}
