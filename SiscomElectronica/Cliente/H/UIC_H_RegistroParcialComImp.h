/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroParcialComImp.ui'
**
** Created: Thu Dec 21 12:53:40 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROPARCIALCOMIMP_H
#define REGISTROPARCIALCOMIMP_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;

class RegistroParcialComImp : public QWidget
{
    Q_OBJECT

public:
    RegistroParcialComImp( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroParcialComImp();

    QLabel* textLabel1;
    QLineEdit* lineEdit18;
    QLabel* textLabel2;
    QTable* QTProductos;
    QPushButton* QPBRegistroProdsFaltantes;
    QPushButton* pushButton14;

protected:
    QGridLayout* RegistroParcialComImpLayout;
    QVBoxLayout* layout33;
    QVBoxLayout* layout34;
    QHBoxLayout* layout35;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROPARCIALCOMIMP_H
