#include <IMP_ModificaGenerales.h>
#include <IMP_CapturaDireccion.h>
#include <IMP_CapturaTelefono.h>
#include <CQSiscomCom.h>
#include <Personas.h>
#include <Personas2.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QModificaGenerales::QModificaGenerales(CSISCOMDatComunicaciones *pCSisDatCom,
				       CQ_Persona *pCQPersona,
					QWidget* parent, 
					const char* name,
					bool modal, WFlags fl )
    : ModificaGenerales( parent, name, modal, fl ),
    CSisDatCom(pCSisDatCom),
    CQPersona(pCQPersona)
{
	MuestraEncabezado();
	MuestraDatos();
	ConectaSlots();
	exec();
}

QModificaGenerales::~QModificaGenerales()
{
}
void QModificaGenerales::ConectaSlots()
{
	connect(QPBAGenerales,
		SIGNAL(clicked()),
		SLOT(S_ActualizaGenerales()));
	connect(QPBADireccion,
		SIGNAL(clicked()),
		SLOT(S_AnexaDireccion()));
	connect(QPBATelefono,
		SIGNAL(clicked()),
		SLOT(S_AnexaTelefono()));
}
void QModificaGenerales::S_AnexaTelefono()
{
QCapturaTelefono lQCTelefono;
	if(lQCTelefono.ObtenOpcion()==QCapturaTelefono::Aceptar)
	{
CQ_Personas lCQPersonas;
CQ_Persona *lCQPersona;
	lCQPersona=new CQ_Persona(
				"",
				"",
				"",
				"",
				"",
				"");
	lCQPersona->AnexaApodo(new CQ_Apodo("",
					    ""));
	lCQPersona->AnexaTelefono(new CQ_Telefono(
					"",
					lQCTelefono.ObtenTelefonoYDescripcion()));
	 lCQPersonas.append(lCQPersona);
	  CQCtrActualizaPersona lCQCAPersona(
				 CSisDatCom,
				 QStringList()    <<
				 "AnexaTelefono" <<
				 CQPersona->ObtenIdPersona(),
				 &lCQPersonas);

	}

}
void QModificaGenerales::S_AnexaDireccion()
{
QCapturaDireccion lQCDireccion;
	    if(lQCDireccion.ObtenOpcion()==SISCOMGlobales::Aceptar)
	    {
CQ_Personas lCQPersonas;
CQ_Persona *lCQPersona;
	lCQPersona=new CQ_Persona(
				"",
				"",
				"",
				"",
				"",
				"");
	 lCQPersona->AnexaDireccion(new CQ_Direccion(
					lQCDireccion.ObtenCalle(),
					lQCDireccion.ObtenNumero(),
					lQCDireccion.ObtenColonia(),
					lQCDireccion.ObtenCP(),
					lQCDireccion.ObtenMunicipio(),
					lQCDireccion.ObtenEstado(),
					lQCDireccion.ObtenReferencias()));
	lCQPersona->AnexaApodo(new CQ_Apodo("",
					    ""));
	 lCQPersonas.append(lCQPersona);
	  CQCtrActualizaPersona lCQCAPersona(
				 CSisDatCom,
				 QStringList()    <<
				 "AnexaDireccion" <<
				 CQPersona->ObtenIdPersona(),
				 &lCQPersonas);
	    }
}
void QModificaGenerales::S_ActualizaGenerales()
{
CQ_Personas lCQPersonas;
CQ_Persona *lCQPersona;
	lCQPersona=new CQ_Persona(
				SISCOMObtenInformacionDelEdit(QLENombre),
				SISCOMObtenInformacionDelEdit(QLEAPaterno),
				SISCOMObtenInformacionDelEdit(QLEAMaterno),
				SISCOMObtenInformacionDelEdit(QLERFC),
				"",
				"");
	lCQPersona->AnexaApodo(new CQ_Apodo("",
					    SISCOMObtenInformacionDelEdit(QLEApodo)));
	lCQPersonas.append(lCQPersona);
CQCtrActualizaPersona lCQCAPersona(CSisDatCom,
				   QStringList() 		<<
				   "ActualizaGenerales" 	<<
				   CQPersona->ObtenIdPersona(),
				   &lCQPersonas);

}
void QModificaGenerales::MuestraEncabezado()
{
	setCaption(QString("Actualizando Datos:")	+
		   CQPersona->ObtenNombre()		+
		   " "					+
		   CQPersona->ObtenAPaterno()		+
		   " "					+
		   CQPersona->ObtenAMaterno());
}
void QModificaGenerales::MuestraDatos()
{
	QLERFC->setText(CQPersona->ObtenRFC());
	QLENombre->setText(CQPersona->ObtenNombre());
	QLEAPaterno->setText(CQPersona->ObtenAPaterno());
	QLEAMaterno->setText(CQPersona->ObtenAMaterno());
	MuestraApodo();
	ObtenDireccion(0);
	MuestraDireccion();
}
void QModificaGenerales::MuestraApodo()
{
CQ_Apodos lCQApodos=CQPersona->ObtenApodos();
	QLEApodo->setText(lCQApodos.at(0)->ObtenApodo());
}
void QModificaGenerales::MuestraDireccion()
{
	if(CQDireccion)
	{
	QLECalle->setText(CQDireccion->ObtenCalle());
	QLENumero->setText(CQDireccion->ObtenNumero());
	QLECP->setText(CQDireccion->ObtenCP()); 
	QLEColonia->setText(CQDireccion->ObtenColonia());
	QLEMunicipio->setText(CQDireccion->ObtenDelegacion());
	QTEReferencias->setText(CQDireccion->ObtenReferencias());
	}

}
void QModificaGenerales::ObtenDireccion(int pintNumDireccion)
{
CQ_Direcciones lCQDirecciones=CQPersona->ObtenDirecciones();
	CQDireccion=lCQDirecciones.at(pintNumDireccion);
}
