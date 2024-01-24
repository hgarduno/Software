#include <Ganancias.h>
#include <SqlGanancias.h>
#include <ComunElectronica2.h>
#include <string.h>
SiscomOperaciones2 *OpGanancia()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosGanancias,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlProductosVendidos,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(GananciaPorPeriodo,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(GananciasPorProducto,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(GananciasPorFecha,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(Ganancias,lSOpOperaciones2);


return lSOpOperaciones2;
}

void ArgumentosGanancias(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlProductosVenta",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"Ganancias",pSAgsSiscom);

}
void GananciaPorFecha(const char *pchrPtrFecha,
			 LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 SArgsSiscom *pSAgsSiscom)
{
float lfltGanancia=0.0;
float lfltTotalVenta=0.0;
float lfltVenta;
char lchrArrGanancia[25];
char lchrArrTotalVenta[25];
char lchrArrEdoGanancia[25];
for(;
	pLCSiscomPro2Dat;
    pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
lfltGanancia+=GananciaPorProducto(pLCSiscomPro2Dat,
				  lchrArrEdoGanancia,
				  &lfltVenta);
lfltTotalVenta+=lfltVenta;
}
sprintf(lchrArrTotalVenta,"%.2f",lfltTotalVenta);
sprintf(lchrArrGanancia,"%.2f",lfltGanancia);
SiscomLog("Fecha(%s) %s %s",
	   pchrPtrFecha,
	   lchrArrTotalVenta,
	   lchrArrGanancia);
SiscomAnexaRegistroArgumento(
		"Ganancias",
		pSAgsSiscom,
		"GananciaFecha,		\
		 Fecha,			\
		 TotalVentas,		\
		 Ganancia",
		 "",
		 pchrPtrFecha,
		 lchrArrTotalVenta,
		 lchrArrGanancia);
}
void GananciaDelProducto(const char *pchrPtrProducto,
			 LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 SArgsSiscom *pSAgsSiscom)
{
float lfltGanancia=0.0;
float lfltTotalVenta=0.0;
float lfltVenta;
char lchrArrGanancia[25];
char lchrArrTotalVenta[25];
char lchrArrEdoGanancia[25];
for(;
	pLCSiscomPro2Dat;
    pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
lfltGanancia+=GananciaPorProducto(pLCSiscomPro2Dat,
				  lchrArrEdoGanancia,
				  &lfltVenta);
lfltTotalVenta+=lfltVenta;
}
sprintf(lchrArrTotalVenta,"%.2f",lfltTotalVenta);
sprintf(lchrArrGanancia,"%.2f",lfltGanancia);
SiscomLog("Producto(%s) %s %s",
	   pchrPtrProducto,
	   lchrArrTotalVenta,
	   lchrArrGanancia);
SiscomAnexaRegistroArgumento(
		"Ganancias",
		pSAgsSiscom,
		"GananciaProducto,	\
		 Producto,		\
		 TotalVentas,		\
		 Ganancia",
		 "",
		 pchrPtrProducto,
		 lchrArrTotalVenta,
		 lchrArrGanancia);
}
void GananciasPorFecha(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
LCamposSiscomPro2Agrupados *lLCSiscomPro2AgrupaP;
lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("SqlProductosVenta",pSAgsSiscom);
SiscomAgrupaListaPorCampoPro2("fechahora",
			      lLCSiscomPro2Dat,
			      &lLCSiscomPro2AgrupaP);
SiscomContenidoAgrupadosPro2(lLCSiscomPro2AgrupaP);
for(;
	lLCSiscomPro2AgrupaP;
    lLCSiscomPro2AgrupaP=lLCSiscomPro2AgrupaP->LCSiscomPro2AgrupaS)
{
  GananciaPorFecha(lLCSiscomPro2AgrupaP->chrPtrCampo,
  		      lLCSiscomPro2AgrupaP->LCSiscomPro2Prim,
  		      pSAgsSiscom);
}
}
void GananciasPorProducto(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
LCamposSiscomPro2Agrupados *lLCSiscomPro2AgrupaP;
lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("SqlProductosVenta",pSAgsSiscom);
SiscomAgrupaListaPorCampoPro2("cveproducto",
			      lLCSiscomPro2Dat,
			      &lLCSiscomPro2AgrupaP);
SiscomContenidoAgrupadosPro2(lLCSiscomPro2AgrupaP);
for(;
	lLCSiscomPro2AgrupaP;
    lLCSiscomPro2AgrupaP=lLCSiscomPro2AgrupaP->LCSiscomPro2AgrupaS)
{
  GananciaDelProducto(lLCSiscomPro2AgrupaP->chrPtrCampo,
  		      lLCSiscomPro2AgrupaP->LCSiscomPro2Prim,
  		      pSAgsSiscom);
}
    
}
void Ganancias(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("");
/*SiscomImprimeArgumento("SqlProductosVenta",pSAgsSiscom); */
SiscomImprimeArgumento("Ganancias",pSAgsSiscom);
SiscomEnviaArgumentoCliente("Ganancias",pSAgsSiscom);

}
void GananciaPorPeriodo(SArgsSiscom *pSAgsSiscom)
{
float lfltGananciaTotal=0.0;
float lfltVentaTotal=0.0;
float lfltVentaProducto;
char lchrArrEdoGanancia[25];
LCamposSiscomPro2 *lLCSiscomPro2Dat;
lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("SqlProductosVenta",
					       pSAgsSiscom);
for(;
    lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
{
lfltGananciaTotal+=GananciaPorProducto(lLCSiscomPro2Dat,
				       lchrArrEdoGanancia,
				       &lfltVentaProducto);
lfltVentaTotal+=lfltVentaProducto;
}
RegresoGananciaPeriodo(lfltGananciaTotal,
		       lfltVentaTotal,
		       pSAgsSiscom);
}
float GananciaPorProducto(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			  char *pchrPtrEdoGanancia,
			  float *pfltPtrVentaProducto)
{
float lfltUltimoPrecio;
float lfltCantidad,
	lfltPrecioVenta;
lfltUltimoPrecio=SiscomObtenCampoAFloat(pLCSiscomPro2Dat,"ultimoprecio");
pchrPtrEdoGanancia[0]=0;
if(lfltUltimoPrecio==0.0)
strcpy(pchrPtrEdoGanancia,"Inventario");

lfltCantidad=SiscomObtenCampoAFloat(pLCSiscomPro2Dat,"cantidad");
lfltPrecioVenta=SiscomObtenCampoAFloat(pLCSiscomPro2Dat,"precio");
*pfltPtrVentaProducto=lfltCantidad*lfltPrecioVenta;
return *pfltPtrVentaProducto-lfltUltimoPrecio;
}

void RegresoGananciaPeriodo(float pfltGanancia,
		     float pfltTotalVentas,
		     SArgsSiscom *pSAgsSiscom)
{
char lchrArrPeriodo[50];
char lchrArrGanancia[12];
char lchrArrTotalVentas[12];
sprintf(lchrArrGanancia,"%.2f",pfltGanancia);
sprintf(lchrArrTotalVentas,"%.2f",pfltTotalVentas);
sprintf(lchrArrPeriodo,
	"%s/%s",
	pSAgsSiscom->chrPtrArgConsulta[2],
	pSAgsSiscom->chrPtrArgConsulta[3]);
SiscomAnexaRegistroArgumento("Ganancias",
			     pSAgsSiscom,
			     "Resumen,		\
			      Periodo,		\
			      Ganancia,		\
			      TotalVentas",
			      "",
			      lchrArrPeriodo,
			      lchrArrGanancia,
			      lchrArrTotalVentas);
}
