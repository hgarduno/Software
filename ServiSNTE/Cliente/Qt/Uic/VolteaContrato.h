/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/VolteaContrato.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef VOLTEACONTRATO_H
#define VOLTEACONTRATO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;

class VolteaContrato : public QDialog
{
    Q_OBJECT

public:
    VolteaContrato( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~VolteaContrato();

    QPushButton* QPBSeVolteoElContrato;
    QPushButton* QPBImprimir;
    QPushButton* QPBTerminar;

protected:
    QGridLayout* VolteaContratoLayout;

protected slots:
    virtual void languageChange();

};

#endif // VOLTEACONTRATO_H
