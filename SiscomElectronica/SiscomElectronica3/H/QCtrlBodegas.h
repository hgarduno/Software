#ifndef __QCTRLBODEGAS_H__
#define __QCTRLBODEGAS_H__

#include <qwidget.h>
#include <qiconview.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>

class QHBoxLayout;
class QIconView;
class SiscomDatCom;

class QIconViewItemBodega:public QIconViewItem
{
public:
	QIconViewItemBodega(SiscomRegistro3 *,QIconView *);
	SiscomRegistro3 *Bodega();
private:
	SiscomRegistro3 *SReg3Bodega;
};

/*!
 * \brief Clase que contiene la funcionalidad para el manejo <br>
 * de los producto mediante un Combo asi como su seleccion
 */
class QT_WIDGET_PLUGIN_EXPORT QCtrlBodegas:public QWidget 
{
Q_OBJECT
public:
	/*!
	 * \brief Constructor de la Clase
	 * \param[in] pQWParent Control en el que se instancia el objeto
	 * \param[in] pchrPtrName Nombre del control
	 */
	QCtrlBodegas(QWidget *pQWParent=0,const char *pchrPtrName=0);
	/*!
	 * \brief Pasa los datos de comunicaciones al Objeto.
	 * \param[in] pSisDatCom Datos de comunicacion del servidor
	 */
	void Servidor(SiscomDatCom *pSisDatCom);

	/*!
	 * \brief Ejecuta la consulta con el servidor, muestra los empleados 
	 */
	void IniciaControl();

	void Expendio(const char *);
private:
	void IniciaVariables();
	void ConectaSlots();
	void ConsultaBodegas();
	void MuestraBodegas();
private:
	QIconView *QIVBodegas;
	QHBoxLayout *QHBLayout;
	SiscomDatCom *SisDatCom;
	SiscomRegistro3Lst SReg3LstBodegas;
	const char *chrPtrIdExpendio;
private slots:
	void SlotBodega(QIconViewItem *);
signals:
	void SignalBodega(SiscomRegistro3 *);

};

#endif

