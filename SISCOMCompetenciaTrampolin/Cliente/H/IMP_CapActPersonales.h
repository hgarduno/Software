
#ifndef __IMP_CAPACTPERSONALES_H__
#define __IMP_CAPACTPERSONALES_H__
#include <UIC_H_CapActPersonales.h>
#include <SisMedioComunicacion.h>
#include <SisDirecciones.h>
class SiscomDatCom;
class CQSisEntrenador;
class QCapActPersonales:public CapActPersonales
{
 Q_OBJECT
public:
	QCapActPersonales(
	    CQSisEntrenador *,
		SiscomDatCom *,
	    const char *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCapActPersonales();
private:
	SiscomDatCom *SisDatCom;
	const char *chrPtrPersona;
	CQSisEntrenador *CQSEPersona;
	SisLstMedCom SLMCom;
	SisLstDireccion SLDireccion;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraGenerales();
	void ConsultaMedios();
	void MuestraMedios();
	void ConsultaDirecciones();
	void MuestraDirecciones();
	void ConsultandoMedios();
private slots:
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoFechaNac();
	void SlotActualizaGenerales();
	void SlotAnexarTelefono();
	void SlotAnexarCorreo();
	void SlotAnexarDireccion();
};
#endif
