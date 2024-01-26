#ifndef __QTIMPACCESOSERVISNTE_H__
#define __QTIMPACCESOSERVISNTE_H__
#include <cstddef>
#include <AccesoServiSNTE.h>

class zSiscomRegistros;
class QFont;
class QtImpAccesoServiSNTE:public AccesoServiSNTE
{
Q_OBJECT
public:
	QtImpAccesoServiSNTE(QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  bool pbModal=false,
			  WFlags pWFlags=false);
	int Aceptar(QFont *pQFTipoLetra);
	zSiscomRegistros *MenusSistema();
private:
	void ConectaSlots();
	int AccesoSistema();
	void IniciaVariables();
	void CargaTipoLetra();
private:
	int intAceptar;
	zSiscomRegistros *zSisRegsAcceso;
	QFont QFTipoLetra;
private slots:
	void reject();
	void SlotAceptar();
	void SlotCancelar();
	void SlotFocoAPassword();
	void SlotFocoAAceptar();
	void SlotTipoLetra();
};
#endif
