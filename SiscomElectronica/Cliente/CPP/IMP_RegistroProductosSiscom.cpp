#include <IMP_RegistroProductosSiscom.h>

#include <QCtrlProductosSE.h>

#include <zProductoCotizar.h>
#include <zClienteSiscom.h>
#include <zTelefono.h>
#include <zCorreo.h>
#include <zDireccion.h>
#include <zProductoSiscom.h>


#include <zSiscomElectronica.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <qmessagebox.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qtable.h>

QRegistroProductosSiscom *InstanciaRegistroProductosSiscom(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRegistroProductosSiscom((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRegistroProductosSiscom::QRegistroProductosSiscom(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RegistroProductosSiscom(pQWParent,pchrPtrName,pWFlags),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion)
{
IniciaVariables();
ConectaSlots();
}

QRegistroProductosSiscom::~QRegistroProductosSiscom()
{

}

void QRegistroProductosSiscom::ConectaSlots()
{

connect(QCtrProductos,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotSeleccionoProducto(zSiscomRegistro *)));

connect(QLECantidad,SIGNAL(returnPressed()),SLOT(SlotFocoARegistrar()));
connect(QLECantidad,SIGNAL(textChanged(const QString &)),SLOT(SlotCapturandoCantidad(const QString &)));
connect(QPBRegistrar,SIGNAL(clicked()),SLOT(SlotRegistrar()));
connect(QPBExpendio,SIGNAL(clicked()),SLOT(SlotExpendio()));
connect(QPBBodega,SIGNAL(clicked()),SLOT(SlotBodega()));
}
void QRegistroProductosSiscom::SlotExpendio()
{
  AsignandoOrigen("Expendio"); 
  ValidandoCompraProductoSiscom(); 
  MuestraDefinicionProducto();
}
void QRegistroProductosSiscom::SlotBodega()
{
  AsignandoOrigen("Bodega"); 
  ValidandoCompraProductoSiscom(); 
  MuestraDefinicionProducto();
}
void QRegistroProductosSiscom::SlotCapturandoCantidad(const QString &)
{
  HabilitandoBotonRegistro();
}
void QRegistroProductosSiscom::SlotRegistrar()
{
  RegistrandoProductoSiscom();
}
void QRegistroProductosSiscom::SlotFocoARegistrar()
{
  zProdSiscom->CantidadAComprar(zSiscomQt3::Texto(QLECantidad));
  zProdSiscom->IdCompra(chrPtrIdCompraProductoSiscom);
  ValidandoCompraProductoSiscom(); 
  MuestraDefinicionProducto();
  HabilitandoBotonRegistro();
  zSiscomQt3::Foco(QPBRegistrar);
  QPBBodega->setEnabled(zProdSiscom && zSiscomQt3::TextoValido(QLECantidad));
  QPBExpendio->setEnabled(zProdSiscom && zSiscomQt3::TextoValido(QLECantidad));
}
void QRegistroProductosSiscom::SlotSeleccionoProducto(zSiscomRegistro *pzSisRegProducto)
{
      zProdSiscom=new zProductoSiscom(pzSisRegProducto);
      ObteniendoDefinicionProducto();
      MuestraDefinicionProducto();
      QLECantidad->setEnabled(true);
      zSiscomQt3::Foco(QLECantidad);
}
void QRegistroProductosSiscom::IniciaVariables()
{
  ObteniendoIdCompraProductosSiscom();
  QCtrProductos->Servidor(zSisConexion);
  QCtrProductos->IniciaControl();
  zSiscomQt3::Foco(QCtrProductos);
}
void QRegistroProductosSiscom::ObteniendoDefinicionProducto()
{
zSiscomElectronica lzSiscomElec(zSisConexion,"DefinicionProducto");
lzSiscomElec.DefinicionProducto(zProdSiscom);
zProdSiscom->AgregaOrigenDefinicion();
}
void QRegistroProductosSiscom::MuestraProductos()
{
const char *lchrPtrCampos[]={"cveproducto",
			     "cantidad",
			     "existencia",
			     "exbodegas",
			     "Origen",
			     0};
	if(EsProductoPracticaEtc())
  	zSiscomQt3::LlenaTabla(lchrPtrCampos,zProdSiscom->DefinicionProducto(),QTDefProducto);
	else
	QMessageBox::information(this,
				"Aviso del sistema",
				"Es Un producto o circuito impreso");

}
void QRegistroProductosSiscom::FilasDefinicionProductoABlanco()
{
int lintArrFilasABlanco[100],lintContador;
memset(lintArrFilasABlanco,-1,100);
for(lintContador=0;lintContador<QTDefProducto->numRows();lintContador++)
 lintArrFilasABlanco[lintContador]=1;
 zSiscomQt3::ColoreaFilas(QTDefProducto,Qt::white,lintArrFilasABlanco);
}
void QRegistroProductosSiscom::MuestraProductosNoAlcanza()
{
int lintArrFilasNoAlcanza[100];
int lintProducto=0;
zProducto *lzProdDefinicion;
 memset(lintArrFilasNoAlcanza,-1,sizeof(int)*100);
 zProdSiscom->PrimerProdDefinicion();
 do
 {
     if(zProdSiscom->SiAlcanzaProdDefinicion())
     {
      lintArrFilasNoAlcanza[lintProducto]=1;
      QTDefProducto->setText(lintProducto,5,zProdSiscom->NoAlcanzaAComprar());
     }
     lintProducto++;
 }while(zProdSiscom->SiguienteProdDefinicion());
 zSiscomQt3::ColoreaFilas(QTDefProducto,Qt::red,lintArrFilasNoAlcanza);
}
void QRegistroProductosSiscom::MuestraDefinicionProducto()
{
   if(QTDefProducto->numRows())
   FilasDefinicionProductoABlanco();
    if(zProdSiscom->NoAlcanza())
    MuestraProductosNoAlcanza();

    MuestraProductos();
}
void QRegistroProductosSiscom::RegistrandoProductoSiscom()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ComprandoProductoSiscom");
lzSisElectronica.ComprandoProductoSiscom(zProdSiscom);
}
void QRegistroProductosSiscom::ValidandoCompraProductoSiscom()
{
zProdSiscom->DefinicionProducto()->EliminaCampo("NoAlcanza");
zSiscomElectronica lzSisElectronica(zSisConexion,"ValidandoCompraProductoSiscom");
lzSisElectronica.ValidandoCompraProductoSiscom(zProdSiscom);
}
void QRegistroProductosSiscom::ObteniendoIdCompraProductosSiscom()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"IdCompraProductoSiscom");
chrPtrIdCompraProductoSiscom=lzSisElectronica.IdCompraProductoSiscom();

}
int QRegistroProductosSiscom::EsProductoPracticaEtc()
{
   return zProdSiscom->TipoProductoInt()==1 ||
          zProdSiscom->TipoProductoInt()==2 ||
	  zProdSiscom->TipoProductoInt()==3 ;
}
void QRegistroProductosSiscom::HabilitandoBotonRegistro()
{
      QPBRegistrar->setEnabled(zProdSiscom && 
      			       zSiscomQt3::TextoValido(QLECantidad) &&
			       !zProdSiscom->NoAlcanza());
 
}	

void QRegistroProductosSiscom::AsignandoOrigen(const char *pchrPtrOrigen)
{
int lintContador;
zSiscomRegistros *lzSisRegsDefinicion;
lzSisRegsDefinicion=zProdSiscom->DefinicionProducto();
SiscomRegistrosLog(lzSisRegsDefinicion);
for(lintContador=0;lintContador<QTDefProducto->numRows();lintContador++)
{
  if(QTDefProducto->isRowSelected(lintContador))
  {
     ((*lzSisRegsDefinicion)[lintContador])->ActualizaCampo("Origen",
     							    (const unsigned char *)pchrPtrOrigen);
  }
}
}
