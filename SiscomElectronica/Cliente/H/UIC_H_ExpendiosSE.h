/****************************************************************************
** Form interface generated from reading ui file 'UI/ExpendiosSE.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef EXPENDIOSSE_H
#define EXPENDIOSSE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QCtrlExpendiosSE;

class ExpendiosSE : public QDialog
{
    Q_OBJECT

public:
    ExpendiosSE( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ExpendiosSE();

    QCtrlExpendiosSE* ctrlExpendiosSE1;

protected:
    QGridLayout* ExpendiosSELayout;

protected slots:
    virtual void languageChange();

};

#endif // EXPENDIOSSE_H
