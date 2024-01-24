#include <QtExpendioOrigen.h>
#include <QCtrlExpendios.h>
#include <zSiscomQt3.h>

#include <zEmpresa.h>

#include <qpushbutton.h>
QtExpendioOrigen::QtExpendioOrigen(SiscomDatCom *pSisDatCom,
				   char **pchrPtrArgumentos,
				   QWidget *pQWParent,
				   const char *pchrPtrName,
				   bool pbModal,
				   WFlags pWFlags):
				 ExpendioOrigen(pQWParent,pchrPtrName,pbModal,pWFlags),
				 SisDatCom(pSisDatCom),
				 chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
exec();
}
void QtExpendioOrigen::IniciaVariables()
{
   IniciaControles();
   ConectaSlots();
}
void QtExpendioOrigen::ConectaSlots()
{
 
	connect(QCtrExpendios,
                SIGNAL(SignalExpendio(SiscomRegistro3 *)),
                SLOT(SlotExpendio(SiscomRegistro3 *)));
	connect(QPBAceptar,SIGNAL(clicked()),SLOT(SlotAceptar()));
}
void QtExpendioOrigen::SlotAceptar()
{
   done(1);	
}
void QtExpendioOrigen::SlotExpendio(SiscomRegistro3 *pSisReg3Expendio)
{
        Expendio(zEmpresa::DeSiscomRegistro3(pSisReg3Expendio));
	zSiscomQt3::Foco(QPBAceptar);
}
void QtExpendioOrigen::IniciaControles()
{
 QCtrExpendios->Servidor(Conexion());
 QCtrExpendios->Expendio(Argumentos()[0]);
 QCtrExpendios->IniciaControl();
}

SiscomDatCom *QtExpendioOrigen::Conexion()
{
 	return SisDatCom;
}
char **QtExpendioOrigen::Argumentos()
{
	return chrPtrArgumentos;
}
void QtExpendioOrigen::Expendio(zEmpresa *pzEmpresa)
{
	zEmExpendio=pzEmpresa;
}

zEmpresa *QtExpendioOrigen::Expendio()
{
 	return zEmExpendio;
}
