/****************************************************************************
** Form interface generated from reading ui file 'UI/InformacionPedido.ui'
**
** Created: Sun Feb 9 03:08:48 2020
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef INFORMACIONPEDIDO_H
#define INFORMACIONPEDIDO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTextEdit;
class QLineEdit;
class QTable;

class InformacionPedido : public QDialog
{
    Q_OBJECT

public:
    InformacionPedido( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~InformacionPedido();

    QPushButton* QPBRegistra;
    QLabel* textLabel1;
    QTextEdit* QTEComentarios;
    QLabel* textLabel3;
    QLineEdit* QLENoPedido;
    QLabel* textLabel2;
    QTable* table3;

protected:
    QGridLayout* InformacionPedidoLayout;
    QVBoxLayout* layout18;
    QHBoxLayout* layout20;
    QSpacerItem* spacer1;
    QVBoxLayout* layout19;
    QVBoxLayout* layout21;

protected slots:
    virtual void languageChange();

};

#endif // INFORMACIONPEDIDO_H
