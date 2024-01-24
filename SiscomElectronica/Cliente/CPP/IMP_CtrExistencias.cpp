#include <IMP_CtrExistencias.h>
#include <IMP_RangoPorcentaje.h>

#include <SiscomDesarrollo3Qt++.h>
#include <CQSis3QtOperaciones.h>
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

QCtrExistencias *InstanciaCtrExistencias(void *pSisDatCom,
					 char **pchrPtrArgumentos,
					 void *pQWParent,
					 const char *pchrPtrName,
					 int pintWFlags)
{
	return new QCtrExistencias((SiscomDatCom *)pSisDatCom,
				   pchrPtrArgumentos,
				   (QWidget *)pQWParent,
				   pchrPtrName,
				   pintWFlags);

}

QCtrExistencias::QCtrExistencias(SiscomDatCom *pSisDatCom,
				 char **pchrPtrArgumentos,
				  QWidget* parent,
				  const char* name,
				  WFlags fl )
    : CtrExistencias( parent, name, fl ),
    SisDatCom(pSisDatCom),
    chrPtrArgumentos(pchrPtrArgumentos),
    intActivarAnexarProductos(0)
{
	IniciaVariables();
	ConectaSlots();

}

QCtrExistencias::~QCtrExistencias()
{
}
void QCtrExistencias::IniciaVariables()
{
	QLECProductos=SiscomColocaEditAlCombo(QCBProductos,"QLECProductos");
	QMProductos=new QManProductos(SisDatCom,
				      chrPtrArgumentos[0],
				      QCBProductos,
				      QLECProductos,
				      QLEDescripcion,
				      this,
				      "QMProductos");
    SiscomDesarrollo3Qt::PasaFocoControl(QMProductos);
}
void QCtrExistencias::ConectaSlots()
{
	connect(QMProductos,
		SIGNAL(SignalProducto(ProductoE *)),
		SLOT(S_SeleccionoProducto(ProductoE *)));
	connect(QMProductos,
		SIGNAL(SignalNoEstaClave(const char *)),
		SLOT(S_NoEstaClave(const char *)));
	connect(QPBPExistencia,
		SIGNAL(clicked()),
		SLOT(S_PorcentajeExistencia()));
	connect(QPBExistenciaM,
		SIGNAL(clicked()),
		SLOT(S_ExistenciaMinima()));
	connect(QPBAAnexarP,
		SIGNAL(clicked()),
		SLOT(S_ActivarAnexarProductos()));
	connect(QPBExExpendio,
		SIGNAL(clicked()),
		SLOT(S_ExistenciasExpendio()));
	connect(QPBProdsBodega,
		SIGNAL(clicked()),
		SLOT(S_ProdsBodega()));
}
void QCtrExistencias::S_ProdsBodega()
{
	ConsultandoProductosBodega();
}
void QCtrExistencias::S_ExistenciasExpendio()
{
	ConsultandoExistenciasExpendio();
}
void QCtrExistencias::S_ActivarAnexarProductos()
{
   if(!intActivarAnexarProductos)
   {
    QPBAAnexarP->setText("Anexando Productos");
    intActivarAnexarProductos=1;
   }
   else
   {
    QPBAAnexarP->setText("Activar Anexar Productos");
    intActivarAnexarProductos=0;
   }
   QMProductos->setFocus(); 
}
void QCtrExistencias::S_PorcentajeExistencia()
{
QRangoPorcentaje lQRPorcentaje;
char lchrArrAlto[25],
	lchrArrBajo[25];
	if(lQRPorcentaje.ObtenOpcion())
	{
	   lQRPorcentaje.ObtenRango(lchrArrBajo,lchrArrAlto);
	   /*
	   ConsultaProductosE lCnsProductos(SisDatCom);
	   PProductos.clear();
	   lCnsProductos.ObtenProductosPorcentajeExistenciaMinima(
	   				chrPtrArgumentos[0],
					lchrArrBajo,
					lchrArrAlto,
					PProductos);
	  MuestraProductos();
	  */
	   ConsultandoPorcentajeExMinima(lchrArrBajo,
	   				 lchrArrAlto);
	}
}
void QCtrExistencias::S_SeleccionoProducto(ProductoE *pProducto)
{
ConsultandoExistenciasProductos((*pProducto)["CveProducto"]);
SiscomDesarrollo3Qt::PasaFocoControl(QMProductos);
}

void QCtrExistencias::S_ExistenciaMinima()
{
  ReportePorExistenciaMinima();
}

