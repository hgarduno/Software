/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/SoporteTransferencias.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SOPORTETRANSFERENCIAS_H
#define SOPORTETRANSFERENCIAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlTiendasEntrega;
class QLineEdit;
class QCtrlSoporteVentas;
class QPushButton;

class SoporteTransferencias : public QWidget
{
    Q_OBJECT

public:
    SoporteTransferencias( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~SoporteTransferencias();

    QLabel* textLabel1;
    QCtrlTiendasEntrega* QCtrTiendas;
    QLabel* textLabel2;
    QLineEdit* QLERangoFechas;
    QCtrlSoporteVentas* QCtrSoporteVentas;
    QPushButton* QPBImprimir;
    QPushButton* pushButton2;

protected:
    QGridLayout* SoporteTransferenciasLayout;
    QVBoxLayout* layout6;
    QVBoxLayout* layout5;
    QHBoxLayout* layout4;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QHBoxLayout* layout3;

protected slots:
    virtual void languageChange();

};

#endif // SOPORTETRANSFERENCIAS_H
