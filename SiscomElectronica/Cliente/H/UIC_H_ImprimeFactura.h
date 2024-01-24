/****************************************************************************
** Form interface generated from reading ui file 'UI/ImprimeFactura.ui'
**
** Created: Thu Dec 21 12:53:39 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef IMPRIMEFACTURA_H
#define IMPRIMEFACTURA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;

class ImprimeFactura : public QWidget
{
    Q_OBJECT

public:
    ImprimeFactura( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ImprimeFactura();


protected:

protected slots:
    virtual void languageChange();

};

#endif // IMPRIMEFACTURA_H
