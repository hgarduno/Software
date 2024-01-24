#include <IMP_MaterialAExpendio.h>
#include <IMP_SelExpendios.h>
#include <IMP_CapturaDato.h>

#include <SiscomDesarrollo3Qt++.h>
#include <ProductosE.h>
#include <CotizaDispositivos.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qiconview.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qmessagebox.h>

QMaterialAExpendio *InstanciaMaterialAExpendio(void *pSisDatCom,
					       char **pchrPtrArgumentos,
					       void *pQWParent,
					       const char *pchrPtrName,
					       int pintWFlags)
{

	return new QMaterialAExpendio((SiscomDatCom *)pSisDatCom,
				      pchrPtrArgumentos,
				      (QWidget *)pQWParent,
				      pchrPtrName,
				      pintWFlags);
}

QMaterialAExpendio::QMaterialAExpendio(SiscomDatCom *pSisDatCom,
				       char **pchrPtrArgumentos,
				 	QWidget* parent,
					const char* name,
					WFlags fl )
    : MaterialAExpendio( parent, name, fl ),
    SisDatCom(pSisDatCom),
    chrPtrArgumentos(pchrPtrArgumentos)
{
	IniciaVariables();
	ConectaSlots();
	ConsultaMatriz();
}

QMaterialAExpendio::~QMaterialAExpendio()
{
}
void QMaterialAExpendio::IniciaVariables()
{
	QLECProductos=SiscomColocaEditAlCombo(QCBProductos,"QLECProductos");
	QMProductos=new QManProductos(SisDatCom,
					chrPtrArgumentos[0],
					QCBProductos,
					QLECProductos,
					QLEDescripcion,
					this,
					"QMProductos");

}
void QMaterialAExpendio::ConectaSlots()
{
	connect(QPBSelExpendio,
		SIGNAL(clicked()),
		SLOT(S_SeleccionaExpendio()));
	connect(QMProductos,
		SIGNAL(SignalProducto(ProductoE *)),
		SLOT(S_Producto(ProductoE *)));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAnexar()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));
	connect(QPBRegistraEnvio,
		SIGNAL(clicked()),
		SLOT(S_RegistraEnvio()));
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(S_Eliminar()));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(S_Producto(int,int,int,const QPoint &)));
	connect(QPBCambiaCantidad,
		SIGNAL(clicked()),
		SLOT(S_CambiaCantidad()));
}
void QMaterialAExpendio::S_CambiaCantidad()
{
char lchrArrCantidad[20];
RegProductoTransfiere *lRegProdTransfiere;
QCapturaDato lQCDato("Cambia Cantidad Producto","Cantidad");
lQCDato.ObtenDato(lchrArrCantidad);
if((lRegProdTransfiere=RegsProTransfiere.at(intProductoActual)))
{
 lRegProdTransfiere->SiscomActualizaCampo("Cantidad",lchrArrCantidad);
 MuestraProductosATransferir(); 
}
QPBCambiaCantidad->setEnabled(false);
QPBEliminar->setEnabled(false);
}
void QMaterialAExpendio::S_Eliminar()
{
	RegsProTransfiere.remove(intProductoActual);
	QTDatos->removeRow(intProductoActual);
	QPBEliminar->setEnabled(false);
	QPBCambiaCantidad->setEnabled(false);
}
void QMaterialAExpendio::S_Producto(int pintNProducto,
				    int,
				    int,
				    const QPoint &)
{
QTDatos->selectRow(pintNProducto);
intProductoActual=pintNProducto;
QPBEliminar->setEnabled(true);
QPBCambiaCantidad->setEnabled(true);
}
void QMaterialAExpendio::S_RegistraEnvio()
{
OpTransfiereProductos lOpTranProductos(SisDatCom);
	lOpTranProductos.EjecutaTransferencia(RegsProTransfiere);
	if(lOpTranProductos.ObtenEdoEnvio())
	{
	  if(lOpTranProductos.NoAlcanza())
	  {
	   ListaNoAlcanza(lOpTranProductos.ProductosNoAlcanza());
	   MuestraProductosATransferir();
	  }
	 else
	   QMessageBox::information(this,
				 "SISCOM Electronica",
				 QString("Error Al Transferir:")+
				 lOpTranProductos.ObtenEdoEnvio());
	}
	else
	{
	QMessageBox::information(this,
				 "SISCOM Electronica",
				 "Transferencia Exitosa");
	RegsProTransfiere.clear();
	QTDatos->setNumRows(0);
	}
}
void QMaterialAExpendio::S_Anexar()
{
/*
 * Domingo 7 de noviembre del 2015  
 * Se integra la validacion de las existencias en el expendio
 * al realizar las transferencias
int lintNFilas;
	QTDatos->setNumRows((lintNFilas=QTDatos->numRows())+1);
	PProducto->SiscomActualizaCampo("Cantidad",
					(const char *)QLECantidad->text());
	SiscomAnexarRegistroALaTabla(lintNFilas,
				     QTDatos,
				     QStringList() <<
				     PProducto->SRegistrosPro2["CveProducto"] <<
				     PProducto->SRegistrosPro2["Cantidad"]);
	 RegsProTransfiere << 
	 new RegProductoTransfiere(PProducto,
	 			   EMatriz->SRegistrosPro2["IdEmpresa"],
				   EExpendio->SRegistrosPro2["IdEmpresa"],
				   chrPtrArgumentos[1]);
	 SiscomPasaFocoControl(QLECProductos);
	 QPBAnexar->setEnabled(false);
	 QPBRegistraEnvio->setEnabled(QTDatos->numRows());
*/
	PProducto->SiscomActualizaCampo("Cantidad",
					(const char *)QLECantidad->text());
	 RegsProTransfiere << 
	 new RegProductoTransfiere(PProducto,
	 			   EMatriz->SRegistrosPro2["IdEmpresa"],
				   EExpendio->SRegistrosPro2["IdEmpresa"],
				   chrPtrArgumentos[1]);
	 MuestraProductosATransferir();
	 SiscomPasaFocoControl(QLECProductos);
	 QPBAnexar->setEnabled(false);
	 QPBRegistraEnvio->setEnabled(QTDatos->numRows());
}
void QMaterialAExpendio::S_PasaFocoAnexar()
{
char lchrArrExistencia[10];
char lchrArrMensaje[256];
	if(VerificaExistencia(lchrArrExistencia))
	{
	QPBAnexar->setEnabled(true);
	SiscomPasaFocoControl(QPBAnexar);
	}
	else
	{
	sprintf(lchrArrMensaje,
		"No Se Puede Anexar El Producto solo hay en existencia %s",
		lchrArrExistencia);

	QMessageBox::information(this,
				 "Aplicacion",
				 lchrArrExistencia);
	}
}
void QMaterialAExpendio::S_Producto(ProductoE *pProducto)
{
	SiscomPasaFocoControl(QLECantidad);
	PProducto=pProducto;
}

