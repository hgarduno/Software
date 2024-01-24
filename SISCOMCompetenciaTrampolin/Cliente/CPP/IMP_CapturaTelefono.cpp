#include <IMP_CapturaTelefono.h>

#include <CQSisEntrenadores.h>
#include <CQSisOperaciones.h>
#include<SISCOMComunicaciones++.h>


#include <qpushbutton.h>
#include <qlineedit.h>
QCapturaTelefono::QCapturaTelefono(SiscomDatCom *pSisDatCom, 
				   CQSisEntrenador *pCQSEPersona,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaTelefono(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				CQSEPersona(pCQSEPersona),
				intSeAnexo(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaTelefono::~QCapturaTelefono()
{

}
int QCapturaTelefono::SeAnexo()
{
	return intSeAnexo;
}
void QCapturaTelefono::ConectaSlots()
{
	SiscomPasaFocoControl(QLETelefono);
	connect(QLETelefono,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoDescripcion()));
	connect(QLEDescripcion,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAnexar()));
	connect(QPBAnexar,
		SIGNAL(clicked()),
		SLOT(SlotAnexar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
}
void QCapturaTelefono::SlotCancelar()
{
	done(1);
}
void QCapturaTelefono::SlotAnexar()
{
CQSisOperaciones lCQSOATelefono(SisDatCom);
	lCQSOATelefono.AnexaMedio(CQSEPersona,
				   "Telefono",
				   SiscomObtenInformacionDelEdit(QLETelefono),
				   SiscomObtenInformacionDelEdit(QLEDescripcion));
	intSeAnexo=1;
	done(1);
}
void QCapturaTelefono::SlotPasaFocoAnexar()
{
	SiscomPasaFocoControl(QPBAnexar);
}
void QCapturaTelefono::SlotPasaFocoDescripcion()
{
	SiscomPasaFocoControl(QLEDescripcion);
}
void QCapturaTelefono::IniciaVariables()
{

}

void QCapturaTelefono::closeEvent(QCloseEvent *)
{

}
