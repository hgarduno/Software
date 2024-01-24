#include <IMP_ActualizaProductoImportado.h>

#include <zSiscomElectronica.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <zSiscomDesarrollo4.h>

#include <zProductoImportado.h>


#include <qlineedit.h>
#include <qpushbutton.h>
QActualizaProductoImportado::QActualizaProductoImportado(
				    zProductoImportado *pzProdImportado,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				ActualizaProductoImportado(pQWParent,pchrPtrName,pbModal,pWFlags),
				zProdImportado(pzProdImportado),
				intCambioPeso(0),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
MuestraProducto();
IniciaVariables();
ConectaSlots();
exec();
}

QActualizaProductoImportado::~QActualizaProductoImportado()
{

}

void QActualizaProductoImportado::ConectaSlots()
{
connect(QLECantidad,SIGNAL(returnPressed()),SLOT(SlotFocoACostoUnitario()));
connect(QLECostoUnitario,SIGNAL(returnPressed()),SLOT(SlotFocoAPeso()));
connect(QLEPeso,SIGNAL(returnPressed()),SLOT(SlotFocoAAceptar()));
connect(QLEPeso,SIGNAL(textChanged(const QString &)),SLOT(SlotCambiandoPeso(const QString &)));
connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
}
void QActualizaProductoImportado::SlotCambiandoPeso(const QString &)
{
 intCambioPeso=1;
}
void QActualizaProductoImportado::SlotFocoACostoUnitario()
{
 zSiscomQt3::Foco(QLECostoUnitario);
}
void QActualizaProductoImportado::SlotFocoAPeso()
{
  zSiscomQt3::Foco(QLEPeso);
}
void QActualizaProductoImportado::SlotFocoAAceptar()
{
  zSiscomQt3::Foco(QPBAceptar);
}
void QActualizaProductoImportado::SlotAceptar()
{
Actualiza();
ActualizandoPeso();
intAceptar=1;
done(1);
}
void QActualizaProductoImportado::IniciaVariables()
{
zSiscomQt3::Foco(QLECantidad);
}
void QActualizaProductoImportado::MuestraProducto()
{
QLEProducto->setText(zProdImportado->Clave());
QLECantidad->setText(zProdImportado->Cantidad());
QLEPeso->setText(zProdImportado->Peso());
QLECostoUnitario->setText(zProdImportado->CostoUnitarioDolares());
}
void QActualizaProductoImportado::Actualiza()
{
  zProdImportado->Peso(zSiscomQt3::Texto(QLEPeso));
  zProdImportado->CostoUnitarioDolares(zSiscomQt3::Texto(QLECostoUnitario));
  zProdImportado->Cantidad(zSiscomQt3::Texto(QLECantidad));
}
int QActualizaProductoImportado::Aceptar()
{
  return intAceptar;

}
void QActualizaProductoImportado::ActualizaPeso()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ActualizaPeso");
lzSisElectronica.ActualizaPesoProducto(zProdImportado);
}
void QActualizaProductoImportado::ActualizandoPeso()
{
  if(intCambioPeso)
    ActualizaPeso();
}
