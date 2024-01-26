#include <zSiscomDesarrollo4.h>
#include <zSiscomFechaHora.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>


void zSiscomDesarrollo4::LiberaCadenas(char **pchrPtrCadenas)
{
char **lchrPtrPaso=pchrPtrCadenas;
	while(*pchrPtrCadenas)
	{
	 free(*pchrPtrCadenas);
	 pchrPtrCadenas++;
	}
free(lchrPtrPaso);
}
void zSiscomDesarrollo4::EliminaEspaciosInicio(char *pchrPtrCadena)
{
char *lchrPtrPaso=pchrPtrCadena;
      while(*lchrPtrPaso==' ')
      lchrPtrPaso++;
strcpy(pchrPtrCadena,lchrPtrPaso);
}
int zSiscomDesarrollo4::LeeLinea(FILE *pFlePtrArchivo,
				  char *pchrPtrLinea)
{
unsigned char lchrCaracter;
char lchrRegreso;
	while((lchrCaracter=getc(pFlePtrArchivo))!='\n' &&
	      lchrCaracter!=(unsigned char )EOF)
	{
	   *pchrPtrLinea=(char )lchrCaracter;
	   pchrPtrLinea++;
	}
  lchrRegreso=lchrCaracter==(unsigned char)EOF ? 1 : 0;
  *pchrPtrLinea=0;
  return lchrRegreso;
}
int zSiscomDesarrollo4::CadenasPorSeparador(const char *pchrPtrCadena,
		 	char pchrSeparador,
			char ***pchrPtrCadenas)
{
char *lchrPtrCampo=(char *)malloc(strlen(pchrPtrCadena)+1);
char *lchrPtrBase=0;
int lintContador=0;
	lchrPtrBase=lchrPtrCampo;
	*pchrPtrCadenas=(char **)malloc(sizeof(char *)*2);
	while(*pchrPtrCadena)
	{
	   if(*pchrPtrCadena==pchrSeparador)
	   {
	      *lchrPtrCampo=0;
	      *(*pchrPtrCadenas+lintContador)=strdup(lchrPtrBase);
	      lintContador++;
	      *pchrPtrCadenas=(char **)realloc(*pchrPtrCadenas,sizeof(char *)*(lintContador+2));
	      lchrPtrCampo=lchrPtrBase;
	   }
	   else
	   {
	   *lchrPtrCampo=*pchrPtrCadena;
	   lchrPtrCampo++;
	   }
	   pchrPtrCadena++;
	}
	*lchrPtrCampo=0;
	*(*pchrPtrCadenas+lintContador)=strdup(lchrPtrBase);
	*(*pchrPtrCadenas+lintContador+1)=0;
	lintContador++;
return lintContador;
}
const char *zSiscomDesarrollo4::ObtenCadenaSeparador(const char *pchrPtrCadena,
						      char pchrSeparador)
{
	while(*pchrPtrCadena &&
	     *pchrPtrCadena!=pchrSeparador)
	pchrPtrCadena++;
	if(*pchrPtrCadena)
	return ++pchrPtrCadena;
	else
	return pchrPtrCadena;
}

