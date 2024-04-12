/****************************************************************************
** Form interface generated from reading ui file 'UI/Facturando.ui'
**
** Created: Thu Apr 11 21:51:14 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FACTURANDO_H
#define FACTURANDO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;

class Facturando : public QWidget
{
    Q_OBJECT

public:
    Facturando( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Facturando();

    QTable* table12;

protected:
    QGridLayout* FacturandoLayout;
    QSpacerItem* spacer8;

protected slots:
    virtual void languageChange();

};

#endif // FACTURANDO_H
