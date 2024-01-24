
#ifndef __IMP_MANEJADOREXPENDIOS_H__
#define __IMP_MANEJADOREXPENDIOS_H__
#include <UIC_H_ManejadorExpendios.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class CQSisExpendio;
/*
 * Se trabaja ahora con la funcionalidad de los expendios
 * no se habia considerado el registro de un expendio 
 * el procedimiento se realizaba simplemente copiando la
 * base de datos del Poli y se actualizaba el id de la empresa
 * en las tablas que lo requieran. En esta fase se contempla el
 * siguiente procedimiento:
 * Primero el expendio que se vaya a registrar debera de estar 
 * conectado a la vpn.
 *
 * En la maquina en la que se instale el sistema se debera 
 * crear la base de datos apartir del esquema de la base de
 * datos de SISCOM Zacatenco.
 *
 * Una vez que se cree el esquema de la base de datos se procedera
 * a la ejecucion del presente modulo para registar el expendio.
 *
 * El expendio se registra en la base de datos Siscom Zacatenco
 *
 * En el nuevo expendio, al ejecutar el boton del modulo Iniciar Expendio
 * se transferiran todos los registros de las tablas necesarias para 
 * que opere el expendio, productos, precios, etc, y se inicializaran 
 * las tablas que asi lo requieran.
 *
 * En los expendios no se realizan compras solo transferencias de mateial.
 *
 *
 */

class QManejadorExpendios:public ManejadorExpendios
{
 Q_OBJECT
public:
	QManejadorExpendios(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QManejadorExpendios();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SisReg3LstEdoReg;
	SiscomRegistro3 *SisReg3Expendio;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Registra();
	CQSisExpendio *Expendio();
	CQSisExpendio *ExpendioActualizar();
	void MuestraExpendio(SiscomRegistro3 *pSisReg3Expendio);
	void ActualizaExpendio();
	void IniciaExpendio();
private slots:
	void SlotPasaFocoRFC();
	void SlotPasaFocoDireccionIp();
	void SlotPasaFocoPuerto();
	void SlotPasaFocoBase();
	void SlotPasaFocoRegistra();
	void SlotRegistra();
	void SlotExpendio(SiscomRegistro3 *pSisReg3Expendio);
	void SlotActualiza();
	void SlotInicia();
};
extern "C" QManejadorExpendios *InstanciaManejadorExpendios(void *,char **,void *,const char *,int);
#endif