zSiscomDesarrollo4::zSiscomDesarrollo4()
{
  gzSiscomConexion=0;
}
const char *zSiscomDesarrollo4::CadenaEntreSeparadores(
				  const char *pchrPtrEntrada,
				  char pchrSepInicio,
				  char pchrSepFin,
				  char *pchrPtrCadena)
{
const char *lchrPtrCadena;

   lchrPtrCadena=ObtenCadenaSeparador(pchrPtrEntrada,
   				      pchrSepInicio);
   while(*lchrPtrCadena!=pchrSepFin)
   {
	*pchrPtrCadena=*lchrPtrCadena;
	pchrPtrCadena++;
	lchrPtrCadena++;

   }
*pchrPtrCadena=0;	
return ++lchrPtrCadena;
}
void zSiscomDesarrollo4::Log(const char *pchrPtrArchivo,
			 const char *pchrPtrFuncion,
			 int pintNoLinea,
			 char *pzCadenaFormato,...)
 {
va_list lzArgumentos;
char *lzCadenaFormato=pzCadenaFormato;
   char  lzMen[1024];
        char *lzParametroChar;
   char  lzFechaActual[128];
        int liParametroInt;
        float lfParametroFloat;
        int liPos=0;
        va_start(lzArgumentos,pzCadenaFormato);
        fprintf(gPtrFleArchivoLog,
		"(%s)( %s %s %d ) ",
                zSiscomFechaHora::Actual3(lzFechaActual),
		pchrPtrArchivo,
		pchrPtrFuncion,
		pintNoLinea);
        do
        {
                if(*lzCadenaFormato=='%')
                {
                        *lzCadenaFormato++;
                        switch(*lzCadenaFormato)
                        {
                          case 's':
                                lzMen[liPos]=0;
                                lzParametroChar=va_arg(lzArgumentos,
                                                       char *);
                                fprintf(gPtrFleArchivoLog,
                                        "%s%s",
                                        lzMen,
                                        lzParametroChar);
                                liPos=0;

                          break;
                          case 'f':
                                lzMen[liPos]=0;
                                lfParametroFloat=(float )va_arg(lzArgumentos,
                                                                double);
                                fprintf(gPtrFleArchivoLog,
                                        "%s%f",
                                         lzMen,
                                         lfParametroFloat);
                                liPos=0;
                          break;
                          case 'd':
                                lzMen[liPos]=0;
                                liParametroInt=(int )va_arg(lzArgumentos,
                                                            int);
                                fprintf(gPtrFleArchivoLog,
                                        "%s%d",
                                        lzMen,
                                        liParametroInt);
                                liPos=0;
                          break;
			  case 'x':
                                lzMen[liPos]=0;
                                lzParametroChar=(char *)va_arg(lzArgumentos,
                                                                char *);
                                fprintf(gPtrFleArchivoLog,
                                        "%s%x",
                                         lzMen,
                                         lzParametroChar);
                                liPos=0;
                          break;
                        }
                     lzMen[0]=0;
                 }
            else
                {
                        lzMen[liPos]=*lzCadenaFormato;
                        liPos++;
                }
         }while(*lzCadenaFormato++);
        lzMen[liPos]=0;
        if(lzMen[0])
        fprintf(gPtrFleArchivoLog,"%s",lzMen);
        fprintf(gPtrFleArchivoLog,"\n");
        va_end(lzArgumentos);
        fflush(gPtrFleArchivoLog);
 }

void zSiscomDesarrollo4::Servidor(zSiscomAnalizaArgumentos pzSiscomAnalizaArgumentos,
				  char **pchrPtrArgv,
				  int pintArgc,
				  char *pchrPtrDirIp,
				  int *pintPtrPuerto)
{
const char *lchrPtrDirIpAmbiente,
	   *lchrPtrPuertoAmbiente;
  if(pzSiscomAnalizaArgumentos)
     pzSiscomAnalizaArgumentos(pintArgc,pchrPtrArgv,pintPtrPuerto,pchrPtrDirIp);
  if(pintArgc==1)
  {
  	lchrPtrDirIpAmbiente=getenv("DirIpServidor");
	lchrPtrPuertoAmbiente=getenv("Puerto");
	if(lchrPtrDirIpAmbiente)
	 strcpy(pchrPtrDirIp,lchrPtrDirIpAmbiente);
	 if(lchrPtrPuertoAmbiente)
	 *pintPtrPuerto=atoi(lchrPtrPuertoAmbiente);
  }

}
int zSiscomDesarrollo4::LeeArchivo(const char *pchrPtrNombreArchivo,
				   char *pchrPtrBufferLinea,
				   char *pchrPtrArchivo)
{
FILE *lFlePtrArchivo;
	*pchrPtrArchivo=0;
   if((lFlePtrArchivo=fopen(pchrPtrNombreArchivo,"r")))
   while(!zSiscomDesarrollo4::LeeLinea(lFlePtrArchivo,pchrPtrBufferLinea))
	strcat(pchrPtrArchivo,pchrPtrBufferLinea);	
fclose(lFlePtrArchivo);
}

void zSiscomDesarrollo4::CadenaHastaDelimitador(const char *pchrPtrCadenaE,
						char pchrCaracter,
						char *pchrPtrCadena)
{
    while(*pchrPtrCadenaE)
    {
       if(*pchrPtrCadenaE==pchrCaracter)
       {
   	  strcpy(pchrPtrCadena,pchrPtrCadenaE+1);
	  break;
       }
        pchrPtrCadenaE++;
    }
}
