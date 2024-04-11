/****************************************************************************
** Form interface generated from reading ui file 'UI/RecibePedido.ui'
**
** Created: Wed Apr 10 20:52:30 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef RECIBEPEDIDO_H
#define RECIBEPEDIDO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;
class CQControlFecha;

class RecibePedido : public QWidget
{
    Q_OBJECT

public:
    RecibePedido( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RecibePedido();

    QLabel* textLabel3;
    QTable* QTPedidos;
    QLabel* textLabel2;
    QTable* QTProductos;
    QPushButton* QPBImprime;
    QPushButton* QPBConsultaPedidos;
    QPushButton* QPBConsultaPedidos_2;
    QPushButton* QPBRegistra;
    QLabel* textLabel1_2;
    CQControlFecha* QCFInicio;
    QLabel* textLabel2_2_2;
    CQControlFecha* QCFFin;

protected:
    QGridLayout* RecibePedidoLayout;
    QSpacerItem* spacer1_2;
    QVBoxLayout* layout12;
    QVBoxLayout* layout11;
    QHBoxLayout* layout5;
    QHBoxLayout* layout17;
    QVBoxLayout* layout15;
    QVBoxLayout* layout16;

protected slots:
    virtual void languageChange();

};

#endif // RECIBEPEDIDO_H
