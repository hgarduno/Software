/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaPrecioIva.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURAPRECIOIVA_H
#define CAPTURAPRECIOIVA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;

class CapturaPrecioIva : public QDialog
{
    Q_OBJECT

public:
    CapturaPrecioIva( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaPrecioIva();

    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel2;
    QLineEdit* QLECantidad;
    QLabel* textLabel2_2;
    QLineEdit* QLEIva;

protected:
    QGridLayout* CapturaPrecioIvaLayout;
    QHBoxLayout* layout89;
    QVBoxLayout* layout90;
    QVBoxLayout* layout90_2;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURAPRECIOIVA_H
