#include <PromocionesElectronica.h>
#include <ComunElectronica2.h>
#include <SqlPromocionesElectronica.h>

#include <stdlib.h>
#include <string.h>
SiscomOperaciones2 *OpRegistraPromocion()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*120);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosPromocion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(GeneraIdPromocion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraPromocion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraPromocion,lSOpOperaciones);
return lSOpOperaciones;
}


void RegistraPromocion(SArgsSiscom *pSAgsSiscom)
{
/*
SiscomEnviaServidorArgumento(pSAgsSiscom,"SqlPromocion");
*/
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegistrosReg;
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SqlPromocion",
				 &lLCSiscomPro2Reg,
				 &lintNRegistrosReg);
ValidaEdoRegistro(pSAgsSiscom);
}
void ValidaEdoRegistro(SArgsSiscom *pSAgsSiscom)
{
const char *lchrPtrEdoSql=SiscomObtenCampoArgumento("SqlPromocion",
						    "EdoRegistro",
						    pSAgsSiscom);
SiscomImprimeArgumento("SqlPromocion",pSAgsSiscom);
if(lchrPtrEdoSql &&
   *lchrPtrEdoSql)
{
 if(strstr(lchrPtrEdoSql,"duplicate key value violates unique constraint"))
 {
    
 }
}
else
{
  lchrPtrEdoSql=0;
}
EnviaEdoRegistroCliente(pSAgsSiscom,lchrPtrEdoSql);
}
void EnviaEdoRegistroCliente(SArgsSiscom *pSAgsSiscom,
			     const char *pchrPtrEdoSql)
{
LCamposSiscomPro2 *lLCSiscomPro2RegAct=0;

pSAgsSiscom->LCSiscomPro2Regreso=0;
pSAgsSiscom->intNumRegRegreso=0;
if(!pchrPtrEdoSql)
SiscomAnexaRegistroPro2(&pSAgsSiscom->LCSiscomPro2Regreso,
			&lLCSiscomPro2RegAct,
			&pSAgsSiscom->intNumRegRegreso,
			"NoError,MsgError",
			"0",
			"");
else
SiscomAnexaRegistroPro2(&pSAgsSiscom->LCSiscomPro2Regreso,
			&lLCSiscomPro2RegAct,
			&pSAgsSiscom->intNumRegRegreso,
			"NoError,MsgError",
			"1",
			"Promocion Ya Registrada");
SiscomLog("---------------");
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
SiscomEnviaRegreso(pSAgsSiscom);
}
void ArgumentosPromocion(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlPromocion",pSAgsSiscom);
}
void GeneraIdPromocion(SArgsSiscom *pSAgsSiscom)
{
 SiscomGeneraIdRegistro(pSAgsSiscom,"IdPromocion");
}
