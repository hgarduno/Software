#ifndef __CQCONTROLDIRECCION_H__
#define __CQCONTROLDIRECCION_H__

#include <UIC_H_QControlDireccion.h>
#include <qwidgetplugin.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QComboBox;
class QDireccion;

class QT_WIDGET_PLUGIN_EXPORT CQControlDireccion : public QControlDireccion
{
    Q_OBJECT

public:
    CQControlDireccion( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CQControlDireccion();
    void setFocus();
    const char *ObtenCalle();
    const char *ObtenNumero();
    const char *ObtenCP();
    const char *ObtenColonia();
    const char *ObtenMunicipio();
    const char *ObtenEstado();
private:
	void IniciaVariables();
	void ConectaSlots();

private:
	QLineEdit *QLEComboEdo;
public slots:
	void S_PasaFocoNumero();	
	void S_PasaFocoColonia();
	void S_PasaFocoMunicipio();	
	void S_PasaFocoCP();
	void S_PasaFocoEstado();	
	void S_CambioElCodigoPostal(const QString &);
	void S_EnterEstado();
signals:
	void SignalEnterEstado();
	
};

#endif 
