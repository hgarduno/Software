#include <IMP_ClavesProveedor4.h>

#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h> 
#include <zSiscomElectronica.h>

#include <zClaveProveedor.h>

#include <QCtrlProveedoresSE.h>
#include <QCtrlProductosSE.h> 

#include <qlineedit.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qtable.h>

QClavesProveedor4 *InstanciaClavesProveedor4(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QClavesProveedor4((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QClavesProveedor4::QClavesProveedor4(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ClavesProveedor4(pQWParent,pchrPtrName,pWFlags),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				intActualizando(0)
{
IniciaVariables();
ConectaSlots();
}

QClavesProveedor4::~QClavesProveedor4()
{

}

void QClavesProveedor4::ConectaSlots()
{
connect(QCtrProductos,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotProducto(zSiscomRegistro *)));
connect(QCtrProveedores,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotProveedor(zSiscomRegistro *)));
connect(QLEClaveP,SIGNAL(returnPressed()),SLOT(SlotFocoADescripcionP()));
connect(QPBAnexar,SIGNAL(clicked()),SLOT(SlotAnexar()));
connect(QPBRegistra,SIGNAL(clicked()),SLOT(SlotRegistra()));
connect(QLEClaveP,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoClaveP(const QString &)));
connect(QTEDescripcionP,
        SIGNAL(textChanged()),
	SLOT(SlotCapturandoDescripcionP()));
connect(QTClaves,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotClave(int,int,int,const QPoint &)));
connect(QPBActualizar,SIGNAL(clicked()),SLOT(SlotActualizar()));

}
void QClavesProveedor4::SlotActualizar()
{
  if(!intActualizando)
  {
  Actualiza();
  MuestraProductos();
  ReIniciaActualizacion();
  }
  else
  {
	LogSiscom("Actualizando la clave ya Registrado..");	
	ActualizaClaveRegistrada();
  }
}
void QClavesProveedor4::SlotClave(int pintNClave,int,int,const QPoint &)
{
  if(pintNClave!=-1)
  SeleccionandoClave(pintNClave); 
}
void QClavesProveedor4::SlotCapturandoDescripcionP()
{
   HabilitaAnexar();
}
void QClavesProveedor4::SlotCapturandoClaveP(const QString &)
{
   HabilitaAnexar();
}
void QClavesProveedor4::SlotRegistra()
{
   Registrando();
   ReIniciaRegistra();
}
void QClavesProveedor4::SlotAnexar()
{
   Anexando();
}
void QClavesProveedor4::SlotFocoADescripcionP()
{
  zSiscomQt3::Foco(QTEDescripcionP);
}
void QClavesProveedor4::SlotProveedor(zSiscomRegistro *pzSisRegProveedor)
{
  zSisRegProveedor=pzSisRegProveedor;
  QCtrProveedores->setEnabled(false);
  QCtrProductos->setEnabled(true);
  zSiscomQt3::Foco(QCtrProductos);
}
void QClavesProveedor4::SlotProducto(zSiscomRegistro *pzSisRegProducto)
{
 zSisRegProducto=pzSisRegProducto;
 AnalizaProductoSeleccionado();
}
void QClavesProveedor4::IniciaVariables()
{
QCtrProveedores->Servidor(zSisConexion);
QCtrProductos->Servidor(zSisConexion);
QCtrProveedores->IniciaControl();
QCtrProductos->IniciaControl();
zSiscomQt3::Foco(QCtrProveedores);
}

void QClavesProveedor4::MuestraProducto(zSiscomRegistro *pzSisRegProducto)
{
 QTEDescripcionS->setText((const char *)(*pzSisRegProducto)["dscproducto"]);
}

