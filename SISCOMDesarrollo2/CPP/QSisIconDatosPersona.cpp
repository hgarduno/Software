#include <QSisIconDatosPersona.h>
#include <QSisOperacionPersona.h>
#include <dlfcn.h>
QSisIconDatosPersona::QSisIconDatosPersona(const char *pchrPtrBiblioteca,
					   const char *pchrPtrFuncion,
					   QWidget *pQWPtrPadre,
					  QIconView *pQIVPrincipal):
			QIconViewItem(pQIVPrincipal),
			chrPtrBiblioteca(pchrPtrBiblioteca),
			chrPtrFuncion(pchrPtrFuncion),
			vidPtrAncla(0),
			QWPtrPadre(pQWPtrPadre),
			QSisOpPersona(0)
{
	CargaBiblioteca();
}
QSisIconDatosPersona::~QSisIconDatosPersona()
{
	if(vidPtrAncla)
	dlclose(vidPtrAncla);
	if(QSisOpPersona)
	delete QSisOpPersona;
}
void QSisIconDatosPersona::CargaBiblioteca()
{

	if(!(vidPtrAncla=dlopen(chrPtrBiblioteca,RTLD_LAZY)))
	printf("dlopen:%s\n",dlerror());
	else
	{
	 CreaInstancia=(QSisOperacionPersona *(*)(QWidget *))dlsym(vidPtrAncla,chrPtrFuncion);
	 if(!CreaInstancia)
	 printf("dlsym:%s\n",dlerror());
	 else
	 QSisOpPersona=CreaInstancia(QWPtrPadre);
	}
			

}
void QSisIconDatosPersona::IniciaControl()
{
	setText(QSisOpPersona->ObtenTexto());
}
QSisOperacionPersona *QSisIconDatosPersona::ObtenOperacionPersona()
{
	return QSisOpPersona;
}
