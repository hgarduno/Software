#include <IMP_CtrExpendios.h>
#include <IMP_SelExpendios.h>
#include <SISCOMVentanaPrincipal3.h>
#include <SISCOMComunicaciones++.h>
#include <QEspacioExpendios.h>

#include <qvariant.h>
#include <qiconview.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qpushbutton.h>
QCtrExpendios *InstanciaCtrExpendios(void *pSisDatCom,
				     char **pchrPtrArgumentos,
				     void *pQWParent,
				     const char *pchrPtrName,
				     int pintWFlags)
{

	return new QCtrExpendios((SiscomDatCom *)pSisDatCom,
				 pchrPtrArgumentos,
				 (QWidget *)pQWParent,
				 pchrPtrName,
				 pintWFlags);
}
QCtrExpendios::QCtrExpendios(SiscomDatCom *pSisDatCom,
			     char **pchrPtrArgumentos,
				QWidget* parent,
				const char* name,
				WFlags fl )
    : CtrExpendios( parent, name, fl ),
    SisDatCom(pSisDatCom),
    chrPtrArgumentos(pchrPtrArgumentos),
    Expendio((EmpresaN *)chrPtrArgumentos[2]),
    SISCOMVenPrincipal((SISCOMVentanaPrincipal *)chrPtrArgumentos[3]),
    QWParent(parent)
{
	ExpendiosDisponibles();
	ConectaSlots();
}

QCtrExpendios::~QCtrExpendios()
{
}
void QCtrExpendios::ConectaSlots()
{
	connect(QIVExpendios,
		SIGNAL(doubleClicked(QIconViewItem *)),
		SLOT(S_SeleccionoExpendio(QIconViewItem *)));
	connect(QPBCEEActual,
		SIGNAL(clicked()),
		SLOT(S_CreaEspacioExpendioActual()));

}
void QCtrExpendios::S_CreaEspacioExpendioActual()
{

	SISCOMVenPrincipal->ObtenVentanasActivas(QWLVentanas);
	CreaEspacioExpendio();
}
void QCtrExpendios::S_SeleccionoExpendio(QIconViewItem *pQIVExpendio)
{
QIconVExpendio *lQIVExpendio=(QIconVExpendio *)pQIVExpendio;
	Expendio=lQIVExpendio->ObtenExpendio();
	chrPtrArgumentos[0]=(char *)Expendio->SRegistrosPro2["IdEmpresa"];
	chrPtrArgumentos[2]=(char *)Expendio;
	SISCOMVenPrincipal->ActualizaExpendio(Expendio);
	SISCOMVenPrincipal->ObtenVentanasActivas(QWLVentanas);
	CreaEspacioExpendio();

}
int QCtrExpendios::VerificaCreacionEspacio()
{
QWidget *lQWVentana;
	if(QWLVentanas.count()==1)
	{
	    lQWVentana=QWLVentanas.first();
	    return !strcmp(lQWVentana->className(),"QCtrExpendios");
	}
	else
	if(QWLVentanas.count()==2)
	{
	 int lintSi=0;
	 for(lQWVentana=QWLVentanas.first();
	     lQWVentana;
	     lQWVentana=QWLVentanas.next())
	  if(!strcmp(lQWVentana->className(),"QEspacioExpendios") ||
	     !strcmp(lQWVentana->className(),"QCtrExpendios"))
	     lintSi++;
	  return !lintSi==2;
	}
	else
	return QWLVentanas.count();

	

}
void QCtrExpendios::CreaEspacioExpendio()
{
/*
if(VerificaCreacionEspacio())
{
QWidget *lQWVentana;
QPoint lQPDonde(10,10);
	
	QEExpendios=new QEspacioExpendios(Expendio,QWParent,0,0);

	for(lQWVentana=QWLVentanas.first();
	    lQWVentana;
	    lQWVentana=QWLVentanas.next())
	{
	if(strcmp(lQWVentana->className(),"QCtrExpendios") &&
	   strcmp(lQWVentana->className(),"QEspacioExpendios"))
	  lQWVentana->reparent(QEExpendios->ObtenEspacioTrabajo(),
	  			lQPDonde,
				true);
	}
	  			
}

*/
}
void QCtrExpendios::ExpendiosDisponibles()
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
void QCtrExpendios::closeEvent(QCloseEvent *)
{
  emit SignalTerminar(this);
}
