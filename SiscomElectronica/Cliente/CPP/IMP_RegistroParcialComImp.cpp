#include <IMP_RegistroParcialComImp.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomElectronica.h>
#include <zCompraImportacion.h>


QRegistroParcialComImp::QRegistroParcialComImp(char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				QtRegistroParcialComImp(pQWParent,pchrPtrName,pWFlags),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
ConectaSlots();
show();
}

QRegistroParcialComImp::~QRegistroParcialComImp()
{

}
void QRegistroParcialComImp::SlotRegistroProductos()
{
RegistrandoProductos();

}
void QRegistroParcialComImp::RegistrandoProductos()
{
zCompraImportacion *lzComImportacion;
zProductosImportados lzProdsImportados=Productos();
lzComImportacion=CompraImportacion()->DuplicaConOtrosProductos(&lzProdsImportados);
zSiscomElectronica lzSisElectronica(zSisConexion,"RegistroParcialCompraImportacionFaltaronProductos");
lzSisElectronica.RegistroParcialCompraImportacionFaltaronProductos(lzComImportacion);
}
