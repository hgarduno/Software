#include <QCtrlEstadisticasSemanalesVentas.h>
#include <qtable.h>
#include <qheader.h>
#include <qlayout.h>
QCtrlEstadisticasSemanalesVentas::QCtrlEstadisticasSemanalesVentas(QWidget *pQWPtrParent,
								   const char *pchrPtrName):
						QWidget(pQWPtrParent,pchrPtrName)
{
IniciaVariables();

}
void QCtrlEstadisticasSemanalesVentas::IniciaControl()
{

}
void QCtrlEstadisticasSemanalesVentas::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlEstadisticasSemanalesVentas::IniciaVariables()
{
const char *lchrPtrCamposOrdenes[]={"Semana","Fecha Inicio","Fecha Fin","Escuela","Ordenes",0};
const char *lchrPtrCamposVentas[]={"Semana","Fecha Inicio","Fecha Fin","Escuela","Ventas",0};
QHBLayout=new QHBoxLayout(0,0,0,"QHBLayout");
//QVBLayout=new QVBoxLayout(this,0,"QVBLayout");
//QHBLayoutAA=new QHBoxLayout(0,0,"QHBLayoutAA");
QTOrdenes=FormaTabla("QTOrdenes",lchrPtrCamposOrdenes);
QTVentas=FormaTabla("QTVentas",lchrPtrCamposVentas);
QTOrdenesAA=FormaTabla("QTOrdenesAA",lchrPtrCamposOrdenes);
QTVentasAA=FormaTabla("QTVentasAA",lchrPtrCamposVentas);
QHBLayout->addWidget(QTOrdenes);
QHBLayout->addWidget(QTVentas);
/*
QHBLayoutAA->addWidget(QTOrdenesAA);
QHBLayoutAA->addWidget(QTVentasAA);
*/
QVBLayout->addLayout(QHBLayout);
//QVBLayout->addLayout(QHBLayoutAA);

}

QTable *QCtrlEstadisticasSemanalesVentas::FormaTabla(const char *pchrPtrName,
						     const char **pchrPtrCampos)
{
QTable *lQTPtrTabla;
int lintContador;
QHeader *lQHPtrTabla; 
lQTPtrTabla=new QTable(this,pchrPtrName);
lQTPtrTabla->setNumCols(5);
lQHPtrTabla=lQTPtrTabla->horizontalHeader();
for(lintContador=0;
    *(pchrPtrCampos+lintContador);
    lintContador++)
    lQHPtrTabla->setLabel(lintContador, *(pchrPtrCampos+lintContador) );
return lQTPtrTabla;
}

void QCtrlEstadisticasSemanalesVentas::Consulta()
{

}

void QCtrlEstadisticasSemanalesVentas::Consultando()
{
Consulta();
Muestra();
}
void QCtrlEstadisticasSemanalesVentas::Muestra()
{

}
