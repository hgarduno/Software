#include <QListBoxItemGimnasia.h>
#include <qpainter.h>
#include <qstyle.h>
#include <qapplication.h>
#include <CQSisClase.h>
#include <CQSisNivel.h>
#include <CQSisGrupo.h>
#include <CQSisCGimnastas.h>

QListBoxItemClase::QListBoxItemClase(CQSisClase *pCQSClase):
				QListBoxItem(),
				CQSClase(pCQSClase)
{

}

void QListBoxItemClase::paint(QPainter *painter)
{
 int itemHeight = height( listBox() );
 QFontMetrics fm = painter->fontMetrics();
 int yPos = ( ( itemHeight - fm.height() ) / 2 ) + fm.ascent();
 painter->drawText( 3, yPos, (*CQSClase)["Clase"] );
}
int QListBoxItemClase::width(const QListBox *lb) const 
{
int w = lb ? lb->fontMetrics().width( text() ) + 6 : 0;
return QMAX( w, QApplication::globalStrut().width() );

}
int QListBoxItemClase::height(const QListBox *lb) const
{
int h = lb ? lb->fontMetrics().lineSpacing() + 2 : 0;
return QMAX( h, QApplication::globalStrut().height() );
}

CQSisClase *QListBoxItemClase::Clase()
{
return CQSClase;
}
QListBoxItemNivel::QListBoxItemNivel(CQSisClaseNivel *pCQSCNivel):
				QListBoxItem(),
				CQSCNivel(pCQSCNivel)
{

}

void QListBoxItemNivel::paint(QPainter *painter)
{
 int itemHeight = height( listBox() );
 QFontMetrics fm = painter->fontMetrics();
 int yPos = ( ( itemHeight - fm.height() ) / 2 ) + fm.ascent();
 painter->drawText( 3, yPos,(*CQSCNivel->Nivel())["Nivel"] );
}
int QListBoxItemNivel::width(const QListBox *lb) const 
{
int w = lb ? lb->fontMetrics().width( text() ) + 6 : 0;
return QMAX( w, QApplication::globalStrut().width() );

}
int QListBoxItemNivel::height(const QListBox *lb) const
{
int h = lb ? lb->fontMetrics().lineSpacing() + 2 : 0;
return QMAX( h, QApplication::globalStrut().height() );
}

CQSisClaseNivel *QListBoxItemNivel::ClaseNivel()
{
return CQSCNivel;

}

QListBoxItemGrupo::QListBoxItemGrupo(CQSisGrupo *pCQSGrupo):
				QListBoxItem(),
				CQSGrupo(pCQSGrupo)
{

}

void QListBoxItemGrupo::paint(QPainter *painter)
{
 int itemHeight = height( listBox() );
 QFontMetrics fm = painter->fontMetrics();
 int yPos = ( ( itemHeight - fm.height() ) / 2 ) + fm.ascent();
 painter->drawText( 3, 
 		   yPos,
		   QString().sprintf("Grupo[%s] Edad[%s]",
		   		     (*CQSGrupo)["Grupo"],
				     (*CQSGrupo)["RangoEdad"]));
}
int QListBoxItemGrupo::width(const QListBox *lb) const 
{
int w = lb ? lb->fontMetrics().width( text() ) + 6 : 0;
return QMAX( w, QApplication::globalStrut().width() );

}
int QListBoxItemGrupo::height(const QListBox *lb) const
{
int h = lb ? lb->fontMetrics().lineSpacing() + 2 : 0;
return QMAX( h, QApplication::globalStrut().height() );
}
CQSisGrupo *QListBoxItemGrupo::Grupo()
{
return CQSGrupo;
}
