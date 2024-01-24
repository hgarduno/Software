#include <IMP_CtrExistenciasMinimas.h>

#include <SISCOMComunicaciones++.h>

#include <ProductosE.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

QCtrExistenciasMinimas *InstanciaCtrExistenciasMinimas(void *pSisDatCom,
					 char **pchrPtrArgumentos,
					 void *pQWParent,
					 const char *pchrPtrName,
					 int pintWFlags)
{
	return new QCtrExistenciasMinimas((SiscomDatCom *)pSisDatCom,
				   pchrPtrArgumentos,
				   (QWidget *)pQWParent,
				   pchrPtrName,
				   pintWFlags);

}

QCtrExistenciasMinimas::QCtrExistenciasMinimas(SiscomDatCom *pSisDatCom,
				 char **pchrPtrArgumentos,
				  QWidget* parent,
				  const char* name,
				  WFlags fl )
    : CtrExistenciasMinimas( parent, name, fl ),
    SisDatCom(pSisDatCom),
    chrPtrArgumentos(pchrPtrArgumentos)
{
	IniciaVariables();
	ConectaSlots();

}

QCtrExistenciasMinimas::~QCtrExistenciasMinimas()
{
}
void QCtrExistenciasMinimas::IniciaVariables()
{
	QLECProductos=SiscomColocaEditAlCombo(QCBProductos,"QLECProductos");
	QMProductos=new QManProductos(SisDatCom,
				      chrPtrArgumentos[0],
				      QCBProductos,
				      QLECProductos,
				      QLEDescripcion,
				      this,
				      "QMProductos");
	PProductos=QMProductos->ObtenProductos();
	MuestraProductos();
	SiscomPasaFocoControl(QLECProductos);

}
void QCtrExistenciasMinimas::ConectaSlots()
{
	connect(QMProductos,
		SIGNAL(SignalProducto(ProductoE *)),
		SLOT(S_SeleccionoProducto(ProductoE *)));
	connect(QMProductos,
		SIGNAL(SignalNoEstaClave(const char *)),
		SLOT(S_NoEstaClave(const char *)));
	connect(QPBAELista,
		SIGNAL(clicked()),
		SLOT(S_AsignarExistenciaALaLista()));
	connect(QPBActualizar,
		SIGNAL(clicked()),
		SLOT(S_ActualizarExistencias()));
	connect(QLEExistenciaM,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAsignaEMinima()));
	connect(QPBAELista,
		SIGNAL(clicked()),
		SLOT(S_PasaFocoActualizaEMinima()));
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(S_Eliminar()));

}
void QCtrExistenciasMinimas::S_Eliminar()
{
QMemArray<int> lQMAFilas=SiscomFilasSeleccionadas(QTDatos);
int lintContador;
ProductosE lPProductos;

	

	for(lintContador=0;
	    lintContador<lQMAFilas.count();
	    lintContador++)
	{
	 SiscomMensajesLog(gPtrFleArchivoLog,
	 		   "Eliminando:%s",
			   PProductos.at(lQMAFilas[lintContador])->SRegistrosPro2["CveProducto"]);
	  lPProductos << PProductos.at(lQMAFilas[lintContador]);
	}
	for(lintContador=0;
	    lintContador<lQMAFilas.count();
	    lintContador++)
	  PProductos.remove(lPProductos[lintContador]);
	QTDatos->removeRows(lQMAFilas); 
}
void QCtrExistenciasMinimas::S_PasaFocoActualizaEMinima()
{
	SiscomPasaFocoControl(QPBActualizar);
}
void QCtrExistenciasMinimas::S_PasaFocoAsignaEMinima()
{
	SiscomPasaFocoControl(QPBAELista);
}
void QCtrExistenciasMinimas::S_ActualizarExistencias()
{
ConsultaProductosE lCnsProductos(SisDatCom);

		lCnsProductos.ActualizaExistenciaMinima(PProductos);

	SiscomPasaFocoControl(QLECProductos);
}
void QCtrExistenciasMinimas::S_AsignarExistenciaALaLista()
{
ProductoE *lProducto;
	for(lProducto=PProductos.first();
	    lProducto;
	    lProducto=PProductos.next())
	{
	  lProducto->SiscomActualizaCampo("ExistenciaMinima",(const char *)QLEExistenciaM->text());
	  lProducto->SiscomActualizaCampo("IdExpendio",chrPtrArgumentos[0]);
	  lProducto->SiscomActualizaCampo("DscProducto","");
	  lProducto->SiscomActualizaCampo("IdFamilia","");
	  lProducto->SiscomActualizaCampo("NmbPrecio","");
	  lProducto->SiscomActualizaCampo("NmbUnidad","");
	  lProducto->SiscomActualizaCampo("NmbFamilia","");
	  lProducto->SiscomActualizaCampo("Existencia","");
	}

	  MuestraProductos();



}
void QCtrExistenciasMinimas::S_SeleccionoProducto(ProductoE *pProducto)
{
 ConsultaProductosE lCnsProductos(SisDatCom);
 PProductos.clear();
 		lCnsProductos.ObtenDatosProducto(chrPtrArgumentos[0],
						 pProducto->SRegistrosPro2["CveProducto"],
						 "Total",
						 PProductos);
		MuestraProductos();
		SiscomPasaFocoControl(QLEExistenciaM);

						 
}

void QCtrExistenciasMinimas::S_NoEstaClave(const char *pchrPtrCasiClave)
{
ConsultaProductosE lCnsProductos(SisDatCom);
 PProductos.clear();
 		lCnsProductos.ObtenDatosProducto(chrPtrArgumentos[0],
						 pchrPtrCasiClave,
						 "Similares",
						 PProductos);
		MuestraProductos();

}
void QCtrExistenciasMinimas::MuestraProductos()
{
ProductoE *lProducto;
int lintContador;
	QTDatos->setNumRows(PProductos.count());
	for(lProducto=PProductos.first(),
	    lintContador=0;
	    lProducto;
	    lProducto=PProductos.next(),
	    lintContador++)
	  SiscomAnexarRegistroALaTabla(lintContador,
	  			      QTDatos,
				      QStringList() <<
				      lProducto->SRegistrosPro2["CveProducto"] <<
				      lProducto->SRegistrosPro2["ExistenciaMinima"]);

}
void QCtrExistenciasMinimas::closeEvent(QCloseEvent *)
{
  emit SignalTerminar(this);
}
