#include <CorteExistencia.h>
OpCorteExistencia::OpCorteExistencia(SiscomDatCom *pSisDatCom):
		SisDatCom(pSisDatCom)
{


}


void OpCorteExistencia::FijaFechaCorte(const char *pchrPtrIdExpendio)
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta 				         	<<
		new SiscomParametroConsulta("FijaFechaCorte")		<<
		new SiscomParametroConsulta(pchrPtrIdExpendio);
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("FijaFechaCorte");


}
