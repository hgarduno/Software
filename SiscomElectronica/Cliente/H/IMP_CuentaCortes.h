#ifndef __IMP_CUENTACORTES_H__
#define __IMP_CUENTACORTES_H__

#include <QtCuentaCortesS.h>

class SiscomDatCom;
class zSiscomConexion;

class QCuentaCortes:public QtCuentaCortesS
{
Q_OBJECT
public:
	QCuentaCortes(SiscomDatCom *,
		      char **pchrPtrArgumentos,
		      QWidget *pQWParent,
		      const char *,
		      WFlags);
	~QCuentaCortes();
private:
	void SeleccionaExpendio();
private:
	SiscomDatCom *SisDatCom;
};

extern "C" QCuentaCortes *InstanciaCuentaCortes(void *pSisDatCom,
				     char **pchrPtrArgumentos,
				     void *pQWParent,
				     const char *pchrPtrName,
				     int pintWFlags);

#endif
