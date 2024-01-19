#include <SiscomFuncionesComunes.h>
#include <SiscomDesarrolloMacros.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void SiscomFechaLocal(char *pchrPtrFecha)
{
time_t ltimeRegreso;
char *lchrPtrRegreso;
        ltimeRegreso=time(0);
        lchrPtrRegreso=ctime(&ltimeRegreso);
      while(*lchrPtrRegreso)
      {
	*pchrPtrFecha=*lchrPtrRegreso;
	pchrPtrFecha++;
	lchrPtrRegreso++;
      }
      *(--pchrPtrFecha)=0;
}

int SiscomLeeLineaArchivo(FILE *pFlePtrArchivo,
			  char *pchrPtrLinea)
{
int lintRegreso;
	while((lintRegreso=(*pchrPtrLinea=getc(pFlePtrArchivo)))!=(char )EOF &&
	      *pchrPtrLinea!='\n')
	   pchrPtrLinea++;
   *pchrPtrLinea=0;
   return lintRegreso;
}


unsigned char *MasDeUnGuionConsecutivo(char pchrCaracter,
				       unsigned char *pchrPtrEntrada)
{
     pchrPtrEntrada++;
     while(*pchrPtrEntrada==pchrCaracter)
     pchrPtrEntrada++;
     return pchrPtrEntrada;

}
void SiscomEliminaMasDeUnCaracterConsecutivo(
					char pchrCaracter,
					unsigned char *pchrPtrEntrada,
				    	unsigned char *pchrPtrBuffer)
{
    while(*pchrPtrEntrada)
    {
      *pchrPtrBuffer=*pchrPtrEntrada;
      if(*pchrPtrEntrada==pchrCaracter)
       pchrPtrEntrada=MasDeUnGuionConsecutivo(pchrCaracter,pchrPtrEntrada);
       else
      pchrPtrEntrada++;
      pchrPtrBuffer++;
    }
    *pchrPtrBuffer=0;
}
void SiscomEliminaMasDeUnCaracterConsecutivo2(char pchrCaracter,
					      unsigned char *pchrPtrEntrada)
{


}
void SiscomEliminaCaracterInicio(char pchrCaracter,
				 unsigned char *pchrPtrEntrada)
{
}
void SiscomEliminaCaracterCadena(char pchrCaracter,
				 char *pchrPtrCadena,
				 char *pchrPtrBuffer)
{
short int lintOcurrencias=0;
	while(*pchrPtrCadena)
	{
	    if(*pchrPtrCadena==pchrCaracter)
	    {
	     pchrPtrCadena++;
	     lintOcurrencias++;
	    }
	    else
	    {
	 	*pchrPtrBuffer=*pchrPtrCadena;
		pchrPtrBuffer++;
		pchrPtrCadena++;

	    }

	}
*(pchrPtrBuffer)=0;
}

const char *SiscomObtenDatoValido(const char *pchrPtrDato)
{
return pchrPtrDato ? pchrPtrDato : "";
}



int SiscomEjecutaComando(const char *pchrPtrComando,char ***pchrPtrSalida)
{
FILE *lFlePtrSalida;
char lchrArrLinea[1024];
int lintLineas=1;
if((lFlePtrSalida=popen(pchrPtrComando,"r")))
  while(SiscomLeeLineaArchivo(lFlePtrSalida,lchrArrLinea)!=(char )EOF)
  {
      if(pchrPtrSalida)
      SiscomAgregaCadenaArreglo(lintLineas,lchrArrLinea,pchrPtrSalida);
      lintLineas++;
  }
pclose(lFlePtrSalida);
return lintLineas;
}

void SiscomAgregaCadenaArreglo(int pintNCadenas,
			       char *pchrPtrCadena,
			       char ***pchrPtrArreglo)
{

if(pintNCadenas==1)
   *pchrPtrArreglo=(char **)malloc(sizeof(char *)*2);
else
*pchrPtrArreglo=(char **)realloc(*pchrPtrArreglo,sizeof(char *)*(pintNCadenas+1));
*((*pchrPtrArreglo)+pintNCadenas-1)=strdup(pchrPtrCadena);
*((*pchrPtrArreglo)+pintNCadenas)=0;
}

void SiscomCambiaCaracter(char pchrCaracter,
			  char pchrPorCaracter,
			  char *pchrPtrCadena)
{
   while(*pchrPtrCadena)
   {
     if(*pchrPtrCadena==pchrCaracter)
	*pchrPtrCadena=pchrPorCaracter;
     pchrPtrCadena++;
   }
}

