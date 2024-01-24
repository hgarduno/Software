
#ifndef __IMP_GIMNASTAS_H__
#define __IMP_GIMNASTAS_H__
#include <UIC_H_Gimnastas.h>
class SiscomDatCom;
class CQSisGimnasio;
class CQSisGimnasta;
class QGimnastas:public Gimnastas
{
 Q_OBJECT
public:
	QGimnastas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QGimnastas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisGimnasio *CQSGimnasio;
private:
	void ConectaSlots();
	void IniciaVariables();
	void FormaDatosGimnasta(CQSisGimnasta **);
	void EstanTodosLosDatos();
private slots:

	void SlotGimnasio(CQSisGimnasio *);
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoTelefono();
	void SlotPasaFocoDscTelefono();
	void SlotPasaFocoCorreo();
	void SlotPasaFocoRegistrar();
	void SlotRegistra();
	void SlotPasaFocoFechaNac();
};
extern "C" QGimnastas *InstanciaGimnastas(void *,char **,void *,const char *,int);
#endif
