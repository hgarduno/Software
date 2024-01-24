
#ifndef __IMP_REGISTROEMPRESAS2_H__
#define __IMP_REGISTROEMPRESAS2_H__
#include <UIC_H_RegistroEmpresas2.h>
#include <CQSisEmpresas2.h>
class SiscomDatCom;
class QRegistroEmpresas2:public RegistroEmpresas2
{
 Q_OBJECT
public:
	QRegistroEmpresas2(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistroEmpresas2();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisEmpresa2 CQSEmpresa2;
	int intTEmpresa;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraContacto(CQSisContactoE *);
	void MuestraDireccion(CQSisDireccionE *);
	void MuestraMedioComunicacion(CQSisMedioComunicacionE *);
	int EmpresaRegistrada();
	void MuestraDatosEmpresa();
	void MuestraRazonSocial();
	void MuestraDirecciones();
	void MuestraMedios();
	void MuestraContactos();
private slots:
	void SlotAnexarDireccion();
	void SlotAnexarContacto();
	void SlotAnexarMedioComunicacion();
	void SlotRegistra();
	void SlotVerificaEmpresa();
	void SlotTipoEmpresa(int);
	void SlotPasaFocoTipoEmpresa();
};
extern "C" QRegistroEmpresas2 *InstanciaRegistroEmpresas2(void *,char **,void *,const char *,int);
#endif
