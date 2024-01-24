#include <IMP_CapturaSueldo.h>

#include <CQSisSueldos.h>
#include <SiscomDatCom.h>
#include <SiscomRegistros3.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qlineedit.h>
#include <qpushbutton.h>
QCapturaSueldo::QCapturaSueldo(SiscomRegistro3 *pSReg3Empleado,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaSueldo(pQWParent,pchrPtrName,pbModal,pWFlags),
				SReg3Empleado(pSReg3Empleado),
				intOpcion(0)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaSueldo::~QCapturaSueldo()
{

}
int QCapturaSueldo::Opcion()
{
	return intOpcion;
}
void QCapturaSueldo::ConectaSlots()
{
connect(QLESueldo,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoRegistra()));
connect(QPBRegistra,
	SIGNAL(clicked()),
	SLOT(SlotRegistra()));
connect(QPBCancela,
	SIGNAL(clicked()),
	SLOT(SlotCancela()));
}
void QCapturaSueldo::SlotPasaFocoRegistra()
{
SiscomDesarrollo3Qt::PasaFocoControl(QPBRegistra);
}
void QCapturaSueldo::SlotRegistra()
{
	intOpcion=1;
	done(1);
}
void QCapturaSueldo::SlotCancela()
{
	intOpcion=0;
	done(1);
}
void QCapturaSueldo::IniciaVariables()
{
QLEEmpleado->setText(QString((*SReg3Empleado)["nombre"])	+
		     " "					+
		     (*SReg3Empleado)["apaterno"]		+
		     " "					+
		     (*SReg3Empleado)["amaterno"]);
SiscomDesarrollo3Qt::PasaFocoControl(QLESueldo);
}

CQSisSueldo *QCapturaSueldo::Sueldo()
{
return new CQSisSueldo((*SReg3Empleado)["idpersona"],
		       "",
		       SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLESueldo));
}
