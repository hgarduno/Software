
#ifndef __IMP_JUEZ_H__
#define __IMP_JUEZ_H__
#include <UIC_H_Juez.h>
class SiscomDatCom;
class CQSisJuez;
class SiscomRegistrosPro2;
class QJuez:public Juez
{
 Q_OBJECT
public:
	QJuez(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QJuez();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistrosPro2 *SRegistrosPro2;
private:
	void ConectaSlots();
	void IniciaVariables();
	void FormaDatosJuez(CQSisJuez **);
private slots:
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoTelefono();
	void SlotPasaFocoDescripcion();
	void SlotPasaFocoCorreo();
	void SlotPasaFocoRegistrar();

	void SlotRegistrar();
};
extern "C" QJuez *InstanciaJuez(void *,char **,void *,const char *,int);
#endif
