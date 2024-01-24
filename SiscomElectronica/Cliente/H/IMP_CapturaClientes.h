
#ifndef __IMP_CAPTURACLIENTES_H__
#define __IMP_CAPTURACLIENTES_H__
#include <UIC_H_CapturaClientes.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class CQSisCliente;
class QCapturaClientes:public CapturaClientes
{
 Q_OBJECT
public:
	QCapturaClientes(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCapturaClientes();
	CQSisCliente *ClienteSiscom();
	int Opcion();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SisReg3LstClientes;
	/*
	 * Cliente Seleccionado
	SiscomRegistro3 *SisReg3Cliente;
	*/
	/*
	 * Cliente capturado
	 */
	CQSisCliente *CQSisPtrCliente;
	int intOpcion;

	int intTipoPersona;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultandoClientes();
	void ConsultaClientes();
	void MuestraClientes();
	void MuestraCliente(SiscomRegistro3 *pSisReg3Cliente);
	void SeleccionaPestana(SiscomRegistro3 *pSisReg3Cliente);
	int TipoCliente(SiscomRegistro3 *pSisReg3Cliente);
	void MuestraPersonaFisica(SiscomRegistro3 *pSisReg3Cliente);
	void MuestraPersonaMoral(SiscomRegistro3 *pSisReg3Cliente);
	void SeleccionaTipoPersona(int pintPersona);
	CQSisCliente *Cliente();
	void Direccion(CQSisCliente *pCQSisPtrCliente);
	void Telefono(CQSisCliente *pCQSisPtrCliente);
	void CorreoElectronico(CQSisCliente *pCQSisPtrCliente);
	void RegistraPersonaFisica();
	void RegistraPersonaMoral();
private slots:
	void SlotFocoAAPaterno();
	void SlotFocoAAMaterno();
	void SlotFocoARFC();
	void SlotFocoATelefono();
	void SlotFocoACorreo();

	void SlotFocoACalle();
	void SlotFocoANumero();
	void SlotFocoAColonia();
	void SlotFocoACP();
	void SlotFocoAMunicipio();
	void SlotFocoAEstado();
	void SlotFocoAAceptar();

	void SlotCliente(int);
	void SlotNCliente();
	void SlotRegistraCliente();
	void SlotAceptar();
};
#endif
