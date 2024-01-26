#include <QtImprimeReciboApartado.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionApartado.h>
#include <zOperacionesServiSNTE.h>
#include <zSiscomRegistros.h>
#include <zSiscomConexion.h>
#include <qprinter.h>
#include <qpainter.h>
#include <stdlib.h>
QtImprimeReciboApartado::QtImprimeReciboApartado(zSiscomConexion *pzSisConexion,
					 QWidget *pQWParent,
					 const char *pchrPtrName):
					 QWidget(pQWParent,pchrPtrName),
					 QtBaseMedidas(pQWParent,pchrPtrName),
					 zSisConexion(pzSisConexion)
{


}
void QtImprimeReciboApartado::Imprime()
{
QPrinter lQPImpresora;
QPainter lQPainter;
QFont font("Roman",8);
font.setBold(true);
	if(ImprimeAArchivo())	
	{
	 lQPImpresora.setOutputToFile(true);
	  lQPImpresora.setOutputFileName("ServiSNTE.ps");
	 }
	 //if(lQPImpresora.setup())
	 {
	   lQPainter.setFont(font);
	   if(lQPainter.begin(&lQPImpresora))
	   {
		Painter(&lQPainter);
		InicializaMedidas();
		ConsultaPosiciones();
		ImprimeReciboApartado();
	   }
	  }
}
int QtImprimeReciboApartado::ImprimeAArchivo()
{
const char *lchrPtrImprimeReciboApartadoAArchivo;

if((lchrPtrImprimeReciboApartadoAArchivo=getenv("ImprimeReciboApartadoAArchivo")))
return 1;
else
return 0;

}
void QtImprimeReciboApartado::ConsultaPosiciones()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"PosicionesReciboApartado");
zSisRegsPosiciones=lzOpServiSNTE.CamposImpresionReciboApartado();
SiscomRegistrosLog(zSisRegsPosiciones);
}
void QtImprimeReciboApartado::ImprimeReciboApartado()
{

LogSiscom("Imprimiendo el recibo de apartado");
zSiscomRegistro *lzSisRegRegistro;
for(lzSisRegRegistro=zSisRegsPosiciones->Primer();
    lzSisRegRegistro;
    lzSisRegRegistro=zSisRegsPosiciones->Siguiente())
{
 LogSiscom("(%s,%s) AnchoX:%s AnchoY:%s %s",
 	    lzSisRegRegistro->Campo("x"),
	    lzSisRegRegistro->Campo("y"),
	    lzSisRegRegistro->Campo("anchox"),
	    lzSisRegRegistro->Campo("anchoy"),
	    lzSisRegRegistro->Campo("campo"));
   Texto(lzSisRegRegistro->CampoInt("x"),
   	 lzSisRegRegistro->CampoInt("y"),
	 lzSisRegRegistro->CampoInt("anchox"),
	 lzSisRegRegistro->CampoInt("anchoy"),
	 zImpReciboApartado->Dato((const char *)lzSisRegRegistro->Campo("campo")));
}
}
void QtImprimeReciboApartado::ImpresionApartado(zImpresionApartado *pzImpReciboApartado)
{
	zImpReciboApartado=pzImpReciboApartado;
}
 
