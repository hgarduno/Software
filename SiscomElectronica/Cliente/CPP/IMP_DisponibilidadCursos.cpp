#include <IMP_DisponibilidadCursos.h>
#include<SiscomDesarrollo3Qt++.h>
#include <QCtrlFechasCursos.h>
#include <CQSis3QtOperaciones.h>
QDisponibilidadCursos::QDisponibilidadCursos(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				DisponibilidadCursos(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QDisponibilidadCursos::~QDisponibilidadCursos()
{

}

void QDisponibilidadCursos::ConectaSlots()
{
connect(QCtrFechasCurso,
	SIGNAL(SignalFechaCurso(SiscomRegistro3 *)),
	SLOT(SlotFechaCurso(SiscomRegistro3 *)));

}
void QDisponibilidadCursos::SlotFechaCurso(SiscomRegistro3 *pSisReg3Fecha)
{
SisReg3Fecha=pSisReg3Fecha;
ConsultandoCursos();
}
void QDisponibilidadCursos::IniciaVariables()
{
QCtrFechasCurso->Servidor(SisDatCom);
QCtrFechasCurso->IdCurso("");
QCtrFechasCurso->IniciaControl();
SiscomDesarrollo3Qt::FocoAControl(QCtrFechasCurso);
}
void QDisponibilidadCursos::ConsultandoCursos()
{
ConsultaCursos();
MuestraCursos();
}

void QDisponibilidadCursos::ConsultaCursos()
{
CQSis3QtOperaciones lCQS3QtDisponibilidadC(SisDatCom);
SisReg3LstCursos.SiscomElimina();
lCQS3QtDisponibilidadC.DisponibilidadCursos((*SisReg3Fecha)["fecha"],
					    &SisReg3LstCursos);
}
void QDisponibilidadCursos::MuestraCursos()
{
const char *lchrPtrDatos[]={"curso","horainicio","horafin","cupo","disponibles",0};

SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrDatos,
					QTHorariosCurso,
					&SisReg3LstCursos);
SiscomDesarrollo3Qt::AjustaColumnas(QTHorariosCurso);
}

