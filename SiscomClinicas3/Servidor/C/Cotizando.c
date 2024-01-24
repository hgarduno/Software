#include <Cotizando.h>
#include <ComunClinicas3.h>
#include <SQLCotizando.h>
#include <string.h>
#include <stdlib.h>

SiscomOperaciones2 *OPVentasMedico()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLVentasMedico,lSOpOperaciones);
return lSOpOperaciones;

}
SiscomOperaciones2 *OPDatosParaCobrarConsulta()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosCotizando,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLDatosParaCobrarConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(CalculaImporteConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EnviaCotizacionClinicas,lSOpOperaciones);
return lSOpOperaciones;

}

SiscomOperaciones2 *OPCotizaConsulta()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosCotizando,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLDatosCotizaConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SumaProductosSimilares,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ActualizaCantidades,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(CotizaPerfilServicio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EnviaCotizacionClinicas,lSOpOperaciones);
return lSOpOperaciones;

}
SiscomOperaciones2 *OPCotizaPerfilMedico()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenDatosComunicacionAD,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosCotizando,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLDatosPerfilServicioMedico,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(CotizaPerfilServicio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EnviaCotizacionClinicas,lSOpOperaciones);
return lSOpOperaciones;

}

void ArgumentosCotizando(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"Cotizando",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SQLCotizando",pSAgsSiscom);
}
void ImporteConsulta(LCamposSiscomPro2 *pLCSiscomPro2Dat,
		     LCamposSiscomPro2 **pLCSiscomPro2Act,
		     char *pchrPtrImporteTotal)
{
char lchrArrImporte[12];
float lfltImporte=0.0; 
float lfltImporteTotal=0.0;
for(;
    pLCSiscomPro2Dat;
    pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
lfltImporte=atof(SiscomObtenDato(pLCSiscomPro2Dat,"importe"));
lfltImporteTotal+=lfltImporte;
sprintf(lchrArrImporte,"%.2f",lfltImporte);
SiscomAsignaDatoCampo2("importe",
			lchrArrImporte,
			pLCSiscomPro2Dat);
*pLCSiscomPro2Act=pLCSiscomPro2Dat;
}
sprintf(pchrPtrImporteTotal,
	"%.2f",
	lfltImporteTotal);


}
void CalculaImporteConsulta(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
LCamposSiscomPro2 *lLCSiscomPro2Act;
int lintNRegistros;
char lchrArrImporteTotal[12];
SiscomObtenInformacionArgumento("SQLCotizando",
				pSAgsSiscom,
				&lLCSiscomPro2Dat,
				&lLCSiscomPro2Act,
				&lintNRegistros);
ImporteConsulta(lLCSiscomPro2Dat,&lLCSiscomPro2Act,lchrArrImporteTotal);
SiscomAnexaRegistroPro2(&lLCSiscomPro2Dat,
			&lLCSiscomPro2Act,
			&lintNRegistros,
			"idservicio,		\
			 clave,			\
			 descripcion,		\
			 precio,		\
			 idprecio,		\
			 cantidad,		\
			 existencia,		\
			 tipo,			\
			 importe",
			 "",
			 "TotalServicio",
			 "",
			 "",
			 "",
			 "",
			 "",
			 "",
			 lchrArrImporteTotal);
SiscomAsignaInformacionArgumento("SQLCotizando",
				pSAgsSiscom,
				lLCSiscomPro2Dat,
				lLCSiscomPro2Act,
				lintNRegistros);
}
/*
 * Martes 26 De febrero.
 * Queretaro
 *
 * Se agrego la variable de salida pLCSiscomPro2Act
 * ya que el tratar de anexar un registro al final de
 * la consulta no es posible hacerlo, ya que se ha 
 * iniciado a 0 el dato actual del campo.
 *
 * Por esto en esta funcion que se recorre la lista
 * se decidio colocar el registro actual para poder
 * anexar el importe del servicio
 *
 */
