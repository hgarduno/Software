#ifndef __IMP_INTRODUCEDATOS_H__
#define __IMP_INTRODUCEDATOS_H__

#include <UIC_H_IntroduceDatos.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class QIntroduceDatos : public IntroduceDatos
{
    Q_OBJECT

public:
    enum BTN_Acciones
    {
	    Aceptar,
	    Cancelar
    };
    QIntroduceDatos(const char *,const char *, QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QIntroduceDatos();
    BTN_Acciones ObtenBoton();
    QString ObtenDato();
private:
    BTN_Acciones Boton;
private:
    void ConectaSlots();
private slots:
	void S_Cancelar();
	void S_Aceptar();
	void S_PasaFocoAceptar();
	void S_CambioTexto(const QString &);

};

#endif 
