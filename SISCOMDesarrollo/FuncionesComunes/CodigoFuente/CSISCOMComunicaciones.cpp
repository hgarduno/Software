/*! \file CSISCOMComunicaciones.cpp
 *  \brief SISCOM Electronica 
 *
 *  Archivo para manejar la informacion de los datos
 *  de conexion en la SiscomDesarrollo 1.0
 *
 */

#include <CSISCOMComunicaciones.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
CSISCOMComunicaciones::CSISCOMComunicaciones()
{

}
CSISCOMComunicaciones::CSISCOMComunicaciones(int pintPtoCom,
					     const char *pchrPtrDirIpSvr,
					     const char *pchrPtrUsuario,
					     const char *pchrPtrPassword):
		      intNRegistros(0),
		      SLRCSisPrim(0),
		      SLRCSisActual(0),
		      SLCRCSisPrimReg(0)


			
{
	CSDComInfo.PonPtoCom(pintPtoCom);
	CSDComInfo.PonDirIpSvr(pchrPtrDirIpSvr);
	CSDComInfo.PonUsuario(pchrPtrUsuario);
	CSDComInfo.PonPassword(pchrPtrPassword);
}
CSISCOMComunicaciones::CSISCOMComunicaciones(CSISCOMDatComunicaciones pCSDComInfo):
		       CSDComInfo(pCSDComInfo),
		      intNRegistros(0),
		      SLRCSisPrim(0),
		      SLRCSisActual(0),
		      SLCRCSisPrimReg(0),
		      chrPtrCamposEnviar(0)
{
}
CSISCOMComunicaciones::~CSISCOMComunicaciones()
{
	close(intSocketCom);
}
StcLtaRegComSISCOM *CSISCOMComunicaciones::ObtenRegistrosResAlta()
{
	return SLCRCSisPrimReg;
}
void CSISCOMComunicaciones::EnviaInformacionAlSvrAlta()
{
	FormaProtocoloEncabezado();
	SISCOMEnviaInfAlServidor(chrPtrDatProtocolo,
				 intNRegistros,
				 SLRCSisPrim,
				 &intSocketCom);
	SISCOMObtenRespuestaSVR(intSocketCom,
				&intNCamResAlta,
				&intNRegResAlta,
				&SLCRCSisPrimReg);
}
void CSISCOMComunicaciones::FormaProtocoloEncabezado()
{
	SISCOMFormaDatosProtocoloInfoUsuario((char *)CSDComInfo.ObtenUsuario(),
					     (char *)CSDComInfo.ObtenPassword(),
					     &chrPtrDatProtocolo);
	SISCOMFormaDatosProtocoloInfoServidor(CSDComInfo.ObtenPtoCom(),
					      (char *)CSDComInfo.ObtenDirIpSvr(),
					      (char *)chrPtrDLLServidorAlta,
					      (char *)chrPtrDLLFuncionAlta,
					      &chrPtrDatProtocolo);
}
void CSISCOMComunicaciones::PonDatosDLLAltaServidor(int pintNumCampos,
						    const char *pchrPtrNmbDll,
						    const char *pchrPtrFuncion)
{
	chrPtrDLLServidorAlta=pchrPtrNmbDll;
	chrPtrDLLFuncionAlta=pchrPtrFuncion;
	intNCampos=pintNumCampos;
}
void CSISCOMComunicaciones::PonDatosDLLAltaServidor(const char *pchrPtrNmbDll,
						    const char *pchrPtrFuncion)
{
	chrPtrDLLServidorAlta=pchrPtrNmbDll;
	chrPtrDLLFuncionAlta=pchrPtrFuncion;
}
void CSISCOMComunicaciones::IniciaCamposAEnviar(int pintNumCampos)
{
    chrPtrCamposEnviar=(char **)malloc(sizeof(char *)*(pintNumCampos+1)); 
    chrPtrCamposEnviar[pintNumCampos]=0;
    intNCampos=pintNumCampos;
}
void CSISCOMComunicaciones::AnexaCampo(int pintNumDCampo,
				       const char *pchrPtrCampo)
{
	if(!chrPtrCamposEnviar)
	 IniciaCamposAEnviar(intNCampos);
	chrPtrCamposEnviar[pintNumDCampo]=(char *)strdup(pchrPtrCampo);

}
void CSISCOMComunicaciones::AnexaRegistro(char **pchrPtrRegistro)
{
	
	SISCOMCreaListaRegCom(pchrPtrRegistro,&SLRCSisPrim,&SLRCSisActual);
	intNRegistros++;
}
void CSISCOMComunicaciones::AnexaRegistro()
{
	
	SISCOMCreaListaRegCom(chrPtrCamposEnviar,&SLRCSisPrim,&SLRCSisActual);
	intNRegistros++;
}
void CSISCOMComunicaciones::AnexaRegistro(const char *pchrPtrFormato,
					  ...)
{
va_list lVLArg;
char **lchrPtrCampos=(char **)malloc(sizeof(char *)*(intNCampos+1));
char *lchrPtrArgumento;
int lintContador=0;
	va_start(lVLArg,pchrPtrFormato);
	lchrPtrCampos[intNCampos]=0;
	while(*pchrPtrFormato)
	{
		if(*pchrPtrFormato++=='%')	
		switch(*pchrPtrFormato)
		{
		  case 's':
			   lchrPtrArgumento=va_arg(lVLArg,char *);
			   lchrPtrCampos[lintContador]=(char *)strdup(lchrPtrArgumento);
			   lintContador++;
		  break;
		  case 'l':
			   lchrPtrCampos[lintContador]=SISCOMNumeroACadenaLong(va_arg(lVLArg,long));
			   lintContador++;
		  break;
		}
	    *pchrPtrFormato++;
	}
	 va_end(lVLArg);
	SISCOMCreaListaRegCom(lchrPtrCampos,&SLRCSisPrim,&SLRCSisActual);
	intNRegistros++;
}
CSISCOMDatComunicaciones::CSISCOMDatComunicaciones(int pintPtoCom,
						   const char *pchrPtrDirIpSvr,
						   const char *pchrPtrUsuario,
						   const char *pchrPtrPassword):
			   intPtoCom(pintPtoCom),
			   chrPtrDirIpSvr(pchrPtrDirIpSvr),
			   chrPtrUsuario(pchrPtrUsuario),
			   chrPtrPassword(pchrPtrPassword)
{

}
CSISCOMDatComunicaciones::CSISCOMDatComunicaciones()
{
}
int CSISCOMDatComunicaciones::ObtenPtoCom()
{
	return intPtoCom;
}
const char *CSISCOMDatComunicaciones::ObtenDirIpSvr()
{
	return  chrPtrDirIpSvr;
}
const char *CSISCOMDatComunicaciones::ObtenUsuario()
{
	return chrPtrUsuario;
}
const char *CSISCOMDatComunicaciones::ObtenPassword()
{
	return chrPtrPassword;
}
const char *CSISCOMDatComunicaciones::ObtenIdAplicacion()
{
	return chrPtrIdAplicacion;
}
void CSISCOMDatComunicaciones::PonPtoCom(int pintPtoCom)
{
	intPtoCom=pintPtoCom;
}
void CSISCOMDatComunicaciones::PonDirIpSvr(const char *pchrPtrDirIpSvr)
{
	chrPtrDirIpSvr=pchrPtrDirIpSvr;
}
void CSISCOMDatComunicaciones::PonUsuario(const char *pchrPtrUsuario)
{
	chrPtrUsuario=pchrPtrUsuario;
}
void CSISCOMDatComunicaciones::PonPassword(const char *pchrPtrPassword)
{
	chrPtrPassword=pchrPtrPassword;
}
void CSISCOMDatComunicaciones::PonIdAplicacion(const char *pchrPtrIdAplicacion)
{
	chrPtrIdAplicacion=pchrPtrIdAplicacion;
}

