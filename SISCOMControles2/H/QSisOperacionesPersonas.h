#ifndef __QSISOPERACIONESPERSONAS_H__
#define __QSISOPERACIONESPERSONAS_H__

#include <qwidget.h>
#include <qwidgetplugin.h>
#include <QSisBibliotecaOpPersonas.h>

class QIconView;
class QIconViewItem;
class QHBoxLayout;
class QSisIconDatosPersona;

class QT_WIDGET_PLUGIN_EXPORT QSisOperacionesPersonas : public QWidget
{
    Q_OBJECT


public:

    QSisOperacionesPersonas( QWidget *parent = 0, const char *name = 0);
    void SiscomAnexaOperacion(const char *,const char *);
    void SiscomIniciaControl();
    QIconView *ObtenIconView();
    QSisOperacionesPersonas &operator<<(QSisIconDatosPersona *);

private:
	QIconView *QIVOperaciones;
	QHBoxLayout *QHBLayout;
	QSisBibliotecaOpsPersonas QSisBOpsPersonas;
private:
	void IniciaVariables();
	void ConectaSlots();
private slots:
	void S_SeleccionoOperacion(QIconViewItem *);
};

#endif
