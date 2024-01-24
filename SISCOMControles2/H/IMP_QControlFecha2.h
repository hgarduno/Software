/****************************************************************************
** Form interface generated from reading ui file 'UI/CQControlFecha2.ui'
**
** Created: Wed May 31 17:48:48 2006
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.5   edited Aug 31 12:13 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef __CQCONTROLFECHA2_H__
#define __CQCONTROLFECHA2_H__

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLineEdit;

class CQControlFecha2 : public QWidget
{
    Q_OBJECT

public:
    CQControlFecha2( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CQControlFecha2();

    QLineEdit* QLEAno;
    QLineEdit* QLEDia;
    QLineEdit* QLEMes;

protected:
    QGridLayout* CQControlFecha2Layout;

protected slots:
    virtual void languageChange();

};

#endif // QCONTROLFECHA_H
