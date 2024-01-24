#ifndef __QCTRLSEPOMEXCOMUNICA_H__
#define __QCTRLSEPOMEXCOMUNICA_H__
#include <qwidget.h>
#include <qwidgetplugin.h>
#include <CQSisSepomexComunicas.h>

class QTabWidget;
class QHBoxLayout;
class SiscomDatCom;
class QSisDirecciones;

class QT_WIDGET_PLUGIN_EXPORT QCtrlSepomexComunicas: public QWidget
{
    Q_OBJECT
public:
    QCtrlSepomexComunicas( QWidget *parent = 0, const char *name = 0);
    void IniciaControl();
    void PonServidor(SiscomDatCom *);
    void Argumentos(char **);
    void IdPersona(const char *);
    void setFocus();
    void LimpiaSeleccion();
    void Limpia();
    
private:
	void IniciaVariables();
	void ConsultaSepomexComunicas();
	void MuestraSepomexComunicas();
	void ConectaSlots();
	void Direcciones();
private:
	QHBoxLayout *QHBLayout;
	QTabWidget *QTWDatos;
	SiscomDatCom *SisDatCom;
	QSisDirecciones *QSDirecciones;
	char **chrPtrArgumentos;
	const char *chrPtrIdPersona;

private slots:
signals:
};

#endif

