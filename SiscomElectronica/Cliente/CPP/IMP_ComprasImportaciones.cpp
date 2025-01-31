#include <IMP_ComprasImportaciones.h>
#include <IMP_CapturaPesoProducto.h>
#include <IMP_ActualizaProductoImportado.h>
#include <IMP_DescripcionCompraImportacion.h>
#include <IMP_SeleccionaCompraImp.h>
#include <IMP_ProveedoresCompraImportacion.h>
#include <IMP_BodegasSiscom.h>
#include <IMP_RegistroParcialComImp.h>
#include <QCtrlProveedoresSE.h>
#include <QCtrlProductosSE.h>



#include <zSiscomElectronica.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomQt3.h>

#include <zSiscomDesarrollo4.h>

#include <zProductoImportado.h>
/*#include <zProductosImportados.h> */
#include <zProductoImportadoInf.h>
#include <zEmpresa.h>
#include <zFacturaImportacion.h>
#include <zCompraParcialImportacion.h>

#include <qmessagebox.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>
#include <qtable.h>
#include <qmessagebox.h>
#include <qfiledialog.h>

QComprasImportaciones *InstanciaComprasImportaciones(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QComprasImportaciones((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QComprasImportaciones::QComprasImportaciones(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ComprasImportaciones(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				zSisConexion((zSiscomConexion *)gzSiscomConexion),
				intSeGuardaComo(0),
				intCapturaSinGuardar(0),
				SisReg3Bodega(0),
				QRegParComImp(0),
				QWParent(pQWParent)
{
IniciaVariables();
ConectaSlots();
}
QComprasImportaciones::~QComprasImportaciones()
{

}

void QComprasImportaciones::ConectaSlots()
{
connect(QLENumFactura,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoNumFactura(const QString &)));
connect(QLECostoEnvio,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoCostoEnvio(const QString &)));
connect(QLECostoDolar,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoCostoDolar(const QString &)));
connect(QLECostoAdministrativo,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoCostoAdministrativo(const QString &)));
connect(QLENumPartidas,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoNumPartidas(const QString &)));

connect(QLECantidad,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoCantidad(const QString &)));
connect(QLECostoUnitario,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoCostoUnitario(const QString &)));

connect(QCtrProductos,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotSeleccionoProducto(zSiscomRegistro *)));
connect(QCtrProveedores,
	SIGNAL(SignalSelecciono(zSiscomRegistro *)),
	SLOT(SlotSeleccionoProveedor(zSiscomRegistro *)));
connect(QTProductos,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionaProducto(int,int,int,const QPoint &)));

connect(QTProductos, SIGNAL(valueChanged(int,int)),SLOT(SlotAOtraCelda(int,int)));
connect(QTProductos,
	SIGNAL(doubleClicked(int,int,int,const QPoint &)),
	SLOT(SlotAgregandoParaRegistroParcial(int,int,int,const QPoint &)));


connect(QLECantidad,SIGNAL(returnPressed()),SLOT(SlotFocoACostoUnitario()));
connect(QLECostoUnitario,SIGNAL(returnPressed()),SLOT(SlotFocoAAnexar()));
connect(QLENumFactura,SIGNAL(returnPressed()),SLOT(SlotFocoACostoEnvio()));
connect(QLECostoEnvio,SIGNAL(returnPressed()),SLOT(SlotFocoACotizacionDolar()));
connect(QLECostoDolar,SIGNAL(returnPressed()),SLOT(SlotFocoACostoAdministrativo()));
connect(QLECostoAdministrativo,SIGNAL(returnPressed()),SLOT(SlotFocoANumPartidas()));
connect(QLENumPartidas,SIGNAL(returnPressed()),SLOT(SlotFocoAProductos()));
connect(QLEDscCompra,SIGNAL(returnPressed()),SLOT(SlotCapturoDescripcion()));
connect(QPBAnexar,SIGNAL(clicked()),SLOT(SlotAnexarProducto()));
connect(QPBRegistraCompra,SIGNAL(clicked()),SLOT(SlotRegistraCompra()));
connect(QPBEliminar,SIGNAL(clicked()),SLOT(SlotEliminar()));
connect(QPBProveedores,SIGNAL(clicked()),SLOT(SlotProveedores()));
connect(QPBActualizar,SIGNAL(clicked()),SLOT(SlotActualiza()));
connect(QPBGuardaCompra,SIGNAL(clicked()),SLOT(SlotGuardaCompra()));
connect(QLEDscCompra,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoDscCompra(const QString &)));
connect(QPBCargaCompra,SIGNAL(clicked()),SLOT(SlotCargaCompra()));
connect(QPBGuardaCompraComo,SIGNAL(clicked()),SLOT(SlotGuardarComo()));
connect(QPBOtroProveedor,SIGNAL(clicked()),SLOT(SlotOtroProveedor()));
connect(QPBCargaCompraAProveedor,SIGNAL(clicked()),SLOT(SlotArchivoCompraProveedor()));
connect(QPBBodegas,SIGNAL(clicked()),SLOT(SlotBodegas()));
connect(QPBRegParProductos,SIGNAL(clicked()),SLOT(SlotRegParProductos()));

