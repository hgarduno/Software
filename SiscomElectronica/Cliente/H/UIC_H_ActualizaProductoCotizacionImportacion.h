/****************************************************************************
** Form interface generated from reading ui file 'UI/ActualizaProductoCotizacionImportacion.ui'
**
** Created: Thu Dec 21 12:53:40 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ACTUALIZAPRODUCTOCOTIZACIONIMPORTACION_H
#define ACTUALIZAPRODUCTOCOTIZACIONIMPORTACION_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class ActualizaProductoCotizacionImportacion : public QDialog
{
    Q_OBJECT

public:
    ActualizaProductoCotizacionImportacion( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ActualizaProductoCotizacionImportacion();

    QLabel* textLabel9;
    QLineEdit* QLEClave;
    QLabel* textLabel9_3;
    QLineEdit* QLECantidad;
    QLabel* textLabel9_2;
    QLineEdit* QLEPrecio;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* ActualizaProductoCotizacionImportacionLayout;
    QVBoxLayout* layout23;
    QHBoxLayout* layout22;
    QVBoxLayout* layout18;
    QVBoxLayout* layout18_3;
    QVBoxLayout* layout18_2;
    QHBoxLayout* layout21;

protected slots:
    virtual void languageChange();

};

#endif // ACTUALIZAPRODUCTOCOTIZACIONIMPORTACION_H
