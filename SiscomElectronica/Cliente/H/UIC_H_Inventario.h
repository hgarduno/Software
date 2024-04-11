/****************************************************************************
** Form interface generated from reading ui file 'UI/Inventario.ui'
**
** Created: Wed Apr 10 21:11:25 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTextEdit;
class QCtrlMotivoInventario;
class QLineEdit;
class QPushButton;
class QComboBox;

class Inventario : public QWidget
{
    Q_OBJECT

public:
    Inventario( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Inventario();

    QLabel* textLabel3;
    QTextEdit* QLEDescripcion;
    QLabel* textLabel1_2;
    QCtrlMotivoInventario* QCtrMotivoInventario;
    QLabel* textLabel1_3;
    QLineEdit* QLEInventario;
    QPushButton* QPBRegistrar;
    QPushButton* QPBActualiza;
    QPushButton* QPBActivaMotivo;
    QLabel* textLabel2;
    QComboBox* QCBProductos;
    QLabel* textLabel1;
    QLineEdit* QLECantidad;
    QLabel* textLabel1_4;
    QLineEdit* QLEExistenciaFisica;

protected:
    QGridLayout* InventarioLayout;
    QVBoxLayout* layout37;
    QVBoxLayout* layout6;
    QVBoxLayout* layout7;
    QHBoxLayout* layout10;
    QHBoxLayout* layout15;
    QVBoxLayout* layout2;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;

protected slots:
    virtual void languageChange();

};

#endif // INVENTARIO_H
