#include <IMP_ActualizaDatosAlumno.h>
#include <SiscomDesarrollo3Qt++.h>

#include <QCtrlAlumnos.h>
#include <QCtrlEscuelas.h>

#include <SiscomRegistros3.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
QActualizaDatosAlumno *InstanciaActualizaDatosAlumno(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QActualizaDatosAlumno((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QActualizaDatosAlumno::QActualizaDatosAlumno(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				ActualizaDatosAlumno(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QActualizaDatosAlumno::~QActualizaDatosAlumno()
{

}
void QActualizaDatosAlumno::ConectaSlots()
{
connect(QCtrAlumnos,
	SIGNAL(SignalAlumno(SiscomRegistro3 *)),
	SLOT(SlotAlumno(SiscomRegistro3 *)));
connect(QPBActualiza,
	SIGNAL(clicked()),
	SLOT(SlotActualiza()));
connect(QPBCambiaEscuela,
	SIGNAL(clicked()),
	SLOT(SlotCambiaEscuela()));
connect(QPBSelAlumno,
	SIGNAL(clicked()),
	SLOT(SlotSeleccionaAlumno()));
connect(QLENombre,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoAPaterno()));

connect(QLEAPaterno,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoAMaterno()));
connect(QLEAMaterno,
	SIGNAL(returnPressed()),
	SLOT(SlotPreguntaCambiaEscuela()));
connect(QLEGrupo,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoBoleta()));
connect(QLEBoleta,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoCorreoE()));
connect(QLECorreoE,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoCelular()));
connect(QLECelular,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoTelefonoCasa()));
connect(QLETelefonoCasa,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoActualizar()));
}
void QActualizaDatosAlumno::SlotPreguntaCambiaEscuela()
{
int lintRegreso;
   lintRegreso=QMessageBox::question(0,
   			 "Se Actualiza la escuela",
			 "Se debera actualizar la escuela",
			 "Si",
			 "No");
   switch(lintRegreso)
   {
   	case 0:
	   QCtrEscuelas->setEnabled(true);
	   SiscomDesarrollo3Qt::PasaFocoControl(QCtrEscuelas);
	break;
	case 1:
	      SiscomDesarrollo3Qt::PasaFocoControl(QLEGrupo);
	break;
   }
SiscomEscribeLog3Qt("El Boton:%d",lintRegreso);
}
void QActualizaDatosAlumno::SlotPasaFocoAPaterno()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLEAPaterno);
}

void QActualizaDatosAlumno::SlotPasaFocoAMaterno()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLEAMaterno);
}
void QActualizaDatosAlumno::SlotPasaFocoBoleta()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLEBoleta);
}
void QActualizaDatosAlumno::SlotPasaFocoCorreoE()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLECorreoE);
}
void QActualizaDatosAlumno::SlotPasaFocoCelular()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLECelular);
}
void QActualizaDatosAlumno::SlotPasaFocoTelefonoCasa()
{
SiscomDesarrollo3Qt::PasaFocoControl(QLETelefonoCasa);
}
void QActualizaDatosAlumno::SlotPasaFocoActualizar()
{
SiscomDesarrollo3Qt::PasaFocoControl(QPBActualiza);
}
void QActualizaDatosAlumno::SlotAlumno(SiscomRegistro3 *pSisReg3Alumno)
{
SisReg3Alumno=pSisReg3Alumno;
SiscomContenidoRegistro3(SisReg3Alumno);
ConsultandoDatosAlumno();
QCtrAlumnos->setEnabled(false);
}
void QActualizaDatosAlumno::SlotActualiza()
{
 Actualizando(); 
}
void QActualizaDatosAlumno::SlotCambiaEscuela()
{

}
void QActualizaDatosAlumno::SlotSeleccionaAlumno()
{

}
void QActualizaDatosAlumno::ConsultaDatosAlumno()
{
CQSisOpAlumno lCQSOpAlumno(SisDatCom);
    CQSAlumno.Expendio((SiscomRegistro3 *)chrPtrArgumentos[5]);
    CQSAlumno.Generales(SisReg3Alumno);
lCQSOpAlumno.Alumno(&CQSAlumno);
SiscomDesarrollo3Qt::PasaFocoControl(QLENombre);

}
void QActualizaDatosAlumno::ConsultandoDatosAlumno()
{
ConsultaDatosAlumno();
MuestraDatosAlumno();
}
void QActualizaDatosAlumno::MuestraDatosAlumno()
{
 QLENombre->setText((*SisReg3Alumno)["nombre"]);
 QLEAPaterno->setText((*SisReg3Alumno)["apaterno"]);
 QLEAMaterno->setText((*SisReg3Alumno)["amaterno"]);
 QLEBoleta->setText(CQSAlumno.Boleta());
 QLEGrupo->setText(CQSAlumno.Grupo());
 QLECorreoE->setText(CQSAlumno.CorreoElectronico());
 QLECelular->setText(CQSAlumno.Celular());
 QLETelefonoCasa->setText(CQSAlumno.TelefonoCasa());
 QCtrEscuelas->Escuela(CQSAlumno.Escuela());
}
void QActualizaDatosAlumno::IniciaVariables()
{
QCtrAlumnos->Servidor(SisDatCom);
QCtrAlumnos->IdExpendio(chrPtrArgumentos[0]);
QCtrAlumnos->IniciaControl();
SiscomDesarrollo3Qt::PasaFocoControl(QCtrAlumnos);
 QCtrEscuelas->PonServidor(SisDatCom);
 QCtrEscuelas->IdExpendio(chrPtrArgumentos[0]);
 QCtrEscuelas->IniciaControl();
}

void QActualizaDatosAlumno::closeEvent(QCloseEvent *)
{
emit SignalTerminar(this);
}
void QActualizaDatosAlumno::Actualizando()
{
ActualizaDatos();
EnviaActualizacion();
}
void QActualizaDatosAlumno::ActualizaDatos()
{
CQSAlumno.Nombre(SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLENombre));
CQSAlumno.APaterno(SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEAPaterno));
CQSAlumno.AMaterno(SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEAMaterno));
CQSAlumno.Grupo(SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLEGrupo));
CQSAlumno.CorreoElectronico(SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLECorreoE));
CQSAlumno.Celular(SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLECelular));
CQSAlumno.TelefonoCasa(SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLETelefonoCasa));
}
void QActualizaDatosAlumno::EnviaActualizacion()
{
CQSisOpAlumno lCQSOAlumno(SisDatCom);
lCQSOAlumno.Actualiza(&CQSAlumno);
}
