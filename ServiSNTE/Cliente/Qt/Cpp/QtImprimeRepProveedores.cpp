#include <QtImprimeRepProveedores.h>

#include <zOperacionesServiSNTE.h> 

#include <zSiscomDesarrollo4.h>
#include <zImpresionProveedores.h>
#include <zProveedores.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qmessagebox.h>

QtImprimeRepProveedores::QtImprimeRepProveedores(zSiscomConexion *pzSisConexion,
							 zImpresionProveedores *pzImpProveedores,
							 QWidget *pQWParent,
							 const char *pchrPtrName):
							QtImprimeReporte(pzSisConexion,
									pzImpProveedores,
									pQWParent,
									pchrPtrName),
							zImpProveedores(pzImpProveedores),
							intIncrementoY(5)
{
ConsultaPosiciones();

}
void QtImprimeRepProveedores::Imprimiendo()
{
Cabecera();
Reporte();
}
void QtImprimeRepProveedores::Reporte()
{
Proveedores();
}
void QtImprimeRepProveedores::Proveedores()
{
int lintDesplazamientoY=0;
zSiscomRegistro *lzSisRegProveedor=(*zSisRegsPosiciones)[11];
zSiscomRegistros *lzSisRegsProveedor=lzSisRegProveedor->AsociadosDelCampo("registrocampo");
while((zImpProveedores->Proveedores()->SiguienteProveedor()))
{
  if(Texto(lintDesplazamientoY,
  	lzSisRegsProveedor,
	zImpProveedores->Proveedores()->Proveedor()))
   {
	NumeroPagina(&lintDesplazamientoY);
	lintDesplazamientoY=0;
   }
   else
   {
  TelefonosProveedor(lintDesplazamientoY);  
  lintDesplazamientoY+=18;
  }
}
}
void QtImprimeRepProveedores::TelefonosProveedor(int pintDesplazamientoY)
{
int lintX=0;
zSiscomRegistro *lzSisRegTelefonos=(*zSisRegsPosiciones)[12];
zSiscomRegistros *lzSisRegsTelefonos=lzSisRegTelefonos->AsociadosDelCampo("registrocampo");
  while(zImpProveedores->Proveedores()->SiguienteTelefono())
  {
     TextoXY(lintX,
     	     pintDesplazamientoY,
	     lzSisRegsTelefonos,
	     zImpProveedores->Proveedores()->Telefono());
     lintX+=20;

  }
}
void QtImprimeRepProveedores::ConsultaPosiciones()
{
zOperacionesServiSNTE lzOpServiSNTE(Conexion(),"PosicionesProveedores");
zSisRegsPosiciones=lzOpServiSNTE.CamposImpresionProveedores();
SiscomRegistrosLog(zSisRegsPosiciones);
}
void QtImprimeRepProveedores::Cabecera()
{
zSiscomRegistro *lzSisRegPosiciones;

for(lzSisRegPosiciones=zSisRegsPosiciones->Primer();
    lzSisRegPosiciones;
    lzSisRegPosiciones=zSisRegsPosiciones->Siguiente())
  Texto(lzSisRegPosiciones,zImpProveedores);

}

