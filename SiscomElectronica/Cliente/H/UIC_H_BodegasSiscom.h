/****************************************************************************
** Form interface generated from reading ui file 'UI/BodegasSiscom.ui'
**
** Created: lun abr 1 18:57:48 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef BODEGASSISCOM_H
#define BODEGASSISCOM_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlCmbBodegas;
class QPushButton;

class BodegasSiscom : public QDialog
{
    Q_OBJECT

public:
    BodegasSiscom( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~BodegasSiscom();

    QLabel* textLabel2;
    QCtrlCmbBodegas* QCtrBodegas;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* BodegasSiscomLayout;
    QVBoxLayout* layout36;
    QVBoxLayout* layout35;
    QHBoxLayout* layout34;

protected slots:
    virtual void languageChange();

};

#endif // BODEGASSISCOM_H
