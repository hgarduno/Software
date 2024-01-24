#include <stdio.h>
#include <stdlib.h>
int Funcion1(int pintSocket,char *pchrPtrBinario,char ***pchrPtrArgs)
{
int i;
printf("Biblioteca de enlace dinamico. CReada Por Heli Garduno Esquivel\n");
if((*pchrPtrArgs=(char **)malloc(sizeof(char *)*5)))
{		
for(i=0;i<5;i++)
(*pchrPtrArgs)[i]=(char *)malloc(256);
strcpy(pchrPtrBinario,"/home/heli/SISCOMDesarrollo/ArchivosBinarios/RNProcesoAtiende.bin");
sprintf((*pchrPtrArgs)[0],"%s","RNProcesoAtiende.bin");
sprintf((*pchrPtrArgs)[1],"-A%d",pintSocket);
(*pchrPtrArgs)[2]=NULL;
}
}
