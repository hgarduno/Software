/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaNoCotizacion.ui'
**
** Created: Wed Jan 31 10:47:52 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURANOCOTIZACION_H
#define CAPTURANOCOTIZACION_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class CapturaNoCotizacion : public QDialog
{
    Q_OBJECT

public:
    CapturaNoCotizacion( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaNoCotizacion();

    QLabel* textLabel4;
    QLineEdit* QLENoCtizacion;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaNoCotizacionLayout;
    QVBoxLayout* layout31;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURANOCOTIZACION_H
