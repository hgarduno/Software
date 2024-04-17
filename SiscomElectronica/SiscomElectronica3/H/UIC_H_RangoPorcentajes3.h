/****************************************************************************
** Form interface generated from reading ui file 'UI/RangoPorcentajes3.ui'
**
** Created: Fri Apr 12 21:25:15 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef RANGOPORCENTAJES3_H
#define RANGOPORCENTAJES3_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class RangoPorcentajes3 : public QDialog
{
    Q_OBJECT

public:
    RangoPorcentajes3( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~RangoPorcentajes3();

    QLabel* textLabel4_2;
    QLineEdit* QLEAlto;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel4;
    QLineEdit* QLEBajo;

protected:
    QGridLayout* RangoPorcentajes3Layout;
    QVBoxLayout* layout36_2;
    QHBoxLayout* layout38;
    QVBoxLayout* layout36;

protected slots:
    virtual void languageChange();

};

#endif // RANGOPORCENTAJES3_H
