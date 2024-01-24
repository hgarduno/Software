#include <IMP_RegistroAlumnoCurso.h>
#include <IMP_DisponibilidadCursos.h>
#include <IMP_AlumnoRegistrado.h>
#include <CQSisImprimeComprobantePagoCurso.h>
#include <CQSisOpeImprimeComprobanteCurso.h>
#include<SiscomDesarrollo3Qt++.h>
#include <QCtrlCursos.h>
#include <QCtrlEscuelas.h>
#include <CQSis3QtOperaciones.h>
#include <CQSisPersonasProt3.h>
#include <qlayout.h>
#include <qframe.h>
#include <qtable.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
QRegistroAlumnoCurso *InstanciaRegistroAlumnoCurso(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRegistroAlumnoCurso((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRegistroAlumnoCurso::QRegistroAlumnoCurso(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RegistroAlumnoCurso(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				SisReg3IdCliente(0)
{
IniciaVariables();
ConectaSlots();
}

QRegistroAlumnoCurso::~QRegistroAlumnoCurso()
{

}

void QRegistroAlumnoCurso::ConectaSlots()
{
connect(QCtrCursos,
	SIGNAL(SignalCurso(SiscomRegistro3*)),
	SLOT(SlotCurso(SiscomRegistro3 *)));
connect(QTHorariosCurso,
	SIGNAL(doubleClicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionaHorarioCurso(int,int,int,const QPoint &)));

connect(QTCostos,
	SIGNAL(doubleClicked(int,int,int,const QPoint &)),
	SLOT(SlotSeleccionaCostoCurso(int,int,int,const QPoint &)));


connect(QLENombre,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoAAPaterno()));


connect(QLEAPaterno,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoAAMaterno()));
connect(QLEAMaterno,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoAEscuela()));
connect(QCtrEscuelas,
	SIGNAL(SignalEscuelas(SiscomRegistro3 *)),
	SLOT(SlotEscuelas(SiscomRegistro3 *)));

connect(QLEGrupo,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoABoleta()));


connect(QLEBoleta,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoACorreo()));
connect(QLECorreo,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoAReCorreo()));
connect(QLEReCorreo,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoACelular()));
connect(QLECelular,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoATCasa()));
connect(QLETCasa,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoARegistrar()));

connect(QPBRegistrar,
	SIGNAL(clicked()),
	SLOT(SlotRegistra()));
connect(QPBDisponibilidadC,
	SIGNAL(clicked()),
	SLOT(SlotDisponibilidadCursos()));
connect(QPBImpComprobante,
	SIGNAL(clicked()),
	SLOT(SlotImprimeComprobante()));
connect(QPBInscribeOAlumno,
	SIGNAL(clicked()),
	SLOT(SlotInscribeOAlumno()));
}
void QRegistroAlumnoCurso::SlotInscribeOAlumno()
{
LiberaRegistro();
QFDatosAlumno->setEnabled(false);
SiscomDesarrollo3Qt::FocoAControl(QCtrCursos);
}
void QRegistroAlumnoCurso::SlotImprimeComprobante()
{
CQSisOpeImprimeComprobanteCurso lCQSOICCurso(SisDatCom);

CQSisImprimeComprobantePagoCurso lCQICPCurso(
				 SisReg3Alumno,
				 SisReg3Curso,
				 SisReg3CostoCurso);
lCQSOICCurso.ImprimeComprobante(&lCQICPCurso);
}
void QRegistroAlumnoCurso::SlotDisponibilidadCursos()
{
QDisponibilidadCursos lQDCursos(SisDatCom,
				chrPtrArgumentos);
}
void QRegistroAlumnoCurso::SlotRegistra()
{
if(!SisReg3IdCliente)
{
 if(ValidaCamposMinimos())
 {
 Registra();
 SiscomDesarrollo3Qt::FocoAControl(QCtrCursos);
 QFDatosAlumno->setEnabled(false);
 QPBRegistrar->setEnabled(false);
 QPBImpComprobante->setEnabled(true);
 SiscomDesarrollo3Qt::FocoAControl(QPBImpComprobante);
 }
}
else
{
InscribeCliente();
 QPBImpComprobante->setEnabled(true);
 QPBRegistrar->setEnabled(false);
}
}
void QRegistroAlumnoCurso::SlotFocoARegistrar()
{
SiscomDesarrollo3Qt::FocoAControl(QPBRegistrar);
}
void QRegistroAlumnoCurso::SlotEscuelas(SiscomRegistro3 *pSisReg3Escuela)
{
	SisReg3Escuela=pSisReg3Escuela;
	SiscomDesarrollo3Qt::FocoAControl(QLEGrupo);
}
void QRegistroAlumnoCurso::SlotFocoAAPaterno()
{
 SiscomDesarrollo3Qt::FocoAControl(QLEAPaterno);
}


