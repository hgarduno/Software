/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/PosicionesBeneficios.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef POSICIONESBENEFICIOS_H
#define POSICIONESBENEFICIOS_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;

class PosicionesBeneficios : public QDialog
{
    Q_OBJECT

public:
    PosicionesBeneficios( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~PosicionesBeneficios();

    QLabel* textLabel1;
    QTable* QTPosiciones;
    QPushButton* QPBIncrementaX;
    QPushButton* QPBIncrementaY;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* PosicionesBeneficiosLayout;
    QVBoxLayout* layout10;
    QHBoxLayout* layout12;

protected slots:
    virtual void languageChange();

};

#endif // POSICIONESBENEFICIOS_H
