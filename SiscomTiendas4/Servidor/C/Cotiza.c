#include <Cotiza.h>
#include <stdlib.h>
#include <string.h>
#include <cups/cups.h>


#include <ComunSiscomTiendas4.h>
#include <Impresion.h>
#include <SQLCotiza.h>
#include <SQLClientes.h>
#include <ServidorGeneral.h>



/*
 *
 * Un problema que tiene este modulo, es el que que se refiere
 * al proceso de la cotizacion de los productos que se encuentran
 * en espera de ser vendidos, es decir, cuando se tiene un cliente
 * que tiene un producto, y hay en el inventario una cantidad 
 * baja, por ejemplo 2 si este cliente, hace una lista larga 
 * o pide mas informacion tardara realizarse la venta, con lo
 * que si en ese momento se realizar otra cotizacion de ese
 * producto, el sistema marcara que si hay en existencia o por
 * lo menos la existencia sufiente para poder realizar la 
 * operacion, entonces cuando algno de los clientes, realizar
 * la venta se marcara una cantidad negativa , ya que el 
 * segundo cliente tomara productos que no existen en el 
 * inventario
 *
 * Este problema se prodra arreglar si se crea una tabla
 * en la que se guarden los productos que se estan cotizando
 * y el total de existencia sea el numero de productos que 
 * existen en el inventario menos el numero total de productos
 * en proceso de cotizacion.
 *
 */
