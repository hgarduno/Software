#include <IMP_VentasMedico.h>
#include<SISCOMComunicaciones++.h>
#include <QCtrlPersonas.h>
#include <QSisEstsMedico.h>
#include <IMP_QControlFecha.h>
QVentasMedico *InstanciaVentasMedico(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QVentasMedico((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QVentasMedico::QVentasMedico(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				VentasMedico(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QVentasMedico::~QVentasMedico()
{

}

void QVentasMedico::ConectaSlots()
{
	connect(QCtrMedicos,
		SIGNAL(SignalPersona(CQSisPersona *)),
		SLOT(SlotMedico(CQSisPersona *)));
}
void QVentasMedico::SlotMedico(CQSisPersona *pCQSPersona)
{
	CQSMedico=pCQSPersona;
	ReporteVentas();
}
void QVentasMedico::IniciaVariables()
{
	QCtrMedicos->PonServidor(SisDatCom);
	QCtrMedicos->NombrePerfil("Medicos");
	QCtrMedicos->IniciaControl();
	QCtrFInicio->ColocaFechaHoy();
	QCtrFFin->ColocaFechaHoy();
	QCtrEstsMedico->Servidor(SisDatCom);
}
void QVentasMedico::ReporteVentas()
{
	QCtrEstsMedico->IdMedico((*CQSMedico)["IdPersona"]);
	QCtrEstsMedico->RangoFechas(
		strdup((const char *)QCtrFInicio->ObtenFecha()),
		strdup((const char *)QCtrFFin->ObtenFecha()));
	QCtrEstsMedico->IniciaControl();
}
