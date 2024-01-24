#include <IMP_OrdenesAFacturar.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSis3QtOperaciones.h>
#include <CQSisProductosE3Qt.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlcdnumber.h>
#include <qtable.h>
QOrdenesAFacturar::QOrdenesAFacturar(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				OrdenesAFacturar(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
//CargaOrdenesEntradaEstandar();
IniciaVariables();
ConectaSlots();
//exec();
}

QOrdenesAFacturar::~QOrdenesAFacturar()
{

}
void QOrdenesAFacturar::IniciaVariables()
{
}
void QOrdenesAFacturar::ConectaSlots()
{
connect(QLEOrden,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoAnexarOrden()));
connect(QPBAnexarO,
	SIGNAL(clicked()),
	SLOT(SlotAnexaOrden()));
connect(QTOrdenes,
	SIGNAL(clicked(int,int,int,const QPoint &)),
	SLOT(SlotProductosOrden(int,int,int,const QPoint &)));
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));
}
void QOrdenesAFacturar::SlotAceptar()
{
 done(1);
}
void QOrdenesAFacturar::SlotProductosOrden(int pintFila,
					  int pintColumna,
					  int,
					  const QPoint &)
{
CQSisOrdenesElectronica lCQSisOElectronica(SisDatCom);
SisReg3LstProdOrden.clear();
lCQSisOElectronica.ProductosOrden(
	chrPtrArgumentos[0],
	(*SisReg3LstOrdenes[pintFila])["NoOrden"],
	&SisReg3LstProdOrden);
MuestraOrdenPorNoOrden();
}
void QOrdenesAFacturar::SlotPasaFocoAnexarOrden()
{
SiscomDesarrollo3Qt::PasaFocoControl(QPBAnexarO);
}
void QOrdenesAFacturar::SlotAnexaOrden()
{
  	AgregaOrden(CreaRegistroOrden());
	EnviaOrdenes();
	Muestra();
	MuestraTotales();
	MuestraOrdenes();
	MuestraOrden();
}
SiscomRegistro3 *QOrdenesAFacturar::CreaRegistroOrden()
{
SiscomRegistro3 *lSisReg3Orden=new SiscomRegistro3;
(*lSisReg3Orden) 								<<
new SiscomCampo3("NoOrden",
		 SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEOrden)) 	<<
new SiscomCampo3("IdExpendio",chrPtrArgumentos[0])				<<
new SiscomCampo3("OrdenActual","");
return lSisReg3Orden;
}


SiscomRegistro3 *QOrdenesAFacturar::CreaRegistroOrden(const char *pchrPtrIdOrden)
{
SiscomRegistro3 *lSisReg3Orden=new SiscomRegistro3;
(*lSisReg3Orden) 								<<
new SiscomCampo3("NoOrden",
		 pchrPtrIdOrden) 	<<
new SiscomCampo3("IdExpendio",chrPtrArgumentos[0])				<<
new SiscomCampo3("OrdenActual","");
return lSisReg3Orden;
}
void QOrdenesAFacturar::EnviaOrdenes()
{
CQSis3QtOperaciones lCQSis3QtOp(SisDatCom);
SisReg3LstProdAFacturar.clear();
SisReg3LstProdOrden.clear();
ColocaOrdenActual();
lCQSis3QtOp.OrdenesParaFacturar(&SisReg3LstOrdenes,
			     &SisReg3LstProdAFacturar,
			     &SisReg3LstProdOrden);
}
void QOrdenesAFacturar::AgregaOrden(SiscomRegistro3 *pSisReg3Orden)
{
    SisReg3LstOrdenes << pSisReg3Orden;
}
void QOrdenesAFacturar::Muestra()
{
const char *lchrPtrCampos[]={"cveproducto",
		       "CantidadTotal",
		       "precio",
		       "ImporteTotal",
		       0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
				       QTDatos,
				       &SisReg3LstProdAFacturar);
}
void QOrdenesAFacturar::MuestraOrden()
{
const char *lchrPtrCampos[]={"cveproducto",
		       "cantidad",
		       "precio",
		       "importe",
		       0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
				       QTProdOrden,
				       &SisReg3LstProdOrden);
}
void QOrdenesAFacturar::MuestraOrdenPorNoOrden()
{
const char *lchrPtrCampos[]={"CveProducto",
		       "Cantidad",
		       "Precio",
		       "ImporteCantidad",
		       0
		       };

QTProdOrden->setNumRows(0);
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
				       QTProdOrden,
				       &SisReg3LstProdOrden);
}
void QOrdenesAFacturar::MuestraTotales()
{
SiscomRegistro3 *lSisReg3Total=SisReg3LstProdAFacturar[0];

QLCNTotal->display((*lSisReg3Total)["Total"]);
QLCNIVA->display((*lSisReg3Total)["IVA"]);
QLCDNTotalMIVA->display((*lSisReg3Total)["TotalMIVA"]);
}
void QOrdenesAFacturar::MuestraOrdenes()
{
const char *lchrPtrCampos[]={"NoOrden",0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
					QTOrdenes,
					&SisReg3LstOrdenes);
}
void QOrdenesAFacturar::ColocaOrdenActual()
{
SiscomRegistro3 *lSisReg3Dato;
lSisReg3Dato=SisReg3LstOrdenes[0];
lSisReg3Dato->SiscomActualizaCampo(
		"OrdenActual",
		SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEOrden));
			
}

void QOrdenesAFacturar::ObtenFacturacion(SiscomRegistro3Lst *pSisReg3LstProdAFacturar)
{
 *pSisReg3LstProdAFacturar=SisReg3LstProdAFacturar;
}
void QOrdenesAFacturar::PonOrdenes(SiscomRegistro3Lst *pSisReg3LstOrdenes)
{
 SisReg3LstOrdenes=*pSisReg3LstOrdenes;
}
void QOrdenesAFacturar::ObtenOrdenes(SiscomRegistro3Lst *pSisReg3LstOrdenes)
{
  *pSisReg3LstOrdenes=SisReg3LstOrdenes;
}
void QOrdenesAFacturar::ConsultandoOrdenesAFacturar()
{
	EnviaOrdenes();
	Muestra();
	MuestraTotales();
	MuestraOrdenes();
	MuestraOrden();
}

void QOrdenesAFacturar::CargaOrdenesEntradaEstandar()
{
char lchrArrLinea[128];
   while(!SiscomDesarrollo3Qt::LeeLinea(stdin,lchrArrLinea))
   {
   	if(lchrArrLinea[0]!='#')
	{
	SiscomEscribeLog3Qt("%s",lchrArrLinea);
	SisReg3LstOrdenes << CreaRegistroOrden(lchrArrLinea);
	}
   }
  ConsultandoOrdenesAFacturar();
}
