#include <IMP_SelAlumno.h>
#include <IMP_RegistroRapidoAlumno.h>

#include <CQSis3QtOperaciones.h>
#include <SiscomDesarrollo3Qt++.h>

#include <Personas.h>

#include <QCtrlEscuelas.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qcombobox.h>
#include <qpushbutton.h>
QSelAlumno::QSelAlumno(SiscomDatCom *pSisDatCom, 
		       char **pchrPtrArgumentos, 
		       QWidget *pQWParent,       
		       const char *pchrPtrName,
		       WFlags pWFlags):	      
		SelAlumno(pQWParent,pchrPtrName,pWFlags),
		SisDatCom(pSisDatCom),
		chrPtrArgumentos(pchrPtrArgumentos),
		SisReg3Alumno(0),
		SisReg3Escuela(0),
		intSeleccion(0),
		QRegRapAlumno(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QSelAlumno::~QSelAlumno()
{

}

void QSelAlumno::ConectaSlots()
{
connect(QCBAlumnos,
	SIGNAL(highlighted(int)),
	SLOT(SlotSeleccionando(int)));
connect(QCBAlumnos,
	SIGNAL(activated(int)),
	SLOT(SlotSelecciono(int)));
connect(QCBEscuelas,
	SIGNAL(SignalEscuelas(SiscomRegistro3 *)),
	SLOT(SlotEscuela(SiscomRegistro3*)));
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));
connect(QPBCancelar,
	SIGNAL(clicked()),
	SLOT(SlotCancelar()));
connect(QPBRegistrarA,
	SIGNAL(clicked()),
	SLOT(SlotRegistrarAlumno()));
connect(QPBCancelarRegRap,
	SIGNAL(clicked()),
	SLOT(SlotCancelarRegRapido()));

}
void QSelAlumno::IniciaVariables()
{
   QCBEscuelas->PonServidor(SisDatCom);
   QCBEscuelas->IdExpendio(chrPtrArgumentos[0]);
   QCBEscuelas->IniciaControl();
   QLEAlumno=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBAlumnos,
   						    "QLEAlumno");

   ConsultandoAlumnos();
   SiscomDesarrollo3Qt::PasaFocoControl(QLEAlumno);
   SisReg3Alumno=SisReg3LstAlumnos[0];
   SisReg3Escuela=QCBEscuelas->EscuelaActual();
}
void QSelAlumno::closeEvent(QCloseEvent *)
{
SiscomEscribeLog3Qt("NO se puede cerrar la ventana");
}
void QSelAlumno::ConsultandoAlumnos()
{
ConsultaAlumnos();
MuestraAlumnos();
}
void QSelAlumno::ConsultaAlumnos()
{
CQSis3QtOperaciones lCQS3QtOperaciones(SisDatCom);
SisReg3LstAlumnos.clear();
QCBAlumnos->clear();
lCQS3QtOperaciones.AlumnosExpendio(chrPtrArgumentos[0],
				   &SisReg3LstAlumnos);
}
void QSelAlumno::MuestraAlumnos()
{
 SiscomDesarrollo3Qt::RegistrosAlCombo("credencial",
 					QCBAlumnos,
					&SisReg3LstAlumnos);
}

void QSelAlumno::MuestraAlumno()
{
if(SisReg3Alumno)
{
SiscomEscribeLog3Qt("Mostrando Alumno:%s",(*SisReg3Alumno)["nombre"]);
QTEAlumno->setText(QString("Alumno")			+
		   "\n"					+
		   (*SisReg3Alumno)["nombre"]		+ 
                   " "					+
		   (*SisReg3Alumno)["apaterno"]		+
		   " "					+
		   (*SisReg3Alumno)["amaterno"]		+
		   "\n"					+
		   "Boleta"				+
		   "\n"					+
		   "Escuela");
}
}
int QSelAlumno::EsAlumnoRegistrado()
{
SiscomEscribeLog3Qt("La escuela :%s",(*SisReg3Alumno)["idescuela"]);
return SisReg3Alumno &&
       strcmp((*SisReg3Alumno)["idescuela"],"0");
}
void QSelAlumno::SlotEscuela(SiscomRegistro3 *pSisReg3Escuela)
{
	SisReg3Escuela=pSisReg3Escuela;
	SiscomDesarrollo3Qt::PasaFocoControl(QPBAceptar);
}
void QSelAlumno::SlotSeleccionando(int pintAlumno)
{
   SisReg3Alumno=SisReg3LstAlumnos[pintAlumno];
   MuestraAlumno();
}

