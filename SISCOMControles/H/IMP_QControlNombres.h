#ifndef __CQCONTROLNOMBRES_H__
#define __CQCONTROLNOMBRES_H__

#include <UIC_H_QControlNombres.h>
#include <qwidgetplugin.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class CQPersona;

class QT_WIDGET_PLUGIN_EXPORT CQControlNombres : public QControlNombres
{
    Q_OBJECT

public:
    CQControlNombres( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CQControlNombres();
    void PonNombre(const char *);
    void PonAPaterno(const char *);
    void PonAMaterno(const char *);
    const char *ObtenNombre();
    const char *ObtenAPaterno();
    const char *ObtenAMaterno();
    void setFocus();
private:
    void ConectaSlots();
private slots:
		void S_PasaFocoAPaterno();
		void S_PasaFocoAMaterno();
		void S_EnterAMaterno();
signals:

    	void SignalEnterAMaterno();
	void SignalEnterNombre();
	void SignalEnterAPaterno();
};

#endif 
