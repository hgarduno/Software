
#ifndef __IMP_GIMNASIO_H__
#define __IMP_GIMNASIO_H__
#include <UIC_H_Gimnasio.h>
class SiscomDatCom;
class SisDireccion;
class CQSisLstGimnasio;
class QGimnasio:public Gimnasio
{
 Q_OBJECT
public:
	QGimnasio(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QGimnasio();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SisDireccion *SisPtrDir;
	const char *chrPtrValNmbGimnasio;
	const char *chrPtrEsEntrenador;
private:
	void ConectaSlots();
	void IniciaVariables();
	void RegistraGimnasio();
	void DespliegaEdoRegistro(CQSisLstGimnasio *);
	const char *EsEntrenadorElContacto();
private slots:
	void SlotRegistraGimnasio();
	void SlotCapturoDireccion(SisDireccion *);
	void SlotPasaFocoDescripcion();
	void SlotPasaFocoNombre();
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoRegistrar();
	void SlotPasaFocoDireccion();
};
extern "C" QGimnasio *InstanciaGimnasio(void *,char **,void *,const char *,int);
#endif
