/****************************************************************************
** Form interface generated from reading ui file 'UI/PagaConTransferencia.ui'
**
** Created: sáb jun 29 15:59:32 2024
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
class QButtonGroup;
class QRadioButton;
class QLabel;
class QTextEdit;
class QPushButton;
class QLineEdit;

class PagaConTransferencia : public QDialog
{
    Q_OBJECT

public:
    PagaConTransferencia( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~PagaConTransferencia();

    QButtonGroup* QBGEdoTransferencia;
    QRadioButton* radioButton2;
    QRadioButton* QRBSeReflejo;
    QLabel* textLabel3;
    QTextEdit* QTEObservaciones;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel2;
    QLineEdit* QLETelefono;

protected:
    QGridLayout* PagaConTransferenciaLayout;
    QHBoxLayout* layout48;
    QGridLayout* QBGEdoTransferenciaLayout;
    QVBoxLayout* layout41;
    QHBoxLayout* layout47;
    QHBoxLayout* layout7;
    QSpacerItem* spacer1;
    QVBoxLayout* layout40;

protected slots:
    virtual void languageChange();

};

#endif // PAGACONTRANSFERENCIA_H
