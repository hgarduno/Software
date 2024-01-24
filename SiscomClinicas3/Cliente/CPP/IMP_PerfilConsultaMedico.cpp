#include <IMP_PerfilConsultaMedico.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlPersonas.h>
#include <QCtrlServicios.h>
#include <qpushbutton.h>
QPerfilConsultaMedico *InstanciaPerfilConsultaMedico(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QPerfilConsultaMedico((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QPerfilConsultaMedico::QPerfilConsultaMedico(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				PerfilConsultaMedico(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QPerfilConsultaMedico::~QPerfilConsultaMedico()
{

}

void QPerfilConsultaMedico::ConectaSlots()
{
	connect(QCtrPersonas,
		SIGNAL(SignalPersona(CQSisPersona *)),
		SLOT(SlotMedico(CQSisPersona *)));
	connect(QCtrSClinica,
		SIGNAL(SignalServicio(CQSisServicio *)),
		SLOT(SlotServicioGeneral(CQSisServicio *)));
	connect(QCtrSMedico,
		SIGNAL(SignalServicio(CQSisServicio *)),
		SLOT(SlotServicioMedico(CQSisServicio *)));
	connect(QPBRPerfil,
		SIGNAL(clicked()),
		SLOT(SlotRegistra()));
		

}
void QPerfilConsultaMedico::SlotRegistra()
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisOpServicio lCQSOServicio(SisDatCom);
lCQSOServicio.PerfilServicioMedico(&CQSLSPerfil,&lSRegistrosPro2);
}
void QPerfilConsultaMedico::SlotServicioGeneral(CQSisServicio *pCQSServicio)
{
	AnexaServicio(pCQSServicio);
}
void QPerfilConsultaMedico::SlotServicioMedico(CQSisServicio *pCQSSMedico)
{
	AnexaServicio(pCQSSMedico);
}
void QPerfilConsultaMedico::SlotMedico(CQSisPersona *pCQSPersona)
{
	
	CQSPersona=pCQSPersona;
	ServiciosMedico();
}
void QPerfilConsultaMedico::IniciaVariables()
{
	QCtrPersonas->PonServidor(SisDatCom);
	QCtrPersonas->NombrePerfil("Medicos");
	QCtrPersonas->IniciaControl();
	QCtrSClinica->PonServidor(SisDatCom);
	QCtrSClinica->TipoServicio("ServiciosGenerales");
	QCtrSClinica->IdMedico("");
	QCtrSClinica->IniciaControl();
}
void QPerfilConsultaMedico::ServiciosMedico()
{

	QCtrSMedico->PonServidor(SisDatCom);
	QCtrSMedico->TipoServicio("ServiciosMedico");
	QCtrSMedico->IdMedico(CQSPersona->SRegistrosPro2["IdPersona"]);
	QCtrSMedico->IniciaControl();

}
void QPerfilConsultaMedico::AnexaServicio(CQSisServicio *pCQSServicio)
{
	pCQSServicio->SiscomActualizaCampo(
			"IdMedico",
			CQSPersona->SRegistrosPro2["IdPersona"]);
	CQSLSPerfil << pCQSServicio;
	MuestraServicio(pCQSServicio);

}
void QPerfilConsultaMedico::MuestraServicio(CQSisServicio *pCQSServicio)
{
int lintContador=QTPerfil->numRows();
QTPerfil->setNumRows(lintContador+1);
SiscomAnexarRegistroALaTabla(lintContador,
			     QTPerfil,
			     QStringList() << 
			     pCQSServicio->SRegistrosPro2["Clave"]	<<
			     pCQSServicio->SRegistrosPro2["Descripcion"]);
}
