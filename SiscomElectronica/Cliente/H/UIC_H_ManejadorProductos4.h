/****************************************************************************
** Form interface generated from reading ui file 'UI/ManejadorProductos4.ui'
**
** Created: Thu Apr 11 21:39:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MANEJADORPRODUCTOS4_H
#define MANEJADORPRODUCTOS4_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProductosSE;
class QTable;
class QTextEdit;
class QLineEdit;
class QCtrlCajasUbicacion;
class QCtrlEstantes;
class QPushButton;

class ManejadorProductos4 : public QWidget
{
    Q_OBJECT

public:
    ManejadorProductos4( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ManejadorProductos4();

    QLabel* textLabel1;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel3;
    QTable* QTUbicacion;
    QLabel* textLabel2;
    QTextEdit* QTEDescripcion;
    QLabel* textLabel2_2;
    QLineEdit* QLECveProducto;
    QLabel* textLabel2_2_2;
    QLineEdit* QLECaja;
    QLabel* textLabel1_2;
    QCtrlCajasUbicacion* QCtrCajas;
    QLabel* textLabel1_3;
    QCtrlEstantes* QCtrEstantes;
    QPushButton* QPBAsignarUbicacion;
    QPushButton* QPBAsigCajaDeDescripcion;
    QPushButton* QPBRegistrarCaja;
    QPushButton* QPBRegistrarCaja_2;
    QPushButton* pushButton5;
    QPushButton* pushButton5_2;

protected:
    QGridLayout* ManejadorProductos4Layout;
    QVBoxLayout* layout1;
    QHBoxLayout* layout6;
    QVBoxLayout* layout3;
    QVBoxLayout* layout2;
    QHBoxLayout* layout11;
    QVBoxLayout* layout9;
    QVBoxLayout* layout9_2;
    QVBoxLayout* layout5;
    QVBoxLayout* layout10;

protected slots:
    virtual void languageChange();

};

#endif // MANEJADORPRODUCTOS4_H
