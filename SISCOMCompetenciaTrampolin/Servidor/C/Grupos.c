#include <Grupos.h>
#include <ServidorGeneral.h>

#include <string.h>
void AsignaArgumentosGrupos(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"GimGrupos",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"GimResGrupos",pSAgsSiscom);
}
void FormaEstructuraNmbsGrupos(
		LCamposSiscomPro2 *pLCSiscomPro2Grupos,
		StcSisFormaRegistro *pSSForReg)
{
int lintContador;

	memset(pSSForReg,0,sizeof(StcSisFormaRegistro));
	pSSForReg->chrPtrCampo=strdup("idgrupo");
	for(lintContador=0;
	    pLCSiscomPro2Grupos;
	    lintContador++,
	    pLCSiscomPro2Grupos=pLCSiscomPro2Grupos->SCP2PtrSig)
	{
	 pSSForReg->SSRegistro[lintContador].chrPtrCampo=strdup("grupo");
	 pSSForReg->SSRegistro[lintContador].chrPtrValor=
	 		SiscomObtenDato(pLCSiscomPro2Grupos,"grupo");
	}

}
void FormaRespuestaGrupos(int pintNumGrupos,
			  LCamposSiscomPro2ConSubReg *pLCSiscomPro2CSRGrupos,
			  LCamposSiscomPro2 **pLCSiscomPro2Prim,
			  int *pintPtrNumRegRes)
{
int lintContador;
LCamposSiscomPro2 *lLCSiscomPro2Contador;
LCamposSiscomPro2 *lLCSiscomPro2Act=0;
SCampoSiscomPro2 *lSCSiscomPro2;


  for(lintContador=0;
      lintContador<pintNumGrupos;
      lintContador++)
  {
   lLCSiscomPro2Contador=pLCSiscomPro2CSRGrupos->LCSiscomSubReg[lintContador].LCSiscomPro2Prim;
   if(lLCSiscomPro2Contador)
   {
    lSCSiscomPro2=lLCSiscomPro2Contador->SCSiscomPro2;
     AnexaRegistroNombreGrupo(
     	SiscomObtenDato(lLCSiscomPro2Contador,"grupo"),
	lLCSiscomPro2Contador->SCSiscomPro2,
	pLCSiscomPro2Prim,
	&lLCSiscomPro2Act,
	pintPtrNumRegRes);
     for(;
         lLCSiscomPro2Contador;
	 lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
     {
	SiscomCreaListaCamposPro2(
			lLCSiscomPro2Contador->SCSiscomPro2,
			pLCSiscomPro2Prim,
			&lLCSiscomPro2Act);
	(*pintPtrNumRegRes)++;
     }
   }
	AnexaRegistroNombreGrupo(
	"",
	lSCSiscomPro2,
	pLCSiscomPro2Prim,
	&lLCSiscomPro2Act,
	pintPtrNumRegRes);

  }
}
			  
void ClasificaGruposPorGrupo(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg;
LCamposSiscomPro2 *lLCSiscomPro2Grupos;
StcSisFormaRegistro lSSFormaRegGrupos;
LCamposSiscomPro2ConSubReg lLCSiscomPro2SGrupos;
int lintNumGrupos;
int lintContador;
LCamposSiscomPro2 *lLCSiscomPro2Res=0;
int lintNumRegRes=0;
lintNumGrupos=SiscomArgumentosNumeroRegistros("GimGrupos",pSAgsSiscom);
lLCSiscomPro2Grupos=SiscomArgumentoOperacionPrim("GimGrupos",pSAgsSiscom);
FormaEstructuraNmbsGrupos(lLCSiscomPro2Grupos,
			  &lSSFormaRegGrupos);
lLCSiscomPro2Reg=SiscomArgumentoOperacionPrim("GimResGrupos",pSAgsSiscom);
SiscomLeeConSubRegistros(lLCSiscomPro2Reg,
			 &lSSFormaRegGrupos,
			 &lLCSiscomPro2SGrupos);
FormaRespuestaGrupos(
	SiscomArgumentosNumeroRegistros("GimGrupos",pSAgsSiscom),
	&lLCSiscomPro2SGrupos,
	&lLCSiscomPro2Res,
	&lintNumRegRes);
SiscomAsignaArgumentoOperacionPrim("GimResGrupos",lLCSiscomPro2Res,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("GimResGrupos",lintNumRegRes,pSAgsSiscom);
}
void ObtenNombresGrupos(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2NmbsGrupos=0;
char lchrArrSQL[125];
int lintNRegRespuesta;

sprintf(lchrArrSQL,
	"select distinct grupo		\
	 from grupos			\
	 where idtipocompetencia=%s",
	 pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseDatosSinDatosConexion(
		lchrArrSQL,
		gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
		gSSiscomConfiguracionSvr.intPtoAccesoDatos,
		&lLCSiscomPro2NmbsGrupos,
		&lintNRegRespuesta);
SiscomAsignaArgumentoOperacionPrim("GimGrupos",lLCSiscomPro2NmbsGrupos,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("GimGrupos",lintNRegRespuesta,pSAgsSiscom);
}

void EnviaGrupos(SArgsSiscom *pSAgsSiscom)
{

SiscomEnviaAlServidor(
	pSAgsSiscom->intSocketCliente,
	SiscomArgumentosNumeroRegistros("GimResGrupos",pSAgsSiscom),
	"Respuesta",
	SiscomArgumentoOperacionPrim("GimResGrupos",pSAgsSiscom));
}
void AnexaRegistroNombreGrupo(const char *pchrPtrGrupo,
			      SCampoSiscomPro2 *pSCSiscomPro2Dat,
			      LCamposSiscomPro2 **pLCSiscomPro2Prim,
			      LCamposSiscomPro2 **pLCSiscomPro2Act,
			      int *pintPtrNRegistros)
{
SCampoSiscomPro2 *lSCSiscomPro2;


	SiscomCopiaCampos(pSCSiscomPro2Dat,
			  &lSCSiscomPro2);

	SiscomAsignaDatoCampo2A("grupo",pchrPtrGrupo,lSCSiscomPro2);
	SiscomCreaListaCamposPro2(lSCSiscomPro2,
				  pLCSiscomPro2Prim,
				  pLCSiscomPro2Act);
	(*pintPtrNRegistros)++;
}
				
