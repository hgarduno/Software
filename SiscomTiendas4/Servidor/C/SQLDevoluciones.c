#include <SQLDevoluciones.h>
#include <stdlib.h>
#include <string.h>

void SQLInventarioDevolucion(SArgsSiscom *pSAgsSiscom)
{
	GeneraInsercionActualizacion(pSAgsSiscom,
				     "SQLDevolucion",
				     SQLGeneraInventarioDevolucion);
}

void SQLVentasDevolucion(SArgsSiscom *pSAgsSiscom)
{
	GeneraInsercionActualizacion(pSAgsSiscom,
				     "SQLDevolucion",
				     SQLGeneraVentasDevolucion);
}
void SQLActualizaTotalVenta(SArgsSiscom *pSAgsSiscom)
{
	GeneraInsercionActualizacion(pSAgsSiscom,
				     "SQLDevolucion",
				     SQLGeneraActualizaTotalVenta);
}
void SQLDevolucion(SArgsSiscom *pSAgsSiscom)
{
	GeneraInsercionActualizacion(pSAgsSiscom,
				       "SQLDevolucion",
				       SQLGeneraDevolucion);
}
void SQLDetalleDevolucion(SArgsSiscom *pSAgsSiscom)
{
	GeneraInsercionActualizacion(pSAgsSiscom,
				       "SQLDevolucion",
				       SQLGeneraDetalleDevolucion);
}
void SQLGeneraInventarioDevolucion(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
LCamposSiscomPro2 *lLCSiscomPro2Contador;
const char *lchrPtrIdExpendio=SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio");
char lchrArrFechaHoraHoy[25];
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoraHoy);
for(lLCSiscomPro2Contador=pLCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
sprintf(lchrArrSQL,
"update inventario set existencia=existencia+%s where idproducto=%s and idexpendio=%s;",
SiscomObtenDato(lLCSiscomPro2Contador,"Cantidad"),
SiscomObtenDato(lLCSiscomPro2Contador,"IdProducto"),
SiscomObtenDato(lLCSiscomPro2Contador,"IdExpendio"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}
void SQLGeneraVentasDevolucion(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
LCamposSiscomPro2 *lLCSiscomPro2Contador;
const char *lchrPtrIdExpendio=SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio");
char lchrArrFechaHoraHoy[25];
float lfltImpDevolucion=0.0;
float lfltImporte;
for(lLCSiscomPro2Contador=pLCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
lfltImporte=atof(SiscomObtenDato(lLCSiscomPro2Contador,"Cantidad"))*
	    atof(SiscomObtenDato(lLCSiscomPro2Contador,"Precio"));
sprintf(lchrArrSQL,
"update detalleventa set cantidad=cantidad-%s,total=total-%.2f where idproducto=%s and idVenta=%s;",
SiscomObtenDato(lLCSiscomPro2Contador,"Cantidad"),
lfltImporte,
SiscomObtenDato(lLCSiscomPro2Contador,"IdProducto"),
SiscomObtenDato(lLCSiscomPro2Contador,"IdCotizacion"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}
void SQLGeneraActualizaTotalVenta(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
LCamposSiscomPro2 *lLCSiscomPro2Contador;
const char *lchrPtrIdExpendio=SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio");
const char *lchrPtrIdVenta=SiscomObtenDato(pLCSiscomPro2Dat,"IdCotizacion");
float lfltImpDevolucion=0.0;
float lfltImporte;
for(lLCSiscomPro2Contador=pLCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
lfltImporte=atof(SiscomObtenDato(lLCSiscomPro2Contador,"Cantidad"))*
	    atof(SiscomObtenDato(lLCSiscomPro2Contador,"Precio"));
lfltImpDevolucion+=lfltImporte;
}

sprintf(lchrArrSQL,
	"update ventas set importe=importe-%.2f where idventa=%s and idexpendio=%s",
	lfltImpDevolucion,
	lchrPtrIdVenta,
	lchrPtrIdExpendio);
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");

}

void SQLGeneraDetalleDevolucion(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
LCamposSiscomPro2 *lLCSiscomPro2Contador;
const char *lchrPtrIdExpendio=SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio");
const char *lchrPtrIdVenta=SiscomObtenDato(pLCSiscomPro2Dat,"IdCotizacion");
float lfltImpDevolucion=0.0;
float lfltImporte;
for(lLCSiscomPro2Contador=pLCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"insert into DetalleDevolucion values(%s,%s,%s,%s,%s);",
	SiscomObtenDato(lLCSiscomPro2Contador,"IdDevolucion"),
	SiscomObtenDato(lLCSiscomPro2Contador,"IdProducto"),
	SiscomObtenDato(lLCSiscomPro2Contador,"Cantidad"),
	SiscomObtenDato(lLCSiscomPro2Contador,"Precio"),
	SiscomObtenDato(lLCSiscomPro2Contador,"Total"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
}

void SQLGeneraDevolucion(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros)
{
char lchrArrSQL[1024];
LCamposSiscomPro2 *lLCSiscomPro2Contador;
const char *lchrPtrIdExpendio=SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio");
const char *lchrPtrIdVenta=SiscomObtenDato(pLCSiscomPro2Dat,"IdCotizacion");
const char *lchrPtrIdDevolucion=SiscomObtenDato(pLCSiscomPro2Dat,"IdDevolucion");
char lchrArrFechaHoraHoy[25];
float lfltImpDevolucion=0.0;
float lfltImporte;
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoraHoy);
for(lLCSiscomPro2Contador=pLCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
lfltImporte=atof(SiscomObtenDato(lLCSiscomPro2Contador,"Cantidad"))*
	    atof(SiscomObtenDato(lLCSiscomPro2Contador,"Precio"));
lfltImpDevolucion+=lfltImporte;

}
sprintf(lchrArrSQL,
	"insert into Devoluciones values(%s,%s,%.2f,'%s','');",
	lchrPtrIdDevolucion,
	lchrPtrIdVenta,
	lfltImpDevolucion,
	lchrArrFechaHoraHoy);
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
