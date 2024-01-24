#include <RNVarios.h>
StcLtaRegComSISCOM *ConsultaTiposPrecios(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     StcLtaRegComSISCOM *pSLRCSisDat,
				     int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0,
		   *lSLRCSisDatRegreso=0;
int lintContador;
int lintNRegistros=0;
long llngIdFamilia;	
char lchrArrBuffer[256];

	SISCOMAnexaRegistroFormateandoParaEnvio(
                        &lSLRCSisDatPrim,
                        &lSLRCSisDatActual,
                        &lintNRegistros,
                        lchrArrBuffer,
                        "select * from tipoprecio");
		
	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADConsultaGenericaElFresno.so",
                                      "ADConsultas",
                                      lintNRegistros,
                                      lSLRCSisDatPrim,
                                      &lSLRCSisDatRegreso,
                                      pintPtrNRegistros);	
	return lSLRCSisDatRegreso;
}
StcLtaRegComSISCOM *ConsultaGenericaALaBaseElFresnoConNumeroRegistros(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     const char *pchrPtrConsulta,
				     int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0,
		   *lSLRCSisDatRegreso=0;
int lintContador;
int lintNRegistros=0;
long llngIdFamilia;	
char lchrArrBuffer[256];

	SISCOMAnexaRegistroLEnvio(
                        &lSLRCSisDatPrim,
                        &lSLRCSisDatActual,
			1,
                        "%s",
			 pchrPtrConsulta);
	lintNRegistros++;		
	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADConsultaGenericaElFresno.so",
                                      "ADConsultas",
                                      lintNRegistros,
                                      lSLRCSisDatPrim,
                                      &lSLRCSisDatRegreso,
                                      pintPtrNRegistros);	
	return lSLRCSisDatRegreso;
}
StcLtaRegComSISCOM *ConsultaGenericaALaBaseElFresno(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     const char *pchrPtrConsulta)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0,
		   *lSLRCSisDatRegreso=0;
int lintContador;
int lintNRegistros=0;
long llngIdFamilia;	
char lchrArrBuffer[256];

	SISCOMAnexaRegistroLEnvio(
                        &lSLRCSisDatPrim,
                        &lSLRCSisDatActual,
			1,
                        "%s",
			 pchrPtrConsulta);
	lintNRegistros++;		
	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADConsultaGenericaElFresno.so",
                                      "ADConsultas",
                                      lintNRegistros,
                                      lSLRCSisDatPrim,
                                      &lSLRCSisDatRegreso,
                                      &lintNRegistros);	
	return lSLRCSisDatRegreso;
}
