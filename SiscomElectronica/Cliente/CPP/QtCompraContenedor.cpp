#include <QtCompraContenedor.h>
#include <QtCapturaFacturaImp.h>
#include <IMP_FacturaContenedor.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>


#include <zComprasImportacion.h>
#include <zCompraImportacion.h>
#include <zCompraContenedor.h>
#include <zEmpresa.h>


#include <qpushbutton.h>
#include <qtable.h>
#include <qlineedit.h>

QtCompraContenedor::QtCompraContenedor(zSiscomConexion *pzSisConexion,
				      char **pchrPtrArgumentos,
				       QWidget *pQWParent,
				       const char *pchrPtrName,
				       WFlags pWFlags):
				        CompraContenedor(pQWParent,pchrPtrName,pWFlags),
					zSisConexion(pzSisConexion),
					chrPtrArgumentos(pchrPtrArgumentos),
					QWParent(pQWParent)

{
  Inicia(); 
}
void QtCompraContenedor::Inicia()
{
   IniciaVariables();
   ConectaSlots();
}
void QtCompraContenedor::ConectaSlots()
{
  connect(QPBAgregaFactura,SIGNAL(clicked()),SLOT(SlotAgregaFactura()));
  connect(QTFacturas,
  	  SIGNAL(doubleClicked(int,int,int,const QPoint &)),
	  SLOT(SlotCapturaFactura(int,int,int,const QPoint &)));
  connect(QLECostoEnvio,SIGNAL(returnPressed()),SLOT(SlotFocoCostoAdministrativo()));
  connect(QLECostoAdministrativo,
  	 SIGNAL(returnPressed()),
	 SLOT(SlotFocoCostoDolar()));
  connect(QLECostoDolar,SIGNAL(returnPressed()),SLOT(SlotFocoAAnexarFactura()));
}
void QtCompraContenedor::SlotFocoAAnexarFactura()
{
Contenedor()->CostoDolar(zSiscomQt3::Texto(QLECostoDolar));
zSiscomQt3::Foco(QPBAgregaFactura);
}
void QtCompraContenedor::SlotFocoCostoDolar()
{
Contenedor()->CostoAdministrativo(zSiscomQt3::Texto(QLECostoAdministrativo));
zSiscomQt3::Foco(QLECostoDolar);
}
void QtCompraContenedor::SlotFocoCostoAdministrativo()
{
Contenedor()->CostoEnvio(zSiscomQt3::Texto(QLECostoEnvio)); 
zSiscomQt3::Foco(QLECostoAdministrativo);
}
void QtCompraContenedor::SlotCapturaFactura(int pintNFactura,
					    int,
					    int,
					    const QPoint &)
{
QtCapturaFacturaImp *lQCapturaFImp=new QtCapturaFacturaImp((SiscomDatCom *)0,
							   chrPtrArgumentos,
							   QWParent,
							   0,
							   0);
Contenedor()->DatosEnvioFactura(pintNFactura);
lQCapturaFImp->CompraImportacion(Contenedor()->Factura(pintNFactura));
lQCapturaFImp->MuestraCompraImportacion();
lQCapturaFImp->show();
}

void QtCompraContenedor::SlotAgregaFactura()
{
    Capturando();   
}
void QtCompraContenedor::Captura()
{
QFacturaContenedor lQFContenedor(zSisConexion);
Contenedor()->Factura(lQFContenedor.Factura());
}
void QtCompraContenedor::Capturando()
{
 Captura();
 Muestra();
}
void QtCompraContenedor::Muestra()
{
int lintI;
zCompraImportacion *lzComImportacion;
QTFacturas->setNumRows(Contenedor()->Facturas()->NNodos());
for(lintI=0,lzComImportacion=(zCompraImportacion *)Contenedor()->Facturas()->Primer();
    lzComImportacion;
    lzComImportacion=(zCompraImportacion *)Contenedor()->Facturas()->Siguiente(),
    lintI++)
{
    QTFacturas->setText(lintI,0,lzComImportacion->Empresa()->RazonSocial());
    QTFacturas->setText(lintI,1,lzComImportacion->NumFactura());
    QTFacturas->setText(lintI,2,lzComImportacion->NumPartidas());
}
zSiscomQt3::AjustaColumnasTabla(QTFacturas);
}
void QtCompraContenedor::IniciaVariables()
{
zComContenedor=new zCompraContenedor;
}
zCompraContenedor *QtCompraContenedor::Contenedor()
{
 	return zComContenedor;
}