connect(QPBACompra,SIGNAL(clicked()),SLOT(SlotActualizaCompra()));
}
void QComprasImportaciones::SlotActualizaCompra()
{
ActualizandoCompra();

}
void QComprasImportaciones::SlotAgregandoParaRegistroParcial(int pintNProducto,
							     int,
							     int,
							     const QPoint &)
{
  AgregandoProductoParaRegistroParcial(zComImportacion.Producto(pintNProducto));
}
void QComprasImportaciones::SlotRegParProductos()
{
 RegistrandoParcialmenteCompra(); 
}
void QComprasImportaciones::SlotBodegas()
{
  BodegasSiscom();
  HabilitaRegistroParcialActualizaCompra(QPBRegParProductos); 
  HabilitaRegistroParcialActualizaCompra(QPBACompra); 
}
void QComprasImportaciones::SlotAOtraCelda(int pintFila,int pintColumna)
{
   if(pintColumna==7)
   ActualizaPrecioUnitario((const  char *)QTProductos->text(pintFila,pintColumna),
   			   ProductoImportado(pintFila));
   if(pintColumna==4)
   ActualizaPeso((const char *)QTProductos->text(pintFila,pintColumna),
   		  ProductoImportado(pintFila));

}
void QComprasImportaciones::SlotArchivoCompraProveedor()
{
  ArchivoCompraProveedor();
  CompletaProductosImportacion();
  MuestraCompraImportacion();
}
void QComprasImportaciones::SlotOtroProveedor()
{
QCtrProveedores->setEnabled(true);
zSiscomQt3::Foco(QCtrProveedores);
}
void QComprasImportaciones::SlotGuardarComo()
{
   if(!intSeGuardaComo)
   {
   QLEDscCompra->setEnabled(true);
   zSiscomQt3::Foco(QLEDscCompra);
   QPBGuardaCompraComo->setEnabled(false);
   intSeGuardaComo=1;
   }
   else
	GuardandoComo();
}
void QComprasImportaciones::SlotCapturoDescripcion()
{
 zComImportacion.Descripcion(zSiscomQt3::Texto(QLEDscCompra));
 if(!intSeGuardaComo)
 HabilitandoGuardaCompra();
 else
 QPBGuardaCompraComo->setEnabled(true);

}
void QComprasImportaciones::SlotCargaCompra()
{
  CargandoCompra();
  HabilitandoGuardaCompra();
  HabilitandoProveedoresCompra();
  HabilitaSeleccionaBodega();
  zSiscomQt3::Foco(QCtrProductos);
}
void QComprasImportaciones::SlotCapturandoDscCompra(const QString &)
{
/*
	if(!intSeGuardaComo)
	HabilitandoGuardaCompra();
*/
}
void QComprasImportaciones::SlotGuardaCompra()
{
  GuardandoCompraImportacion();
}
void QComprasImportaciones::SlotActualiza()
{
  ActualizaDatosProducto();  
}
void QComprasImportaciones::SlotProveedores()
{
QProveedoresCompraImportacion lQPCImportacion(&zComImportacion);
 zEmpresaA=lQPCImportacion.Proveedor(); 
 MuestraProveedor();
 zSiscomQt3::Foco(QCtrProductos);
}
void QComprasImportaciones::SlotCapturandoCantidad(const QString &)
{
    QPBAnexar->setEnabled(ValidandoDatos()); 
}
void QComprasImportaciones::SlotCapturandoCostoUnitario(const QString &)
{
    QPBAnexar->setEnabled(ValidandoDatos()); 
}
void QComprasImportaciones::SlotCapturandoNumFactura(const QString &)
{
     QCtrProductos->setEnabled(ValidaDatosEnvio()); 
     QPBAnexar->setEnabled(ValidandoDatos()); 
}

