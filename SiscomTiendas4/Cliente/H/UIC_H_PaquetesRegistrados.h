/****************************************************************************
** Form interface generated from reading ui file 'UI/PaquetesRegistrados.ui'
**
** Created: Thu Apr 11 20:30:19 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PAQUETESREGISTRADOS_H
#define PAQUETESREGISTRADOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTable;

class PaquetesRegistrados : public QWidget
{
    Q_OBJECT

public:
    PaquetesRegistrados( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~PaquetesRegistrados();

    QPushButton* QPBEliminar;
    QLabel* textLabel3;
    QTable* QTDatos;
    QLabel* textLabel3_2;
    QTable* QTProductos;
    QPushButton* QPBAPaquete;
    QPushButton* QPBEProducto;

protected:
    QGridLayout* PaquetesRegistradosLayout;
    QVBoxLayout* layout12;
    QVBoxLayout* layout4;
    QVBoxLayout* layout12_2;
    QHBoxLayout* layout3;

protected slots:
    virtual void languageChange();

};

#endif // PAQUETESREGISTRADOS_H
