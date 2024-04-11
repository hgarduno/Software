/****************************************************************************
** Form interface generated from reading ui file 'UI/CambiaEdoControlCaja.ui'
**
** Created: Wed Apr 10 20:52:29 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAMBIAEDOCONTROLCAJA_H
#define CAMBIAEDOCONTROLCAJA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QButtonGroup;
class QRadioButton;
class QPushButton;

class CambiaEdoControlCaja : public QDialog
{
    Q_OBJECT

public:
    CambiaEdoControlCaja( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CambiaEdoControlCaja();

    QButtonGroup* QGBEstados;
    QRadioButton* QRBHabilitado;
    QRadioButton* QRBDesHabilitado;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CambiaEdoControlCajaLayout;
    QGridLayout* QGBEstadosLayout;

protected slots:
    virtual void languageChange();

};

#endif // CAMBIAEDOCONTROLCAJA_H
