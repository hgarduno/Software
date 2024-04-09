/****************************************************************************
** Form interface generated from reading ui file 'UI/ProgramacionPlacas.ui'
**
** Created: lun abr 1 18:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PROGRAMACIONPLACAS_H
#define PROGRAMACIONPLACAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QTable;
class QLabel;
class CQControlFecha;

class ProgramacionPlacas : public QWidget
{
    Q_OBJECT

public:
    ProgramacionPlacas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ProgramacionPlacas();

    QPushButton* QPBPPendientes;
    QPushButton* QPBEntregar;
    QTable* QTDatos;
    QLabel* textLabel1;
    QLabel* textLabel2;
    CQControlFecha* QCtrFechaInicio;
    QLabel* textLabel3;
    CQControlFecha* QCtrFechaFin;

protected:
    QGridLayout* ProgramacionPlacasLayout;
    QHBoxLayout* layout1;
    QHBoxLayout* layout5;
    QSpacerItem* spacer1;
    QHBoxLayout* layout4;
    QVBoxLayout* layout2;
    QVBoxLayout* layout3;

protected slots:
    virtual void languageChange();

};

#endif // PROGRAMACIONPLACAS_H
