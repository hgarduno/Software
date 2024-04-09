/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaTelefono.ui'
**
** Created: lun abr 1 19:07:12 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURATELEFONO_H
#define CAPTURATELEFONO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;

class CapturaTelefono : public QDialog
{
    Q_OBJECT

public:
    CapturaTelefono( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaTelefono();

    QPushButton* QPBCancelar;
    QPushButton* QPBAceptar;
    QLabel* textLabel2;
    QLineEdit* QLETelefono;
    QLabel* textLabel2_2;
    QLineEdit* QLEDescripcion;

protected:
    QGridLayout* CapturaTelefonoLayout;
    QVBoxLayout* layout159;
    QVBoxLayout* layout159_2;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURATELEFONO_H
