/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaInventario.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURAINVENTARIO_H
#define CAPTURAINVENTARIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProveedoresSS;
class QCtrlProductosSS;
class QLineEdit;
class QTable;
class QPushButton;

class CapturaInventario : public QWidget
{
    Q_OBJECT

public:
    CapturaInventario( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CapturaInventario();

    QLabel* textLabel2;
    QCtrlProveedoresSS* QCtrProveedores;
    QLabel* textLabel1;
    QCtrlProductosSS* QCtrProductos;
    QLabel* textLabel3;
    QLineEdit* QLECodigoBarras;
    QLabel* textLabel4;
    QTable* QTProductos;
    QLabel* textLabel1_2;
    QLineEdit* QLECantidad;
    QPushButton* QPBProgramaInventario;
    QPushButton* QPBAnexar;
    QPushButton* QPBRegistrar;

protected:
    QGridLayout* CapturaInventarioLayout;
    QHBoxLayout* layout3;
    QVBoxLayout* layout2;
    QVBoxLayout* layout1;
    QVBoxLayout* layout4;
    QVBoxLayout* layout5;
    QHBoxLayout* layout8;
    QSpacerItem* spacer1;
    QVBoxLayout* layout7;
    QHBoxLayout* layout10;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURAINVENTARIO_H
