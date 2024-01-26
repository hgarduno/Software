#include <QtImprimeReporte.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionPuntoVenta.h>
#include <zOperacionesServiSNTE.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistros.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qmessagebox.h>
#include <stdlib.h>
QtImprimeReporte::QtImprimeReporte(zSiscomConexion *pzSisConexion,
				   zSiscomRegistros *pzSisRegsInformacion,
				   QWidget *pQWParent,
				   const char *pchrPtrName ):
				   QScrollView(pQWParent,pchrPtrName),
						QtBaseMedidas(pQWParent,pchrPtrName),
						zSisConexion(pzSisConexion),
						zSisRegsInformacion(pzSisRegsInformacion),
					QPDibujando(0)
{
setResizePolicy(Default);
resizeContents(1920,400000);
viewport()->setBackgroundMode( PaletteBase );
setVScrollBarMode(QScrollView::AlwaysOn);
}

void QtImprimeReporte::Imprime(QPainter *pQPainter)
{
QFont lQFLetra;
QPDibujando=pQPainter;
Painter(pQPainter);
ObtenTipoLetra(&lQFLetra);
Letra(lQFLetra);
InicializaMedidas();
Imprimiendo();
}
void QtImprimeReporte::Imprimiendo()
{
}
void QtImprimeReporte::drawContents(QPainter *pQPainter,
					int,
				int,
				int,
				int)
{
Imprime(pQPainter);
}
void QtImprimeReporte::ObtenTipoLetra(QFont *pQFTipoLetra)
{
char lchrArrNombreArchivo[256];
const char *lchrPtrHome=getenv("HOME");
sprintf(lchrArrNombreArchivo,
	"%s/.ServiSNTE/Impresion.TipoLetra",
	lchrPtrHome);
if(!zSiscomQt3::LeeTipoLetra(lchrArrNombreArchivo,pQFTipoLetra))
{
QString lQStrMensaje;
	lQStrMensaje=QString("No Se encontro el archivo") +
		     "\n"			 +
		     lchrArrNombreArchivo;
QMessageBox::information(this,"Aviso Sistema",lQStrMensaje);
}
}
void QtImprimeReporte::ContadorPagina(int *pintPtrY,
				      int *pintPtrContadorY,
				      int *pintPtrContadorPagina)
{
char lchrArrPagina[20];
    if(*pintPtrContadorY>70)
    {
     LogSiscom("%d %d",*pintPtrContadorY,*pintPtrY);
     (*pintPtrContadorPagina)++;
     (*pintPtrY)+=35;
     sprintf(lchrArrPagina,"Pagina %d",*pintPtrContadorPagina);
     Texto(110,*pintPtrY,100,100,lchrArrPagina);
     *pintPtrContadorY=0;
     (*pintPtrY)+=5;
      if(EsDispositivoExterno())
      {
       *pintPtrY=0;
      ((QPrinter *)QPDibujando->device())->newPage();
      }
    }
}
zSiscomRegistros *QtImprimeReporte::Informacion()
{
   return zSisRegsInformacion;
}
zSiscomConexion *QtImprimeReporte::Conexion()
{
  return zSisConexion;
}
int QtImprimeReporte::EsDispositivoExterno()
{
  if(QPDibujando)
  return QPDibujando->device()->isExtDev()==true;
}
void QtImprimeReporte::Nombre(const char *pchrPtrNombre)
{	
	chrPtrNombre=pchrPtrNombre;
}
const char *QtImprimeReporte::Nombre()
{
	return chrPtrNombre;
}
