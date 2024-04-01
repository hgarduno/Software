/****************************************************************************
** Form interface generated from reading ui file 'UI/CotizacionImportacionCierre.ui'
**
** Created: Wed Jan 31 10:48:07 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef COTIZACIONIMPORTACIONCIERRE_H
#define COTIZACIONIMPORTACIONCIERRE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;

class CotizacionImportacionCierre : public QDialog
{
    Q_OBJECT

public:
    CotizacionImportacionCierre( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CotizacionImportacionCierre();

    QPushButton* QPBCerrar;
    QPushButton* QPBOtraCotizacion;
    QPushButton* QPBRegistrarCotizacion;

protected:
    QGridLayout* CotizacionImportacionCierreLayout;
    QHBoxLayout* layout36;

protected slots:
    virtual void languageChange();

};

#endif // COTIZACIONIMPORTACIONCIERRE_H
