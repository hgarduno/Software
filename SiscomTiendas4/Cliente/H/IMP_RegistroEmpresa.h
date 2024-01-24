
#ifndef __IMP_REGISTROEMPRESA_H__
#define __IMP_REGISTROEMPRESA_H__
#include <UIC_H_RegistroEmpresa.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class SiscomRegistro3;
class SisMedCom;
class CQSisEmpresa;
class QRegistroEmpresa:public RegistroEmpresa
{
 Q_OBJECT
public:
	QRegistroEmpresa(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistroEmpresa();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	/* 
	 * Queretaro 12 Enero 2010
	 * Por culpa de la nueva version esta variable en el 
	 * singal para obtener la direccion ya no se usa
	 *
	SisDireccion *SDireccion;
	*/
	SiscomRegistro3 *SisReg3Direccion;
	SisMedCom *SMCom;
	const char *chrPtrTipo;
	SiscomRegistro3LstLst SisReg3LstLstEmpReg;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Registra();
	CQSisEmpresa *FormaEmpresa();
	void closeEvent(QCloseEvent *);
	int EmpresaRegistrada();
	void InformacionEmpresa();
	void MuestraDirecciones();
	void MuestraContactos();
	void MuestraComunicacion();
	const char *IdEmpresaRegistrada();
	
private slots:
	void SlotPasaFocoDireccion();
	void SlotDireccion(SiscomRegistro3 *);
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoDscContacto();
	void SlotPasaFocoDscTelefono();
	void SlotRegistra();
	void SlotMedComunicacion(SisMedCom *);
	void SlotTipo(int);
	void SlotMantenimientoDirecciones(int pintNFila,
					  int pintNColumna,
					  const QPoint &pQPPosicion);
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QRegistroEmpresa *InstanciaRegistroEmpresa(void *,char **,void *,const char *,int);
#endif
