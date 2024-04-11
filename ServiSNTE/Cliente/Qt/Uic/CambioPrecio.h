/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CambioPrecio.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAMBIOPRECIO_H
#define CAMBIOPRECIO_H

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

class CambioPrecio : public QDialog
{
    Q_OBJECT

public:
    CambioPrecio( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CambioPrecio();

    QLabel* textLabel1;
    QLineEdit* QLEPrecioAnterior;
    QLabel* textLabel1_2;
    QLineEdit* QLENvoPrecio;
    QLabel* textLabel2;
    QTextEdit* QTEMotivoCambioPrecio;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CambioPrecioLayout;
    QHBoxLayout* layout32;
    QVBoxLayout* layout30;
    QVBoxLayout* layout30_2;
    QVBoxLayout* layout34;
    QHBoxLayout* layout35;

protected slots:
    virtual void languageChange();

};

#endif // CAMBIOPRECIO_H
