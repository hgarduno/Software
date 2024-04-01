/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaDato.ui'
**
** Created: Wed Jan 31 10:47:45 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURADATO_H
#define CAPTURADATO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;

class CapturaDato : public QDialog
{
    Q_OBJECT

public:
    CapturaDato( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaDato();

    QLabel* QLEtiqueta;
    QLineEdit* QLEDato;

protected:
    QGridLayout* CapturaDatoLayout;
    QVBoxLayout* layout19;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURADATO_H
