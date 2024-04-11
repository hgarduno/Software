/****************************************************************************
** Form interface generated from reading ui file 'UI/UI_ControlFormas.ui'
**
** Created: Sat Jan 27 16:42:05 2024
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
