#ifndef __QCTRLESTADISTICASSEMANALESVENTAS_H__
#define __QCTRLESTADISTICASSEMANALESVENTAS_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros.h>

class QHBoxLayout;
class QVBoxLayout;
class SiscomDatCom;
class SiscomRegistro3;
class QTable;
class QT_WIDGET_PLUGIN_EXPORT QCtrlEstadisticasSemanalesVentas:public QWidget
{
Q_OBJECT
	public:
		QCtrlEstadisticasSemanalesVentas(QWidget *pQWPtrParent=0,
						 const char *pchrPtrName=0);
	void IniciaControl();
	void Servidor(SiscomDatCom *);
private:
	void IniciaVariables();
	QTable *FormaTabla(const char *pchrPtrName,const char **pchrPtrCampos);
	void Consulta();
	void Consultando();
	void Muestra();
private:
	SiscomDatCom *SisDatCom;
	QHBoxLayout *QHBLayout;
	QHBoxLayout *QHBLayoutAA;
	QVBoxLayout *QVBLayout;
	QTable *QTOrdenes;
	QTable *QTVentas;
	QTable *QTOrdenesAA;
	QTable *QTVentasAA;
};
#endif
