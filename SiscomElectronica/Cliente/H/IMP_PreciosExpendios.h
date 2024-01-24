
#ifndef __IMP_PRECIOSEXPENDIOS_H__
#define __IMP_PRECIOSEXPENDIOS_H__
#include <UIC_H_PreciosExpendios.h>
#include <zPreciosExpendios.h>
#include <zPrecios2Productos.h>
class zSiscomConexion;

class SiscomDatCom;

class EmpresaN;
class zEmpresa;
class zPreciosExpendio;
class QPreciosExpendios:public PreciosExpendios
{
 Q_OBJECT
public:
	QPreciosExpendios(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QPreciosExpendios();
private:
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	SiscomDatCom *SisDatCom;
	EmpresaN *EmpNExpendioO;
	EmpresaN *EmpNExpendioD;
	zEmpresa *zEmpExpO;
	zEmpresa *zEmpExpD;
	zPreciosExpendios zPreciosExps;
	zPrecios2Productos zPrecios2Prods;
	int intYaSeIniciaron;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultandoPrecios2();
	void ConsultaPrecios2();
	void MuestraPrecios2();
	void ConsultandoPrecios();
	void ConsultaPrecios();
	void MuestraPrecios();
	zEmpresa *Expendio(EmpresaN *);
	zPreciosExpendio *Precios(zEmpresa *);
	void IniciaPreciosExpendios();
	void MuestraPreciosExpendioOrigen();
	void MuestraPreciosExpendioDestino();
	void MuestraPreciosExpendio(int pintFilaInicio,int pintColumnaInicio,zSiscomRegistros *);
	void IniciaExpendios();
private slots:
	void SlotExpendioO();
	void SlotExpendioD();
	void SlotConsultaPrecios();
	void SlotConsulta2Precios();
};
extern "C" QPreciosExpendios *InstanciaPreciosExpendios(void *,char **,void *,const char *,int);
#endif
