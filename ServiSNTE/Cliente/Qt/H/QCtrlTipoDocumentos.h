#ifndef __QCTRLTIPODOCUMENTOS_H__
#define __QCTRLTIPODOCUMENTOS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlTipoDocumentos : public QWidget
{
    Q_OBJECT
public:
    QCtrlTipoDocumentos( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *TipoDocumento();
private:
	void IniciaVariables();
	void ConsultaTipoDocumento();
	void MuestraTipoDocumento();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBTipoDocumento;
	QLineEdit *QLETipoDocumento;
	zSiscomRegistros *zSisRegTipoDocumentos;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegTipoDocumento;

private slots:
	void SlotTipoDocumento(int);
	void SlotCapturo();
	void SlotCapturandoTipoDocumento(const QString &pQStrTipoDocumento);
signals:
	void SignalNuevoTipoDocumento(const QString &);
	void SignalTipoDocumento(zSiscomRegistro *pzSisRegTipoDocumento);
	void SignalTipoDocumentoVacia();
};

#endif
