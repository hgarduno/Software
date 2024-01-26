#ifndef __QCTRLTIPOSFOLIO_H__
#define __QCTRLTIPOSFOLIO_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlTiposFolio : public QWidget
{
    Q_OBJECT
public:
    QCtrlTiposFolio( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *Folio();
private:
	void IniciaVariables();
	void ConsultaFolio();
	void MuestraFolio();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBFolio;
	QLineEdit *QLEFolio;
	zSiscomRegistros *zSisRegTiposFolio;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegFolio;

private slots:
	void SlotFolio(int);
	void SlotCapturo();
	void SlotCapturandoFolio(const QString &pQStrFolio);
signals:
	void SignalNuevoFolio(const QString &);
	void SignalFolio(zSiscomRegistro *pzSisRegFolio);
	void SignalFolioVacia();
};

#endif
