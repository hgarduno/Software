#include <IMP_VentasExpendio.h>
#include <IMP_RangoFechas.h>
#include <CQSiscomCom.h>
#include <VentasExpendio.h>
#include <Empresas.h>

#include <qvariant.h>
#include <qtable.h>
#include <qlcdnumber.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qpushbutton.h>


QVentasExpendio::QVentasExpendio(CSISCOMDatComunicaciones *pCSisDatCom,
				 Empresa *pEmpresa,
				 QWidget* parent,
				 const char* name,
				 WFlags fl )
    : VentasExpendio( parent, name, fl ),
     CSisDatCom(pCSisDatCom),
     E_Empresa(pEmpresa)
{
	setCaption(QString("Reporte De Ventas:") +
			   E_Empresa->ObtenRazonSocial());
	ConectaSlots();
	show();
}

QVentasExpendio::~QVentasExpendio()
{
}
void QVentasExpendio::ConectaSlots()
{
	connect(QPBFechaReporte,
		SIGNAL(clicked()),
		SLOT(S_FechaReporte()));
}
void QVentasExpendio::S_FechaReporte()
{
QRangoFechas lQRFechas;

	if(lQRFechas.ObtenSeleccion()==QRangoFechas::Aceptar)
	{
		lQRFechas.ObtenRangoFechas(&chrPtrFechaIni,
					   &chrPtrFechaFin);
		CQVentasExpendio lCQVExpendio;
		CQCtrVentasExpendio lCQCtrVentasE(CSisDatCom,
						  QStringList() <<
						  "VentasExpendio" <<
						  "VentaExpendio" <<
						  E_Empresa->ObtenIdEmpresa() <<
						  chrPtrFechaIni <<
						  chrPtrFechaFin,
						  &lCQVExpendio);
		MuestraReporte(&lCQVExpendio);
				
						  
	}

}
void QVentasExpendio::MuestraReporte(CQVentasExpendio *pCQVExpendio)
{
VentaExpendio *lV_Expendio;
int lintContador;
	QTDatos->setNumRows(pCQVExpendio->count());
	for(lintContador=0,
		lV_Expendio=pCQVExpendio->first();
	    lV_Expendio;
	    lV_Expendio=pCQVExpendio->next(),
	    lintContador++)
	 SISCOMAnexarRegistroALaTabla(lintContador,
	 			QTDatos,
				QStringList () <<
				lV_Expendio->ObtenCveProducto() 	<<
				lV_Expendio->ObtenExistencia()   	<< 
				lV_Expendio->ObtenCantidad() 		<<
				lV_Expendio->ObtenPrecioProducto() 	<<
				lV_Expendio->ObtenImporte());
	QLCNImpTotal->display(pCQVExpendio->ObtenImporteVenta());
}
