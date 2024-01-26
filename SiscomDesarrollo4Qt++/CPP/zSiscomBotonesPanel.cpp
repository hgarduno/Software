#include <zSiscomBotonesPanel.h>
#include <zSiscomBotonPanel.h>
zSiscomBotonesPanel::zSiscomBotonesPanel()
{

}

zSiscomBotonesPanel &zSiscomBotonesPanel::operator<<(zSiscomBotonPanel *pzSisBotonPanel)
{
Agrega(pzSisBotonPanel);
return *this;
}
