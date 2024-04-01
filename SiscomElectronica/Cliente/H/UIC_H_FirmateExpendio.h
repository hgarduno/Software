/****************************************************************************
** Form interface generated from reading ui file 'UI/FirmateExpendio.ui'
**
** Created: Wed Jan 31 10:57:03 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FIRMATEEXPENDIO_H
#define FIRMATEEXPENDIO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;

class FirmateExpendio : public QDialog
{
    Q_OBJECT

public:
    FirmateExpendio( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~FirmateExpendio();

    QLabel* textLabel2;
    QLineEdit* QLEFirma;
    QLabel* textLabel2_2;
    QLineEdit* QLEPassword;

protected:
    QGridLayout* FirmateExpendioLayout;
    QVBoxLayout* layout23;
    QVBoxLayout* layout23_2;

protected slots:
    virtual void languageChange();

};

#endif // FIRMATEEXPENDIO_H
