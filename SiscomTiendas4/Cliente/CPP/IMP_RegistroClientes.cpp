#include <IMP_RegistroClientes.h>
#include<SISCOMComunicaciones++.h>
#include <CQSisOpTiendas4.h>
#include <CQSisClientes.h>
#include <QSisSepomex.h>
#include <QSisDirecciones.h>
#include <QSisTelefonos.h>
#include <qtabwidget.h>
QRegistroClientes *InstanciaRegistroClientes(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRegistroClientes((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRegistroClientes::QRegistroClientes(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RegistroClientes(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QRegistroClientes::~QRegistroClientes()
{

}

void QRegistroClientes::ConectaSlots()
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
		SLOT(SlotPasaFocoRegistrar()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistrar()));
	

}
void QRegistroClientes::SlotRegistrar()
{
	Registra();
	HabilitaControles(1);
}
void QRegistroClientes::SlotPasaFocoAPaterno()
{
SiscomPasaFocoControl(QLEAPaterno);
}

void QRegistroClientes::SlotPasaFocoAMaterno()
{
SiscomPasaFocoControl(QLEAMaterno);
}
void QRegistroClientes::SlotPasaFocoRFC()
{
	SiscomPasaFocoControl(QLERFC);
}
void QRegistroClientes::SlotPasaFocoRegistrar()
{
SiscomPasaFocoControl(QPBRegistrar);
}
void QRegistroClientes::IniciaVariables()
{
SiscomPasaFocoControl(QLENombre);
QSDirecciones->DatosServidor("ConsultaTiendas4","SepomexEstados");
QSDirecciones->Servidor(SisDatCom);
QSDirecciones->IniciaControl();
QSDirecciones->SistemaConsulta("ConsultaTiendas4");
QSTelefonos->Servidor(SisDatCom);
QSTelefonos->SistemaConsulta("ConsultaTiendas4");
}
void QRegistroClientes::Registra()
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisOpTiendas4 lCQSOTiendas4(SisDatCom);
CQSCliente=Cliente();
lCQSOTiendas4.Cliente(CQSCliente,&lSRegistrosPro2);
CQSCliente->SiscomActualizaCampo("IdPersona",(*lSRegistrosPro2)["IdPersona"]);
QSDirecciones->IdPersona((*CQSCliente)["IdPersona"]);
QSTelefonos->IdPersona((*CQSCliente)["IdPersona"]);

}
CQSisCliente *QRegistroClientes::Cliente()
{
return new CQSisCliente(
		SiscomObtenInformacionDelEdit(QLENombre),
		SiscomObtenInformacionDelEdit(QLEAPaterno),
		SiscomObtenInformacionDelEdit(QLEAMaterno),
		SiscomObtenInformacionDelEdit(QLERFC),
		"");
}
void QRegistroClientes::HabilitaControles(int pintEdo)
{
QTWidget->setEnabled(pintEdo);
QSDirecciones->setEnabled(pintEdo);
QSTelefonos->setEnabled(pintEdo);
}

void QRegistroClientes::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
