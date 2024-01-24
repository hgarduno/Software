#include <IMP_RemisionFactura.h>
#include<SISCOMComunicaciones++.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qpushbutton.h>
QRemisionFactura::QRemisionFactura(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				RemisionFactura(pQWParent,
						pchrPtrName,
						pbModal,
						pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QRemisionFactura::~QRemisionFactura()
{

}

void QRemisionFactura::ConectaSlots()
{
connect(QLERemFactura,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoAceptar()));
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));
connect(QPBCancelar,
	SIGNAL(clicked()),
	SLOT(SlotCancelar()));
}
void QRemisionFactura::IniciaVariables()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLERemFactura);
}
void QRemisionFactura::SlotPasaFocoAceptar()
{
SiscomDesarrollo3Qt::PasaFocoControl(QPBAceptar);
}
void QRemisionFactura::SlotAceptar()
{
strcpy(chrArrNoRemFactura,
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLERemFactura));
	intOpcion=1;
	done(1);
}
void QRemisionFactura::SlotCancelar()
{
	intOpcion=0;
	done(0);
}
int QRemisionFactura::Opcion()
{
return intOpcion;

}
void QRemisionFactura::NoRemFactura(char *pchrPtrNoRemFactura)
{
strcpy(pchrPtrNoRemFactura,chrArrNoRemFactura);
}
