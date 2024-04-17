/****************************************************************************
** Form interface generated from reading ui file 'UI/UI_CapturaDatos.ui'
**
** Created: Fri Apr 12 21:23:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURADATOS_H
#define CAPTURADATOS_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class CapturaDatos : public QDialog
{
    Q_OBJECT

public:
    CapturaDatos( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaDatos();

    QLabel* textLabel2;
    QLineEdit* QLEDatos;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaDatosLayout;
    QVBoxLayout* layout21;
    QHBoxLayout* layout22;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURADATOS_H
