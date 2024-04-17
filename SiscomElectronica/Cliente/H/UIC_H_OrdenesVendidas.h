/****************************************************************************
** Form interface generated from reading ui file 'UI/OrdenesVendidas.ui'
**
** Created: Fri Apr 12 21:36:20 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ORDENESVENDIDAS_H
#define ORDENESVENDIDAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QTable;
class QLCDNumber;
class QLabel;
class QLineEdit;
class CQControlFecha;

class OrdenesVendidas : public QWidget
{
    Q_OBJECT

public:
    OrdenesVendidas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~OrdenesVendidas();

    QPushButton* QPBOFecha;
    QPushButton* pushButton16;
    QPushButton* pushButton17;
    QPushButton* pushButton18;
    QPushButton* QPBFacturar;
    QTable* QTDatos;
    QPushButton* QPBAOrden;
    QPushButton* QPBNOrden;
    QLCDNumber* lCDNumber1;
    QLabel* textLabel4;
    QLineEdit* QLENoOrden;
    QLabel* textLabel5;
    CQControlFecha* QCFSFechaIni;
    CQControlFecha* QCFSFechaFin;

protected:
    QGridLayout* OrdenesVendidasLayout;
    QHBoxLayout* layout37;
    QHBoxLayout* layout39;
    QVBoxLayout* layout38;
    QVBoxLayout* layout31;
    QVBoxLayout* layout68;
    QHBoxLayout* layout67;
    QSpacerItem* spacer9;

protected slots:
    virtual void languageChange();

};

#endif // ORDENESVENDIDAS_H
