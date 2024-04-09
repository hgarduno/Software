/****************************************************************************
** Form interface generated from reading ui file 'UI/CorteCajaSucursal.ui'
**
** Created: lun abr 1 18:57:48 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CORTECAJASUCURSAL_H
#define CORTECAJASUCURSAL_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QtCorteCajaImp;

class CorteCajaSucursal : public QWidget
{
    Q_OBJECT

public:
    CorteCajaSucursal( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CorteCajaSucursal();

    QLabel* textLabel1;
    QLabel* textLabel2;
    QLineEdit* lineEdit1;
    QPushButton* pushButton1;
    QPushButton* pushButton2;
    QPushButton* pushButton3;
    QtCorteCajaImp* QtCCaja;

protected:
    QGridLayout* CorteCajaSucursalLayout;
    QVBoxLayout* layout1;
    QHBoxLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // CORTECAJASUCURSAL_H
