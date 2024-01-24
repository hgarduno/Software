#include <zTransferenciasBodegaBodega.h>
#include <zSiscomCampo.h>
#include <zExistenciaBodegaOriDes.h>
#include <zExistenciaBodega.h>
#include <zBodega.h>
zTransferenciasBodegaBodega::zTransferenciasBodegaBodega()
{

}
void zTransferenciasBodegaBodega::Agrega(zExistenciaBodegaOriDes *pzExisBodOriDes)
{
   (*this) << pzExisBodOriDes;
}
zExistenciaBodega *zTransferenciasBodegaBodega::TransferenciaO(int pintNTransferencia)
{
zExistenciaBodegaOriDes *lzExistenciaBodOriDes;
lzExistenciaBodOriDes=(zExistenciaBodegaOriDes *)(*this)[pintNTransferencia];
return lzExistenciaBodOriDes->BodegaO();
}

zExistenciaBodega *zTransferenciasBodegaBodega::TransferenciaD(int pintNTransferencia)
{
zExistenciaBodegaOriDes *lzExistenciaBodOriDes;
lzExistenciaBodOriDes=(zExistenciaBodegaOriDes *)(*this)[pintNTransferencia];
return lzExistenciaBodOriDes->BodegaD();
}
const char *zTransferenciasBodegaBodega::BodegaO(int pintNTransferencia)
{
return TransferenciaO(pintNTransferencia)->Bodega()->Bodega();
}
const char *zTransferenciasBodegaBodega::BodegaD(int pintNTransferencia)
{
return TransferenciaD(pintNTransferencia)->Bodega()->Bodega();
}
const char *zTransferenciasBodegaBodega::ExistenciaO(int pintNTransferencia)
{
 return TransferenciaO(pintNTransferencia)->Existencia();
}
const char *zTransferenciasBodegaBodega::ExistenciaD(int pintNTransferencia)
{
 return TransferenciaD(pintNTransferencia)->Existencia();
}

const char *zTransferenciasBodegaBodega::Producto(int pintNTransferencia)
{
 return TransferenciaO(pintNTransferencia)->Producto();
}
const char *zTransferenciasBodegaBodega::Cantidad(int pintNTransferencia)
{
 return TransferenciaO(pintNTransferencia)->Cantidad();
}
