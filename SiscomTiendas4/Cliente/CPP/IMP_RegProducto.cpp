#include <IMP_RegProducto.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlFamilias.h>
#include <CQSisFamilias.h>
#include <CQSisOpTiendas4.h>
#include <CQSisProductos.h>

#include <qpushbutton.h>
#include <qmessagebox.h>
QRegProducto *InstanciaRegProducto(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRegProducto((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRegProducto::QRegProducto(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RegProducto(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				CQSFamilia(0)
{
IniciaVariables();
ConectaSlots();
}

QRegProducto::~QRegProducto()
{

}

void QRegProducto::ConectaSlots()
{

	connect(QCtrFamilias,
		SIGNAL(SignalFamilia(CQSisFamilia *)),
		SLOT(SlotFamilia(CQSisFamilia *)));
	connect(QCtrFamilias,
		SIGNAL(SignalCambiandoFamilia()),
		SLOT(SlotCambiandoFamilia()));
	connect(QPBRegistra,
		SIGNAL(clicked()),
		SLOT(SlotRegistrar()));
	connect(QLEClave,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoDescripcion()));
	connect(QLEClave,
		SIGNAL(textChanged(const QString &)),
		SLOT(SlotCambiandoClave(const QString &)));
	connect(QTEDsc,
		SIGNAL(textChanged()),
		SLOT(SlotCapturandoDsc()));
}
void QRegProducto::SlotCambiandoClave(const QString &pQSClave)
{
int lintNCaracteres=pQSClave.length();
QPBRegistra->setEnabled(lintNCaracteres &&
			QTEDsc->text().length());
QTEDsc->setEnabled(lintNCaracteres);
}
void QRegProducto::SlotCapturandoDsc()
{
QPBRegistra->setEnabled(QLEClave->text().length() &&
			QTEDsc->text().length());
}
void QRegProducto::SlotCambiandoFamilia()
{
  QPBRegistra->setEnabled(false);
}
void QRegProducto::SlotPasaFocoDescripcion()
{
	SiscomPasaFocoControl(QTEDsc);
}
void QRegProducto::SlotRegistrar()
{
   RegistraProducto();
   QCtrFamilias->setFocus();
   QPBRegistra->setEnabled(false);
   QLEClave->setEnabled(false);
   QTEDsc->setEnabled(false);
}
void QRegProducto::RegistraProducto()
{
CQSisProducto *lCQSProducto=GeneraProducto();
CQSisOpTiendas4 lCQSOT4RProducto(SisDatCom);
	lCQSOT4RProducto.AnexaProducto(lCQSProducto);
}
void QRegProducto::IniciaVariables()
{
	QCtrFamilias->PonServidor(SisDatCom);
	QCtrFamilias->IniciaControl();
	QCtrFamilias->setFocus();
}
void QRegProducto::SlotFamilia(CQSisFamilia *pCQSFamilia)
{
	if(pCQSFamilia)
	{
	CQSFamilia=pCQSFamilia;
	QLEClave->setEnabled(CQSFamilia);
	SiscomPasaFocoControl(QLEClave);
	}
	else
	{
	  QMessageBox::information(
	  		this,
			"Siscom",
			"No se han registrado familias");
	}

}
CQSisProducto *QRegProducto::GeneraProducto()
{
	return new CQSisProducto(
		CQSFamilia,
		"",
		SiscomObtenInformacionDelEdit(QLEClave),
		SiscomObtenInformacionDelEdit(QTEDsc));
}

void QRegProducto::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
