#include <QCtrlStock.h>

#include <zReportesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <zStockTienda.h>


QCtrlStock::QCtrlStock( QWidget *parent, const char *name )
    : QTable( parent, name ),
    zSisRegStock(0)

{
	ConectaSlots();
}
void QCtrlStock::IniciaVariables()
{
 FormaEncabezado();
}
void QCtrlStock::MuestraStock()
{
int lintContador=1;
if(zLstStock->PrimerProveedor())
{
  do
  {
        setNumRows(lintContador);
        setText(lintContador-1,0,zLstStock->NumeroProveedor());
        setText(lintContador-1,1,zLstStock->RazonSocial());
        lintContador=MuestraProductosProveedor(lintContador);
	//lintContador=MuestraTotalProveedor(lintContador);
        lintContador++;
  }while(zLstStock->SiguienteProveedor());

zSiscomQt3::AjustaColumnasTabla(this);
}
}
int QCtrlStock::MuestraProductosProveedor(int pintContador)
{
int lintContador=pintContador+1;
  if(zLstStock->PrimerProducto())
 {
         do
         {
                setNumRows(lintContador);
                setText(lintContador-1,2,zLstStock->Numero());
                setText(lintContador-1,3,zLstStock->Nombre());
                setText(lintContador-1,4,zLstStock->Modelo());
		setText(lintContador-1,5,zLstStock->Stock());
		if(intConCosto)
		{
                setText(lintContador-1,6,zLstStock->CostoNeto());
		setText(lintContador-1,7,zLstStock->ImporteCosto());
		}
                lintContador++;
         }while(zLstStock->SiguienteProducto());
  }
return lintContador-1;
}
void QCtrlStock::IniciaControl()
{
	FormaEncabezado();
	ConsultaStock();
	MuestraStock();
	setReadOnly(true);
}
void QCtrlStock::ReConsultando()
{
    ConsultaStock();
    MuestraStock();
}
void QCtrlStock::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlStock::ConsultaStock()
{
zReportesServiSNTE lzRepServiSNTE(zSisConexion,"StockTienda");
zLstStock=lzRepServiSNTE.StockTienda(zSisRegTienda,zSisRegProveedor );
zLstStock->Tienda(zSisRegTienda);
}
void QCtrlStock::ConectaSlots()
{
}
void QCtrlStock::Tienda(zSiscomRegistro *pzSisRegTienda)
{  
	zSisRegTienda=pzSisRegTienda;
}

void QCtrlStock::Proveedor(zSiscomRegistro *pzSisRegProveedor)
{
	zSisRegProveedor=pzSisRegProveedor;
}
void QCtrlStock::FormaEncabezado()
{
  if(intConCosto)
   setNumCols(8);
   else
   setNumCols(6);

  horizontalHeader()->setLabel(0,"#Proveedor");
  horizontalHeader()->setLabel(1,"Proveedor");
  horizontalHeader()->setLabel(2,"#Producto");
  horizontalHeader()->setLabel(3,"Descripcion Producto");
  horizontalHeader()->setLabel(4,"Modelo");
  horizontalHeader()->setLabel(5,"Stock");
  if(intConCosto)
  {
  horizontalHeader()->setLabel(6,"Costo");
  horizontalHeader()->setLabel(7,"Imp. Costo");
  }
}
void QCtrlStock::ConCosto(int pintConCosto)
{
	intConCosto=pintConCosto;
}
