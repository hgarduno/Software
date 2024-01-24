#include <ManInventario.h>

ManInventario::ManInventario(SiscomDatCom *pSisDatCom,
		       ProductosE &pProductos):
		    SisDatCom(pSisDatCom),
		    Productos(pProductos)
{


}
void ManInventario::Registra()
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&Productos);
		lSGenOp.SiscomEjecutaEnvio("RegistraInventario");

}
