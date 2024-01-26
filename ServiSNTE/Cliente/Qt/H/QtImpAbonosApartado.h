#ifndef __QTIMPABONOSAPARTADO_H__
#define __QTIMPABONOSAPARTADO_H__
#include <cstddef>
#include <AbonosApartado.h>
#include <zReciboApartado.h>
class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;

class QtImpAbonosApartado:public AbonosApartado
{
Q_OBJECT
public:
	QtImpAbonosApartado(QWidget *pQWParent,
			  const char *pchrPtrName);

private:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaVariables();
	int ConsultaApartados();
	void MuestraApartados();
	void MuestraCliente();
	void ConsultandoApartados();
	int  CapturaAbono();
	void RegistrandoAbono();
	void RegistraAbono();
        void ConsultaAbonos();
	void CancelaAbono();
	void CancelaApartado();
	void ValidaLiquidacionApartado();
	void ImprimeReciboApartado();
	void CancelarFolioAbono();
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsApartados;
	zSiscomRegistros *zSisRegsAbonos;
	zSiscomRegistro *zSisRegCliente;
	zSiscomRegistro *zSisRegVenta;
	zSiscomRegistro *zSisRegTienda;
	zSiscomRegistro *zSisRegAbono;
    	zReciboApartado zRecibo;
private slots:

	void SlotRFC();
	void SlotSeleccionaApartado(int ,int,int,const QPoint &);
	void SlotSeleccionaAbono(int ,int,int,const QPoint &);
	void SlotCapturaAbono();
	void SlotCancelaAbono();
	void SlotCancelaApartado();
	void SlotImprimeRecibo();
	void SlotCancelarFolioAbono();

};
#endif
