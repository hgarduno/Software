/****************************************************************************
** Form interface generated from reading ui file 'UI/MaterialAreaDiseno.ui'
**
** Created: lun abr 1 18:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MATERIALAREADISENO_H
#define MATERIALAREADISENO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTextEdit;

class MaterialAreaDiseno : public QDialog
{
    Q_OBJECT

public:
    MaterialAreaDiseno( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~MaterialAreaDiseno();

    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel1;
    QTextEdit* QTEExplicacion;

protected:
    QGridLayout* MaterialAreaDisenoLayout;
    QHBoxLayout* layout6;
    QVBoxLayout* layout7;

protected slots:
    virtual void languageChange();

};

#endif // MATERIALAREADISENO_H
