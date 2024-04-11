/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/SeleccionaCredito.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SELECCIONACREDITO_H
#define SELECCIONACREDITO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;

class SeleccionaCredito : public QDialog
{
    Q_OBJECT

public:
    SeleccionaCredito( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~SeleccionaCredito();

    QLabel* textLabel1;
    QLineEdit* QLERFC;
    QLabel* textLabel1_2;
    QLineEdit* QLECliente;
    QLabel* textLabel2;
    QTable* QTCreditos;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* SeleccionaCreditoLayout;
    QHBoxLayout* layout4;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;
    QVBoxLayout* layout2;
    QHBoxLayout* layout6;

protected slots:
    virtual void languageChange();

};

#endif // SELECCIONACREDITO_H
