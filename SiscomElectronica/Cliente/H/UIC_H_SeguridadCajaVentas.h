/****************************************************************************
** Form interface generated from reading ui file 'UI/SeguridadCajaVentas.ui'
**
** Created: Thu Apr 11 21:39:51 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SEGURIDADCAJAVENTAS_H
#define SEGURIDADCAJAVENTAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QListView;
class QListViewItem;
class QPushButton;

class SeguridadCajaVentas : public QWidget
{
    Q_OBJECT

public:
    SeguridadCajaVentas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~SeguridadCajaVentas();

    QListView* QLVCajas;
    QPushButton* QPBActualizar;
    QPushButton* QPBRCambios;

protected:
    QGridLayout* SeguridadCajaVentasLayout;

protected slots:
    virtual void languageChange();

};

#endif // SEGURIDADCAJAVENTAS_H
