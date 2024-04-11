/****************************************************************************
** Form interface generated from reading ui file 'UI/SueldosEmpleados.ui'
**
** Created: Wed Jan 31 10:47:32 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SUELDOSEMPLEADOS_H
#define SUELDOSEMPLEADOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlEmpleados;
class QLineEdit;
class QPushButton;
class QTable;

class SueldosEmpleados : public QWidget
{
    Q_OBJECT

public:
    SueldosEmpleados( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~SueldosEmpleados();

    QLabel* textLabel1;
    QCtrlEmpleados* QCtrEmpleados;
    QLabel* textLabel2;
    QLineEdit* lineEdit1;
    QLabel* textLabel2_2;
    QLineEdit* lineEdit1_2;
    QPushButton* pushButton2;
    QLabel* textLabel3;
    QTable* table1;
    QPushButton* QPBCambia;
    QPushButton* pushButton1_2;

protected:
    QGridLayout* SueldosEmpleadosLayout;
    QVBoxLayout* layout1;
    QHBoxLayout* layout4;
    QVBoxLayout* layout2;
    QVBoxLayout* layout2_2;
    QVBoxLayout* layout5;
    QHBoxLayout* layout6;

protected slots:
    virtual void languageChange();

};

#endif // SUELDOSEMPLEADOS_H
