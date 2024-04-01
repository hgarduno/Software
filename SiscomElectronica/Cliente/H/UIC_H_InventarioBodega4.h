/****************************************************************************
** Form interface generated from reading ui file 'UI/InventarioBodega4.ui'
**
** Created: Wed Jan 31 10:48:07 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef INVENTARIOBODEGA4_H
#define INVENTARIOBODEGA4_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProductosSE;
class QLineEdit;
class QPushButton;
class QTable;
class QTextEdit;

class InventarioBodega4 : public QWidget
{
    Q_OBJECT

public:
    InventarioBodega4( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~InventarioBodega4();

    QLabel* textLabel2;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel3;
    QLineEdit* QLECantidad;
    QLabel* textLabel3_2;
    QLineEdit* QLEExistencia;
    QPushButton* QPBActualiza;
    QLabel* textLabel4;
    QTable* QTDatos;
    QLabel* textLabel5;
    QTextEdit* QTEDescripcion;

protected:
    QGridLayout* InventarioBodega4Layout;
    QHBoxLayout* layout5;
    QVBoxLayout* layout2;
    QVBoxLayout* layout3;
    QVBoxLayout* layout3_2;
    QHBoxLayout* layout7;
    QVBoxLayout* layout6;
    QVBoxLayout* layout8;

protected slots:
    virtual void languageChange();

};

#endif // INVENTARIOBODEGA4_H
