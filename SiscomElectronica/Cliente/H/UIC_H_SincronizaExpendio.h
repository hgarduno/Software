/****************************************************************************
** Form interface generated from reading ui file 'UI/SincronizaExpendio.ui'
**
** Created: Wed Apr 10 20:52:30 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SINCRONIZAEXPENDIO_H
#define SINCRONIZAEXPENDIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlExpendios;
class QPushButton;
class QTable;

class SincronizaExpendio : public QWidget
{
    Q_OBJECT

public:
    SincronizaExpendio( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~SincronizaExpendio();

    QLabel* textLabel1_2;
    QCtrlExpendios* QCtrExpendiosO;
    QPushButton* QPBSincronizaProd;
    QPushButton* QPBSincronizaPrec;
    QPushButton* QPBSincronizaCli;
    QPushButton* QPBSincronizaTodo;
    QLabel* textLabel1;
    QTable* table1;

protected:
    QGridLayout* SincronizaExpendioLayout;
    QVBoxLayout* layout6;
    QHBoxLayout* layout4;
    QVBoxLayout* layout3;

protected slots:
    virtual void languageChange();

};

#endif // SINCRONIZAEXPENDIO_H
