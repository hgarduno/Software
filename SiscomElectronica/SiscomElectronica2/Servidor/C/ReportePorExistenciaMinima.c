#include <ReportePorExistenciaMinima.h>
#include <ComunElectronica2.h>
#include <SqlReportePorExistenciaMinima.h>
#include <string.h>

SiscomOperaciones2 *OpProductosPorcentajeExMinima()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(155,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosVentas,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(FechasSemestreAnterior,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(FechasSemestreActual,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ObtenFechaActual,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlProductosPorcentajeExMinima,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlVentasSemestreAnterior,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlVentasSemestreActual,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(AsignaInformacionUltimaCompra,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(AsignaVentasSemAnterior,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(AsignaVentasActuales,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(EnviaReportePorExistenciaMinima,lSOpOperaciones2);
return lSOpOperaciones2;

}
SiscomOperaciones2 *OpReportePorExistenciaMinima()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(155,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(FechasSemestreAnterior,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(FechasSemestreActual,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ObtenFechaActual,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlReportePorExistenciaMinima,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(AsignaInformacionUltimaCompra,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(EnviaReportePorExistenciaMinima,lSOpOperaciones2);
return lSOpOperaciones2;
}


void EnviaReportePorExistenciaMinima(SArgsSiscom *pSArgSiscom)
{
SiscomContenidoProtocolo(pSArgSiscom->LCSiscomPro2Regreso);
SiscomEnviaRegreso(pSArgSiscom);
}


void FechasSemestreActual(SArgsSiscom *pSArgsSiscom)
{
char lchrArrFechaIni[15],
     lchrArrFechaFin[15];
SemestreActual(lchrArrFechaIni,lchrArrFechaFin);
SiscomAnexaArgumentoConsulta(lchrArrFechaIni,pSArgsSiscom);
SiscomAnexaArgumentoConsulta(lchrArrFechaFin,pSArgsSiscom);
SiscomImprimeArgumentosConsulta(pSArgsSiscom);
}
void FechasSemestreAnterior(SArgsSiscom *pSArgsSiscom)
{
char lchrArrFechaIni[15],
     lchrArrFechaFin[15];
SiscomImprimeArgumentosConsulta(pSArgsSiscom);
SemestreAnterior(lchrArrFechaIni,lchrArrFechaFin);
SiscomAnexaArgumentoConsulta(lchrArrFechaIni,pSArgsSiscom);
SiscomAnexaArgumentoConsulta(lchrArrFechaFin,pSArgsSiscom);
SiscomImprimeArgumentosConsulta(pSArgsSiscom);
}
void ObtenFechaActual(SArgsSiscom *pSAgsSiscom)
{
char lchrArrFechaHoy[15];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFechaHoy);
SiscomAnexaArgumentoConsulta(lchrArrFechaHoy,pSAgsSiscom);
}
void DatosUltimaCompra(LCamposSiscomPro2 *pLCSiscomPro2Dat,
		       char *pchrPtrFecha,
		       char *pchrPtrCantidad,
		       char *pchrPtrPrecio,
		       char *pchrPtrProveedor)
{
char **lchrPtrCadenas;
char lchrArrBuffer[512];
char lchrArrUltimaCompra[256];
strcpy(lchrArrUltimaCompra,SiscomObtenDato(pLCSiscomPro2Dat,"ultimacompra"));
SiscomEliminaCaracteres("()\"",lchrArrUltimaCompra);
/*
SiscomLog("%s",lchrArrUltimaCompra);
*/
*pchrPtrFecha=*pchrPtrCantidad=*pchrPtrPrecio=*pchrPtrProveedor=0;
if(strcmp(lchrArrUltimaCompra,",,,") &&
   SiscomAnalizaCadenas(lchrArrUltimaCompra,
			',',
			lchrArrBuffer,
			&lchrPtrCadenas))
{
   strcpy(pchrPtrFecha,lchrPtrCadenas[0]);
   strcpy(pchrPtrCantidad,lchrPtrCadenas[1]);
   strcpy(pchrPtrPrecio,lchrPtrCadenas[2]);
   strcpy(pchrPtrProveedor,lchrPtrCadenas[3]);

}

}
void AsignaInformacionUltimaCompra(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Regreso;
char lchrArrFecha[25],
     lchrArrCantidad[20],
     lchrArrPrecio[20],
     lchrArrProveedor[256];
while(lLCSiscomPro2Dat)
{
DatosUltimaCompra(lLCSiscomPro2Dat,
		  lchrArrFecha,
		  lchrArrCantidad,
		  lchrArrPrecio,
		  lchrArrProveedor);
SiscomAsignaDatoCampo2("fechaultimacompra",lchrArrFecha,lLCSiscomPro2Dat);
SiscomAsignaDatoCampo2("cantidadultimacompra",lchrArrCantidad,lLCSiscomPro2Dat);
SiscomAsignaDatoCampo2("precioultimacompra",lchrArrPrecio,lLCSiscomPro2Dat);
SiscomAsignaDatoCampo2("proveedor",lchrArrProveedor,lLCSiscomPro2Dat);
lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;
}

}



void ArgumentosVentas(SArgsSiscom *pSAgsSiscom)
{
   SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
   SiscomIniciaMemoriaArgumentoOperacion(0,"SqlVentasSemAnterior",pSAgsSiscom);
   SiscomIniciaMemoriaArgumentoOperacion(1,"SqlVentasActuales",pSAgsSiscom);
}

void AsignaVentasSemAnterior(SArgsSiscom *pSAgsSiscom)
{
SiscomImprimeArgumento("SqlVentasSemAnterior",pSAgsSiscom);
AsignaVentas("ventsemestreanterior",
	     "SqlVentasSemAnterior",
	     pSAgsSiscom);
}
void AsignaVentasActuales(SArgsSiscom *pSAgsSiscom)
{
SiscomImprimeArgumento("SqlVentasActuales",pSAgsSiscom);

AsignaVentas("ventactuales",
	     "SqlVentasActuales",
	     pSAgsSiscom);
}


int ObtenVentas(LCamposSiscomPro2 *pLCSiscomPro2Prod,
                LCamposSiscomPro2 *pLCSiscomPro2Dat,
		 char *pchrPtrVentas)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=pLCSiscomPro2Dat;
const  char *lchrPtrCveProducto;
const char *lchrPtrCveEntrada;
lchrPtrCveEntrada=SiscomObtenDato(pLCSiscomPro2Prod,"cveproducto");
		while(lLCSiscomPro2Dat)
		{
		   lchrPtrCveProducto=SiscomObtenDato(lLCSiscomPro2Dat,"cveproducto");
		   if(!strcmp(lchrPtrCveEntrada,lchrPtrCveProducto))
		   {
		       strcpy(pchrPtrVentas,SiscomObtenDato(lLCSiscomPro2Dat,"ventas"));
		       return 1;
		   }
		   lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;
		}
  return 0;
}

void AsignaVentas(const char *pchrPtrColumna,
		  const char *pchrPtrArgumento,
		  SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Regreso;
char lchrArrVentas[25];
   while(lLCSiscomPro2Dat)
   {
	if(ObtenVentas(lLCSiscomPro2Dat,
		       SiscomArgumentoOperacionPrim(pchrPtrArgumento,pSAgsSiscom),
		       lchrArrVentas))
	 SiscomAsignaDatoCampo2(pchrPtrColumna,lchrArrVentas,lLCSiscomPro2Dat);

      lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;

   }
}
