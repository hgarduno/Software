/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaCantidad.ui'
**
** Created: Sun Feb 9 03:08:48 2020
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURACANTIDAD_H
#define CAPTURACANTIDAD_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLCDNumber;
class QLineEdit;
class QTextEdit;

class CapturaCantidad : public QDialog
{
    Q_OBJECT

public:
    CapturaCantidad( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaCantidad();

    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel2_2_3;
    QLCDNumber* QLCDNExistencia;
    QLabel* textLabel2_2;
    QLineEdit* QLEClave;
    QLabel* textLabel2_2_2;
    QLineEdit* QLECantidad;
    QLabel* textLabel2_3;
    QTextEdit* QTEDescripcion;

protected:
    QGridLayout* CapturaCantidadLayout;
    QHBoxLayout* layout32;
    QVBoxLayout* layout31;
    QHBoxLayout* layout33;
    QVBoxLayout* layout26;
    QVBoxLayout* layout26_2;
    QVBoxLayout* layout43;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURACANTIDAD_H
