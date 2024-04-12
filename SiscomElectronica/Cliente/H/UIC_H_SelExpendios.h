/****************************************************************************
** Form interface generated from reading ui file 'UI/SelExpendios.ui'
**
** Created: Thu Apr 11 21:39:45 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SELEXPENDIOS_H
#define SELEXPENDIOS_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QIconView;
class QIconViewItem;

class SelExpendios : public QDialog
{
    Q_OBJECT

public:
    SelExpendios( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~SelExpendios();

    QIconView* QIVExpendios;

protected:
    QGridLayout* SelExpendiosLayout;

protected slots:
    virtual void languageChange();

};

#endif // SELEXPENDIOS_H
