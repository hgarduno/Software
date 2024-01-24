#include <RNComunFresno.h>



/*

	Esto salio muy util porque lo pense 
	para las consultas pero es practicamente
	lo mismo para las inserciones a la 
	base de datos :)

	Para la parte de registro de muchos
	datos, lo unique que se hara en el 
	cliente es enviar toda la informacion
	como si fuera una consulta, y al 
	finalizar esta un registro vacio, y
	las funciones deberan recorrer hasta
	donde estan los registros a insertar


*/
void SeleccionaYEjecutaConsultaGeneral(int pintPtoComAD,
				       const char *pchrPtrDirIpSvr,
				       StcConsultasAlSistema *pSCNSAlSistema,
				       int pintNConsultas,
				       StcLtaRegComSISCOM *pSLRCSisEntrada,
				       StcLtaRegComSISCOM **pSLRCSisRespuesta,
				       int *pintPtrNRegistros)
{
int lintContador;
char **lchrPtrParametrosConsulta;
char lchrArrConsulta[2048];
StcLtaRegComSISCOM *lSLRCSisRegreso=0;
int lintNRegistrosReg=0;
	SISCOMCopiaACharCharDeComunicaciones(pSLRCSisEntrada,
					     1,
					     &lchrPtrParametrosConsulta);
	for(lintContador=0;
	    lintContador<pintNConsultas;
	    lintContador++)
	if((pSCNSAlSistema+lintContador)->EsConsulta(lchrPtrParametrosConsulta,
						     lchrArrConsulta))
	{
	   (pSCNSAlSistema+lintContador)->ObtenInformacionConsulta(
				pintPtoComAD,
				pchrPtrDirIpSvr,
				lchrArrConsulta,
				&lSLRCSisRegreso,
				&lintNRegistrosReg);
	   (pSCNSAlSistema+lintContador)->RealizaOperacionesRespuesta(
				pintPtoComAD,
				pchrPtrDirIpSvr,
				lintNRegistrosReg,
				lSLRCSisRegreso,
				pSLRCSisRespuesta,
				pintPtrNRegistros);
	}
}

void SeleccionaYEjecutaOperacionAlSistema(int pintPtoComAD,
				       const char *pchrPtrDirIpSvr,
				       StcOperacionesAlSistema *pSCNSAlSistema,
				       int pintNConsultas,
				       StcLtaRegComSISCOM *pSLRCSisEntrada,
				       StcLtaRegComSISCOM **pSLRCSisRespuesta,
				       int *pintPtrNRegistros)
{
int lintContador;
char **lchrPtrParametrosConsulta;
char lchrArrConsulta[2048];
StcLtaRegComSISCOM *lSLRCSisRegreso=0,
		   *lSLRCSisInserciones=0;
int lintNRegistrosReg=0;
	SISCOMCopiaACharCharDeComunicaciones2(1,
					     &pSLRCSisEntrada,
					     &lchrPtrParametrosConsulta);
	for(lintContador=0;
	    lintContador<pintNConsultas;
	    lintContador++)
	if((pSCNSAlSistema+lintContador)->EsOperacion(lchrPtrParametrosConsulta,
						     lchrArrConsulta,
						     pSLRCSisEntrada,
						     &lSLRCSisInserciones))
	{
	   (pSCNSAlSistema+lintContador)->EjecutaOperacionAlSistema(
				pintPtoComAD,
				pchrPtrDirIpSvr,
				lchrArrConsulta,
				lSLRCSisInserciones,	
				&lSLRCSisRegreso,
				&lintNRegistrosReg);
	   (pSCNSAlSistema+lintContador)->FormaRespuestaOperacion(
				pintPtoComAD,
				pchrPtrDirIpSvr,
				lintNRegistrosReg,
				lSLRCSisRegreso,
				pSLRCSisRespuesta,
				pintPtrNRegistros);
	}
}
