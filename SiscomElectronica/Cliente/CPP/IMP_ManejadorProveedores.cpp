#include <IMP_ManejadorProveedores.h>
#include <IMP_CapturaContacto.h>
#include <IMP_CapturaTelefono.h>


#include <SISCOMComunicaciones++.h>
#include <EmpresasN.h>
#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

QManejadorProveedores *InstanciaManejadorProveedores(
						void *pSisDatCom,
						char **pchrPtrArgumentos,
						void *pQWParent,
						const char *pchrPtrName,
						int pintWFlags)
{
	return new QManejadorProveedores((SiscomDatCom *)pSisDatCom,
					 pchrPtrArgumentos,
					 (QWidget *)pQWParent,
					 pchrPtrName,
					 pintWFlags);
}
QManejadorProveedores::QManejadorProveedores(SiscomDatCom *pSisDatCom,
					     char **pchrPtrArgumentos,
					     QWidget* parent,
					     const char* name,
					     WFlags fl ) : ManejadorProveedores( parent, name, fl ),
					     SisDatCom(pSisDatCom)
{
	IniciaVariables();
	ConectaSlots();
}

QManejadorProveedores::~QManejadorProveedores()
{
}
void QManejadorProveedores::IniciaVariables()
{
	SiscomPasaFocoControl(QLERazonSocial);
	QLECEstado=SiscomColocaEditAlCombo(QCBEstados,"QLECEstado");
}
void QManejadorProveedores::ConectaSlots()
{
	connect(QLERazonSocial,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoRFC()));
	connect(QLERFC,
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
		SLOT(S_PasaFocoAnexarDireccion()));
	connect(QPBAnexarDireccion,
		SIGNAL(clicked()),
		SLOT(S_AnexarDireccion()));
	connect(QPBRProveedor,
		SIGNAL(clicked()),
		SLOT(S_RegistrarProveedor()));
	connect(QPBAnexarTelefono,
		SIGNAL(clicked()),
		SLOT(S_AnexarTelefono()));
	connect(QPBAnexarContacto,
		SIGNAL(clicked()),
		SLOT(S_AnexarContacto()));
		
}
void QManejadorProveedores::S_AnexarTelefono()
{
QCapturaTelefono lQCTelefono;
MedioComunicacion *lMedioCom;
int lintContador;
	if(lQCTelefono.ObtenSeleccion())
	{
	 QTTelefonos->setNumRows((lintContador=QTTelefonos->numRows())+1);
	 Empresa->AnexaMedioComunicacion((lMedioCom=lQCTelefono.ObtenTelefono()));
	 SiscomAnexarRegistroALaTabla(lintContador,
	 			      QTTelefonos,
				      QStringList() << 
				      QString(lMedioCom->SRegistrosPro2["Medio"])	+
				      " "					  	+
				      lMedioCom->SRegistrosPro2["Departamento"]);

	}

}
void QManejadorProveedores::S_AnexarContacto()
{
QCapturaContacto lQCContacto;
Persona *lPContacto;
int lintNumFilas;
	if(lQCContacto.ObtenSeleccion())
	{
	  QTContactos->setNumRows((lintNumFilas=QTContactos->numRows())+1);
	  Empresa->AnexaContacto((lPContacto=lQCContacto.ObtenContacto()));
	  SiscomAnexarRegistroALaTabla(lintNumFilas,
	  			       QTContactos,
				       QStringList() <<
				       QString(lPContacto->SRegistrosPro2["Nombre"])    +
				       " "						+
				       lPContacto->SRegistrosPro2["APaterno"]		+
				       " "						+
				       lPContacto->SRegistrosPro2["AMaterno"]);
	}
}
void QManejadorProveedores::S_RegistrarProveedor()
{
EmpresasN lEmpresas;
OpEmpresas lOpEmpresas(SisDatCom);	
	lEmpresas << Empresa;
	lOpEmpresas.RegistraEmpresas(lEmpresas);
	LimpiaRegistros();
}
void QManejadorProveedores::S_PasaFocoRFC()
{
	HabilitaAnexar();
	SiscomPasaFocoControl(QLERFC);
}

void QManejadorProveedores::S_PasaFocoCalle()
{
	HabilitaAnexar();
	SiscomPasaFocoControl(QLECalle);
}

void QManejadorProveedores::S_PasaFocoNumero()
{
	SiscomPasaFocoControl(QLENumero);
}

void QManejadorProveedores::S_PasaFocoCP()
{
	SiscomPasaFocoControl(QLECP);
}

void QManejadorProveedores::S_PasaFocoColonia()
{
	SiscomPasaFocoControl(QLEColonia);
}

void QManejadorProveedores::S_PasaFocoMunicipio()
{
	SiscomPasaFocoControl(QLEMunicipio);
}

void QManejadorProveedores::S_PasaFocoEstado()
{
	SiscomPasaFocoControl(QLECEstado);
}

void QManejadorProveedores::S_PasaFocoAnexarDireccion()
{
	SiscomPasaFocoControl(QPBAnexarDireccion);
}

void QManejadorProveedores::S_AnexarDireccion()
{
int lintNumFila=QTDirecciones->numRows();
	Empresa->AnexaDireccion(new 
			Direccion(
				"",
				"",
				SiscomObtenInformacionDelEdit(QLECalle),
				SiscomObtenInformacionDelEdit(QLENumero),
				SiscomObtenInformacionDelEdit(QLEColonia),
				SiscomObtenInformacionDelEdit(QLECP),
				SiscomObtenInformacionDelEdit(QLEMunicipio),
				SiscomObtenInformacionDelEdit(QLECEstado),
				"")
				);
	QTDirecciones->setNumRows(lintNumFila+1);
	SiscomAnexarRegistroALaTabla(lintNumFila,
				     QTDirecciones,
				     QStringList() <<
				     QString(SiscomObtenInformacionDelEdit(QLECalle)) +
				     " "					      +
				     SiscomObtenInformacionDelEdit(QLENumero));
				     
}
void QManejadorProveedores::HabilitaAnexar()
{
	if(!QLERazonSocial->text().isEmpty() &&
	   !QLERFC->text().isEmpty())
	{
	  QPBAnexarDireccion->setEnabled(true);
	  QPBAnexarTelefono->setEnabled(true);
	  QPBAnexarContacto->setEnabled(true);
	  QPBRProveedor->setEnabled(true);
	  Empresa=new EmpresaN((const char *)QLERazonSocial->text(),
	  		       "",
			       (const char *)QLERFC->text());
	}
}

void QManejadorProveedores::LimpiaRegistros()
{
	delete Empresa;
	QTDirecciones->setNumRows(0);
	QTTelefonos->setNumRows(0);
	QTContactos->setNumRows(0);
	SiscomPasaFocoControl(QLERazonSocial);
}
void QManejadorProveedores::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
