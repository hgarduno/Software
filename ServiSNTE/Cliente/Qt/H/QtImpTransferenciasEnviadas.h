#ifndef __QTIMPTRANSFERENCIASENVIADAS_H__
#define __QTIMPTRANSFERENCIASENVIADAS_H__

#include <TransferenciasEnviadas.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;

class QtImpTransferenciasEnviadas:public TransferenciasEnviadas
{
Q_OBJECT

public:
	QtImpTransferenciasEnviadas(QWidget *pQWParent,const char *pchrPtrName);
private:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaVariables();

	void Consultando();
	void Consulta();
	void Muestra();

	void ConsultandoTransferencia(const char *pchrPtrIdTransferencia);
	zSiscomRegistros *ConsultaTransferencia(const char *pchrPtrIdTransferencia);
	void MuestraTransferencia(zSiscomRegistros *pzSisRegDetalleTransferencia);
	void GeneraListaCodigosBarras(QString &pQStrLista);

private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsTransferencias;
	zSiscomRegistros *zSisRegsDetalleTransferencia;
private slots:
	void SlotCapturoRangoFechas();
	void SlotSeleccionoTransferencia(int,int,int,const QPoint &);
	void SlotCopiar();

};


#endif
