/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaCliente.ui'
**
** Created: Thu Apr 11 21:05:32 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURACLIENTE_H
#define CAPTURACLIENTE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class CapturaCliente : public QDialog
{
    Q_OBJECT

public:
    CapturaCliente( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaCliente();

    QLabel* textLabel3;
    QLineEdit* QLEApellidoPaterno;
    QLabel* textLabel3_2;
    QLineEdit* QLEApellidoMaterno;
    QLabel* textLabel4;
    QLineEdit* QLENombres;
    QPushButton* QPBCrear;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel2;
    QLineEdit* QLEClaveCliente;
    QLabel* textLabel6;
    QLineEdit* QLERFC;

protected:
    QGridLayout* CapturaClienteLayout;
    QHBoxLayout* layout87;
    QVBoxLayout* layout81;
    QVBoxLayout* layout83;
    QVBoxLayout* layout84;
    QHBoxLayout* layout72;
    QVBoxLayout* layout80;
    QVBoxLayout* layout92;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURACLIENTE_H