void QRegistroAlumnoCurso::SlotFocoAAMaterno()
{
 SiscomDesarrollo3Qt::FocoAControl(QLEAMaterno);
 }
void QRegistroAlumnoCurso::SlotFocoAEscuela()
{
 if(VerificaAlumnoRegistrado())
 {
	
 }
 else
 SiscomDesarrollo3Qt::FocoAControl(QCtrEscuelas);
}
void QRegistroAlumnoCurso::SlotFocoAGrupo()
{
 SiscomDesarrollo3Qt::FocoAControl(QLEGrupo);
}


void QRegistroAlumnoCurso::SlotFocoABoleta()
{
 SiscomDesarrollo3Qt::FocoAControl(QLEBoleta);
}
void QRegistroAlumnoCurso::SlotFocoACorreo()
{
 SiscomDesarrollo3Qt::FocoAControl(QLECorreo);
}

void QRegistroAlumnoCurso::SlotFocoAReCorreo()
{
 SiscomDesarrollo3Qt::FocoAControl(QLEReCorreo);
}
void QRegistroAlumnoCurso::SlotFocoACelular()
{
 SiscomDesarrollo3Qt::FocoAControl(QLECelular);
}
void QRegistroAlumnoCurso::SlotFocoATCasa()
{
 SiscomDesarrollo3Qt::FocoAControl(QLETCasa);
}
void QRegistroAlumnoCurso::SlotSeleccionaHorarioCurso(int pintFila,
						      int,
						      int,
						      const QPoint &)
{
if(pintFila!=-1)
{
QTHorariosCurso->selectRow(pintFila);
SisReg3FechaCurso=SisReg4FechasCurso.RegistroSubGrupo(pintFila,0,0);
ConsultandoCostosCurso(SisReg3FechaCurso);
}
}

void QRegistroAlumnoCurso::SlotSeleccionaCostoCurso(int pintFila,
						    int,
						    int,
						    const QPoint &)
{
if(pintFila!=-1)
{
 QTCostos->selectRow(pintFila);
 SisReg3CostoCurso=SisReg3LstCostosCurso[pintFila];
 SiscomContenidoRegistro3(SisReg3CostoCurso);
 if(SisReg3FechaCurso &&
    SisReg3CostoCurso)
 {
	QFDatosAlumno->setEnabled(true);
	SiscomDesarrollo3Qt::FocoAControl(QLENombre);
 }
}

}
void QRegistroAlumnoCurso::SlotCurso(SiscomRegistro3 *pSisReg3Curso)
{
	SisReg3Curso=pSisReg3Curso; 
	ConsultandoFechasCursos();
 	QPBImpComprobante->setEnabled(false);
 	QPBRegistrar->setEnabled(true);


}

void QRegistroAlumnoCurso::IniciaVariables()
{
QFDatosAlumno->setEnabled(false);
QCtrCursos->Servidor(SisDatCom);
QCtrCursos->IniciaControl();
SiscomDesarrollo3Qt::FocoAControl(QCtrCursos);

QCtrEscuelas->PonServidor(SisDatCom);
QCtrEscuelas->IdExpendio(chrPtrArgumentos[0]);
QCtrEscuelas->IniciaControl();

QPBImpComprobante->setEnabled(false);
}

void QRegistroAlumnoCurso::ConsultandoFechasCursos()
{
ConsultaFechasCurso();
MuestraFechasCurso();
}

void QRegistroAlumnoCurso::ConsultaFechasCurso()
{
CQSis3QtOperaciones lCQS3QtOpFechasCurso(SisDatCom);
SisReg4FechasCurso.SiscomLimpia();
lCQS3QtOpFechasCurso.FechasCostosCursos(chrPtrArgumentos[0],
				  (*SisReg3Curso)["idcurso"],
				  &SisReg4FechasCurso);
}
void QRegistroAlumnoCurso::MuestraFechasCurso()
{
const char *lchrArrRegistro[]={"fecha",
			"horainicio",
			 "horafin",
			 "cupo",
			 "disponibles",
			 0};
SiscomDesarrollo3Qt::RegsPrincipal4ALaTabla(lchrArrRegistro,
					QTHorariosCurso,
					&SisReg4FechasCurso);
SiscomDesarrollo3Qt::AjustaColumnas(QTHorariosCurso);
}

