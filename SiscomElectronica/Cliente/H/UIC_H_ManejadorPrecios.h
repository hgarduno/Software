/****************************************************************************
** Form interface generated from reading ui file 'UI/ManejadorPrecios.ui'
**
** Created: Wed Jan 31 10:58:34 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MANEJADORPRECIOS_H
#define MANEJADORPRECIOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;
class QTextEdit;

class ManejadorPrecios : public QWidget
{
    Q_OBJECT

public:
    ManejadorPrecios( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ManejadorPrecios();

    QLabel* textLabel4;
    QComboBox* QCBTipoPrecio;
    QLabel* textLabel4_2;
    QComboBox* QCBProductos;
    QLabel* textLabel5;
    QLineEdit* QLEPVenta;
    QLabel* textLabel5_2;
    QLineEdit* QLENvoPrecio;
    QPushButton* QPBRegistrarPrecio;
    QLabel* textLabel6;
    QTextEdit* QLEDescripcion;

protected:
    QGridLayout* ManejadorPreciosLayout;
    QVBoxLayout* layout31;
    QHBoxLayout* layout35;
    QVBoxLayout* layout31_2;
    QVBoxLayout* layout33;
    QVBoxLayout* layout33_2;
    QVBoxLayout* layout52;

protected slots:
    virtual void languageChange();

};

#endif // MANEJADORPRECIOS_H
