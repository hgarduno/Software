#ifndef __QCTRLCMBBODEGAS_H__
#define __QCTRLCMBBODEGAS_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>

class QHBoxLayout;
class QComboBox;
class QLineEdit;
class SiscomDatCom;

/*!
 * \brief Clase que contiene la funcionalidad para el manejo <br>
 * de los producto mediante un Combo asi como su seleccion
 */
class QT_WIDGET_PLUGIN_EXPORT QCtrlCmbBodegas:public QWidget 
{
Q_OBJECT
public:
	/*!
	 * \brief Constructor de la Clase
	 * \param[in] pQWParent Control en el que se instancia el objeto
	 * \param[in] pchrPtrName Nombre del control
	 */
	QCtrlCmbBodegas(QWidget *pQWParent=0,const char *pchrPtrName=0);
	/*!
	 * \brief Pasa los datos de comunicaciones al Objeto.
	 * \param[in] pSisDatCom Datos de comunicacion del servidor
	 */
	void Servidor(SiscomDatCom *pSisDatCom);

	/*!
	 * \brief Ejecuta la consulta con el servidor, muestra los productos 
	 */
	void IniciaControl();
	/*!
	 * \brief Regresa el QLineEdit asignado al combo
	 */
	QLineEdit *QLineEditBodega();
	void setFocus();
	void Expendio(const char *pchrPtrIdExpendio);
private:
	void IniciaVariables();
	void ConectaSlots();
	void ConsultaBodegas();
	void MuestraBodegas();
private:
	QComboBox *QCBProductos;
	QHBoxLayout *QHBLayout;
	QLineEdit *QLEBodega;
	SiscomDatCom *SisDatCom;
	SiscomRegistro3Lst SReg3LstBodegas;
	const char *chrPtrIdExpendio;
private slots:
	void SlotSeleccionando(int);
	void SlotSelecciono(int);
signals:
	void SignalSeleccionando(SiscomRegistro3 *);
	void SignalSelecciono(SiscomRegistro3 *);

};

#endif

