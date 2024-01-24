#include <RNUnidades.h>
const char *ObtenUnidad(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Unidades_Unidad];
}
const char *ObtenNmbUnidad(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Unidades_NmbUnidad];
}

const char *ObtenAbreviatura(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Unidades_Abreviatura];
}

const char *ObtenEdoRegistroUnidad(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Unidades_EdoRegistro];
}



void AnexaRegistroUnidad(char **pchrPtrRegistro,
                          int pintContador,
                          int *pintPtrNRegistros,
                          StcLtaRegComSISCOM **pSLRCSisDatPrim,
                          StcLtaRegComSISCOM **pSLRCSisActual)
{
char lchrArrBuffer[256];
        if(ObtenEdoRegistroUnidad(pchrPtrRegistro)[0]=='0')
        SISCOMAnexaRegistroFormateandoParaEnvio(
                        pSLRCSisDatPrim,
                        pSLRCSisActual,
                        pintPtrNRegistros,
                        lchrArrBuffer,
                        "insert into Unidades values(%ld,'%s','%s');",
                        SISCOMObtenNumeroUnico()+pintContador,
                        ObtenNmbUnidad(pchrPtrRegistro),
                        ObtenAbreviatura(pchrPtrRegistro));
}
                        
        
StcLtaRegComSISCOM *RegistraUnidades(int pintPtoComAD,
                                     const char *pchrPtrDirIpSvr,
                                     StcLtaRegComSISCOM *pSLRCSisDat,
                                     int *pintPtrNRegistros)
{                       
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
                   *lSLRCSisDatActual=0,
                   *lSLRCSisDatRegreso=0;
int lintContador;                     
int lintNRegistros=0;                 
long llngIdUnidad;                   
char lchrArrBuffer[256];              
*pintPtrNRegistros=0;                 
                                      
        for(lintContador=0;           
            pSLRCSisDat;              
            lintContador++,
            pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig)
        {
                AnexaRegistroUnidad(pSLRCSisDat->chrPtrRegistro,
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
        return GeneraRespuestaUnidades(pintPtrNRegistros);
}
StcLtaRegComSISCOM *GeneraRespuestaUnidades(int *pintPtrNRegistros)
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

StcLtaRegComSISCOM *ConsultaUnidades(int pintPtoComAD,
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
                        "select * from unidades");
                
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

