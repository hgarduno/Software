
#ifndef __IMP_REGISTROCLIENTES_H__
#define __IMP_REGISTROCLIENTES_H__
#include <UIC_H_RegistroClientes.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class SiscomRegistro3;
class SiscomCampo3;

class QRegistroClientes:public RegistroClientes
{
 Q_OBJECT
public:
	QRegistroClientes(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistroClientes();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3Escuela;
	SiscomRegistro3 *SisReg3Alumno;
	SiscomRegistro3Lst SisReg3LstRegAlumno;
private:
	void ConectaSlots();
	void IniciaVariables();
	void RegistraGenerales();
	SiscomRegistro3 *Alumno();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoRegGenerales();
	void SlotPasaFocoEscuelas();
	void SlotEscuelas(SiscomRegistro3 *);
	void SlotPasaFocoRegistraGenerales();
	void SlotRegistraGenerales();

	void SlotPasaFocoBoleta();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QRegistroClientes *InstanciaRegistroClientes(void *,char **,void *,const char *,int);
#endif
