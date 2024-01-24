#include <SiscomDesarrollo3Qt++.h>
#include <time.h>
#include <stdarg.h>
#include <sys/timeb.h>
#include <string.h>
#include <stdlib.h>

#include <qcombobox.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qfont.h>
#include <qtabwidget.h>
#include <SiscomRegistros3.h>
#include <SiscomRegistros4.h>
#include <SiscomCampos3.h>
#include <SiscomParametroConsulta3.h>
#include <SiscomTableItemColor.h>


void SiscomEliminaCaracter3Qt(char pchrCaracter,
			   char *pchrPtrCadena)
{
char *lchrPtrRespaldo=(char *)strdup(pchrPtrCadena);
char *lchrPtrRespaldoRes=lchrPtrRespaldo;
int lintContador=0;
		   for(;
		       *lchrPtrRespaldo;
		       *lchrPtrRespaldo++)
		       if(*lchrPtrRespaldo!=pchrCaracter)
		       {
			  pchrPtrCadena[lintContador]=*lchrPtrRespaldo;
			  lintContador++;
		       }
	pchrPtrCadena[lintContador]=0;
	free(lchrPtrRespaldoRes); 
}
void SiscomFechaLocal3Qt(char *pchrPtrFecha)
{
time_t ltimeRegreso;
char *lchrPtrRegreso;
        ltimeRegreso=time(0);
        lchrPtrRegreso=(char *)strdup(ctime(&ltimeRegreso));

	SiscomEliminaCaracter3Qt('\n',lchrPtrRegreso);
	strcpy(pchrPtrFecha,lchrPtrRegreso);
	free(lchrPtrRegreso);	

}
void SiscomMensajesLog3Qt(const char *pchrPtrArchivo,
			 const char *pchrPtrFuncion,
			 int pintNoLinea,
			 const char *pzCadenaFormato,...)
 {
         va_list lzArgumentos;
        const char *lzCadenaFormato=pzCadenaFormato;
   char  lzMen[1024];
        char *lzParametroChar;
   char  lzFechaActual[25];
        int liParametroInt;
        float lfParametroFloat;
        int liPos=0;
	SiscomFechaLocal3Qt(lzFechaActual);
        va_start(lzArgumentos,pzCadenaFormato);
        fprintf(gPtrFleArchivoLog3Qt,
		"%s:( %s %s %d ) ",
                lzFechaActual,
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
                                fprintf(gPtrFleArchivoLog3Qt,
                                        "%s%s",
                                        lzMen,
                                        lzParametroChar);
                                liPos=0;

                          break;
                          case 'f':
                                lzMen[liPos]=0;
                                lfParametroFloat=(float )va_arg(lzArgumentos,
                                                                double);
                                fprintf(gPtrFleArchivoLog3Qt,
                                        "%s%f",
                                         lzMen,
                                         lfParametroFloat);
                                liPos=0;
                          break;
                          case 'd':
                                lzMen[liPos]=0;
                                liParametroInt=(int )va_arg(lzArgumentos,
                                                            int);
                                fprintf(gPtrFleArchivoLog3Qt,
                                        "%s%d",
                                        lzMen,
                                        liParametroInt);
                                liPos=0;
                          break;
			  case 'x':
                                lzMen[liPos]=0;
                                lzParametroChar=(char *)va_arg(lzArgumentos,
                                                                char *);
                                fprintf(gPtrFleArchivoLog3Qt,
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
        fprintf(gPtrFleArchivoLog3Qt,"%s",lzMen);
        fprintf(gPtrFleArchivoLog3Qt,"\n");
        va_end(lzArgumentos);
        fflush(gPtrFleArchivoLog3Qt);
 
 }

 SiscomDesarrollo3Qt::SiscomDesarrollo3Qt()
 {

 }
QLineEdit *SiscomDesarrollo3Qt::ColocaEditAlCombo(QComboBox *pQCBCombo,
 						   const char *pchrPtrName)
{
QLineEdit *lQLERegreso=new QLineEdit(pQCBCombo,pchrPtrName);
	pQCBCombo->setLineEdit(lQLERegreso);
	return lQLERegreso;
}

const char *SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLineEdit *pQLEControl)
{
	return pQLEControl->text().isEmpty() ? "" :((const char *)pQLEControl->text());
}
const char *SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QTextEdit *pQTEControl)
{
	return pQTEControl->text().isEmpty() ? "" :strdup((const char *)pQTEControl->text());
}
const char *SiscomDesarrollo3Qt::InformacionEdit(QLineEdit *pQLEControl)
{
	return pQLEControl->text().isEmpty() ? "" :((const char *)pQLEControl->text());
}
const char *SiscomDesarrollo3Qt::InformacionEdit(QTextEdit *pQTEControl)
{
	return pQTEControl->text().isEmpty() ? "" :strdup((const char *)pQTEControl->text());
}
SiscomCampo3 *SiscomDesarrollo3Qt::Campo3Edit(const char *pchrPtrNmbCampo,
					      QLineEdit *pQLEControl)
{
return new SiscomCampo3(pchrPtrNmbCampo,
			SiscomDesarrollo3Qt::InformacionEdit(pQLEControl));
}
void SiscomDesarrollo3Qt::PasaFocoControl(QLineEdit *pQLEControl)
{
pQLEControl->setFocus();
pQLEControl->selectAll();
}
void SiscomDesarrollo3Qt::PasaFocoControl(QWidget *pQWControl)
{
	pQWControl->setFocus();
}


