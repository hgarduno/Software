/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/ActualizandoSistema.ui'
**
** Created: Thu Apr 11 21:10:07 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ACTUALIZANDOSISTEMA_H
#define ACTUALIZANDOSISTEMA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTextEdit;
class QLabel;
class QProgressBar;

class ActualizandoSistema : public QDialog
{
    Q_OBJECT

public:
    ActualizandoSistema( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ActualizandoSistema();

    QTextEdit* textEdit1;
    QLabel* textLabel1;
    QProgressBar* progressBar1;

protected:
    QGridLayout* ActualizandoSistemaLayout;
    QGridLayout* layout2;
    QVBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // ACTUALIZANDOSISTEMA_H
