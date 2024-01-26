#include <QtImprimeTransferencia2.h>
#include <zSiscomDesarrollo4.h>
#include <zImpresionTransferencia.h>
#include <zOperacionesServiSNTE.h>
#include <zSiscomRegistros.h>
#include <zSiscomConexion.h>
#include <qprinter.h>
#include <qpainter.h>
#include <stdlib.h>
QtImprimeTransferencia2::QtImprimeTransferencia2(zSiscomConexion *pzSisConexion,
					 QWidget *pQWParent,
					 const char *pchrPtrName):
					 QWidget(pQWParent,pchrPtrName),
					 QtBaseMedidas(pQWParent,pchrPtrName),
					 zSisConexion(pzSisConexion)
{


}
void QtImprimeTransferencia2::Imprime()
{
QPrinter lQPImpresora;
QPainter lQPainter;
QFont font("Roman",8);
font.setBold(true);
	if(ImprimeAArchivo())	
	{
	 lQPImpresora.setOutputToFile(true);
	  lQPImpresora.setOutputFileName("ServiSNTE.ps");
	  lQPImpresora.setPageSize(QPrinter::Legal);
	 }
	   lQPainter.setFont(font);
	   if(lQPainter.begin(&lQPImpresora))
	   {
		Painter(&lQPainter);
		InicializaMedidas();
		ConsultaPosiciones();
		ImprimeTransferencia2();
	   }
}
int QtImprimeTransferencia2::ImprimeAArchivo()
{
const char *lchrPtrImprimeTransferencia2AArchivo;

if((lchrPtrImprimeTransferencia2AArchivo=getenv("ImprimeTransferenciaAArchivo")))
return 1;
else
return 0;

}
void QtImprimeTransferencia2::ConsultaPosiciones()
{
zOperacionesServiSNTE lzOpServiSNTE(zSisConexion,"PosicionesTransferencia");
zSisRegsPosiciones=lzOpServiSNTE.CamposImpresionTransferencia();
SiscomRegistrosLog(zSisRegsPosiciones);
}
void QtImprimeTransferencia2::ImprimeTransferencia2()
{

zSiscomRegistro *lzSisRegRegistro;
for(lzSisRegRegistro=zSisRegsPosiciones->Primer();
    lzSisRegRegistro;
    lzSisRegRegistro=zSisRegsPosiciones->Siguiente())
{
if(lzSisRegRegistro->CampoInt("idtipocampo")==1)
ImprimeProductosTransferencia(lzSisRegRegistro->AsociadosDelCampo("registrocampo"));
else
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
	 zImpTransferencia2->Dato((const char *)lzSisRegRegistro->Campo("campo")));
}
}
}
void QtImprimeTransferencia2::ImpresionTransferencia2(zImpresionTransferencia *pzImpTransferencia2)
{
	zImpTransferencia2=pzImpTransferencia2;
}
void QtImprimeTransferencia2::ImprimeCamposProducto(int pintDesplazamientoY,
						    zSiscomRegistros *pzSisRegsCamposRegistro)
{
zSiscomRegistro *lzSisRegProducto;
for(lzSisRegProducto=pzSisRegsCamposRegistro->Primer();
    lzSisRegProducto;
    lzSisRegProducto=pzSisRegsCamposRegistro->Siguiente())
   Texto(lzSisRegProducto->CampoInt("x"),
   	 pintDesplazamientoY+lzSisRegProducto->CampoInt("y"),
	 lzSisRegProducto->CampoInt("anchox"),
	 lzSisRegProducto->CampoInt("anchoy"),
	 zImpTransferencia2->CampoProducto((const char *)lzSisRegProducto->Campo("campo")));
}
void QtImprimeTransferencia2::ImprimeProductosTransferencia(zSiscomRegistros *pzSisRegsProductos)
{
int lintDesplazamientoY=0;
zImpTransferencia2->PrimerProducto();
do
{
	ImprimeCamposProducto(lintDesplazamientoY,pzSisRegsProductos);
	lintDesplazamientoY+=5;
}while(zImpTransferencia2->SiguienteProducto());

}
