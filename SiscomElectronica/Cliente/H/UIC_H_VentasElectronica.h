/****************************************************************************
** Form interface generated from reading ui file 'UI/VentasElectronica.ui'
**
** Created: Thu Dec 21 13:55:36 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef VENTASELECTRONICA_H
#define VENTASELECTRONICA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QToolBox;
class QIconView;
class QIconViewItem;
class QLabel;
class QPushButton;

class VentasElectronica : public QWidget
{
    Q_OBJECT

public:
    VentasElectronica( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~VentasElectronica();

    QToolBox* toolBox1;
    QWidget* page1;
    QIconView* QIVOrdenes;
    QLabel* textLabel1;
    QIconView* iconView2;
    QPushButton* QPBNOrden;
    QPushButton* QPBVenderTodo;
    QPushButton* QPBRPSinOrden;
    QPushButton* QPBCotizaPractica;

protected:
    QGridLayout* VentasElectronicaLayout;
    QGridLayout* page1Layout;

protected slots:
    virtual void languageChange();

};

#endif // VENTASELECTRONICA_H
