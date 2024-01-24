#include <QSisImporteServicios.h>
QSisImporteServicios::QSisImporteServicios(QWidget *pQWParent,
					   const char *pchrPtrName,
					   WFlags pWFlags):
			QWidget(pQWParent,pchrPtrName,pWFlags),
			chrPtrFechaIni(""),
			chrPtrFechaFin("")
{
IniciaInterfaz();

}

void QSisImporteServicios::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QSisImporteServicios::IdMedico(const char *pchrPtrIdMedico)
{
	chrPtrIdMedico=pchrPtrIdMedico;
}
void QSisImporteServicios::IniciaControl()
{
	ConsultandoVentasMedico();
}
void QSisImporteServicios::IniciaInterfaz()
{
QVBoxLayout *lQVBLControles=new QVBoxLayout(this);

QLDetServicios=SiscomCreaEtiqueta(this,
				  "Detalle Servicios",
				  "QLDetServicios");
lQVBLControles->addWidget(QLDetServicios);
QTDatos=SiscomCreaTabla(this,
			"QTDatos",
			0,
			QStringList()	<< 
			"Clave"	      	<<
			"Descripcion"	<<
			"Cantidad"	<<
			"Importe");

lQVBLControles->addWidget(QTDatos);
lQVBLControles->addItem(SiscomCreaDisplayEtiqueta(
				this,
				"QLImporte",
				"Importe Total",
				"QLCDNTotal",
				8,
				&QLCDNTotal,
				&QLImporte));
}
void QSisImporteServicios::RangoFechas(const char *pchrPtrFechaIni,
				       const char *pchrPtrFechaFin)
{
	chrPtrFechaIni=pchrPtrFechaIni;
	chrPtrFechaFin=pchrPtrFechaFin;
}
void QSisImporteServicios::ConsultaVentasMedico()
{
CQSisOpCotizando lCQSOCotizando(SisDatCom);
	lCQSOCotizando.VentasTotalesMedico(
			chrPtrFechaIni,
			chrPtrFechaFin,
			chrPtrIdMedico,
			&CQSLCotizando);
}
void QSisImporteServicios::ConsultandoVentasMedico()
{
	ConsultaVentasMedico();
	MuestraVentasMedico();
}
void QSisImporteServicios::MuestraVentasMedico()
{
CQSisCotizando *lCQSCotizando;
int lintContador;
QTDatos->setNumRows(CQSLCotizando.count());
for(lintContador=0,
    lCQSCotizando=CQSLCotizando.first();
    lCQSCotizando;
    lintContador++,
    lCQSCotizando=CQSLCotizando.next())
SiscomAnexarRegistroALaTabla(
	lintContador,
	QTDatos,
	QStringList () <<
	(*lCQSCotizando)["Clave"] <<
	(*lCQSCotizando)["Descripcion"] <<
	(*lCQSCotizando)["Cantidad"] <<
	(*lCQSCotizando)["Importe"] );
SiscomAjustaColumnas(QTDatos);
SiscomAjustaFilas(QTDatos);
}