void SiscomCadenasLog(const char *pchrPtrArchivo,
		      const char *pchrPtrFuncion,
		      int pintNLinea,
		      char **pchrPtrCadenas)
{
int lintContador=0;
while(*pchrPtrCadenas)
{
  SiscomMensajesLog4(pchrPtrArchivo,
  		    pchrPtrFuncion,
		    pintNLinea,
		    "%d.- %s (%d)",
		    lintContador,
		    *pchrPtrCadenas,
		    strlen(*pchrPtrCadenas));
  lintContador++;
  pchrPtrCadenas++;
}
}

FILE *SiscomEscribeLineaArchivo(const char *pchrPtrArchivo,
			  FILE *pFlePtrArchivo,
			  const char *pchrPtrLinea)
{
   if(!pFlePtrArchivo)
   {
      if((pFlePtrArchivo=fopen(pchrPtrArchivo,"w")))
      {
	fprintf(pFlePtrArchivo,"%s",pchrPtrLinea);
	return pFlePtrArchivo;
      }
      else
	LogSiscom("NO Se pudo abrir el archivo:%s",pchrPtrArchivo);
   }
return 0;
}


void SiscomAMayusculas(char *pchrPtrCadena)
{
	while(*pchrPtrCadena)
	{
		*pchrPtrCadena=toupper(*pchrPtrCadena);
		*pchrPtrCadena++;
	}
}


void SiscomObtenNumeroUnicoChar(char *pchrPtrUnico)
{
static int lintContador=0;
	sprintf(pchrPtrUnico,
		"%ld",
		SiscomObtenNumeroUnico()+lintContador);
	lintContador++;
}
long SiscomObtenNumeroUnico()
{
/*
struct timeb ltmbFechaH;
        ftime(&ltmbFechaH);
	return ltmbFechaH.millitm+ltmbFechaH.time;;
*/
struct timeval ltRegreso;
gettimeofday(&ltRegreso,0);
return ltRegreso.tv_sec+ltRegreso.tv_usec;
}




void SiscomObtenHoraActualChar(char *pchrPtrHora)
{
int lintHora,
    lintMinuto,
    lintSegundo;
        SiscomObtenHoraActual(&lintHora,
                              &lintMinuto,
                              &lintSegundo);
        sprintf(pchrPtrHora,
                "%02d:%02d:%02d",
                lintHora,
                lintMinuto,
                lintSegundo);
                       

}
void SiscomObtenHoraActual(int *pintPtrHora,
                           int *pintPtrMinuto,
                           int *pintPtrSegundo)
{
time_t regTime,lregTime;
struct tm *stctm;
regTime=time(&lregTime);
stctm=localtime(&lregTime);

        *pintPtrHora=stctm->tm_hour;
        *pintPtrMinuto=stctm->tm_min;
        *pintPtrSegundo=stctm->tm_sec;
}
void SiscomObtenFechaHoraActualAAAADDMM(char *pchrPtrFechaConHora)
{
char lchrArrFecha[25],
     lchrArrHora[20];
        SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
        SiscomObtenHoraActualChar(lchrArrHora);
        sprintf(pchrPtrFechaConHora,
                "%sT%s",
                lchrArrFecha,
                lchrArrHora);
}
void SiscomObtenFechaHoyCharAAAADDMM(char *pchrPtrFecha)
{
int lintAno,
    lintMes,
    lintDia;
        SiscomObtenFechaHoyINT(&lintDia,
                               &lintMes,
                               &lintAno);
        sprintf(pchrPtrFecha,"%04d-%02d-%02d",lintAno,lintMes,lintDia);
}

int SiscomObtenFechaHoyINT(int *pintPtrDia,
                           int *pintPtrMes,
                           int *pintPtrAno)
{
time_t regTime,lregTime;
struct tm *stctm;
regTime=time(&lregTime); 
stctm=localtime(&lregTime);
*pintPtrDia=stctm->tm_mday;
*pintPtrMes=stctm->tm_mon+1;
*pintPtrAno=stctm->tm_year+1900;
}



