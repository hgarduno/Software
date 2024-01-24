
#ifndef __IMP_RECETASCONSULTA_H__
#define __IMP_RECETASCONSULTA_H__
#include <UIC_H_RecetasConsulta.h>
class CQSisConsulta;
class QSisReceta;
class SiscomDatCom;
class QRecetasConsulta:public RecetasConsulta
{
 Q_OBJECT
public:
	QRecetasConsulta(
	   CQSisConsulta *,
	   SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QRecetasConsulta();
	int Recetas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisConsulta *CQSConsulta;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotOFolio();
	void SlotRegistroReceta(QSisReceta *);
	void SlotTerminar();
};
#endif