void SiscomDesarrollo3Qt::PasaFoco(QLineEdit *pQLEControl)
{
pQLEControl->setFocus();
pQLEControl->selectAll();
}
void SiscomDesarrollo3Qt::PasaFoco(QWidget *pQWControl)
{
	pQWControl->setFocus();
}

void SiscomDesarrollo3Qt::FocoAControl(QLineEdit *pQLEControl)
{
pQLEControl->setFocus();
pQLEControl->selectAll();
}
void SiscomDesarrollo3Qt::FocoAControl(QWidget *pQWControl)
{
	pQWControl->setFocus();
}

void SiscomDesarrollo3Qt::RegistroALaTabla(int pintNFila,
					   QTable *pQTDatos,
					   const QStringList &pQSLRegistro)
{
int lintContador;
int lintNColumnas=pQSLRegistro.count();
for(lintContador=0;
    lintContador<lintNColumnas;
    lintContador++)
pQTDatos->setText(pintNFila,
		  lintContador,
		  pQSLRegistro[lintContador]);

}

void SiscomDesarrollo3Qt::RegsPrincipal4ALaTabla(const char *pchrPtrCamposM[],
					   QTable *pQTDato,
					   SiscomRegistro4 *pSisReg4Dat)
{
SiscomRegistro3 *lSisReg3Dat;
SiscomRegistro3LstLst *lSisReg3LstLst; 
SiscomCampo3 *lSisCampo3;
int lintContador;
int lintCampos;
pQTDato->setNumRows(pSisReg4Dat->count());
  for(lSisReg3LstLst=pSisReg4Dat->first(),
      lintContador=0;
      lSisReg3LstLst;
      lSisReg3LstLst=pSisReg4Dat->next(),
      lintContador++)
  {
      if((lSisReg3Dat=pSisReg4Dat->RegistroPrincipal()))
      {
         for(lintCampos=0;
	     pchrPtrCamposM[lintCampos];
	     lintCampos++)
	    pQTDato->setText(lintContador,
	    		     lintCampos,
			     (*lSisReg3Dat)[pchrPtrCamposM[lintCampos]]);
       }
  }
}
void SiscomDesarrollo3Qt::RegistroALaTabla(int pintFila,
					   QTable *pQTDatos,
					   const char *pchrPtrCampos[],
					   SiscomRegistro3 *pSisReg3Dato)
{
int lintContador;
	for(lintContador=0;
	    pchrPtrCampos[lintContador];
	    lintContador++)
   pQTDatos->setText(pintFila,
   		     lintContador,
		     (*pSisReg3Dato)[pchrPtrCampos[lintContador]]);
}
void ConcatenaCadenaSalida(const char **pchrPtrCampos,
			   SiscomRegistro3 *pSisReg3Dato,
			   char *pchrPtrCadena)
{
int lintContador=0;
char lchrArrPaso[128];

	while(*pchrPtrCampos)
	{
	   sprintf(lchrArrPaso,"%s ",(*pSisReg3Dato)[*pchrPtrCampos]);
	   if(!lintContador) 
	   strcpy(pchrPtrCadena,lchrArrPaso);
	   else
	   strcat(pchrPtrCadena,lchrArrPaso);
	  pchrPtrCampos++;
	  lintContador++;
	}


}
void SiscomDesarrollo3Qt::RegistrosALaTabla(QTable *pQTDatos,
					    SiscomRegistro3Lst *pSisReg3LstDat,
					    const char *pchrPtrConcatena[],
					    const char *pchrPtrAnexa[])
{
int lintContador=0;
int lintFila=0;
int lintColumna=0;
SiscomRegistro3 *lSRegistro3;
char lchrArrCadena[256];

if(pSisReg3LstDat)
{
pQTDatos->setNumRows(pSisReg3LstDat->count());
lintColumna=lintContador;
for(lSRegistro3=pSisReg3LstDat->first();
    lSRegistro3;
    lSRegistro3=pSisReg3LstDat->next(),
    lintFila++)
{
ConcatenaCadenaSalida(pchrPtrConcatena,
   			 lSRegistro3,
			 lchrArrCadena);
    pQTDatos->setText(lintFila,
    		      0,
		      lchrArrCadena);
if(pchrPtrAnexa)
for(lintContador=0,
    lintColumna=1;
    pchrPtrAnexa[lintContador];
    lintContador++,
    lintColumna++)
    
{
  if(pchrPtrAnexa[lintContador])
   pQTDatos->setText(lintFila,
   		     lintColumna,
		     (*lSRegistro3)[pchrPtrAnexa[lintContador]]);
}
}
}
}
void SiscomDesarrollo3Qt::RegistrosALaTabla(const char *pchrPtrCamposM[],
					    QTable *pQTDatos,
					    SiscomRegistro3Lst *pSRegistro3Lst)
{
int lintContador=0;
int lintFila=0;
int lintColumna=0;
SiscomRegistro3 *lSRegistro3;
if(pSRegistro3Lst)
{
pQTDatos->setNumRows(pSRegistro3Lst->count());
for(lSRegistro3=pSRegistro3Lst->first(),
    lintFila=0;
    lSRegistro3;
    lSRegistro3=pSRegistro3Lst->next(),
    lintFila++)
for(lintContador=0,
    lintColumna=0;
    pchrPtrCamposM[lintContador];
    lintContador++,
    lintColumna++)
if(pchrPtrCamposM[lintContador][0])
pQTDatos->setText(lintFila,
		  lintColumna,
		  (*lSRegistro3)[pchrPtrCamposM[lintContador]]);
}
}
void SiscomDesarrollo3Qt::RegistrosAlCombo(const char *pchrPtrNmbCampo,
					   QComboBox *pQCBCombo,
					   SiscomRegistro3Lst *pSRegistro3Lst)
{
SiscomRegistro3 *lSRegistro3;
for(lSRegistro3=pSRegistro3Lst->first();
    lSRegistro3;
    lSRegistro3=pSRegistro3Lst->next())
pQCBCombo->insertItem((*lSRegistro3)[pchrPtrNmbCampo]);


}
void SiscomDesarrollo3Qt::Registros4PrincipalAlCombo(
			   const char *pchrPtrNmbCampo,
			   QComboBox *pQCBCombo,
			   SiscomRegistro4 *pSisReg4Dat)
{
SiscomRegistro3 *lSisReg3Dat;
SiscomRegistro3LstLst *lSisReg3LstLst; 
SiscomCampo3 *lSisCampo3;
int lintContador;
int lintCampos;
  for(lSisReg3LstLst=pSisReg4Dat->first(),
      lintContador=0;
      lSisReg3LstLst;
      lSisReg3LstLst=pSisReg4Dat->next(),
      lintContador++)
      if((lSisReg3Dat=pSisReg4Dat->RegistroPrincipal()))
	    pQCBCombo->insertItem((*lSisReg3Dat)[pchrPtrNmbCampo]);

}
void SiscomDesarrollo3Qt::AjustaFilas(QTable *pQTDatos)
{
int lintContador;
	for(lintContador=0;
		lintContador<pQTDatos->numRows();
		lintContador++)
	  pQTDatos->adjustRow(lintContador);
}
void SiscomDesarrollo3Qt::AjustaColumnas(QTable *pQTDatos)
{
int lintContador;
	for(lintContador=0;
		lintContador<pQTDatos->numCols();
		lintContador++)
	  pQTDatos->adjustColumn(lintContador);
}

