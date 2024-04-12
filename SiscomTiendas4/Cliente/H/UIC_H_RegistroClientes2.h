/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroClientes2.ui'
**
** Created: Thu Apr 11 22:09:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROCLIENTES2_H
#define REGISTROCLIENTES2_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTabWidget;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;

class RegistroClientes2 : public QWidget
{
    Q_OBJECT

public:
    RegistroClientes2( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroClientes2();

    QTabWidget* QTWPersonas;
    QWidget* tab;
    QLabel* textLabel1;
    QLineEdit* QLENombre;
    QLabel* textLabel1_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel1_2_2;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel1_3;
    QLineEdit* QLERFC;
    QWidget* tab_2;
    QLabel* textLabel1_4;
    QLineEdit* QLERazonSocial;
    QLabel* textLabel1_3_2;
    QLineEdit* QLERFCPM;
    QLabel* textLabel4;
    QTable* QTDirecciones;
    QPushButton* QPBRegistraG;
    QPushButton* QPBADireccion;
    QPushButton* pushButton2_3;
    QLabel* textLabel1_5;
    QLabel* textLabel2;
    QLineEdit* QLEDLinea1;
    QLabel* textLabel2_2;
    QLineEdit* QLEDLinea2;
    QLabel* textLabel2_2_2;
    QLineEdit* QLEDLinea3;
    QLabel* textLabel2_2_3;
    QLineEdit* QLEDLinea4;

protected:
    QGridLayout* RegistroClientes2Layout;
    QVBoxLayout* tabLayout;
    QSpacerItem* spacer1;
    QHBoxLayout* layout6;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;
    QVBoxLayout* layout1_2_2;
    QVBoxLayout* layout5;
    QVBoxLayout* tabLayout_2;
    QSpacerItem* spacer2;
    QVBoxLayout* layout1_3;
    QVBoxLayout* layout5_2;
    QVBoxLayout* layout16;
    QHBoxLayout* layout18;
    QVBoxLayout* layout23;
    QHBoxLayout* layout14;
    QHBoxLayout* layout14_2;
    QHBoxLayout* layout14_2_2;
    QHBoxLayout* layout14_2_3;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROCLIENTES2_H
