#include <IMP_ManejadorProductos.h>
#include <IMP_MantenProductos.h>
#include <IMP_CambiaEliminaClaveProducto.h>

#include <zSiscomQt3.h>
#include <Familias.h>
#include <Unidades.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qmessagebox.h>
QManejadorProductos *InstanciaManejadorProductos(void *pSisDatCom,
						 char **pchrPtrArgumentos,
						 void *pQWParent,
						 const char *pchrPtrName,
						 int pintWFlags)
{
	return new QManejadorProductos((SiscomDatCom *)pSisDatCom,
				       pchrPtrArgumentos,
				       (QWidget *)pQWParent,
				       pchrPtrName,
				       pintWFlags);
}
		



QManejadorProductos::QManejadorProductos(SiscomDatCom *pSisDatCom,
 				         char **pchrPtrArgumentos,
					 QWidget* parent, const char* name, WFlags fl )
    : ManejadorProductos( parent, name, fl ),
    SisDatCom(pSisDatCom),
    chrPtrArgumentos(pchrPtrArgumentos)
{
	IniciaVariables();
	ConectaSlots();
}

QManejadorProductos::~QManejadorProductos()
{
}
void QManejadorProductos::IniciaVariables()
{
	QLECFamilias=SiscomColocaEditAlCombo(QCBFamilias,"QLECFamilias");
	QLECUnidades=SiscomColocaEditAlCombo(QCBUnidades,"QLECUnidades");
	MFamilias=new ManFamilias(SisDatCom,
			      QCBFamilias,
			      QLECFamilias,
			      0,
			      this,
			      "MFamilias");
	MUnidades=new ManUnidades(SisDatCom,
			      QCBUnidades,
			      QLECUnidades,
			      0,
			      0,
			      this,
			      "MUnidades");
	SiscomPasaFocoControl(QLECFamilias);
	FFamilia=MFamilias->ObtenFamilia(0);
	UUnidad=MUnidades->ObtenUnidad(0);
	/*
	QPBAnexar->setEnabled(FFamilia &&
			     UUnidad); 
	*/
	HabilitandoAnexar();
}

