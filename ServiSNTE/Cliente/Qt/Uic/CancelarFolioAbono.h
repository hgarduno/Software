/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CancelarFolioAbono.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CANCELARFOLIOABONO_H
#define CANCELARFOLIOABONO_H

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

class CancelarFolioAbono : public QDialog
{
    Q_OBJECT

public:
    CancelarFolioAbono( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CancelarFolioAbono();

    QLabel* textLabel1;
    QLineEdit* QLEFolioCancelar;
    QLabel* textLabel1_2;
    QLineEdit* QLEFolioAAsignar;
    QLabel* textLabel2;
    QTextEdit* QTEMotivo;
    QPushButton* QPBRegistrarCancelacion;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CancelarFolioAbonoLayout;
    QVBoxLayout* layout39;
    QVBoxLayout* layout39_2;
    QVBoxLayout* layout42;
    QHBoxLayout* layout47;

protected slots:
    virtual void languageChange();

};

#endif // CANCELARFOLIOABONO_H
