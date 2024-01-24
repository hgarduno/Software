#include <IMP_CapturaClientes.h>
#include <SiscomDesarrollo3Qt++.h>
#include <CQSis3QtOperaciones.h>
#include <CQSisClientes.h>
#include <SiscomDesarrollo3Qt++.h>


#include <qcombobox.h>
#include <qtabwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
QCapturaClientes::QCapturaClientes(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaClientes(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				intOpcion(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaClientes::~QCapturaClientes()
{

}

void QCapturaClientes::ConectaSlots()
{

connect(QLENombre,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoAAPaterno()));
connect(QLEAPaterno,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoAAMaterno()));
connect(QLEAMaterno,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoARFC()));

connect(QLERFC,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoATelefono()));
connect(QLETelefono,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoACorreo()));

connect(QLECorreoE,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoACalle()));
connect(QLECalle,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoANumero()));
connect(QLENumero,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoAColonia()));
connect(QLEColonia,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoACP()));
connect(QLECP,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoAMunicipio()));
connect(QLEDelMun,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoAEstado()));

connect(QLEEstado,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoAAceptar()));
connect(QCBRFC,
	SIGNAL(activated(int)),
	SLOT(SlotCliente(int)));
connect(QPBNCliente,
	SIGNAL(clicked()),
	SLOT(SlotNCliente()));
connect(QPBRCliente,
	SIGNAL(clicked()),
	SLOT(SlotRegistraCliente()));
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));
}
void QCapturaClientes::SlotFocoACalle()
{
SiscomDesarrollo3Qt::FocoAControl(QLECalle);
}

void QCapturaClientes::SlotFocoANumero()
{
SiscomDesarrollo3Qt::FocoAControl(QLENumero);
}
void QCapturaClientes::SlotFocoAColonia()
{
SiscomDesarrollo3Qt::FocoAControl(QLEColonia);
}

void QCapturaClientes::SlotFocoACP()
{
SiscomDesarrollo3Qt::FocoAControl(QLECP);
}

void QCapturaClientes::SlotFocoAMunicipio()
{
SiscomDesarrollo3Qt::FocoAControl(QLEDelMun);
}

void QCapturaClientes::SlotFocoAEstado()
{
SiscomDesarrollo3Qt::FocoAControl(QLEEstado);
}

void QCapturaClientes::SlotFocoAAceptar()
{
SiscomDesarrollo3Qt::FocoAControl(QPBAceptar);
}
void QCapturaClientes::SlotFocoAAPaterno()
{
SiscomDesarrollo3Qt::FocoAControl(QLEAPaterno);
}
void QCapturaClientes::SlotFocoAAMaterno()
{
SiscomDesarrollo3Qt::FocoAControl(QLEAMaterno);
}

void QCapturaClientes::SlotFocoARFC()
{
SiscomDesarrollo3Qt::FocoAControl(QLERFC);
}

void QCapturaClientes::SlotFocoATelefono()
{
SiscomDesarrollo3Qt::FocoAControl(QLETelefono);
}
void QCapturaClientes::SlotFocoACorreo()
{
SiscomDesarrollo3Qt::FocoAControl(QLECorreoE);
}

void QCapturaClientes::SlotRegistraCliente()
{
if(!intTipoPersona)
RegistraPersonaMoral();
if(intTipoPersona==1)
RegistraPersonaMoral();
}
void QCapturaClientes::SlotNCliente()
{
int lintOpcion;
lintOpcion=QMessageBox::information(this,
			 "Mensaje Del Sistema",
			 "Selecciona Persona Fisica/Moral",
			 "Persona Fisica",
			 "Persona Moral");
SiscomEscribeLog3Qt("La Opcion Seleccionada:%d",lintOpcion); 
intTipoPersona=lintOpcion;
SeleccionaTipoPersona(lintOpcion);
}
void QCapturaClientes::SlotCliente(int pintCliente)
{
   CQSisPtrCliente=(CQSisCliente *)SisReg3LstClientes[pintCliente];
   MuestraCliente(CQSisPtrCliente);
   SeleccionaPestana(CQSisPtrCliente);
   SiscomDesarrollo3Qt::PasaFocoControl(QPBAceptar);
}
void QCapturaClientes::SlotAceptar()
{
   intOpcion=1;
   done(1);
}
void QCapturaClientes::IniciaVariables()
{
ConsultandoClientes();
}

void QCapturaClientes::ConsultandoClientes()
{
	ConsultaClientes();
	MuestraClientes();
}

