#include <IMP_ProgramandoCurso.h>
#include <IMP_RegistraProgramaCurso.h>
#include <IMP_QControlFecha.h>
#include <IMP_RegistraCostoCurso.h>

#include <QCtrlProgramacionCursos.h>
#include <QCtrlCursos.h>
#include <QCtrlRangoHora.h>
#include <CQSis3QtOperaciones.h>
#include <CQSisOpeCursos.h>
#include<SiscomDesarrollo3Qt++.h>


#include <qpushbutton.h>
#include <qtable.h>
#include <qmessagebox.h>
QProgramandoCurso *InstanciaProgramandoCurso(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QProgramandoCurso((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QProgramandoCurso::QProgramandoCurso(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ProgramandoCurso(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				SisReg3ProgramacionCurso(0)
{
IniciaVariables();
ConectaSlots();
}

QProgramandoCurso::~QProgramandoCurso()
{

}

void QProgramandoCurso::ConectaSlots()
{
connect(QPBAgregaProgramacion,
	SIGNAL(clicked()),
	SLOT(SlotAgregaProgramacion()));

connect(QPBHabilitaProgCursos,
	SIGNAL(clicked()),
	SLOT(SlotHabilitaProgramacionCursos()));


connect(QPBHabilitaCursos,
	SIGNAL(clicked()),
	SLOT(SlotHabilitaCursos()));
connect(QCtrProgramacionC,
	SIGNAL(SignalProgramacionCurso(SiscomRegistro3 *)),
	SLOT(SlotProgramacionCurso(SiscomRegistro3 *)));
connect(QCtrCursos,
	SIGNAL(SignalCurso(SiscomRegistro3 *)),
	SLOT(SlotCurso(SiscomRegistro3 *)));
connect(QCtrFechaInicio,
	SIGNAL(Signal_EnterA_o()),
	SLOT(SlotFocoAHoraInicioFin()));
connect(QCtrRangoHora,
	SIGNAL(SignalCapturoRangoHora(char *,char *)),
	SLOT(SlotCapturoRangoHora(char *,char *)));
connect(QPRegistraFecha,
	SIGNAL(clicked()),
	SLOT(SlotRegistraFecha()));
connect(QPBRegistraProgCursos,
	SIGNAL(clicked()),
	SLOT(SlotRegistraProgramacionCurso()));
connect(QPEliminaHorariosSeleccionados,
	SIGNAL(clicked()),
	SLOT(SlotEliminaHorariosSeleccionados()));
connect(QPBCCPorFecha,
	SIGNAL(clicked()),
	SLOT(SlotConsultaCursosPorFecha()));

connect(QTCursos,
	SIGNAL(selectionChanged()),
	SLOT(SlotSeSeleccionoAlgo()));
connect(QTCursos,
	SIGNAL(doubleClicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionandoCurso(int,int,int,const QPoint &)));

}
void QProgramandoCurso::SlotSeleccionandoCurso(int pintFila,
					      int pintColumna,
					      int,
					      const QPoint &)
{
SiscomEscribeLog3Qt("Datos para el costo:IdProgramacion(%s) IdCurso(%s)",
		    CQSisCuDiaHora.IdProgramacion(pintColumna,pintFila),
		    CQSisCuDiaHora.IdCurso(pintColumna,pintFila));
ConsultandoPreciosCurso(CQSisCuDiaHora.IdProgramacion(pintColumna,pintFila),
			CQSisCuDiaHora.IdCurso(pintColumna,pintFila),
			CQSisCuDiaHora.Curso(pintColumna,pintFila));
}
void QProgramandoCurso::SlotSeSeleccionoAlgo()
{
SiscomEscribeLog3Qt("Se selecciono algo de los cursos:%d", QTCursos->numSelections());
QPEliminaHorariosSeleccionados->setEnabled(VerificaAlgunaCeldaSeleccionada()); 
QPBRegistraProgCursos->setEnabled(false);
}
void QProgramandoCurso::SlotConsultaCursosPorFecha()
{
CQSis3QtOperaciones lCQS3QtOpsValidando(SisDatCom);
lCQS3QtOpsValidando.CursosProgramados((const char *)QCtrFechaInicio->ObtenFecha(),
					&CQSisCuDiaHora);
MuestraCursosProgramados();
}
void QProgramandoCurso::SlotEliminaHorariosSeleccionados()
{
int lintDias,lintHoras;
for(lintHoras=0;lintHoras<QTCursos->numRows();lintHoras++)
for(lintDias=0;lintDias<7;lintDias++)
{
   if(QTCursos->isSelected(lintHoras,lintDias))
   {
	SiscomEscribeLog3Qt("Dia %d Hora %d Eliminado",lintDias,lintHoras);
	CQSisCuDiaHora.ActualizaEstatusHorario(lintDias,lintHoras,"2");
   }
}
HabilitaProgramacionCurso();
QPEliminaHorariosSeleccionados->setEnabled(false);
}
void QProgramandoCurso::SlotRegistraProgramacionCurso()
{
CQSis3QtOperaciones lCQSis3QtProgramandoCursos(SisDatCom);
lCQSis3QtProgramandoCursos.ProgramaCurso((*SisReg3ProgramacionCurso)["idprogramacion"],
					 (*SisReg3Curso)["idcurso"],
					 (const char *)QCtrFechaInicio->ObtenFecha());
QPBRegistraProgCursos->setEnabled(false);
QPRegistraFecha->setEnabled(true);
}
void QProgramandoCurso::SlotRegistraFecha()
{
CQSisOpeCursos lCQSisOpCursos(SisDatCom);
lCQSisOpCursos.RegistraHorariosCursos(&CQSisCuDiaHora);
SiscomContenidoRegistro4Log(&CQSisCuDiaHora);
QPRegistraFecha->setEnabled(false);
SlotConsultaCursosPorFecha();
}
void QProgramandoCurso::SlotCapturoFecha()
{

}
void QProgramandoCurso::SlotCapturoRangoHora(char *pchrPtrHoraInicio,
					     char *pchrPtrHoraFin)
{
if(SisReg3ProgramacionCurso &&
   SisReg3Curso)
{
ValidandoRegistroCurso(pchrPtrHoraInicio,
		       pchrPtrHoraFin);
MuestraCursosProgramados();
}
else
QMessageBox::information(this,"Aviso del sistema","No se ha seleccionado un programa y un curso");
}
void QProgramandoCurso::SlotFocoAHoraInicioFin()
{
QCtrRangoHora->setFocus();
}
void QProgramandoCurso::SlotHabilitaCursos()
{
QCtrCursos->setEnabled(true);
QCtrCursos->setFocus();
}
void QProgramandoCurso::SlotCurso(SiscomRegistro3 *pSisReg3Curso)
{
 SisReg3Curso=pSisReg3Curso;
 QCtrCursos->setEnabled(false);
 //HabilitaProgramacionCurso();
 SiscomDesarrollo3Qt::FocoAControl(QCtrFechaInicio);
}
void QProgramandoCurso::SlotProgramacionCurso(SiscomRegistro3 *pSisReg3ProgramacionC)
{
QCtrProgramacionC->setEnabled(false);
SisReg3ProgramacionCurso=pSisReg3ProgramacionC;
//HabilitaProgramacionCurso();
SiscomDesarrollo3Qt::FocoAControl(QCtrCursos);
}
void QProgramandoCurso::SlotHabilitaProgramacionCursos()
{
QCtrProgramacionC->setEnabled(true);
}
void QProgramandoCurso::SlotAgregaProgramacion()
{
QRegistraProgramaCurso lQRPCurso(SisDatCom,chrPtrArgumentos);
if(lQRPCurso.BotonAceptar())
QCtrProgramacionC->IniciaControl();
}
void QProgramandoCurso::IniciaVariables()
{
QCtrProgramacionC->Servidor(SisDatCom);
QCtrProgramacionC->IniciaControl();
QCtrCursos->Servidor(SisDatCom);
QCtrCursos->IniciaControl();
QCtrFechaInicio->ColocaFechaHoy();
}

void QProgramandoCurso::ValidandoRegistroCurso(char *pchrPtrHoraInicio,
					       char *pchrPtrHoraFin)
{
CQSis3QtOperaciones lCQS3QtOpsValidando(SisDatCom);
lCQS3QtOpsValidando.CursosProgramadosFechaRegistro(
					(const char *)QCtrFechaInicio->ObtenFecha(),
					pchrPtrHoraInicio,
					pchrPtrHoraFin,
					(*SisReg3Curso)["idcurso"],
					(*SisReg3ProgramacionCurso)["idprogramacion"],
					(*SisReg3Curso)["curso"],
					&CQSisCuDiaHora);
SiscomContenidoRegistro4Log(&CQSisCuDiaHora);
}
void QProgramandoCurso::MuestraCursosPorHora(int pintDia,
					     SiscomRegistro3Lst *pSisReg3LstCursos)
{
SiscomRegistro3 *lSiscomReg3Dato,*lSiscomReg3DatoSig;
int lintContador=0;
 lSiscomReg3Dato=pSisReg3LstCursos->first();
 
  while(lSiscomReg3Dato)
  {
      if((lSiscomReg3DatoSig=pSisReg3LstCursos->next()))
      { 
      if(!EsHoraInicioFinCurso(lSiscomReg3Dato,lSiscomReg3DatoSig))
      {
          SiscomEscribeLog3Qt("%s (%s-%s)",
	  		     (*lSiscomReg3Dato)["Curso"],
	  		     (*lSiscomReg3Dato)["HoraInicio"],
	  		     (*lSiscomReg3Dato)["HoraFin"]);
          QTCursos->setText(lintContador,pintDia,(*lSiscomReg3Dato)["Curso"]);       
          lintContador++; 
      }
      }
     lSiscomReg3Dato=lSiscomReg3DatoSig;
  }
}

int QProgramandoCurso::EsHoraInicioFinCurso(SiscomRegistro3 *pSiscomReg3Dato,
					    SiscomRegistro3 *pSiscomReg3DatoSig)
{
const char *lchrPtrCurso=(*pSiscomReg3Dato)["Curso"],
           *lchrPtrCursoSig=(*pSiscomReg3DatoSig)["Curso"],
	   *lchrPtrHoraInicio=(*pSiscomReg3Dato)["HoraInicio"],
	   *lchrPtrHoraInicioSig=(*pSiscomReg3DatoSig)["HoraInicio"];

if(strcmp(lchrPtrCurso,lchrPtrCursoSig))
{
	if(!strcmp(lchrPtrHoraInicio,lchrPtrHoraInicioSig))
	return 1;
	else 
	return 0;

}
else
return 0;


}
void QProgramandoCurso::MuestraCursosProgramados()
{
const char *lchrPtrDia;
SiscomRegistro3Lst *lSisReg3LstCursosDia;
int lintDia=0;
   CQSisCuDiaHora.first();
    while((lchrPtrDia=CQSisCuDiaHora.Dia()))
    {
	SiscomEscribeLog3Qt("%s",lchrPtrDia);
	 MuestraCursosPorHora(lintDia,CQSisCuDiaHora.Cursos());
	CQSisCuDiaHora.SiguienteDia();
	lintDia++;
    }
SiscomDesarrollo3Qt::AjustaColumnas(QTCursos);
}

void QProgramandoCurso::HabilitaProgramacionCurso()
{
    QPBRegistraProgCursos->setEnabled(SisReg3ProgramacionCurso && SisReg3Curso);
}
int QProgramandoCurso::VerificaAlgunaCeldaSeleccionada()
{
int lintFilas,lintColumnas;
for(lintFilas=0;lintFilas<QTCursos->numRows();lintFilas++)
 for(lintColumnas=0;lintColumnas<QTCursos->numCols();lintColumnas++)
  if(QTCursos->isSelected(lintFilas,lintColumnas))
  {
  SiscomEscribeLog3Qt("Celda Seleccionada(%d,%d)",lintFilas,lintColumnas);
  return 1;
  }

return 0;
}
void QProgramandoCurso::ConsultandoPreciosCurso(const char *pchrPtrIdProgramacion,
						const char *pchrPtrIdCurso,
						const char *pchrPtrCurso)
{
if(ConsultaPreciosCurso(pchrPtrIdProgramacion,pchrPtrIdCurso))
MuestraPreciosCurso();
else
{
 QRegistraCostoCurso lQRegCosCurso(pchrPtrIdProgramacion,
 			 	   pchrPtrIdCurso,
				   pchrPtrCurso,
				   SisDatCom,
				   chrPtrArgumentos);
}
}
int QProgramandoCurso::ConsultaPreciosCurso(const char *pchrPtrIdProgramacion,
					     const char *pchrPtrIdCurso)
{
CQSis3QtOperaciones lCQS3QtOperaciones(SisDatCom);
lCQS3QtOperaciones.CostosCurso(pchrPtrIdProgramacion,pchrPtrIdCurso,&SisReg3LstCostosCurso);
return SisReg3LstCostosCurso.count();
}
void QProgramandoCurso::MuestraPreciosCurso()
{
SiscomRegistro3LstContenido(&SisReg3LstCostosCurso);
SiscomEscribeLog3Qt("Se recibieron %d Registros",SisReg3LstCostosCurso.count());
}
