/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/ImpresionCodigoBarras.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef IMPRESIONCODIGOBARRAS_H
#define IMPRESIONCODIGOBARRAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QTabWidget;
class QCtrlProveedoresSS;
class QLineEdit;
class QPushButton;

class ImpresionCodigoBarras : public QWidget
{
    Q_OBJECT

public:
    ImpresionCodigoBarras( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ImpresionCodigoBarras();

    QLabel* textLabel1;
    QTable* QTProductos;
    QTabWidget* tabWidget2;
    QWidget* tab;
    QLabel* textLabel2;
    QCtrlProveedoresSS* QCtrProveedores;
    QWidget* tab_2;
    QLabel* textLabel3;
    QLineEdit* QLEFechaCompra;
    QPushButton* QPBImpresionTodaHoja;
    QPushButton* QPBImprimir;
    QPushButton* QPBImprimirTodo;
    QPushButton* QPBTodosProductos;

protected:
    QGridLayout* ImpresionCodigoBarrasLayout;
    QVBoxLayout* layout2;
    QGridLayout* tabLayout;
    QVBoxLayout* layout7;
    QGridLayout* tabLayout_2;
    QHBoxLayout* layout6;
    QSpacerItem* spacer2;
    QVBoxLayout* layout5;
    QHBoxLayout* layout8;

protected slots:
    virtual void languageChange();

};

#endif // IMPRESIONCODIGOBARRAS_H
