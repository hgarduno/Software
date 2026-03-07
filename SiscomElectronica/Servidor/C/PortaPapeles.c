#include <PortaPapeles.h>



#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>
#include <stdlib.h>

void ClienteSiscomPortaPapeles(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{

SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
/*SiscomOperacionErrores lSiscomOpDatError={0,NoSeRegistraNoAlcanza,0}; */
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(EnviaClienteSiscomPortaPapeles,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int EnviaClienteSiscomPortaPapeles(SiscomOperaciones *pSiscomOpePtrDato)
{
AnalizandoCadenaPortaPapeles(pSiscomOpePtrDato);
return 0;
}

int SeparaCadenaPortaPapeles(const char *pchrPtrCadena,
			      char ***pchrPtrCadenas)
{
char lchrArrBuffer[512];
int lintCadenas;
if((lintCadenas=SiscomAnalizaCadenas(pchrPtrCadena,'\n',lchrArrBuffer,pchrPtrCadenas)))
{
SiscomImprimeCadenas(*pchrPtrCadenas);
}

return lintCadenas==2 ? 1 : 0 ;
}
const char *SaltaCodigoPais(const char *pchrPtrTelefono)
{
int lintContador=0;
    
     while(*pchrPtrTelefono && lintContador<2)
     {
     if(*pchrPtrTelefono==' ')
     lintContador++;
     pchrPtrTelefono++;
     }
return pchrPtrTelefono;
}
const char *ObtenNumeroTelefonico(const char *pchrPtrCadena)
{
const char *lchrPtrTelefono;
lchrPtrTelefono=SaltaCodigoPais(pchrPtrCadena);
SiscomCambiaCaracter(' ','-',(char *)pchrPtrCadena);
return lchrPtrTelefono;
}
void AnalizandoCadenaPortaPapeles(SiscomOperaciones *pSisOpePtrDatos)
{
int lintDondeElTelefono;
const char *lchrPtrTelefono;
char **lchrPtrCadenas;
const char *lchrPtrCadena=SiscomCampoAsociadoEntradaOperacion("Envio",
							      "PortaPapeles",
							      pSisOpePtrDatos);
lintDondeElTelefono=SeparaCadenaPortaPapeles(lchrPtrCadena,&lchrPtrCadenas);
lchrPtrTelefono=ObtenNumeroTelefonico(*(lchrPtrCadenas+lintDondeElTelefono));
EnviaRespuestaPortaPapeles(pSisOpePtrDatos,lchrPtrTelefono);

}
void EnviaRespuestaPortaPapeles(SiscomOperaciones *pSisOpePtrDatos,
				    const char *pchrPtrTelefono)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrResPrim=0,
		   *lSisRegProLPtrResAct=0;
SiscomAnexaRegistroPro(&lSisRegProLPtrResPrim,
		       &lSisRegProLPtrResAct,
		       lchrArrBuffer,
		       "Celular,"
		       "Alumno,",
		       pchrPtrTelefono,
		       0);
SiscomEnviaRegistrosSocket(pSisOpePtrDatos->intSocket,
			  lchrArrBuffer,
			  lSisRegProLPtrResPrim);
}
