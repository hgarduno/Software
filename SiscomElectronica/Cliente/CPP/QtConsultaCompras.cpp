#include <QtConsultaCompras.h>
#include <IMP_QControlFecha.h>

#include <qpushbutton.h>
#include <qtable.h> 

#include <zSiscomQt3.h>

#include <zCompras.h> 
#include <zCompra.h>
#include <zProductos.h>

#include <zSiscomDesarrollo4.h>


QtConsultaCompras::QtConsultaCompras(QWidget *pQWParent,
				     const char *pchrPtrName,
				     WFlags pWFlags):
		   ConsultaCompras(pQWParent,pchrPtrName,pWFlags)
{

IniciaVariables();
ConectaSlots();
}
void QtConsultaCompras::IniciaVariables()
{
 IniciaFechas();

 zComsSiscom=new zCompras;
}
void QtConsultaCompras::IniciaFechas()
{
QCtrFechaIni->ColocaFechaHoy();
QCtrFechaFin->ColocaFechaHoy();
QCtrFechaIni->setFocus();
}

void QtConsultaCompras::ConectaSlots()
{
connect(QCtrFechaIni,
        SIGNAL(Signal_EnterA_o()),
        SLOT(SlotFocoAFechaFin()));

connect(QCtrFechaFin,
        SIGNAL(Signal_EnterA_o()),
        SLOT(SlotFocoAConsulta()));

connect(QPBConsulta,
	SIGNAL(clicked()),
	SLOT(SlotConsulta()));

connect(QTCompras,
	SIGNAL(doubleClicked(int,int,int,const QPoint &)),
	SLOT(SlotDetalleCompra(int,int,int,const QPoint &)));
}
void QtConsultaCompras::SlotDetalleCompra(int pintCompra,
					  int,
					  int,
					  const QPoint &)
{
zCompra *lzCompra;
  if((lzCompra=Compra(pintCompra)))
  MuestraDetalleCompra(lzCompra);

}
void QtConsultaCompras::SlotFocoAConsulta()
{
 zSiscomQt3::Foco(QPBConsulta);
}
void QtConsultaCompras::SlotConsulta()
{
 Consultando();
}
void QtConsultaCompras::SlotFocoAFechaFin()
{
  zSiscomQt3::Foco(QCtrFechaFin);
}

void QtConsultaCompras::Consulta()
{

}
void QtConsultaCompras::Consultando()
{
  Consulta();
  Muestra();
}
void QtConsultaCompras::Muestra()
{
const char *lchrPtrCampos[]={"IdCompra",
		       "Fecha",
		       "Importe",
		       0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,Compras(),QTCompras);
}
zCompras *QtConsultaCompras::Compras()
{
   return zComsSiscom;
}

void QtConsultaCompras::MuestraDetalleCompra(zCompra *pzCompra)
{
const char *lchrPtrCampos[]={"Clave", 
			    "Cantidad",
			    "Precio",
			    "PrecioTotal",
			    0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,
			pzCompra->Productos(),
			QTDetalle);

}
zCompra *QtConsultaCompras::Compra(int pintCompra)
{
  if(pintCompra!=-1)
  return (zCompra *)(*Compras())[pintCompra];
  else
  return 0;


}