void QComprasImportaciones::SlotCapturandoCostoEnvio(const QString &)
{
 ValidandoParaAnexar();
}

void QComprasImportaciones::SlotCapturandoCostoDolar(const QString &)
{
     QCtrProductos->setEnabled(ValidaDatosEnvio()); 
    QPBAnexar->setEnabled(ValidandoDatos()); 
}
void QComprasImportaciones::SlotCapturandoCostoAdministrativo(const QString &)
{
     QCtrProductos->setEnabled(ValidaDatosEnvio()); 
    QPBAnexar->setEnabled(ValidandoDatos()); 
}
void QComprasImportaciones::SlotCapturandoNumPartidas(const QString &)
{
    QCtrProductos->setEnabled(ValidaDatosEnvio()); 
    QPBAnexar->setEnabled(ValidandoDatos()); 
    HabilitandoRegistraCompra();
}

void QComprasImportaciones::SlotSeleccionaProducto(int pintNProducto,
						   int,
						   int,
						   const QPoint &)
{
    intProductoSeleccionado=pintNProducto;
    QTProductos->selectRow(intProductoSeleccionado);
    QPBEliminar->setEnabled(true);
}
void QComprasImportaciones::SlotEliminar()
{
  EliminaProducto();
  Calculando();
  MostrandoCalculos();
  ValidandoNumeroPartidas();
  QPBEliminar->setEnabled(false);
  HabilitandoBodegas();

}
void QComprasImportaciones::SlotFocoACostoEnvio()
{
  zSiscomQt3::Foco(QLECostoEnvio);
  zComImportacion.NumFactura(zSiscomQt3::Texto(QLENumFactura));
}
void QComprasImportaciones::SlotRegistraCompra()
{
   zComImportacion.IdExpendio(*(chrPtrArgumentos+0));
   zComImportacion.IdResponsable(*(chrPtrArgumentos+1));
   RegistraCompra();
   EliminaCompraActual();
}
void QComprasImportaciones::SlotAnexarProducto()
{
if((QTProductos->numRows())<zComImportacion.NumPartidasInt())
{
  zComImportacion.AgregaProducto(zProdImportado); 
  Calculando();
  HabilitandoRegistraCompra();
  HabilitandoBodegas();
  zSiscomQt3::Foco(QCtrProductos);
}
else
QMessageBox::information(this,"Aviso Sistema","Ya Se capturaron todas las partidas");
}
void QComprasImportaciones::SlotFocoAProductos()
{
  HabilitaProductos(); 
  zSiscomQt3::Foco(QCtrProductos);
  zComImportacion.NumPartidas(zSiscomQt3::Texto(QLENumPartidas));
  HabilitaSeleccionaBodega();
  HabilitandoRegistraCompra();
}
void QComprasImportaciones::SlotSeleccionoProveedor(zSiscomRegistro *pzSisRegEmpresa)
{
	zSiscomQt3::Foco(QLENumFactura);
	zEmpresaA=zEmpresa::DeConsultaEmpresas(pzSisRegEmpresa);
	zComImportacion.Empresa(zEmpresaA);
	zComImportacion.AgregaProveedor(zEmpresaA);
	QCtrProveedores->setEnabled(false);
}
void QComprasImportaciones::SlotFocoACotizacionDolar()
{
	zSiscomQt3::Foco(QLECostoDolar);
	zComImportacion.CostoEnvio(zSiscomQt3::Texto(QLECostoEnvio));
	Calculando();
}
void QComprasImportaciones::SlotFocoACostoAdministrativo()
{
	zSiscomQt3::Foco(QLECostoAdministrativo);
	zComImportacion.CostoDolar(zSiscomQt3::Texto(QLECostoDolar));
	Calculando();
}
void QComprasImportaciones::SlotFocoANumPartidas()
{
	zSiscomQt3::Foco(QLENumPartidas);
	zComImportacion.CostoAdministrativo(zSiscomQt3::Texto(QLECostoAdministrativo));
	Calculando();
}
void QComprasImportaciones::SlotFocoAAnexar() { zSiscomQt3::Foco(QPBAnexar);
  zProdImportado->CostoUnitarioDolares(zSiscomQt3::Texto(QLECostoUnitario));
}
void QComprasImportaciones::SlotFocoACostoUnitario()
{
    zSiscomQt3::Foco(QLECostoUnitario);
    zProdImportado->Cantidad(zSiscomQt3::Texto(QLECantidad));
}
void QComprasImportaciones::SlotSeleccionoProducto(zSiscomRegistro *pzSisRegProducto)
{
   ProductoImportadoInf(pzSisRegProducto);
   AnexandoProducto(pzSisRegProducto);
   PesoRegistrado();
   TeniendoClaveProveedor();
   delete zProdImportadoInf;
}
void QComprasImportaciones::IniciaVariables()
{
  QCtrProveedores->Servidor(zSisConexion);
  QCtrProveedores->IniciaControl();
  QCtrProductos->Servidor(zSisConexion);
  QCtrProductos->IniciaControl();
  zSiscomQt3::Foco(QCtrProveedores);
  VeSiSePasaElFocoAProducto();
  QLCNCostoGrEnvio->setSmallDecimalPoint(true);
  zComParcialI=new zCompraParcialImportacion;
}

