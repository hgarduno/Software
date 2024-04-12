/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaContactoE.ui'
**
** Created: Thu Apr 11 22:09:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURACONTACTOE_H
#define CAPTURACONTACTOE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;

class CapturaContactoE : public QDialog
{
    Q_OBJECT

public:
    CapturaContactoE( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaContactoE();

    QLabel* textLabel11;
    QLineEdit* QLENombre;
    QLabel* textLabel11_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel11_3;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel12;
    QTextEdit* QTEDescripcion;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaContactoELayout;
    QVBoxLayout* layout49;
    QHBoxLayout* layout48;
    QVBoxLayout* layout45;
    QVBoxLayout* layout45_2;
    QVBoxLayout* layout45_3;
    QHBoxLayout* layout25;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURACONTACTOE_H