void QMaterialAExpendio::S_SeleccionaExpendio()
{
QSelExpendios lQSelExpendio(SisDatCom);

	if((EExpendio=lQSelExpendio.ObtenExpendio()))
	{
	  QLEExpendio->setText(EExpendio->SRegistrosPro2["RazonSocial"]);
	  QCBProductos->setEnabled(true);
	  SiscomPasaFocoControl(QCBProductos);
	  SiscomPasaFocoControl(QLECProductos);
	}
	  else
	  QMessageBox::information(this,
	  			   "Aplicacion",
				   "No Se Selecciono Un Expendio Valido");
}
void QMaterialAExpendio::ConsultaMatriz()
{
ConsultaEmpresasN lCnsMatriz(SisDatCom);
	
	if((EMatriz=lCnsMatriz.ObtenMatriz()))
	 QLEMatriz->setText(EMatriz->SRegistrosPro2["RazonSocial"]);

}
int QMaterialAExpendio::VerificaExistencia(char *pchrPtrExistencia)
{
ProductosE lProductos;
ProductoE *lProducto;
	lProductos << 
	new ProductoE(PProducto->SRegistrosPro2["CveProducto"],
		  "",
		  "",
		  "",
		  "",
		  "DEFAULT",
		  (const char *)QLECantidad->text(),
		  "",
		  "",
		  EMatriz->SRegistrosPro2["IdEmpresa"]);

CotizaDispositivosE lCotDispo(SisDatCom,
			     lProductos);
	if((lProducto=lProductos.at(0)))
	{
	QLEExistencia->setText(lProducto->SRegistrosPro2["Existencia"]);
	strcpy(pchrPtrExistencia,lProducto->SRegistrosPro2["Existencia"]);
	return !strcmp(lProducto->SRegistrosPro2["SePuedeVender"],"Si");
	}
	else
	return 0;
}
void QMaterialAExpendio::closeEvent(QCloseEvent *)
{
 emit SignalTerminar(this);
}
void QMaterialAExpendio::ListaNoAlcanza(SiscomRegistrosPro2 *pSisReg2NoAlcanza)
{
RegProductoTransfiere *lRegProdTransfiere;
pSisReg2NoAlcanza->SiscomColocaPrimerRegistro();
pSisReg2NoAlcanza->SiscomImprimeContenido();
SiscomEscribeLog3Qt("Se muestra la informacion de los que no alcanzan");
     while(!pSisReg2NoAlcanza->SiscomEsElUltimoRegistro())
     {	
     	
	 SiscomEscribeLog3Qt("Este producto no alcanza %s (Existencia:%s Pedido:%s)",
	 		     (*pSisReg2NoAlcanza)["CveProducto"],
	 		     (*pSisReg2NoAlcanza)["Existencia"],
	 		     (*pSisReg2NoAlcanza)["Cantidad"]);
	  lRegProdTransfiere=RegsProTransfiere[pSisReg2NoAlcanza];
	  lRegProdTransfiere->SiscomActualizaCampo("Existencia",(*pSisReg2NoAlcanza)["Existencia"]);
	  lRegProdTransfiere->SiscomActualizaCampo("EdoConexion",(*pSisReg2NoAlcanza)["EdoConexion"]);

	 ++(*pSisReg2NoAlcanza);
     }
}
void QMaterialAExpendio::MuestraProductosATransferir()
{
int lintContador;
RegProductoTransfiere *lRegProdTransfiere;
QMemArray<int> lQMNoAlcanza(RegsProTransfiere.count());
int lintNoAlcanzan=0;
QTDatos->setNumRows(RegsProTransfiere.count());
for(lRegProdTransfiere=RegsProTransfiere.first(),
    lintContador=0;
	lRegProdTransfiere;
	lRegProdTransfiere=RegsProTransfiere.next(),
	lintContador++)
{
   if(!strcmp((*lRegProdTransfiere)["EdoConexion"],"No Alcanza")) 
    lQMNoAlcanza[lintNoAlcanzan++]=lintContador;
   QTDatos->setText(lintContador,0,(*lRegProdTransfiere)["CveProducto"]);
   QTDatos->setText(lintContador,1,(*lRegProdTransfiere)["Cantidad"]);
   QTDatos->setText(lintContador,2,(*lRegProdTransfiere)["Existencia"]);
}
if(lintNoAlcanzan)
SiscomDesarrollo3Qt::ColoreaFilasSeleccionadas(QTDatos,
					       QColor("Red"),
					       lQMNoAlcanza);
}
