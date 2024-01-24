#include <OrdenesFavoritas.h>
#include <SqlOrdenesFavoritas.h>
#include <ComunSiscomElectronica4.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomMacrosInsercionesSql.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>
#include <string.h>

void RegistraOrdenesFavoritas(int pintSocket,
                             SiscomRegistroProL *pSiscomRegProLPtrPrim,
                             SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
                           0,
                           (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
                           (SiscomRegistroProL *)pSiscomRegProLPtrAct,
                           &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(AgregaArgumentosOrdenesFavoritas,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraOrdenesFavoritas,&lSiscomProDat);
SiscomAgregaOperacion(RegistrandoOrdenesFavoritas,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void EliminaOrdenesFavoritas(int pintSocket,
                             SiscomRegistroProL *pSiscomRegProLPtrPrim,
                             SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
                           0,
                           (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
                           (SiscomRegistroProL *)pSiscomRegProLPtrAct,
                           &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(AgregaArgumentosOrdenesFavoritas,&lSiscomProDat);
SiscomAgregaOperacion(SqlEliminaOrdenesFavoritas,&lSiscomProDat);
SiscomAgregaOperacion(RegistrandoOrdenesFavoritas,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void ConsultaOrdenesFavoritas(int pintSocket,
                             SiscomRegistroProL *pSiscomRegProLPtrPrim,
                             SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
                           0,
                           (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
                           (SiscomRegistroProL *)pSiscomRegProLPtrAct,
                           &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlOrdenesFavoritasRegistradas,&lSiscomProDat);
SiscomAgregaOperacion(EnviaOrdenesFavoritas,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int RegistrandoOrdenesFavoritas(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
return 0;
}
int EnviaOrdenesFavoritas(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
return 0;
}

int AgregaArgumentosOrdenesFavoritas(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlOrdenFavorita",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}
