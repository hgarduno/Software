#include <IMP_ManejadorProveedores.h>
#include <IMP_CapturaTelefono.h>
#include <IMP_CapturaContacto.h>
#include <IMP_BuscaEmpresas.h>
#include <IMP_ModificaProveedor.h>
#include <Direcciones.h>
#include <Personas.h>
#include <Telefonos.h>
#include <CQSiscomCom.h>
#include <Empresas.h>

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qmessagebox.h>
QManejadorProveedores *InstanciaManejadorProveedores(void *pCSisDatCom,
						     void *pQWParent,
						     const char *pchrPtrName,
						     int pintWFlags)
{
	return new QManejadorProveedores((CSISCOMDatComunicaciones *)pCSisDatCom,
					 (QWidget *)pQWParent,
					 pchrPtrName,
					 pintWFlags);
}

QManejadorProveedores::QManejadorProveedores(CSISCOMDatComunicaciones *pCSisDatCom,
				QWidget* parent, const char* name, WFlags fl )
    : ManejadorProveedores( parent, name, fl ),
    CSisDatCom(pCSisDatCom),
	E_Empresa(0),
	chrPtrEsExpendio("0")
{
	IniciaVariables();
	ConectaSlots();
}

QManejadorProveedores::~QManejadorProveedores()
{
}
void QManejadorProveedores::IniciaVariables()
{
	QLECEstado=ColocaLineEditAlCombo(QCBEstados,"QLECEstado");
	PasaFocoControl(QLERazonSocial);
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
		SLOT(S_RegistraProveedor()));
	connect(QPBAnexarTelefono,
		SIGNAL(clicked()),
		SLOT(S_AnexarTelefono()));
	connect(QPBAnexarContacto,
		SIGNAL(clicked()),
		SLOT(S_AnexarContacto()));
	connect(QPBCnsProveedor,
		SIGNAL(clicked()),
		SLOT(S_BuscarProveedores()));
	connect(QPBMDatos,
		SIGNAL(clicked()),
		SLOT(S_ModificarDatos()));
	

}
void QManejadorProveedores::S_ModificarDatos()
{
if(E_Empresa)
QModificaProveedor lQMProveedor(CSisDatCom,
				E_Empresa);
else
QMessageBox::information(this,
			 getenv("Aplicacion"),
			 "Se debe seleccionar Una empresa");
}
void QManejadorProveedores::S_BuscarProveedores()
{
QBuscaEmpresas lCQBEmpresas(CSisDatCom);
	CQEBuscar.clear();
	if(lCQBEmpresas.ObtenSeleccion()==SISCOMGlobales::Aceptar)
	{
	 Empresa *lE_Empresa=lCQBEmpresas.ObtenEmpresa();
	   
	   CQCtrEmpresas lCQEmpresas(CSisDatCom,
				     QStringList() <<
				     "ConsultaEmpresas" <<
				     "DatosDeLaEmpresa" <<
				     lE_Empresa->ObtenIdEmpresa(),
				     &CQEBuscar);
	   E_Empresa=CQEBuscar.at(0);
	  MuestraEmpresa(CQEBuscar.at(0));
	}
}
void QManejadorProveedores::S_AnexarContacto()
{
QCapturaContacto lQCapContacto;

PasaFocoControl(QPBAnexarContacto);
		if(lQCapContacto.ObtenOpcion()==SISCOMGlobales::Aceptar)
		{
		   AnexarRegistroALaTabla(QTContactos,
				   	  QStringList() <<
					  lQCapContacto.ObtenNombreCompleto());
		   E_Empresa->AnexarContacto(new CQ_Persona(
					   lQCapContacto.ObtenNombre(),
					   lQCapContacto.ObtenAPaterno(),
					   lQCapContacto.ObtenAMaterno(),
					   "",
					   "2",
					   "")
				   	  );
		}

}
void QManejadorProveedores::S_AnexarTelefono()
{
QCapturaTelefono lQCTelefono;
const char *lchrPtrTelefonoYDescripcion;
PasaFocoControl(QPBAnexarTelefono);
	if(lQCTelefono.ObtenOpcion()==QCapturaTelefono::Aceptar)
	{
	    AnexarRegistroALaTabla(QTTelefonos,
				   QStringList() <<
				   (lchrPtrTelefonoYDescripcion=lQCTelefono.ObtenTelefonoYDescripcion()));
	    E_Empresa->AnexarTelefono(new CQ_Telefono("",
						      lchrPtrTelefonoYDescripcion));
				

				   
	}

}
void QManejadorProveedores::S_PasaFocoRFC()
{
	PasaFocoControl(QLERFC);
}
void QManejadorProveedores::S_PasaFocoCalle()
{
	if(!E_Empresa)
	E_Empresa= new Empresa(SISCOMObtenInformacionDelEdit(QLERazonSocial),
				SISCOMObtenInformacionDelEdit(QLERFC),
				"",
				chrPtrEsExpendio);
	QPBRProveedor->setEnabled(true);
	PasaFocoControl(QLECalle);
	HabilitaDesHabilitaControles("%W1%W1",
				     QPBAnexarTelefono,
				     QPBAnexarContacto);
}
void QManejadorProveedores::S_PasaFocoNumero()
{
	PasaFocoControl(QLENumero);
	SeHabilitaAnexarDireccion();
}
void QManejadorProveedores::S_PasaFocoCP()
{
	SeHabilitaAnexarDireccion();
	PasaFocoControl(QLECP);
}
void QManejadorProveedores::S_PasaFocoColonia()
{
	PasaFocoControl(QLEColonia);
}
void QManejadorProveedores::S_PasaFocoMunicipio()
{
	PasaFocoControl(QLEMunicipio);
}
void QManejadorProveedores::S_PasaFocoEstado()
{
	PasaFocoControl(QLECEstado);
}
void QManejadorProveedores::S_PasaFocoAnexarDireccion()
{
	PasaFocoControl(QPBAnexarDireccion);
}
void QManejadorProveedores::S_AnexarDireccion()
{
PasaFocoControl(QPBAnexarDireccion);
	E_Empresa->AnexarDireccion(
			new CQ_Direccion(
			SISCOMObtenInformacionDelEdit(QLECalle),
			SISCOMObtenInformacionDelEdit(QLENumero),
			SISCOMObtenInformacionDelEdit(QLEColonia),
			SISCOMObtenInformacionDelEdit(QLECP),
			SISCOMObtenInformacionDelEdit(QLEMunicipio),
			SISCOMObtenInformacionDelEdit(QLECEstado),
			"")
		     );
	AnexarRegistroALaTabla(QTDirecciones,
			       QStringList() <<
			       QLECalle->text () + 
			       " "    		 +
			       QLENumero->text() );

	
}
void QManejadorProveedores::S_RegistraProveedor()
{
CQEmpresas lCQEmpresas;

lCQEmpresas.append(E_Empresa);
CQCtrEmpresas lCQCERegProv(CSisDatCom,
			   QStringList () <<
			   QString("RegistraEmpresa") <<
			   "Otro Parametro"           <<
			   "Otro Parametro 1" ,
			   &lCQEmpresas);

	QPBRProveedor->setEnabled(false);
	PasaFocoControl(QLERazonSocial);
	QTTelefonos->setNumRows(0);
	QTContactos->setNumRows(0);
	QTDirecciones->setNumRows(0);
	emit Signal_EjecutoRegistro();
	
	HabilitaDesHabilitaControles("%W0%W0",
				     QPBAnexarTelefono,
				     QPBAnexarContacto);
}
void QManejadorProveedores::SeHabilitaAnexarDireccion()
{
	printf("SeHabilitaAnexarDireccion:%d,%d\n",
		QLECalle->text().isEmpty(),
		QLENumero->text().isEmpty());
	QPBAnexarDireccion->setEnabled(!QLECalle->text().isEmpty()	&&
				       !QLENumero->text().isEmpty());
	
}
void QManejadorProveedores::PonEsExpendio(const char *pchrPtrEsExpendio)
{
	chrPtrEsExpendio=pchrPtrEsExpendio;
}
void QManejadorProveedores::MuestraEmpresa(Empresa *pEEmpresa)
{

	QLERazonSocial->setText(pEEmpresa->ObtenRazonSocial());	
	MuestraDirecciones(pEEmpresa->ObtenDirecciones());
	MuestraTelefonos(pEEmpresa->ObtenTelefonos());
	MuestraContactos(pEEmpresa->ObtenContactos());


}
void QManejadorProveedores::MuestraDirecciones(CQ_Direcciones pCQDirecciones)
{
CQ_Direccion *lCQDireccion;

	QTDirecciones->setNumRows(0);
	for(lCQDireccion=pCQDirecciones.first();
	    lCQDireccion;
	    lCQDireccion=pCQDirecciones.next())
	AnexarRegistroALaTabla(QTDirecciones,
				QStringList() <<
				QString(lCQDireccion->ObtenCalle()) +
				" "				    +
				lCQDireccion->ObtenNumero());
	MuestraDatosDireccion(pCQDirecciones.first());
}
void QManejadorProveedores::MuestraDatosDireccion(CQ_Direccion *pCQDireccion)
{
	QLECalle->setText(pCQDireccion->ObtenCalle());
	QLENumero->setText(pCQDireccion->ObtenNumero());
	QLECP->setText(pCQDireccion->ObtenCP());
	QLEColonia->setText(pCQDireccion->ObtenColonia());
	QLEMunicipio->setText(pCQDireccion->ObtenDelegacion());
}
void QManejadorProveedores::MuestraTelefonos(CQ_Telefonos pCQTelefonos)
{
CQ_Telefono *lCQTelefono;
	QTTelefonos->setNumRows(0);
	for(lCQTelefono=pCQTelefonos.first();
	    lCQTelefono;
	    lCQTelefono=pCQTelefonos.next())
	 AnexarRegistroALaTabla(QTTelefonos,
				QStringList() <<
				lCQTelefono->ObtenTelefono());
}
void QManejadorProveedores::MuestraContactos(CQ_Personas pCQContactos)
{
CQ_Persona *lCQPersona;
	QTContactos->setNumRows(0);
	  for(lCQPersona=pCQContactos.first();
	      lCQPersona;
	      lCQPersona=pCQContactos.next())
	   AnexarRegistroALaTabla(QTContactos,
				  QStringList() <<
				  QString(lCQPersona->ObtenNombre()) +
				  " "                                +
				  lCQPersona->ObtenAPaterno());
}
