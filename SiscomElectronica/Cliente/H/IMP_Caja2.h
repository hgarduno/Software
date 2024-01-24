
#ifndef __IMP_CAJA2_H__
#define __IMP_CAJA2_H__
#include <UIC_H_Caja2.h>
class SiscomDatCom;
class zSiscomConexion;
class QCaja2:public Caja2
{
 Q_OBJECT
public:
	QCaja2(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCaja2();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;

private:
	void ConectaSlots();
	void IniciaVariables();
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConsultaOrdenesPendientes();
	void ConsultandoOrdenesPendientes();
	void MuestraOrdenesPendientes();
private slots:
	void SlotOrdenesPendientes();
};
extern "C" QCaja2 *InstanciaCaja2(void *,char **,void *,const char *,int);
#endif
