#ifndef __MODULOVENTASMAYOREO_H__
#define __MODULOVENTASMAYOREO_H__
#include <IMP_ManejadorOrden.h>


class QModuloVentasMayoreo:public QManejadorOrden 
{
Q_OBJECT
	public:
		QModuloVentasMayoreo(SiscomDatCom *pzSisDatCom,
				     char **pchrPtrArgumentos,
				     QWidget *pQWParent,
				     const char *pchrPtrName,
				     WFlags pWFlags);
private:
	void NuevaOrden();
	void IniciaVariables();
	void TextoBotonRegistro(const char *);
};


extern "C" QModuloVentasMayoreo *InstanciaModuloVentasMayoreo(void *pSisDatCom,
                 char **pchrPtrArgumentos,
                 void *pQWParent,
                const char *pchrPtrName,
                 int pintWFlags);

#endif
