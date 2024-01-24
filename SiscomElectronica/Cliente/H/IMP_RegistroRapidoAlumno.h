
#ifndef __IMP_REGISTRORAPIDOALUMNO_H__
#define __IMP_REGISTRORAPIDOALUMNO_H__
#include <UIC_H_RegistroRapidoAlumno.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class SiscomRegistro3;
class QRegistroRapidoAlumno:public RegistroRapidoAlumno
{
 Q_OBJECT
public:
	QRegistroRapidoAlumno(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistroRapidoAlumno();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3Escuela;
	SiscomRegistro3 *SisReg3Alumno;
	SiscomRegistro3Lst SisReg3LstRegAlumno;
private:
	void ConectaSlots();
	void IniciaVariables();
	void setFocus();
	void Registra();
	SiscomRegistro3 *Alumno();
private slots:
	
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoRegGenerales();
	void SlotPasaFocoEscuelas();
	void SlotPasaFocoCorreo();
	void SlotPasaFocoCelular();
	void SlotPasaFocoTCasa();
	void SlotEscuelas(SiscomRegistro3 *);
	void SlotPasaFocoRegistraGenerales();
	void SlotRegistra();

	void SlotPasaFocoBoleta();
signals:
	void SignalRegistroAlumno(const QString &pQSBoltea);
};
extern "C" QRegistroRapidoAlumno *InstanciaRegistroRapidoAlumno(void *,char **,void *,const char *,int);
#endif
