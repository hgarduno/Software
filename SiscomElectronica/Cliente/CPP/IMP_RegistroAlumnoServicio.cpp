#include <IMP_RegistroAlumnoServicio.h>
#include<SiscomDesarrollo3Qt++.h>
#include <QCtrlServiciosSiscom.h>
#include <QCtrlAlumnos.h>
#include <CQSis3QtOperaciones.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qtable.h>

QRegistroAlumnoServicio *InstanciaRegistroAlumnoServicio(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags)
{
	return new QRegistroAlumnoServicio((SiscomDatCom *)pSisDatCom,	
			pchrPtrArgumentos,		
			(QWidget *)pQWParent,		
			pchrPtrName,			
			pintWFlags);
}
QRegistroAlumnoServicio::QRegistroAlumnoServicio(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				RegistroAlumnoServicio(pQWParent,pchrPtrName,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
}

QRegistroAlumnoServicio::~QRegistroAlumnoServicio()
{

}

void QRegistroAlumnoServicio::ConectaSlots()
{
connect(QCtrServicios,
	SIGNAL(SignalServicio(SiscomRegistro3 *)),
	SLOT(SlotServicio(SiscomRegistro3 *)));
connect(QCtrAlumnos,
	SIGNAL(SignalAlumno(SiscomRegistro3 *)),
	SLOT(SlotAlumno(SiscomRegistro3 *)));
connect(QPBRegHEntrada,
	SIGNAL(clicked()),
	SLOT(SlotRegistraHoraEntrada()));
connect(QTAlumnosEnTaller,
	SIGNAL(doubleClicked(int,int,int,const QPoint &)),
	SLOT(SlotAsignaSalida(int,int,int,const QPoint &)));
connect(QPBRHSalida,
	SIGNAL(clicked()),
	SLOT(SlotRegistraHoraSalida()));
	
}
void QRegistroAlumnoServicio::SlotRegistraHoraSalida()
{
RegistraHoraSalida();
ConsultandoSinRegistroSalida();
}
void QRegistroAlumnoServicio::SlotAsignaSalida(int pintFila,
						int,
						int,
						const QPoint &)
{
if(pintFila!=-1)
{
QTAlumnosEnTaller->selectRow(pintFila);
SisReg3ServicioSel=SisReg3LstAlumnosEnTaller[pintFila];
}

}
void QRegistroAlumnoServicio::SlotRegistraHoraEntrada()
{
CQSis3QtOperaciones lCQS3QtOpRegistra(SisDatCom);
if((SisReg3RegEntrada=lCQS3QtOpRegistra.RegistraAlumnoServicioHoraEntrada(
			chrPtrArgumentos[0],
			SisReg3Servicio,
			SisReg3Alumno,
			SiscomDesarrollo3Qt::InformacionEdit(QTEComentarios))))
{
 /*
  *  Lunes 16 de Diciembre del 2013, fue un buen ejercio
  *  para el registro de informacion, y como se arma un registro
  *  de regreso para la respuesta, como se muestra ....
  *  pero ....
  *
  SiscomContenidoRegistro3(SisReg3RegEntrada); 
  SisReg3LstAlumnosEnTaller<<SisReg3RegEntrada;
  MuestraAlumnosEnTaller(); 
  */
 ConsultandoSinRegistroSalida();
}
}
void QRegistroAlumnoServicio::SlotServicio(SiscomRegistro3 *pSisReg3Servicio)
{
SisReg3Servicio=pSisReg3Servicio;
SiscomDesarrollo3Qt::FocoAControl(QCtrAlumnos);
}
void QRegistroAlumnoServicio::SlotAlumno(SiscomRegistro3 *pSisReg3Alumno)
{
	SisReg3Alumno=pSisReg3Alumno;
	SiscomDesarrollo3Qt::FocoAControl(QTEComentarios);
}
void QRegistroAlumnoServicio::IniciaVariables()
{
QCtrServicios->Servidor(SisDatCom);
QCtrServicios->IniciaControl();
QCtrAlumnos->Servidor(SisDatCom);
QCtrAlumnos->IdExpendio(chrPtrArgumentos[0]);
QCtrAlumnos->IniciaControl();
SiscomDesarrollo3Qt::FocoAControl(QCtrServicios);
ConsultandoSinRegistroSalida();
}
void QRegistroAlumnoServicio::MuestraAlumnosEnTaller()
{
const char *lchrArrCampos[]={"Nombre","HoraEntrada",0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrArrCampos,QTAlumnosEnTaller,&SisReg3LstAlumnosEnTaller);
SiscomDesarrollo3Qt::AjustaColumnas(QTAlumnosEnTaller);
}
void QRegistroAlumnoServicio::ConsultandoSinRegistroSalida()
{
ConsultaSinRegistroSalida();
MuestraSinRegistroSalida();
}
void QRegistroAlumnoServicio::ConsultaSinRegistroSalida()
{
CQSis3QtOperaciones lCQS3QtOpASinRegSalida(SisDatCom);
SisReg3LstAlumnosEnTaller.SiscomElimina();
lCQS3QtOpASinRegSalida.ServiciosSinRegistroSalida(
				chrPtrArgumentos[0],
				"",
				&SisReg3LstAlumnosEnTaller);
}
void QRegistroAlumnoServicio::MuestraSinRegistroSalida()
{
const char *lchrPtrCampos[]={"nombre","horaentrada",0};

SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
					QTAlumnosEnTaller,
					&SisReg3LstAlumnosEnTaller);
SiscomDesarrollo3Qt::AjustaColumnas(QTAlumnosEnTaller);
}

void QRegistroAlumnoServicio::RegistraHoraSalida()
{
CQSis3QtOperaciones lCQS3QtOpRegHoraSalida(SisDatCom);
lCQS3QtOpRegHoraSalida.RegistraSalidaAlumno(chrPtrArgumentos[0],
					    (*SisReg3ServicioSel)["idregistroservicio"]);
					  
}
