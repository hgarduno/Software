#include <IMP_RegistroAlumno.h>
#include <IMP_AlumnoRegistrado.h>
#include<SiscomDesarrollo3Qt++.h>
#include <QCtrlEscuelas.h>
#include <CQSis3QtOperaciones.h>
#include <CQSisPersonasProt3.h>
#include <qlineedit.h>
#include <qpushbutton.h>

#include <qmessagebox.h>


QRegistroAlumno *InstanciaRegistroAlumno(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRegistroAlumno((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRegistroAlumno::QRegistroAlumno(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RegistroAlumno(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QRegistroAlumno::~QRegistroAlumno()
{

}

void QRegistroAlumno::ConectaSlots()
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


connect(QCtrEscuelas,
	SIGNAL(SignalEscuelas(SiscomRegistro3 *)),
	SLOT(SlotEscuelas(SiscomRegistro3 *)));


connect(QLETCasa,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoANoCredencial()));
connect(QLENoCredencial,
	SIGNAL(returnPressed()),
	SLOT(SlotFocoARegistrar()));

connect(QPBRegistrar,
	SIGNAL(clicked()),
	SLOT(SlotRegistra()));
}
void QRegistroAlumno::SlotFocoANoCredencial()
{
SiscomDesarrollo3Qt::FocoAControl(QLENoCredencial);
}
void QRegistroAlumno::SlotRegistra()
{
 if(ValidaCamposMinimos())
 {
 Registra();
 //LiberaRegistro();
 }
}
void QRegistroAlumno::SlotEscuelas(SiscomRegistro3 *pSisReg3Escuela)
{
	SisReg3Escuela=pSisReg3Escuela;
	SiscomDesarrollo3Qt::FocoAControl(QLEGrupo);
}
void QRegistroAlumno::SlotFocoAAPaterno()
{
 SiscomDesarrollo3Qt::FocoAControl(QLEAPaterno);
}


void QRegistroAlumno::SlotFocoAAMaterno()
{
 SiscomDesarrollo3Qt::FocoAControl(QLEAMaterno);
 }
void QRegistroAlumno::SlotFocoAEscuela()
{
 if(VerificaAlumnoRegistrado())
 {
	
 }
 else
 SiscomDesarrollo3Qt::FocoAControl(QCtrEscuelas);
}
void QRegistroAlumno::SlotFocoAGrupo()
{
 SiscomDesarrollo3Qt::FocoAControl(QLEGrupo);
}


void QRegistroAlumno::SlotFocoABoleta()
{
 SiscomDesarrollo3Qt::FocoAControl(QLEBoleta);
}
void QRegistroAlumno::SlotFocoACorreo()
{
 SiscomDesarrollo3Qt::FocoAControl(QLECorreo);
}

void QRegistroAlumno::SlotFocoAReCorreo()
{
 SiscomDesarrollo3Qt::FocoAControl(QLEReCorreo);
}
void QRegistroAlumno::SlotFocoACelular()
{
 SiscomDesarrollo3Qt::FocoAControl(QLECelular);
}
void QRegistroAlumno::SlotFocoATCasa()
{
 SiscomDesarrollo3Qt::FocoAControl(QLETCasa);
}

void QRegistroAlumno::SlotFocoARegistrar()
{
SiscomDesarrollo3Qt::FocoAControl(QPBRegistrar);
}

void QRegistroAlumno::IniciaVariables()
{

QCtrEscuelas->PonServidor(SisDatCom);
QCtrEscuelas->IdExpendio(chrPtrArgumentos[0]);
QCtrEscuelas->IniciaControl();
SiscomDesarrollo3Qt::FocoAControl(QLENombre);
}


int QRegistroAlumno::VerificaAlumnoRegistrado()
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
}

SiscomRegistro3 *QRegistroAlumno::AlumnoParaValidar()
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

int QRegistroAlumno::MostrandoMensajeValidacionCamposMinimos(
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
int QRegistroAlumno::MensajeValidacionCamposMinimos(SiscomRegistro3Lst *pSisReg3LstRegreso)
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
int QRegistroAlumno::ValidaCamposMinimos()
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
}

void QRegistroAlumno::Registra()
{
CQSisPersonasProt3 lCQSisPersonasProt3(SisDatCom);
  SisReg3Alumno=Alumno();
  (*SisReg3Alumno)+=Credencial();
  lCQSisPersonasProt3.Registra("RegistraAlumnoSiscom",
  			       SisReg3Alumno,
  			       &SisReg3LstRegAlumno); 
}

void QRegistroAlumno::LiberaRegistro()
{
SisReg3Alumno=0;
SisReg3Escuela=0;
SisReg3LstRegAlumno.SiscomElimina();
LimpiaCampos();
}

SiscomRegistro3 *QRegistroAlumno::Alumno()
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

void QRegistroAlumno::LimpiaCampos()
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

SiscomRegistro3 *QRegistroAlumno::Credencial()
{
return SiscomDesarrollo3Qt::Registro3("NoCredencial,	\
				       Nada",
				       SiscomDesarrollo3Qt::InformacionEdit(QLENoCredencial),
				       "");

}
