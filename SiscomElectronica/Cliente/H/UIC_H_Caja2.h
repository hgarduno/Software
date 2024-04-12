/****************************************************************************
** Form interface generated from reading ui file 'UI/Caja2.ui'
**
** Created: Thu Apr 11 21:39:52 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAJA2_H
#define CAJA2_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QTable;

class Caja2 : public QWidget
{
    Q_OBJECT

public:
    Caja2( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Caja2();

    QPushButton* QPBOrdenesPendientes;
    QTable* table1;

protected:
    QGridLayout* Caja2Layout;

protected slots:
    virtual void languageChange();

};

#endif // CAJA2_H
