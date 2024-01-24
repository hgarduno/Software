
#ifndef __IMP_PROGRAMACIONINVENTARIO_H__
#define __IMP_PROGRAMACIONINVENTARIO_H__
#include <UIC_H_ProgramacionInventario.h>
class SiscomDatCom;
class SiscomRegistro3;
class CQSisProgramacionInventario;
class QProgramacionInventario:public ProgramacionInventario
{
 Q_OBJECT
public:
	QProgramacionInventario(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QProgramacionInventario();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3Motivo;
	CQSisProgramacionInventario *CQSProgInventario;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
	void EnviaRegistro();
	void InformaEdoRegistro();
private slots:
	void SlotMotivoInventario(SiscomRegistro3 *);
	void SlotRegistra();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QProgramacionInventario *InstanciaProgramacionInventario(void *,char **,void *,const char *,int);
#endif
