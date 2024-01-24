/****************************************************************************
** Form interface generated from reading ui file 'UI/Pedidos.ui'
**
** Created: Sun Feb 9 03:08:48 2020
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PEDIDOS_H
#define PEDIDOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QCtrlCotizas;
class QLabel;
class QTable;
class QSisDirecciones;
class QGroupBox;
class QLineEdit;
class QTabWidget;
class QTextEdit;
class QPushButton;

class Pedidos : public QWidget
{
    Q_OBJECT

public:
    Pedidos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Pedidos();

    QCtrlCotizas* QCCotizando;
    QLabel* textLabel2;
    QTable* QTProductos;
    QSisDirecciones* QSDirecciones;
    QGroupBox* groupBox1;
    QLabel* textLabel4;
    QLineEdit* QLEFecha;
    QLabel* textLabel4_2;
    QLineEdit* lineEdit5_2;
    QTabWidget* tabWidget3;
    QWidget* TabPage;
    QLabel* textLabel2_2;
    QTable* QTPedidoAnterior;
    QWidget* tab;
    QLabel* textLabel3;
    QTextEdit* QTEComentario;
    QWidget* tab_2;
    QLabel* textLabel3_2;
    QTextEdit* textEdit1_2;
    QPushButton* QPBAnexar;
    QPushButton* QPBRegistrar;

protected:
    QGridLayout* PedidosLayout;
    QHBoxLayout* layout8;
    QVBoxLayout* layout7;
    QHBoxLayout* layout13;
    QGridLayout* groupBox1Layout;
    QVBoxLayout* layout10;
    QVBoxLayout* layout10_2;
    QGridLayout* TabPageLayout;
    QVBoxLayout* layout7_2;
    QGridLayout* tabLayout;
    QVBoxLayout* layout9;
    QGridLayout* tabLayout_2;
    QVBoxLayout* layout9_2;
    QHBoxLayout* layout14;

protected slots:
    virtual void languageChange();

};

#endif // PEDIDOS_H
