#include <QtFacturaContenedor.h>
#include <QCtrlProveedoresSE.h>

#include <zSiscomQt3.h>
#include <zCompraImportacion.h>
#include <zEmpresa.h>


#include <qlineedit.h>
#include <qpushbutton.h>
QtFacturaContenedor::QtFacturaContenedor(zSiscomConexion *pzSisConexion,
					QWidget *pQWParent,
					 const char *pchrPtrName,
					 bool pbModal,
					 WFlags pWFlags):
				FacturaContenedor(pQWParent,
						  pchrPtrName,
						  pbModal,
						  pWFlags),
					zSisConexion(pzSisConexion)
{
Inicia();
  exec();
}
void QtFacturaContenedor::Inicia()
{
  IniciaControles();
  IniciaVariables();
  ConectaSlots();
}
void QtFacturaContenedor::IniciaControles()
{
QCtrProveedores->Servidor(zSisConexion);
QCtrProveedores->IniciaControl();
}
void QtFacturaContenedor::IniciaVariables()
{
 zComImportacion=new zCompraImportacion;
}
void QtFacturaContenedor::ConectaSlots()
{
  connect(QCtrProveedores,
  	  SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	  SLOT(SlotProveedor(zSiscomRegistro *)));
  connect(QLENumFactura,SIGNAL(returnPressed()),SLOT(SlotFocoNumPartidas()));
  connect(QLENumPartidas,SIGNAL(returnPressed()),SLOT(SlotFocoDscCompra()));
  connect(QLEDscCompra,SIGNAL(returnPressed()),SLOT(SlotFocoAceptar()));
  connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
}
void QtFacturaContenedor::SlotAceptar()
{
   done(1);
}
void QtFacturaContenedor::SlotFocoDscCompra()
{
   zSiscomQt3::Foco(QLEDscCompra);
   Factura()->NumPartidas(zSiscomQt3::Texto(QLENumPartidas));
}
void QtFacturaContenedor::SlotFocoNumPartidas()
{
  Factura()->NumFactura(zSiscomQt3::Texto(QLENumFactura));
  zSiscomQt3::Foco(QLENumPartidas);
}
void QtFacturaContenedor::SlotFocoAceptar()
{
  Factura()->Descripcion(zSiscomQt3::Texto(QLEDscCompra)); 
  zSiscomQt3::Foco(QPBAceptar);
}
void QtFacturaContenedor::SlotProveedor(zSiscomRegistro *pzSisRegProveedor)
{
  Factura()->Empresa(zEmpresa::DeConsultaEmpresas(pzSisRegProveedor));
  zSiscomQt3::Foco(QLENumFactura);
}
zCompraImportacion *QtFacturaContenedor::Factura()
{
   return zComImportacion;
}
