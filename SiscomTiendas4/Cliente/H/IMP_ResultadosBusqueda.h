
#ifndef __IMP_RESULTADOSBUSQUEDA_H__
#define __IMP_RESULTADOSBUSQUEDA_H__
#include <UIC_H_ResultadosBusqueda.h>
class SiscomDatCom;
class SiscomRegistro3Lst;
class QResultadosBusqueda:public ResultadosBusqueda
{
 Q_OBJECT
public:
	QResultadosBusqueda(SiscomRegistro3Lst *pSisReg3LstRes,
			SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QResultadosBusqueda();
	const char *Clave();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst *SisReg3LstRegreso;
	const char *chrPtrClave;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraResultados();
private slots:
	void SlotSelecciono(int,int,int,const QPoint &);
};
#endif
