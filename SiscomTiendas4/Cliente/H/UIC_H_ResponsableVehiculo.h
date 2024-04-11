/****************************************************************************
** Form interface generated from reading ui file 'UI/ResponsableVehiculo.ui'
**
** Created: Wed Jan 31 10:59:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef RESPONSABLEVEHICULO_H
#define RESPONSABLEVEHICULO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class CQControlNombres;
class QLabel;
class QLineEdit;
class QPushButton;

class ResponsableVehiculo : public QDialog
{
    Q_OBJECT

public:
    ResponsableVehiculo( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ResponsableVehiculo();

    CQControlNombres* QCtrNombre;
    QLabel* textLabel2;
    QLineEdit* QLECargo;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* ResponsableVehiculoLayout;
    QVBoxLayout* layout6;
    QHBoxLayout* layout7;

protected slots:
    virtual void languageChange();

};

#endif // RESPONSABLEVEHICULO_H
