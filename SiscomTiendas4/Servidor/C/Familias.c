#include <Familias.h>
#include <SQLFamilias.h>
#include <ComunSiscomTiendas4.h>

#include <stdlib.h>
#include <string.h>
SiscomOperaciones2 *FamiliasRegistradas()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SQLFamiliasRegistradas,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OperacionesFamilias()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosFamilia,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(AsignaIdentificadorFamilia,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(CambiaMayusculasFamilia,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLRegistroFamilias,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraFamilia,lSOpOperaciones);
return lSOpOperaciones;
}

void RegistraFamilia(SArgsSiscom *pSAgsSiscom)
{
EjecutaRegistroInformacion(pSAgsSiscom,"Familias");
}
void ArgumentosFamilia(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"Familias",pSAgsSiscom);
}
void CambiaMayusculasFamilia(SArgsSiscom *pSAgsSiscom)
{
CambiaCampoProtocoloMayusculas(pSAgsSiscom->LCSiscomPro2Dat,"Familia");
}

void AsignaIdentificadorFamilia(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Contador;
char lchrArrIdFamilia[20];
for(lLCSiscomPro2Contador=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
   SiscomObtenNumeroUnicoChar(lchrArrIdFamilia);
   SiscomAsignaDatoCampo2("IdFamilia",lchrArrIdFamilia,lLCSiscomPro2Contador);
}
}
