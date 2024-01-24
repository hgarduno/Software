#include <SiscomQAction.h>
#include <SiscomDatCom.h>
#include <SiscomDesarrollo3Qt++.h>
#include <dlfcn.h>

SiscomQAction::SiscomQAction(QObject *pQOParent,
			     const char *pchrPtrNombre,
			     void *pvidPtrIconos):
		QAction(pQOParent,pchrPtrNombre),
		vidPtrIconos(pvidPtrIconos)
{
  connect(this,
  	  SIGNAL(activated()),
	  SLOT(SlotSelecciono()));
}
void SiscomQAction::SlotSelecciono()
{
   emit SignalSelecciono(this);
}
void SiscomQAction::NombreClase(const char *pchrPtrNmbClase)
{
strcpy(chrArrNmbClase,pchrPtrNmbClase);
}

void SiscomQAction::Texto(const char *pchrPtrTexto)
{
strcpy(chrArrTexto,pchrPtrTexto);
setText(chrArrTexto);
}

void SiscomQAction::Icono(const char *pchrPtrIcono)
{
strcpy(chrArrIcono,pchrPtrIcono);
}
void SiscomQAction::Funcion(const char *pchrPtrFuncion)
{
strcpy(chrArrFuncion,pchrPtrFuncion);
}
void SiscomQAction::Modulo(const char *pchrPtrModulo)
{
strcpy(chrArrModulo,pchrPtrModulo);
}
void SiscomQAction::Argumentos(char **pchrPtrArgumentos)
{
 chrPtrArgumentos=pchrPtrArgumentos;
}
void SiscomQAction::Comunicaciones(SiscomDatCom *pSisDatCom)
{
 SisDatCom=pSisDatCom;
}
void SiscomQAction::ObtenTexto(char *pchrPtrTexto)
{
  strcpy(pchrPtrTexto,chrArrTexto);
}

void SiscomQAction::ObtenIcono(char *pchrPtrIcono)
{
strcpy(pchrPtrIcono,chrArrIcono);
}
void SiscomQAction::ObtenModulo(char *pchrPtrModulo)
{
strcpy(pchrPtrModulo,chrArrModulo);
}
void SiscomQAction::ObtenFuncion(char *pchrPtrFuncion)
{
strcpy(pchrPtrFuncion,chrArrFuncion);
}

void *SiscomQAction::SiscomObtenFuncionIcono()
{
void *lvidPtrFuncionIcono;
     if(vidPtrIconos&&
        (lvidPtrFuncionIcono=dlsym(vidPtrIconos,chrArrIcono)))
     {
	return lvidPtrFuncionIcono;
     }
     else
     return 0;

}
void SiscomQAction::SiscomMuestraIcono()
{
const char **lchrPtrIcono;
const char **(*SiscomIconoBiblioteca)();
if((SiscomIconoBiblioteca=(const char **(*)())SiscomObtenFuncionIcono()))
   setIconSet(QPixmap(SiscomIconoBiblioteca()));
}
