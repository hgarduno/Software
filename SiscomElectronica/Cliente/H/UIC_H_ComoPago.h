/****************************************************************************
** Form interface generated from reading ui file 'UI/ComoPago.ui'
**
** Created: Thu Apr 11 21:39:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef COMOPAGO_H
#define COMOPAGO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QButtonGroup;
class QRadioButton;
class QPushButton;

class ComoPago : public QDialog
{
    Q_OBJECT

public:
    ComoPago( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ComoPago();

    QButtonGroup* QBGComoPago;
    QRadioButton* QREfectivo;
    QRadioButton* QRTransferencia;
    QRadioButton* QRTarjeta;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* ComoPagoLayout;
    QHBoxLayout* layout43;

protected slots:
    virtual void languageChange();

};

#endif // COMOPAGO_H
