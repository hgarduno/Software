/****************************************************************************
** Form interface generated from reading ui file 'UI/Firmate.ui'
**
** Created: Thu Apr 11 21:37:04 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FIRMATE_H
#define FIRMATE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class Firmate : public QDialog
{
    Q_OBJECT

public:
    Firmate( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Firmate();

    QLabel* textLabel1;
    QLineEdit* QLEFirma;
    QLabel* textLabel1_2;
    QLineEdit* QLEPassword;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* FirmateLayout;
    QHBoxLayout* layout4;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;
    QHBoxLayout* layout3;

protected slots:
    virtual void languageChange();

};

#endif // FIRMATE_H
