#include <QtActualizaPrecioExpendios.h>

#include <QCtrlProductosSE.h>
#include <QCtrlExpendios.h>

#include <TipoPrecios.h>
#include <SISCOMComunicaciones++.h>
#include <ProductosE.h>

#include <zEmpresas.h>
#include <zEmpresa.h>
#include <zPrecio.h>
#include <zProductoPrecio.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomQt3.h>


#include <zSiscomRegistro.h>
QtActualizaPrecioExpendios::QtActualizaPrecioExpendios(SiscomDatCom *pSisDatCom,
							char **pchrPtrArgumentos,
						      QWidget *pQWParent,
						       const char *pchrPtrName,
						       WFlags pWFlags):
						    ActualizaPrecioExpendios(pQWParent,
						    			     pchrPtrName,
									     pWFlags),
						    SisDatCom(pSisDatCom),
						    zSisConexion((zSiscomConexion *)gzSiscomConexion),
						    chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

void QtActualizaPrecioExpendios::Variables()
{
  zEExpendios=new zEmpresas;
}
void QtActualizaPrecioExpendios::IniciaVariables()
{
 Variables();
 IniciaTipoPrecio();
 IniciaProductos();
 IniciaExpendios();
 HabilitaInterfazCaptura(false);
}
void QtActualizaPrecioExpendios::IniciaTipoPrecio()
{
	QLECTipoPrecio=SiscomColocaEditAlCombo(QCBTipoPrecio,"QLECTipoPrecio");
	MTipoPrecio=new ManTipoPrecio(SisDatCom,
				      QCBTipoPrecio,
				      QLECTipoPrecio,
				      QLEDescripcion,
				      this,
				      "MTipoPrecio");
	zSiscomQt3::Foco(QLECTipoPrecio);
}
void QtActualizaPrecioExpendios::IniciaProductos()
{
QCtrProductos->Servidor(zSisConexion);
QCtrProductos->IniciaControl();
}
void QtActualizaPrecioExpendios::IniciaExpendios()
{
 QCtrExpendiosO->Servidor(SisDatCom);
 QCtrExpendiosO->Expendio(chrPtrArgumentos[0]);
 QCtrExpendiosO->IniciaControl();
}
void QtActualizaPrecioExpendios::SlotActualiza()
{
   Actualizando();
   zSiscomQt3::Foco(QCtrProductos);
   QPBActualizar->setEnabled(false);
}
void QtActualizaPrecioExpendios::SlotTipoPrecio(TipoPrecio *pTipoPrecio)
{
  TTipoPrecio=pTipoPrecio;
 zSiscomQt3::Foco(QCtrProductos);
}
void QtActualizaPrecioExpendios::SlotProducto(zSiscomRegistro *pzSisRegProducto)
{
  zSisRegProducto=pzSisRegProducto;
  MuestraDescripcion();
  ConsultandoPrecioProducto();
}
void QtActualizaPrecioExpendios::SlotExpendio(SiscomRegistro3 *pSisReg3Expendio)
{
  (*zEExpendios) <<  zEmpresa::DeSiscomRegistro3(pSisReg3Expendio);
 MuestraExpendios(); 
 HabilitaInterfazCaptura(true);
 zSiscomQt3::Foco(QLECTipoPrecio);
}
void QtActualizaPrecioExpendios::MuestraDescripcion()
{
  QLEDescripcion->setText((const char *)(*zSisRegProducto)["dscproducto"]);
}

int QtActualizaPrecioExpendios::ConsultaPrecioProducto()
{
ConsultaProductosE lCnsProducto(SisDatCom);
ProductosE lProductos;
PProducto=Producto(zSisRegProducto);
		lCnsProducto.ObtenPrecioProducto(TTipoPrecio,
						 PProducto,
						 lProductos);
	if(lProductos.count())
	{
	 QLEPVenta->setText(lProductos.at(0)->SRegistrosPro2["Precio"]);
	 return 1;
	}
	else 
	return 0;
}
void QtActualizaPrecioExpendios::PasandoFocoNuevoPrecio()
{
   QLENvoPrecio->setEnabled(true);
   zSiscomQt3::Foco(QLENvoPrecio);
}
void QtActualizaPrecioExpendios::ConsultandoPrecioProducto()
{
   if(ConsultaPrecioProducto())
   {
 	PasandoFocoNuevoPrecio();	
   }
}
ProductoE *QtActualizaPrecioExpendios::Producto(zSiscomRegistro *pzSisRegistro)
{

return new ProductoE((const char *)(*pzSisRegistro)["cveproducto"],
		     "",
		     "",
		     "");
}
void QtActualizaPrecioExpendios::AgregandoExpendio(zSiscomRegistro *pzSisRegExpendio)
{
 SiscomRegistroLog2(pzSisRegExpendio);
}
void QtActualizaPrecioExpendios::ConectaSlots()
{
	connect(MTipoPrecio,
		SIGNAL(SignalTipoPrecio(TipoPrecio *)),
		SLOT(SlotTipoPrecio(TipoPrecio *)));

	connect(QCtrProductos,
		SIGNAL(SignalSelecciono(zSiscomRegistro *)),
		SLOT(SlotProducto(zSiscomRegistro *)));

	connect(QCtrExpendiosO,
        	SIGNAL(SignalExpendio(SiscomRegistro3 *)),
        	SLOT(SlotExpendio(SiscomRegistro3 *)));
	connect(QLENvoPrecio,SIGNAL(returnPressed()),SLOT(SlotFocoAActualizar()));
	connect(QPBActualizar,SIGNAL(clicked()),SLOT(SlotActualiza()));
	connect(QLENvoPrecio,SIGNAL(textChanged(const QString &)),SLOT(SlotHabilitandoActualizar(const QString &)));
		
}
void QtActualizaPrecioExpendios::SlotHabilitandoActualizar(const QString &)
{
    QPBActualizar->setEnabled(zSiscomQt3::TextoValido(QLENvoPrecio));
}
void QtActualizaPrecioExpendios::SlotFocoAActualizar()
{
  zSiscomQt3::Foco(QPBActualizar); 
}
void QtActualizaPrecioExpendios::MuestraExpendios()
{
 const char *chrPtrCampos[]={"RazonSocial",0};
zSiscomQt3::LlenaTabla(chrPtrCampos,
		       zEExpendios,
		       QTExpendios);
zSiscomQt3::AjustaColumnasTabla(QTExpendios);
}
void QtActualizaPrecioExpendios::Actualizando()
{
}
const char *QtActualizaPrecioExpendios::Clave()
{
   return (*PProducto)["CveProducto"];
}
zPrecio *QtActualizaPrecioExpendios::TipoPrecioSeleccionado()
{
   return zPrecio::DeTipoPrecio(TTipoPrecio);
}
const char *QtActualizaPrecioExpendios::PrecioNuevo()
{
   return zSiscomQt3::Texto(QLENvoPrecio);
}
zEmpresas *QtActualizaPrecioExpendios::Expendios()
{
  return zEExpendios;
}
void QtActualizaPrecioExpendios::HabilitaInterfazCaptura(bool pbEstado)
{
  QLECTipoPrecio->setEnabled(pbEstado);
  QCtrProductos->setEnabled(pbEstado);
  QLEPVenta->setEnabled(pbEstado);
  QPBActualizar->setEnabled(pbEstado);
}
