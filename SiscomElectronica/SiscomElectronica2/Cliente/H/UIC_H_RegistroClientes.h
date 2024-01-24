/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroClientes.ui'
**
** Created: Fri Aug 4 21:21:10 2023
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
class QLabel;
class QLineEdit;
class QTable;
class QSisSepomex;
class QCtrlEscuelas;

class RegistroClientes : public QWidget
{
    Q_OBJECT

public:
    RegistroClientes( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroClientes();

    QPushButton* QPBRGenerales;
    QPushButton* pushButton19;
    QPushButton* pushButton20;
    QTabWidget* tabWidget26;
    QWidget* tab;
    QLabel* textLabel3_5;
    QLineEdit* lineEdit4_4;
    QPushButton* QPBSDireccion_4_2;
    QPushButton* QPBAntDireccion_4_2;
    QPushButton* QPBAgregarDireccion_4_2;
    QPushButton* QPBEliminarDireccion_4_2;
    QPushButton* QPBModificar_4_2;
    QTable* table6;
    QTabWidget* tabWidget3;
    QWidget* tab_2;
    QTable* table1;
    QSisSepomex* QCtrSepomex;
    QLabel* textLabel4;
    QPushButton* QPBSDireccion;
    QPushButton* QPBAntDireccion;
    QPushButton* QPBAgregarDireccion;
    QPushButton* QPBEliminarDireccion;
    QPushButton* QPBModificar;
    QTabWidget* tabWidget22;
    QWidget* tab_3;
    QPushButton* QPBSDireccion_4;
    QPushButton* QPBAntDireccion_4;
    QPushButton* QPBAgregarDireccion_4;
    QPushButton* QPBEliminarDireccion_4;
    QPushButton* QPBModificar_4;
    QTable* table2;
    QLabel* textLabel3_4;
    QLineEdit* lineEdit4_3;
    QTabWidget* tabWidget2;
    QWidget* tab_4;
    QLabel* textLabel3;
    QLineEdit* QLENombre;
    QLabel* textLabel3_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel3_2_2;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel1;
    QCtrlEscuelas* QCtrEscuelas;
    QLabel* textLabel2;
    QLineEdit* QLEGrupo;
    QWidget* tab_5;
    QWidget* TabPage;

protected:
    QGridLayout* RegistroClientesLayout;
    QHBoxLayout* layout40;
    QGridLayout* tabLayout;
    QVBoxLayout* layout5_4;
    QHBoxLayout* layout37_3_2;
    QSpacerItem* spacer2_4_2;
    QGridLayout* tabLayout_2;
    QHBoxLayout* layout37;
    QSpacerItem* spacer2;
    QGridLayout* tabLayout_3;
    QHBoxLayout* layout37_3;
    QSpacerItem* spacer2_4;
    QVBoxLayout* layout5_3;
    QGridLayout* tabLayout_4;
    QVBoxLayout* layout5;
    QVBoxLayout* layout5_2;
    QVBoxLayout* layout5_2_2;
    QHBoxLayout* layout12;
    QSpacerItem* spacer4;
    QVBoxLayout* layout10;
    QVBoxLayout* layout11;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROCLIENTES_H
