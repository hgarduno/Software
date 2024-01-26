#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomTableItem.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qpushbutton.h>
#include <string.h>
#include <stdlib.h>
#include <qfont.h>
#include <qfile.h>
#include <qdatastream.h>

zSiscomQt3::zSiscomQt3()
{

}

QLineEdit *zSiscomQt3::EditAlCombo(QComboBox *pQCBCombo,const char *pchrPtrName)
{
    QLineEdit *lQLERegreso=new QLineEdit(pQCBCombo,pchrPtrName);
	pQCBCombo->setLineEdit(lQLERegreso);
	return lQLERegreso;
}

void zSiscomQt3::RegistrosAlCombo(QComboBox *pQCBCombo,
				  const char *pchrPtrCampo,
				  zSiscomRegistros *pzSisRegistros)
{
zSiscomRegistro *lzSisRegistro;
for(lzSisRegistro=pzSisRegistros->Primer();
    lzSisRegistro;
    lzSisRegistro=pzSisRegistros->Siguiente())
{
	pQCBCombo->insertItem((const char *)lzSisRegistro->Campo(pchrPtrCampo));

}

}

void zSiscomQt3::Foco(QLineEdit *pQLEControl)
{
	pQLEControl->selectAll();
	pQLEControl->setFocus();
}

void zSiscomQt3::Foco(QTextEdit *pQTEControl)
{
   pQTEControl->selectAll();
   pQTEControl->setFocus();
}

void zSiscomQt3::Foco(QPushButton *pQPBControl)
{
   pQPBControl->setFocus();
}

void zSiscomQt3::Foco(QWidget *pQWidget)
{
  pQWidget->setFocus();
}

const char *zSiscomQt3::Texto(QLineEdit *pQLEControl)
{
if(pQLEControl->text().isEmpty())
return 0;
else
return (const char *)pQLEControl->text();
}
int zSiscomQt3::TextoValido(QLineEdit *pQLEControl)
{
/*
  return !pQLEControl->text().isEmpty() &&
         !pQLEControl->text().isNull() ;
*/
	return TextoValido(pQLEControl->text());
}
int zSiscomQt3::TextoValido(const QString &pQStrTexto)
{
  return !pQStrTexto.isEmpty() &&
         !pQStrTexto.isNull() ;
}
int zSiscomQt3::TextoValido(QTextEdit *pQTETexto)
{

   return zSiscomQt3::TextoValido(pQTETexto->text());
}

const char *zSiscomQt3::Texto(QTextEdit *pQTEControl)
{
if(pQTEControl->text().isEmpty())
return 0;
else
return strdup((const char *)(pQTEControl->text()));
}

void zSiscomQt3::LlenaTabla(const char *pchrPtrCampos[],
			    zSiscomRegistros *pzSisRegistros,
			    QTable *pQTDatos)
{
const char **lchrPtrCampos=pchrPtrCampos;
int lintFilas,lintColumnas;
zSiscomRegistro *lzSisRegistro;
pQTDatos->setNumRows(pzSisRegistros->NNodos());
for(lzSisRegistro=pzSisRegistros->Primer(),
    lintFilas=0;
    lzSisRegistro;
    lzSisRegistro=pzSisRegistros->Siguiente(),
    lintFilas++)
{
   for(lintColumnas=0;
       *lchrPtrCampos;
       lchrPtrCampos++,
       lintColumnas++)
  pQTDatos->setText(lintFilas,lintColumnas,(const char *)lzSisRegistro->Campo(*lchrPtrCampos));
  lchrPtrCampos=pchrPtrCampos;
}
zSiscomQt3::AjustaColumnasTabla(pQTDatos);
}

void zSiscomQt3::LimpiaTabla(QTable *pQTable)
{
    while (pQTable->numRows())
        pQTable->removeRow(0);
}

