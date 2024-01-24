#include <ManipulacionArchivos.h>
#include <dirent.h>
void SISCOMObtenFechasDelRango(char *pchrPtrFechaEnRango,
			       char **pchrPtrFInicio,
			       char **pchrPtrFFin)
{
char **lchrPtrDosFechas;
	RegresaCadenas(pchrPtrFechaEnRango,'/',&lchrPtrDosFechas);
	*pchrPtrFInicio=lchrPtrDosFechas[0];
	*pchrPtrFFin=lchrPtrDosFechas[1];

	

}
void ObtenArchivos(char *pchrPtrDirectorio,char ***pchrPtrNmbArchivos)
{
struct dirent **lstcDirentPtrReg;
           int lintNArchivos;
	  lintNArchivos = scandir(pchrPtrDirectorio, &lstcDirentPtrReg, 0, alphasort);
	  *pchrPtrNmbArchivos=(char **)malloc(sizeof(char *)*(lintNArchivos+1));
	  (*pchrPtrNmbArchivos)[lintNArchivos]=0;
	  if (lintNArchivos < 0)
	  perror("scandir");
	  else 
	  {
            while(lintNArchivos--) 
	   {
	     (*pchrPtrNmbArchivos)[lintNArchivos]=(char *)malloc(strlen(lstcDirentPtrReg[lintNArchivos]->d_name));
	     strcpy((*pchrPtrNmbArchivos)[lintNArchivos],lstcDirentPtrReg[lintNArchivos]->d_name);
	      
             free(lstcDirentPtrReg[lintNArchivos]);
           }
             free(lstcDirentPtrReg);
	  }
										  

}
void QuitaEspacioPrincipioYFinal(char *pchrPtrCadena)
{
char *lchrPtrPaso=pchrPtrCadena;	
int lintPosFinal;
	while(*lchrPtrPaso==' ')
		*lchrPtrPaso++;
	strcpy(pchrPtrCadena,lchrPtrPaso);
	lintPosFinal=strlen(pchrPtrCadena)-1;
      	while(pchrPtrCadena[lintPosFinal]==' ')
	{
		pchrPtrCadena[lintPosFinal]=0;
		lintPosFinal--;
	}		

}
void RegresaLinea(char *lchrPtrRegreso,FILE *pflePtrArchivoEntrada)
{
int lintI=0;
	if(!feof(pflePtrArchivoEntrada))
	while((lchrPtrRegreso[lintI]=getc(pflePtrArchivoEntrada))!='\n')
	{
	if(lchrPtrRegreso[lintI]==EOF)break;	
	lintI++;	
	}
	lchrPtrRegreso[lintI]=0;
}
void RemplazaCaracter(char pchrPtrBusca,char pchrRemplaza,char *pchrPtrCadena)
{
int lintI;
	for(lintI=0;pchrPtrCadena[lintI];lintI++)
	if(pchrPtrCadena[lintI]==pchrPtrBusca)
		pchrPtrCadena[lintI]=pchrRemplaza;

}
void QuitaEspaciosPrincipioOFinal(char *pchrPtrCadena)
{
	int lintPos;
	char *lchrPtrRegreso;
	if((lchrPtrRegreso=strstr(pchrPtrCadena,"  ")))
	{	
	lintPos=lchrPtrRegreso-pchrPtrCadena;
	 if(lintPos)
	  pchrPtrCadena[lintPos]=0;
	}
	if(!lintPos)
	{	
	 lchrPtrRegreso=(char *)malloc(strlen(pchrPtrCadena)+1);	
	 strcpy(lchrPtrRegreso,pchrPtrCadena);
	 while(*lchrPtrRegreso==' ')
	 *lchrPtrRegreso++;
	 strcpy(pchrPtrCadena,lchrPtrRegreso);
	} 
}
int ObtenCadenaConDelimitador(char *pchrPtrCadenaEntrada,char pchrDelimitador,char *pchrPtrCadenaSalida,int *pintPtrPosicion)
{
	char *lchrPtrRegreso;
	if((lchrPtrRegreso=strchr(pchrPtrCadenaEntrada,pchrDelimitador)))
	{
		*pintPtrPosicion=lchrPtrRegreso-pchrPtrCadenaEntrada;
		strncpy(pchrPtrCadenaSalida,pchrPtrCadenaEntrada,*pintPtrPosicion);
		pchrPtrCadenaSalida[*pintPtrPosicion]=0;
		(*pintPtrPosicion)+=1;
		return 1;
	}
	else
	if(pchrPtrCadenaEntrada[0])
	{	
	 strcpy(pchrPtrCadenaSalida,pchrPtrCadenaEntrada);
	 *pintPtrPosicion=strlen(pchrPtrCadenaEntrada);
	 return 1;
	}
	else
	return 0;
		
}
int RegresaCadenas(char *pchrPtrCadena,char pchrSeparadorColumna,char ***pchrPtrCadenasRegreso)
{
int lintCadenas;
int lintPosicion;
int lintSumaPosicion=0;
int lintColumnas=0;
char lchrArrRegreso[10000];
	*pchrPtrCadenasRegreso=(char **)malloc(sizeof(char *)*(lintColumnas+3));
	while(pchrPtrCadena[lintSumaPosicion])
	{	
	 if(ObtenCadenaConDelimitador(pchrPtrCadena+lintSumaPosicion,pchrSeparadorColumna,lchrArrRegreso,&lintPosicion))
	 {
	/* HGE 	QuitaEspaciosPrincipioOFinal(lchrArrRegreso); */
		(*pchrPtrCadenasRegreso)[lintColumnas]=(char *)malloc(strlen(lchrArrRegreso)+5);
		strcpy((*pchrPtrCadenasRegreso)[lintColumnas],lchrArrRegreso);
		lintColumnas++;
		*pchrPtrCadenasRegreso=(char **)realloc(*pchrPtrCadenasRegreso,sizeof(char *)*(lintColumnas+1));
		lintSumaPosicion+=lintPosicion;
	 }
	}		
	(*pchrPtrCadenasRegreso)[lintColumnas]=0;
	return lintColumnas;
}
void LiberaMemoria(char **pchrPtrRegreso)
{
int lintI=0;
	while(pchrPtrRegreso[lintI])
	free(pchrPtrRegreso[lintI++]);
	free(pchrPtrRegreso);
	

}
