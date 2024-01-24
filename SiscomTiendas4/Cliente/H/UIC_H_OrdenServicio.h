/****************************************************************************
** Form interface generated from reading ui file 'UI/OrdenServicio.ui'
**
** Created: Sun Feb 9 03:08:48 2020
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ORDENSERVICIO_H
#define ORDENSERVICIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;
class QTable;
class QTextEdit;
class QLCDNumber;
class QCtrlFechaHora;

class OrdenServicio : public QWidget
{
    Q_OBJECT

public:
    OrdenServicio( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~OrdenServicio();

    QPushButton* pushButton17;
    QLabel* textLabel1;
    QLineEdit* QLEResponsableCargo;
    QPushButton* QPBCEVehiculo;
    QLabel* textLabel1_2;
    QLineEdit* QLEPropietario;
    QPushButton* QPBPropietario;
    QLabel* textLabel1_3;
    QTable* QTDirecciones;
    QLabel* textLabel1_3_2;
    QTable* QTTelefonos;
    QLabel* textLabel1_4;
    QTextEdit* textEdit3;
    QLabel* textLabel4_3;
    QTable* table7;
    QLabel* textLabel5_3_3;
    QLCDNumber* lCDNumber2_3;
    QLabel* textLabel5_3_2;
    QLCDNumber* lCDNumber2_2;
    QLabel* textLabel5_3_4_2;
    QLCDNumber* lCDNumber2_4_2;
    QLabel* textLabel5_3;
    QLCDNumber* lCDNumber2;
    QLabel* textLabel5_3_4;
    QLCDNumber* lCDNumber2_4;
    QLabel* textLabel4;
    QCtrlFechaHora* CtrFHRecepcion;
    QLabel* textLabel4_2;
    QCtrlFechaHora* CtrFHEntrega;
    QLabel* textLabel5;
    QLineEdit* lineEdit5;
    QLabel* textLabel5_2;
    QLineEdit* lineEdit5_2;
    QLabel* textLabel5_2_2;
    QLineEdit* lineEdit5_2_2;
    QPushButton* pushButton7;
    QLabel* textLabel5_2_2_2;
    QLineEdit* lineEdit5_2_2_2;
    QPushButton* pushButton7_2;
    QLabel* textLabel1_4_2;
    QTextEdit* textEdit3_2;

protected:
    QGridLayout* OrdenServicioLayout;
    QVBoxLayout* layout44;
    QVBoxLayout* layout43;
    QHBoxLayout* layout2;
    QVBoxLayout* layout1;
    QHBoxLayout* layout2_2;
    QVBoxLayout* layout1_2;
    QVBoxLayout* layout41;
    QVBoxLayout* layout5;
    QVBoxLayout* layout5_2;
    QVBoxLayout* layout47;
    QVBoxLayout* layout55;
    QVBoxLayout* layout64;
    QVBoxLayout* layout63;
    QVBoxLayout* layout56_3;
    QVBoxLayout* layout56_2;
    QHBoxLayout* layout62;
    QVBoxLayout* layout56_4_2;
    QVBoxLayout* layout56;
    QVBoxLayout* layout56_4;
    QVBoxLayout* layout48;
    QHBoxLayout* layout66;
    QSpacerItem* spacer2_2;
    QVBoxLayout* layout11;
    QHBoxLayout* layout67;
    QSpacerItem* spacer2;
    QVBoxLayout* layout11_2;
    QVBoxLayout* layout13;
    QVBoxLayout* layout13_2;
    QHBoxLayout* layout17;
    QVBoxLayout* layout13_2_2;
    QHBoxLayout* layout18;
    QVBoxLayout* layout13_2_2_2;
    QVBoxLayout* layout47_2;

protected slots:
    virtual void languageChange();

};

#endif // ORDENSERVICIO_H