void QComprasImportaciones::PesoRegistrado()
{
if(zProdImportadoInf->Peso())
    zSiscomQt3::Foco(QLECantidad);
else
  NoEstaElPesoRegistrado();
}
void QComprasImportaciones::NoEstaElPesoRegistrado()
{
char lchrArrPeso[12];
QCapturaPesoProducto lQPesoProducto(zProdImportado);
if(lQPesoProducto.Regreso(lchrArrPeso))
{
    zProdImportado->Peso(lchrArrPeso);
    QLEPeso->setText(lchrArrPeso);
    zSiscomQt3::Foco(QLECantidad);
}
}
void QComprasImportaciones::AnexandoProducto(zSiscomRegistro *pzSisRegProducto)
{
   zProdImportado=new zProductoImportado(pzSisRegProducto);
   zProdImportado->Peso(zSiscomQt3::Texto(QLEPeso));
   zProdImportado->CveProveedor((const char *)(*zProdImportadoInf)["CveProveedor"]);
   zProdImportado->IdProveedor(zEmpresaA->IdEmpresa());

}
void QComprasImportaciones::Calculando()
{
char lchrArrMensaje[128];
  if(zComImportacion.Productos())
  {
  if(EnviaDatos(lchrArrMensaje))
  MostrandoCalculos();
  else
  {
  zComImportacion.Productos()->Elimina(zProdImportado);
  QMessageBox::information(this,"Aviso Sistema",lchrArrMensaje);
  }
  }
}
int QComprasImportaciones::EnviaDatos(char *pchrPtrMensaje)
{
zSiscomElectronica lzSisElectronica(zSisConexion,"CompraImportacion");
return lzSisElectronica.CalculaProductoImportacion(&zComImportacion,pchrPtrMensaje); 
}
void QComprasImportaciones::MostrandoCalculos()
{
  QLCNPesoCompra->display(zComImportacion.PesoCompra());
  QLCDNImporteFactura->display(zComImportacion.ImporteFactura());
  QLECostoGrEnvio->setText(zComImportacion.CostoGrEnvio());
  QLCNCostoGrEnvio->display(zComImportacion.CostoGrEnvio());
  MuestraProductos();

}
void QComprasImportaciones::MuestraProductos()
{
int lintContadorI;
zProductoImportado *lzProdImportado;
if(zComImportacion.Productos())
{
QTProductos->setNumRows(zComImportacion.Productos()->NNodos());
for(lzProdImportado=(zProductoImportado *)zComImportacion.Productos()->Primer(),
    lintContadorI=0;
    lzProdImportado;
    lzProdImportado=(zProductoImportado *)zComImportacion.Productos()->Siguiente(),
    lintContadorI++)
{
  QTProductos->setText(lintContadorI,0,lzProdImportado->RazonSocial());
  QTProductos->setText(lintContadorI,1,lzProdImportado->Clave());
  QTProductos->setText(lintContadorI,2,lzProdImportado->CveProveedor());
  QTProductos->setText(lintContadorI,3,lzProdImportado->Cantidad());
  QTProductos->setText(lintContadorI,4,lzProdImportado->Peso());
  QTProductos->setText(lintContadorI,5,lzProdImportado->PesoTotal());
  QTProductos->setText(lintContadorI,6,lzProdImportado->CostoEnvio());
  QTProductos->setText(lintContadorI,7,lzProdImportado->CostoUnitarioDolares());
  QTProductos->setText(lintContadorI,8,lzProdImportado->PrecioMasCostoEnvio());
  QTProductos->setText(lintContadorI,9,lzProdImportado->CostoFinalPesos());
  QTProductos->setText(lintContadorI,10,lzProdImportado->CostoFinalMasCosAdm());
  QTProductos->setText(lintContadorI,11,lzProdImportado->CostoPartida());

  QTProductos->setColumnReadOnly(0,true);
  QTProductos->setColumnReadOnly(1,true);
  QTProductos->setColumnReadOnly(2,true);
  QTProductos->setColumnReadOnly(3,true);
  QTProductos->setColumnReadOnly(5,true);
  QTProductos->setColumnReadOnly(6,true);
  QTProductos->setColumnReadOnly(8,true);
  QTProductos->setColumnReadOnly(9,true);
  QTProductos->setColumnReadOnly(10,true);
  QTProductos->setColumnReadOnly(11,true);
}
zSiscomQt3::AjustaColumnasTabla(QTProductos);
}
}

