#include <IMP_OrdenServicio.h>
#include <IMP_ResponsableVehiculo.h>
#include <IMP_CapturaPropietario.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlFechaHora.h>

QOrdenServicio *InstanciaOrdenServicio(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QOrdenServicio((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QOrdenServicio::QOrdenServicio(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				OrdenServicio(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QOrdenServicio::~QOrdenServicio()
{

}

void QOrdenServicio::ConectaSlots()
{

	connect(QPBPropietario,
		SIGNAL(clicked()),
		SLOT(SlotCapturaPropietario()));
	connect(QPBCEVehiculo,
		SIGNAL(clicked()),
		SLOT(SlotCapturaNombreEncargadoEntregaVehiculo()));

}
void QOrdenServicio::SlotCapturaPropietario()
{
char lchrArrPropietario[256];
QCapturaPropietario lQCPropietario(SisDatCom,
				   chrPtrArgumentos);

lQCPropietario.Propietario(lchrArrPropietario);
QLEPropietario->setText(lchrArrPropietario);
lQCPropietario.Direcciones(&CQSLDirecciones);
lQCPropietario.Telefonos(&SLMCom);
MuestraDireccionesPropietario();
MuestraTelefonos();
}
void QOrdenServicio::SlotCapturaNombreEncargadoEntregaVehiculo()
{
char lchrArrNombre[128];
char lchrArrCargo[128];
QResponsableVehiculo lQRVehiculo(SisDatCom,
				 chrPtrArgumentos);
lQRVehiculo.NombreCompleto(lchrArrNombre);
lQRVehiculo.Cargo(lchrArrCargo);
QLEResponsableCargo->setText(QString(lchrArrNombre)	+
			     " "			+
			     "("			+
			     lchrArrCargo		+
			     ")");
}
void QOrdenServicio::IniciaVariables()
{
	CtrFHRecepcion->ColocaFechaHoy();
	CtrFHEntrega->ColocaFechaHoy();
}
void QOrdenServicio::Direccion(CQSisDireccion *pCQSisDireccion,
			       char *pchrPtrDireccion)
{

sprintf(pchrPtrDireccion,
	"%s %s %s",
	(*pCQSisDireccion)["Calle"],
	(*pCQSisDireccion)["Numero"],
	(*pCQSisDireccion)["Estado"]);
}
void QOrdenServicio::MuestraDireccionesPropietario()
{
CQSisDireccion *lCQSDireccion;
char lchrArrDireccion[1024];
int lintContador=0;

QTDirecciones->setNumRows(CQSLDirecciones.count());
for(lCQSDireccion=CQSLDirecciones.first();
    lCQSDireccion;
    lCQSDireccion=CQSLDirecciones.next(),
    lintContador++)
{
Direccion(lCQSDireccion,lchrArrDireccion);
QTDirecciones->setText(lintContador,0,lchrArrDireccion);
}


}

void QOrdenServicio::Telefono(SisMedCom *pSMedCom,
			      char *pchrPtrTelefono)
{
sprintf(pchrPtrTelefono,
	"%s %s",
	(*pSMedCom)["Dato"],
	(*pSMedCom)["Descripcion"]);

}

void QOrdenServicio::MuestraTelefonos()
{
SisMedCom *lSMCom;
int lintContador;
char lchrArrTelefono[256];
QTTelefonos->setNumRows(SLMCom.count());

for(lSMCom=SLMCom.first(),
    lintContador=0;
    lSMCom;
    lSMCom=SLMCom.next(),
    lintContador++)
{
Telefono(lSMCom,lchrArrTelefono);
QTTelefonos->setText(lintContador,0,lchrArrTelefono);
}
}

void QOrdenServicio::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
