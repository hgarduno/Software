#include <SiscomOperaciones.h>
#include <SiscomDatCom.h>
#include <SiscomGeneralOperacionesSrv.h>

SiscomOperaciones::SiscomOperaciones(SiscomDatCom *pSisDatCom,
				     QPtrList<SiscomInformacion> *pQPLSiscomInfo):
		SisDatCom(pSisDatCom),
		QPLSiscomInfo(pQPLSiscomInfo)
{


}
SiscomOperaciones::SiscomOperaciones(SiscomDatCom *pSisDatCom):
		SisDatCom(pSisDatCom)
{

}
SiscomOperaciones::~SiscomOperaciones()
{

}

void SiscomOperaciones::SiscomActualiza(const char *pchrPtrOperacion)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				QPLSiscomInfo);
lSGenOp.SiscomEjecutaEnvio(pchrPtrOperacion);
}
void SiscomOperaciones::SiscomActualiza(
			const char *pchrPtrOperacion,
			SiscomInformacionLst *pSisInfoLstRegreso)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				QPLSiscomInfo);
lSGenOp.SiscomEjecutaEnvio(pchrPtrOperacion);
SiscomGeneraRegistrosActualiza((const SiscomComunicaSrv *)lSGenOp,pSisInfoLstRegreso);
}

void SiscomOperaciones::SiscomActualiza2(const char *pchrPtrOperacion)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				QPLSiscomInfo);
lSGenOp.SiscomEjecutaEnvio2(pchrPtrOperacion);
}

void SiscomOperaciones::SiscomActualiza2(
			const char *pchrPtrOperacion,
			SiscomRegistrosPro2 **pSRegistrosPro2)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				QPLSiscomInfo);
lSGenOp.SiscomEjecutaEnvio2(pchrPtrOperacion);
SiscomGeneraRegistrosActualiza((const SiscomComunicaSrv *)lSGenOp,pSRegistrosPro2);
}
void SiscomOperaciones::SiscomActualiza2(
			const char *pchrPtrOperacion,
			SiscomInformacionLst *pSisInfoLstRegreso)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				QPLSiscomInfo);
lSGenOp.SiscomEjecutaEnvio2(pchrPtrOperacion);
SiscomGeneraRegistrosActualiza((const SiscomComunicaSrv *)lSGenOp,pSisInfoLstRegreso);
}
void SiscomOperaciones::SiscomActualizaSubRegistros(
			const char *pchrPtrOperacion,
			SiscomInformacionLst *pSisInfoLstRegreso)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				QPLSiscomInfo);
lSGenOp.SiscomEjecutaEnvioSubRegistros(pchrPtrOperacion);
SiscomGeneraRegistrosActualiza((const SiscomComunicaSrv *)lSGenOp,pSisInfoLstRegreso);
}
void SiscomOperaciones::SiscomActualiza2SubRegistros(
			const char *pchrPtrOperacion,
			SiscomRegistrosPro2 **pSRegistrosPro2)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				QPLSiscomInfo);
lSGenOp.SiscomEjecutaEnvioSubRegistros(pchrPtrOperacion);
SiscomGeneraRegistrosActualiza((const SiscomComunicaSrv *)lSGenOp,pSRegistrosPro2);
}
void SiscomOperaciones::SiscomConsulta(const char *pchrPtrOperacion,
				       SiscomRegistrosPro2 **pSRegistrosPro2)
{
	SiscomActualiza2SubRegistros(pchrPtrOperacion,
				     pSRegistrosPro2);
}
void SiscomOperaciones::SiscomConsulta(const char *pchrPtrOperacion,
				       QPtrList<SiscomInformacion> *pQPLSiscomInfo)
{
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				QPLSiscomInfo);
lSGenOp.SiscomEjecutaEnvio2(pchrPtrOperacion);
SiscomGeneraRegistros((const SiscomComunicaSrv *)lSGenOp,pQPLSiscomInfo);
}
void SiscomOperaciones::SiscomPonParametrosConsulta(
					QPtrList<SiscomInformacion> *pQPtrInformacion)
{
	QPLSiscomInfo=pQPtrInformacion;
}
void SiscomOperaciones::SiscomGeneraRegistros(const SiscomComunicaSrv *,
					      QPtrList<SiscomInformacion> *)
{
SiscomInformacion *lSInformacion;
}
void SiscomOperaciones::SiscomGeneraRegistrosActualiza(const SiscomComunicaSrv *,
					      QPtrList<SiscomInformacion> *)
{

}
void SiscomOperaciones::SiscomGeneraRegistrosActualiza(
			const SiscomComunicaSrv *pSComunicaSrv,
			SiscomRegistrosPro2 **pSRegistrosPro2)
{
	*pSRegistrosPro2=new SiscomRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);

}