void SiscomDesarrollo3Qt::ParametrosConsulta3(
				SiscomRegistro3Lst *pSRegistro3Lst,
				char *pchrPtrFormato,
				...)
{
va_list lzArgumentos;
char *lzCadenaFormato=pchrPtrFormato;
char  lzMen[1024];
        char *lzParametroChar;
        int liParametroInt;
        float lfParametroFloat;
        int liPos=0;
        va_start(lzArgumentos,pchrPtrFormato);
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
				(*pSRegistro3Lst) << 
				   new SiscomParametroConsulta3(lzParametroChar);
                                liPos=0;

                          break;
                          case 'f':
                                lzMen[liPos]=0;
                                lfParametroFloat=(float )va_arg(lzArgumentos,
                                                                double);
                                liPos=0;
                          break;
                          case 'd':
                                lzMen[liPos]=0;
                                liParametroInt=(int )va_arg(lzArgumentos,
                                                            int);
                                liPos=0;
                          break;
			  case 'x':
                                lzMen[liPos]=0;
                                lzParametroChar=(char *)va_arg(lzArgumentos,
                                                                char *);
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
        va_end(lzArgumentos);

}
void SiscomDesarrollo3Qt::ImprimeContenido(SiscomRegistro3Lst *pSReg3LstDatos)
{
SiscomRegistro3 *lSReg3Imprime;
SiscomCampo3 *lS3Campo;
for(lSReg3Imprime=pSReg3LstDatos->first();
    lSReg3Imprime;
    lSReg3Imprime=pSReg3LstDatos->next())
{
for(lS3Campo=lSReg3Imprime->SiscomColocaPrimerCampo();
    lS3Campo;
    lS3Campo=lSReg3Imprime->SiscomSiguienteCampo())
{
SiscomEscribeLog3Qt("{%s [%s]}",
		    lS3Campo->SiscomNmbCampo(),
		    lS3Campo->SiscomDato());
}
}
}
void SiscomDesarrollo3Qt::EliminaFilas(QTable *pQTDatos)
{
QMemArray<int> lQMAFilas(pQTDatos->numRows());
int lintContador;
int lintNFilas=pQTDatos->numRows();
for(lintContador=0;
    lintContador<lintNFilas;
    lintContador++)
lQMAFilas[lintContador]=lintContador;
pQTDatos->removeRows(lQMAFilas);
}

