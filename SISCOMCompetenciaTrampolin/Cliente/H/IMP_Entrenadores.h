
#ifndef __IMP_ENTRENADORES_H__
#define __IMP_ENTRENADORES_H__
#include <UIC_H_Entrenadores.h>
class SiscomDatCom;
class CQSisGimnasio;
class CQSisEntrenador;
class QEntrenadores:public Entrenadores
{
 Q_OBJECT
public:
	QEntrenadores(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QEntrenadores();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisGimnasio *CQSGimnasio;
private:
	void ConectaSlots();
	void IniciaVariables();
	void FormaDatosEntrenador(CQSisEntrenador **);
private slots:
	void SlotGimnasio(CQSisGimnasio *);
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoTelefono();
	void SlotPasaFocoDscTelefono();
	void SlotPasaFocoCorreo();
	void SlotPasaFocoRegistrar();
	void SlotRegistra();
};
extern "C" QEntrenadores *InstanciaEntrenadores(void *,char **,void *,const char *,int);
#endif
