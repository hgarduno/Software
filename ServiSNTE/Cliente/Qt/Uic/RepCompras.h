/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/RepCompras.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPCOMPRAS_H
#define REPCOMPRAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QCtrlProveedoresSS;
class QCtrlDepartamentosSS;
class QTable;

class RepCompras : public QWidget
{
    Q_OBJECT

public:
    RepCompras( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RepCompras();

    QPushButton* QPBConsultar;
    QPushButton* QPBImprimir;
    QLabel* textLabel1;
    QCtrlProveedoresSS* QCtrProveedores;
    QLabel* textLabel1_2;
    QCtrlDepartamentosSS* QCtrDepartamentos;
    QTable* QTDatos;

protected:
    QGridLayout* RepComprasLayout;
    QHBoxLayout* layout2;
    QVBoxLayout* layout1;
    QVBoxLayout* layout25;

protected slots:
    virtual void languageChange();

};

#endif // REPCOMPRAS_H
