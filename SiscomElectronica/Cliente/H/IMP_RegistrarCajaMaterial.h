
#ifndef __IMP_REGISTRARCAJAMATERIAL_H__
#define __IMP_REGISTRARCAJAMATERIAL_H__
#include <UIC_H_RegistrarCajaMaterial.h>
class zSiscomConexion;
class zCajaMaterial;
class QRegistrarCajaMaterial:public RegistrarCajaMaterial
{
 Q_OBJECT
public:
	QRegistrarCajaMaterial(QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QRegistrarCajaMaterial();
	int Aceptar();
private:
	zSiscomConexion *zSisConexion;
	zCajaMaterial *zCaMaterial;
	int intAceptar;
private:
	void ConectaSlots();
	void IniciaVariables();

	void RegistraCajaMaterial();
	void CajaMaterial();
	void HabilitaRegistrar();
private slots:
	void SlotRegistrar();
	void SlotCapturandoCaja(const QString &);
	void SlotCapturandoDescripcion();
	void SlotAceptar();
};
#endif
