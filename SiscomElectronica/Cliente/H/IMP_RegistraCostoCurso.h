
#ifndef __IMP_REGISTRACOSTOCURSO_H__
#define __IMP_REGISTRACOSTOCURSO_H__
#include <UIC_H_RegistraCostoCurso.h>
class SiscomDatCom;
class SiscomRegistro3;
class CQSisCostoCurso;
class QRegistraCostoCurso:public RegistraCostoCurso
{
 Q_OBJECT
public:
	QRegistraCostoCurso(const char *pchrPtrIdProgramacion,
			    const char *pchrPtrIdCurso,
			    const char *pchrPtrCurso,
			    SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QRegistraCostoCurso();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	const char *chrPtrIdProgramacion;
	const char *chrPtrIdCurso;
	const char *chrPtrCurso;
	SiscomRegistro3 *SisReg3ExPromocion;
	CQSisCostoCurso *CQSCostoCurso;
private:
	void ConectaSlots();
	void IniciaVariables();
	void CostosCurso();
	void HabilitaAnexar();
	void FocoAPromocion();
private slots:
	void SlotExplicacionPromocion(SiscomRegistro3 *);
	void SlotFocoAAnexar();
	void SlotAnexarPrecio();
	void SlotRegistraPrecios();
	void SlotTerminar();
};
#endif
