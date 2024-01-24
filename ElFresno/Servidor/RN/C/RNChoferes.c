#include <RNChoferes.h>


int EsConsultaTodosLosChoferes(char **pchrPtrArgumentos,
			       char *pchrPtrConsulta,
			       StcLtaRegComSISCOM *pSLRCSisDat,
			       StcLtaRegComSISCOM **pSLRCSisRegreso)
{

	if(!strcmp(pchrPtrArgumentos[0],
		   "ConsultaTodosLosChoferes"))
	{
	   sprintf(pchrPtrConsulta,
		   "select nombre,		\
		   	   apaterno,		\
			   amaterno,		\
			   rfc,			\
			   idpersona,		\
			   tipopersona		\
		    from personas		\
		    where TipoPersona=%s and 	\
		          edoregistro=1",
		    pchrPtrArgumentos[1]);
	  return 1;
	}
	
		return 0;	


}
		  
void EjecutaConsultaTodosLosChoferes(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     const char *pchrPtrConsulta,
				     StcLtaRegComSISCOM *pSLRCSisDatEntrada,
				     StcLtaRegComSISCOM **pSLRCSisDatRegreso,
				     int *pintPtrNRegreso)
{
*pSLRCSisDatRegreso=ConsultaGenericaALaBaseElFresnoConNumeroRegistros(
	pintPtoComAD,
	 pchrPtrDirIpSvr,
	 pchrPtrConsulta,
	 pintPtrNRegreso);


}
void FormaRespuestaTodosLosChoferes(int pintPtoComAD,
			            const char *pchrPtrDirIpSvr,
				    int pintNRegistros,
				    StcLtaRegComSISCOM *pSLRCSisDatEnt,
				    StcLtaRegComSISCOM **pSLRCSisDatRegreso,
				    int *pintPtrNRegistros)
{

	*pSLRCSisDatRegreso=pSLRCSisDatEnt;
	*pintPtrNRegistros=pintNRegistros;

}
StcLtaRegComSISCOM *OperacionesChoferes(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     StcLtaRegComSISCOM *pSLRCSisDat,
				     int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatRegreso=0;
StcOperacionesAlSistema lSOpChoferes[]={ {EsConsultaTodosLosChoferes,
					  EjecutaConsultaTodosLosChoferes,
					  FormaRespuestaTodosLosChoferes
					 }
					};
	SeleccionaYEjecutaOperacionAlSistema(pintPtoComAD,
					     pchrPtrDirIpSvr,
					     lSOpChoferes,
					     1,
					     pSLRCSisDat,
					     &lSLRCSisDatRegreso,
					     pintPtrNRegistros);

	return lSLRCSisDatRegreso;
}

