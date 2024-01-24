#include <IMP_SelExpendios.h>

#include <SISCOMComunicaciones++.h>
#include <EmpresasN.h>
#include <qvariant.h>
#include <qiconview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QSelExpendios::QSelExpendios(SiscomDatCom *pSisDatCom,
			     QWidget* parent,
			     const char* name,
			     bool modal,
			     WFlags fl )
    : SelExpendios( parent, name, modal, fl ),
      SisDatCom(pSisDatCom)

{
	ExpendiosDisponibles();
	ConectaSlots();
	exec();
}

QSelExpendios::~QSelExpendios()
{
}
void QSelExpendios::ExpendiosDisponibles()
{
ConsultaEmpresasN lCnsExpendios(SisDatCom,
				"Expendios",
				Expendios);
EmpresaN *lEmpresa;

	for(lEmpresa=Expendios.first();
	    lEmpresa;
	    lEmpresa=Expendios.next())
	  QIVExpendios->insertItem(new QIconVExpendio(lEmpresa,QIVExpendios));
}
void QSelExpendios::ConectaSlots()
{
	connect(QIVExpendios,
		SIGNAL(clicked(QIconViewItem *)),
		SLOT(S_SeleccionoExpendio(QIconViewItem *)));
	connect(QIVExpendios,
		SIGNAL(returnPressed(QIconViewItem *)),
		SLOT(S_SeleccionoExpendio(QIconViewItem *)));
}
void QSelExpendios::S_SeleccionoExpendio(QIconViewItem *pQIVExpendio)
{
	Expendio=((QIconVExpendio *)pQIVExpendio)->ObtenExpendio();
	done(1);
}
EmpresaN *QSelExpendios::ObtenExpendio()
{
	return Expendio;
}
QIconVExpendio::QIconVExpendio(EmpresaN *pEmpresa,
			       QIconView *pQiVExpendios):
			  QIconViewItem(pQiVExpendios),
			  Empresa(pEmpresa)
{
	setText(QString(Empresa->SRegistrosPro2["RazonSocial"]));
}
EmpresaN *QIconVExpendio::ObtenExpendio()
{
	return Empresa;
}
