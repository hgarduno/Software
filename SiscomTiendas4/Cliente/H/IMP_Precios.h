
#ifndef __IMP_PRECIOS_H__
#define __IMP_PRECIOS_H__
#include <UIC_H_Precios.h>
#include <CQSisPrecios.h>
class SiscomDatCom;
class CQSisPrecio;
class QPrecios:public Precios
{
 Q_OBJECT
public:
	QPrecios(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QPrecios();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstPrecio CQSLPrecio;
private:
	void ConectaSlots();
	void IniciaVariables();
	CQSisPrecio *FormaPrecio();
	void AnexaPrecio(CQSisPrecio *);
	void ConsultaPrecios();
	void MuestraPrecios();
	void ConsultandoPrecios();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotPasaFocoDsc();
	void SlotRegistra();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QPrecios *InstanciaPrecios(void *,char **,void *,const char *,int);
#endif
