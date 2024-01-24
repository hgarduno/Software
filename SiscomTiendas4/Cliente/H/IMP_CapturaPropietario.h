
#ifndef __IMP_CAPTURAPROPIETARIO_H__
#define __IMP_CAPTURAPROPIETARIO_H__
#include <UIC_H_CapturaPropietario.h>
class SiscomDatCom;
class CQControlNombres;
class QSisDirecciones;
class QSisTelefonos;
class CQSisCliente3Qt;
class CQSisLstDireccion;
class SisLstMedCom;
class QCapturaPropietario:public CapturaPropietario
{
 Q_OBJECT
public:
	QCapturaPropietario(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCapturaPropietario();
	void Propietario(char *pchrPtrPropietario);
	void Direcciones(CQSisLstDireccion *);
	void Telefonos(SisLstMedCom *pSLMCom);
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisCliente3Qt *CQSC3QtPropietario;
private:
	void ConectaSlots();
	void IniciaVariables();
	void RegistraPropietario();
	CQSisCliente3Qt *Propietario();
private slots:
	void SlotPasaFocoDirecciones();
	void SlotPasaFocoRegistrarPropietario();
	void SlotRegistrarP();
	void SlotAceptar();
};
#endif
