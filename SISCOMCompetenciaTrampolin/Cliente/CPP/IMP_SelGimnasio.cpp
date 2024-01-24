#include <IMP_SelGimnasio.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlGimnasios.h>
#include <qpushbutton.h>
#include <qmessagebox.h>

QSelGimnasio::QSelGimnasio(SiscomDatCom *pSisDatCom, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				SelGimnasio(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				CQSGimnasio(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QSelGimnasio::~QSelGimnasio()
{

}
void QSelGimnasio::closeEvent(QCloseEvent *)
{

}
void QSelGimnasio::ConectaSlots()
{

	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QCtrGimnasios,
		SIGNAL(SignalGimnasio(CQSisGimnasio *)),
		SLOT(SlotGimnasio(CQSisGimnasio *)));

}
void QSelGimnasio::SlotAceptar()
{
	if(CQSGimnasio)
	done(1);
	else
	QMessageBox::information(this,
				 "Aviso Del Sistema",
				 "No se ha seleccionado un gimnasio");
}
void QSelGimnasio::SlotCancelar()
{
	CQSGimnasio=0;
	done(1);
}
void QSelGimnasio::SlotGimnasio(CQSisGimnasio *pCQSGimnasio)
{
	CQSGimnasio=pCQSGimnasio;
}
void QSelGimnasio::IniciaVariables()
{
	QCtrGimnasios->PonServidor(SisDatCom);
	QCtrGimnasios->IniciaControl();
	QCtrGimnasios->setFocus();
}
CQSisGimnasio *QSelGimnasio::ObtenGimnasio()
{
	return CQSGimnasio;
}
