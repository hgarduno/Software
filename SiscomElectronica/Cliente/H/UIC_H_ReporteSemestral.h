/****************************************************************************
** Form interface generated from reading ui file 'UI/ReporteSemestral.ui'
**
** Created: Thu Apr 11 21:39:51 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPORTESEMESTRAL_H
#define REPORTESEMESTRAL_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class CQControlFecha;
class QPushButton;
class QTable;

class ReporteSemestral : public QWidget
{
    Q_OBJECT

public:
    ReporteSemestral( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ReporteSemestral();

    QLabel* textLabel1;
    CQControlFecha* QCFInicio;
    QLabel* textLabel2;
    CQControlFecha* QCFFin;
    QPushButton* QPBReporte;
    QPushButton* QPBImprime;
    QTable* QTDatos;

protected:
    QGridLayout* ReporteSemestralLayout;
    QHBoxLayout* layout4;
    QSpacerItem* spacer1;
    QHBoxLayout* layout3;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // REPORTESEMESTRAL_H
