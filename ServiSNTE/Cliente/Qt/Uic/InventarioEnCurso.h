/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/InventarioEnCurso.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef INVENTARIOENCURSO_H
#define INVENTARIOENCURSO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;

class InventarioEnCurso : public QDialog
{
    Q_OBJECT

public:
    InventarioEnCurso( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~InventarioEnCurso();

    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel1;

protected:
    QGridLayout* InventarioEnCursoLayout;
    QHBoxLayout* layout12;

protected slots:
    virtual void languageChange();

};

#endif // INVENTARIOENCURSO_H
