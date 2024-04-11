/****************************************************************************
** Form interface generated from reading ui file 'UI/Clientes.ui'
**
** Created: Wed Apr 10 21:12:22 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CLIENTES_H
#define CLIENTES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTabWidget;
class QLabel;
class QLineEdit;
class QPushButton;
class QListView;
class QListViewItem;
class QComboBox;
class QTextEdit;

class Clientes : public QWidget
{
    Q_OBJECT

public:
    Clientes( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Clientes();

    QTabWidget* QTWTipoPersona;
    QWidget* tab;
    QLabel* textLabel10;
    QLineEdit* QLENombre;
    QLabel* textLabel10_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel10_2_2;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel10_2_2_2;
    QLineEdit* QLERFC;
    QWidget* tab_2;
    QLabel* textLabel11;
    QLineEdit* QLERazonSocial;
    QLabel* textLabel10_2_2_2_2;
    QLineEdit* QLERFCEmpresa;
    QWidget* TabPage;
    QPushButton* QPBRegistrar;
    QPushButton* QPBBuscar;
    QPushButton* QPBEliminar;
    QTabWidget* tabWidget4;
    QWidget* tab_3;
    QLabel* textLabel9;
    QLineEdit* QLETelefono;
    QLabel* textLabel9_2;
    QLineEdit* QLEDescripcion;
    QListView* QLVTelefonos;
    QPushButton* QPBAnexarTelefono;
    QPushButton* QPBEliminarTelefono;
    QTabWidget* tabWidget8;
    QWidget* tab_4;
    QLabel* textLabel9_2_2;
    QLineEdit* lineEdit10_2_2;
    QPushButton* QPBAnexarCorreo;
    QPushButton* QPBEliminarCorreo;
    QListView* QLVCorreos;
    QTabWidget* tabWidget3;
    QWidget* tab_5;
    QLabel* textLabel2;
    QLineEdit* QLECalle;
    QLabel* textLabel3;
    QLineEdit* QLENo;
    QLabel* textLabel3_2;
    QLineEdit* QLECP;
    QLabel* textLabel3_2_2;
    QLineEdit* QLEColonia;
    QLabel* textLabel4;
    QLineEdit* QLEMunicipio;
    QLabel* textLabel6;
    QComboBox* QCBEstados;
    QLabel* textLabel8;
    QTextEdit* QTEDirecciones;
    QPushButton* QPBSDireccion;
    QPushButton* QPBAntDireccion;
    QPushButton* QPBAgregarDireccion;
    QPushButton* QPBEliminarDireccion;
    QPushButton* QPBModificar;

protected:
    QGridLayout* ClientesLayout;
    QGridLayout* tabLayout;
    QHBoxLayout* layout50;
    QVBoxLayout* layout46;
    QVBoxLayout* layout46_2;
    QVBoxLayout* layout46_2_2;
    QVBoxLayout* layout46_2_2_2;
    QGridLayout* tabLayout_2;
    QHBoxLayout* layout53;
    QVBoxLayout* layout51;
    QVBoxLayout* layout46_2_2_2_2;
    QHBoxLayout* layout54;
    QVBoxLayout* layout44;
    QGridLayout* tabLayout_3;
    QVBoxLayout* layout42;
    QHBoxLayout* layout41;
    QVBoxLayout* layout24;
    QVBoxLayout* layout24_2;
    QHBoxLayout* layout43;
    QSpacerItem* spacer4;
    QHBoxLayout* layout23_2;
    QGridLayout* tabLayout_4;
    QSpacerItem* spacer3;
    QVBoxLayout* layout24_2_2;
    QHBoxLayout* layout23_2_2;
    QGridLayout* tabLayout_5;
    QSpacerItem* spacer2;
    QVBoxLayout* layout21;
    QHBoxLayout* layout14;
    QVBoxLayout* layout9;
    QVBoxLayout* layout11;
    QVBoxLayout* layout11_2;
    QVBoxLayout* layout11_2_2;
    QHBoxLayout* layout18;
    QVBoxLayout* layout15;
    QVBoxLayout* layout17;
    QVBoxLayout* layout22;

protected slots:
    virtual void languageChange();

};

#endif // CLIENTES_H
