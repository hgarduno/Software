
#ifndef __IMP_REGISTROCOTIZACIONIMPORTACION_H__
#define __IMP_REGISTROCOTIZACIONIMPORTACION_H__
#include <UIC_H_RegistroCotizacionImportacion.h>
#include <zCotizacionesImportacion.h>
class zSiscomConexion;
class zCotizacionImportacion;
class QRegistroCotizacionImportacion:public RegistroCotizacionImportacion
{
 Q_OBJECT
public:
	QRegistroCotizacionImportacion(zCotizacionImportacion *pzCotImportacion,
				       char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QRegistroCotizacionImportacion();
	int Cotizando();
	zCotizacionImportacion *Cotizacion();
private:
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zCotizacionesImportacion zCotsImportacion;
	zCotizacionImportacion *zCotImportacion;
	int intCotizando;
	
private:
	void ConectaSlots();
	void IniciaVariables();
	void IniciaVariablesConsulta();
	void IniciaVariablesRegistro();

	void ConsultandoCotizacionesImportacion();
	void ConsultaCotizacionesImportacion();
	void MuestraCotizacionesImportacion();
	void MuestraCotizacion(int pintFila,zCotizacionImportacion *);
	void Registrando();
	int Registra();
	void SeRegistroLaCotizacion();
	void CompletaCotizacion(zCotizacionImportacion *);
private slots:
	void SlotCapturandoCotizacion();
	void SlotRegistrar();
	void SlotSeleccionaCotizacion(int,int,int,const QPoint &);
};
#endif
