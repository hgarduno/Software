/****************************************************************************
** Form interface generated from reading ui file 'UI/VendiendoOrden.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef VENDIENDOORDEN_H
#define VENDIENDOORDEN_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;

class VendiendoOrden : public QDialog
{
    Q_OBJECT

public:
    VendiendoOrden( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~VendiendoOrden();

    QPushButton* QPBImprimir;
    QPushButton* QPBVender;

protected:
    QGridLayout* VendiendoOrdenLayout;
    QHBoxLayout* layout8;

protected slots:
    virtual void languageChange();

};

#endif // VENDIENDOORDEN_H
