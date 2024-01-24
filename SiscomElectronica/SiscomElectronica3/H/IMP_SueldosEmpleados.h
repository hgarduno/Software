
#ifndef __IMP_SUELDOSEMPLEADOS_H__
#define __IMP_SUELDOSEMPLEADOS_H__
#include <UIC_H_SueldosEmpleados.h>
class SiscomDatCom;
class SiscomRegistro3;
class CQSisSueldo;
class QSueldosEmpleados:public SueldosEmpleados
{
 Q_OBJECT
public:
	QSueldosEmpleados(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QSueldosEmpleados();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SReg3Empleado;
	void (QSueldosEmpleados::*CambiaSueldo[2])(CQSisSueldo *);
private:
	void ConectaSlots();
	void IniciaVariables();
	void Cancela(CQSisSueldo *);
	void Registra(CQSisSueldo *);
	void closeEvent(QCloseEvent *);
private slots:
	void SlotCambia();
	void SlotEmpleado(SiscomRegistro3 *);
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QSueldosEmpleados *InstanciaSueldosEmpleados(void *,char **,void *,const char *,int);
#endif
