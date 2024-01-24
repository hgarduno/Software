
#ifndef __IMP_COMPRASREGISTRADAS_H__
#define __IMP_COMPRASREGISTRADAS_H__
#include <UIC_H_ComprasRegistradas.h>
#include <CQSisCompras.h>
class SiscomDatCom;
class QComprasRegistradas:public ComprasRegistradas
{
 Q_OBJECT
public:
	QComprasRegistradas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QComprasRegistradas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstCompra CQSLCompras;
	CQSisLstCompra CQSLDCompras;
private:
	void ConectaSlots();
	void IniciaVariables();
	void EjecutaConsulta();
	void ConsultaCompras();
	void MuestraCompras();

	void ConsultandoDetalleCompra(int);
	void ConsultaDetalleCompra(int);
	void MuestraDetalleCompra();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotEjecuta();
	void SlotDetalleCompra(int,int,int,const QPoint &);
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QComprasRegistradas *InstanciaComprasRegistradas(void *,char **,void *,const char *,int);
#endif
