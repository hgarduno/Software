#include <IniciaExpendio.h>

OpIniciaExpendios::OpIniciaExpendios(SiscomDatCom *pSisDatCom):
			SisDatCom(pSisDatCom)
{



}


void OpIniciaExpendios::IniciaBaseDatos(const char *pchrPtrIdExpendio)
{
SiscomParametrosConsulta lSPConsulta;

			lSPConsulta			<<
			new SiscomParametroConsulta(pchrPtrIdExpendio);
SiscomGeneralOperacionesSrv lSGenOp(
				SisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
			lSGenOp.SiscomEjecutaEnvio("IniciaExpendio");
}
