/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroClientes.ui'
**
** Created: Wed Apr 10 20:52:29 2024
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
class QSisDirecciones;
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
    QSisDirecciones* QDirecciones;
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
    QLabel* textLabel2;
    QLineEdit* QLEGrupo;
    QLabel* textLabel2_2;
    QLineEdit* QLEBoleta;
    QLabel* textLabel1;
    QCtrlEscuelas* QCtrEscuelas;
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
    QGridLayout* tabLayout_3;
    QHBoxLayout* layout37_3;
    QSpacerItem* spacer2_4;
    QVBoxLayout* layout5_3;
    QGridLayout* tabLayout_4;
    QHBoxLayout* layout12;
    QVBoxLayout* layout5;
    QVBoxLayout* layout5_2;
    QVBoxLayout* layout5_2_2;
    QVBoxLayout* layout11;
    QVBoxLayout* layout11_2;
    QVBoxLayout* layout10;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROCLIENTES_H
