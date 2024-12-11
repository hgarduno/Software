#include <IMP_TransfiereBodegaBodega.h>


#include <zSiscomDesarrollo4.h>
#include <zSiscomElectronica.h>
#include <zExistenciaBodega.h>

#include <zSiscomQt3.h>
QTransfiereBodegaBodega::QTransfiereBodegaBodega(zSiscomConexion *pzSisConexion,
						 char **pchrPtrArgumentos,
						 QWidget *pQWParent,
						 const char *pchrPtrName,
						 WFlags pWFlags):
			QtTransfiereBodegaBodega(pQWParent,pchrPtrName,pWFlags)
{
 QtTransfiereBodegaBodega::Conexion(pzSisConexion);
 QtTransfiereBodegaBodega::IniciaVariables();
}
void QTransfiereBodegaBodega::Transfiere()
{
zSiscomElectronica lzSiscomE(QtTransfiereBodegaBodega::Conexion(),"TransfiereBodegaBodega");
lzSiscomE.TransfiereBodegaBodega(QtTransfiereBodegaBodega::BodegaBodega());
}
void QTransfiereBodegaBodega::Consultando(zExistenciaBodega *pzExistenciaB)
{
zSiscomElectronica lzSisElectronica(Conexion(),"ExistenciaBodega4");
lzSisElectronica.ExistenciaBodega(pzExistenciaB);
}
int QTransfiereBodegaBodega::ValidaExistenciaBodegaO(zExistenciaBodega *pzExistenciaB)
{
zSiscomElectronica lzSiscomE(Conexion(),"ValidaExistenciaBodega");
return lzSiscomE.ValidaExistenciaBodega(zSiscomQt3::Texto(QLECantidad),pzExistenciaB);
}
