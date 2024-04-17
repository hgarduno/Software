/****************************************************************************
** Form interface generated from reading ui file 'UI/OrdenesDisponibles.ui'
**
** Created: Fri Apr 12 21:25:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ORDENESDISPONIBLES_H
#define ORDENESDISPONIBLES_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTable;

class OrdenesDisponibles : public QDialog
{
    Q_OBJECT

public:
    OrdenesDisponibles( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~OrdenesDisponibles();

    QPushButton* QPBAceptar;
    QPushButton* pushButton2;
    QLabel* textLabel1;
    QTable* QTDatos;
    QLabel* textLabel1_2;
    QTable* QTDetalle;

protected:
    QGridLayout* OrdenesDisponiblesLayout;
    QHBoxLayout* layout1;
    QVBoxLayout* layout2;
    QVBoxLayout* layout2_2;

protected slots:
    virtual void languageChange();

};

#endif // ORDENESDISPONIBLES_H
