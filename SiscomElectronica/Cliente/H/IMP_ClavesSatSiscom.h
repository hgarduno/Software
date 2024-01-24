
#ifndef __IMP_CLAVESSATSISCOM_H__
#define __IMP_CLAVESSATSISCOM_H__
#include <UIC_H_ClavesSatSiscom.h>
#include <zClaveSat.h>
class SiscomDatCom;
class zSiscomConexion;
class zSiscomRegistro;
class QClavesSatSiscom:public ClavesSatSiscom
{
 Q_OBJECT
public:
	QClavesSatSiscom(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QClavesSatSiscom();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;

	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProducto;
	zClaveSat *zCveSat;
	zClaveSat zCveSatReg;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Registrando();
	zClaveSat *ClaveSatSiscom();
	int ConsultandoClaveSat();
	void SeRegistraClave();
	void YaEstaLaClave();
private slots:
	void SlotSeleccionoProducto(zSiscomRegistro *);
	void SlotFocoAPalabraClave();
	void SlotFocoARegistrar();
	void SlotRegistrar();
	void SlotCapturandoSat(const QString &);
	void SlotCapturandoPalabraClave(const QString &);
};
extern "C" QClavesSatSiscom *InstanciaClavesSatSiscom(void *,char **,void *,const char *,int);
#endif
