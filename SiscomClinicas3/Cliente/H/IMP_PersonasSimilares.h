
#ifndef __IMP_PERSONASSIMILARES_H__
#define __IMP_PERSONASSIMILARES_H__
#include <UIC_H_PersonasSimilares.h>
class SiscomDatCom;
class SiscomRegistrosPro2;
class QPersonasSimilares:public PersonasSimilares
{
 Q_OBJECT
public:
	QPersonasSimilares(SiscomRegistrosPro2 *,
	   SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QPersonasSimilares();
	const char *IdPersona();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistrosPro2 *SRegistrosPro2;
	const char *chrPtrIdPersona;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraPersonas();
private slots:
	void SlotPersona(int,int,int,const QPoint &);
	void SlotCancelar();
};
#endif
