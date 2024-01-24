#include <Devoluciones.h>
#include <ComunElectronica2.h>
#include <SqlDevoluciones.h>
SiscomOperaciones2 *OpEjecutaDevolucion()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosDevolucion,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlEliminaProductosVenta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlActualizaVentaCaja,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlActualizaExistencia,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlActualizaImporteOrden,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(EjecutaDevolucion,lSOpOperaciones2);
return lSOpOperaciones2;
}
SiscomOperaciones2 *OpCalculaDevolucion()
{
SiscomOperaciones2 *lSOpOperaciones2;

SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(CalculaDevolucion,lSOpOperaciones2);
return lSOpOperaciones2;
}
void EjecutaDevolucion(SArgsSiscom *pSAgsSiscom)
{
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomImprimeArgumento("SqlDevoluciones",pSAgsSiscom);
SiscomEnviaServidorArgumento(pSAgsSiscom,"SqlDevoluciones");
}

void ArgumentosDevolucion(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlDevoluciones",pSAgsSiscom);
}
void CalculaDevolucion(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
float lfltSuma=0.0;
char lchrArrSuma[12];
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
for(;
    lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
{
lfltSuma+=SiscomObtenCampoAFloat(lLCSiscomPro2Dat,"Cantidad")*
	  SiscomObtenCampoAFloat(lLCSiscomPro2Dat,"Precio");
sprintf(lchrArrSuma,"%.2f",lfltSuma);
SiscomAnexaRegistroRegreso(pSAgsSiscom,
			   "TotalADevolver,	\
			    CveProducto,	\
			    Cantidad,		\
			    IdExpendio,		\
			    IdVenta,		\
			    IdCaja",
			    lchrArrSuma,
			    SiscomObtenDato(lLCSiscomPro2Dat,"CveProducto"),
			    SiscomObtenDato(lLCSiscomPro2Dat,"Cantidad"),
			    SiscomObtenDato(lLCSiscomPro2Dat,"IdExpendio"),
			    SiscomObtenDato(lLCSiscomPro2Dat,"IdPractica"),
			    SiscomObtenDato(lLCSiscomPro2Dat,"IdCaja"));
}
SiscomEnviaRegreso(pSAgsSiscom);
SiscomLog("El Importe A Devolver:%f",lfltSuma);
}
