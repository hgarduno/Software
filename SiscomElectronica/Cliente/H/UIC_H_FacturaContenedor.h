/****************************************************************************
** Form interface generated from reading ui file 'UI/FacturaContenedor.ui'
**
** Created: Wed Apr 10 20:52:31 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FACTURACONTENEDOR_H
#define FACTURACONTENEDOR_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProveedoresSE;
class QLineEdit;
class QPushButton;

class FacturaContenedor : public QDialog
{
    Q_OBJECT

public:
    FacturaContenedor( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~FacturaContenedor();

    QLabel* textLabel1_3;
    QCtrlProveedoresSE* QCtrProveedores;
    QLabel* textLabel1_6;
    QLineEdit* QLENumFactura;
    QLabel* textLabel1_2_2_2;
    QLineEdit* QLENumPartidas;
    QLabel* textLabel1_8;
    QLineEdit* QLEDscCompra;
    QPushButton* QPBAceptar;

protected:
    QGridLayout* FacturaContenedorLayout;
    QVBoxLayout* layout25;
    QVBoxLayout* layout1_4;
    QVBoxLayout* layout1_2_2_2;
    QVBoxLayout* layout27;

protected slots:
    virtual void languageChange();

};

#endif // FACTURACONTENEDOR_H
