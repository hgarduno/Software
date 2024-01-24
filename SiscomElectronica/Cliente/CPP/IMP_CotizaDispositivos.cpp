#include <IMP_CotizaDispositivos.h>
#include <IMP_ProdSimilares.h>
#include <IMP_CapturaDato.h>
#include <CotizaDispositivos.h>
#include <SiscomDesarrollo3Qt++.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qmessagebox.h>

QCotizaDispositivos::QCotizaDispositivos(SiscomDatCom *pSisDatCom,
					 const char *pchrPtrIdExpendio,
					 const char *pchrPtrIdTipoPersona,
					 const char *pchrPtrNmbTipoPrecio,
				         QWidget* parent,
					 const char* name,
					 WFlags fl )
    : Seguridad3Protocolo2(getenv("Aplicacion"),
      			   pchrPtrIdTipoPersona,
			   pSisDatCom,
			   this), 
	/*
	 Tepotzotlan Mexico
	 Sabado 4 de Septiembre 2009.
	 Se observo que el tamano de la letra que se tiene 
	 almacenado en la base de datos de seguridad para 
	 esta pantalla hace que en los monitores de 15 pulgadas
	 la pantalla ocupe un mayor espacio , por lo que se deci-
	 de eliminar la carga de la informacion para esta pantalla
	 */
    	CotizaDispositivos( parent, name, fl ),
            SisDatCom(pSisDatCom),
      chrPtrIdExpendio(pchrPtrIdExpendio),
      chrPtrNmbTipoPrecio(pchrPtrNmbTipoPrecio)
{
	ConsultaProductos();
	IniciaVariables();
	ConectaSlots();
	show();
}

