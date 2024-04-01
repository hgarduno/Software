#include <IMP_RegistroEmpresas2.h>
#include <IMP_CapturaDireccionE.h>
#include <IMP_CapturaContactoE.h>
#include <IMP_CapturaMedioComunicacionE.h>
#include<SiscomDesarrollo3Qt++.h>

#include <qpushbutton.h>
#include <qlineedit.h>
#include <qtable.h>
#include <qbuttongroup.h>
QRegistroEmpresas2 *InstanciaRegistroEmpresas2(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRegistroEmpresas2((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRegistroEmpresas2::QRegistroEmpresas2(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RegistroEmpresas2(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QRegistroEmpresas2::~QRegistroEmpresas2()
{

}

void QRegistroEmpresas2::ConectaSlots()
{
	connect(QLERSocial,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoTipoEmpresa()));
	connect(QPBADireccion,
		SIGNAL(clicked()),
		SLOT(SlotAnexarDireccion()));
	connect(QPBAContacto,
		SIGNAL(clicked()),
		SLOT(SlotAnexarContacto()));
	connect(QPBAMedComunicacion,
		SIGNAL(clicked()),
		SLOT(SlotAnexarMedioComunicacion()));
	connect(QPBRegistra,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));
	connect(QBGTEmpresa,
		SIGNAL(clicked(int)),
		SLOT(SlotTipoEmpresa(int)));


}
void QRegistroEmpresas2::SlotPasaFocoTipoEmpresa()
{
SiscomDesarrollo3Qt::PasaFocoControl(QBGTEmpresa);
}
void QRegistroEmpresas2::SlotTipoEmpresa(int pintBoton)
{
intTEmpresa=pintBoton;
SlotVerificaEmpresa();
}
void QRegistroEmpresas2::SlotVerificaEmpresa()
{
  CQSEmpresa2.Generales("",
  			SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLERSocial),
			intTEmpresa==0 ? "Cliente" : "Proveedor" );
if(!EmpresaRegistrada())
{
  SiscomDesarrollo3Qt::PasaFocoControl(QPBADireccion);
  QLERSocial->setEnabled(false);
}
else
{
SiscomEscribeLog3Qt("Empresa ya registrada");
MuestraDatosEmpresa();
SiscomRegistro3LstContenido(CQSEmpresa2.RegistrosSubGrupo(0,0));
SiscomRegistro3LstContenido(CQSEmpresa2.RegistrosSubGrupo(0,1));
SiscomRegistro3LstContenido(CQSEmpresa2.RegistrosSubGrupo(0,2));
SiscomRegistro3LstContenido(CQSEmpresa2.RegistrosSubGrupo(0,3));
}
}
void QRegistroEmpresas2::SlotRegistra()
{
CQSisOperacionesEmp2 lCQSisOpEmpresa2(SisDatCom);
SiscomRegistro4 lSisReg4Resp;
lCQSisOpEmpresa2.Envia((SiscomRegistro3 *)0,
				&CQSEmpresa2,
			&lSisReg4Resp);
}
void QRegistroEmpresas2::SlotAnexarMedioComunicacion()
{
QCapturaMedioComunicacionE lQCMedComunicacion(SisDatCom,chrPtrArgumentos);
CQSisMedioComunicacionE *lCQSMedComunicacion;
if((lCQSMedComunicacion=lQCMedComunicacion.MedioComunicacion()))
{
CQSEmpresa2.AgregaMedioComunicacion(lCQSMedComunicacion);
MuestraMedioComunicacion(lCQSMedComunicacion);
}
}
void QRegistroEmpresas2::SlotAnexarDireccion()
{
CQSisDireccionE *lCQSDireccionE;
QCapturaDireccionE lQCDireccionE(SisDatCom,chrPtrArgumentos);
if((lCQSDireccionE=lQCDireccionE.DireccionE()))
{
CQSEmpresa2.AgregaDireccion(lCQSDireccionE);
MuestraDireccion(lCQSDireccionE);
}
}
void QRegistroEmpresas2::SlotAnexarContacto()
{
CQSisContactoE *lCQSContactoE;
QCapturaContactoE lQCContactoE(SisDatCom,chrPtrArgumentos);
if((lCQSContactoE=lQCContactoE.ContactoE()))
{
 CQSEmpresa2.AgregaContacto(lCQSContactoE);
 MuestraContacto(lCQSContactoE);
}
}
void QRegistroEmpresas2::IniciaVariables()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLERSocial);
}

