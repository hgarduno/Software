/****************************************************************************
** Form interface generated from reading ui file 'UI/AccionTraspasoBodegaExp.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ACCIONTRASPASOBODEGAEXP_H
#define ACCIONTRASPASOBODEGAEXP_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QTextEdit;

class AccionTraspasoBodegaExp : public QDialog
{
    Q_OBJECT

public:
    AccionTraspasoBodegaExp( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~AccionTraspasoBodegaExp();

    QLabel* textLabel1;
    QLineEdit* QLECveProducto;
    QLabel* textLabel2;
    QLineEdit* QLEExistenciaE;
    QLabel* textLabel2_2;
    QLineEdit* QLEExistenciaB;
    QPushButton* QPBPasarEB;
    QPushButton* QPBCancelar;
    QLabel* textLabel3;
    QTextEdit* QTEError;

protected:
    QGridLayout* AccionTraspasoBodegaExpLayout;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QVBoxLayout* layout2_2;
    QHBoxLayout* layout4;
    QVBoxLayout* layout5;

protected slots:
    virtual void languageChange();

};

#endif // ACCIONTRASPASOBODEGAEXP_H
