/****************************************************************************
** Form interface generated from reading ui file 'UI/FechaHoraEntrega.ui'
**
** Created: lun abr 1 18:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FECHAHORAENTREGA_H
#define FECHAHORAENTREGA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlFechaHora;
class QPushButton;

class FechaHoraEntrega : public QDialog
{
    Q_OBJECT

public:
    FechaHoraEntrega( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~FechaHoraEntrega();

    QLabel* textLabel1;
    QCtrlFechaHora* ctrlFechaHora1;
    QPushButton* pushButton1;
    QPushButton* pushButton2;

protected:
    QGridLayout* FechaHoraEntregaLayout;
    QVBoxLayout* layout1;
    QHBoxLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // FECHAHORAENTREGA_H
