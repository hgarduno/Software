
#ifndef __IMP_CAPTURAMEDIOCOMUNICACIONE_H__
#define __IMP_CAPTURAMEDIOCOMUNICACIONE_H__
#include <UIC_H_CapturaMedioComunicacionE.h>
class SiscomDatCom;
class CQSisMedioComunicacionE;
class SisMedCom;
class QCapturaMedioComunicacionE:public CapturaMedioComunicacionE
{
 Q_OBJECT
public:
	QCapturaMedioComunicacionE(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=0,
	    WFlags pWFlags=0);
	~QCapturaMedioComunicacionE();
	CQSisMedioComunicacionE *MedioComunicacion();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SisMedCom *SisMedioCom;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotMedioComunicacion(SisMedCom *pSisMedCom);
	void SlotPasaFocoDescripcion();
	void SlotAceptar();
};
#endif
