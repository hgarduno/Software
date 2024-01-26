#include <QtImprimePuntoVenta.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionPuntoVenta.h>
#include <zOperacionesServiSNTE.h>
#include <zSiscomRegistros.h>
#include <zSiscomConexion.h>
#include <zSiscomQt3.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qmessagebox.h>
#include <stdlib.h>
QtImprimePuntoVenta::QtImprimePuntoVenta(zSiscomConexion *pzSisConexion,
					 QWidget *pQWParent,
					 const char *pchrPtrName):
					 QWidget(pQWParent,pchrPtrName),
					 QtBaseMedidas(pQWParent,pchrPtrName),
					 zSisConexion(pzSisConexion)
{


}
void QtImprimePuntoVenta::Imprime()
{
QPrinter lQPImpresora(QPrinter::HighResolution);
QPainter lQPainter;
QFont font;
ObtenTipoLetra(&font);
	if(ImprimeAArchivo())	
	{
	 lQPImpresora.setOutputToFile(true);
	  lQPImpresora.setOutputFileName("ServiSNTE.ps");
	 }
	   if(lQPainter.begin(&lQPImpresora))
	   {
		Painter(&lQPainter);
		Letra(font);
		InicializaMedidas();
		ConsultaPosiciones();
		ImprimeFacturaPuntoVenta();
	   }
}
int QtImprimePuntoVenta::ImprimeAArchivo()
{
const char *lchrPtrImprimePuntoVentaAArchivo;

if((lchrPtrImprimePuntoVentaAArchivo=getenv("ImprimePuntoVentaAArchivo")))
return 1;
else
return 0;

}
void QtImprimePuntoVenta::ConsultaPosiciones()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"PosicionesPuntoVenta");
zSisRegsPosiciones=lzOpServiSNTE.CamposImpresionPuntoVenta();
}
void QtImprimePuntoVenta::ImprimeFacturaPuntoVenta()
{
zSiscomRegistro *lzSisRegRegistro;
for(lzSisRegRegistro=zSisRegsPosiciones->Primer();
    lzSisRegRegistro;
    lzSisRegRegistro=zSisRegsPosiciones->Siguiente())
  if(lzSisRegRegistro->CampoInt("idtipocampo")==1)
	ImprimeProductosFactura(lzSisRegRegistro->AsociadosDelCampo("registrocampo"));
  else
   Texto(lzSisRegRegistro->CampoInt("x"),
   	 lzSisRegRegistro->CampoInt("y"),
	 lzSisRegRegistro->CampoInt("anchox"),
	 lzSisRegRegistro->CampoInt("anchoy"),
	 zImpPuntoVenta->Dato((const char *)lzSisRegRegistro->Campo("campo")));
}
void QtImprimePuntoVenta::Venta(zImpresionPuntoVenta *pzImpPuntoVenta)
{
	zImpPuntoVenta=pzImpPuntoVenta;
}
void QtImprimePuntoVenta::ImprimeProductosFactura(zSiscomRegistros *pzSisRegsCamposRegistro)
{
zImpPuntoVenta->PrimerProducto();
int lintDesplazamientoY=0;
do
{
   ImprimeCamposProducto(lintDesplazamientoY,pzSisRegsCamposRegistro);  
   lintDesplazamientoY+=5;

}while(zImpPuntoVenta->SiguienteProducto());
}
void QtImprimePuntoVenta::ImprimeCamposProducto(int pintDesplazamientoY,
						zSiscomRegistros *pzSisRegsCamposRegistro)
{
zSiscomRegistro *lzSisRegProducto;
for(lzSisRegProducto=pzSisRegsCamposRegistro->Primer();
    lzSisRegProducto;
    lzSisRegProducto=pzSisRegsCamposRegistro->Siguiente())
{
   Texto(lzSisRegProducto->CampoInt("x"),
   	 pintDesplazamientoY+lzSisRegProducto->CampoInt("y"),
	 lzSisRegProducto->CampoInt("anchox"),
	 lzSisRegProducto->CampoInt("anchoy"),
	 zImpPuntoVenta->CampoProducto((const char *)lzSisRegProducto->Campo("campo")));

}

}

int QtImprimePuntoVenta::TamanoLetra()
{
const char *lchrPtrTamanoLetra;
if((lchrPtrTamanoLetra=getenv("TAMANIO_FONT_IMPRESION")))
return atoi(lchrPtrTamanoLetra);
else
return 8;
}
void QtImprimePuntoVenta::ObtenTipoLetra(QFont *pQFTipoLetra)
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
