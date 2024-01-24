/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaNumFactura.ui'
**
** Created: Thu Dec 21 12:53:39 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURANUMFACTURA_H
#define CAPTURANUMFACTURA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class CapturaNumFactura : public QDialog
{
    Q_OBJECT

public:
    CapturaNumFactura( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaNumFactura();

    QLabel* textLabel4;
    QLineEdit* QLENumFactura;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaNumFacturaLayout;
    QVBoxLayout* layout48;
    QVBoxLayout* layout46;
    QHBoxLayout* layout47;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURANUMFACTURA_H
