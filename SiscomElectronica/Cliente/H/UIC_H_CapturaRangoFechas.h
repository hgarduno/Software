/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaRangoFechas.ui'
**
** Created: Thu Apr 11 21:05:11 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURARANGOFECHAS_H
#define CAPTURARANGOFECHAS_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class CQControlFecha;
class QPushButton;

class CapturaRangoFechas : public QDialog
{
    Q_OBJECT

public:
    CapturaRangoFechas( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaRangoFechas();

    QLabel* textLabel1;
    CQControlFecha* QSisContFechaIni;
    QLabel* textLabel1_2;
    CQControlFecha* QSisContFechaFin;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaRangoFechasLayout;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURARANGOFECHAS_H