void QClavesProveedor4::Anexando()
{ 
 AnexaClaveProveedor();
 MuestraClaveProveedor();
 QPBAnexar->setEnabled(false);
 zSiscomQt3::Foco(QCtrProductos);
 HabilitaRegistrar();  
}
void QClavesProveedor4::MuestraClaveProveedor()
{
const char *lchrPtrDatos[]={"Clave","ClaveP","DescripcionP",0};
 zSiscomQt3::LlenaTabla(lchrPtrDatos,&zClavsProveedor,QTClaves);
 zSiscomQt3::AjustaColumnasTabla(QTClaves);
 zSiscomQt3::AjustaFilasTabla(QTClaves);
}
void QClavesProveedor4::AnexaClaveProveedor()
{
   zClavsProveedor << ClaveProveedor(); 
}
zClaveProveedor *QClavesProveedor4::ClaveProveedor()
{
zClaveProveedor *lzClaveProveedor=new zClaveProveedor; 
lzClaveProveedor->Clave((const char *)(*zSisRegProducto)["cveproducto"]);
lzClaveProveedor->ClaveP(zSiscomQt3::Texto(QLEClaveP));
lzClaveProveedor->DescripcionP(zSiscomQt3::Texto(QTEDescripcionP));
lzClaveProveedor->Proveedor(zSisRegProveedor);
return lzClaveProveedor;
}
void QClavesProveedor4::Registrando()
{
zSiscomElectronica lzSisElect(zSisConexion,"RegistraClavesProveedor");
lzSisElect.RegistraClavesProveedor(&zClavsProveedor);
}
int QClavesProveedor4::ValidaClaveRegistrada(zClaveProveedor **pzClaveProveedor)
{
zSiscomElectronica lzSisElect(zSisConexion,"ValidaClaveRegistrada");
return lzSisElect.ValidaClaveRegistrada(zSisRegProducto,zSisRegProveedor,pzClaveProveedor);
}
void QClavesProveedor4::AnalizaProductoSeleccionado()
{
 if(ValidaClaveRegistrada(&zClavProveedor))
 {
    HabilitaDesHabilitaClaveDescripcionProveedor(false);
    MuestraProductoRegistrado(zClavProveedor);
    HabilitandoParaActualizar();
 }
 else
   NoEstaLaClaveProveedor();
}
void QClavesProveedor4::NoEstaLaClaveProveedor()
{
 	QTEDescripcionP->clear();
	QLEClaveP->clear();
	QPBActualizar->setEnabled(false);
    	HabilitaDesHabilitaClaveDescripcionProveedor(true);    
 	zSiscomQt3::Foco(QLEClaveP);
 	MuestraProducto(zSisRegProducto);

}
void QClavesProveedor4::MuestraProductoRegistrado(zClaveProveedor *pzClaveProveedor)
{
  QLEClaveP->setText(pzClaveProveedor->ClaveP());      
  QTEDescripcionP->setText(pzClaveProveedor->DescripcionP());
  QTEDescripcionS->setText((const char *)(*zSisRegProducto)["dscproducto"]);
}
void QClavesProveedor4::HabilitaAnexar()
{
    QPBAnexar->setEnabled(!zClavProveedor 			&& 
    			  zSiscomQt3::TextoValido(QLEClaveP) 	&&
			  zSiscomQt3::TextoValido(QTEDescripcionP));
}
void QClavesProveedor4::HabilitaRegistrar()
{
  QPBRegistra->setEnabled(zClavsProveedor.NNodos());
}

void QClavesProveedor4::ReIniciaRegistra()
{
   zClavsProveedor.Libera();
   QTClaves->setNumRows(0);
   QPBRegistra->setEnabled(false);
   QCtrProductos->setEnabled(false);
   QCtrProveedores->setEnabled(true);
   zSiscomQt3::Foco(QCtrProveedores);
}

void QClavesProveedor4::SeleccionandoClave(int pintNClave)
{
  zClavProveedor=(zClaveProveedor *)zClavsProveedor[pintNClave];
  QTEDescripcionP->setText(zClavProveedor->DescripcionP());
  QTClaves->selectRow(pintNClave);
  QLEClaveP->setText(zClavProveedor->ClaveP());
  zSiscomQt3::Foco(QLEClaveP);
  QPBActualizar->setEnabled(true);
  QCtrProductos->setEnabled(false);
  HabilitaRegistrar();
}
void QClavesProveedor4::Actualiza()
{
  zClavProveedor->ClaveP(zSiscomQt3::Texto(QLEClaveP));
  zClavProveedor->DescripcionP(zSiscomQt3::Texto(QTEDescripcionP));
}

void QClavesProveedor4::MuestraProductos()
{
 const char *lchrPtrCampos[]={"Clave","ClaveP","DescripcionP",0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,&zClavsProveedor,QTClaves);
zSiscomQt3::AjustaFilasTabla(QTClaves);
zSiscomQt3::AjustaColumnasTabla(QTClaves);
}
void QClavesProveedor4::ReIniciaActualizacion()
{
  QPBActualizar->setEnabled(false); 
  QCtrProductos->setEnabled(true);
  zSiscomQt3::Foco(QCtrProductos);
}
void QClavesProveedor4::HabilitaDesHabilitaClaveDescripcionProveedor(bool pbEstado)
{
QTEDescripcionP->setEnabled(pbEstado);
QLEClaveP->setEnabled(pbEstado);
}
void QClavesProveedor4::HabilitandoParaActualizar()
{
  	HabilitaDesHabilitaClaveDescripcionProveedor(true);
	//QCtrProductos->setEnabled(false);
	QPBActualizar->setEnabled(true);
	intActualizando=1;
	zSiscomQt3::Foco(QLEClaveP);
}
void QClavesProveedor4::ActualizaDatosClaveProveedor()
{
	Actualiza();
}
void QClavesProveedor4::ActualizaClaveRegistrada()
{
	ActualizaDatosClaveProveedor();
	ActualizandoClaveRegistrada();
	ReIniciaActualizacion();
	intActualizando=0;
}
void QClavesProveedor4::ActualizandoClaveRegistrada()
{
zSiscomElectronica lzSisElec(zSisConexion,"ActualizaClaveProveedor");
lzSisElec.ActualizaClaveProveedor4(zClavProveedor);
}
