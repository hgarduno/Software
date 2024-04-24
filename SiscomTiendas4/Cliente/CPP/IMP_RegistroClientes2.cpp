#include <IMP_RegistroClientes2.h>
#include <SiscomDesarrollo3Qt++.h>

#include <CQSisClientes.h>
#include <CQSisOpTiendas4.h>
#include <CQSisOpTiendas43Qt.h>
#include <CQSisDirecciones2.h>

#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtabwidget.h>
QRegistroClientes2 *InstanciaRegistroClientes2(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRegistroClientes2((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRegistroClientes2::QRegistroClientes2(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RegistroClientes2(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				chrPtrIdPersona(0)
{
IniciaVariables();
ConectaSlots();
}

QRegistroClientes2::~QRegistroClientes2()
{

}

void QRegistroClientes2::ConectaSlots()
{
connect(QLENombre,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoAPaterno()));
connect(QLEAPaterno,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoAMaterno()));
connect(QLEAMaterno,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoRFC()));
connect(QLERFC,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoRegistraGenerales()));
connect(QPBRegistraG,
	SIGNAL(clicked()),
	SLOT(SlotRegistraG()));
connect(QPBADireccion,
	SIGNAL(clicked()),
	SLOT(SlotAnexarDireccion()));
}
void QRegistroClientes2::SlotAnexarDireccion()
{
	AnexarDireccion();
}
void QRegistroClientes2::SlotRegistraG()
{
	RegistraG();
	/*
	QTWPersonas->setEnabled(false);
	*/
	SiscomDesarrollo3Qt::PasaFocoControl(QLEDLinea1);
	if(chrPtrIdPersona)
	ConsultandoDirecciones();
}
void QRegistroClientes2::SlotPasaFocoRegistraGenerales()
{
SiscomDesarrollo3Qt::PasaFocoControl(QPBRegistraG);
}
void QRegistroClientes2::SlotPasaFocoAPaterno()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLEAPaterno);
}
void QRegistroClientes2::SlotPasaFocoAMaterno()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLEAMaterno);
}
void QRegistroClientes2::SlotPasaFocoRFC()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLERFC);
}
void QRegistroClientes2::IniciaVariables()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLENombre);
}

void QRegistroClientes2::RegistraG()
{
SiscomRegistrosPro2 *lSRegistroPro2;
CQSisOpTiendas4 lCQSOTiendas4(SisDatCom);
CQSCliente=Cliente();
lCQSOTiendas4.Cliente(CQSCliente,&lSRegistroPro2);
CQSCliente->SiscomActualizaCampo("IdPersona",(*lSRegistroPro2)["IdPersona"]);
SiscomEscribeLog3Qt("El Id De La persona:%s",
		    (*lSRegistroPro2)["IdPersona"]);
chrPtrIdPersona=(*lSRegistroPro2)["IdPersona"];
}
CQSisCliente *QRegistroClientes2::Cliente()
{
return new CQSisCliente(
		SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLENombre),
		SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEAPaterno),
		SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEAMaterno),
		SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLERFC),
		"");
}
void QRegistroClientes2::ConsultaDirecciones()
{
SisReg3LstDirecciones.clear();
CQSisOpTiendas43Qt lCQSisOpT43Qt(SisDatCom);
lCQSisOpT43Qt.DireccionesCliente(chrPtrIdPersona,&SisReg3LstDirecciones);
}
void QRegistroClientes2::ConsultandoDirecciones()
{
ConsultaDirecciones();
MuestraDirecciones();
}

void QRegistroClientes2::MuestraDirecciones()
{
char *lchrPtrCampos[]={"direccion",0};
SiscomDesarrollo3Qt::RegistrosALaTabla((const char **)lchrPtrCampos,
					QTDirecciones,
					&SisReg3LstDirecciones);
SiscomDesarrollo3Qt::AjustaColumnas(QTDirecciones);
SiscomDesarrollo3Qt::AjustaFilas(QTDirecciones);
QLERFC->setText((*(SisReg3LstDirecciones[0]))["rfc"]);
}

void QRegistroClientes2::AnexarDireccion()
{
char lchrArrDireccion[256];
CQSisOpTiendas43Qt lCQSisOpT43Qt(SisDatCom);
 strcpy(lchrArrDireccion,SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEDLinea1));
 strcat(lchrArrDireccion,"\n");
 strcat(lchrArrDireccion,SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEDLinea2));
 strcat(lchrArrDireccion,"\n");
 strcat(lchrArrDireccion,SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEDLinea3));
 strcat(lchrArrDireccion,"\n");
 strcat(lchrArrDireccion,SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEDLinea4));
 SiscomEscribeLog3Qt("La Direccion A Anexar:%s",lchrArrDireccion);
  SisReg3LstDirecciones << new CQSisDireccion2("0",chrPtrIdPersona,"",lchrArrDireccion);
 lCQSisOpT43Qt.AnexaDireccion(&SisReg3LstDirecciones);
}