void QSelAlumno::SlotSelecciono(int pintAlumno)
{
   SisReg3Alumno=SisReg3LstAlumnos[pintAlumno];
   MuestraAlumno();
   if(EsAlumnoRegistrado())
   {
    SiscomDesarrollo3Qt::PasaFocoControl(QPBAceptar);
    QCBEscuelas->setEnabled(false);
    AsignaEscuelaAlumnoSeleccionado();
   }
    else
    {
    QCBEscuelas->setEnabled(true);
    SiscomDesarrollo3Qt::PasaFocoControl(QCBEscuelas);
    SiscomContenidoRegistro3(SisReg3Escuela);
    }
}
void QSelAlumno::SlotAceptar()
{
	if(SisReg3Alumno &&
	   SisReg3Escuela)
	{
	SiscomEscribeLog3Qt("%s %s",
			    (*SisReg3Alumno)["nombre"],
			    (*SisReg3Escuela)["nombre"]);
	intSeleccion=1;
	done(1);
	}
}
void QSelAlumno::SlotCancelar()
{
	intSeleccion=0;
	done(0);
}

void QSelAlumno::SlotRegistrarAlumno()
{
    if(!QRegRapAlumno)
    {
     QRegRapAlumno=new QRegistroRapidoAlumno(SisDatCom,chrPtrArgumentos);
     connect(QRegRapAlumno,
     	     SIGNAL(SignalRegistroAlumno(const QString &)),
	     SLOT(SlotRegistroAlumno(const QString &)));
     setExtension(QRegRapAlumno);
     setOrientation(Vertical);
   }
   HabilitaDesHabilitaControles(false);
   showExtension(true);
   SiscomDesarrollo3Qt::PasaFocoControl(QRegRapAlumno);
}
void QSelAlumno::SlotRegistroAlumno(const QString &pQSBoleta)
{
   ConsultandoAlumnos();
   showExtension(false);
   HabilitaDesHabilitaControles(true);
   SiscomDesarrollo3Qt::PasaFocoControl(QCBAlumnos);
}
void QSelAlumno::SlotCancelarRegRapido()
{
	showExtension(false);
        HabilitaDesHabilitaControles(true);

}
SiscomRegistro3 *QSelAlumno::Escuela()
{
	return SisReg3Escuela;
}
Persona *QSelAlumno::Alumno()
{
SiscomEscribeLog3Qt("El Alumno:%s -> %s ",
		    (*SisReg3Alumno)["nombre"],
		    (*SisReg3Alumno)["idpersona"]);
return new Persona(
		(*SisReg3Alumno)["nombre"],
		(*SisReg3Alumno)["apaterno"],
		(*SisReg3Alumno)["amaterno"],
		(*SisReg3Alumno)["rfc"],
		(*SisReg3Alumno)["idpersona"],
		"",
		"",
		"",
		"",
		"",
		"",
		"");
}
int QSelAlumno::Selecciono()
{
 return intSeleccion;
}
void QSelAlumno::HabilitaDesHabilitaControles(bool pbEstado)
{

     QCBEscuelas->setEnabled(pbEstado); 
     QCBAlumnos->setEnabled(pbEstado);
     QPBAceptar->setEnabled(pbEstado);
     QPBRegistrarA->setEnabled(pbEstado);
     QPBCancelar->setEnabled(pbEstado);
}

void QSelAlumno::AsignaEscuelaAlumnoSeleccionado()
{
SisReg3Escuela=new SiscomRegistro3;

(*SisReg3Escuela) 						<<
new SiscomCampo3("idescuela",(*SisReg3Alumno)["idescuela"]) 	<<
new SiscomCampo3("nombre",(*SisReg3Alumno)["escuela"]);
}
