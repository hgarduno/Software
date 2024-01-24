#ifndef __IMP_RECETA_H__
#define __IMP_RECETA_H__
#include <UIC_H_Receta.h>
#include <CQSisRecetas.h>
class SiscomDatCom;
class CQSisConsulta;
class CQSisReceta;
class QReceta:public Receta
{
 Q_OBJECT
public:
	QReceta(
	    CQSisConsulta *,
	    SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QReceta();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisConsulta *CQSConsulta;
	CQSisLstReceta CQSLReceta;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Registra();
	void Actualiza();
	CQSisReceta *FormaReceta();
	void RecetaConsulta();
private slots:
	void SlotPasaFocoReceta();
	void SlotRegistra();
};
#endif
