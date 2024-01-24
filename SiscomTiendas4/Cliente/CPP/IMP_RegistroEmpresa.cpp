#include <IMP_RegistroEmpresa.h>
#include<SISCOMComunicaciones++.h>
#include <SiscomDesarrollo3Qt++.h>


#include <QSisSepomex.h>
#include <SisDirecciones.h>
#include <SisMedioComunicacion.h>
#include <CQSisEmpresas.h>
#include <CQSisOpTiendas4.h>

#include <QCtrlMedComunicacion.h>
#include <CQSisOpTiendas43Qt.h>
#include <QSisManDirecciones.h>

#include <qpushbutton.h>
#include <qbuttongroup.h>
#include <qtoolbox.h>
QRegistroEmpresa *InstanciaRegistroEmpresa(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRegistroEmpresa((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRegistroEmpresa::QRegistroEmpresa(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RegistroEmpresa(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QRegistroEmpresa::~QRegistroEmpresa()
{

}

void QRegistroEmpresa::ConectaSlots()
{
	connect(QLERSocial,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoDireccion()));
	connect(QCtrSepomex,
		SIGNAL(SignalDireccion(SiscomRegistro3 *)),
		SLOT(SlotDireccion(SiscomRegistro3 *)));
	connect(QLENombre,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAPaterno()));
	connect(QLEAPaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoAMaterno()));
	connect(QLEAMaterno,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoDscContacto()));
	connect(QLEMedio,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoDscTelefono()));
	connect(QPBRegistrar,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));
	connect(QCtrMedCom,
		SIGNAL(SignalMedComunicacion(SisMedCom *)),
		SLOT(SlotMedComunicacion(SisMedCom *)));
	connect(QBGTipo,
		SIGNAL(clicked(int)),
		SLOT(SlotTipo(int)));
	connect(QTDirecciones,
		SIGNAL(contextMenuRequested(int,int,const QPoint &)),
		SLOT(SlotMantenimientoDirecciones(int,int,const QPoint &)));
		
		
}
void QRegistroEmpresa::SlotMantenimientoDirecciones(int pintNFila,
						    int pintNColumna,
						    const QPoint &pQPPosicion)
{
QSisManDirecciones lQSisManDir(pQPPosicion,
			       IdEmpresaRegistrada(),
			       SisDatCom,
			       chrPtrArgumentos);
if(lQSisManDir.EdoOperacion())
InformacionEmpresa();
}
void QRegistroEmpresa::SlotTipo(int )
{
	chrPtrTipo=(const char *)QBGTipo->selected()->text();
}
void QRegistroEmpresa::SlotMedComunicacion(SisMedCom *pSMCom)
{
	SMCom=pSMCom;	
	SiscomPasaFocoControl(QLEMedio);
	
}
void QRegistroEmpresa::SlotRegistra()
{
	Registra();
}
void QRegistroEmpresa::SlotPasaFocoDscTelefono()
{
	SiscomPasaFocoControl(QTEDscTelefono);
}
void QRegistroEmpresa::SlotPasaFocoDscContacto()
{
	SiscomPasaFocoControl(QTEDscContacto);
}
void QRegistroEmpresa::SlotPasaFocoAMaterno()
{
	SiscomPasaFocoControl(QLEAMaterno);
}
void QRegistroEmpresa::SlotPasaFocoAPaterno()
{
	SiscomPasaFocoControl(QLEAPaterno);
}
void QRegistroEmpresa::SlotDireccion(SiscomRegistro3 *pSisReg3Direccion)
{
	if(pSisReg3Direccion)
	{
	SisReg3Direccion=pSisReg3Direccion;
	SiscomPasaFocoControl(QLENombre);
	}
}
void QRegistroEmpresa::SlotPasaFocoDireccion()
{
	if(!EmpresaRegistrada())
	{
	SiscomEscribeLog3Qt("La Empresa no esta registrada");
	QCtrSepomex->setFocus();
	}
	else
	InformacionEmpresa();
}

void QRegistroEmpresa::InformacionEmpresa()
{
MuestraDirecciones();
MuestraContactos();
MuestraComunicacion();
QTBEmpresas->setCurrentIndex(1);
}
int QRegistroEmpresa::EmpresaRegistrada()
{
CQSisOpTiendas43Qt lCQSisOpT43Qt(SisDatCom);
CQSisEmpresa3Qt *lCQSEmpresa3Qt;

lCQSEmpresa3Qt=new CQSisEmpresa3Qt("",
			SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLERSocial));
SisReg3LstLstEmpReg.clear();
return lCQSisOpT43Qt.EmpresaRegistrada(
		      lCQSEmpresa3Qt,
		      &SisReg3LstLstEmpReg);
			
}
void QRegistroEmpresa::IniciaVariables()
{
	QCtrSepomex->PonServidor(SisDatCom);
	QCtrSepomex->SiscomDatosServidor("ConsultaTiendas4","SepomexEstados");
	QCtrSepomex->IniciaControl();
	SiscomPasaFocoControl(QLERSocial);
	QCtrMedCom->PonServidor(SisDatCom);
	QCtrMedCom->IniciaControl();
}
void QRegistroEmpresa::Registra()
{
CQSisOpTiendas4 lCQSOT4REmpresa(SisDatCom);
	lCQSOT4REmpresa.AnexaEmpresa(FormaEmpresa());
}
CQSisEmpresa *QRegistroEmpresa::FormaEmpresa()
{

return new CQSisEmpresa(
		"",
		SiscomObtenInformacionDelEdit(QLERSocial),
		(*SisReg3Direccion)["Calle"],
		(*SisReg3Direccion)["Numero"],
		(*SisReg3Direccion)["idasentamiento"],
		SiscomObtenInformacionDelEdit(QLENombre),
		SiscomObtenInformacionDelEdit(QLEAPaterno),
		SiscomObtenInformacionDelEdit(QLEAMaterno),
		SiscomObtenInformacionDelEdit(QTEDscContacto),
		SMCom->SRegistrosPro2["IdMedio"],
		SiscomObtenInformacionDelEdit(QLEMedio),
		SiscomObtenInformacionDelEdit(QTEDscTelefono),
		chrPtrTipo);
}

void QRegistroEmpresa::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}

void QRegistroEmpresa::MuestraDirecciones()
{
const char *lchrPtrCampos[]={"calle",
		       "numero",
		       "asentamiento",
		       "municipio",
		       "estado",
		       "cp",
		       0
		       };
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
				       QTDirecciones,
				       SisReg3LstLstEmpReg[1]);
			
}
void QRegistroEmpresa::MuestraContactos()
{
const char *lchrPtrCampos[]={"nombre",
		       "apaterno",
		       "amaterno",
		       0
		       };
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
					QTContactos,
					SisReg3LstLstEmpReg[0]);
}
void QRegistroEmpresa::MuestraComunicacion()
{
const char *lchrPtrCampos[]={"dato",
		       "descripcion",
		       0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
					QTMedCom,
					SisReg3LstLstEmpReg[2]);
}
const char *QRegistroEmpresa::IdEmpresaRegistrada()
{
SiscomRegistro3Lst *lSisReg3LstDat=SisReg3LstLstEmpReg[0];
SiscomRegistro3 *lSisReg3Dato=(*lSisReg3LstDat)[0];
 SiscomEscribeLog3Qt("%s",(*lSisReg3Dato)["idempresa"]);
 return (*lSisReg3Dato)["idempresa"];
}
