/****************************************************************************
** Form interface generated from reading ui file 'UI/AccesoSiscomElectronica.ui'
**
** Created: lun abr 1 18:04:50 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ACCESOSISCOMELECTRONICA_H
#define ACCESOSISCOMELECTRONICA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QIconView;
class QIconViewItem;

class AccesoSiscomElectronica : public QDialog
{
    Q_OBJECT

public:
    AccesoSiscomElectronica( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~AccesoSiscomElectronica();

    QPushButton* QPBSLetra;
    QPushButton* QPBAceptar;
    QIconView* QIconViewInforma;

protected:
    QGridLayout* AccesoSiscomElectronicaLayout;
    QHBoxLayout* layout21;

protected slots:
    virtual void languageChange();

};

#endif // ACCESOSISCOMELECTRONICA_H
