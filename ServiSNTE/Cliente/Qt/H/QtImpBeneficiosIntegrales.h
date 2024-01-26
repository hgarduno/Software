#ifndef __QTIMPBENEFICIOSINTEGRALES_H__
#define __QTIMPBENEFICIOSINTEGRALES_H__
#include <QtImprimeBeneficiosIntegrales.h>
#include <BeneficiosIntegrales.h>
#include <cstddef>

class zSiscomConexion;
class zSiscomRegistro;
class zDireccion;
class zContratoBeneficios;
class QtImpBeneficiosIntegrales:public BeneficiosIntegrales
{
Q_OBJECT
public:
	QtImpBeneficiosIntegrales(QWidget *pQWParent,
			  const char *pchrPtrName);

public:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaVariables();

    	void imprimeContrato();

private:
	zSiscomConexion *zSisConexion;
	QString QStrFormato;
	char *chrPtrFormato;
	char *chrPtrFormatoDatos;
	const char *Direccion(const char *pchrPtrCampo,zDireccion *pzDireccion);
	zContratoBeneficios *zConBeneficios;
	Registro RegPosiciones[500];
private:
	void Formato();
	void MuestraDatos();
	void MuestraPosiciones();
	void CargaPosicionesArchivo();
	void CargandoPosiciones();
	int LineaValida(const char *pchrPtrLinea);
	int FinPagina(const char *pchrPtrLinea,Registro *pRegistro);
	void ImprimeContratoAArchivo();
	void CompletaContratoBeneficios();
	const char *FormaNumeroDireccion();
	int EsFinContrato(const char *pchrPtrLinea,Registro *pRegistro);
private slots:
	void SlotSeleccionaCredito();
	void SlotCapturaDatosEmpleo();
	void SlotCapturaDireccionParticular();
	void SlotCapturaDatosComplementarios();
    	void SlotImprimeContrato();
	void SlotImprimeContratoAArchivo();
	void SlotImprimeFrente();
	void SlotImprimeAtras();
	void SlotPosicionesBeneficios();
	void SlotCapturaDatosGenerales();
	void SlotCapturaDatosComunicacion();
	void SlotGeneralesContrato();
	void SlotCentroTrabajo();
	void SlotCreditosBeneficiosIntegrales();
};

#endif