void SiscomCopiaOtraCadena(int pintNCadena,
		     const char *pchrPtrCadena,
		     char ***pchrPtrCadenas)
{

	(*pchrPtrCadenas)[pintNCadena]=(char *)strdup(pchrPtrCadena);
	*pchrPtrCadenas=(char **)realloc(*pchrPtrCadenas,sizeof(char *)*(pintNCadena+2));

}
int SiscomAnalizaCadenas(const char *pchrPtrCadena,
		   char pchrSeparador,
		   char *pchrPtrBuffer,
		   char ***pchrPtrRegreso)
{
int lintContador=0;
int lintNCadenas=0;
	*pchrPtrRegreso=(char **)malloc(sizeof(char *));
	while(*pchrPtrCadena)
	{
	    if(*pchrPtrCadena==pchrSeparador)
	    {
		*pchrPtrCadena++;
		pchrPtrBuffer[lintContador]=0;
		SiscomCopiaOtraCadena(lintNCadenas,pchrPtrBuffer,pchrPtrRegreso);
		*pchrPtrBuffer=0;
		lintContador=0;
		lintNCadenas++;
    	        (*pchrPtrRegreso)[lintNCadenas]=0; 
	    }
	    else
	    {
	    pchrPtrBuffer[lintContador]=*pchrPtrCadena;
	    *pchrPtrCadena++;
	    lintContador++;
	    }
	}
    if(lintContador)
    {
		pchrPtrBuffer[lintContador]=0;
     SiscomCopiaOtraCadena(lintNCadenas++,pchrPtrBuffer,pchrPtrRegreso);
     (*pchrPtrRegreso)[lintNCadenas]=0; 
    }
    return lintNCadenas;

}

int SiscomGeneraIdProducto(const char *nombre, const char *modelo)
{
    char lcharIdProducto[15] = {'\0'}, lcharAux[10];
    int lintEristico, lintLadoDerecho, lintLadoIzquierdo;
    lintLadoIzquierdo = 0;
    while(*nombre)
    {
        lintLadoIzquierdo += *nombre;
        nombre++;
    }
    lintLadoDerecho = 0;
    while(*modelo)
    {
        lintLadoDerecho += *modelo;
        modelo++;
    }
    sprintf(lcharIdProducto, "%d", lintLadoIzquierdo);
    sprintf(lcharAux, "%d", lintLadoDerecho);
    strcat(lcharIdProducto,lcharAux);
    return atoi(lcharIdProducto);
}

void SiscomLiberaCadenas(char **pchrPtrCadenas)
{
char **lchrPtrCadenas=pchrPtrCadenas;
	while(*pchrPtrCadenas)
	{
	    free(*pchrPtrCadenas);
	    pchrPtrCadenas++;
	}
free(lchrPtrCadenas);
}



void SiscomEliminaEspaciosFinal(const char *pchrPtrCadena)
{
char *lchrPtrFinalCadena;
int lintTamano=strlen(pchrPtrCadena);
lchrPtrFinalCadena=(char *)(pchrPtrCadena+lintTamano-1);
while(*lchrPtrFinalCadena==' ')
{
   *lchrPtrFinalCadena=0;
   lchrPtrFinalCadena--;
}
}

void SiscomEliminaEspaciosInicio4(char *pchrPtrBuffer,char *pchrPtrCadena)
{
    strcpy(pchrPtrBuffer,pchrPtrCadena);
    while(*pchrPtrBuffer==' ')
     pchrPtrBuffer++;
     strcpy(pchrPtrCadena,pchrPtrBuffer);
}

int SiscomRemplazandoCaracteres(unsigned const char *pchrPtrCadena,
			        unsigned const char *pchrPtrCaracteres,
				unsigned const char *pchrPtrCambio,
				unsigned char *pchrPtrSalida)
{
int lintRegreso=0;
	while(*pchrPtrCadena)
	{
	    if(*(pchrPtrCaracteres+*pchrPtrCadena))
	    {
		*pchrPtrSalida=*(pchrPtrCambio+*pchrPtrCadena);
		lintRegreso=1;
	    }
	    else
	    	*pchrPtrSalida=*pchrPtrCadena;
		
	    pchrPtrCadena++;
	    pchrPtrSalida++;
	}
	*pchrPtrSalida=0;
	return lintRegreso;
}


void SiscomNumeroCaracterACambiar(int pintNCaracter,
			    unsigned char *pchrPtrCaracteres)
{
	*(pchrPtrCaracteres+pintNCaracter)=1;
}
void SiscomNumeroCaracterRemplazar(int pintNCaracter,
				   unsigned char pchrCaracter,
				   unsigned char *pchrPtrCaracteres)
{
	*(pchrPtrCaracteres+pintNCaracter)=pchrCaracter;
}

