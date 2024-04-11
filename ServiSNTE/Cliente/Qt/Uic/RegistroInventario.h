/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/RegistroInventario.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROINVENTARIO_H
#define REGISTROINVENTARIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTextEdit;
class QCtrlTiendasEntrega;
class QCtrlVendedores;
class QLineEdit;

class RegistroInventario : public QWidget
{
    Q_OBJECT

public:
    RegistroInventario( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroInventario();

    QPushButton* pushButton4;
    QLabel* textLabel4;
    QTextEdit* textEdit1;
    QLabel* textLabel1;
    QCtrlTiendasEntrega* ctrlTiendasEntrega2;
    QLabel* textLabel2;
    QCtrlVendedores* ctrlVendedores1;
    QLabel* textLabel5;
    QLineEdit* lineEdit1;

protected:
    QGridLayout* RegistroInventarioLayout;
    QHBoxLayout* layout7;
    QVBoxLayout* layout6;
    QHBoxLayout* layout9;
    QVBoxLayout* layout3;
    QVBoxLayout* layout4;
    QVBoxLayout* layout8;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROINVENTARIO_H
