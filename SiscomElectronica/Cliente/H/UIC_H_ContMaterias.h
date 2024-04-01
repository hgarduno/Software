/****************************************************************************
** Form interface generated from reading ui file 'UI/ContMaterias.ui'
**
** Created: Wed Jan 31 10:58:08 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONTMATERIAS_H
#define CONTMATERIAS_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;

class ContMaterias : public QDialog
{
    Q_OBJECT

public:
    ContMaterias( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ContMaterias();

    QLabel* textLabel4;
    QLineEdit* QLEMateria;
    QTable* QTDatos;
    QPushButton* QPBAnexar;
    QPushButton* QPBRegistrar;
    QPushButton* QPBSelEscuela;
    QPushButton* pushButton27_3;

protected:
    QGridLayout* ContMateriasLayout;
    QVBoxLayout* layout64;
    QHBoxLayout* layout69;

protected slots:
    virtual void languageChange();

};

#endif // CONTMATERIAS_H
