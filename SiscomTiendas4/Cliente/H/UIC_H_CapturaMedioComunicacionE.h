/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaMedioComunicacionE.ui'
**
** Created: Thu Apr 11 20:30:19 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURAMEDIOCOMUNICACIONE_H
#define CAPTURAMEDIOCOMUNICACIONE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlMedComunicacion;
class QLineEdit;
class QTextEdit;
class QPushButton;

class CapturaMedioComunicacionE : public QDialog
{
    Q_OBJECT

public:
    CapturaMedioComunicacionE( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaMedioComunicacionE();

    QLabel* textLabel1;
    QCtrlMedComunicacion* QCtrMedioComunicacion;
    QLabel* textLabel2;
    QLineEdit* QLEDato;
    QLabel* textLabel3;
    QTextEdit* QTEDescripcion;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaMedioComunicacionELayout;
    QVBoxLayout* layout8;
    QHBoxLayout* layout6;
    QVBoxLayout* layout2;
    QVBoxLayout* layout5;
    QVBoxLayout* layout3;
    QVBoxLayout* layout4;
    QHBoxLayout* layout7;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURAMEDIOCOMUNICACIONE_H
