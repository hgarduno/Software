
#ifndef __IMP_REENVIOFACTURA_H__
#define __IMP_REENVIOFACTURA_H__
#include <UIC_H_ReEnvioFactura.h>

class zSiscomConexion;
class zOrdenes;
class zSiscomRegistros;
class zSiscomRegistro;

class zDatosReEnvioFactura;
class QReEnvioFactura:public ReEnvioFactura
{
 Q_OBJECT
public:
	QReEnvioFactura(const char *pchrPtrIdFactura,
			char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QReEnvioFactura();
private:
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	const char *chrPtrIdFactura;
	zDatosReEnvioFactura *zDatReEnvioFactura;
	zSiscomRegistro *zSisRegEdoReEnvio;
	int intCorreoReEnvio;
	int intSeEnviaOtroCorreo;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void Muestra();
	void MuestraCorreos();
	void ReEnviando();
	void MuestraEdoReEnvio();
private slots:
	void SlotCorreo(int,int,int,const QPoint &);
	void SlotReEnviaFactura();
	void SlotCapturandoOtroCorreo(const QString &);
};
#endif
