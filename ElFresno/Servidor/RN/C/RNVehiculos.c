#include <RNVehiculos.h>



const char *ObtenIdVehiculo(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Vehiculo_IdVehiculo];
}

const char *ObtenPlacas(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Vehiculo_Placas];
}


const char *ObtenDescripcionVehiculo(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Vehiculo_Descripcion];
}


const char *ObtenEdoRegistroVehiculo(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Vehiculo_EdoRegistro];
}



void AnexaRegistroVehiculo(char **pchrPtrRegistro,
			  int pintContador,
			  int *pintPtrNRegistros,
			  StcLtaRegComSISCOM **pSLRCSisDatPrim,
			  StcLtaRegComSISCOM **pSLRCSisActual)
{
char lchrArrBuffer[256];
	if(ObtenEdoRegistroVehiculo(pchrPtrRegistro)[0]=='0')
	SISCOMAnexaRegistroFormateandoParaEnvio(
                        pSLRCSisDatPrim,
                        pSLRCSisActual,
                        pintPtrNRegistros,
                        lchrArrBuffer,
                        "insert into Vehiculos values(%ld,'%s','%s');",
                        SISCOMObtenNumeroUnico()+pintContador,
                        ObtenPlacas(pchrPtrRegistro),
                        ObtenDescripcionVehiculo(pchrPtrRegistro));
}
			  

StcLtaRegComSISCOM *RegistraVehiculos(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     StcLtaRegComSISCOM *pSLRCSisDat,
				     int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0,
		   *lSLRCSisDatRegreso=0;
int lintContador;
int lintNRegistros=0;
long llngIdVehiculo;	
char lchrArrBuffer[256];
*pintPtrNRegistros=0;

	for(lintContador=0;
	    pSLRCSisDat;
	    lintContador++,
	    pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig)
	{
	 	AnexaRegistroVehiculo(pSLRCSisDat->chrPtrRegistro,
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
	return GeneraRespuestaVehiculos(pintPtrNRegistros);
}
int EsConsultaTodosLosVehiculos(char **pchrPtrRegistro,
				char *pchrPtrConsulta)
{
printf("Consultando -> Vehiculos \n");
	if(!pchrPtrRegistro[0][0] &&
	   !pchrPtrRegistro[1][0] )
	{
	  sprintf(pchrPtrConsulta,
		  "select * 	 \
		   from vehiculos");
	  return 1;
	}
	return 0;
}
void ConsultaTodosLosVehiculos(int pintPtoComAD,
			       const char *pchrPtrDirIpSvr,
			       const char *pchrPtrConsulta,
			       StcLtaRegComSISCOM **pSLRCSisVehiculos,
			       int *pintPtrNVehiculos)
{
*pSLRCSisVehiculos=ConsultaGenericaALaBaseElFresnoConNumeroRegistros(
				       pintPtoComAD,
                                        pchrPtrDirIpSvr,
                                        pchrPtrConsulta,
                                        pintPtrNVehiculos);


}
void RespondeTodosLosVehiculos(int pintPtoComAD,
			       const char *pchrPtrDirIpSvr,
			       int pintNVehiculos,
			       StcLtaRegComSISCOM *pSLRCSisVehiculos,
			       StcLtaRegComSISCOM **pSLRCSisVehiculosRes,
			       int *pintPtrNVehiculosRes)
{

	*pSLRCSisVehiculosRes=pSLRCSisVehiculos;
	*pintPtrNVehiculosRes=pintNVehiculos;

}
StcLtaRegComSISCOM *ConsultaVehiculos(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     StcLtaRegComSISCOM *pSLRCSisDat,
				     int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0,
		   *lSLRCSisDatRegreso=0;
int lintContador;
int lintNRegistros=0;
long llngIdVehiculo;	
char lchrArrBuffer[256];
StcConsultasAlSistema lSCNSAlSistema[]={ {EsConsultaTodosLosVehiculos,
					  ConsultaTodosLosVehiculos,
					  RespondeTodosLosVehiculos
					 }
				        };
						
	printf("Entro a la consulta de vehiculos \n");
	SeleccionaYEjecutaConsultaGeneral(pintPtoComAD,
					  pchrPtrDirIpSvr,
					  lSCNSAlSistema,
					  1,
					  pSLRCSisDat,
					  &lSLRCSisDatRegreso,
					  pintPtrNRegistros);
					  
/*
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
*/
	return lSLRCSisDatRegreso;
}
StcLtaRegComSISCOM *GeneraRespuestaVehiculos(int *pintPtrNRegistros)
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
