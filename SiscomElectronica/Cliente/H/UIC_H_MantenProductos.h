/****************************************************************************
** Form interface generated from reading ui file 'UI/MantenProductos.ui'
**
** Created: Thu Dec 21 13:56:09 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MANTENPRODUCTOS_H
#define MANTENPRODUCTOS_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QPushButton;
class QTextEdit;
class QLineEdit;

class MantenProductos : public QDialog
{
    Q_OBJECT

public:
    MantenProductos( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~MantenProductos();

    QLabel* textLabel1;
    QComboBox* QCBProductos;
    QLabel* textLabel2_3;
    QPushButton* QPBModificar;
    QPushButton* QPBCancelar;
    QLabel* textLabel4;
    QTextEdit* QLEDescripcion;
    QLabel* textLabel2;
    QComboBox* QCBFamilias;
    QLabel* textLabel2_2;
    QComboBox* QCBUnidades;
    QLabel* textLabel3_2;
    QLineEdit* QLEAbreviatura;
    QLabel* textLabel2_3_2;
    QLabel* textLabel3;
    QLineEdit* QLEFamilia;
    QLabel* textLabel3_3;
    QLineEdit* QLEUnidades;
    QLabel* textLabel4_2;
    QTextEdit* QLEDescripcionB;

protected:
    QGridLayout* MantenProductosLayout;
    QHBoxLayout* layout28;
    QSpacerItem* spacer18_2;
    QVBoxLayout* layout27;
    QHBoxLayout* layout37;
    QVBoxLayout* layout23;
    QHBoxLayout* layout16;
    QSpacerItem* spacer18;
    QVBoxLayout* layout35;
    QVBoxLayout* layout35_2;
    QVBoxLayout* layout36_2;
    QHBoxLayout* layout136;
    QVBoxLayout* layout88;
    QSpacerItem* spacer10;
    QVBoxLayout* layout86;
    QVBoxLayout* layout39;
    QVBoxLayout* layout39_2;
    QVBoxLayout* layout85;

protected slots:
    virtual void languageChange();

};

#endif // MANTENPRODUCTOS_H
