#include <SiscomDesarrollo2.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void SiscomTransformaImporteALetraFloat(float pfltImporte,
				   char *pchrPtrImporteALetra)
{
char lchrArrImporte[120];
sprintf(lchrArrImporte,"%.2f",pfltImporte);
SiscomTransformaImporteALetra(lchrArrImporte,pchrPtrImporteALetra);
}
void SiscomTransformaImporteALetra(const char *pchrPtrImporte,
				   char *pchrPtrImporteALetra)
{
int lintNoEnteros,
    lintNoDecimales;
int lintImporte,
    lintDecimal;
int lintEnteroDescompuesto[12];
int lintContador;
char lchrArrLetra[128];
memset(lintEnteroDescompuesto,-1,sizeof(int)*11);
*pchrPtrImporteALetra=0;
   ObtenNoEnterosImporte(pchrPtrImporte,
   			 &lintNoEnteros,
			 &lintNoDecimales,
			 &lintImporte,
			 &lintDecimal);
DescomponImporte(lintImporte,lintNoEnteros,lintEnteroDescompuesto);
for(lintContador=10;
    lintContador>=0;
    lintContador--)
if(lintEnteroDescompuesto[lintContador]!=-1)
{
ObtenLetraPosicionNumero(lintContador,
			lintEnteroDescompuesto[lintContador],
			 lchrArrLetra);
/*
SiscomLog("%d %d %s",
	  lintContador,
	  lintEnteroDescompuesto[lintContador],
	  lchrArrLetra);
*/
strcat(pchrPtrImporteALetra,lchrArrLetra);
strcat(pchrPtrImporteALetra," ");
}
strcat(pchrPtrImporteALetra,"pesos");
strcat(pchrPtrImporteALetra," ");
sprintf(lchrArrLetra,"%d/100 M.N.",lintDecimal);
strcat(pchrPtrImporteALetra,lchrArrLetra);
}

void ObtenLetraPosicionNumero(int pintPosicion,
			      int pintNumero,
			      char *pchrPtrLetra)
{
StcImporteALetra lStcArrImpLetra[]={ 
					{ "",
					  "uno",
					  "dos",
					  "tres",
					  "cuatro",
					  "cinco",
					  "seis",
					  "siete",
					  "ocho",
					  "nueve"
					 },
					 {
					  "",
					  "No Se",
					  "veinti ",
					  "treinta y",
					  "cuarenta y",
					  "cincuenta y",
					  "sesenta y",
					  "setenta y",
					  "ochenta y",
					  "noventa y"
					 },
					{
					  "",
					  "ciento",
					  "dos cientos",
					  "tres cientos",
					  "cuatro cientos",
					  "quinientos",
					  "seis cientos",
					  "sete cientos",
					  "ocho cientos",
					  "novecientos"
					 },
					 {
					  "",
					  "mil",
					  "dos mil",
					  "tres mil",
					  "cuatro mil",
					  "cinco mil",
					  "seis mil",
					  "siete mil",
					  "ocho mil",
					  "nueve mil"
					 }
				      };
strcpy(pchrPtrLetra,
	lStcArrImpLetra[pintPosicion].chrArrLetra[pintNumero]);

	

}

void ObtenNoEnterosImporte(const char *pchrPtrImporte,
			   int *pintPtrNoEnteros,
			   int *pintPtrNoDecimales,
			   int *pintPtrImporte,
			   int *pintPtrDecimal)
{
char lchrArrEnteros[25];
char lchrArrDecimales[25];
SiscomObten2CadenasPorSeparador(pchrPtrImporte,
				'.',
				lchrArrEnteros,
				lchrArrDecimales);
*pintPtrNoEnteros=strlen(lchrArrEnteros);
*pintPtrNoDecimales=strlen(lchrArrDecimales);
*pintPtrImporte=atoi(lchrArrEnteros);
*pintPtrDecimal=atoi(lchrArrDecimales);
}
			  
void DescomponImporte(int pintImporte,
		      int pintNoEnteros,
		      int *pintPtrDescompuesto)
{
int lintContador;
int lintResultado;
int lintImporte=pintImporte;
for(lintContador=pintNoEnteros-1;
    lintContador>=0;
    lintContador--)
{
/*lintResultado=lintImporte/pow10(lintContador); */
pintPtrDescompuesto[lintContador]=lintResultado;
/*SiscomLog("%d %f %d %d",lintContador,pow10(lintContador),lintResultado,lintImporte);*/
/*lintImporte-=(int )pow10(lintContador)*lintResultado; */
}


}