void SiscomALetra(double lfltDato, char **pchrArrALetraPtr)
{
    char lchrArrNumeroCompleto[10],
         lchrArrNumeroALetra[128] = "\0",
         lchrArrDecimal[12] = "00/100 M.N.",
         lchrArrEntero[8],
         *pchrArrPtr;
    int lintContador;
    sprintf(lchrArrNumeroCompleto, "%.2f", lfltDato);
    pchrArrPtr = lchrArrNumeroCompleto;
    for(lintContador=0;*pchrArrPtr!='.';lintContador++,pchrArrPtr++)
    {
        lchrArrEntero[lintContador]=*pchrArrPtr;
    }
    lchrArrEntero[lintContador]='\0';
    lchrArrDecimal[0]=*(pchrArrPtr+1);
    lchrArrDecimal[1]=*(pchrArrPtr+2);

    if(atoi(lchrArrEntero)==0)
    {
        strcat(lchrArrNumeroALetra,"cero ");
    }
    else if(atoi(lchrArrEntero)>999999)
    {
        ALMillones(lchrArrNumeroALetra,lchrArrEntero);
    }
    else if(atoi(lchrArrEntero)>999)
    {
        ALMillares(lchrArrNumeroALetra,lchrArrEntero);
    }
    else if(atoi(lchrArrEntero)>99)
    {
        ALCentenas(lchrArrNumeroALetra,lchrArrEntero);
    }
    else if(atoi(lchrArrEntero)>9)
    {
        ALDecenas(lchrArrNumeroALetra,lchrArrEntero);
    }
    else
    {
        ALUnidades(lchrArrNumeroALetra,lchrArrEntero);
    }
    strcat(lchrArrNumeroALetra,"pesos ");
    strcat(lchrArrNumeroALetra,lchrArrDecimal);
    *pchrArrALetraPtr = (char *) malloc(sizeof(char)*strlen(lchrArrNumeroALetra)+10);
    strcpy(*pchrArrALetraPtr,lchrArrNumeroALetra);
}

void SiscomALetraSinDecimal(double lfltDato, char **pchrArrALetraPtr)
{
    char lchrArrNumeroCompleto[10],
         lchrArrNumeroALetra[128] = "\0",
         lchrArrDecimal[12] = "",
         lchrArrEntero[8],
         *pchrArrPtr;
    int lintContador;
    sprintf(lchrArrNumeroCompleto, "%.2f", lfltDato);
    pchrArrPtr = lchrArrNumeroCompleto;
    for(lintContador=0;*pchrArrPtr!='.';lintContador++,pchrArrPtr++)
    {
        lchrArrEntero[lintContador]=*pchrArrPtr;
    }
    lchrArrEntero[lintContador]='\0';
    lchrArrDecimal[0]=*(pchrArrPtr+1);
    lchrArrDecimal[1]=*(pchrArrPtr+2);

    if(atoi(lchrArrEntero)==0)
    {
        strcat(lchrArrNumeroALetra,"cero ");
    }
    else if(atoi(lchrArrEntero)>999999)
    {
        ALMillones(lchrArrNumeroALetra,lchrArrEntero);
    }
    else if(atoi(lchrArrEntero)>999)
    {
        ALMillares(lchrArrNumeroALetra,lchrArrEntero);
    }
    else if(atoi(lchrArrEntero)>99)
    {
        ALCentenas(lchrArrNumeroALetra,lchrArrEntero);
    }
    else if(atoi(lchrArrEntero)>9)
    {
        ALDecenas(lchrArrNumeroALetra,lchrArrEntero);
    }
    else
    {
        ALUnidades(lchrArrNumeroALetra,lchrArrEntero);
    }
    //strcat(lchrArrNumeroALetra,"pesos "); //Pesos
    strcat(lchrArrNumeroALetra,lchrArrDecimal);
    strcat(lchrArrNumeroALetra,lchrArrDecimal);
    *pchrArrALetraPtr = (char *) malloc(sizeof(char)*strlen(lchrArrNumeroALetra));
    strcpy(*pchrArrALetraPtr,lchrArrNumeroALetra);
}

void ALUnidades(char *pchrArrNumeroLetra, char *pchrArrNumero)
{
    const char *Unidades[] =
               {"",
                "un ",
                "dos ",
                "tres ",
                "cuatro ",
                "cinco ",
                "seis ",
                "siete ",
                "ocho ",
                "nueve "};
    strcat(pchrArrNumeroLetra,Unidades[atoi(pchrArrNumero)]);
}