void QCtrExistencias::S_NoEstaClave(const char *pchrPtrCasiClave)
{
ConsultandoExistenciasProductosPorCasiClave(pchrPtrCasiClave);
SiscomDesarrollo3Qt::PasaFocoControl(QMProductos);
}
void QCtrExistencias::MuestraProductos()
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
				      lProducto->SRegistrosPro2["Existencia"]  <<
				      lProducto->SRegistrosPro2["ExistenciaMinima"]);

}
void QCtrExistencias::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
void QCtrExistencias::ReportePorExistenciaMinima()
{
   ConsultaReportePorExistenciaMinima();
   MuestraReportePorExistenciaMinima();
}
void QCtrExistencias::ConsultaReportePorExistenciaMinima()
{
CQSis3QtOperaciones lCQSis3QtOpReporte(SisDatCom);
VeSiEliminaConsultaAnterior();
lCQSis3QtOpReporte.ReportePorExistenciaMinima(chrPtrArgumentos[0],
					      &SisReg3LstReporteExMinima);
}
void QCtrExistencias::ConsultaPorcentajeExMinima(const char *pchrPtrPAlto,
						 const char *pchrPtrPBajo)
{
CQSis3QtOperaciones lCQSis3QtOpReporte(SisDatCom);
VeSiEliminaConsultaAnterior();
lCQSis3QtOpReporte.ProductosPorcentajeExistenciaMinima(chrPtrArgumentos[0],
					      pchrPtrPAlto,
					      pchrPtrPBajo,
					      &SisReg3LstReporteExMinima);


}
void QCtrExistencias::ConsultandoPorcentajeExMinima(const char *pchrPtrPAlto,
						    const char *pchrPtrPBajo)
{
	ConsultaPorcentajeExMinima(pchrPtrPAlto,
				   pchrPtrPBajo);
	
	MuestraExistenciasProductos();
}
void QCtrExistencias::MuestraReportePorExistenciaMinima()
{
const char *lchrPtrCamposReporte[]=
 {"cveproducto",
  "total",
  "existencia",
  "exbodegas",
  "eximinima",
  "fechaultimacompra",
  "cantidadultimacompra",
  "precioultimacompra",
  "proveedor",
  "ventsemestreanterior",
  "comsemestreanterior",
  "ventactuales",
  "comactuales",
  0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCamposReporte,
				       QTDatos,
				       &SisReg3LstReporteExMinima);
SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
}

void QCtrExistencias::ConsultandoExistenciasProductos(const char *pchrPtrCveProducto)
{
	ConsultaExistenciasProductos(pchrPtrCveProducto);
	MuestraExistenciasProductos();
}
void QCtrExistencias::ConsultaExistenciasProductos(const char *pchrPtrCveProducto)
{
CQSis3QtOperaciones lCQSis3QtOpReporte(SisDatCom);
VeSiEliminaConsultaAnterior();
	lCQSis3QtOpReporte.ExistenciasProductos(
				chrPtrArgumentos[0],
				pchrPtrCveProducto,
				&SisReg3LstReporteExMinima);

}


void QCtrExistencias::ConsultandoExistenciasProductosPorCasiClave(const char *pchrPtrCveProducto)
{
	ConsultaExistenciasProductosPorCasiClave(pchrPtrCveProducto);
	MuestraExistenciasProductos();
}
void QCtrExistencias::ConsultaExistenciasProductosPorCasiClave(const char *pchrPtrCveProducto)
{
CQSis3QtOperaciones lCQSis3QtOpReporte(SisDatCom);
VeSiEliminaConsultaAnterior();
	lCQSis3QtOpReporte.ExistenciasProductosPorCasiClave(
				chrPtrArgumentos[0],
				pchrPtrCveProducto,
				&SisReg3LstReporteExMinima);

}
void QCtrExistencias::ConsultaExistenciasExpendio()
{
CQSis3QtOperaciones lCQSis3QtOpReporte(SisDatCom);
	lCQSis3QtOpReporte.ExistenciasExpendio(
				chrPtrArgumentos[0],
				&SisReg3LstReporteExMinima);
}
void QCtrExistencias::ConsultandoExistenciasExpendio()
{
	ConsultaExistenciasExpendio();
	MuestraExistenciasProductos();
}
void QCtrExistencias::MuestraExistenciasProductos()
{
	MuestraReportePorExistenciaMinima();
}

void QCtrExistencias::VeSiEliminaConsultaAnterior()
{
	if(!intActivarAnexarProductos)
	 SisReg3LstReporteExMinima.clear();
}

void QCtrExistencias::ConsultaProductosBodega()
{
CQSis3QtOperaciones lCQSis3QtOpReporte(SisDatCom);
	lCQSis3QtOpReporte.ExistenciasProductosBodega(
				chrPtrArgumentos[0],
				&SisReg3LstReporteExMinima);
}
void QCtrExistencias::ConsultandoProductosBodega()
{
	ConsultaProductosBodega();
	MuestraExistenciasProductos();

}
