/****************************************************************************
** Form interface generated from reading ui file 'UI/ComprasRegistradas.ui'
**
** Created: Thu Apr 11 22:09:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef COMPRASREGISTRADAS_H
#define COMPRASREGISTRADAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class CQControlFecha;
class QLineEdit;
class QTable;
class QPushButton;

class ComprasRegistradas : public QWidget
{
    Q_OBJECT

public:
    ComprasRegistradas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ComprasRegistradas();

    QLabel* textLabel2;
    CQControlFecha* QCtrFechaIni;
    QLabel* textLabel2_2;
    CQControlFecha* QCtrFechaFin;
    QLabel* textLabel2_3;
    QLineEdit* lineEdit4;
    QLabel* textLabel3;
    QTable* QTCompras;
    QLabel* textLabel2_4;
    QTable* QTDetalleCompra;
    QPushButton* QPBEjecuta;
    QPushButton* QPBModificar;
    QPushButton* QPBEProducto;

protected:
    QGridLayout* ComprasRegistradasLayout;
    QHBoxLayout* layout51;
    QVBoxLayout* layout48;
    QVBoxLayout* layout48_2;
    QVBoxLayout* layout50;
    QVBoxLayout* layout52;
    QVBoxLayout* layout44;
    QHBoxLayout* layout73;

protected slots:
    virtual void languageChange();

};

#endif // COMPRASREGISTRADAS_H
