/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/RegistroLibro.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROLIBRO_H
#define REGISTROLIBRO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QCtrlProveedoresSS;
class QCtrlConceptosExistencias;
class QComboBox;
class QTable;
class QPushButton;

class RegistroLibro : public QWidget
{
    Q_OBJECT

public:
    RegistroLibro( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroLibro();

    QLabel* textLabel1;
    QLineEdit* lineEdit1;
    QLabel* textLabel1_2;
    QLineEdit* lineEdit1_2;
    QLabel* textLabel2;
    QCtrlProveedoresSS* ctrlProveedoresSS1;
    QLabel* textLabel5;
    QLineEdit* lineEdit3;
    QLabel* textLabel5_2;
    QLineEdit* lineEdit3_2;
    QLabel* textLabel5_2_2;
    QLineEdit* lineEdit3_2_2;
    QLabel* textLabel5_2_2_2;
    QLineEdit* lineEdit3_2_2_2;
    QLabel* textLabel5_2_2_2_2;
    QLineEdit* lineEdit3_2_2_2_2;
    QLabel* textLabel3;
    QCtrlConceptosExistencias* ctrlConceptosExistencias1;
    QLabel* textLabel4;
    QComboBox* comboBox1;
    QLabel* textLabel6;
    QTable* table1;
    QPushButton* pushButton1;
    QPushButton* pushButton2;
    QPushButton* QPBImprimir;

protected:
    QGridLayout* RegistroLibroLayout;
    QHBoxLayout* layout11;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;
    QVBoxLayout* layout3;
    QHBoxLayout* layout13;
    QVBoxLayout* layout6;
    QVBoxLayout* layout6_2;
    QVBoxLayout* layout6_2_2;
    QVBoxLayout* layout6_2_2_2;
    QVBoxLayout* layout6_2_2_2_2;
    QHBoxLayout* layout12;
    QVBoxLayout* layout4;
    QVBoxLayout* layout5;
    QVBoxLayout* layout14;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROLIBRO_H
