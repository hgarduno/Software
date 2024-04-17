/****************************************************************************
** Form interface generated from reading ui file 'UI/CtrExpendios.ui'
**
** Created: Fri Apr 12 21:35:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CTREXPENDIOS_H
#define CTREXPENDIOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QIconView;
class QIconViewItem;
class QPushButton;

class CtrExpendios : public QWidget
{
    Q_OBJECT

public:
    CtrExpendios( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CtrExpendios();

    QIconView* QIVExpendios;
    QPushButton* QPBCEEActual;

protected:
    QGridLayout* CtrExpendiosLayout;

protected slots:
    virtual void languageChange();

};

#endif // CTREXPENDIOS_H
