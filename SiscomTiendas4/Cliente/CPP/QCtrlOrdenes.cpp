#include <QCtrlOrdenes.h>
#include <SISCOMComunicaciones++.h>

#include <qlayout.h>

#include <CQSisEmpresas.h>
#include <CQSisOpTiendas4.h>
#include <CQSisClientes.h>
QCtrlOrdenes::QCtrlOrdenes( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlOrdenes::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QIVCompetencias=new QIconView(this);
	QHBLayout->addWidget(QIVCompetencias);
}
void QCtrlOrdenes::MuestraClases()
{

CQSisOrden *lCQSOrden;

	for(lCQSOrden=CQSLOrden.first();
	    lCQSOrden;
	    lCQSOrden=CQSLOrden.next())
	 QIVCompetencias->insertItem(new QIVItemOrden(lCQSOrden,QIVCompetencias));
	 QIVCompetencias->arrangeItemsInGrid();
}
void QCtrlOrdenes::IniciaControl()
{
	QIVCompetencias->clear();
	ConsultaClases();
	MuestraClases();
}
void QCtrlOrdenes::ConsultaClases()
{
CQSLOrden.clear();
CQSisOpTiendas4 lCQSOConsultas(SisDatCom);
		lCQSOConsultas.Ordenes(
			CQSExpendio,
			chrPtrFechaIni,
			chrPtrFechaFin,
			chrPtrEdoVenta,
			&CQSLOrden);
}
void QCtrlOrdenes::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlOrdenes::PonRangoFecha(const char *pchrPtrFechaIni,
				 const char *pchrPtrFechaFin)
{
   chrPtrFechaIni=pchrPtrFechaIni;
   chrPtrFechaFin=pchrPtrFechaFin;
}
void QCtrlOrdenes::PonExpendio(CQSisEmpresa *pCQSExpendio)
{
	CQSExpendio=pCQSExpendio;
}
void QCtrlOrdenes::PonEdoVenta(const char *pchrPtrEdoVenta)
{
   chrPtrEdoVenta=pchrPtrEdoVenta;
}
void QCtrlOrdenes::ConectaSlots()
{
	connect(QIVCompetencias,
		SIGNAL(clicked(QIconViewItem *)),
		SLOT(S_SeleccionoClase(QIconViewItem *)));
	connect(QIVCompetencias,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionoClase(QIconViewItem *)));
}
void QCtrlOrdenes::S_SeleccionoClase(QIconViewItem *pQIVGimnasio)
{
	if(pQIVGimnasio)
	 emit SignalOrden(((QIVItemOrden *)pQIVGimnasio)->ObtenOrden());
}
void QCtrlOrdenes::setFocus()
{
	
	QIVCompetencias->setFocus();
}
void QCtrlOrdenes::LimpiaSeleccion()
{
	QIVCompetencias->clearSelection();
}









QIVItemOrden::QIVItemOrden(CQSisOrden *pCQSOrden,
				QIconView *pQIVParent):
		QIconViewItem(pQIVParent),
		CQSOrden(pCQSOrden)

{
	IniciaVariables();
}
void QIVItemOrden::IniciaVariables()
{
QString lQSTexto;
	if(QString(CQSOrden->Cliente()->SRegistrosPro2["TipoCliente"])==
	   "Fisica")
	 lQSTexto=QString(CQSOrden->Cliente()->Persona()->SRegistrosPro2["Nombre"])+
	          " "								   +
		  CQSOrden->Cliente()->Persona()->SRegistrosPro2["APaterno"]	   +
		  "\n"								   +
		  "Importe:"							   +
		  CQSOrden->SRegistrosPro2["Importe"]				   +
		  "\n"								   +
		  "Orden:"							   +
		  CQSOrden->SRegistrosPro2["IdVenta"]                              +
		  "\n"								   +
		  "Hora:"							   +
		  (CQSOrden->SRegistrosPro2["Fecha"]+10);

	if(QString(CQSOrden->Cliente()->SRegistrosPro2["TipoCliente"])==
	   "Moral")
	  lQSTexto=QString(CQSOrden->Cliente()->Empresa()->SRegistrosPro2["RazonSocial"])+
	  "\n"								   		+
		  "Importe:"							   +
		  CQSOrden->SRegistrosPro2["Importe"]				   +
		  "\n"								   +
		  "Hora:"         						   +
		  (CQSOrden->SRegistrosPro2["Fecha"]+10);

	  
	  ;

	setText(lQSTexto);
}
CQSisOrden *QIVItemOrden::ObtenOrden()
{
	return CQSOrden;
}
