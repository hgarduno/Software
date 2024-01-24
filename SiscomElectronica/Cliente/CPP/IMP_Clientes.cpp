#include <IMP_Clientes.h>
#include<SISCOMComunicaciones++.h>
#include <qtabwidget.h>
#include <qpushbutton.h>
#include <qlistview.h>
QClientes *InstanciaClientes(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QClientes((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QClientes::QClientes(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				Clientes(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				intDireccionActual(0)
{
IniciaVariables();
ConectaSlots();
}

QClientes::~QClientes()
{

}

void QClientes::ConectaSlots()
{
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoRFC()));
	connect(QLERFC,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoCalle()));
	connect(QLECalle,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoNo()));
	connect(QLENo,
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
	connect(QLECEstados,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoTelefono()));
	connect(QLETelefono,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoDescripcion()));
	connect(QLEDescripcion,
		SIGNAL(returnPressed()),
		SLOT(S_PasaFocoAnexarTelefono()));
	connect(QTWTipoPersona,
		SIGNAL(currentChanged(QWidget *)),
		SLOT(S_CambioPestana(QWidget *)));
	
	connect(QPBAgregarDireccion,
		SIGNAL(clicked()),
		SLOT(S_AnexarDireccion()));
	connect(QPBSDireccion,
		SIGNAL(clicked()),
		SLOT(S_SiguienteDireccion()));
	connect(QPBAntDireccion,
		SIGNAL(clicked()),
		SLOT(S_DireccionAnterior()));
	connect(QPBModificar,
		SIGNAL(clicked()),
		SLOT(S_ModificarDireccion()));
	connect(QPBEliminarDireccion,
		SIGNAL(clicked()),
		SLOT(S_EliminarDireccion()));
	connect(QPBAnexarTelefono,
		SIGNAL(clicked()),
		SLOT(S_AnexarTelefono()));
	connect(QLVTelefonos,
		SIGNAL(clicked(QListViewItem *)),
		SLOT(S_SeleccionaTelefono(QListViewItem *)));
	connect(QPBEliminarTelefono,
		SIGNAL(clicked()),
		SLOT(S_EliminaTelefono()));
}
void QClientes::S_EliminaTelefono()
{
int lintNoTelefono=QLVTelefonos->itemPos(QLVITelefono);

	SiscomMensajesLog(gPtrFleArchivoLog,
			  "El numero del telefono: %d",
			  lintNoTelefono);

	delete QLVITelefono;
	MCCliente.remove(lintNoTelefono);

}
void QClientes::S_SeleccionaTelefono(QListViewItem *pQLVITelefono)
{
	QLVITelefono=pQLVITelefono;	
}
void QClientes::S_AnexarTelefono()
{
MedioComunicacion *lMCTelefono;
	MCCliente << (lMCTelefono=new MedioComunicacion("",
					   "",
					   SiscomObtenInformacionDelEdit(QLETelefono),
					   "Telefono",
					   SiscomObtenInformacionDelEdit(QLEDescripcion)));
	
	QLVTelefonos->insertItem(
			new QListViewItem(
				QLVTelefonos,
				SiscomObtenInformacionDelEdit(QLETelefono)));
				

}
void QClientes::S_EliminarDireccion()
{
	DCliente.remove(intDireccionActual);
	intDireccionActual=0;
}
void QClientes::S_ModificarDireccion()
{
Direccion *lDireccion=DCliente.at(intDireccionActual);
	if(QPBModificar->text()=="M")
	{
	   QLECalle->setText(lDireccion->SRegistrosPro2["Calle"]);
	   QLENo->setText(lDireccion->SRegistrosPro2["Numero"]);
	   QLECP->setText(lDireccion->SRegistrosPro2["CP"]);
	   QLEColonia->setText(lDireccion->SRegistrosPro2["Colonia"]);
	   QLEMunicipio->setText(lDireccion->SRegistrosPro2["Municipio"]);
	   QCBEstados->setCurrentText(lDireccion->SRegistrosPro2["Estado"]);
	   QPBModificar->setText("A");
	}
	else
	if(QPBModificar->text()=="A")
	{
 	    lDireccion->SiscomActualizaCampo(
	    		"Calle",
			SiscomObtenInformacionDelEdit(QLECalle));
	    lDireccion->SiscomActualizaCampo(
	    		"Numero",
			SiscomObtenInformacionDelEdit(QLENo));
	    lDireccion->SiscomActualizaCampo(
	    		"CP",
			SiscomObtenInformacionDelEdit(QLECP));
	    lDireccion->SiscomActualizaCampo(
	    		"Municipio",
			SiscomObtenInformacionDelEdit(QLEMunicipio));
	    lDireccion->SiscomActualizaCampo(
	    		"Estado",
			SiscomObtenInformacionDelEdit(QLECEstados));
	   QPBModificar->setText("M");
	   MuestraDireccion(lDireccion);
	}
	
}
void QClientes::S_SiguienteDireccion()
{
	intDireccionActual++;
	intDireccionActual=intDireccionActual==DCliente.count() ?
	                   0 : intDireccionActual;
	MuestraDireccion(DCliente.at(intDireccionActual));
}
void QClientes::S_DireccionAnterior()
{
	intDireccionActual--;
	intDireccionActual=intDireccionActual<0 ? DCliente.count()-1:intDireccionActual; 
	MuestraDireccion(DCliente.at(intDireccionActual));
}
void QClientes::S_AnexarDireccion()
{

	DCliente << new Direccion(
			   "",
			   "",
			   SiscomObtenInformacionDelEdit(QLECalle),
			   SiscomObtenInformacionDelEdit(QLENo),
			   SiscomObtenInformacionDelEdit(QLEColonia),
			   SiscomObtenInformacionDelEdit(QLECP),
			   SiscomObtenInformacionDelEdit(QLEMunicipio),
			   SiscomObtenInformacionDelEdit(QLECEstados),
			   "");
	intDireccionActual=DCliente.count()-1;
	MuestraDireccion(DCliente.at(intDireccionActual));
}
void QClientes::S_CambioPestana(QWidget *pQWPestana)
{
	switch(QTWTipoPersona->indexOf(pQWPestana))
	{
		case 0:
			SiscomPasaFocoControl(QLENombre);
		break;
		case 1:
			SiscomPasaFocoControl(QLERazonSocial);
		break;
	}

}
void QClientes::S_PasaFocoAPaterno()
{
	SiscomPasaFocoControl(QLEAPaterno);
}
void QClientes::S_PasaFocoAMaterno()
{
	SiscomPasaFocoControl(QLEAMaterno);
}
void QClientes::S_PasaFocoRFC()
{
	SiscomPasaFocoControl(QLERFC);
}
void QClientes::S_PasaFocoCalle()
{
	SiscomPasaFocoControl(QLECalle);
}
void QClientes::S_PasaFocoNo()
{
	SiscomPasaFocoControl(QLENo);
}
void QClientes::S_PasaFocoCP()
{
	SiscomPasaFocoControl(QLECP);
}
void QClientes::S_PasaFocoColonia()
{
	SiscomPasaFocoControl(QLEColonia);
}
void QClientes::S_PasaFocoMunicipio()
{
	SiscomPasaFocoControl(QLEMunicipio);
}
void QClientes::S_PasaFocoEstado()
{
	SiscomPasaFocoControl(QLECEstados);
}
void QClientes::S_PasaFocoTelefono()
{
	SiscomPasaFocoControl(QLETelefono);
}
void QClientes::S_PasaFocoDescripcion()
{
	SiscomPasaFocoControl(QLEDescripcion);
}
void QClientes::S_PasaFocoAnexarTelefono()
{
	SiscomPasaFocoControl((QWidget *)QPBAnexarTelefono);
}
void QClientes::IniciaVariables()
{
	QLECEstados=SiscomColocaEditAlCombo(QCBEstados,"QLECEstados");
}

void QClientes::MuestraDireccion(Direccion *pDireccion)
{
	QTEDirecciones->setText(
		QString("Calle:")+
		pDireccion->SRegistrosPro2["Calle"]		+
		" "						+
		pDireccion->SRegistrosPro2["Numero"]		+
		"\n"						+
		"Colonia:"					+
		pDireccion->SRegistrosPro2["Colonia"]		+
		","						+
		pDireccion->SRegistrosPro2["CP"]		+
		"\n"						+
		"Municipio:"					+
		pDireccion->SRegistrosPro2["Municipio"]		+
		"\n"						+
		"Estado:"					+
		pDireccion->SRegistrosPro2["Estado"]);
}

void QClientes::closeEvent(QCloseEvent *)
{
  emit SignalTerminar(this);
}
