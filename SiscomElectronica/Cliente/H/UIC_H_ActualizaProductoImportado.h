/****************************************************************************
** Form interface generated from reading ui file 'UI/ActualizaProductoImportado.ui'
**
** Created: Thu Apr 11 21:39:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ACTUALIZAPRODUCTOIMPORTADO_H
#define ACTUALIZAPRODUCTOIMPORTADO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class ActualizaProductoImportado : public QDialog
{
    Q_OBJECT

public:
    ActualizaProductoImportado( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ActualizaProductoImportado();

    QLabel* textLabel1_4_3;
    QLineEdit* QLEProducto;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel1_4;
    QLineEdit* QLECantidad;
    QLabel* textLabel1_4_2;
    QLineEdit* QLECostoUnitario;
    QLabel* textLabel1_4_2_2;
    QLineEdit* QLEPeso;

protected:
    QGridLayout* ActualizaProductoImportadoLayout;
    QGridLayout* layout28;
    QVBoxLayout* layout1_3_3;
    QHBoxLayout* layout27;
    QHBoxLayout* layout26;
    QVBoxLayout* layout1_3;
    QVBoxLayout* layout1_3_2;
    QVBoxLayout* layout1_3_2_2;

protected slots:
    virtual void languageChange();

};

#endif // ACTUALIZAPRODUCTOIMPORTADO_H
