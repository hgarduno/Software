/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaDireccion.ui'
**
** Created: Thu Apr 11 21:05:32 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURADIRECCION_H
#define CAPTURADIRECCION_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QTextEdit;

class CapturaDireccion : public QDialog
{
    Q_OBJECT

public:
    CapturaDireccion( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaDireccion();

    QLabel* textLabel6;
    QLineEdit* QLECalle;
    QLabel* textLabel5;
    QLineEdit* QLENoExterior;
    QLabel* textLabel5_2;
    QLineEdit* QLENoInterior;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel7;
    QTextEdit* QTEReferencias;
    QLabel* textLabel6_2;
    QLineEdit* QLEColonia;
    QLabel* textLabel6_2_2;
    QLineEdit* QLEDelegacionMunicipio;
    QLabel* textLabel5_2_2;
    QLineEdit* QLEEstado;
    QLabel* textLabel5_2_2_2;
    QLineEdit* QLECodigoPostal;

protected:
    QGridLayout* CapturaDireccionLayout;
    QHBoxLayout* layout25;
    QVBoxLayout* layout22;
    QVBoxLayout* layout16;
    QVBoxLayout* layout16_2;
    QHBoxLayout* layout32;
    QVBoxLayout* layout29;
    QHBoxLayout* layout36;
    QVBoxLayout* layout22_2;
    QVBoxLayout* layout22_2_2;
    QVBoxLayout* layout16_2_2;
    QVBoxLayout* layout16_2_2_2;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURADIRECCION_H
