/****************************************************************************
** Form interface generated from reading ui file 'UI/ReEnvioFactura.ui'
**
** Created: Thu Apr 11 21:39:52 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REENVIOFACTURA_H
#define REENVIOFACTURA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QTable;

class ReEnvioFactura : public QDialog
{
    Q_OBJECT

public:
    ReEnvioFactura( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ReEnvioFactura();

    QLabel* textLabel1_2;
    QLineEdit* QLERFC;
    QPushButton* QPBReEnvia;
    QPushButton* pushButton5_2;
    QPushButton* pushButton5_2_2;
    QLabel* textLabel2;
    QTable* QTCorreos;
    QLabel* textLabel1;
    QLineEdit* QLERazonSocial;
    QLabel* textLabel1_3;
    QLineEdit* QLEOtroCorreo;

protected:
    QGridLayout* ReEnvioFacturaLayout;
    QVBoxLayout* layout10_2;
    QHBoxLayout* layout13;
    QVBoxLayout* layout12;
    QVBoxLayout* layout10;
    QVBoxLayout* layout10_3;

protected slots:
    virtual void languageChange();

};

#endif // REENVIOFACTURA_H
