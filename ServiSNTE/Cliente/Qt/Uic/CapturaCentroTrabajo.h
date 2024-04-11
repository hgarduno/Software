/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaCentroTrabajo.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURACENTROTRABAJO_H
#define CAPTURACENTROTRABAJO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class CapturaCentroTrabajo : public QDialog
{
    Q_OBJECT

public:
    CapturaCentroTrabajo( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaCentroTrabajo();

    QLabel* textLabel1_2;
    QLineEdit* QLECentroTrabajo;
    QLabel* textLabel1;
    QLineEdit* QLEClavePresupuestal;
    QPushButton* QPBRegistrar;
    QPushButton* QPBCancelar;
    QPushButton* QPBAceptar;
    QPushButton* QPBActualizar;

protected:
    QGridLayout* CapturaCentroTrabajoLayout;
    QHBoxLayout* layout4;
    QVBoxLayout* layout1_2;
    QVBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURACENTROTRABAJO_H
