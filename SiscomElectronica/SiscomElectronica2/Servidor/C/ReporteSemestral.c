#include <ReporteSemestral.h>
#include <ComunElectronica2.h>
#include <SqlReporteSemestral.h>
#include <string.h>

SiscomOperaciones2 *OpReporteSemestral()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlReporteSemestral,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(AsignaDatosUltimaCompra,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(EnviaReporteSemestral,lSOpOperaciones2);
return lSOpOperaciones2;

}
void EliminaPuntoCantidad(const char *pchrPtrCampo,
			 LCamposSiscomPro2 *pLCSiscomPro2)
{
char *lchrPtrCantidad;
lchrPtrCantidad=(char *)SiscomObtenDato(pLCSiscomPro2,pchrPtrCampo);
SiscomEliminaCadenaDespuesCadena(".",
				 lchrPtrCantidad);
}
void AsignaDatosUltimaCompra(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBuffer[256];
char **lchrPtrRegreso;
LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Regreso;
char lchrArrUCompra[256];
while(lLCSiscomPro2Dat)
{
strcpy(lchrArrUCompra,SiscomObtenDato(lLCSiscomPro2Dat,"ultimacompra"));
EliminaPuntoCantidad("total",lLCSiscomPro2Dat);
EliminaPuntoCantidad("inventario",lLCSiscomPro2Dat);
SiscomEliminaCaracteres("()\"",lchrArrUCompra);
SiscomLog("%s",lchrArrUCompra);
if(strlen(lchrArrUCompra)>3&&
   SiscomAnalizaCadenas(lchrArrUCompra,
			',',
			lchrArrBuffer,
			&lchrPtrRegreso))
{
SiscomEliminaCadenaDespuesCadena(".",lchrPtrRegreso[1]);
SiscomAsignaDatoCampo2("fechaucompra",lchrPtrRegreso[0],lLCSiscomPro2Dat);
SiscomAsignaDatoCampo2("cantidaducompra",lchrPtrRegreso[1],lLCSiscomPro2Dat);
SiscomAsignaDatoCampo2("precioucompra",lchrPtrRegreso[2],lLCSiscomPro2Dat);
SiscomAsignaDatoCampo2("proveedor",lchrPtrRegreso[3],lLCSiscomPro2Dat);
}
lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;
}
}
void EnviaReporteSemestral(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("");
	SiscomEnviaRegreso(pSAgsSiscom);
}
