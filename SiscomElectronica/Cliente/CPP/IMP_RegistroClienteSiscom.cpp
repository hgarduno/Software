#include <IMP_RegistroClienteSiscom.h>
#include <IMP_AlumnoRegistrado.h>
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
QRegistroClienteSiscom *InstanciaRegistroClienteSiscom(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRegistroClienteSiscom((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRegistroClienteSiscom::QRegistroClienteSiscom(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RegistroClienteSiscom(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				SisReg3Alumno(0)
{
IniciaVariables();
ConectaSlots();
}

QRegistroClienteSiscom::~QRegistroClienteSiscom()
{

}



void QRegistroClienteSiscom::ConectaSlots()
{
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
}

void QRegistroClienteSiscom::SlotRegistra()
{
 if(ValidaCamposMinimos())
 {
 SiscomEscribeLog3Qt("--------- Se registra ahora el alumno---");
 Registra();
 LiberaRegistro();
 }
}
void QRegistroClienteSiscom::SlotFocoARegistrar()
{
SiscomDesarrollo3Qt::FocoAControl(QPBRegistrar);
}
void QRegistroClienteSiscom::SlotEscuelas(SiscomRegistro3 *pSisReg3Escuela)
{
	SisReg3Escuela=pSisReg3Escuela;
	SiscomDesarrollo3Qt::FocoAControl(QLEGrupo);
}
void QRegistroClienteSiscom::SlotFocoAAPaterno()
{
 SiscomDesarrollo3Qt::FocoAControl(QLEAPaterno);
}


void QRegistroClienteSiscom::SlotFocoAAMaterno()
{
 SiscomDesarrollo3Qt::FocoAControl(QLEAMaterno);
 }
void QRegistroClienteSiscom::SlotFocoAEscuela()
{
 if(VerificaAlumnoRegistrado())
 {
	
 }
 else
 SiscomDesarrollo3Qt::FocoAControl(QCtrEscuelas);
}
void QRegistroClienteSiscom::SlotFocoAGrupo()
{
 SiscomDesarrollo3Qt::FocoAControl(QLEGrupo);
}


void QRegistroClienteSiscom::SlotFocoABoleta()
{
 SiscomDesarrollo3Qt::FocoAControl(QLEBoleta);
}
void QRegistroClienteSiscom::SlotFocoACorreo()
{
 SiscomDesarrollo3Qt::FocoAControl(QLECorreo);
}

void QRegistroClienteSiscom::SlotFocoAReCorreo()
{
 SiscomDesarrollo3Qt::FocoAControl(QLEReCorreo);
}
void QRegistroClienteSiscom::SlotFocoACelular()
{
 SiscomDesarrollo3Qt::FocoAControl(QLECelular);
}
void QRegistroClienteSiscom::SlotFocoATCasa()
{
 SiscomDesarrollo3Qt::FocoAControl(QLETCasa);
}



void QRegistroClienteSiscom::IniciaVariables()
{
SiscomDesarrollo3Qt::FocoAControl(QLENombre);
QCtrEscuelas->PonServidor(SisDatCom);
QCtrEscuelas->IdExpendio(chrPtrArgumentos[0]);
QCtrEscuelas->IniciaControl();
}


SiscomRegistro3 *QRegistroClienteSiscom::Alumno()
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

SiscomRegistro3 *QRegistroClienteSiscom::AlumnoParaValidar()
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


void QRegistroClienteSiscom::Registra()
{
CQSisPersonasProt3 lCQSisPersonasProt3(SisDatCom);
  SisReg3Alumno=Alumno();
  lCQSisPersonasProt3.Registra("RegistraAlumno2",
  			       SisReg3Alumno,
  			       &SisReg3LstRegAlumno); 
}
void QRegistroClienteSiscom::InscribeCliente()
{
SiscomEscribeLog3Qt("-------------------------");
CQSisPersonasProt3 lCQSisPersonasProt3(SisDatCom);
SiscomRegistro3 *lSisReg3Alumno;
  lSisReg3Alumno=SisReg3IdCliente;
  (*lSisReg3Alumno)+=SisReg3FechaCurso;
  (*lSisReg3Alumno)+=SisReg3CostoCurso;
 SiscomContenidoRegistro3(lSisReg3Alumno);
  lCQSisPersonasProt3.Registra("InscribeClienteCurso",
  			       lSisReg3Alumno,
  			       &SisReg3LstRegAlumno); 
}
int QRegistroClienteSiscom::VerificaAlumnoRegistrado()
{
SiscomRegistro3 *lSisReg3Alumno=AlumnoParaValidar();
SiscomRegistro3Lst lSisReg3LstValAlumno;
CQSisPersonasProt3 lCQSisProt3Valida(SisDatCom);
lSisReg3LstValAlumno.SiscomElimina();
lCQSisProt3Valida.Registra("AlumnoYaRegistrado",
			   lSisReg3Alumno,
			   &lSisReg3LstValAlumno);
if(lSisReg3LstValAlumno.count())
{
QAlumnoRegistrado lQARegistrado(&lSisReg3LstValAlumno,
				SisDatCom,
				chrPtrArgumentos);
if(lQARegistrado.InscribirCliente())
{
 SisReg3IdCliente=lQARegistrado.IdCliente();
 SiscomContenidoRegistro3(SisReg3IdCliente);
}
}

return 1;
}
int QRegistroClienteSiscom::MostrandoMensajeValidacionCamposMinimos(
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
int QRegistroClienteSiscom::MensajeValidacionCamposMinimos(SiscomRegistro3Lst *pSisReg3LstRegreso)
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
int QRegistroClienteSiscom::ValidaCamposMinimos()
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
void QRegistroClienteSiscom::LimpiaCampos()
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
void QRegistroClienteSiscom::LiberaRegistro()
{
SisReg3Curso=0;
SisReg3Alumno=0;
SisReg3FechaCurso=0;
SisReg3CostoCurso=0;
SisReg3Escuela=0;
SisReg3LstRegAlumno.SiscomElimina();
LimpiaCampos();
}
