#include <RNTiposPrecios.h>

const char *ObtenNmbTipoPrecioTiposPrecios(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_TiposPrecios_NmbTipoPrecio];
}
const char *ObtenDescripcionTiposPrecios(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_TiposPrecios_Descripcion];
}

const char *ObtenEdoRegistroTiposPrecios(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_TiposPrecios_EdoRegistroTiposPrecios];
}
const char *ObtenTipoTiposPrecios(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_TiposPrecios_Tipo];
}
void AnexaRegistroTiposPrecios(char **pchrPtrRegistro,
			  int pintContador,
			  int *pintPtrNRegistros,
			  StcLtaRegComSISCOM **pSLRCSisDatPrim,
			  StcLtaRegComSISCOM **pSLRCSisActual)
{
char lchrArrBuffer[256];
	if(ObtenEdoRegistroTiposPrecios(pchrPtrRegistro)[0]=='0')
	SISCOMAnexaRegistroFormateandoParaEnvio(
                        pSLRCSisDatPrim,
                        pSLRCSisActual,
                        pintPtrNRegistros,
                        lchrArrBuffer,
                        "insert into TipoPrecio values('%s','%s','%s');",
                        ObtenNmbTipoPrecioTiposPrecios(pchrPtrRegistro),
                        ObtenDescripcionTiposPrecios(pchrPtrRegistro),
			ObtenTipoTiposPrecios(pchrPtrRegistro));
}

StcLtaRegComSISCOM *GeneraRespuestaTiposPrecios(int *pintPtrNRegistros)
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

StcLtaRegComSISCOM *RegistraTiposPrecios(int pintPtoComAD,
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

	SISCOMImprimeContenidoCom2(stdout,
				   "RegistraTiposPrecios",
				   '|',
				   '\n',
				   pSLRCSisDat);
	for(lintContador=0;
	    pSLRCSisDat;
	    lintContador++,
	    pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig)
	{
	 	AnexaRegistroTiposPrecios(pSLRCSisDat->chrPtrRegistro,
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
	return GeneraRespuestaTiposPrecios(pintPtrNRegistros);

}


