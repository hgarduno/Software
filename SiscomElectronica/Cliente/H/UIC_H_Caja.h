/****************************************************************************
** Form interface generated from reading ui file 'UI/Caja.ui'
**
** Created: lun abr 1 18:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAJA_H
#define CAJA_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QIconView;
class QIconViewItem;
class QPushButton;

class Caja : public QWidget
{
    Q_OBJECT

public:
    Caja( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Caja();

    QIconView* QIVOrdenes;
    QPushButton* QPBMOrden;
    QPushButton* QPBActualiza;

protected:
    QGridLayout* CajaLayout;
    QHBoxLayout* layout2;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

};

#endif // CAJA_H
