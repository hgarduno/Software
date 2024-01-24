/****************************************************************************
** Form interface generated from reading ui file 'UI/ProgramaInventario.ui'
**
** Created: Thu Dec 21 13:56:56 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PROGRAMAINVENTARIO_H
#define PROGRAMAINVENTARIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QTable;
class CQControlFecha;
class QLineEdit;
class QPushButton;

class ProgramaInventario : public QWidget
{
    Q_OBJECT

public:
    ProgramaInventario( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ProgramaInventario();

    QLabel* textLabel1;
    QComboBox* comboBox3;
    QTable* table1;
    QLabel* textLabel1_2;
    QLabel* textLabel2;
    CQControlFecha* controlFechaDesarrollo21;
    QLabel* textLabel2_2;
    QLabel* textLabel1_3;
    QLineEdit* lineEdit1;
    QLabel* textLabel3;
    CQControlFecha* controlFechaDesarrollo21_2;
    QPushButton* pushButton1_2;
    QPushButton* pushButton1_3;
    QPushButton* pushButton1;

protected:
    QGridLayout* ProgramaInventarioLayout;
    QVBoxLayout* layout5;
    QHBoxLayout* layout5_2;
    QSpacerItem* spacer2;
    QVBoxLayout* layout4;
    QHBoxLayout* layout3;
    QSpacerItem* spacer1;
    QHBoxLayout* layout16;
    QVBoxLayout* layout10;
    QVBoxLayout* layout15;
    QHBoxLayout* layout14;
    QSpacerItem* spacer5;
    QHBoxLayout* layout17;

protected slots:
    virtual void languageChange();

};

#endif // PROGRAMAINVENTARIO_H