void QManejadorProductos::ConectaSlots()
{
	connect(QPBMDatos,
		SIGNAL(clicked()),
		SLOT(S_ModificaProductos()));
	connect(QLECFamilias,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoUnidades()));
	connect(QLECUnidades,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoProducto()));
	connect(QLEProducto,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoDescripcion()));
	/*
	connect(QLEDescripcion,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAnexarProducto()));
	*/
	connect(MFamilias,
		SIGNAL(SignalFamilia(Familia *)),
		SLOT(S_SeleccionoFamilia(Familia *)));
	connect(MUnidades,
		SIGNAL(SignalUnidad(Unidad *)),
		SLOT(S_SeleccionoUnidad(Unidad *)));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_AnexarProducto()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_RegistraProductos()));
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(S_EliminarDeLaLista()));

	connect(QPBModEliClave,
		SIGNAL(clicked()),
		SLOT(S_CambiaEliminaClave()));
	connect(QLEDescripcion,SIGNAL(textChanged()),SLOT(S_CapturandoDescripcion()));
	connect(QLEProducto,
		SIGNAL(textChanged(const QString &)),
		SLOT(S_CapturandoClave(const QString &)));
}
void QManejadorProductos::S_CapturandoClave(const QString &)
{
 MuestraCaracteres(QLEProducto->text(),QLENClave);
 HabilitandoAnexar();
}
void QManejadorProductos::S_CapturandoDescripcion()
{
      MuestraCaracteres(QLEDescripcion->text(),QLENCDescripcion);     
      HabilitandoAnexar();
}
void QManejadorProductos::S_ModificaProductos()
{
   QMantenProductos lQMProductos(SisDatCom,chrPtrArgumentos[0]);  
}
void QManejadorProductos::S_CambiaEliminaClave()
{
QCambiaEliminaClaveProducto lQCEClaveProd(SisDatCom,
					  chrPtrArgumentos);
}
void QManejadorProductos::S_EliminarDeLaLista()
{
QMemArray<int> lQMemAProductos=SiscomFilasSeleccionadas(QTDatos);
int lintContador;
		if(!lQMemAProductos.count())
		QMessageBox::information(this,
					 "Siscom Electronica",
					 "NO se han seleccionado Productos");
		else
		{
		  ProductosE lProductos;
		  for(lintContador=0;
		      lintContador<lQMemAProductos.count();
		      lintContador++)
		    lProductos << PProductos.at(lQMemAProductos[lintContador]);
		    ProductoE *lProducto;
		    for(lProducto=lProductos.first();
		    	lProducto;
			lProducto=lProductos.next())
		    PProductos.remove(lProducto);
		    QTDatos->removeRows(lQMemAProductos);
		}
   QPBRegistrar->setEnabled(QTDatos->numRows());
}
void QManejadorProductos::S_RegistraProductos()
{
ConsultaProductosE lCnsProdReg(SisDatCom);
		lCnsProdReg.RegistraProductos(PProductos);
		PProductos.clear();
		QTDatos->setNumRows(0);

}
void QManejadorProductos::S_AnexarProducto()
{	
int lintNumFilas=QTDatos->numRows();
ProductoE *lProductoE;
	QTDatos->setNumRows(lintNumFilas+1);
	SiscomAnexarRegistroALaTabla(lintNumFilas,
				     QTDatos,
				     QStringList() 	 	<<
				     QLEProducto->text()	<<
				     QLEDescripcion->text()	<<
				     FFamilia->SRegistrosPro2["NmbFamilia"] <<
				     UUnidad->SRegistrosPro2["NmbUnidad"]);
	SiscomPasaFocoControl(QLECFamilias);
	lProductoE = new ProductoE((const char *)QLEProducto->text(),
				   (const char *)QLEDescripcion->text(),
				   UUnidad->SRegistrosPro2["IdUnidad"],
				   FFamilia->SRegistrosPro2["IdFamilia"]);
	lProductoE->SiscomActualizaCampo("IdExpendio",chrPtrArgumentos[0]);
	PProductos << lProductoE;
AnexandoProducto();
}
void QManejadorProductos::S_SeleccionoFamilia(Familia *pFamilia)
{
	FFamilia=pFamilia;
	/*
	QPBAnexar->setEnabled(FFamilia &&
			     UUnidad); 

	 */
	HabilitandoAnexar();
}
void QManejadorProductos::S_SeleccionoUnidad(Unidad *pUnidad)
{
	UUnidad=pUnidad;
	/*
	QPBAnexar->setEnabled(FFamilia &&
			     UUnidad); 
	*/
	HabilitandoAnexar();
}
void QManejadorProductos::S_PasaFocoUnidades()
{
	SiscomPasaFocoControl(QLECUnidades);
}
void QManejadorProductos::S_PasaFocoProducto()
{
	SiscomPasaFocoControl(QLEProducto);
			
}
void QManejadorProductos::S_PasaFocoDescripcion()
{
	SiscomPasaFocoControl(QLEDescripcion);
}
void QManejadorProductos::S_PasaFocoAnexarProducto()
{
	SiscomPasaFocoControl(QPBAnexar);
}

void QManejadorProductos::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
void QManejadorProductos::MuestraCaracteres(const QString &pQStrTexto,QLineEdit *pQLENCaracteres)
{
   pQLENCaracteres->setText(QString().sprintf("%d",pQStrTexto.length()));   
}
int QManejadorProductos::CaracteresCadena(const QString &pQStrCadena,
					 int pintCaracteres)
{
   return pQStrCadena.length() > 0  &&
          pQStrCadena.length() <= pintCaracteres;
}
void QManejadorProductos::HabilitandoAnexar()
{
	QPBAnexar->setEnabled(FFamilia &&
			      UUnidad  &&
			      CaracteresCadena(QLEProducto->text(),50) &&
			      CaracteresCadena(QLEDescripcion->text(),250)); 
}

void QManejadorProductos::AnexandoProducto()
{
   FFamilia=0;
   UUnidad=0;
   QLEDescripcion->setText("");
   QLEProducto->setText("");
   QPBAnexar->setEnabled(false);
   QPBRegistrar->setEnabled(QTDatos->numRows());
   zSiscomQt3::AjustaFilasTabla(QTDatos);
}
