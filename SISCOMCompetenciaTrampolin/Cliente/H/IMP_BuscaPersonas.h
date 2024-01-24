#ifndef __IMP_BUSCAPERSONAS_H__
#define __IMP_BUSCAPERSONAS_H__
#include <UIC_H_BuscaPersonas.h>
class SiscomDatCom;
class CQSisEntrenador;
class QBuscaPersonas:public BuscaPersonas
{
 Q_OBJECT
public:
	QBuscaPersonas(const char *,
			SiscomDatCom *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QBuscaPersonas();
	CQSisEntrenador *ObtenPersona();
private:
	SiscomDatCom *SisDatCom;
	const char *chrPtrPersona;
	CQSisEntrenador *CQSPersona;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotPersona(CQSisEntrenador *,const char *);
};
#endif
