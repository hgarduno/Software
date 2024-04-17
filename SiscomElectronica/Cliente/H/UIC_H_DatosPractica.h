/****************************************************************************
** Form interface generated from reading ui file 'UI/DatosPractica.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DATOSPRACTICA_H
#define DATOSPRACTICA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlMateriasSE;
class QLineEdit;
class QTextEdit;
class QPushButton;

class DatosPractica : public QDialog
{
    Q_OBJECT

public:
    DatosPractica( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~DatosPractica();

    QLabel* textLabel1_2;
    QCtrlMateriasSE* QCtrMaterias;
    QLabel* textLabel1;
    QLineEdit* lineEdit3;
    QLabel* textLabel2;
    QTextEdit* textEdit1;
    QPushButton* pushButton5;
    QPushButton* pushButton6;

protected:
    QGridLayout* DatosPracticaLayout;
    QHBoxLayout* layout3;
    QVBoxLayout* layout2;
    QVBoxLayout* layout10;
    QVBoxLayout* layout4;

protected slots:
    virtual void languageChange();

};

#endif // DATOSPRACTICA_H
