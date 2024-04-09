/****************************************************************************
** Form interface generated from reading ui file 'UI/CompraContenedor.ui'
**
** Created: lun abr 1 18:57:48 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef COMPRACONTENEDOR_H
#define COMPRACONTENEDOR_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QTextEdit;
class QLineEdit;
class QPushButton;

class CompraContenedor : public QWidget
{
    Q_OBJECT

public:
    CompraContenedor( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CompraContenedor();

    QLabel* textLabel2;
    QTable* QTFacturas;
    QLabel* textLabel3;
    QTextEdit* textEdit1;
    QLabel* textLabel3_2;
    QLineEdit* QLECostoEnvio;
    QLabel* textLabel3_2_2;
    QLineEdit* QLECostoDolar;
    QLabel* textLabel3_2_2_2;
    QLineEdit* QLECostoAdministrativo;
    QPushButton* pushButton5;
    QPushButton* QPBAgregaFactura;

protected:
    QGridLayout* CompraContenedorLayout;
    QSpacerItem* spacer2;
    QVBoxLayout* layout9;
    QHBoxLayout* layout53;
    QHBoxLayout* layout51;
    QVBoxLayout* layout49;
    QVBoxLayout* layout50;
    QVBoxLayout* layout40_2;
    QVBoxLayout* layout40_2_2;
    QVBoxLayout* layout52;
    QSpacerItem* spacer3;
    QVBoxLayout* layout40_2_2_2;
    QHBoxLayout* layout54;

protected slots:
    virtual void languageChange();

};

#endif // COMPRACONTENEDOR_H
