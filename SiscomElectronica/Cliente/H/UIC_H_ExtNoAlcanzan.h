/****************************************************************************
** Form interface generated from reading ui file 'UI/ExtNoAlcanzan.ui'
**
** Created: Thu Apr 11 21:51:25 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef EXTNOALCANZAN_H
#define EXTNOALCANZAN_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;

class ExtNoAlcanzan : public QWidget
{
    Q_OBJECT

public:
    ExtNoAlcanzan( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ExtNoAlcanzan();

    QTable* QTDatos;

protected:
    QGridLayout* ExtNoAlcanzanLayout;

protected slots:
    virtual void languageChange();

};

#endif // EXTNOALCANZAN_H
