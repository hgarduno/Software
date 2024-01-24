#ifndef __IMP_CAPTURACONTACTO_H__
#define __IMP_CAPTURACONTACTO_H__

#include <UIC_H_CapturaContacto.h>
#include <CQSiscomCom.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class QCapturaContacto : public CapturaContacto
{
    Q_OBJECT

public:
    QCapturaContacto( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~QCapturaContacto();
    SISCOMGlobales::BTN_Captura ObtenOpcion(); 
    const char *ObtenNombreCompleto();
    const char *ObtenNombre();
    const char *ObtenAPaterno();
    const char *ObtenAMaterno();
    const char *ObtenDescripcion();
private:
    SISCOMGlobales::BTN_Captura Seleccion;
    const char *chrPtrNombre;
    const char *chrPtrAMaterno;
    const char *chrPtrAPaterno;
    const char *chrPtrDescripcion;
private:
    void ConectaSlots();
private slots:
    void S_PasaFocoAPaterno();
    void S_PasaFocoAMaterno();
    void S_PasaFocoAceptar();
    void S_PasaFocoDescripcion();
    void S_Aceptar();
    void S_Cancelar();

};

#endif 
