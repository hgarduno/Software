#include <QCtrlExistenciaProveedor.h>

#include <zReportesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <zExistenciaProveedor.h>


QCtrlExistenciaProveedor::QCtrlExistenciaProveedor( QWidget *parent, const char *name )
    : QTable( parent, name ),
    zSisRegProveedor(0),
    zSisRegProducto(0)

{
	ConectaSlots();
}
void QCtrlExistenciaProveedor::IniciaVariables()
{
 FormaEncabezado();
	setReadOnly(true);
}
void QCtrlExistenciaProveedor::IniciaControl()
{
	if(intTipoVista==0)
	ConsultandoSaldosMovimientos();

	/*
	FormaEncabezado();
	Consultando();
	*
	*/
}

void QCtrlExistenciaProveedor::TipoVista(int pintTipoVista)
{
   intTipoVista=pintTipoVista;
}
void QCtrlExistenciaProveedor::ReConsultando()
{
	
}
void QCtrlExistenciaProveedor::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlExistenciaProveedor::Consultando()
{
	Consulta();
	Muestra();
}
void QCtrlExistenciaProveedor::Consulta()
{
}

void QCtrlExistenciaProveedor::ConectaSlots()
{
}
void QCtrlExistenciaProveedor::Producto(zSiscomRegistro *pzSisRegProducto)
{
     zSisRegProducto=pzSisRegProducto;
}
void QCtrlExistenciaProveedor::Proveedor(zSiscomRegistro *pzSisRegProveedor)
{
	zSisRegProveedor=pzSisRegProveedor;
}
void QCtrlExistenciaProveedor::FormaEncabezado()
{
  setNumCols(8);
  horizontalHeader()->setLabel(0,"#Proveedor");
  horizontalHeader()->setLabel(1,"Proveedor");
  horizontalHeader()->setLabel(2,"#Producto");
  horizontalHeader()->setLabel(3,"Descripcion Producto");
  horizontalHeader()->setLabel(4,"Modelo");
  horizontalHeader()->setLabel(5,"ExistenciaProveedor");
}


void QCtrlExistenciaProveedor::Muestra()
{
int lintContador=1;
if(zExiProveedor->PrimerProducto())
{
	do 
	{
	  setNumRows(lintContador);
	  setText(lintContador-1,0,zExiProveedor->NumeroProducto());
	  setText(lintContador-1,1,zExiProveedor->NombreProducto());
	  setText(lintContador-1,2,zExiProveedor->Modelo());
	  lintContador=MuestraExistenciaTienda(lintContador); 
	  lintContador=MuestraTotalExistencia(lintContador); 
	  lintContador++;
	}while(zExiProveedor->SiguienteProducto());

}
}
int QCtrlExistenciaProveedor::MuestraExistenciaTienda(int pintContador)
{
int lintContador=pintContador+1;
 if(zExiProveedor->PrimerTienda())
 {
	do
	{	
		setNumRows(lintContador);
		setText(lintContador-1,3,zExiProveedor->IdTienda());
		setText(lintContador-1,4,zExiProveedor->Nombre());
		setText(lintContador-1,5,zExiProveedor->Stock());
		setText(lintContador-1,6,zExiProveedor->Existencia());
		lintContador++;
	}while(zExiProveedor->SiguienteTienda());
 }
return lintContador-1;
}
int QCtrlExistenciaProveedor::MuestraStockExistencia(int pintContador)
{
       	setNumRows(pintContador);
	setText(pintContador,5,zExiProveedor->Stock());
	setText(pintContador,6,zExiProveedor->Existencia());
	return pintContador+1;
}
int QCtrlExistenciaProveedor::MuestraTotalExistencia(int pintContador)
{
       	setNumRows(pintContador+1);
	setText(pintContador,4,"Total Producto");
	setText(pintContador,5,zExiProveedor->TotalStock());
	setText(pintContador,6,zExiProveedor->TotalExistencia());
	return pintContador+1;
}
void QCtrlExistenciaProveedor::ConsultandoSaldosMovimientos()
{
	ConsultaSaldosMovimientos();
	MuestraFormatoSaldosMovimientos();
}
void QCtrlExistenciaProveedor::ConsultaSaldosMovimientos()
{
zReportesServiSNTE lzRepServiSNTE(zSisConexion,"ExistenciasProveedor");
zExiProveedor=lzRepServiSNTE.ExistenciaProveedor(zSisRegProveedor,zSisRegProducto);
}
void QCtrlExistenciaProveedor::MuestraFormatoSaldosMovimientos()
{
   EncabezadoSaldosMovimientos();
   SaldosMovimientos();
}
void QCtrlExistenciaProveedor::SaldosMovimientos()
{
int lintContador=0;
if(zExiProveedor->PrimerProducto())
{
    do
    {
	MuestraTiendasSaldosMovimientos(lintContador);

    }while(zExiProveedor->SiguienteProducto());

}
}
int QCtrlExistenciaProveedor::MuestraTiendasSaldosMovimientos(int pintContador)
{
if(zExiProveedor->PrimerTienda())
{
	do
	{
		setNumRows(pintContador+1);
		setText(pintContador,0,zExiProveedor->Siglas());
		setText(pintContador,1,zExiProveedor->Nombre());
		setText(pintContador,2,zExiProveedor->Stock());
		setText(pintContador,3,zExiProveedor->Existencia());
		pintContador++;
	}while(zExiProveedor->SiguienteTienda());
}
}
void QCtrlExistenciaProveedor::EncabezadoSaldosMovimientos()
{
  setNumCols(4);
  horizontalHeader()->setLabel(0,"#Tienda");
  horizontalHeader()->setLabel(1,"Nombre");
  horizontalHeader()->setLabel(2,"Stock");
  horizontalHeader()->setLabel(3,"Existencia");
}
zExistenciaProveedor *QCtrlExistenciaProveedor::ExistenciaProveedor()
{
	return zExiProveedor;
}
