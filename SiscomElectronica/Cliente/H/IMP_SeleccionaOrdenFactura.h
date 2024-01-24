
#ifndef __IMP_SELECCIONAORDENFACTURA_H__
#define __IMP_SELECCIONAORDENFACTURA_H__
#include <UIC_H_SeleccionaOrdenFactura.h>
class SiscomDatCom;
class zSiscomConexion;
class zOrdenes;
class zSiscomRegistros;
class zSiscomRegistro;
class QSeleccionaOrdenFactura:public SeleccionaOrdenFactura
{
 Q_OBJECT
public:
	QSeleccionaOrdenFactura(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QSeleccionaOrdenFactura();
	zSiscomRegistro *Orden();
	 
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zOrdenes *zOrdenesV;
	zSiscomRegistro *zSisRegOrden;
	int intAceptar;
	int intOrdenActual;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Conexion(zSiscomConexion *);

	void Consultando();
	void Consulta();
	void Muestra();
	void MuestraOrden(zSiscomRegistros *);

	void HabilitaRangoFecha(bool );
private:
	void reject();
private slots:
	void SlotFocoAFechaInicio();
	void SlotFocoAFechaFin();
	void SlotFocoAConsultar();
	void SlotConsultar();
	void SlotOrden(int pintOrden,int,int,const QPoint &);
	void SlotAceptar();
	void SlotCancelar();
	void SlotReEnviar();
	void SlotCapturandoNoOrden(const QString &);
	void SlotCapturoNoOrden();	

};
#endif
