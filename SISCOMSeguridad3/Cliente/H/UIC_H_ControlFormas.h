/****************************************************************************
** Form interface generated from reading ui file 'UI/UI_ControlFormas.ui'
**
** Created: Fri Apr 12 21:23:37 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONTROLFORMAS_H
#define CONTROLFORMAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QListView;
class QListViewItem;

class ControlFormas : public QWidget
{
    Q_OBJECT

public:
    ControlFormas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ControlFormas();

    QListView* QLVLista;

protected:
    QGridLayout* ControlFormasLayout;

protected slots:
    virtual void languageChange();

};

#endif // CONTROLFORMAS_H
