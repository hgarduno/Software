
#ifndef __IMP_CIERREDIA_H__
#define __IMP_CIERREDIA_H__
#include <UIC_H_CierreDia.h>
#include <zReporteVentas.h>
class SiscomDatCom;
class EmpresaN;
class zSiscomConexion;
class QCierreDia:public CierreDia
{
 Q_OBJECT
public:
	QCierreDia(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCierreDia();
private:
	SiscomDatCom *SisDatCom;
	zSiscomConexion *zSisConexion;
	char **chrPtrArgumentos;
	EmpresaN *EExpendio;
	zReporteVentas zRepVentas;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void Muestra();
	void MuestraEncabezado();
	const char *ObtenIdExpendio();
private slots:
	void SlotFocoAFechaFin();
	void SlotFocoAExpendio();
	void SlotSeleccionaExpendio();
	void SlotConsulta();
};
extern "C" QCierreDia *InstanciaCierreDia(void *,char **,void *,const char *,int);
#endif