void QComprasImportaciones::RegistraCompra()
{
zSiscomElectronica  lzSisElectronica(zSisConexion,"RegistraCompraImportacion");
lzSisElectronica.RegistraCompraImportacion(&zComImportacion);
}
bool QComprasImportaciones::ValidandoNumeroPartidas()
{
     return zComImportacion.NumPartidasInt()==QTProductos->numRows();
}
void QComprasImportaciones::EliminaCompraActual()
{
   zComImportacion.EliminaProductos();  
   QTProductos->setNumRows(0);
}
void QComprasImportaciones::EliminaProducto()
{
   if(intProductoSeleccionado>=0)
   zComImportacion.EliminaProductoImportado(intProductoSeleccionado);
}
bool QComprasImportaciones::ValidaDatosEnvio()
{
   return zSiscomQt3::TextoValido(QLENumFactura) 		&&
          zSiscomQt3::TextoValido(QLECostoEnvio) 		&&
	  zSiscomQt3::TextoValido(QLECostoDolar) 		&&
	  zSiscomQt3::TextoValido(QLECostoAdministrativo) 	&&
	  zSiscomQt3::TextoValido(QLENumPartidas);
}
bool QComprasImportaciones::ValidaDatosProducto()
{
  return zSiscomQt3::TextoValido(QLECantidad) &&
         zSiscomQt3::TextoValido(QLECostoUnitario);
}
bool QComprasImportaciones::ValidandoDatos()
{
    return ValidaDatosProducto() &&
           ValidaDatosEnvio();
}
void QComprasImportaciones::ProductosPorFiltro()
{
   ConsultandoProductosPorFiltro();
   Calculando();
}
void QComprasImportaciones::ConsultaProductosFiltrados()
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ProductosPorFiltroComprasImportacion");
lzSisElectronica.ProductosImportadosPorFiltro(zSiscomQt3::Texto(QLEFiltro),
					      zSiscomQt3::Texto(QLECantidad),
					      zSiscomQt3::Texto(QLECostoUnitario),
					      zSiscomQt3::Texto(QLEPeso),
					      &zProdsImportados);

}
void QComprasImportaciones::ConsultandoProductosPorFiltro()
{
char lchrArrNumPartidas[28];
 ConsultaProductosFiltrados();
 zComImportacion.Productos(zProdsImportados);
 zProdsImportados->Partidas(lchrArrNumPartidas);
 QLENumPartidas->setText(lchrArrNumPartidas);
}
void QComprasImportaciones::ActualizaDatosProducto()
{
QActualizaProductoImportado lQProdImportado(zComImportacion.Producto(intProductoSeleccionado));
if(lQProdImportado.Aceptar())
Calculando();
}

