/****************************************************************************
** Form interface generated from reading ui file 'UI/PedidoMaterial.ui'
**
** Created: lun abr 1 18:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PEDIDOMATERIAL_H
#define PEDIDOMATERIAL_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QLabel;
class QComboBox;
class QLineEdit;
class QTextEdit;
class QPushButton;

class PedidoMaterial : public QWidget
{
    Q_OBJECT

public:
    PedidoMaterial( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~PedidoMaterial();

    QTable* QTProductos;
    QLabel* textLabel1;
    QComboBox* QCBProductos;
    QLabel* textLabel3;
    QLineEdit* QLECantidad;
    QLabel* textLabel2;
    QTextEdit* QTEDescripcion;
    QLabel* textLabel2_2;
    QTextEdit* QTEObservacionesPedido;
    QPushButton* QPBAnexar;
    QPushButton* QPBEliminaProducto;
    QPushButton* QPBRegPedidoMaterial;
    QPushButton* QPBPedidosPendientes;

protected:
    QGridLayout* PedidoMaterialLayout;
    QHBoxLayout* layout13;
    QVBoxLayout* layout12;
    QVBoxLayout* layout1;
    QVBoxLayout* layout8;
    QHBoxLayout* layout15;
    QVBoxLayout* layout2;
    QVBoxLayout* layout2_2;

protected slots:
    virtual void languageChange();

};

#endif // PEDIDOMATERIAL_H
