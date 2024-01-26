#include <QtImprimeRepStockDepartamentoProveedor.h>
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
QtImprimeRepStockDepartamentoProveedor::QtImprimeRepStockDepartamentoProveedor(
						zSiscomConexion *pzSisConexion,
						zSiscomRegistros *pzSisRegsInformacion,
						QWidget *pQWParent,
						const char *pchrPtrName ):
						QtImprimeReporte(pzSisConexion,
								 pzSisRegsInformacion,
								 pQWParent,
								 pchrPtrName)
{
}
void QtImprimeRepStockDepartamentoProveedor::Imprimiendo()
{
zSiscomRegistro *lzSisRegRegistro;
int lintY,lintContadorY=10;
int lintContadorPagina=0;
for(lzSisRegRegistro=Informacion()->Primer(),
    lintY=30;
    lzSisRegRegistro;
    lzSisRegRegistro=Informacion()->Siguiente(),
    lintY+=5,
    lintContadorY+=5)
{
  Texto(0,lintY,100,40,(const char *)(*lzSisRegRegistro)["numproducto"]);
  Texto(20,lintY,100,40,(const char *)(*lzSisRegRegistro)["nombreproducto"]);
  Texto(80,lintY,100,40,(const char *)(*lzSisRegRegistro)["modelo"]);
  Texto(110,lintY,100,400,(const char *)(*lzSisRegRegistro)["stock"]);
  Texto(120,lintY,100,400,(const char *)(*lzSisRegRegistro)["costoneto"]);
  Texto(140,lintY,100,400,(const char *)(*lzSisRegRegistro)["costototal"]);
  Texto(160,lintY,100,400,(const char *)(*lzSisRegRegistro)["preciogeneral"]);
  Texto(180,lintY,100,400,(const char *)(*lzSisRegRegistro)["totalventa"]);
  Texto(200,lintY,100,400,(const char *)(*lzSisRegRegistro)["margen"]);
  ContadorPagina(&lintY,&lintContadorY,&lintContadorPagina);
}

}
