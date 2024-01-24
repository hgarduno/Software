#include <IMP_MaterialPractica.h>
#include <IMP_ProductoPractica.h>
#include <SISCOMComunicaciones++.h>
#include <CotizaDispositivos.h>

#include <Practicas.h>
#include <Materias.h>
#include <Escuelas.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qlcdnumber.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>


QMaterialPractica::QMaterialPractica(Escuela *pEscuela,
				     Materia *pMateria,
				     Practica *pPractica,
				     SiscomDatCom *pSisDatCom,
				     char **pchrPtrArgumentos,
				     QWidget* parent,
				     const char* name,
				     bool modal,
				     WFlags fl )
    : MaterialPractica( parent, name, modal, fl ),
    EEscuela(pEscuela),
    MMateria(pMateria),
    PPractica(pPractica),
    SisDatCom(pSisDatCom),
    chrPtrArgumentos(pchrPtrArgumentos)
{
	MuestraDatos();
	MuestraMaterial();
	ConectaSlots();
	exec();
}

QMaterialPractica::~QMaterialPractica()
{
}
void QMaterialPractica::MuestraDatos()
{
    QLEEscuela->setText(EEscuela->SRegistrosPro2["Nombre"]);
    QLEMateria->setText(MMateria->SRegistrosPro2["Nombre"]);
    QLEPractica->setText(PPractica->SRegistrosPro2["Nombre"]);
}
void QMaterialPractica::MuestraMaterial()
{
int lintNumFilas;
int lintContador;
ProductoE *lProducto;
PProductos.clear();
ConsultaPracticas lCnsPracticas(SisDatCom,
			        PPractica->SRegistrosPro2["IdPractica"],
				chrPtrArgumentos[0],
				"DEFAULT",
				PProductos);
	lintNumFilas=PProductos.count()-1;	
	QTDatos->setNumRows(lintNumFilas);
	for(lintContador=0,
	    lProducto=PProductos.first();
	    lintContador<lintNumFilas;
	    lintContador++,
	    lProducto=PProductos.next())
	 SiscomAnexarRegistroALaTabla(lintContador,
	 			      QTDatos,
				      QStringList() <<
				      lProducto->SRegistrosPro2["CveProducto"] <<
				      lProducto->SRegistrosPro2["Cantidad"]    <<
				      lProducto->SRegistrosPro2["EdoRegistro"]);
	if(lProducto)
	QLCDNTotal->display(lProducto->SRegistrosPro2["Importe"]);
	
	    
}

void QMaterialPractica::ConectaSlots()
{
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(S_Anexar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(S_MaterialPractica()));
	connect(QPBEliminar,
		SIGNAL(clicked()),
		SLOT(S_EliminarProductos()));
}
void QMaterialPractica::S_EliminarProductos()
{
QMemArray<int> lQMAProdEli=SiscomFilasSeleccionadas(QTDatos);
int lintContador;

	if(lQMAProdEli.count())
	{
	  for(lintContador=0;
	      lintContador<lQMAProdEli.count();
	      lintContador++)
	  {
	   PProductos.at(lQMAProdEli[lintContador])->SiscomActualizaCampo("IdPractica",PPractica->SRegistrosPro2["IdPractica"]);
	   PProductos.at(lQMAProdEli[lintContador])->SiscomActualizaCampo("EdoRegistro","Eliminar");
	  }
	  ConsultaPracticas lCnsPracticas;
	  lCnsPracticas.RegistraDetallePractica(SisDatCom,PProductos);
	  MuestraMaterial();
	}
}
void QMaterialPractica::S_MaterialPractica()
{
ConsultaPracticas lCnsPracticas;
		lCnsPracticas.RegistraDetallePractica(SisDatCom,
						      PProductosPractica);
	

	MuestraMaterial(); 
}
void QMaterialPractica::S_Anexar()
{
QProductoPractica lQPPractica(SisDatCom,
			      chrPtrArgumentos[0],
			      "DEFAULT");
ProductoE *lProducto;
	if((lProducto=lQPPractica.ObtenProducto()))
	{
		AnexaProducto(lProducto);
		CotizaPractica();
		
	}
}
void QMaterialPractica::AnexaProducto(ProductoE *pProducto)
{
int lintNFilas;
	/*
	 * En el campo de IdFamilia se pasa el IdPractica
	 */
	pProducto->SiscomActualizaCampo("IdPractica",PPractica->SRegistrosPro2["IdPractica"]);
	pProducto->SiscomActualizaCampo("EdoRegistro","Insertar");
	pProducto->SiscomActualizaCampo("NmbTipoPrecio","DEFAULT");
	pProducto->SiscomActualizaCampo("IdExpendio",chrPtrArgumentos[0]);
	PProductos << pProducto;
	PProductosPractica << pProducto;
	lintNFilas=QTDatos->numRows();
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "--> %d",
			  lintNFilas);
	/*
	if((lintNFilas=PProductos.count())!=1)
	lintNFilas--;

	*/
	
	QTDatos->setNumRows(lintNFilas+1);
	SiscomAnexarRegistroALaTabla(lintNFilas,
				     QTDatos,
				     QStringList() <<
				     pProducto->SRegistrosPro2["CveProducto"] <<
				     pProducto->SRegistrosPro2["Cantidad"]    <<
				     pProducto->SRegistrosPro2["EdoRegistro"]);

}
void QMaterialPractica::CotizaPractica()
{
int lintNRegistros;
CotizaDispositivosE lCotProductos(SisDatCom,
				  PProductos);
	if((lintNRegistros=PProductos.count()))
	 QLCDNTotal->display(PProductos.at(lintNRegistros-1)->SRegistrosPro2["Importe"]);
}
