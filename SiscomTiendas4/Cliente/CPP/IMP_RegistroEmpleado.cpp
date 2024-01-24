#include <IMP_RegistroEmpleado.h>
#include<SISCOMComunicaciones++.h>
#include <SiscomDesarrollo3Qt++.h>
#include <QCtrlPerfiles.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <CQSisOpTiendas4.h>
#include <CQSisEmpleados.h>
#include <Seguridad3Protocolo2.h>
QRegistroEmpleado *InstanciaRegistroEmpleado(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRegistroEmpleado((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRegistroEmpleado::QRegistroEmpleado(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RegistroEmpleado(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QRegistroEmpleado::~QRegistroEmpleado()
{

}

void QRegistroEmpleado::ConectaSlots()
{
	connect(QCtrPerfiles,
		SIGNAL(SignalPerfil(PerfilSeguridadProt2 *)),
		SLOT(SlotPerfil(PerfilSeguridadProt2 *)));
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoFirma()));
	connect(QLEFirma,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoPassword()));
	connect(QLEPassword,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoRePassword()));
	connect(QLENPassword,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoRegistra()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));
}
void QRegistroEmpleado::SlotPerfil(PerfilSeguridadProt2 *pPSeguridad)
{
	PSeguridad=pPSeguridad;
	SiscomPasaFocoControl(QLENombre);
}
void QRegistroEmpleado::SlotRegistra()
{
	Registra();
}
void QRegistroEmpleado::SlotPasaFocoAPaterno()
{
	SiscomPasaFocoControl(QLEAPaterno);
}
void QRegistroEmpleado::SlotPasaFocoAMaterno()
{
	SiscomPasaFocoControl(QLEAMaterno);
}
void QRegistroEmpleado::SlotPasaFocoFirma()
{
	SiscomPasaFocoControl(QLEFirma);
}
void QRegistroEmpleado::SlotPasaFocoPassword()
{
	SiscomPasaFocoControl(QLEPassword);
}
void QRegistroEmpleado::SlotPasaFocoRePassword()
{
	SiscomPasaFocoControl(QLENPassword);
}
void QRegistroEmpleado::SlotPasaFocoRegistra()
{
	SiscomPasaFocoControl(QPBRegistrar);
}
void QRegistroEmpleado::IniciaVariables()
{
	ObtenAplicacion();
	ObtenPerfiles();
	QCtrPerfiles->setFocus();

	SiscomEscribeLog3Qt("El Id de la aplicacion:%s", chrPtrArgumentos[9]);
}
void QRegistroEmpleado::ObtenPerfiles()
{
	QCtrPerfiles->PonServidor(SisDatCom);
	QCtrPerfiles->PonAplicacion(chrPtrAplicacion);
	QCtrPerfiles->IniciaControl();
}
void QRegistroEmpleado::ObtenAplicacion()
{

	if(!(chrPtrAplicacion=getenv("Aplicacion")))
	{
	 printf("No Se Ha definido la variable \"Aplicacion\"\n");
	 exit(0);
	}

}
void QRegistroEmpleado::FormaEmpleado()
{
   CQSEmpleado=new CQSisEmpleado(
   		"",
		SiscomObtenInformacionDelEdit(QLENombre),
		SiscomObtenInformacionDelEdit(QLEAPaterno),
		SiscomObtenInformacionDelEdit(QLEAMaterno),
		SiscomObtenInformacionDelEdit(QLEFirma),
		SiscomObtenInformacionDelEdit(QLEPassword),
		SiscomObtenInformacionDelEdit(QLENPassword),
		PSeguridad->SRegistrosPro2["IdPerfil"],
		chrPtrArgumentos[9]);
}
void QRegistroEmpleado::EjecutaRegistro()
{
SiscomRegistrosPro2 *lSRegistroPro2=0;
CQSisOpTiendas4 lCQOTiendas4(SisDatCom);
lCQOTiendas4.Empleado(CQSEmpleado,&lSRegistroPro2);
SiscomEscribeLog3Qt("El Resultado:%d",lSRegistroPro2->SiscomObtenNumRegistros());
if(lSRegistroPro2->SiscomObtenNumRegistros())
QMessageBox::information(this,
			 (*lSRegistroPro2)["Funcion"],
			 (*lSRegistroPro2)["Error"]);
}
void QRegistroEmpleado::Registra()
{
  FormaEmpleado();
  EjecutaRegistro();
}

void QRegistroEmpleado::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
