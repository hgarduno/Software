#include <RNFamilias.h>

const char *ObtenIdFamilia(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Familia_IdFamilia];
}

const char *ObtenNmbFamilia(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Familia_NmbFamilia];
}

const char *ObtenDscFamilia(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Familia_DscFamilia];
}

const char *ObtenEdoRegistro(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Familia_EdoRegistro];
}
void AnexaRegistroFamilia(char **pchrPtrRegistro,
			  int pintContador,
			  int *pintPtrNRegistros,
			  StcLtaRegComSISCOM **pSLRCSisDatPrim,
			  StcLtaRegComSISCOM **pSLRCSisActual)
{
char lchrArrBuffer[256];
	if(ObtenEdoRegistro(pchrPtrRegistro)[0]=='0')
	SISCOMAnexaRegistroFormateandoParaEnvio(
                        pSLRCSisDatPrim,
                        pSLRCSisActual,
                        pintPtrNRegistros,
                        lchrArrBuffer,
                        "insert into Familias values(%ld,'%s','%s');",
                        SISCOMObtenNumeroUnico()+pintContador,
                        ObtenNmbFamilia(pchrPtrRegistro),
                        ObtenDscFamilia(pchrPtrRegistro));
}
			  

StcLtaRegComSISCOM *RegistraFamilias(int pintPtoComAD,
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
*pintPtrNRegistros=0;

	for(lintContador=0;
	    pSLRCSisDat;
	    lintContador++,
	    pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig)
	{
	 	AnexaRegistroFamilia(pSLRCSisDat->chrPtrRegistro,
				     lintContador,
				     &lintNRegistros,
				     &lSLRCSisDatPrim,
				     &lSLRCSisDatActual);
				      	
	}
	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADAltaGenericaElFresno.so",
                                      "ADComandosAlta",
                                      lintNRegistros,
                                      lSLRCSisDatPrim,
                                      &lSLRCSisDatRegreso,
                                      pintPtrNRegistros);	
	return GeneraRespuestaFamilias(pintPtrNRegistros);
}
StcLtaRegComSISCOM *ConsultaFamilias(int pintPtoComAD,
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
                        "select * from familias");
		
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
StcLtaRegComSISCOM *GeneraRespuestaFamilias(int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0;

char lchrArrBuffer[256];
	*pintPtrNRegistros=0;
	SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisDatPrim,
                                               &lSLRCSisDatActual,
                                               pintPtrNRegistros,
                                               lchrArrBuffer,
                                               "%ld",
                                               0);

	return lSLRCSisDatPrim;
}
