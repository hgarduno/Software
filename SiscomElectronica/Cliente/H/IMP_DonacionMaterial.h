
#ifndef __IMP_DONACIONMATERIAL_H__
#define __IMP_DONACIONMATERIAL_H__
#include <UIC_H_DonacionMaterial.h>
class zDonacionMaterial;

class QDonacionMaterial:public DonacionMaterial
{
 Q_OBJECT
public:
	QDonacionMaterial(QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QDonacionMaterial();
	int Aceptar();
	zDonacionMaterial *MaterialDonado();	
private:
	int intAceptar;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotAceptar();
	void SlotCancelar();
};
extern "C" QDonacionMaterial *InstanciaDonacionMaterial(void *,char **,void *,const char *,int);
#endif
