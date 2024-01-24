
#ifndef __IMP_REGISTROEMPLEADO_H__
#define __IMP_REGISTROEMPLEADO_H__
#include <UIC_H_RegistroEmpleado.h>
class SiscomDatCom;
class CQSisEmpleado;
class PerfilSeguridadProt2;
class QRegistroEmpleado:public RegistroEmpleado
{
 Q_OBJECT
public:
	QRegistroEmpleado(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistroEmpleado();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	const char *chrPtrAplicacion;
	CQSisEmpleado *CQSEmpleado;
	PerfilSeguridadProt2 *PSeguridad;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ObtenAplicacion();
	void ObtenPerfiles();
	void Registra();
	void FormaEmpleado();
	void EjecutaRegistro();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoFirma();
	void SlotPasaFocoPassword();
	void SlotPasaFocoRePassword();
	void SlotPasaFocoRegistra();
	void SlotRegistra();
	void SlotPerfil(PerfilSeguridadProt2 *);
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QRegistroEmpleado *InstanciaRegistroEmpleado(void *,char **,void *,const char *,int);
#endif
