#ifndef __QCTRLPERFILESSS_H__
#define __QCTRLPERFILESSS_H__ 
#include <qwidget.h>
#include <qwidgetplugin.h>

class zSiscomConexion;
class zSiscomRegistros;
class zSiscomRegistro;
class QHBoxLayout;
class QComboBox;
class QLineEdit;
class QT_WIDGET_PLUGIN_EXPORT QCtrlPerfilesSS : public QWidget
{
    Q_OBJECT
public:
    QCtrlPerfilesSS( QWidget *parent = 0, const char *name = 0);
	void IniciaControl();
	void ReIniciaControl();
	void Servidor(zSiscomConexion *pzSisConexion);
	void setFocus();
	const char *Perfil();
private:
	void IniciaVariables();
	void ConsultaPerfil();
	void MuestraPerfil();
	void ConectaSlots();
	void keyPressEvent(QKeyEvent *);
private:
	QHBoxLayout *QHBLayout;
	QComboBox *QCBPerfil;
	QLineEdit *QLEPerfil;
	zSiscomRegistros *zSisRegPerfilesSS;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegPerfil;
    char lchrArrTipoPersona[20];
private slots:
	void SlotPerfil(int);
	void SlotCapturo();
	void SlotCapturandoPerfil(const QString &pQStrPerfil);
signals:
	void SignalNuevoPerfil(const QString &);
	void SignalPerfil(zSiscomRegistro *pzSisRegPerfil);
	void SignalPerfilVacia();
};

#endif
