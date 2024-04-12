/****************************************************************************
** Form interface generated from reading ui file 'UI/PedidosPendientes.ui'
**
** Created: Thu Apr 11 21:39:52 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PEDIDOSPENDIENTES_H
#define PEDIDOSPENDIENTES_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;

class PedidosPendientes : public QDialog
{
    Q_OBJECT

public:
    PedidosPendientes( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~PedidosPendientes();

    QLabel* textLabel1;
    QTable* QTDetallePedido;
    QLabel* textLabel2;
    QTable* QTPedidos;
    QPushButton* pushButton1;
    QPushButton* QPBEnviarAMatriz;
    QPushButton* pushButton1_2_2;

protected:
    QGridLayout* PedidosPendientesLayout;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QHBoxLayout* layout3;

protected slots:
    virtual void languageChange();

};

#endif // PEDIDOSPENDIENTES_H
