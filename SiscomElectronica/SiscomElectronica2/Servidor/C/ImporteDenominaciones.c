#include <ImporteDenominaciones.h>
#include <stdlib.h>
SiscomOperaciones2 *OpImporteDenominacion()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(CalculaImporteDenominacion,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(EnviaCalculoImporteDenominacion,lSOpOperaciones2);

return lSOpOperaciones2;
}
/*
void SiscomRestaCamposAB_R(const char *pchrPtrCampoA,
		      const char *pchrPtrCampoB,
		      const char *pchrPtrCampoRes,
		      LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
float lfltCampoA=atof(SiscomObtenDato(pLCSiscomPro2Dat,pchrPtrCampoA));
float lfltCampoB=atof(SiscomObtenDato(pLCSiscomPro2Dat,pchrPtrCampoB));
char lchrArrResultado[12];
sprintf(lchrArrResultado,
	"%.2f",
	lfltCampoA-lfltCampoB);
SiscomAsignaDatoCampo2(pchrPtrCampoRes,lchrArrResultado,pLCSiscomPro2Dat);
}

*/
void CalculaImporteDenominacion(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
LCamposSiscomPro2 *lLCSiscomPro2Ultimo;
int lintContador=0;
float lfltTotal=0;
char lchrArrTotal[12];
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
for(lintContador=0;
    lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig,
    lintContador++)
{
	ImporteDenominacion(lLCSiscomPro2Dat);
	lfltTotal+=atof(SiscomObtenDato(lLCSiscomPro2Dat,"Importe"));
	lLCSiscomPro2Ultimo=lLCSiscomPro2Dat;
}

sprintf(lchrArrTotal,"%.2f",lfltTotal);
SiscomAsignaDatoCampo2("Total",lchrArrTotal,lLCSiscomPro2Ultimo);
pSAgsSiscom->LCSiscomPro2Regreso=pSAgsSiscom->LCSiscomPro2Dat;
pSAgsSiscom->intNumRegRegreso=lintContador;
SiscomRestaCamposAB_R("ImporteActualCaja",
		      "Total",
		      "RestoEnCaja",
		      lLCSiscomPro2Ultimo);
}
void ImporteDenominacion(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
int lintDenominacion;
int lintCantidad;
char lchrArrImporte[12];
	lintDenominacion=atoi(SiscomObtenDato(pLCSiscomPro2Dat,"Denominacion"));
	lintCantidad=atoi(SiscomObtenDato(pLCSiscomPro2Dat,"Cantidad"));
sprintf(lchrArrImporte,
	"%d",
	lintDenominacion*lintCantidad);
SiscomAsignaDatoCampo2("Importe",lchrArrImporte,pLCSiscomPro2Dat);
}
void EnviaCalculoImporteDenominacion(SArgsSiscom *pSAgsSiscom)
{
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
SiscomEnviaRegreso(pSAgsSiscom); 
}
