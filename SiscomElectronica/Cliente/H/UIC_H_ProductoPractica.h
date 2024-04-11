/****************************************************************************
** Form interface generated from reading ui file 'UI/ProductoPractica.ui'
**
** Created: Wed Apr 10 21:11:28 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PRODUCTOPRACTICA_H
#define PRODUCTOPRACTICA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLCDNumber;
class QLabel;
class QComboBox;
class QLineEdit;
class QTextEdit;

class ProductoPractica : public QDialog
{
    Q_OBJECT

public:
    ProductoPractica( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ProductoPractica();

    QPushButton* QPBAnexar;
    QPushButton* QPBCancelar;
    QLCDNumber* QLCDNTotal;
    QLabel* textLabel5;
    QComboBox* QCBProductos;
    QLabel* textLabel6;
    QLineEdit* QLECantidad;
    QLabel* textLabel6_2;
    QLineEdit* QLEExistencia;
    QLabel* textLabel8;
    QTextEdit* QLEDescripcion;

protected:
    QGridLayout* ProductoPracticaLayout;
    QHBoxLayout* layout101;
    QVBoxLayout* layout100;
    QVBoxLayout* layout97;
    QHBoxLayout* layout104;
    QVBoxLayout* layout98;
    QVBoxLayout* layout98_2;
    QVBoxLayout* layout45;

protected slots:
    virtual void languageChange();

};

#endif // PRODUCTOPRACTICA_H
