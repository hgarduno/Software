#include <BusquedaProductos.h>
#include<ComunSiscomTiendas4.h>
#include <SqlBusquedaProductos.h>
#include <stdlib.h>
#include <string.h>

SiscomOperaciones2 *OpProductosPorAproximacion()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(ArgumentosBusquedas,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SeleccionaConsulta,lSOpOperaciones); 
/*
 * Debido a que cada consulta genera, en un espacio diferente su
 * respuesta, se procedio a enviar el resultado en la funcion donde
 * se generan
SiscomAnexaOperacionAlArreglo2(EnviaResultadosBusqueda,lSOpOperaciones); 
*/
return lSOpOperaciones;
}



void EnviaResultadosBusqueda(SArgsSiscom *pSAgsSiscom)
{
}

SiscomOperaciones2 AnalizaTextoBusqueda(const char *pchrPtrTexto)
{
/*
 * En este punto se debera formular un mecanismo para
 * poder realizar las busquedas mediante comodines, 
 * RES* que busque todo lo que inicie con RES *RES*
 * todo lo que tenga RES no importa si es es al inicio
 * o al final
 * ....
 *
 */
	SiscomLog("Analizando:%s",pchrPtrTexto);

	return SqlBusquedaPorAproximacionClave;
}
void SiscomBuscaRegistrosEnLista(const char *pchrPtrCampo,
				 const char *pchrPtrTexto,
				 LCamposSiscomPro2 *pLCSiscomPro2Dat,
				 LCamposSiscomPro2 **pLCSiscomPro2Reg,
				 int *pintPtrNRegreso)
{
char lchrArrTextoM[128];
char lchrArrDescripcion[1024];
LCamposSiscomPro2 *lLCSiscomPro2DatActual=0;
unsigned char *lchrPtrCambia=SiscomCaracteresCambiados();
unsigned char *lchrPtrDscNormalizada;
*pintPtrNRegreso=0;
*pLCSiscomPro2Reg=0;
strcpy(lchrArrTextoM,pchrPtrTexto);
SiscomCambiaMayusculas(lchrArrTextoM);
for(;
     pLCSiscomPro2Dat;
     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
{
	SiscomNormaliza2(SiscomObtenDato(pLCSiscomPro2Dat,"dsc"),
			lchrPtrCambia,
			&lchrPtrDscNormalizada);
	if(strstr(lchrPtrDscNormalizada,lchrArrTextoM))
	{
	  SiscomCreaListaCamposPro2(pLCSiscomPro2Dat->SCSiscomPro2,
	  			    pLCSiscomPro2Reg,
				    &lLCSiscomPro2DatActual);
	  (*pintPtrNRegreso)++;
	}
	free(lchrPtrDscNormalizada);

}
}

				 
void SeleccionaConsulta(SArgsSiscom *pSAgsSiscom)
{
SiscomOperaciones2 lSisOp2Consulta;

     lSisOp2Consulta=AnalizaTextoBusqueda(pSAgsSiscom->chrPtrArgConsulta[1]); 
     lSisOp2Consulta(pSAgsSiscom);
     if(!SiscomArgumentoOperacionPrim("Productos",pSAgsSiscom))
     {
	 SiscomLog("No hay claves similares, se busca en la descripcion");
	 SqlTodosLosProductos(pSAgsSiscom);
	 BuscaEnLasDescripciones(pSAgsSiscom);
     }
     else
     SiscomEnviaArgumentoCliente("Productos",pSAgsSiscom);


}
void BuscaEnLasDescripciones(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCamposSiscomPro2Dat;
int lintNRegistros;
SiscomBuscaRegistrosEnLista(
		"dsc",
		pSAgsSiscom->chrPtrArgConsulta[1],
		SiscomArgumentoOperacionPrim("Productos",pSAgsSiscom),
		&lLCamposSiscomPro2Dat,
		&lintNRegistros);
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      lintNRegistros,
		      "Respuesta",
		      lLCamposSiscomPro2Dat);
}
SiscomOperaciones2 BusquedaPorAproximacionClave(const char*pchrPtrTexto)
{

}
int ElTextoContieneComodines(const char *pchrPtrTexto)
{
	while(*pchrPtrTexto)
	{

	   pchrPtrTexto++;
	}
}

void ArgumentosBusquedas(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"Productos",pSAgsSiscom);
}
