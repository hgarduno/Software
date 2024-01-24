#include <IMP_HistorialTransferencias.h>
#include <IMP_QControlFecha.h>
#include <IMP_SelExpendios.h>
#include <CQSis3QtOperaciones.h>
#include <CQSisHisTransferencias.h>
#include <SiscomDesarrollo3Qt++.h>


#include <EmpresasN.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <qmessagebox.h>
QHistorialTransferencias *InstanciaHistorialTransferencias(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QHistorialTransferencias((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QHistorialTransferencias::QHistorialTransferencias(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				HistorialTransferencias(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				EExpendio(0)
{
IniciaVariables();
ConectaSlots();
}

QHistorialTransferencias::~QHistorialTransferencias()
{

}

void QHistorialTransferencias::ConectaSlots()
{
	connect(QCtrFecha,
		SIGNAL(Signal_EnterA_o()),
		SLOT(S_PasaFocoFechaFin()));
	connect(QCtrFechaFin,
		SIGNAL(Signal_EnterA_o()),
		SLOT(S_PasaFocoEjecuta()));
	connect(QPBConsulta,
		SIGNAL(clicked()),
		SLOT(S_Consulta()));
	connect(QTDatos,
		SIGNAL(clicked(int,int,int,const QPoint &)),
		SLOT(S_SeleccionaTransferencia(int,int,int,const QPoint &)));
	connect(QPBReEnviaTrans,
		SIGNAL(clicked()),
		SLOT(S_ReEnviaTransferencia()));

	connect(QPBSeleccionaExpendio,
		SIGNAL(clicked()),
		SLOT(S_SeleccionaExpendio()));
}
void QHistorialTransferencias::S_SeleccionaExpendio()
{
QSelExpendios lQSelExpendio(SisDatCom);

	if((EExpendio=lQSelExpendio.ObtenExpendio()))
	{
	 	QPBSeleccionaExpendio->setText(QString("Selecciona Expendio") 	+
					       "\n"				+
					       (*EExpendio)["RazonSocial"]);
		SiscomDesarrollo3Qt::PasaFoco(QPBConsulta);
	}
	  else
	  QMessageBox::information(this,
	  			   "Aplicacion",
				   "No Se Selecciono Un Expendio Valido");
}
void QHistorialTransferencias::S_ReEnviaTransferencia()
{
ReEnviandoTransferencia();
Consultando();
}
void QHistorialTransferencias::S_SeleccionaTransferencia(int pintFila,
							 int,
							 int,
							 const QPoint &)
{
  if(pintFila!=-1)
  {
   SiscomRegProTransferencia=SisReg3LstTransferencias[pintFila];
   QTDatos->selectRow(pintFila);
   QPBReEnviaTrans->setEnabled(true);
  }
}
void QHistorialTransferencias::S_PasaFocoFechaFin()
{
  SiscomDesarrollo3Qt::PasaFocoControl(QCtrFechaFin);
}
void QHistorialTransferencias::S_Consulta()
{
Consultando();
}
void QHistorialTransferencias::S_PasaFocoEjecuta()
{
QPBConsulta->setFocus();
}
void QHistorialTransferencias::Consulta()
{
CQSisHisTransferencias lCQSHTransfe(SisDatCom);
SisReg3LstTransferencias.clear();
lCQSHTransfe.MaterialTransferido((const char *)QCtrFecha->ObtenFecha(),
				 (const char *)QCtrFechaFin->ObtenFecha(),
				  chrPtrArgumentos[0],
				  EExpendio ? (*EExpendio)["IdEmpresa"] : "",
				&SisReg3LstTransferencias);
}
void QHistorialTransferencias::Consultando()
{
Consulta();
Muestra();
}
void QHistorialTransferencias::Muestra()
{
const char *lchrArrCamposM[]={
			"fechahora",
			"cantidad",
			"cveproducto",
			"origen",
			"destino",
			"estado",
			0
			};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrArrCamposM,
				     QTDatos,
				     &SisReg3LstTransferencias);
SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
}
void QHistorialTransferencias::IniciaVariables()
{
QCtrFecha->ColocaFechaHoy();
QCtrFecha->setFocus();
QCtrFechaFin->ColocaFechaHoy();
}
void QHistorialTransferencias::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
void QHistorialTransferencias::ReEnviandoTransferencia()
{
CQSis3QtOperaciones lCQS3QtReEnvTran(SisDatCom);
lCQS3QtReEnvTran.ReEnviaTransferencia(SiscomRegProTransferencia);
}
