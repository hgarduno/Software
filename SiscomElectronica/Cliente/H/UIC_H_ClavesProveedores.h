/****************************************************************************
** Form interface generated from reading ui file 'UI/ClavesProveedores.ui'
**
** Created: Thu Dec 21 12:53:39 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CLAVESPROVEEDORES_H
#define CLAVESPROVEEDORES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QTable;
class QTextEdit;
class QPushButton;

class ClavesProveedores : public QWidget
{
    Q_OBJECT

public:
    ClavesProveedores( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ClavesProveedores();

    QLabel* textLabel1;
    QComboBox* QCBProductos;
    QLabel* textLabel3;
    QTable* QTClavesProveedor;
    QLabel* textLabel2;
    QTextEdit* QTEDescripcion;
    QPushButton* pushButton1;
    QPushButton* pushButton2;

protected:
    QGridLayout* ClavesProveedoresLayout;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QVBoxLayout* layout3;
    QHBoxLayout* layout4;

protected slots:
    virtual void languageChange();

};

#endif // CLAVESPROVEEDORES_H
