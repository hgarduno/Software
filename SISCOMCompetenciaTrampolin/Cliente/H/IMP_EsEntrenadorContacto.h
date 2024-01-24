#ifndef __IMP_ESENTRENADORCONTACTO_H__
#define __IMP_ESENTRENADORCONTACTO_H__
#include <UIC_H_EsEntrenadorContacto.h>

class QEsEntrenadorContacto:public EsEntrenadorContacto
{
 Q_OBJECT
public:
	QEsEntrenadorContacto(
	    const char *,
	    const char *,
	    const char *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=true,
	    WFlags pWFlags=0);
	~QEsEntrenadorContacto();
	const char *ObtenSiEntrenador();
private:
	const char *chrPtrNombre;
	const char *chrPtrAPaterno;
	const char *chrPtrAMaterno;
	const char *chrPtrSiEntrenador;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotSiEntrenador();
	void SlotNoEntrenador();
};
#endif
