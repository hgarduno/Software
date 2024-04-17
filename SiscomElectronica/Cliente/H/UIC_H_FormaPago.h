/****************************************************************************
** Form interface generated from reading ui file 'UI/FormaPago.ui'
**
** Created: Fri Apr 12 21:33:12 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORMAPAGO_H
#define FORMAPAGO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTabWidget;
class QWidget;
class QButtonGroup;
class QRadioButton;
class QTextEdit;
class QPushButton;

class FormaPago : public QDialog
{
    Q_OBJECT

public:
    FormaPago( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~FormaPago();

    QLabel* textLabel2;
    QLineEdit* lineEdit19;
    QTabWidget* QTWFormaPago;
    QWidget* tab;
    QButtonGroup* buttonGroup1;
    QRadioButton* radioButton2;
    QRadioButton* radioButton1;
    QLabel* textLabel3;
    QTextEdit* textEdit2;
    QWidget* tab_2;
    QLabel* textLabel3_2;
    QTextEdit* textEdit2_2;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* FormaPagoLayout;
    QVBoxLayout* layout40;
    QGridLayout* tabLayout;
    QGridLayout* buttonGroup1Layout;
    QVBoxLayout* layout41;
    QGridLayout* tabLayout_2;
    QVBoxLayout* layout41_2;

protected slots:
    virtual void languageChange();

};

#endif // FORMAPAGO_H
