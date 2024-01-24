
#include <QCtrlPersonas.h>
#include <SISCOMComunicaciones++.h>
#include <CQSisPersonas.h>
#include <qlayout.h>


QCtrlPersonas::QCtrlPersonas( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlPersonas::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QIVPersonas=new QIconView(this);
	QHBLayout->addWidget(QIVPersonas);
}
void QCtrlPersonas::MuestraPersonas()
{
CQSisPersona *lCQSPersona;
for(lCQSPersona=CQSLPersona.first();
    lCQSPersona;
    lCQSPersona=CQSLPersona.next())
  QIVPersonas->insertItem(new QIVItemPersona(lCQSPersona,QIVPersonas)); 
}
void QCtrlPersonas::setFocus()
{
  QIVPersonas->setFocus();
  QIVPersonas->setSelected(QIVPersonas->firstItem(),true);
}
void QCtrlPersonas::IniciaControl()
{
	QIVPersonas->clear();
	ConsultaPersonas();
	MuestraPersonas();
}
void QCtrlPersonas::ConsultaPersonas()
{
CQSisOpPersona lCQSOPersona(SisDatCom);
lCQSOPersona.Empleados(chrPtrNmbPerfil,&CQSLPersona);
}
void QCtrlPersonas::NombrePerfil(const char *pchrPtrNmbPerfil)
{
	chrPtrNmbPerfil=pchrPtrNmbPerfil;
}
void QCtrlPersonas::PonServidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}

void QCtrlPersonas::ConectaSlots()
{
	connect(QIVPersonas,
		SIGNAL(clicked(QIconViewItem *)),
		SLOT(S_SeleccionoPersona(QIconViewItem *)));
	connect(QIVPersonas,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionoPersona(QIconViewItem *)));
}
void QCtrlPersonas::S_SeleccionoPersona(QIconViewItem *pQIVPersona)
{

	if(pQIVPersona)
	 emit SignalPersona(((QIVItemPersona*)pQIVPersona)->ObtenPersona());

}

void QCtrlPersonas::LimpiaSeleccion()
{
	QIVPersonas->clearSelection();
}
void QCtrlPersonas::Limpia()
{
	QIVPersonas->clear();
}








QIVItemPersona::QIVItemPersona(
		    CQSisPersona *pCQSPersona,
				QIconView *pQIVParent):
		QIconViewItem(pQIVParent),
		CQSPersona(pCQSPersona)

{
	IniciaVariables();
}
void QIVItemPersona::IniciaVariables()
{
QString lQSTexto;
	lQSTexto=QString(CQSPersona->SRegistrosPro2["Nombre"]) 	+
		 " "					       	+
		 CQSPersona->SRegistrosPro2["APaterno"]		+	
		 " "						+
		 CQSPersona->SRegistrosPro2["AMaterno"];
	setText(lQSTexto);	
}
CQSisPersona *QIVItemPersona::ObtenPersona()
{
	return CQSPersona;
}


