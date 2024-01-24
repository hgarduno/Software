
#ifndef __IMP_MANDATPERSONALES_H__
#define __IMP_MANDATPERSONALES_H__
#include <UIC_H_ManDatPersonales.h>
#include <CQSisBuscaPersonas.h>
class SiscomDatCom;

class QManDatPersonales:public ManDatPersonales
{
 Q_OBJECT
public:
	QManDatPersonales(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QManDatPersonales();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstBuscaPersona CQSLBPersona;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ObtenPersonas();
	void MuestraPersonas();
	void EliminaPersonasAnterior();
	void MuestraRegistroTrabajo(int );
	void Actualiza();
private slots:
	void SlotSeleccionaPersonas();
	void SlotSeleccionandoPersona(int,int,int,const QPoint &);
	void SlotActualiza();
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoActualizar();
};
extern "C" QManDatPersonales *InstanciaManDatPersonales(void *,char **,void *,const char *,int);
#endif