void ALDecenas(char *pchrArrNumeroLetra, char *pchrArrNumero)
{
    const char *Decenas[] =
               {"diez ",
                "once ",
                "doce ",
                "trece ",
                "catorce ",
                "quince ",
                "dieciseis ",
                "diecisiete ",
                "dieciocho ",
                "diecinueve ",
                "veinte ",
                "treinta ",
                "cuarenta ",
                "cincuenta ",
                "sesenta ",
                "setenta ",
                "ochenta ",
                "noventa "};
    char lchrArrUnidades[10]="\0";
    int lintNumero = atoi(pchrArrNumero);
    if(lintNumero<10)
    {
        ALUnidades(pchrArrNumeroLetra, pchrArrNumero+1);
    }
    else if(lintNumero>19)
    {
        ALUnidades(lchrArrUnidades, pchrArrNumero+1);
        if((lintNumero%10)!=0)
        {
            strcat(pchrArrNumeroLetra,Decenas[(lintNumero/10)+8]);
            strcat(pchrArrNumeroLetra,"y ");
            strcat(pchrArrNumeroLetra,lchrArrUnidades);
        }
        else
        {
            strcat(pchrArrNumeroLetra,Decenas[(lintNumero/10)+8]);
        }
    }
    else
    {
        strcat(pchrArrNumeroLetra,Decenas[lintNumero-10]);
    }
}

void ALCentenas(char *pchrArrNumeroLetra, char *pchrArrNumero)
{
    const char *Centenas[] =
               {"",
                "ciento ",
                "doscientos ",
                "trescientos ",
                "cuatrocientos ",
                "quinientos ",
                "seiscientos ",
                "setecientos ",
                "ochocientos ",
                "novecientos "};
    int lintNumero = atoi(pchrArrNumero);
    if(lintNumero>99)
    {
        if(lintNumero==100)
        {
            strcat(pchrArrNumeroLetra,"cien ");
        }
        else
        {
            strcat(pchrArrNumeroLetra,Centenas[(lintNumero/100)]);
            ALDecenas(pchrArrNumeroLetra, pchrArrNumero+1);
        }
    }
    else
    {
        ALDecenas(pchrArrNumeroLetra, pchrArrNumero+1);
    }
}

void ALMillares(char *pchrArrNumeroLetra, char *pchrArrNumero)
{
    char lchrArrNumMiles[10],
         *pchrArrPtr;
    int lintCont,
        lintNumero = atoi(pchrArrNumero);
    pchrArrPtr=pchrArrNumero;
    for(lintCont=0;lintCont<(strlen(pchrArrNumero)-3);lintCont++,pchrArrPtr++)
        lchrArrNumMiles[lintCont]=*pchrArrPtr;
    lchrArrNumMiles[lintCont]='\0';
    if(lintNumero>999)
    {
        if(atoi(lchrArrNumMiles)>99)
        {
            ALCentenas(pchrArrNumeroLetra,lchrArrNumMiles);
        }
        else if(atoi(lchrArrNumMiles)>9)
        {
            ALDecenas(pchrArrNumeroLetra,lchrArrNumMiles);
        }
        else
        {
            ALUnidades(pchrArrNumeroLetra,lchrArrNumMiles);
        }
        strcat(pchrArrNumeroLetra,"mil ");
        ALCentenas(pchrArrNumeroLetra, pchrArrNumero+strlen(lchrArrNumMiles));
    }
    else
    {
        ALCentenas(pchrArrNumeroLetra, pchrArrNumero+strlen(lchrArrNumMiles));
    }
}

void ALMillones(char *pchrArrNumeroLetra, char *pchrArrNumero)
{
    char lchrArrNumMillones[10],
         *pchrArrPtr;
    int lintCont,
        lintNumero = atoi(pchrArrNumero);
    pchrArrPtr=pchrArrNumero;
    for(lintCont=0;lintCont<(strlen(pchrArrNumero)-6);lintCont++,pchrArrPtr++)
        lchrArrNumMillones[lintCont]=*pchrArrPtr;
    lchrArrNumMillones[lintCont]='\0';
    if(lintNumero>999999)
    {
        ALCentenas(pchrArrNumeroLetra, lchrArrNumMillones);
        strcat(pchrArrNumeroLetra,"mil ");
        ALCentenas(pchrArrNumeroLetra, pchrArrNumero+strlen(lchrArrNumMillones));
    }
    else
    {
        ALCentenas(pchrArrNumeroLetra, pchrArrNumero+strlen(lchrArrNumMillones));
    }
}

int SiscomEsHoyLaFecha(const char *pchrPtrFecha)
{
char lchrArrFechaHoy[25];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFechaHoy);
return strcmp(lchrArrFechaHoy,pchrPtrFecha);
}


