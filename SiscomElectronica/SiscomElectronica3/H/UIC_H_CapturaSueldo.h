/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaSueldo.ui'
**
** Created: Wed Jan 31 10:47:32 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURASUELDO_H
#define CAPTURASUELDO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class CapturaSueldo : public QDialog
{
    Q_OBJECT

public:
    CapturaSueldo( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaSueldo();

    QLabel* textLabel4;
    QLineEdit* QLEEmpleado;
    QLabel* textLabel6;
    QLineEdit* QLESueldo;
    QPushButton* QPBRegistra;
    QPushButton* QPBCancela;

protected:
    QGridLayout* CapturaSueldoLayout;
    QVBoxLayout* layout17;
    QVBoxLayout* layout13;
    QHBoxLayout* layout15;
    QSpacerItem* spacer1;
    QVBoxLayout* layout14;
    QHBoxLayout* layout16;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURASUELDO_H
