#include <QCtrlConceptosSaldosMovimientos.h>
#include <zOperacionesSaldosMovimientos.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <zStockTienda.h>


QCtrlConceptosSaldosMovimientos::QCtrlConceptosSaldosMovimientos( QWidget *parent, const char *name )
    : QTable( parent, name )

{
	ConectaSlots();
}
void QCtrlConceptosSaldosMovimientos::IniciaVariables()
{
setReadOnly(true);
}
void QCtrlConceptosSaldosMovimientos::IniciaControl()
{
	Consultando();  
}
void QCtrlConceptosSaldosMovimientos::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlConceptosSaldosMovimientos::ConectaSlots()
{
	connect(this,	
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotMes(int,int,int,const QPoint &)));

}
void QCtrlConceptosSaldosMovimientos::SlotMes(int pintMes,
				        int,
					int,
					const QPoint &)
{
emit SignalMes(pintMes+1);
}
void QCtrlConceptosSaldosMovimientos::Producto(zSiscomRegistro *pzSisRegProducto)
{
	zSisRegProducto=pzSisRegProducto;
}
void QCtrlConceptosSaldosMovimientos::Tienda(zSiscomRegistro *pzSisRegTienda)
{
	zSisRegTienda=pzSisRegTienda;
}
void QCtrlConceptosSaldosMovimientos::FormaEncabezado()
{
  setNumCols(6);
  horizontalHeader()->setLabel(0,"Fecha");
  horizontalHeader()->setLabel(1,"Concepto");
  horizontalHeader()->setLabel(2,"Folio");
  horizontalHeader()->setLabel(3,"Ent");
  horizontalHeader()->setLabel(4,"Sal");
  horizontalHeader()->setLabel(5,"Saldo");
  horizontalHeader()->setLabel(5,"Documento");
}
void QCtrlConceptosSaldosMovimientos::Consultando()
{
FormaEncabezado();
Consulta();
//Muestra();
}
void QCtrlConceptosSaldosMovimientos::Consulta()
{
zOperacionesSaldosMovimientos lzOpSaldosMovimientos(zSisConexion,"ConceptosSaldosMovimientos");
zSisRegsConceptosSaldosMovimientos=lzOpSaldosMovimientos.ConceptosSaldosMovimientos(zSisRegTienda,zSisRegProducto);
}
void QCtrlConceptosSaldosMovimientos::Muestra()
{
const char *lchrPtrCampos[]={"Mes","Salidas","Entradas","Existencia",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,
			zSisRegsConceptosSaldosMovimientos,
			this);
}