QCotizaDispositivos::~QCotizaDispositivos()
{
}
void QCotizaDispositivos::ConectaSlots()
{
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoDispositivo()));
	connect(QLEDispositivo,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAnexarOrden()));
	connect(QCBProductos,
		SIGNAL(highlighted(int)),
		SLOT(S_MuestraDescripcion(int)));
	connect(QPBAnexarOrden,
		SIGNAL(clicked()),
		SLOT(S_AnexarALaOrden()));
	connect(QPBPDescripcion,
		SIGNAL(clicked()),
		SLOT(S_ProductosPorDescripcion()));

}
void QCotizaDispositivos::S_ProductosPorDescripcion()
{
char lchrArrDescripcion[1024];
QCapturaDato lQCDato("Descripcion",
		     "Descripcion:");
	lQCDato.ObtenDato(lchrArrDescripcion);
	BuscaProductosPorDescripcion(lchrArrDescripcion);
}
void QCotizaDispositivos::S_AnexarALaOrden()
{
	/* Queretaro a 17 de Noviembre del 2015
	 * Para la integracion con el tipo Precio se agrega ...
	 */
	PProducto->SiscomActualizaCampo("TipoCotizacion","ALaOrden");
	SiscomEscribeLog3Qt("Agregando a la orden");
	emit SignalAnexarALaOrden(PProducto);
}
void QCotizaDispositivos::S_MuestraDescripcion(int pintNProducto)
{
ProductoE *lProducto=PProductos.at(pintNProducto);
	QLEDescripcion->setText(lProducto->SRegistrosPro2["DscProducto"]);
}
void QCotizaDispositivos::S_PasaFocoAnexarOrden()
{
const char *lchrPtrProducto;
	if(QLECantidad->text().toInt()>0)
	{
		if(EsParteLista((lchrPtrProducto=(const char *)QLEDispositivo->text())))
		{
			CotizaDispositivo();
			SiscomPasaFocoControl(QPBAnexarOrden);
		}
		else
		{
			ConsultaClavesSimilares(lchrPtrProducto);
			//SiscomPasaFocoControl(QLEDispositivo);
		}
	}
	else
	{
	SiscomPasaFocoControl(QLECantidad);	
	QPBAnexarOrden->setEnabled(false);
	}
}
void QCotizaDispositivos::S_PasaFocoDispositivo()
{
	SiscomPasaFocoControl(QLEDispositivo);

}
void QCotizaDispositivos::IniciaVariables()
{
	SiscomPasaFocoControl(QLECantidad);
	QLEDispositivo=SiscomColocaEditAlCombo(QCBProductos,"QLEDispositivo");
	if(QLEExistencia->isEnabled()==false)
	QLEExistencia->setEchoMode(QLineEdit::Password);

}
void QCotizaDispositivos::ConsultaProductos()
{
ConsultaProductosE lCnsProductos(SisDatCom,
				"",
				"",
				"",
				chrPtrIdExpendio,
				PProductos);
ProductoE *lProducto;
  for(lProducto=PProductos.first();
      lProducto;
      lProducto=PProductos.next())
	QCBProductos->insertItem(lProducto->SRegistrosPro2["CveProducto"]);
}
void QCotizaDispositivos::CotizaDispositivo()
{
ProductosE lProductos;
int lintSePuedeVender;
ProductoE *lProducto=PProductos.at(QCBProductos->currentItem());
/* Tepotzotlan a viernes 20 de noviembre del 2015
 * Con la integracion del tipo producto (Kits)
 *
 */
ProductoE *lProductoACotizar;
	lProductoACotizar=new ProductoE(lProducto->SRegistrosPro2["CveProducto"],
		      "",
		      "",
		      "",
		      "",
		      chrPtrNmbTipoPrecio,
		      (const char *)QLECantidad->text(),
		      "",
		      "",
		      chrPtrIdExpendio);
		      
	lProductoACotizar->SiscomActualizaCampo("CantidadKit",(const char *)QLECantidad->text());
	lProductos << lProductoACotizar;
CotizaDispositivosE lCotDispo(SisDatCom,
			      lProductos);
if(lCotDispo.EstadoCotizacion())
{
QLEPrcVenta->setText(lProductos.at(0)->SRegistrosPro2["Precio"]);
QLEExistencia->setText(lProductos.at(0)->SRegistrosPro2["Existencia"]);
/* Domingo 2 de Septiembre 2012 
 * Se agrega el campo de la existencia de la bodega, ya que se observo
 * que en la toma de ordenes al marcar 0 en existencia, se tenia que 
 * abrir la pantalla de existencias de bodegas para verificar si hay 
 * producto en la bodega 
 */
QLEExistBodega->setText((*lProductos.at(0))["ExisBodega"]);
QLCNTotal->display(lProductos.at(0)->SRegistrosPro2["Importe"]);

QPBAnexarOrden->setEnabled((lintSePuedeVender=!strcmp(lProductos.at(0)->SRegistrosPro2["SePuedeVender"],"Si")));
if(!lintSePuedeVender)
SiscomPasaFocoControl(QLECantidad);
PProducto=lProductos.at(0);
}
else
 QMessageBox::information(this,"Aviso Sistema","El producto no Existe");
}
void QCotizaDispositivos::setFocus()
{
	SiscomPasaFocoControl(QLECantidad);
}
int QCotizaDispositivos::EsParteLista(const char *pchrPtrCveProducto)
{
ProductoE *lProducto;
	for(lProducto=PProductos.first();
	    lProducto;
	    lProducto=PProductos.next())
	  if(!strcmp(lProducto->SRegistrosPro2["CveProducto"],pchrPtrCveProducto))
	   return 1;
	   return 0;

}
void QCotizaDispositivos::BuscaProductosPorDescripcion(const char *pchrPtrDescripcion)
{
ConsultaProductosE lCnsProductos(SisDatCom);
ProductosE lProductos;
ProductoE *lProducto;
		lCnsProductos.ObtenProductosPorDescripcion(pchrPtrDescripcion,
							   chrPtrIdExpendio,
							   lProductos);

			if(lProductos.count())
			{
			  QProdSimilares lQProdSim(lProductos);
			  if((lProducto=lQProdSim.ObtenProducto()))
			  {
				QLEDispositivo->setText(lProducto->SRegistrosPro2["CveProducto"]);			      		   SiscomPasaFocoControl(QLEDispositivo);
		
			  }
			  else
			  SiscomPasaFocoControl(QCBProductos);
			  
			}
			else
			{
				QMessageBox::information(this,
					 "Siscom Electronica",
					 "No Existen ningun producto Asociado a la Descripcion");
				SiscomPasaFocoControl(QLEDispositivo);
			}


}
void QCotizaDispositivos::ConsultaClavesSimilares(const char *pchrPtrProducto)
{
ConsultaProductosE lCnsProductos(SisDatCom);
ProductosE lProductos;
ProductoE *lProducto;
		lCnsProductos.ObtenProductosSimilares(pchrPtrProducto,
						      chrPtrIdExpendio,
							lProductos);
		if(lProductos.count())
		{
		QProdSimilares lQProdSim(lProductos);	
		lProducto=lQProdSim.ObtenProducto();
		if(lProducto)
		{
		QLEDispositivo->setText(lProducto->SRegistrosPro2["CveProducto"]);			      
		SiscomPasaFocoControl(QLEDispositivo);
		}
		else
		SiscomPasaFocoControl(QCBProductos);
		}
		else
		{
		QMessageBox::information(this,
					 "Siscom Electronica",
					 "No Existen ningun producto Asociado a la Clave");
		SiscomPasaFocoControl(QLEDispositivo);
		}


}