SiscomOperaciones2 *OPIdCotizacion()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(ArgumentosImpresion,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(GeneraIdCotizacion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenFechaRemision,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(NombreArchivoImpresion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlDireccionesCliente2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlNombreCliente,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(Imprime,lSOpOperaciones);
if(!strcmp(gSSiscomConfiguracionSvr.chrPtrHabilitaImpresion,"Si"))
SiscomAnexaOperacionAlArreglo2(EnviaImpresion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EnviaCotizacion,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPCotiza()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(ArgumentosCotiza,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SQLDatosProducto,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(EjecutaCotizacion,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(EnviaCotizacion,lSOpOperaciones);
return lSOpOperaciones;
}

void ObtenFechaRemision(SArgsSiscom *pSAgsSiscom)
{
char lchrArrFecha[25];
SiscomObtenFechaHoy(lchrArrFecha);
SiscomAnexaRegistroArgumento("Remision",
			     pSAgsSiscom,
			     "FechaRemision,OtroDato",
			     lchrArrFecha,
			     "Nada");
}
void ArgumentosImpresion(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(4,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"Remision",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"Direccion",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"Nombre",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(3,"ArchivoImpresion",pSAgsSiscom);
}
void ArgumentosCotiza(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"DatosCotiza",pSAgsSiscom);
}
void GeneraIdCotizacion(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2=pSAgsSiscom->LCSiscomPro2Dat;
char lchrArrIdCotizacion[12];
SiscomObtenNumeroUnicoChar(lchrArrIdCotizacion);
for(;
	lLCSiscomPro2;
    lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
SiscomAsignaDatoCampo2("IdCotizacion",lchrArrIdCotizacion,lLCSiscomPro2);
}
void EnviaCotizacion(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      pSAgsSiscom->intNRegistrosDat,
		      "Respuesta",
		      pSAgsSiscom->LCSiscomPro2Dat);
}
void CalculaCantidadImporte(
		     const char *pchrPtrCantidad,
		     const char *pchrPtrPrecio,
		     float pfltIva,
		     float *pfltPtrImporte,
		     float *pfltPtrPrecio,
		     float *pfltPtrCantidad)
{
	if(!strcmp(pchrPtrCantidad,"Calcula"))
	{
	   *pfltPtrPrecio=atof(pchrPtrPrecio);
	  *pfltPtrCantidad=(*pfltPtrImporte)/(*pfltPtrPrecio); 

	}
	else
	{
	   *pfltPtrPrecio=atof(pchrPtrPrecio)/pfltIva;
	   *pfltPtrCantidad=atof(pchrPtrCantidad);
	   *pfltPtrImporte=(*pfltPtrPrecio)*(*pfltPtrCantidad);
	 }
}
		     
void ObtenDatosParaCotizar(LCamposSiscomPro2 *pLCSiscomPro2SQL,
			   const char *pchrPtrIdProducto,
			   const char *pchrPtrCantidad,
			   float pfltIva,
			   float *pfltPtrPrecio,
			   float *pfltPtrImporte,
			   float *pfltPtrExistencia,
			   float *pfltPtrCantidad,
			   char *pchrPtrSePuedeVender,
			   char *pchrPtrEscala)
{
/* Miercoles 23 De Enero 2008
 *
 * Se requiere modificar esta rutina para
 * lograr incorporar la posibilidad de que 
 * el vendedor pueda captuarar el importe
 * del producto que se cotiza
 *
 */
	for(;
	    pLCSiscomPro2SQL;
	    pLCSiscomPro2SQL=pLCSiscomPro2SQL->SCP2PtrSig)
	{
	  if(!strcmp(SiscomObtenDato(pLCSiscomPro2SQL,"idproducto"),
	  	     pchrPtrIdProducto))
	  {
	     CalculaCantidadImporte(
	     	pchrPtrCantidad,
	     	SiscomObtenDato(pLCSiscomPro2SQL,"precio"),
		pfltIva,
	     	pfltPtrImporte,
		pfltPtrPrecio,
		pfltPtrCantidad);
	     /*
	      * Miercoles 23 de enero 2008
	      * Se modifico el modulo para lograr integrar
	      * la funcionalidad que permita que el vendedor
	      * capture el importe de un producto y se calcule
	      * la cantidad que se debe veder
	      */
	     /*
	     *pfltPtrPrecio=atof(SiscomObtenDato(pLCSiscomPro2SQL,"precio"));
	     *pfltPtrImporte=*pfltPtrPrecio*lfltCantidad;
	     */
	     *pfltPtrExistencia=atof(SiscomObtenDato(pLCSiscomPro2SQL,"existencia"));
	     strcpy(pchrPtrEscala,SiscomObtenDato(pLCSiscomPro2SQL,"cantidad"));
	     /*
	      * Miercoles 23 de abril
	      *
	      * Se agrego la valiacion de cantidad cero que 
	      * no estaba considerada.
	      *
	      * Queretaro
	      *
	      *
	      */
	     if(*pfltPtrCantidad 			&&
	        *pfltPtrExistencia>=(*pfltPtrCantidad)  &&
	        *pfltPtrPrecio>0)
	      strcpy(pchrPtrSePuedeVender,"Si");
	     else
	     strcpy(pchrPtrSePuedeVender,"No");
	     break;
	  }
	}
}
void EjecutaCotizacion(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2DatPrim,
		  *lLCSiscomPro2DatAct;
LCamposSiscomPro2 *lLCSiscomPro2Contador;
LCamposSiscomPro2 *lLCSiscomPro2Ultimo;
int lintNRegistros;
float lfltTotal=0.0;
float lfltPrecio,
      lfltImporte,
      lfltExistencia,
      lfltCantidad,
      lfltIva;
char lchrArrSePuedeVender[3];
char lchrArrEscala[10];
SiscomObtenInformacionArgumento("DatosCotiza",
				pSAgsSiscom,
				&lLCSiscomPro2DatPrim,
				&lLCSiscomPro2DatAct,
				&lintNRegistros);
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
lfltIva=!strcmp(SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"TipoOrden"),
		"Factura") ? 1.16 : 1;
for(lLCSiscomPro2Contador=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
	if(!lLCSiscomPro2Contador->SCP2PtrSig)
	lLCSiscomPro2Ultimo=lLCSiscomPro2Contador;
	/*
	 * Miercoles 23 De Enero 2008
	 * Para integrar al proceso de cotizacion la posibilidad
	 * de que el vendedor capture el importe que puede quiere
	 * de un producto determinado
	 */

	lfltImporte=atof(SiscomObtenDato(lLCSiscomPro2Contador,"Total"));
	ObtenDatosParaCotizar(lLCSiscomPro2DatPrim,
			      SiscomObtenDato(lLCSiscomPro2Contador,"IdProducto"),
			      SiscomObtenDato(lLCSiscomPro2Contador,"Cantidad"),
			      lfltIva,
			      &lfltPrecio,
			      &lfltImporte,
			      &lfltExistencia,
			      &lfltCantidad,
			      lchrArrSePuedeVender,
			      lchrArrEscala);
	 ActualizaResultados(lLCSiscomPro2Contador,
	 		     lfltPrecio,
			     lfltImporte,
			     lfltExistencia,
			     lfltCantidad,
			     lchrArrSePuedeVender,
			     lchrArrEscala);
	 lfltTotal+=lfltImporte;
	}
	ColocaImporteOrden(pSAgsSiscom,lLCSiscomPro2Ultimo,lfltTotal);

}
void ActualizaResultados(LCamposSiscomPro2 *pLCSiscomPro2,
			 float pfltPrecio,
			 float pfltImporte,
			 float pfltExistencia,
			 float pfltCantidad,
			 const char *pchrPtrSePuedeVender,
			 const char *pchrPtrEscala)
{
char lchrArrExistencia[20],
     lchrArrPrecio[20],
     lchrArrImporte[20],
     lchrArrCantidad[20];
sprintf(lchrArrExistencia,"%.2f",pfltExistencia);
sprintf(lchrArrImporte,"%.2f",pfltImporte);
sprintf(lchrArrPrecio,"%.2f",pfltPrecio);
sprintf(lchrArrCantidad,"%.2f",pfltCantidad);
	SiscomAsignaDatoCampo2(
			"Cantidad",
			lchrArrCantidad,
			pLCSiscomPro2);
	SiscomAsignaDatoCampo2(
			"Existencia",
			lchrArrExistencia,
			pLCSiscomPro2);
	SiscomAsignaDatoCampo2(
			"Precio",
			lchrArrPrecio,
			pLCSiscomPro2);
	SiscomAsignaDatoCampo2(
			"Total",
			lchrArrImporte,
			pLCSiscomPro2);
	SiscomAsignaDatoCampo2(
			"SePuedeVender",
			pchrPtrSePuedeVender,
			pLCSiscomPro2);
	SiscomAsignaDatoCampo2(
			"Escala",
			pchrPtrEscala,
		 	pLCSiscomPro2);	

SiscomContenidoProtocolo(pLCSiscomPro2);
}
void ColocaImporteOrden(SArgsSiscom *pSAgsSiscom,
			LCamposSiscomPro2 *pLCSiscomPro2Ultimo,
			float pfltImporte)
{
char lchrArrTotalOrden[12];
char lchrArrImporteSinIva[12];
char lchrArrIva[12];
float lfltImporteSinIva=pfltImporte;

if(!strcmp(SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"TipoOrden"),
	   "Factura"))
{
SiscomLog("Calculando Factura");
sprintf(lchrArrImporteSinIva,"%.2f",lfltImporteSinIva);
pfltImporte*=1.16;
sprintf(lchrArrIva,"%.2f",pfltImporte-lfltImporteSinIva);
}
else
{
sprintf(lchrArrImporteSinIva,"0.00");
sprintf(lchrArrIva,"0.00");
}

sprintf(lchrArrTotalOrden,"%.2f",pfltImporte);
SiscomAnexaRegistroPro2(
		&pSAgsSiscom->LCSiscomPro2Dat,
		&pLCSiscomPro2Ultimo,
		&pSAgsSiscom->intNRegistrosDat,
		"IdProducto,				\
		 Clave,					\
		 IdPrecio,				\
		 IdExpendio,				\
		 IdCliente,				\
		 IdEmpleado,				\
		 Cantidad,				\
		 Existencia,				\
		 Precio,				\
		 Total,					\
		 SePuedeVender,				\
		 Iva,					\
		 TotalSinIva",
	   "",
	   "TotalOrden",
	   "",
	   "",
	   "",
	   "",
	   "",
	   "",
	   "",
	   lchrArrTotalOrden,
	   "",
	   lchrArrIva,
	   lchrArrImporteSinIva);
}
void NombreArchivoImpresion(SArgsSiscom *pSAgsSiscom)
{
char lchrArrArchivo[1024];

sprintf(lchrArrArchivo,
	"%s_%s.ps",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"TipoOrden"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdCotizacion"));
SiscomAnexaRegistroArgumento("ArchivoImpresion",
			     pSAgsSiscom,
			     "Archivo,ArchivoParaCups",
			     lchrArrArchivo,
			     "");
}
void ArchivoParaCups(SArgsSiscom *pSAgsSiscom,
			    char *pchrPtrArchivo)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
if((lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("ArchivoImpresion",pSAgsSiscom)))
{
sprintf(pchrPtrArchivo,
	"%s/%s",
	gSSiscomConfiguracionSvr.chrPtrDirTrabajo,	
	SiscomObtenDato(lLCSiscomPro2Dat,"ArchivoParaCups"));
SiscomLog("%s",pchrPtrArchivo);
}
else
{
SiscomLog("NO se encontro el argumento para el nombre");
}
	

}
void EnviaImpresion(SArgsSiscom *pSAgsSiscom)
{
char lchrArrArchivo[256];
int lintNumDests;
cups_dest_t *lcupsPtrDestinos,*lcupsPtrDefault;
lintNumDests=cupsGetDests(&lcupsPtrDestinos);
if((lcupsPtrDefault=cupsGetDest(0,0,lintNumDests,lcupsPtrDestinos))) 
{
ArchivoParaCups(pSAgsSiscom,lchrArrArchivo);
cupsPrintFile(lcupsPtrDefault->name,
	      lchrArrArchivo,
		lchrArrArchivo,
		lcupsPtrDefault->num_options,
		lcupsPtrDefault->options);
}
else
SiscomLog("No se ha configurado la impresora por default");
}