void ImporteServicio(LCamposSiscomPro2 *pLCSiscomPro2Dat,
		     LCamposSiscomPro2 **pLCSiscomPro2Act,
		     char *pchrPtrImporteTotal)
{
char lchrArrImporte[12];
float lfltImporte=0.0; 
float lfltImporteTotal=0.0;
for(;
    pLCSiscomPro2Dat;
    pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
lfltImporte=atof(SiscomObtenDato(pLCSiscomPro2Dat,"cantidad"))*
	    atof(SiscomObtenDato(pLCSiscomPro2Dat,"precio"));
lfltImporteTotal+=lfltImporte;
sprintf(lchrArrImporte,"%.2f",lfltImporte);
SiscomAsignaDatoCampo2("importe",
			lchrArrImporte,
			pLCSiscomPro2Dat);
*pLCSiscomPro2Act=pLCSiscomPro2Dat;
}
sprintf(pchrPtrImporteTotal,
	"%.2f",
	lfltImporteTotal);
SiscomLog("Total:%s",pchrPtrImporteTotal);
}
void CotizaPerfilServicio(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
LCamposSiscomPro2 *lLCSiscomPro2Act;
int lintNRegistros;
char lchrArrImporteTotal[12];
SiscomObtenInformacionArgumento("SQLCotizando",
				pSAgsSiscom,
				&lLCSiscomPro2Dat,
				&lLCSiscomPro2Act,
				&lintNRegistros);
ImporteServicio(lLCSiscomPro2Dat,&lLCSiscomPro2Act,lchrArrImporteTotal);
SiscomAnexaRegistroPro2(&lLCSiscomPro2Dat,
			&lLCSiscomPro2Act,
			&lintNRegistros,
			"idservicio,		\
			 clave,			\
			 descripcion,		\
			 precio,		\
			 idprecio,		\
			 cantidad,		\
			 existencia,		\
			 tipo,			\
			 importe",
			 "",
			 "TotalServicio",
			 "",
			 "",
			 "",
			 "",
			 "",
			 "",
			 lchrArrImporteTotal);
SiscomAsignaInformacionArgumento("SQLCotizando",
				pSAgsSiscom,
				lLCSiscomPro2Dat,
				lLCSiscomPro2Act,
				lintNRegistros);
}

void EnviaCotizacionClinicas(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat,
                  *lLCSiscomPro2Act;
int lintNRegistros;
SiscomObtenInformacionArgumento("SQLCotizando",
				pSAgsSiscom,
				&lLCSiscomPro2Dat,
				&lLCSiscomPro2Act,
				&lintNRegistros);

SiscomEnviaAlServidor(
	pSAgsSiscom->intSocketCliente,
	lintNRegistros,
	"Cotizando",
	lLCSiscomPro2Dat);
SiscomLog("LCSiscomPro2Dat");
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomLog("SQLCotizando");
SiscomContenidoProtocolo(lLCSiscomPro2Dat);
}
void ActualizaCantidades(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
LCamposSiscomPro2 *lLCSiscomPro2Act;
LCamposSiscomPro2 *lLCSiscomPro2Datos;
LCamposSiscomPro2 *lLCSiscomPro2Contador;
int lintNRegistros;
SiscomObtenInformacionArgumento("SQLCotizando",
				pSAgsSiscom,
				&lLCSiscomPro2Dat,
				&lLCSiscomPro2Act,
				&lintNRegistros);
SiscomLog("Iniciando");
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
for(lLCSiscomPro2Datos=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Datos;
    lLCSiscomPro2Datos=lLCSiscomPro2Datos->SCP2PtrSig)
{
for(lLCSiscomPro2Contador=lLCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{
if(!strcmp(SiscomObtenDato(lLCSiscomPro2Datos,"IdSerProd"),
	   SiscomObtenDato(lLCSiscomPro2Contador,"idservicio")))
SiscomAsignaDatoCampo2("cantidad",
			SiscomObtenDato(lLCSiscomPro2Datos,"Cantidad"),
			lLCSiscomPro2Contador);

}
}
}
void SumaProductosSimilares(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
LCamposSiscomPro2 *lLCSiscomPro2Act;
LCamposSiscomPro2 *lLCSiscomPro2Datos;
LCamposSiscomPro2 *lLCSiscomPro2Contador;
int lintNRegistros;
float lfltCantidad;
char lchrArrCantidad[15];
SiscomObtenInformacionArgumento("SQLCotizando",
				pSAgsSiscom,
				&lLCSiscomPro2Dat,
				&lLCSiscomPro2Act,
				&lintNRegistros);

for(lLCSiscomPro2Datos=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Datos;
    lLCSiscomPro2Datos=lLCSiscomPro2Datos->SCP2PtrSig)
for(lLCSiscomPro2Contador=lLCSiscomPro2Datos->SCP2PtrSig;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
{

 if(!strcmp(SiscomObtenDato(lLCSiscomPro2Datos,"IdSerProd"),
 	    SiscomObtenDato(lLCSiscomPro2Contador,"IdSerProd")))
 {
   lfltCantidad=atof(SiscomObtenDato(lLCSiscomPro2Datos,"Cantidad"))+
                atof(SiscomObtenDato(lLCSiscomPro2Contador,"Cantidad"));
   sprintf(lchrArrCantidad,"%.2f",lfltCantidad);
   SiscomAsignaDatoCampo2("Cantidad",
   			  lchrArrCantidad,
			  lLCSiscomPro2Datos);
   SiscomAsignaDatoCampo2("Cantidad",
   			  lchrArrCantidad,
			  lLCSiscomPro2Contador);
 }
}
SiscomLog("Nuevas Cantidades");
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomLog("Termino");
}

