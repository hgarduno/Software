
#ifndef __IMP_REGISTRAPROGRAMACURSO_H__
#define __IMP_REGISTRAPROGRAMACURSO_H__
#include <UIC_H_RegistraProgramaCurso.h>
class SiscomDatCom;
class QRegistraProgramaCurso:public RegistraProgramaCurso
{
 Q_OBJECT
public:
	QRegistraProgramaCurso(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QRegistraProgramaCurso();
	int BotonAceptar();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	int intBotonAceptar;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotFocoAAceptar();
	void SlotAceptar();
};
#endif