void QComprasImportaciones::ConsultandoCompraImportacion(const char *pchrPtrIdCompra)
{
char lchrArrMensaje[128];
if(!ConsultaCompraImportacion(pchrPtrIdCompra,lchrArrMensaje))
{
zEmpresaA=zComImportacion.UltimoProveedor();
HabilitaProveedores();
MuestraCompraImportacion();
HabilitandoRegistraCompra();
Calculando();
QLEDscCompra->setEnabled(false);
QPBGuardaCompraComo->setEnabled(true);
}
else
QMessageBox::information(this,"Aviso Sistema",lchrArrMensaje);
}
void QComprasImportaciones::HabilitaProveedores()
{
QCtrProveedores->setEnabled(false);
}
int QComprasImportaciones::ConsultaCompraImportacion(const char *pchrPtrIdCompra,
						      char *pchrPtrMensaje)
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ConsultaCompraImportacion");
return lzSisElectronica.ConsultaCompraImportacion(pchrPtrIdCompra,
						  &zComImportacion,
						  pchrPtrMensaje);

}
void QComprasImportaciones::MuestraCompraImportacion()
{
QLECostoEnvio->setText(zComImportacion.CostoEnvio());
QLECostoDolar->setText(zComImportacion.CostoDolar());
QLENumPartidas->setText(zComImportacion.NumPartidas());
QLECostoAdministrativo->setText(zComImportacion.CostoAdministrativo());
QLENumFactura->setText(zComImportacion.NumFactura());
MuestraProductos();
MuestraDescripcion();
MuestraProveedor();
}

