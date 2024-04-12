/****************************************************************************
** Form interface generated from reading ui file 'UI/UI_ObjetosEjecucion.ui'
**
** Created: Thu Apr 11 21:35:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef OBJETOSEJECUCION_H
#define OBJETOSEJECUCION_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QFrame;
class QLabel;
class QLineEdit;
class QPushButton;

class ObjetosEjecucion : public QDialog
{
    Q_OBJECT

public:
    ObjetosEjecucion( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ObjetosEjecucion();

    QTable* QTDatosObj;
    QFrame* line1;
    QTable* QTDatosO;
    QTable* QTDatosP;
    QLabel* textLabel6_2;
    QLineEdit* QLEObjeto;
    QLabel* textLabel6;
    QLineEdit* QLENombre;
    QPushButton* QPBAnexarObjeto;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* ObjetosEjecucionLayout;
    QVBoxLayout* layout44;
    QHBoxLayout* layout38;
    QHBoxLayout* layout42;
    QVBoxLayout* layout39_2;
    QVBoxLayout* layout39;
    QHBoxLayout* layout43;

protected slots:
    virtual void languageChange();

};

#endif // OBJETOSEJECUCION_H
