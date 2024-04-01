/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaPago.ui'
**
** Created: Wed Jan 31 10:47:55 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURAPAGO_H
#define CAPTURAPAGO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;
class QLCDNumber;

class CapturaPago : public QDialog
{
    Q_OBJECT

public:
    CapturaPago( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaPago();

    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel1;
    QLineEdit* QLERecibo;
    QLabel* textLabel2;
    QLCDNumber* QLCDNImporte;
    QLabel* textLabel2_2;
    QLCDNumber* QLCDNCambio;

protected:
    QGridLayout* CapturaPagoLayout;
    QHBoxLayout* layout4;
    QVBoxLayout* layout1;
    QHBoxLayout* layout11;
    QVBoxLayout* layout2;
    QVBoxLayout* layout2_2;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURAPAGO_H
