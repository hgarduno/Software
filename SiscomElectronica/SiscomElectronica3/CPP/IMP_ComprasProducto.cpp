#include <IMP_ComprasProducto.h>
#include <IMP_RangoPorcentajes3.h>
#include <IMP_QControlFecha.h> 
#include <CQSis3QtOperaciones.h>

#include <QCtrlProdSiscomElectronica.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomRegistros3.h>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qlineedit.h>
#include <qmessagebox.h>
QComprasProducto *InstanciaComprasProducto(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QComprasProducto((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QComprasProducto::QComprasProducto(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ComprasProducto(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QComprasProducto::~QComprasProducto()
{

}

void QComprasProducto::ConectaSlots()
{
    connect(QCtrSis3QtProds,
    	    SIGNAL(SignalSeleccionando(SiscomRegistro3 *)),
	    SLOT(SlotSeleccionando(SiscomRegistro3 *)));
    connect(QCtrSis3QtProds,
    	    SIGNAL(SignalSelecciono(SiscomRegistro3 *)),
	    SLOT(SlotSelecciono(SiscomRegistro3 *)));
    connect(QPBHCompras,
    	    SIGNAL(clicked()),
	    SLOT(SlotHistorico()));
    connect(QPBRPorcentajes,
    	    SIGNAL(clicked()),
	    SLOT(SlotPorcentajes()));
}
void QComprasProducto::SlotPorcentajes()
{
QRangoPorcentajes3 lQRPorcentajes;

	if(lQRPorcentajes.OpcionSeleccionada(
				chrArrPEMBajo,
				chrArrPEMAlto))
	{
	 	ConsultaPorExistenciaMinima();
		Muestra();
	}
	else
	{

	}
}
void QComprasProducto::SlotHistorico()
{
	Consultando();
}
void QComprasProducto::SlotSelecciono(SiscomRegistro3 *pSRegistro3)
{
	if(pSRegistro3)
	{
	SRegistro3Prod=pSRegistro3;
	QPBHCompras->setFocus();
	}
}
void QComprasProducto::SlotSeleccionando(SiscomRegistro3 *pSRegistro3)
{
	QTEDescripcion->setText((*pSRegistro3)["dscproducto"]);
}
void QComprasProducto::IniciaVariables()
{
QCtrSis3QtProds->Servidor(SisDatCom);
QCtrSis3QtProds->IdExpendio(chrPtrArgumentos[0]);
QCtrSis3QtProds->IniciaControl();
SiscomDesarrollo3Qt::PasaFocoControl(QCtrSis3QtProds->QLineEditProducto());
QCtrFechaRefVentas->ColocaFechaHoy();
}
void QComprasProducto::Consulta()
{
CQSis3QtOperaciones lCQS3QtHistorico(SisDatCom);
SRegistro3LstHistorico.clear();
lCQS3QtHistorico.HistoricoCompras(
			(*SRegistro3Prod)["cveproducto"],
			chrPtrArgumentos[0],
			(const char *)QCtrFechaRefVentas->ObtenFecha(),
			&SRegistro3LstHistorico);
}
void QComprasProducto::ConsultaPorExistenciaMinima()
{
CQSis3QtOperaciones lCQS3QtHistorico(SisDatCom);
SRegistro3LstHistorico.clear();
lCQS3QtHistorico.HistoricoCompras(
			chrArrPEMBajo,
			chrArrPEMAlto,
			chrPtrArgumentos[0],
			(const char *)QCtrFechaRefVentas->ObtenFecha(),
			&SRegistro3LstHistorico);

}
void QComprasProducto::Muestra()
{
const char *lchrArrCamposM[]={"cveproducto",
			"fecha",
			"hora",
			"preciocompra",
			"cantidad",
			"numfactura",
			"precioventa",
			"proveedor",
			0
			};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrArrCamposM,
				       QTDatos,
				       &SRegistro3LstHistorico);
SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
MuestraComprasVentas();
}
void QComprasProducto::InformaNoHayCompras()
{
QMessageBox::information(this,"Aviso del Sistema","NO Hay Compras del producto");

}
void QComprasProducto::MuestraComprasVentas()
{
SiscomRegistro3 *lSRegistro3=SRegistro3LstHistorico[0];
if(lSRegistro3) 
{
QLEComprasSemAnterior->setText((*lSRegistro3)["comprassemanterior"]);
QTEVentasSemAnterior->setText((*lSRegistro3)["ventastotalessemanterior"]);
QLEVentasActuales->setText((*lSRegistro3)["cantidadvendidaactual"]);
QLEExistenciaA->setText((*lSRegistro3)["existencia"]);
}
else
InformaNoHayCompras();

}
void QComprasProducto::Consultando()
{
	Consulta();
	Muestra();
}
void QComprasProducto::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
