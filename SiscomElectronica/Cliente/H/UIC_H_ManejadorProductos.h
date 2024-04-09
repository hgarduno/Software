/****************************************************************************
** Form interface generated from reading ui file 'UI/ManejadorProductos.ui'
**
** Created: lun abr 1 19:07:05 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MANEJADORPRODUCTOS_H
#define MANEJADORPRODUCTOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QTextEdit;
class QTable;
class QPushButton;

class ManejadorProductos : public QWidget
{
    Q_OBJECT

public:
    ManejadorProductos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ManejadorProductos();

    QLabel* textLabel2;
    QComboBox* QCBFamilias;
    QLabel* textLabel2_2;
    QComboBox* QCBUnidades;
    QLabel* textLabel3_2;
    QLineEdit* QLEAbreviatura;
    QLabel* textLabel3;
    QLineEdit* QLEProducto;
    QLabel* textLabel1_2;
    QLineEdit* QLENClave;
    QLabel* textLabel1;
    QLineEdit* QLENCDescripcion;
    QLabel* textLabel4;
    QTextEdit* QLEDescripcion;
    QTable* QTDatos;
    QPushButton* QPBAnexar;
    QPushButton* QPBRegistrar;
    QPushButton* QPBEliminar;
    QPushButton* QPBMDatos;
    QPushButton* QPBModEliClave;

protected:
    QGridLayout* ManejadorProductosLayout;
    QVBoxLayout* layout30;
    QHBoxLayout* layout28;
    QVBoxLayout* layout35;
    QVBoxLayout* layout35_2;
    QVBoxLayout* layout36_2;
    QHBoxLayout* layout27;
    QVBoxLayout* layout36;
    QVBoxLayout* layout24_2;
    QVBoxLayout* layout24;
    QVBoxLayout* layout13;
    QHBoxLayout* layout29;

protected slots:
    virtual void languageChange();

};

#endif // MANEJADORPRODUCTOS_H
