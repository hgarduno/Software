#include <IMP_RegistroParcialComImp.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomElectronica.h>
#include <zCompraImportacion.h>
#include <zCompraParcialImportacion.h>


QRegistroParcialComImp::QRegistroParcialComImp(
				     zCompraParcialImportacion *pzCompraParI,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				QtRegistroParcialComImp(pQWParent,pchrPtrName,pWFlags),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				zCompraParcialI(pzCompraParI)	
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
emit  SignalRegistro();
}
void QRegistroParcialComImp::RegistrandoProductos()
{
zCompraImportacion *lzComImportacion;
zProductosImportados lzProdsImportados=Productos();
lzComImportacion=CompraImportacion()->DuplicaConOtrosProductos(&lzProdsImportados);
zCompraParcialI->Parcial(lzComImportacion);
zSiscomElectronica lzSisElectronica(zSisConexion,"RegistroParcialCompraImportacionFaltaronProductos");
lzSisElectronica.RegistroParcialCompraImportacionFaltaronProductos(zCompraParcialI);
}
