/****************************************************************************
** Form interface generated from reading ui file 'UI/ModuloBodegas.ui'
**
** Created: Thu Apr 11 21:39:53 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MODULOBODEGAS_H
#define MODULOBODEGAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlBodegas4;
class QTabWidget;

class ModuloBodegas : public QWidget
{
    Q_OBJECT

public:
    ModuloBodegas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ModuloBodegas();

    QLabel* textLabel1;
    QCtrlBodegas4* QCtrBodegas;
    QTabWidget* QTWOperaciones;
    QWidget* tab;

protected:
    QGridLayout* ModuloBodegasLayout;
    QVBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // MODULOBODEGAS_H