void zSiscomQt3::RegistrosSeleccionados(QTable *pQTDatos,
				        zSiscomRegistros *pzSisRegistros,
					zSiscomRegistros *pzSisRegsSeleccionados)
{
int lintContador,
	lintNRegistros=pzSisRegistros->NNodos();
for(lintContador=0;
    lintContador<lintNRegistros;
    lintContador++)
{
if(pQTDatos->isRowSelected(lintContador,true))
(*pzSisRegsSeleccionados) << (*pzSisRegistros)[lintContador];
}
}

void zSiscomQt3::SiscomALetra(double lfltDato, char **pchrArrALetraPtr)
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
    *pchrArrALetraPtr = (char *) malloc(sizeof(char)*strlen(lchrArrNumeroALetra));
    strcpy(*pchrArrALetraPtr,lchrArrNumeroALetra);
}

void zSiscomQt3::SiscomALetraSinDecimal(double lfltDato, char **pchrArrALetraPtr)
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

void zSiscomQt3::ALUnidades(char *pchrArrNumeroLetra, char *pchrArrNumero)
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

void zSiscomQt3::ALDecenas(char *pchrArrNumeroLetra, char *pchrArrNumero)
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

void zSiscomQt3::ALCentenas(char *pchrArrNumeroLetra, char *pchrArrNumero)
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

void zSiscomQt3::ALMillares(char *pchrArrNumeroLetra, char *pchrArrNumero)
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

void zSiscomQt3::ALMillones(char *pchrArrNumeroLetra, char *pchrArrNumero)
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

void zSiscomQt3::AjustaFilasTabla(QTable *pQTDatos)
{
int lintContador;
	for(lintContador=0;
		lintContador<pQTDatos->numRows();
		lintContador++)
	  pQTDatos->adjustRow(lintContador);
}
void zSiscomQt3::AjustaColumnasTabla(QTable *pQTDatos)
{
int lintContador;
	for(lintContador=0;
		lintContador<pQTDatos->numCols();
		lintContador++)
	  pQTDatos->adjustColumn(lintContador);
}

int zSiscomQt3::LeeTipoLetra(const char *pchrPtrArchivo,
			      QFont *pQFTipoLetra)
{
bool lbAbrirArchivo;
QFile lQFleTipoLetra(pchrPtrArchivo);
if((lbAbrirArchivo=lQFleTipoLetra.open(IO_ReadOnly)))
{
QDataStream lQDSGuarda(&lQFleTipoLetra);
  lQDSGuarda >> *pQFTipoLetra;
  lQFleTipoLetra.close();
return 1;
}
else 
return 0;
}
int zSiscomQt3::GuardaTipoLetra(const char *pchrPtrArchivo,
				  QFont *pQFTipoLetra)
{
bool lbAbriArchivo;
QFile lQFleTipoLetra(pchrPtrArchivo);
if((lQFleTipoLetra.open(IO_WriteOnly)))
{
QDataStream lQDSGuarda(&lQFleTipoLetra);
  lQDSGuarda<< *pQFTipoLetra;
  lQFleTipoLetra.close();
return 1;
}
else
return 0;
}
void zSiscomQt3::HabilitaPasaFoco(QWidget *pQWControl)
{
   pQWControl->setEnabled(true);
   Foco(pQWControl);
}


void zSiscomQt3::ColoreaFilas(QTable *pQTDatos,
					   const QColor &pQColor,
					   int *pintPtrFilas)
{
int lintContador;
int lintNFilas;
int lintNColumnas;
int lintContadorJ;
lintNColumnas=pQTDatos->numCols();
zSiscomTableItem *lSisTabItemColor;
for(lintContador=0;
    lintContador<pQTDatos->numRows();
    lintContador++)
{
   if(*(pintPtrFilas+lintContador)==1)
   for(lintContadorJ=0;
       lintContadorJ<lintNColumnas;
       lintContadorJ++)
   {
     lSisTabItemColor=new zSiscomTableItem(
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
