#include <IMP_CapturaDenominacion.h>
#include<SISCOMComunicaciones++.h>
#include <SiscomDesarrollo3Qt++.h>
QCapturaDenominacion::QCapturaDenominacion(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaDenominacion(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaDenominacion::~QCapturaDenominacion()
{

}

void QCapturaDenominacion::ConectaSlots()
{
	connect(QPBAceptar,
		SIGNAL(clicked()),
		SLOT(SlotAceptar()));
	connect(QPBCancelar,
		SIGNAL(clicked()),
		SLOT(SlotCancelar()));
	connect(QLEDenominacion,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoCantidad()));
	connect(QLECantidad,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAceptar()));

}
void QCapturaDenominacion::SlotPasaFocoCantidad()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QLECantidad);
}
void QCapturaDenominacion::SlotPasaFocoAceptar()
{
	SiscomDesarrollo3Qt::PasaFocoControl(QPBAceptar);
}
void QCapturaDenominacion::SlotAceptar()
{
	intOpcion=1;
	done(1);
}
void QCapturaDenominacion::SlotCancelar()
{
	intOpcion=0;
	done(1);
}
int QCapturaDenominacion::Opcion()
{
	return intOpcion;
}
void QCapturaDenominacion::DatosDenominacion(char *pchrPtrDenominacion,
					     char *pchrPtrCantidad)
{
strcpy(pchrPtrDenominacion,(const char *)QLEDenominacion->text());
strcpy(pchrPtrCantidad,(const char *)QLECantidad->text());
}
void QCapturaDenominacion::IniciaVariables()
{

}
