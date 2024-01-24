#include <IMP_Facturas.h>
#include <IMP_CapturaRangoFechas.h>
#include <IMP_BuscaProveedor.h>
#include <IMP_CapturaNumFactura.h>
#include <IMP_AnexarFactura.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSisFacturas.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qapplication.h>
#include <qclipboard.h>


#include <SiscomOperaciones3.h>
QFacturas *InstanciaFacturas(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QFacturas((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QFacturas::QFacturas(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Facturas(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				SisReg3Proveedor(0)
{
IniciaVariables();
ConectaSlots();
}

QFacturas::~QFacturas()
{

}

void QFacturas::ConectaSlots()
{

	connect(QPBRangoFechas,
		SIGNAL(clicked()),
		SLOT(SlotRangoFechas()));
	connect(QPBADatos,
		SIGNAL(clicked()),
		SLOT(SlotActualiza()));
	connect(QPBFProveedor,
		SIGNAL(clicked()),
		SLOT(SlotFiltroProveedor()));
	connect(QTFacturas,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(SlotSeleccionandoFactura(int,int,int,const QPoint &)));
	connect(QPBANumFactura,
		SIGNAL(clicked()),
		SLOT(SlotActualizaNumFactura()));
	connect(QPBCopiar,
		SIGNAL(clicked()),
		SLOT(SlotCopiar()));
	connect(QPBAnexarFactura,
		SIGNAL(clicked()),
		SLOT(SlotAnexarFactura()));
	connect(QPBAContabilidad,
		SIGNAL(clicked()),
		SLOT(SlotAnexarFacturasPeriodoContable()));
	connect(QTFacturas,
		SIGNAL(currentChanged(int,int)),
		SLOT(SlotCambiandoFactura(int,int)));

}
void QFacturas::SlotCambiandoFactura(int pintNFactura,
				     int)
{
	SisReg3Factura=SisReg3LstFacturas[pintNFactura];
	ConsultandoDetalleFactura();
}
void QFacturas::SlotAnexarFacturasPeriodoContable()
{
CQSisFacturando lCQSFacturando(SisDatCom);
lCQSFacturando.AnexaFacturasContabilidad(&SisReg3LstFacturas);

}
void QFacturas::SlotAnexarFactura()
{
QAnexarFactura lQAFactura(SisDatCom,chrPtrArgumentos);
if(lQAFactura.Opcion())
{
	SisReg3LstFacturas << lQAFactura.Factura();
	SisReg3Factura=SisReg3LstFacturas[0];
	MuestraFacturas();
	ConsultandoDetalleFactura();
	SiscomDesarrollo3Qt::PasaFocoControl(QPBAnexarFactura);
}
}
void QFacturas::SlotCopiar()
{
int lintContador;
SiscomRegistro3 *lSisReg3Factura;
SiscomRegistro3Lst lSisReg3LstCopiar;
char lchrArrBuffer[8192];
for(lintContador=0;
    lintContador<QTFacturas->numRows();
    lintContador++)
 if(QTFacturas->isRowSelected(lintContador))
     lSisReg3LstCopiar << SisReg3LstFacturas[lintContador];
SiscomOperaciones3 lSisOp3Prueba;
	lSisOp3Prueba.SiscomCopiaProtocoloCadena("Pruebas",	
					   &lSisReg3LstCopiar,
					   lchrArrBuffer);
   QApplication::clipboard()->setText(lchrArrBuffer);

}
void QFacturas::SlotActualizaNumFactura()
{
QCapturaNumFactura lQCapNFactura(SisReg3Factura,
				SisDatCom,
				 chrPtrArgumentos);
}
void QFacturas::SlotSeleccionandoFactura(int pintNFactura,
					 int,
					 int,
					 const QPoint &)
{
	QTFacturas->selectRow(pintNFactura);
	SisReg3Factura=SisReg3LstFacturas[pintNFactura];
	ConsultandoDetalleFactura();
}
void QFacturas::SlotFiltroProveedor()
{
QBuscaProveedor lQBProveedor(SisDatCom,
			     chrPtrArgumentos);
if(lQBProveedor.Opcion())
{
SisReg3Proveedor=lQBProveedor.Proveedor();
QPBFProveedor->setText((*SisReg3Proveedor)["razonsocial"]);
}
}
void QFacturas::SlotActualiza()
{
ConsultandoFacturas();
}
void QFacturas::SlotRangoFechas()
{
QCapturaRangoFechas lQCRangoFechas;
if(lQCRangoFechas.ObtenOpcion())
{
   lQCRangoFechas.ObtenRangoFechas(chrArrFechaIni,
   				   chrArrFechaFin);

  ConsultandoFacturas();
}
}
void QFacturas::IniciaVariables()
{

}

void QFacturas::ConsultandoFacturas()
{
	ConsultaFacturas();
	MuestraFacturas();
}
void QFacturas::ConsultaFacturas()
{
CQSisFacturando lCQSFacturando(SisDatCom);
SisReg3LstFacturas.clear();
lCQSFacturando.Facturas(chrPtrArgumentos[0],
			chrArrFechaIni,
			chrArrFechaFin,
			SisReg3Proveedor ? (*SisReg3Proveedor)["idempresa"]:"",
			&SisReg3LstFacturas);
}
void QFacturas::MuestraFacturas()
{
const char *lchrArrCampos[]={"numfactura",
		       "fecha",
		       "razonsocial",
		       0
		      };
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrArrCampos,
				       QTFacturas,
				       &SisReg3LstFacturas);
SiscomDesarrollo3Qt::AjustaColumnas(QTFacturas);
}

void QFacturas::ConsultandoDetalleFactura()
{
ConsultaDetalleFactura();
MuestraDetalleFactura();
}

void QFacturas::ConsultaDetalleFactura()
{
CQSisFacturando lCQSFacturando(SisDatCom);
SisReg3LstDFactura.clear();
lCQSFacturando.DetalleFactura(chrPtrArgumentos[0],
			      (*SisReg3Factura)["numfactura"],
			      (*SisReg3Factura)["fecha"],
			      &SisReg3LstDFactura);
}
void QFacturas::MuestraDetalleFactura()
{
const char *lchrArrCampos[]={"cveproducto",
		       "precio",
		       "cantidad",
		       0
		       };
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrArrCampos,
				       QTDFactura,
				       &SisReg3LstDFactura);
SiscomDesarrollo3Qt::AjustaColumnas(QTDFactura);
}
void QFacturas::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
