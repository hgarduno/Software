/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroClientes.ui'
**
** Created: Fri Apr 12 21:36:40 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROCLIENTES_H
#define REGISTROCLIENTES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QTabWidget;
class QSisDirecciones;
class QSisTelefonos;
class QLabel;
class QLineEdit;

class RegistroClientes : public QWidget
{
    Q_OBJECT

public:
    RegistroClientes( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroClientes();

    QPushButton* QPBRegistrar;
    QTabWidget* QTWidget;
    QWidget* tab;
    QSisDirecciones* QSDirecciones;
    QWidget* tab_2;
    QSisTelefonos* QSTelefonos;
    QLabel* textLabel1;
    QLineEdit* QLENombre;
    QLabel* textLabel1_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel1_2_2;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel1_3;
    QLineEdit* QLERFC;

protected:
    QGridLayout* RegistroClientesLayout;
    QGridLayout* tabLayout;
    QGridLayout* tabLayout_2;
    QHBoxLayout* layout6;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;
    QVBoxLayout* layout1_2_2;
    QVBoxLayout* layout5;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROCLIENTES_H
