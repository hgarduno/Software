#include <IMP_AlumnosInscritosCurso.h>
#include<SiscomDesarrollo3Qt++.h>
#include <CQSis3QtOperaciones.h>
#include <QCtrlFechasCursos.h>
#include <QCtrlCursos.h>
QAlumnosInscritosCurso *InstanciaAlumnosInscritosCurso(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QAlumnosInscritosCurso((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QAlumnosInscritosCurso::QAlumnosInscritosCurso(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				AlumnosInscritosCurso(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QAlumnosInscritosCurso::~QAlumnosInscritosCurso()
{

}

void QAlumnosInscritosCurso::ConectaSlots()
{
connect(QCtrCursos,
	SIGNAL(SignalCurso(SiscomRegistro3 *)),
	SLOT(SlotCurso(SiscomRegistro3 *)));
connect(QCtrFechasCurso,
	SIGNAL(SignalFechaCurso(SiscomRegistro3 *)),
	SLOT(SlotFecha(SiscomRegistro3 *)));

}
void QAlumnosInscritosCurso::SlotFecha(SiscomRegistro3 *pSisReg3Fecha)
{
   SisReg3Fecha=pSisReg3Fecha;
   ConsultandoAlumnosInscritosCurso();
}
void QAlumnosInscritosCurso::SlotCurso(SiscomRegistro3 *pSisReg3Curso)
{
   SisReg3Curso=pSisReg3Curso;
   ObtenFechasCurso();
   SiscomDesarrollo3Qt::FocoAControl(QCtrFechasCurso);
}
void QAlumnosInscritosCurso::ObtenFechasCurso()
{
   QCtrFechasCurso->IdCurso((*SisReg3Curso)["idcurso"]);
   QCtrFechasCurso->IniciaControl();

}
void QAlumnosInscritosCurso::IniciaVariables()
{
QCtrCursos->Servidor(SisDatCom);
QCtrCursos->IniciaControl();
QCtrFechasCurso->Servidor(SisDatCom);
SiscomDesarrollo3Qt::FocoAControl(QCtrCursos);
}

void QAlumnosInscritosCurso::ConsultandoAlumnosInscritosCurso()
{
ConsultaAlumnosInscritosCurso();
MuestraAlumnosInscritosCurso();
}
void QAlumnosInscritosCurso::MuestraAlumnosInscritosCurso()
{
const char *lchrArrCampos[]={"nombrec","telefono","correo","costo","explicacion",0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrArrCampos,
					QTAlumnos,
					&SisReg3LstAInscritosCurso);
SiscomDesarrollo3Qt::AjustaColumnas(QTAlumnos);
}
void QAlumnosInscritosCurso::ConsultaAlumnosInscritosCurso()
{
CQSis3QtOperaciones lCQS3QtOpAInsCurso(SisDatCom);
SisReg3LstAInscritosCurso.SiscomElimina();
lCQS3QtOpAInsCurso.AlumnosInscritosCurso((*SisReg3Curso)["idcurso"],
					 (*SisReg3Fecha)["fecha"],
					 &SisReg3LstAInscritosCurso);
}

