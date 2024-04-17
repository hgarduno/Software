/****************************************************************************
** Form interface generated from reading ui file 'UI/PagaConTransferencia.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PAGACONTRANSFERENCIA_H
#define PAGACONTRANSFERENCIA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QButtonGroup;
class QRadioButton;
class QTextEdit;
class QPushButton;

class PagaConTransferencia : public QDialog
{
    Q_OBJECT

public:
    PagaConTransferencia( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~PagaConTransferencia();

    QLabel* textLabel2;
    QLineEdit* QLETelefono;
    QButtonGroup* QBGEdoTransferencia;
    QRadioButton* radioButton2;
    QRadioButton* QRBSeReflejo;
    QLabel* textLabel3;
    QTextEdit* QTEObservaciones;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* PagaConTransferenciaLayout;
    QVBoxLayout* layout49;
    QVBoxLayout* layout40;
    QHBoxLayout* layout48;
    QGridLayout* QBGEdoTransferenciaLayout;
    QVBoxLayout* layout41;
    QHBoxLayout* layout47;

protected slots:
    virtual void languageChange();

};

#endif // PAGACONTRANSFERENCIA_H