void QCapturaClientes::ConsultaClientes()
{
CQSis3QtOperaciones lCQSis3QtOperacion(SisDatCom);
lCQSis3QtOperacion.Clientes(chrPtrArgumentos[0],
			    &SisReg3LstClientes);
}
void QCapturaClientes::MuestraClientes()
{
/*
SiscomDesarrollo3Qt::RegistrosAlCombo("rfc",
				      QCBRFC,
				      &SisReg3LstClientes);
*/
SiscomRegistro3 *lzSisRegCliente;
for(lzSisRegCliente=SisReg3LstClientes.first();
    lzSisRegCliente;
    lzSisRegCliente=SisReg3LstClientes.next())
     QCBRFC->insertItem(QString((*lzSisRegCliente)["rfc"])+
     		        " " 				  +
			"["                               +
		 	(*lzSisRegCliente)["nombre"]      +
			" "				  +
			(*lzSisRegCliente)["apaterno"]	  +
			"]");

}
void QCapturaClientes::MuestraCliente(SiscomRegistro3 *pSisReg3Cliente)
{
 if(!TipoCliente(pSisReg3Cliente))
  MuestraPersonaFisica(pSisReg3Cliente);
  else
  MuestraPersonaMoral(pSisReg3Cliente);

}
void QCapturaClientes::MuestraPersonaFisica(SiscomRegistro3 *pSisReg3Cliente)
{
QLENombre->setText((*pSisReg3Cliente)["nombre"]);
QLEAPaterno->setText((*pSisReg3Cliente)["apaterno"]);
QLEAMaterno->setText((*pSisReg3Cliente)["amaterno"]);
QLERFC->setText((*pSisReg3Cliente)["rfc"]);
QLECalle->setText((*pSisReg3Cliente)["calle"]);
QLENumero->setText((*pSisReg3Cliente)["numero"]);
QLEColonia->setText((*pSisReg3Cliente)["colonia"]);
QLEEstado->setText((*pSisReg3Cliente)["estado"]);
QLEDelMun->setText((*pSisReg3Cliente)["municipio"]);
QLECP->setText((*pSisReg3Cliente)["cp"]);
QLETelefono->setText((*pSisReg3Cliente)["telefono"]);
QLECorreoE->setText((*pSisReg3Cliente)["correo"]);
}
void QCapturaClientes::MuestraPersonaMoral(SiscomRegistro3 *pSisReg3Cliente)
{
 QLERazonSocial->setText((*pSisReg3Cliente)["nombre"]);
 QLERFC->setText((*pSisReg3Cliente)["rfc"]);
 QLECalle->setText((*pSisReg3Cliente)["calle"]);
 QLENumero->setText((*pSisReg3Cliente)["numero"]);
 QLEColonia->setText((*pSisReg3Cliente)["colonia"]);
 QLEEstado->setText((*pSisReg3Cliente)["estado"]);
 QLEDelMun->setText((*pSisReg3Cliente)["municipio"]);
 QLECP->setText((*pSisReg3Cliente)["cp"]);
 QLETelefono->setText((*pSisReg3Cliente)["telefono"]);
 QLECorreoE->setText((*pSisReg3Cliente)["correo"]);
}
void QCapturaClientes::SeleccionaPestana(SiscomRegistro3 *pSisReg3Cliente)
{
int lintPestana=TipoCliente(pSisReg3Cliente);
QTWTipoCliente->setCurrentPage(lintPestana);
}
int QCapturaClientes::TipoCliente(SiscomRegistro3 *pSisReg3Cliente)
{
return !strcmp((*pSisReg3Cliente)["persona"],"PersonaFisica") ?
	0 : 1;
}
void QCapturaClientes::SeleccionaTipoPersona(int pintPersona)
{
QWidget *lQWFisica=QTWTipoCliente->page(0);
QWidget *lQWMoral=QTWTipoCliente->page(1);

if(!pintPersona)
{
 QTWTipoCliente->setTabEnabled(lQWFisica,true);
 QTWTipoCliente->setTabEnabled(lQWMoral,false);
 QTWTipoCliente->setCurrentPage(0);
 SiscomDesarrollo3Qt::PasaFocoControl(QLENombre);
}
else
if(pintPersona==1)
{
 QTWTipoCliente->setTabEnabled(lQWFisica,false);
 QTWTipoCliente->setTabEnabled(lQWMoral,true);
 QTWTipoCliente->setCurrentPage(1);
 SiscomDesarrollo3Qt::PasaFocoControl(QLERazonSocial);
 connect(QLERazonSocial,
 	SIGNAL(returnPressed()),
	SLOT(SlotFocoARFC()));
}
}

CQSisCliente *QCapturaClientes::Cliente()
{
if(!intTipoPersona)
return new CQSisCliente(
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLENombre),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEAPaterno),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEAMaterno),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLERFC),
	chrPtrArgumentos[0],
	"");
if(intTipoPersona==1)
return new CQSisCliente(
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLERazonSocial),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLERFC),
	"",
	chrPtrArgumentos[0]);
}
void QCapturaClientes::Direccion(CQSisCliente *pCQSisPtrCliente)
{
pCQSisPtrCliente->Direccion(
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLECalle),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLENumero),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEColonia),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLECP),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEDelMun),
	SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEEstado));

}
void QCapturaClientes::Telefono(CQSisCliente *pCQSisPtrCliente)
{
pCQSisPtrCliente->Telefono(
	   SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLETelefono));
}

void QCapturaClientes::CorreoElectronico(CQSisCliente *pCQSisPtrCliente)
{
pCQSisPtrCliente->Correo(
	   SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLECorreoE));
}
CQSisCliente *QCapturaClientes::ClienteSiscom()
{
return CQSisPtrCliente;
}
int QCapturaClientes::Opcion()
{
return intOpcion;
}
void QCapturaClientes::RegistraPersonaFisica()
{
CQSis3QtOperaciones lCQSis3QtOp(SisDatCom);
CQSisPtrCliente=Cliente();
Direccion(CQSisPtrCliente);
Telefono(CQSisPtrCliente);
CorreoElectronico(CQSisPtrCliente);
lCQSis3QtOp.RegistraClienteFisica(CQSisPtrCliente);

}
void QCapturaClientes::RegistraPersonaMoral()
{
CQSis3QtOperaciones lCQSis3QtOp(SisDatCom);
CQSisPtrCliente=Cliente();
Direccion(CQSisPtrCliente);
Telefono(CQSisPtrCliente);
CorreoElectronico(CQSisPtrCliente);
lCQSis3QtOp.RegistraClienteMoral(CQSisPtrCliente);
}
