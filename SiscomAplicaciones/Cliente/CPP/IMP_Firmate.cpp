#include <IMP_Firmate.h>
#include<SISCOMComunicaciones++.h>
#include <Seguridad3Protocolo2.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qmessagebox.h>
QFirmate::QFirmate(SiscomDatCom *pSisDatCom, 
		   SisUsuarioSeg3 *pSUsuarioSeg3,
		   QWidget *pQWParent,       
		   const char *pchrPtrName,
		   bool pbModal,
		   WFlags pWFlags):	      
		Firmate(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				SUsuarioSeg3(pSUsuarioSeg3),
		intValidacionPassword(0),
		intIntentos(0)
{
IniciaVariables();
ConectaSlots();
MuestraUsuario();
exec();
}

QFirmate::~QFirmate()
{

}

void QFirmate::ConectaSlots()
{
	connect(QLEPassword,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAceptar()));
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotValidaFirma()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
		

}
void QFirmate::SlotCancelar()
{
intValidacionPassword=0;
done(1);
}
void QFirmate::SlotValidaFirma()
{
	ValidaFirma();
}
void QFirmate::SlotPasaFocoAceptar()
{
	SiscomPasaFocoControl(QPBAceptar);
}
void QFirmate::IniciaVariables()
{
	SiscomPasaFocoControl(QLEPassword);
}


void QFirmate::MuestraUsuario()
{
QLEFirma->setText(SUsuarioSeg3->SRegistrosPro2["Firma"]);
}
void QFirmate::closeEvent(QCloseEvent *)
{

}
void QFirmate::ValidaFirma()
{
OpUsuariosSeg3 lOUsuariosSeg3(SisDatCom);
	if((intValidacionPassword=lOUsuariosSeg3.ValidaFirmaAlSistema(
		SUsuarioSeg3->SRegistrosPro2["Firma"],
		SiscomObtenInformacionDelEdit(QLEPassword))))
	 done(1);
	 else
	 {
	 QMessageBox::information(
	 	this,
		"Siscom Tiendas4",
		"Password Incorrecto");
	intIntentos++;
	SiscomPasaFocoControl(QLEPassword);
	if(intIntentos>2)
	exit(0);
	}
}
int QFirmate::ValidacionPassword()
{
	return intValidacionPassword;
}