SiscomRegistro3 *QRegistroAlumnoCurso::Alumno()
{
SiscomRegistro3 *lSisReg3Persona=new SiscomRegistro3;

(*lSisReg3Persona)						<<
new SiscomCampo3("IdPersona","") 				<<
new SiscomCampo3("EdoRegistro","") 				<<
new SiscomCampo3("IdExpendio",chrPtrArgumentos[0])		<<
    SiscomDesarrollo3Qt::Campo3Edit("Boleta",QLEBoleta)		<<
    SiscomDesarrollo3Qt::Campo3Edit("Grupo",QLEGrupo)		<<
    SiscomDesarrollo3Qt::Campo3Edit("Nombre",QLENombre)		<<
    SiscomDesarrollo3Qt::Campo3Edit("APaterno",QLEAPaterno)	<<
    SiscomDesarrollo3Qt::Campo3Edit("AMaterno",QLEAMaterno)	<<
    SiscomDesarrollo3Qt::Campo3Edit("Correo",QLECorreo)		<<
    SiscomDesarrollo3Qt::Campo3Edit("ReCorreo",QLEReCorreo)	<<
    SiscomDesarrollo3Qt::Campo3Edit("Celular",QLECelular)	<<
    SiscomDesarrollo3Qt::Campo3Edit("Telefono",QLETCasa);
(*lSisReg3Persona)+=SisReg3Escuela;
return lSisReg3Persona;
}

SiscomRegistro3 *QRegistroAlumnoCurso::AlumnoParaValidar()
{
SiscomRegistro3 *lSisReg3Persona=new SiscomRegistro3;

(*lSisReg3Persona)						<<
new SiscomCampo3("IdPersona","") 				<<
new SiscomCampo3("EdoRegistro","") 				<<
    SiscomDesarrollo3Qt::Campo3Edit("Nombre",QLENombre)		<<
    SiscomDesarrollo3Qt::Campo3Edit("APaterno",QLEAPaterno)	<<
    SiscomDesarrollo3Qt::Campo3Edit("AMaterno",QLEAMaterno);
return lSisReg3Persona;
}


