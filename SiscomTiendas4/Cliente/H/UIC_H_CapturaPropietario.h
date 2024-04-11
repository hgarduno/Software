/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaPropietario.ui'
**
** Created: Wed Jan 31 11:00:10 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURAPROPIETARIO_H
#define CAPTURAPROPIETARIO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class CQControlNombres;
class QSisTelefonos;
class QLabel;
class QLineEdit;
class QPushButton;
class QSisDirecciones;

class CapturaPropietario : public QDialog
{
    Q_OBJECT

public:
    CapturaPropietario( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaPropietario();

    CQControlNombres* QCtrPropietario;
    QSisTelefonos* QCtrTelefonos;
    QLabel* textLabel3;
    QLineEdit* lineEdit4;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QPushButton* QPBRegistrarP;
    QSisDirecciones* QCtrDirecciones;

protected:
    QGridLayout* CapturaPropietarioLayout;
    QVBoxLayout* layout8;
    QHBoxLayout* layout7;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURAPROPIETARIO_H
