
#ifndef __IMP_MATERIALAREADISENO_H__
#define __IMP_MATERIALAREADISENO_H__
#include <UIC_H_MaterialAreaDiseno.h>
class zMaterialAAreaDiseno;
class QMaterialAreaDiseno:public MaterialAreaDiseno
{
 Q_OBJECT
public:
	QMaterialAreaDiseno(QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QMaterialAreaDiseno();
	int Aceptar();
	zMaterialAAreaDiseno *MaterialAAreaDiseno();
private:
	int intAceptar;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
		void SlotAceptar();
		void SlotCancelar();
};
#endif