void QRegistroAlumnoCurso::Registra()
{
CQSisPersonasProt3 lCQSisPersonasProt3(SisDatCom);
  SisReg3Alumno=Alumno();
  (*SisReg3Alumno)+=SisReg3FechaCurso;
  (*SisReg3Alumno)+=SisReg3CostoCurso;
  (*SisReg3Alumno)+=SisReg3Curso;
  lCQSisPersonasProt3.Registra("RegistraAlumnoCurso",
  			       SisReg3Alumno,
  			       &SisReg3LstRegAlumno); 
}
void QRegistroAlumnoCurso::InscribeCliente()
{
CQSisPersonasProt3 lCQSisPersonasProt3(SisDatCom);
SiscomRegistro3 *lSisReg3Alumno;
  lSisReg3Alumno=SisReg3IdCliente;
  (*lSisReg3Alumno)+=SisReg3Alumno;
  (*lSisReg3Alumno)+=SisReg3FechaCurso;
  (*lSisReg3Alumno)+=SisReg3CostoCurso;
 SiscomContenidoRegistro3(lSisReg3Alumno);
  lCQSisPersonasProt3.Registra("InscribeClienteCurso",
  			       lSisReg3Alumno,
  			       &SisReg3LstRegAlumno); 
}
int QRegistroAlumnoCurso::VerificaAlumnoRegistrado()
{
SiscomRegistro3 *lSisReg3Alumno=AlumnoParaValidar();
SiscomRegistro3Lst lSisReg3LstValAlumno;
CQSisPersonasProt3 lCQSisProt3Valida(SisDatCom);
lSisReg3LstValAlumno.SiscomElimina();
lCQSisProt3Valida.Registra("AlumnoYaRegistrado",
			   lSisReg3Alumno,
			   &lSisReg3LstValAlumno);
SiscomEscribeLog3Qt("El numero de registros que coinciden es :%d",
		    lSisReg3LstValAlumno.count());
if(lSisReg3LstValAlumno.count())
{
QAlumnoRegistrado lQARegistrado(&lSisReg3LstValAlumno,
				SisDatCom,
				chrPtrArgumentos);
if(lQARegistrado.InscribirCliente())
{
 SisReg3IdCliente=lQARegistrado.IdCliente();
 SisReg3Alumno=lQARegistrado.Cliente();
 QFDatosAlumno->setEnabled(false);
 SiscomDesarrollo3Qt::FocoAControl(QPBRegistrar);
}
}
else
return 0;
}
int QRegistroAlumnoCurso::MostrandoMensajeValidacionCamposMinimos(
				const char *pchrPtrValidacion,
				SiscomRegistro3Lst *pSisReg3LstRegreso)
{
SiscomRegistro3 *lSisReg3Regreso=(*pSisReg3LstRegreso)[0];
if(!strcmp((*lSisReg3Regreso)[pchrPtrValidacion],"0"))
{
QMessageBox::warning(this,"Aviso Sistema",(*lSisReg3Regreso)["Mensaje"]);
return 0;
}
else
return 1;
}
int QRegistroAlumnoCurso::MensajeValidacionCamposMinimos(SiscomRegistro3Lst *pSisReg3LstRegreso)
{
if(!MostrandoMensajeValidacionCamposMinimos("ValidacionNombre",pSisReg3LstRegreso))
{
 SiscomDesarrollo3Qt::FocoAControl(QLENombre);
 return 0;
}
else
if(!MostrandoMensajeValidacionCamposMinimos("ValidacionCorreo",pSisReg3LstRegreso))
{
  SiscomDesarrollo3Qt::FocoAControl(QLECorreo);
  return 0;
}
else
if(!MostrandoMensajeValidacionCamposMinimos("ValidacionTelefonos",pSisReg3LstRegreso))
{
  SiscomDesarrollo3Qt::FocoAControl(QLECelular);
  return 0;
}
else
return 1;
}
int QRegistroAlumnoCurso::ValidaCamposMinimos()
{
SiscomRegistro3 *lSisReg3Alumno=Alumno();
SiscomRegistro3Lst lSisReg3LstValAlumno;
CQSisPersonasProt3 lCQSisProt3Valida(SisDatCom);
lSisReg3LstValAlumno.SiscomElimina();
lCQSisProt3Valida.Registra("ValidaCamposMinimosRegistroAlumno",
			   lSisReg3Alumno,
			   &lSisReg3LstValAlumno);
SiscomRegistro3LstContenido(&lSisReg3LstValAlumno);
return MensajeValidacionCamposMinimos(&lSisReg3LstValAlumno);
return 0;
}
void QRegistroAlumnoCurso::LimpiaCampos()
{
QLENombre->clear();
QLEAPaterno->clear();
QLEAMaterno->clear();
QLEGrupo->clear();
QLEBoleta->clear();
QLECorreo->clear();
QLEReCorreo->clear();
QLECelular->clear();
QLETCasa->clear();
}
void QRegistroAlumnoCurso::LiberaRegistro()
{
SisReg3Curso=0;
SisReg3Alumno=0;
SisReg3FechaCurso=0;
SisReg3CostoCurso=0;
SisReg3Escuela=0;
SisReg3LstRegAlumno.SiscomElimina();
LimpiaCampos();
}

void QRegistroAlumnoCurso::ConsultandoCostosCurso(SiscomRegistro3 *pSisReg3FechaCurso)
{
SiscomContenidoRegistro3(pSisReg3FechaCurso);
ConsultaCostosCurso(pSisReg3FechaCurso);
MuestraCostosCurso();
}

void QRegistroAlumnoCurso::ConsultaCostosCurso(SiscomRegistro3 *pSisReg3FechaCurso)
{
SisReg3LstCostosCurso.SiscomElimina();
CQSis3QtOperaciones lCQS3QtOpCostosCurso(SisDatCom);
lCQS3QtOpCostosCurso.CostosCurso(chrPtrArgumentos[0],
			       pSisReg3FechaCurso,
			       &SisReg3LstCostosCurso);
}

void QRegistroAlumnoCurso::MuestraCostosCurso()
{
const char *lchrArrCostos[]={"explicacion","costo",0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrArrCostos,
					QTCostos,
					&SisReg3LstCostosCurso);
SiscomDesarrollo3Qt::AjustaColumnas(QTCostos);
}
