#include <IMP_AlumnoRegistrado.h>
#include<SiscomDesarrollo3Qt++.h>
#include <SiscomRegistros3.h>
#include <QCtrlEscuelas.h>
#include <qlineedit.h>
#include <qpushbutton.h>

QAlumnoRegistrado::QAlumnoRegistrado(SiscomRegistro3Lst *pSisReg3LstARegistrado,
				    SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				AlumnoRegistrado(pQWParent,pchrPtrName,pbModal,pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				SisReg3LstARegistrado(pSisReg3LstARegistrado),
				intInscribirCliente(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QAlumnoRegistrado::~QAlumnoRegistrado()
{

}

void QAlumnoRegistrado::ConectaSlots()
{
connect(QPBInscribirCliente,
	SIGNAL(clicked()),
	SLOT(SlotInscribirCliente()));
connect(QPBCancelar,
	SIGNAL(clicked()),
	SLOT(SlotCancelar()));

}
void QAlumnoRegistrado::SlotInscribirCliente()
{
   intInscribirCliente=1;
    done(1); 
}
void QAlumnoRegistrado::SlotCancelar()
{
   intInscribirCliente=0;
   done(0);
}
void QAlumnoRegistrado::IniciaVariables()
{
QCtrEscuelas->PonServidor(SisDatCom);
QCtrEscuelas->IdExpendio(chrPtrArgumentos[0]);
QCtrEscuelas->IniciaControl();
SiscomDesarrollo3Qt::FocoAControl(QPBInscribirCliente);
CopiaDatosAlumnoRegistrado();
}

SiscomRegistro3 *QAlumnoRegistrado::FormaRegistroAlumno(SiscomRegistro3 *pSisReg3Cliente)
{
SiscomRegistro3 *lSisReg3Alumno=new SiscomRegistro3 ;

(*lSisReg3Alumno) << 
new SiscomCampo3("IdPersona",(*pSisReg3Cliente)["idpersona"])	<<
new SiscomCampo3("Nombre",(*pSisReg3Cliente)["nombre"])		<<
new SiscomCampo3("APaterno",(*pSisReg3Cliente)["apaterno"])	<<
new SiscomCampo3("AMaterno",(*pSisReg3Cliente)["amaterno"])	<<
new SiscomCampo3("Grupo",(*pSisReg3Cliente)["grupo"])		<<
new SiscomCampo3("Boleta",(*pSisReg3Cliente)["boleta"])		<<
new SiscomCampo3("Correo",(*pSisReg3Cliente)["correo"])		<<
new SiscomCampo3("Telefono",(*pSisReg3Cliente)["telefono"])	<<
new SiscomCampo3("Escuela",(*pSisReg3Cliente)["escuela"]);

return lSisReg3Alumno;
}

void QAlumnoRegistrado::CopiaDatosAlumnoRegistrado()
{
SiscomRegistro3LstContenido(SisReg3LstARegistrado);
SiscomRegistro3 *lSisReg3ARegistrado=(*SisReg3LstARegistrado)[0];
SisReg3Cliente=FormaRegistroAlumno(lSisReg3ARegistrado);
QLENombre->setText((*lSisReg3ARegistrado)["nombre"]);
QLEAPaterno->setText((*lSisReg3ARegistrado)["apaterno"]);
QLEAMaterno->setText((*lSisReg3ARegistrado)["amaterno"]);
QLEGrupo->setText((*lSisReg3ARegistrado)["grupo"]);
QLEBoleta->setText((*lSisReg3ARegistrado)["boleta"]);
QLECorreo->setText((*lSisReg3ARegistrado)["correo"]);
QLECelular->setText((*lSisReg3ARegistrado)["telefono"]);
QLEEscuela->setText((*lSisReg3ARegistrado)["escuela"]);
SiscomContenidoRegistro3(SisReg3Cliente);
}
SiscomRegistro3 *QAlumnoRegistrado::Cliente()
{
  return SisReg3Cliente;
}
SiscomRegistro3 *QAlumnoRegistrado::IdCliente()
{
SiscomRegistro3 *lSisReg3Cliente=new SiscomRegistro3;
SiscomContenidoRegistro3(SisReg3Cliente);
(*lSisReg3Cliente)						<<
new SiscomCampo3("IdPersona",(*SisReg3Cliente)["IdPersona"]) 	<<
new SiscomCampo3("EdoRegistro","");
SiscomContenidoRegistro3(lSisReg3Cliente);
return lSisReg3Cliente;
}
int QAlumnoRegistrado::InscribirCliente()
{
 return intInscribirCliente;
}
void QAlumnoRegistrado::closeEvent(QCloseEvent *)
{

}
