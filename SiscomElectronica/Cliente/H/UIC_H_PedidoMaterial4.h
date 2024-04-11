/****************************************************************************
** Form interface generated from reading ui file 'UI/PedidoMaterial4.ui'
**
** Created: Wed Apr 10 20:52:30 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PEDIDOMATERIAL4_H
#define PEDIDOMATERIAL4_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTextEdit;
class QCtrlProductosSE;
class QTable;
class QLineEdit;
class QPushButton;

class PedidoMaterial4 : public QWidget
{
    Q_OBJECT

public:
    PedidoMaterial4( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~PedidoMaterial4();

    QLabel* textLabel2;
    QTextEdit* QTEDescripcion;
    QLabel* textLabel2_2;
    QTextEdit* QTEObservacionesPedido;
    QLabel* textLabel1;
    QCtrlProductosSE* QCtrProductos;
    QTable* QTProductos;
    QLabel* textLabel3;
    QLineEdit* QLECantidad;
    QLabel* textLabel2_2_2;
    QTextEdit* QTEObsProducto;
    QPushButton* QPBAnexar;
    QPushButton* QPBActualizar;
    QPushButton* QPBActualizaObsPedido;
    QPushButton* QPBEliminaProducto;
    QPushButton* QPBRegistraPedido;

protected:
    QGridLayout* PedidoMaterial4Layout;
    QHBoxLayout* layout15;
    QVBoxLayout* layout2;
    QVBoxLayout* layout2_2;
    QVBoxLayout* layout15_2;
    QHBoxLayout* layout15_3;
    QSpacerItem* spacer2;
    QVBoxLayout* layout8;
    QVBoxLayout* layout2_2_2;
    QHBoxLayout* layout9;

protected slots:
    virtual void languageChange();

};

#endif // PEDIDOMATERIAL4_H
