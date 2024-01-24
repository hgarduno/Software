
#ifndef __IMP_SERVICIOS_H__
#define __IMP_SERVICIOS_H__
#include <UIC_H_Servicios.h>
#include <CQSisServicios.h>
class SiscomDatCom;
class CQSisServicio;
class SisUsuarioSeg3;
/*
 * Jueves 14 de Febrero 2008
 *
 * A esta clase se pasaran como argumentos 
 * desde el archivo de configuracion de la aplicacion
 * los argumentos del tipo de servicio que se esta 
 * manipulando.
 * En el argumento 10 se pasa el tipo de servicio para
 * el registro.
 *
 * Para el caso de los servicios generales se pasa:
 * RegistraServicioGeneral
 *
 * Para el caso de los servicios de cada medico.
 * RegistraServicioMedico
 *
 * En el argumento 11 se pasara el tipo de servicio para
 * la consulta
 * en el caso de los servicios generales:
 * ServiciosGenerales
 *
 * para el caso de los servicios de cada medico
 * ServiciosMedico
 *
 */
class QServicios:public Servicios
{
 Q_OBJECT
public:
	QServicios(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QServicios();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstServicio CQSLServicios;
	SisUsuarioSeg3 *SUSeg3Firmado;
private:
	void ConectaSlots();
	void IniciaVariables();
	CQSisServicio *Servicio();
	void Registra();
	void ServiciosRegistrados();
	void MuestraServicios();
private slots:
	void SlotPasaFocoDescripcion();
	void SlotPasaFocoRegistrar();
	void SlotRegistrar();
};
extern "C" QServicios *InstanciaServicios(void *,char **,void *,const char *,int);
#endif
