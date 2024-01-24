#include <RNProductos.h>
const char *ObtenClave(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Productos_Clave];
}
const char *ObtenDescripcion(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Productos_Descripcion];
}

const char *ObtenUnidades(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Productos_Unidad];
}

const char *ObtenFamilia(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Productos_Familia];
}
const char *ObtenEdoRegistroProducto(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Productos_EdoRegistroProducto];
}


void AnexaRegistroProducto(char **pchrPtrRegistro,
                          int pintContador,
                          int *pintPtrNRegistros,
                          StcLtaRegComSISCOM **pSLRCSisDatPrim,
                          StcLtaRegComSISCOM **pSLRCSisActual)
{
char lchrArrBuffer[256];
        if(ObtenEdoRegistroProducto(pchrPtrRegistro)[0]=='0')
	{
        SISCOMAnexaRegistroFormateandoParaEnvio(
                        pSLRCSisDatPrim,
                        pSLRCSisActual,
                        pintPtrNRegistros,
                        lchrArrBuffer,
                        "insert into Productos values('%s','%s',%s,%s);",
                        ObtenClave(pchrPtrRegistro),
                        ObtenDescripcion(pchrPtrRegistro),
			ObtenUnidades(pchrPtrRegistro),
			ObtenFamilia(pchrPtrRegistro));
	}
}
                        
        
StcLtaRegComSISCOM *RegistraProductos(int pintPtoComAD,
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
        SISCOMImprimeContenidoCom2(stdout,
				   "RegistraProductos",
				   '|',
				   '\n',
				   pSLRCSisDat); 
        for(lintContador=0;           
            pSLRCSisDat;              
            lintContador++,
            pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig)
        {
                AnexaRegistroProducto(pSLRCSisDat->chrPtrRegistro,
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
        return GeneraRespuestaProductos(pintPtrNRegistros);
}
StcLtaRegComSISCOM *GeneraRespuestaProductos(int *pintPtrNRegistros)
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
StcLtaRegComSISCOM *ConsultaClavesYDescripciones(int pintPtoComAD,
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
char lchrArrBuffer[1024];
char lchrArrCondicion[128];
	SISCOMImprimeContenidoCom2(stdout,
				   "ConsultaClavesYDescripciones",
				  '|',
				  '\n',
				  pSLRCSisDat);
	if(pSLRCSisDat &&
	   pSLRCSisDat->chrPtrRegistro[1][0])
	  sprintf(lchrArrCondicion,
		  "where NmbFamilia='%s'",
		  pSLRCSisDat->chrPtrRegistro[1]);
	else
	 lchrArrCondicion[0]=0;
	
        SISCOMAnexaRegistroFormateandoParaEnvio(
                        &lSLRCSisDatPrim,
                        &lSLRCSisDatActual,
                        &lintNRegistros,
                        lchrArrBuffer,
                        "SELECT * \
			 from	productos  \
				inner join unidades using(Unidad)    \
				inner join familias using(idFamilia) \
			 %s 					     \
			 order by NmbFamilia,	\
				  CveProducto",
			 lchrArrCondicion);
                
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
