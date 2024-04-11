/****************************************************************************
** Form interface generated from reading ui file 'UI/UI_PerfilReferencia.ui'
**
** Created: Sat Jan 27 16:42:29 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PERFILREFERENCIA_H
#define PERFILREFERENCIA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;
class QTable;

class PerfilReferencia : public QDialog
{
    Q_OBJECT

public:
    PerfilReferencia( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~PerfilReferencia();

    QPushButton* QPBAceptar;
    QLabel* textLabel1;
    QLineEdit* QLEPerfil;
    QLabel* textLabel2;
    QTable* QTDatos;
    QLabel* textLabel1_2;
    QLineEdit* QLEPerfileRef;

protected:
    QGridLayout* PerfilReferenciaLayout;
    QVBoxLayout* layout15;
    QVBoxLayout* layout14;
    QVBoxLayout* layout14_2;

protected slots:
    virtual void languageChange();

};

#endif // PERFILREFERENCIA_H
