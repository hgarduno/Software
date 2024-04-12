/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaDireccionE.ui'
**
** Created: Thu Apr 11 22:09:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURADIRECCIONE_H
#define CAPTURADIRECCIONE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class CapturaDireccionE : public QDialog
{
    Q_OBJECT

public:
    CapturaDireccionE( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaDireccionE();

    QLabel* textLabel5;
    QLineEdit* QLELinea1;
    QLabel* textLabel5_2;
    QLineEdit* QLELinea2;
    QLabel* textLabel5_3;
    QLineEdit* QLELinea3;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaDireccionELayout;
    QVBoxLayout* layout24;
    QVBoxLayout* layout21;
    QVBoxLayout* layout21_2;
    QVBoxLayout* layout21_3;
    QHBoxLayout* layout25;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURADIRECCIONE_H