void SiscomDesarrollo3Qt::EliminaFilasSeleccionadas(QTable *pQTDatos)
{
QMemArray<int> lQMAFilas(pQTDatos->numRows());
int lintContador;
int lintNFilas=pQTDatos->numRows();
int lintContadorJ=0;
for(lintContador=0;
    lintContador<lintNFilas;
    lintContador++)
if(pQTDatos->isRowSelected(lintContador))
lQMAFilas[lintContadorJ++]=lintContador;
/*
 * Sabado 13 Agosto 2011 
 * Esta funcion, tronaba al invocarse, el problema
 * estaba en que al no ejecutar el resize de QMemArray
 * el numero de registros considerados para eliminar 
 * las filas no era correcto
 */
lQMAFilas.resize(lintContadorJ);
if(lQMAFilas.count())
pQTDatos->removeRows(lQMAFilas);
}
int SiscomDesarrollo3Qt::LeeLinea(FILE *pFlePtrArchivo,
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
void SiscomDesarrollo3Qt::EliminaCaracter(char pchrCaracter,
					  char *pchrPtrCadena)
{
char *lchrPtrPaso=pchrPtrCadena;
        while(*lchrPtrPaso)
	{
	   if(*lchrPtrPaso!=pchrCaracter)
	   {
	    *pchrPtrCadena=*lchrPtrPaso;
	    pchrPtrCadena++;
	   }
	   lchrPtrPaso++;
	}
   *pchrPtrCadena=0;
}
void SiscomDesarrollo3Qt::EliminaCaracteres(const char *pchrPtrCaracteres,
					   char *pchrPtrCadena)
{
    while(*pchrPtrCaracteres)
    { 
       EliminaCaracter(*pchrPtrCaracteres,pchrPtrCadena);
       pchrPtrCaracteres++;
    }

}
void SiscomDesarrollo3Qt::EliminaEspaciosInicio(char *pchrPtrCadena)
{
char *lchrPtrPaso=pchrPtrCadena;
      while(*lchrPtrPaso==' ')
      lchrPtrPaso++;
strcpy(pchrPtrCadena,lchrPtrPaso);
}
void SiscomDesarrollo3Qt::EliminaEspaciosFinal(char *pchrPtrCadena)
{
char *lchrPtrPaso=pchrPtrCadena+strlen(pchrPtrCadena)-1;
		while(*lchrPtrPaso==' ')
		 lchrPtrPaso--;
    *(lchrPtrPaso+1)=0;
}
const char *SiscomDesarrollo3Qt::ObtenCadenaSeparador(const char *pchrPtrCadena,
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
void SiscomDesarrollo3Qt::CopiaCadenaPorSeparador(const char *pchrPtrBase,
						  const char *pchrPtrCadena,
						  char **pchrPtrCadenas)
{
int lintNCaracteres;
    lintNCaracteres=*pchrPtrCadena ? pchrPtrCadena-pchrPtrBase-1 :
    	                             pchrPtrCadena-pchrPtrBase; 
     *pchrPtrCadenas=(char *)malloc(lintNCaracteres+1);
     strncpy(*pchrPtrCadenas,pchrPtrBase,lintNCaracteres);
     *(*pchrPtrCadenas+lintNCaracteres)=0;
}

int SiscomDesarrollo3Qt::CadenasPorSeparador2(const char *pchrPtrCadena,
		 	char pchrSeparador,
			char ***pchrPtrCadenas)
{
char *lchrPtrCampo=(char *)malloc(strlen(pchrPtrCadena));
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
	      *pchrPtrCadenas=(char **)realloc(*pchrPtrCadenas,
	      				        sizeof(char *)*(lintContador+2));
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
int SiscomDesarrollo3Qt::CadenasPorSeparador(const char *pchrPtrCadena,
					     char pchrSeparador,
					     char ***pchrPtrCadenas)
{
int lintContador=0;
const char *lchrPtrBase=pchrPtrCadena;
	*pchrPtrCadenas=(char **)malloc(2*sizeof(char *));
	while(*pchrPtrCadena)
	{
           pchrPtrCadena=ObtenCadenaSeparador(pchrPtrCadena,pchrSeparador);
	   CopiaCadenaPorSeparador(lchrPtrBase,
	   			   pchrPtrCadena,
				   &*(*pchrPtrCadenas+lintContador));
	  lchrPtrBase=pchrPtrCadena;
	  lintContador++;
	  *pchrPtrCadenas=(char **)realloc(*pchrPtrCadenas,sizeof(char *)*(lintContador+2));
	}
	*(*pchrPtrCadenas+lintContador)=0;
return lintContador;
}
void SiscomDesarrollo3Qt::LiberaCadenas(char **pchrPtrCadenas)
{
char **lchrPtrPaso=pchrPtrCadenas;
	while(*pchrPtrCadenas)
	{
	 free(*pchrPtrCadenas);
	 pchrPtrCadenas++;
	}
free(lchrPtrPaso);
}
void SiscomDesarrollo3Qt::CadenasPorSeparador(const char *pchrPtrCadena,	                                            char pchrSeparador,
					      char *pchrPtrCadena1,
					      char *pchrPtrCadena2)
{
    while(*pchrPtrCadena!=pchrSeparador)
    {
      *pchrPtrCadena1=*pchrPtrCadena;
      pchrPtrCadena1++;
      pchrPtrCadena++;
    }
    *pchrPtrCadena1=0;
    pchrPtrCadena++;
    while(*pchrPtrCadena)
    {
       *pchrPtrCadena2=*pchrPtrCadena;
       pchrPtrCadena2++;
       pchrPtrCadena++;
    }
    *pchrPtrCadena2=0;
}
			
							
void SiscomDesarrollo3Qt::FechaHoy(char *pchrPtrDia,
				   char *pchrPtrMes,
				   char *pchrPtrA_o)
{
int lintDia,
	lintMes,
	lintA_o;
SiscomDesarrollo3Qt::FechaHoy(&lintDia,
			      &lintMes,
			      &lintA_o);
sprintf(pchrPtrDia,"%02d",lintDia);
sprintf(pchrPtrMes,"%02d",lintMes);
sprintf(pchrPtrA_o,"%04d",lintA_o);
}
void SiscomDesarrollo3Qt::FechaHoy(int *pintPtrDia,
				   int *pintPtrMes,
				   int *pintPtrA_o)
{
time_t regTime;
struct tm *stctm;
time(&regTime);
stctm=gmtime(&regTime);
*pintPtrDia=stctm->tm_mday;
*pintPtrMes=stctm->tm_mon+1;
*pintPtrA_o=stctm->tm_year+1900;
}

void SiscomDesarrollo3Qt::ColoreaFilasSeleccionadas(QTable *pQTDatos,
						    const QColor &pQColor)
{
int lintContador;
int lintNFilas;
int lintNColumnas;
int lintContadorJ;
lintNFilas=pQTDatos->numRows();
lintNColumnas=pQTDatos->numCols();
SiscomTableItemColor *lSisTabItemColor;
for(lintContador=0;
    lintContador<lintNFilas;
    lintContador++)
{
   for(lintContadorJ=0;
       lintContadorJ<lintNColumnas;
       lintContadorJ++)
   {
     if(pQTDatos->isRowSelected(lintContador,true))
     {
     lSisTabItemColor=new SiscomTableItemColor(
     				pQTDatos,
     				pQColor,	
				QTableItem::Never,
				pQTDatos->text(lintContador,lintContadorJ));
      pQTDatos->setItem(lintContador,
      		lintContadorJ,
		lSisTabItemColor);
      }

   }

  }
}
void SiscomDesarrollo3Qt::ColoreaFilasSeleccionadas(QTable *pQTDatos,
						    const QColor &pQColor,
						    const QMemArray<int> &pQMAFilas)
{
int lintContador;
int lintNFilas;
int lintNColumnas;
int lintContadorJ;
lintNFilas=pQMAFilas.count();
lintNColumnas=pQTDatos->numCols();
SiscomTableItemColor *lSisTabItemColor;
for(lintContador=0;
    lintContador<lintNFilas;
    lintContador++)
{
   if(pQMAFilas[lintContador]!=-1)
   for(lintContadorJ=0;
       lintContadorJ<lintNColumnas;
       lintContadorJ++)
   {
     lSisTabItemColor=new SiscomTableItemColor(
     			   pQTDatos,
     			   pQColor,	
			   QTableItem::Never,
			   pQTDatos->text(pQMAFilas[lintContador],lintContadorJ));
      pQTDatos->setItem(pQMAFilas[lintContador],
      		lintContadorJ,
		lSisTabItemColor);
   }

  }
}


void SiscomDesarrollo3Qt::ColoreaFilas(QTable *pQTDatos,
						    const QColor &pQColor)
{
int lintContador;
int lintNFilas;
int lintNColumnas;
int lintContadorJ;
lintNFilas=pQTDatos->numRows();
lintNColumnas=pQTDatos->numCols();
SiscomTableItemColor *lSisTabItemColor;
for(lintContador=0;
    lintContador<lintNFilas;
    lintContador++)
{
   for(lintContadorJ=0;
       lintContadorJ<lintNColumnas;
       lintContadorJ++)
   {
     lSisTabItemColor=new SiscomTableItemColor(
     			   pQTDatos,
     			   pQColor,	
			   QTableItem::Never,
			   pQTDatos->text(lintContador,lintContadorJ));
      pQTDatos->setItem(lintContador,
      		lintContadorJ,
		lSisTabItemColor);
   }

  }
}
void SiscomDesarrollo3Qt::ColoreaCelda(int pintFila,
				       int pintColumna,
				       QTable *pQTabla,
				       const QColor &pQColor)
{
SiscomTableItemColor *lSisTabItemColor;

}
void SiscomDesarrollo3Qt::EliminaPaginasQTabWidget(QTabWidget *pQTWControl)
{
int lintContador;
QPtrList<QWidget > lQPLPaginas;
QWidget *lQWPagina;
for(lintContador=0;
    lintContador<pQTWControl->count();
    lintContador++)
  lQPLPaginas.append(pQTWControl->page(lintContador));
for(lQWPagina=lQPLPaginas.first();
    lQWPagina;
    lQWPagina=lQPLPaginas.next())
pQTWControl->removePage(lQWPagina);
}

int SiscomDesarrollo3Qt::TipoLetraPerfil(const char *pchrPtrArchivo,
					QFont *pQFLetra)
{
FILE *lFlePtrArchivo;
char lchrArrLinea[128];
char lchrArrTipoLetra[128];
char lchrArrTamLetra[128];
int lintTamLetra;
SiscomEscribeLog3Qt("Abriendo ... (%s)",pchrPtrArchivo);
if((lFlePtrArchivo=fopen(pchrPtrArchivo,"r")))
{
   SiscomDesarrollo3Qt::LeeLinea(lFlePtrArchivo,lchrArrLinea);
   SiscomDesarrollo3Qt::CadenasPorSeparador(lchrArrLinea,
   					     '\t', 
					     lchrArrTipoLetra,
					     lchrArrTamLetra);
  lintTamLetra=atoi(lchrArrTamLetra);
  pQFLetra->setFamily(lchrArrTipoLetra);
  pQFLetra->setPointSize(lintTamLetra);
  fclose(lFlePtrArchivo);
  return 1;
}
else
return 0;


}
/*
 * SiscomDesarrollo3Qt::Registro3("Campo1,	\
 * 				   Campo2,	\
 * 				   Campo3",
 * 				   "Dato Campo1",
 * 				   "Dato Camp2",
 * 				   "Dato Campo3");
 */

void EliminaCaracteresNoNecesarios(char **pchrPtrCampos)
{
	while(*pchrPtrCampos)
	{
	  SiscomDesarrollo3Qt::EliminaCaracter('\t',*pchrPtrCampos);
	  SiscomDesarrollo3Qt::EliminaEspaciosInicio(*pchrPtrCampos);
	 pchrPtrCampos++;
	}
}

void FormaCamposRegistro3(const char *pchrPtrFormato,
			 char ***pchrPtrCampos)
{
char **lchrPtrCampos;
  SiscomDesarrollo3Qt::CadenasPorSeparador(pchrPtrFormato,
  					   ',',
					   pchrPtrCampos);
   EliminaCaracteresNoNecesarios(*pchrPtrCampos);
lchrPtrCampos=*pchrPtrCampos;
}
SiscomRegistro3 *SiscomDesarrollo3Qt::Registro3(const char *pchrPtrFormato,
					       ...)
{
char **lchrPtrCampos;
SiscomRegistro3 *lSisReg3Regreso;
va_list lvLCampos;
 FormaCamposRegistro3(pchrPtrFormato,&lchrPtrCampos);
 va_start(lvLCampos,pchrPtrFormato);
 lSisReg3Regreso=new SiscomRegistro3;
 while(*lchrPtrCampos)
 {
    (*lSisReg3Regreso) << new SiscomCampo3(*lchrPtrCampos,va_arg(lvLCampos,char *)); 
    lchrPtrCampos++;
 }
 va_end(lvLCampos);

 return lSisReg3Regreso;
}
/* Viernes 6 de septiembre del 2013 
 * cadena de entrada "adfafd[Cadenita]llllll"
 *
 */
const char *SiscomDesarrollo3Qt::CadenaEntreSeparadores(
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


