
#ifndef __IMP_TIPOPRECIOS_H__
#define __IMP_TIPOPRECIOS_H__
#include <UIC_H_TiposPrecios.h>
#include <CQSisTipoPrecio.h>
class SiscomDatCom;
class CQSisTipoPrecio;
class QTiposPrecios:public TiposPrecios
{
 Q_OBJECT
public:
	QTiposPrecios(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QTiposPrecios();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstTipoPrecio CQSLTPrecio;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Registra();
	void ConsultandoTipoPrecios();
	void ConsultaTipoPrecios();
	void MuestraTipoPrecios();
	CQSisTipoPrecio *TipoPrecio();
private slots:
	void SlotPasaFocoDescripcion();
	void SlotPasaFocoRegistra();
	void SlotRegistra();
};
extern "C" QTiposPrecios *InstanciaTiposPrecios(void *,char **,void *,const char *,int);
#endif