void QRegistroEmpresas2::MuestraDireccion(CQSisDireccionE *pCQSDireccionE)
{
int lintNFila=QTDirecciones->numRows();
QTDirecciones->setNumRows(lintNFila+1);
QTDirecciones->setText(lintNFila,
		       0,
		       QString((*pCQSDireccionE)["Linea1"])	+
		       	       "\n"			  	+
			       (*pCQSDireccionE)["Linea2"] 	+
			       "\n"				+
			       (*pCQSDireccionE)["Linea3"]);
SiscomDesarrollo3Qt::AjustaFilas(QTDirecciones);
SiscomDesarrollo3Qt::AjustaColumnas(QTDirecciones);
}
void QRegistroEmpresas2::MuestraContacto(CQSisContactoE *pCQSContactoE)
{
int lintNFila=QTContactos->numRows();
QTContactos->setNumRows(lintNFila+1);
QTContactos->setText(lintNFila,
		     0,
		     QString((*pCQSContactoE)["Nombre"]) +
		     " "				 +
		     (*pCQSContactoE)["APaterno"]	 +
		     (*pCQSContactoE)["AMaterno"]);
QTContactos->setText(lintNFila,
		     1,
		     QString((*pCQSContactoE)["Descripcion"]));
SiscomDesarrollo3Qt::AjustaFilas(QTContactos);
SiscomDesarrollo3Qt::AjustaColumnas(QTContactos);
}
void QRegistroEmpresas2::MuestraMedioComunicacion(CQSisMedioComunicacionE *pCQSMedComunicacion)
{
int lintNFila=QTMedComunicacion->numRows();
QTMedComunicacion->setNumRows(lintNFila+1);
QTMedComunicacion->setText(lintNFila,
			   0,
			   (*pCQSMedComunicacion)["Dato"]);
QTMedComunicacion->setText(lintNFila,
			   1,
			   (*pCQSMedComunicacion)["Descripcion"]);


SiscomDesarrollo3Qt::AjustaFilas(QTMedComunicacion);
SiscomDesarrollo3Qt::AjustaColumnas(QTMedComunicacion);
}
int QRegistroEmpresas2::EmpresaRegistrada()
{
int lintRegreso;
CQSisOperacionesEmp2 lCQSOpEmp2(SisDatCom);
lintRegreso=lCQSOpEmp2.EmpresaRegistrada(&CQSEmpresa2);
return lintRegreso;
}
void QRegistroEmpresas2::MuestraDatosEmpresa()
{
MuestraDirecciones();
MuestraMedios();
MuestraContactos();
MuestraRazonSocial();

}
void QRegistroEmpresas2::MuestraMedios()
{
char *lchrPtrCampos[]={"dato",
		       "descripcion",
		       0
		       };
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
				       QTMedComunicacion,
				       CQSEmpresa2.RegistrosSubGrupo(0,3));
SiscomDesarrollo3Qt::AjustaFilas(QTMedComunicacion);
SiscomDesarrollo3Qt::AjustaColumnas(QTMedComunicacion);
}
void QRegistroEmpresas2::MuestraContactos()
{
const char *lchrPtrConcatena[]={"nombre",
			  "apaterno",
			  "amaterno",
			  0};

SiscomDesarrollo3Qt::RegistrosALaTabla(QTContactos,
				       CQSEmpresa2.RegistrosSubGrupo(0,2),
				       lchrPtrConcatena,
				       0);
SiscomDesarrollo3Qt::AjustaFilas(QTContactos);
SiscomDesarrollo3Qt::AjustaColumnas(QTContactos);
}
void QRegistroEmpresas2::MuestraRazonSocial()
{
 QLERSocial->setText(CQSEmpresa2.CampoRegistroSubGrupo(0,0,0,"razonsocial"));
}
void QRegistroEmpresas2::MuestraDirecciones()
{
const char *lchrPtrCampos[]={"direccion",
			0
			};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
				       QTDirecciones,
				       CQSEmpresa2.RegistrosSubGrupo(0,1));
SiscomDesarrollo3Qt::AjustaFilas(QTDirecciones);
SiscomDesarrollo3Qt::AjustaColumnas(QTDirecciones);
}