const char *QComprasImportaciones::FormaSignalCambiandoDato(const char *pchrPtrDato)
{
char lchrArrSenal[120];
sprintf(lchrArrSenal, "%s",SIGNAL(textChanged(const QString &)));
}
void QComprasImportaciones::GuardaCompraImportacion()
{
zSiscomElectronica lzSisEleGuardaCompra(zSisConexion,"GuardaCompraImportacion");
lzSisEleGuardaCompra.GuardaCompraImportacion(&zComImportacion);
}
void QComprasImportaciones::GuardandoCompraImportacion()
{
 if(YaTieneDescripcionCompra())
 GuardaCompraImportacion();
}
int QComprasImportaciones::YaTieneDescripcionCompra()
{
   
}
int QComprasImportaciones::ValidandoParaAnexar()
{
int lintValidaDatosEnvio=ValidaDatosEnvio(),
    lintValidaDatos=ValidandoDatos();
    QCtrProductos->setEnabled(lintValidaDatosEnvio); 
    QPBAnexar->setEnabled(lintValidaDatos); 
 return lintValidaDatosEnvio && lintValidaDatos;
}
void QComprasImportaciones::VeSiSePasaElFocoAProducto()
{
  if(ValidandoParaAnexar())
  zSiscomQt3::Foco(QCtrProductos); 
  else
  LogSiscom("NO Se pasa el foco");
}
void QComprasImportaciones::HabilitandoGuardaCompra()
{
   QPBGuardaCompra->setEnabled(zSiscomQt3::TextoValido(QLEDscCompra));
}
void QComprasImportaciones::HabilitaProductos()
{
  QCtrProductos->setEnabled(!ValidandoNumeroPartidas());
}
void QComprasImportaciones::HabilitandoRegistraCompra()
{
  QPBRegistraCompra->setEnabled(ValidandoNumeroPartidas() &&  
   				YaSeleccionoBodega());
}
void QComprasImportaciones::HabilitandoBodegas()
{
   QPBBodegas->setEnabled(ValidandoNumeroPartidas());
}
void QComprasImportaciones::CargandoCompra()
{
QSeleccionaCompraImp lQSelComImp(chrPtrArgumentos);
if(lQSelComImp.Aceptar())
{
 ConsultandoCompraImportacion(lQSelComImp.CompraImportacion()->IdCompraImportacion()); 
 AsignaGenerales();
}
}
void QComprasImportaciones::MuestraDescripcion()
{
   QLEDscCompra->setText(zComImportacion.Descripcion()); 
}
void QComprasImportaciones::closeEvent(QCloseEvent *pQCEAccion)
{
 QMessageBox::information(this,"Aviso del Sistema","Se va a cerrar revisar ...");
 pQCEAccion->accept();
}
void QComprasImportaciones::ConsultaProductoImportadoInf(zSiscomRegistro *pzSisRegProProd)
{
zSiscomElectronica lzSisEleProImpInf(zSisConexion,"ProductoImportadoInf");
lzSisEleProImpInf.ProductoImportadoInf(pzSisRegProProd,
				       zEmpresaA,
				       zProdImportadoInf);
}
void QComprasImportaciones::ProductoImportadoInf(zSiscomRegistro *pzSisRegProProd)
{
   zProdImportadoInf=new zProductoImportadoInf;
   ConsultaProductoImportadoInf(pzSisRegProProd);
   MuestraProductoImportadoInf();
}
void QComprasImportaciones::MuestraProductoImportadoInf()
{
 if(zProdImportadoInf->Peso())
 QLEPeso->setText(zProdImportadoInf->Peso());
 if(zProdImportadoInf->Cantidad())
 QLECantidadUC->setText(zProdImportadoInf->Cantidad());
 if(zProdImportadoInf->CostoUnitarioDolares())
 {
 QLECostoUC->setText(zProdImportadoInf->CostoUnitarioDolares());
 QLECostoUnitario->setText(zProdImportadoInf->CostoUnitarioDolares()); 
 }
 if(zProdImportadoInf->Compra())
 QLEFechaUC->setText(zProdImportadoInf->Compra()->Fecha());
}
int QComprasImportaciones::TieneClaveProveedor()
{
   if(zProdImportadoInf->CveProveedor())
   return 1;
   else
   return 0;
}
void QComprasImportaciones::TeniendoClaveProveedor()
{
int lintRegreso;
    if(!(lintRegreso=TieneClaveProveedor()))
    QMessageBox::information(this,
    			    "Aviso Del Sistema",
			    "El Producto NO TIENE Clave del PROVEEDOR");
    HabilitaDesHabilitaCantidadCosto(lintRegreso);
}
void QComprasImportaciones::HabilitaDesHabilitaCantidadCosto(bool pbModal)
{
 QLECantidad->setEnabled(pbModal);
 QLECostoUnitario->setEnabled(pbModal);
}
void QComprasImportaciones::GuardarComo()
{
zSiscomElectronica lzSisElect(zSisConexion,"GuardaCompraImportacionComo");
lzSisElect.GuardaCompraImportacionComo(&zComImportacion);
}
void QComprasImportaciones::GuardandoComo()
{
  GuardarComo();
  intSeGuardaComo=0;
}

void QComprasImportaciones::CompraImportacion(zCompraImportacion *pzComImportacion)
{
   zComImportacion=*pzComImportacion;    
}
void QComprasImportaciones::HabilitandoProveedoresCompra()
{
   QPBProveedores->setEnabled(zComImportacion.Productos()->NNodos());
}
void QComprasImportaciones::MuestraProveedor()
{
QLEProveedor->setText(QString(zEmpresaA->RazonSocial())+
		      " " + zEmpresaA->IdEmpresa());
}

