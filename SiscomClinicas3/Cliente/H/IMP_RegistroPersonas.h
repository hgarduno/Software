#ifndef __IMP_REGISTROPERSONAS_H__
#define __IMP_REGISTROPERSONAS_H__
#include <UIC_H_RegistroPersonas.h>

/*
 * Jueves 7 De Febrero 2008
 *
 * Ventana que se utilizara para registrar
 * los empleados de la clinica, esta ventana
 * tomara de la base de datos de seguridad
 *
 *
 */
class SiscomDatCom;
class PerfilSeguridadProt2;
class CQSisPersona;
class SiscomRegistrosPro2;
class QRegistroPersonas:public RegistroPersonas
{
 Q_OBJECT
public:
	QRegistroPersonas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistroPersonas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	PerfilSeguridadProt2 *PSegProt2;
private:
	void ConectaSlots();
	void IniciaVariables();
	CQSisPersona *Empleado();
	void RegistraGenerales();
	void InformaEdoRegistro(SiscomRegistrosPro2 *);
private slots:
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoRFC();
	void SlotPasaFocoFirma();
	void SlotPasaFocoPassword();
	void SlotPasaFocoRePassword();
	void SlotPasaFocoPerfiles();
	void SlotPerfil(PerfilSeguridadProt2 *);
	void SlotRegistraGenerales();
};
extern "C" QRegistroPersonas *InstanciaRegistroPersonas(void *,char **,void *,const char *,int);
#endif
