/****************************************************************************
** Form interface generated from reading ui file 'UI/DonacionMaterial.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DONACIONMATERIAL_H
#define DONACIONMATERIAL_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTextEdit;
class QPushButton;

class DonacionMaterial : public QDialog
{
    Q_OBJECT

public:
    DonacionMaterial( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~DonacionMaterial();

    QLabel* Explicacion;
    QTextEdit* QTEExplicacion;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* DonacionMaterialLayout;
    QHBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // DONACIONMATERIAL_H