void QComprasImportaciones::ArchivoCompraProveedor()
{
  QString lQStrArchivo = QFileDialog::getOpenFileName(
                    "/home/hgarduno",
                    "Archivos (*.csv)",
                    this,
                    "file dialog",
                    "Selecciona el archivo" );  
zFacturaImportacion lzFacImp((const char *)lQStrArchivo,
			     zEmpresaA->IdEmpresa());  
zComImportacion.Productos(lzFacImp.Productos());
}
void QComprasImportaciones::CompletaProductosImportacion()
{
zSiscomElectronica lzSisElec(zSisConexion,"CompletaProductosImportacion");
lzSisElec.CompletaProductosImportacion(&zComImportacion);
}
zProductoImportado *QComprasImportaciones::ProductoImportado(int pintNProducto)
{
   return zComImportacion.Producto(pintNProducto); 
}

void QComprasImportaciones::ActualizaPrecioUnitario(const char *pchrPtrPrecio,
						    zProductoImportado *pzProdImportado)
{
  pzProdImportado->CostoUnitarioDolares(pchrPtrPrecio);
  Calculando();
}


void QComprasImportaciones::ActualizaPeso(zProductoImportado *pzProdImportado)
{
zSiscomElectronica lzSisElectronica(zSisConexion,"ActualizaPeso");
lzSisElectronica.ActualizaPesoProducto(pzProdImportado);
}
void QComprasImportaciones::ActualizaPeso(const char *pchrPtrPrecio,
					  zProductoImportado *pzProdImportado)
{
  pzProdImportado->Peso(pchrPtrPrecio);
  ActualizaPeso(pzProdImportado);
  Calculando();
}

void QComprasImportaciones::MuestraBodega()
{
  QLEBodega->setText((*SisReg3Bodega)["bodega"]);
}
void QComprasImportaciones::BodegasSiscom()
{
QBodegasSiscom lQBSiscom(SisDatCom,chrPtrArgumentos);
if(lQBSiscom.Aceptar())
{
   SisReg3Bodega=lQBSiscom.Bodega();
   MuestraBodega();
   zComImportacion.IdBodega((*SisReg3Bodega)["idbodega"]);
   HabilitandoRegistraCompra();
}
}
void QComprasImportaciones::HabilitaSeleccionaBodega()
{
  QPBBodegas->setEnabled(ValidandoNumeroPartidas());
}
int QComprasImportaciones::YaSeleccionoBodega()
{
      return SisReg3Bodega ? 1 :0 ; 
}

void QComprasImportaciones::RegistrandoParcialmenteCompra()
{
 if(!QRegParComImp)
 {
   zComParcialI->Compra(&zComImportacion); 
   QRegParComImp=new QRegistroParcialComImp(zComParcialI,QWParent);
   QRegParComImp->CompraImportacion(&zComImportacion);
   connect(QRegParComImp,SIGNAL(SignalRegistro()),SLOT(SlotRegistroParcialCompra()));
 }
}
void QComprasImportaciones::SlotRegistroParcialCompra()
{
    delete QRegParComImp;
    GuardandoCompraImportacion();
}
void QComprasImportaciones::AgregandoProductoParaRegistroParcial(zProductoImportado *pzProdImportado)
{
    if(QRegParComImp)
    QRegParComImp->AgregandoProducto(pzProdImportado);
}
void QComprasImportaciones::AsignaGenerales()
{
   zComImportacion.IdExpendio(*(chrPtrArgumentos+0));
   zComImportacion.IdResponsable(*(chrPtrArgumentos+1));
}
void QComprasImportaciones::ActualizandoCompra()
{
 EnviaActualizacionCompra();
}
void QComprasImportaciones::EnviaActualizacionCompra()
{
zSiscomElectronica lzSiscomE(zSiscomDesarrollo4::Conexion(),"ActualizacionCompraRegistrada");
lzSiscomE.ActualizaCompraImportacionRegistrada(&zComImportacion);
}

void QComprasImportaciones::HabilitaRegistroParcialActualizaCompra(QPushButton *pQPBBoton)
{
  pQPBBoton->setEnabled(SisReg3Bodega ? true : false);
}
