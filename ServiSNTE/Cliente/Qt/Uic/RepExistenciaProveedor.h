/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/RepExistenciaProveedor.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPEXISTENCIAPROVEEDOR_H
#define REPEXISTENCIAPROVEEDOR_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProveedoresSS;
class QPushButton;
class QTable;

class RepExistenciaProveedor : public QWidget
{
    Q_OBJECT

public:
    RepExistenciaProveedor( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RepExistenciaProveedor();

    QLabel* textLabel1;
    QCtrlProveedoresSS* QCtrProveedores;
    QPushButton* QPBConsulta;
    QPushButton* QPBImprimir;
    QTable* QTExistenciaProveedor;

protected:
    QGridLayout* RepExistenciaProveedorLayout;
    QVBoxLayout* layout1;
    QHBoxLayout* layout4;

protected slots:
    virtual void languageChange();

};

#endif // REPEXISTENCIAPROVEEDOR_H
