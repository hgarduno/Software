/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/PagosDocumentosPagar.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PAGOSDOCUMENTOSPAGAR_H
#define PAGOSDOCUMENTOSPAGAR_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;
class QLineEdit;
class QComboBox;
class QCtrlProveedoresSS;

class PagosDocumentosPagar : public QWidget
{
    Q_OBJECT

public:
    PagosDocumentosPagar( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~PagosDocumentosPagar();

    QLabel* textLabel6;
    QTable* table1;
    QPushButton* pushButton1;
    QPushButton* pushButton2;
    QPushButton* QPBImprimir;
    QLabel* textLabel1;
    QLineEdit* lineEdit1;
    QLabel* textLabel4;
    QComboBox* comboBox1;
    QLabel* textLabel2_2;
    QCtrlProveedoresSS* ctrlProveedoresSS1_2;
    QLabel* textLabel1_2_2;
    QLineEdit* lineEdit1_2_2;
    QLabel* textLabel1_2_2_2;
    QLineEdit* lineEdit1_2_2_2;
    QLabel* textLabel4_2;
    QComboBox* comboBox1_2;
    QLabel* textLabel1_2_2_2_2;
    QLineEdit* lineEdit1_2_2_2_2;
    QLabel* textLabel1_2_2_2_2_2;
    QLineEdit* lineEdit1_2_2_2_2_2;
    QLabel* textLabel1_2_2_2_2_2_2;
    QLineEdit* lineEdit1_2_2_2_2_2_2;

protected:
    QGridLayout* PagosDocumentosPagarLayout;
    QVBoxLayout* layout14;
    QHBoxLayout* layout30;
    QVBoxLayout* layout34;
    QHBoxLayout* layout27;
    QVBoxLayout* layout1;
    QVBoxLayout* layout5;
    QVBoxLayout* layout3_2;
    QHBoxLayout* layout33;
    QVBoxLayout* layout1_2_2;
    QVBoxLayout* layout1_2_2_2;
    QVBoxLayout* layout5_2;
    QHBoxLayout* layout29;
    QVBoxLayout* layout1_2_2_2_2;
    QVBoxLayout* layout1_2_2_2_2_2;
    QVBoxLayout* layout1_2_2_2_2_2_2;

protected slots:
    virtual void languageChange();

};

#endif // PAGOSDOCUMENTOSPAGAR_H
