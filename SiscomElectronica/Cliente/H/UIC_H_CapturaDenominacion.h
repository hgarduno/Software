/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaDenominacion.ui'
**
** Created: Fri Apr 12 21:25:57 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURADENOMINACION_H
#define CAPTURADENOMINACION_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class CapturaDenominacion : public QDialog
{
    Q_OBJECT

public:
    CapturaDenominacion( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaDenominacion();

    QLabel* textLabel3;
    QLineEdit* QLEDenominacion;
    QLabel* textLabel3_2;
    QLineEdit* QLECantidad;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaDenominacionLayout;
    QVBoxLayout* layout4;
    QVBoxLayout* layout4_2;
    QHBoxLayout* layout6;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURADENOMINACION_H
