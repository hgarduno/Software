#ifndef __QCTRLEXPENDIOS_H__
#define __QCTRLEXPENDIOS_H__

#include <qwidget.h>
#include <qiconview.h>
#include <qwidgetplugin.h>
#include <SiscomRegistros3.h>

class QHBoxLayout;
class QIconView;
class SiscomDatCom;

class QIconViewItemExpendio:public QIconViewItem
{
public:
	QIconViewItemExpendio(SiscomRegistro3 *,QIconView *);
	SiscomRegistro3 *Expendio();
private:
	SiscomRegistro3 *SReg3Expendio;
};

/*!
 * \brief Clase que contiene la funcionalidad para el manejo <br>
 * de los producto mediante un Combo asi como su seleccion
 */
class QT_WIDGET_PLUGIN_EXPORT QCtrlExpendios:public QWidget 
{
Q_OBJECT
public:
	/*!
	 * \brief Constructor de la Clase
	 * \param[in] pQWParent Control en el que se instancia el objeto
	 * \param[in] pchrPtrName Nombre del control
	 */
	QCtrlExpendios(QWidget *pQWParent=0,const char *pchrPtrName=0);
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
	void setFocus();
private:
	void IniciaVariables();
	void ConectaSlots();
	void ConsultaExpendios();
	void MuestraExpendios();
private:
	QIconView *QIVExpendios;
	QHBoxLayout *QHBLayout;
	SiscomDatCom *SisDatCom;
	SiscomRegistro3Lst SReg3LstExpendios;
	const char *chrPtrIdExpendio;
private slots:
	void SlotExpendio(QIconViewItem *);
signals:
	void SignalExpendio(SiscomRegistro3 *);

};

#endif

