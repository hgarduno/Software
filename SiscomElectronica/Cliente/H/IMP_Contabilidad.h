
#ifndef __IMP_CONTABILIDAD_H__
#define __IMP_CONTABILIDAD_H__
#include <UIC_H_Contabilidad.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class QContabilidad:public Contabilidad
{
 Q_OBJECT
public:
	QContabilidad(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QContabilidad();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SisReg3LstFacturas;
	
	SiscomRegistro3Lst SisReg3LstFactVentas;
	SiscomRegistro3Lst SisReg3LstFactCompras;
	SiscomRegistro3Lst SisReg3LstTotales;
	SiscomRegistro3Lst SisReg3LstDatRegistro;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraFacturas();
	void ObtenFacturasPortaPapeles();

	void ConsultandoContabilidad();
	void ConsultaContabilidad();
	void MuestraContabilidad();

	void MuestraFacturasCompras();
	void MuestraFacturasVentas();
	void MuestraTotales();
	void MuestraDatosRegistro();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotCopiarFacturasCompras();
	void SlotEjecutaContabilidad();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QContabilidad *InstanciaContabilidad(void *,char **,void *,const char *,int);
#endif
