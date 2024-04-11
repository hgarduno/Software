/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaCantidad.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURACANTIDAD_H
#define CAPTURACANTIDAD_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class CapturaCantidad : public QDialog
{
    Q_OBJECT

public:
    CapturaCantidad( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaCantidad();

    QLabel* textLabel2;
    QLineEdit* QLECantidad;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaCantidadLayout;
    QVBoxLayout* layout90;
    QHBoxLayout* layout89;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURACANTIDAD_H
