
#ifndef __IMP_PRODUCTOSINVENTARIAR_H__
#define __IMP_PRODUCTOSINVENTARIAR_H__
#include <UIC_H_ProductosInventariar.h>
class SiscomDatCom;
class QProductosInventariar:public ProductosInventariar
{
 Q_OBJECT
public:
	QProductosInventariar(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QProductosInventariar();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
private slots:
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QProductosInventariar *InstanciaProductosInventariar(void *,char **,void *,const char *,int);
#endif
