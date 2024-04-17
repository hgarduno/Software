/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroCotizacionImportacion.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROCOTIZACIONIMPORTACION_H
#define REGISTROCOTIZACIONIMPORTACION_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTextEdit;
class QTable;

class RegistroCotizacionImportacion : public QDialog
{
    Q_OBJECT

public:
    RegistroCotizacionImportacion( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~RegistroCotizacionImportacion();

    QPushButton* QPBCancelar;
    QPushButton* QPBRegistrar;
    QLabel* textLabel6;
    QTextEdit* QTECotizacion;
    QLabel* textLabel7;
    QTable* QTCotizaciones;

protected:
    QGridLayout* RegistroCotizacionImportacionLayout;
    QVBoxLayout* layout12;
    QVBoxLayout* layout10;
    QVBoxLayout* layout9;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROCOTIZACIONIMPORTACION_H
