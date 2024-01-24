#include <IMP_RegistroEmpleados.h>
#include <IMP_CapturaTelefono.h>
#include <IMP_SelExpendios.h>

#include <SISCOMComunicaciones++.h>
#include <Seguridad3Protocolo2.h>
#include <Personas.h>
#include <EmpresasN.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
QRegistroEmpleados *InstanciaRegistroEmpleados(void *pSisDatCom,
					       char **pchrPtrArgumentos,
					       void *pQWParent,
					       const char *pchrPtrName,
					       int pintWFlags)
{

	return new QRegistroEmpleados((SiscomDatCom *)pSisDatCom,
				  pchrPtrArgumentos,
				  (QWidget *)pQWParent,
				  pchrPtrName,
				  pintWFlags);

}
QRegistroEmpleados::QRegistroEmpleados(SiscomDatCom *pSisDatCom,
				       char **pchrPtrArgumentos,
					QWidget* parent,
					const char* name,
					WFlags fl )
    : RegistroEmpleados( parent, name, fl ),
    SisDatCom(pSisDatCom),
    chrPtrArgumentos(pchrPtrArgumentos)
{
	IniciaVariables();
	ConectaSlots();
}

QRegistroEmpleados::~QRegistroEmpleados()
{
}
void QRegistroEmpleados::IniciaVariables()
{
	LlenaComboPerfiles();
	SiscomPasaFocoControl(QLERFC);
	QLECEstado=SiscomColocaEditAlCombo(QCBEstados,"QLECEstado");
	/*PEmpleado=new Persona;
	DDireccion=new Direccion;
	*/
}
void QRegistroEmpleados::ConectaSlots()
{

	connect(QLERFC,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoNombre()));
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoCalle()));
	connect(QLECalle,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoNumero()));
	connect(QLENumero,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoCP()));
	connect(QLECP,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoColonia()));
	connect(QLEColonia,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoMunicipio()));
	connect(QLEMunicipio,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoEstado()));
	connect(QLECEstado,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAnexarTelefono()));
	connect(QPBAETelefono,
		SIGNAL(clicked()),
		SLOT(S_AnexarTelefono()));
	connect(QPBREmpleado,
		SIGNAL(clicked()),
		SLOT(S_RegistraEmpleado()));
	connect(QPBSExpendio,
		SIGNAL(clicked()),
		SLOT(S_Expendio()));
	
		

}
void QRegistroEmpleados::S_Expendio()
{
QSelExpendios lQSExpendio(SisDatCom);

	Expendio=lQSExpendio.ObtenExpendio();

	setCaption(QString("El Expendio De Trabajo:") +
		   Expendio->SRegistrosPro2["RazonSocial"]);

	QPBREmpleado->setEnabled(Expendio);
}
void QRegistroEmpleados::S_RegistraEmpleado()
{
OpPersonas lOpPersonas(SisDatCom);
PerfilSeguridadProt2 *lPSegProt2;
	lPSegProt2=pSeguridadProt2.at(QCBPerfiles->currentItem());

Persona *lPEmpleado=new Persona(SiscomObtenInformacionDelEdit(QLENombre),
				SiscomObtenInformacionDelEdit(QLEAPaterno),
				SiscomObtenInformacionDelEdit(QLEAMaterno),
				SiscomObtenInformacionDelEdit(QLERFC),
				"",
				lPSegProt2->SRegistrosPro2["IdPerfil"],
				SiscomObtenInformacionDelEdit(QLEFirma),
				SiscomObtenInformacionDelEdit(QLEPassword),
				Expendio->SRegistrosPro2["IdEmpresa"],
				"Empleado",
				lPSegProt2->SRegistrosPro2["IdAplicacion"]);
Direccion *lDireccion;
	lDireccion=new Direccion("",
				 "",
				 SiscomObtenInformacionDelEdit(QLECalle),
				 SiscomObtenInformacionDelEdit(QLENumero),
				 SiscomObtenInformacionDelEdit(QLEColonia),
				 SiscomObtenInformacionDelEdit(QLECP),
				 SiscomObtenInformacionDelEdit(QLEMunicipio),
				 SiscomObtenInformacionDelEdit(QLECEstado),
				 "");
	lPEmpleado->AnexarDireccion(lDireccion);	
	lPEmpleado->AnexarMediosComunicacion(MComunicacion);
	lOpPersonas.RegistrarPersona(lPEmpleado);


}
void QRegistroEmpleados::S_AnexarTelefono()
{
QCapturaTelefono lQCTelefono;

		if(lQCTelefono.ObtenSeleccion())
		{
		 MComunicacion << lQCTelefono.ObtenTelefono();
		 QCBTelefonos->insertItem(lQCTelefono.ObtenTelefono()->SRegistrosPro2["Medio"]);
		}

}
void QRegistroEmpleados::S_PasaFocoNombre()
{
	SiscomPasaFocoControl(QLENombre);
}

void QRegistroEmpleados::S_PasaFocoAPaterno()
{
	SiscomPasaFocoControl(QLEAPaterno);
}
void QRegistroEmpleados::S_PasaFocoAMaterno()
{
	SiscomPasaFocoControl(QLEAMaterno);
}
void QRegistroEmpleados::S_PasaFocoCalle()
{
	SiscomPasaFocoControl(QLECalle);
}
void QRegistroEmpleados::S_PasaFocoNumero()
{
	SiscomPasaFocoControl(QLENumero);
	/*
	DDireccion->SiscomActualizaCampo("Numero",
					 SiscomObtenInformacionDelEdit(QLENumero));
	*/
}
void QRegistroEmpleados::S_PasaFocoCP()
{
	SiscomPasaFocoControl(QLECP);
}
void QRegistroEmpleados::S_PasaFocoColonia()
{
	SiscomPasaFocoControl(QLEColonia);
}
void QRegistroEmpleados::S_PasaFocoMunicipio()
{
	SiscomPasaFocoControl(QLEMunicipio);
}
void QRegistroEmpleados::S_PasaFocoEstado()
{
	SiscomPasaFocoControl(QLECEstado);
}
void QRegistroEmpleados::S_PasaFocoAnexarTelefono()
{
	SiscomPasaFocoControl(QPBAETelefono);
}

void QRegistroEmpleados::LlenaComboPerfiles()
{
const char *lchrPtrNmbAplicacion=getenv("Aplicacion");

	if(lchrPtrNmbAplicacion)
	{
		QOperacionesSeguridad3 lQOpSeguridad3(SisDatCom);
		lQOpSeguridad3.PerfilesAplicacion(lchrPtrNmbAplicacion,
						  pSeguridadProt2);
		PerfilSeguridadProt2 *lPSeguridadProt2;
		for(lPSeguridadProt2=pSeguridadProt2.first();
		    lPSeguridadProt2;
		    lPSeguridadProt2=pSeguridadProt2.next())
		  QCBPerfiles->insertItem(lPSeguridadProt2->SRegistrosPro2["NmbPerfil"]);
	}
	else
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "QRegistroEmpleados::LlenaComboPerfiles:No se definio la variable de ambiente \"Aplicaion\"");
}
void QRegistroEmpleados::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
