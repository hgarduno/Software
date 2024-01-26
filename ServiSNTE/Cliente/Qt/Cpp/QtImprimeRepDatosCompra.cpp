#include <QtImprimeRepDatosCompra.h>

#include <zOperacionesServiSNTE.h> 

#include <zSiscomDesarrollo4.h>
#include <zImpresionDatosCompra.h>
#include <zDatosCompra.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qmessagebox.h>

QtImprimeRepDatosCompra::QtImprimeRepDatosCompra(zSiscomConexion *pzSisConexion,
							 zImpresionDatosCompra *pzImpDatosCompra,
							 QWidget *pQWParent,
							 const char *pchrPtrName):
							QtImprimeReporte(pzSisConexion,
									pzImpDatosCompra,
									pQWParent,
									pchrPtrName),
							zImpDatosCompra(pzImpDatosCompra),
							intIncrementoY(5)
{
ConsultaPosiciones();

}
void QtImprimeRepDatosCompra::Imprimiendo()
{
Cabecera();
Reporte();
}
void QtImprimeRepDatosCompra::Reporte()
{
Departamento();
Proveedor();
Telefonos();
Productos();
}
void QtImprimeRepDatosCompra::ConsultaPosiciones()
{
zOperacionesServiSNTE lzOpServiSNTE(Conexion(),"PosicionesDatosCompra");
zSisRegsPosiciones=lzOpServiSNTE.CamposImpresionDatosCompra();
SiscomRegistrosLog(zSisRegsPosiciones);
}
void QtImprimeRepDatosCompra::Cabecera()
{
zSiscomRegistro *lzSisRegPosiciones;

for(lzSisRegPosiciones=zSisRegsPosiciones->Primer();
    lzSisRegPosiciones;
    lzSisRegPosiciones=zSisRegsPosiciones->Siguiente())
  Texto(lzSisRegPosiciones,zImpDatosCompra);

}

void QtImprimeRepDatosCompra::Departamento()
{
zSiscomRegistro *lzSisRegDepartamento=(*zSisRegsPosiciones)[21];
zSiscomRegistros *lzSisRegsDepartamento=lzSisRegDepartamento->AsociadosDelCampo("registrocampo");
Texto(0,lzSisRegsDepartamento,zImpDatosCompra->Departamento());
}

void QtImprimeRepDatosCompra::Proveedor()
{
zSiscomRegistro *lzSisRegProveedor=(*zSisRegsPosiciones)[23];
zSiscomRegistros *lzSisRegsProveedor=lzSisRegProveedor->AsociadosDelCampo("registrocampo");
Texto(0,lzSisRegsProveedor,zImpDatosCompra->DatosCompra()->Proveedor());
}
void QtImprimeRepDatosCompra::Telefonos()
{
zSiscomRegistro *lzSisRegTelefono=(*zSisRegsPosiciones)[24];
zSiscomRegistros *lzSisRegsTelefono=lzSisRegTelefono->AsociadosDelCampo("registrocampo");
zSiscomRegistros *lzSisRegsTelefonos=zImpDatosCompra->DatosCompra()->Telefonos();
zSiscomRegistro *lzSisRegDatTelefono;
int lintDesplazamientoX=0;
for(lzSisRegDatTelefono=lzSisRegsTelefonos->Primer();
    lzSisRegDatTelefono;
    lzSisRegDatTelefono=lzSisRegsTelefonos->Siguiente(),
    lintDesplazamientoX+=20)
 TextoXY(lintDesplazamientoX,0,lzSisRegsTelefono,lzSisRegDatTelefono);
}

void QtImprimeRepDatosCompra::Productos()
{
zSiscomRegistro *lzSisRegProducto=(*zSisRegsPosiciones)[22];
zSiscomRegistros *lzSisRegsProducto=lzSisRegProducto->AsociadosDelCampo("registrocampo");
zSiscomRegistros *lzSisRegsProductos=zImpDatosCompra->DatosCompra()->Productos();
zSiscomRegistro *lzSisRegDatProducto;
int lintDesplazamientoY=0;
for(lzSisRegDatProducto=lzSisRegsProductos->Primer();
    lzSisRegDatProducto;
    lzSisRegDatProducto=lzSisRegsProductos->Siguiente(),
    lintDesplazamientoY+=5)
 Texto(lintDesplazamientoY,lzSisRegsProducto,lzSisRegDatProducto);


}
