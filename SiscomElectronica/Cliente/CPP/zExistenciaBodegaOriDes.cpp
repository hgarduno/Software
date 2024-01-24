#include <zExistenciaBodegaOriDes.h>
#include <zSiscomCampo.h>
#include <zExistenciaBodega.h>
zExistenciaBodegaOriDes::zExistenciaBodegaOriDes(zExistenciaBodega *pzExistenciaBO,
						 zExistenciaBodega *pzExistenciaBD)
{
(*this)						<<
new zSiscomCampo("Origen",pzExistenciaBO)	<<
new zSiscomCampo("Destino",pzExistenciaBD);
}
zExistenciaBodega *zExistenciaBodegaOriDes::BodegaO()
{
  return (zExistenciaBodega *)AsociadoDelCampo("Origen");
}

zExistenciaBodega *zExistenciaBodegaOriDes::BodegaD()
{
  return (zExistenciaBodega *)AsociadoDelCampo("Destino");
}
