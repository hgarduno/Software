#include <Empresas.h>
#include <Personas.h>
#include <SQLEmpresas.h>
#include <SQLPersonas.h>
#include <ComunSiscomTiendas4.h>
#include <SiscomFuncionesComunes.h>
#include <stdlib.h>
#include <string.h>
SiscomOperaciones2 *OpEmpresaRegistrada()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(ArgumentosEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(NormalizaEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLConsultaEmpresaNormalizada,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLEmpresasSimilares,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EmpresaYaRegistrada,lSOpOperaciones);
return lSOpOperaciones;


}
int NoRegistrosAEnviar(SArgsSiscom *pSAgsSiscom)
{
int lintNRegRegreso;
int lintNRegPersonas;
int lintNRegDirEmpresa;
int lintNRegComEmpresa;
lintNRegPersonas=SiscomArgumentosNumeroRegistros("Personas",pSAgsSiscom);
lintNRegDirEmpresa=SiscomArgumentosNumeroRegistros("SqlDireccionesEmpresa",pSAgsSiscom);
lintNRegComEmpresa=SiscomArgumentosNumeroRegistros("SqlComunicacionEmpresa",pSAgsSiscom);

return lintNRegPersonas+
       lintNRegDirEmpresa+
       lintNRegComEmpresa+
       1;
}
void EnviaEmpresaRegistrada(SArgsSiscom *pSAgsSiscom)
{
pSAgsSiscom->LCSiscomPro2Regreso=SiscomArgumentoOperacionPrim("EmpresaEnNormalizada",pSAgsSiscom);
 SiscomSumaListas(pSAgsSiscom->LCSiscomPro2Regreso,
 		  SiscomArgumentoOperacionPrim("SqlDireccionesEmpresa",pSAgsSiscom));
 SiscomSumaListas(pSAgsSiscom->LCSiscomPro2Regreso,
 		  SiscomArgumentoOperacionPrim("Personas",pSAgsSiscom));
 SiscomSumaListas(pSAgsSiscom->LCSiscomPro2Regreso,
 		  SiscomArgumentoOperacionPrim("SqlComunicacionEmpresa",pSAgsSiscom));
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
pSAgsSiscom->intNumRegRegreso=NoRegistrosAEnviar(pSAgsSiscom);
SiscomLog("Se Enviaran %d Registros",pSAgsSiscom->intNumRegRegreso);
SiscomEnviaRegreso2(pSAgsSiscom,"EmpresaRegistrada");
}
void RespondeEmpresaNoRegistrada(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim=0,
		  *lLCSiscomPro2Act=0;
int lintNRespuesta=0;
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNRespuesta,
			"Regreso,Estado",
			"",
			"");
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      lintNRespuesta,
		      "EmpresaNoRegistrada",
		      lLCSiscomPro2Prim);
}
void AcondicionaArgumentoConsulta(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("EmpresaEnNormalizada",pSAgsSiscom);
							
pSAgsSiscom->chrPtrArgConsulta=(char **)malloc(sizeof(char *)*2);
pSAgsSiscom->chrPtrArgConsulta[0]=strdup("EmpresasRegistrada");
pSAgsSiscom->chrPtrArgConsulta[1]=(char *)SiscomObtenDato(lLCSiscomPro2Dat,"idempresa");
pSAgsSiscom->chrPtrArgConsulta[2]=0;
}
void InformacionEmpresaRegistrada(SArgsSiscom *pSAgsSiscom)
{
AcondicionaArgumentoConsulta(pSAgsSiscom);
SqlMediosComunicacionEmpresa(pSAgsSiscom);
SqlContactosEmpresa(pSAgsSiscom);
SqlDireccionesEmpresa(pSAgsSiscom);
/*
SiscomImprimeArgumento("SqlComunicacionEmpresa",pSAgsSiscom);
SiscomImprimeArgumento("SqlDireccionesEmpresa",pSAgsSiscom);
SiscomImprimeArgumento("Personas",pSAgsSiscom);
*/

}
void EmpresaYaRegistrada(SArgsSiscom *pSAgsSiscom)
{
if(LaEmpresaEstaEnNormalizados(pSAgsSiscom))
{

  InformacionEmpresaRegistrada(pSAgsSiscom); 
 EnviaEmpresaRegistrada(pSAgsSiscom);
}
else
{
RespondeEmpresaNoRegistrada(pSAgsSiscom);
}
}
void CopiaIdEmpresaArgumento(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=SiscomArgumentoOperacionPrim(
					"EmpresaEnNormalizada",
					pSAgsSiscom);
  pSAgsSiscom->chrPtrArgConsulta=(char **)malloc(sizeof(char *)*3); 
  pSAgsSiscom->chrPtrArgConsulta[0]=strdup("Consulta"); 
  pSAgsSiscom->chrPtrArgConsulta[1]=SiscomObtenDato(lLCSiscomPro2Reg,"idempresa"); 
  pSAgsSiscom->chrPtrArgConsulta[2]=0;
}
SiscomOperaciones2 *OPProveedores()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLProveedores,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPContactosProveedores()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLContactosProveedores,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPRegistraEmpresa2()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(ArgumentosEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(GeneraIdEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(AsignaIdEmpresaADirecciones,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(AsignaIdEmpresaAMediosComunicacion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(AsignaIdPersonaContactos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(CopiaContactoAPersonas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(NormalizaPersonas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(NormalizaEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraEmpresaNormalizada,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraContactoEnPersonas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraContactoEnNormalizadas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraContactoEnContactos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraComunicacionEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraDireccion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraEnClientes,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraEnProveedores,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraEmpresa2,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPRegistraEmpresa()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(GeneraIdEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(ArgumentosEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(NormalizaEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(CopiaContactoAPersonas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(NormalizaPersonas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLConsultaEmpresaNormalizada,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLEmpresasSimilares,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraEmpresaNormalizada,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLPersonaEnNormalizada,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraContactoEnPersonas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraContactoEnNormalizadas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraContactoEnContactos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraEnClientes,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraEnProveedores,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraComunicacionEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraDireccion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraEmpresa,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OpAnexaDireccion()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(ArgumentosEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLRegistraDireccion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(AnexaDireccion,lSOpOperaciones);
return lSOpOperaciones;
}
void AnexaDireccion(SArgsSiscom *pSAgsSiscom)
{
SiscomImprimeArgumento("SQLEmpresa",pSAgsSiscom);
EjecutaRegistroInformacion(pSAgsSiscom,"SQLEmpresa");
}
void ArgumentosEmpresa(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(10,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"Empresa",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"EmpresaNormalizada",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"EmpresaEnNormalizada",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(3,"EmpresaSimilar",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(4,"SQLEmpresa",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(5,"Personas",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(6,"PersonaNormalizada",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(7,"PersonaEnNormalizada",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(8,"SqlDireccionesEmpresa",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(9,"SqlComunicacionEmpresa",pSAgsSiscom);
}
void NormalizaEmpresa(SArgsSiscom *pSAgsSiscom)
{
unsigned char *lchrPtrCambia=SiscomCaracteresCambiados();
LCamposSiscomPro2 *lLCSiscomPro2EmpresaN=0;
SiscomNormalizaEmpresaPrincipalSR2(lchrPtrCambia,
		       pSAgsSiscom->LCSiscomPro2SREntrada,
		       lLCSiscomPro2EmpresaN);
SiscomAsignaArgumentoOperacionPrim("EmpresaNormalizada",
				   lLCSiscomPro2EmpresaN,
				   pSAgsSiscom);
}

void RegistraEmpresa2(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaServidorArgumento(pSAgsSiscom,"SQLEmpresa");
SiscomContenidoSubRegistrosLog(pSAgsSiscom->LCSiscomPro2SREntrada);
}
void RegistraEmpresa(SArgsSiscom *pSAgsSiscom)
{
if(!LaEmpresaEstaEnNormalizados(pSAgsSiscom))
{
SiscomMensajesLog2("Si Se puede registrar La Empresa");
/*if(!ElContactoEstaEnNormalizados(pSAgsSiscom))*/
if(1)
{
SiscomMensajesLog2("Si se puede registrar el contacto");
SiscomImprimeArgumento("SQLEmpresa",pSAgsSiscom);
EjecutaRegistroInformacion(pSAgsSiscom,"SQLEmpresa");
}
else
{
SiscomLog("El contacto Ya Esta registrado");
}

}
else
{
SiscomLog("La Empresa esta ya registrada");
}
/*
SiscomImprimeContenidoProtocolo2("",pSAgsSiscom->LCSiscomPro2Dat);
SiscomImprimeContenidoProtocolo2("",
	SiscomArgumentoOperacionPrim("SQLEmpresa",pSAgsSiscom));
SiscomImprimeContenidoProtocolo2("",
	SiscomArgumentoOperacionPrim("Personas",pSAgsSiscom));
SiscomImprimeContenidoProtocolo2("",
	SiscomArgumentoOperacionPrim("PersonaNormalizada",pSAgsSiscom));
*/
}
int LaEmpresaEstaEnNormalizados(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=SiscomArgumentoOperacionPrim(
					"EmpresaEnNormalizada",
					pSAgsSiscom);
if(lLCSiscomPro2Reg)
{
SiscomContenidoProtocolo(lLCSiscomPro2Reg);
return (int )SiscomObtenDato(lLCSiscomPro2Reg,"idempresa")[0];
}
return 0;
}
int ElContactoEstaEnNormalizados(SArgsSiscom *pSAgsSiscom)
{
return (int )SiscomArgumentoOperacionPrim(
		"PersonaEnNormalizada",
		pSAgsSiscom);
}
void AsignaIdEmpresaADirecciones(SArgsSiscom *pSAgsSiscom)
{
AsignaIdEmpresaASubRegistro(pSAgsSiscom,0);
}
void AsignaIdEmpresaAMediosComunicacion(SArgsSiscom *pSAgsSiscom)
{
AsignaIdEmpresaASubRegistro(pSAgsSiscom,1);
}
void AsignaIdPersonaContactos(SArgsSiscom *pSAgsSiscom)
{
char lchrArrIdPersona[25];
LCamposSiscomPro2 *lLCSiscomPro2Cont;
for(lLCSiscomPro2Cont=SiscomSubRegistroPrim(2,pSAgsSiscom->LCSiscomPro2SREntrada);
    lLCSiscomPro2Cont;
    lLCSiscomPro2Cont=lLCSiscomPro2Cont->SCP2PtrSig)
{
SiscomObtenNumeroUnicoChar(lchrArrIdPersona);
  SiscomAsignaDatoCampo2("IdPersona",
  			lchrArrIdPersona, 
			lLCSiscomPro2Cont);
}

}
void AsignaIdEmpresaASubRegistro(SArgsSiscom *pSAgsSiscom,
				 int pintNSubRegistro)
{
const char *lchrPtrIdEmpresa=SiscomCampoRegistroPrincipal(
				pSAgsSiscom->LCSiscomPro2SREntrada,
				"IdEmpresa");
LCamposSiscomPro2 *lLCSiscomPro2Direcciones;
lLCSiscomPro2Direcciones=SiscomSubRegistroPrim(pintNSubRegistro,
					pSAgsSiscom->LCSiscomPro2SREntrada);
for(;
    lLCSiscomPro2Direcciones;
    lLCSiscomPro2Direcciones=lLCSiscomPro2Direcciones->SCP2PtrSig)
  SiscomAsignaDatoCampo2("IdEmpresa",
  			lchrPtrIdEmpresa, 
			lLCSiscomPro2Direcciones);
}
void GeneraIdEmpresa(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2ConSubReg *lLCSiscomPro2SRDat=pSAgsSiscom->LCSiscomPro2SREntrada;
char lchrArrIdEmpresa[12];
for(;
     lLCSiscomPro2SRDat;
     lLCSiscomPro2SRDat=lLCSiscomPro2SRDat->LCSiscomPro2SRSig)
{
	    SiscomObtenNumeroUnicoChar(lchrArrIdEmpresa);
            SiscomAsignaCampoRegistroPrincipal(lLCSiscomPro2SRDat,
    				       "IdEmpresa",
				       lchrArrIdEmpresa);
}
}
void CopiaContactoAPersonas(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaInformacionArgumento("Personas",
       pSAgsSiscom,
       SiscomSubRegistroPrim(2,pSAgsSiscom->LCSiscomPro2SREntrada),
       SiscomSubRegistroAct(2,pSAgsSiscom->LCSiscomPro2SREntrada),
       0);
}

