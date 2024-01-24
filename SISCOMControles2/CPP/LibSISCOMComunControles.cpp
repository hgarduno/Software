#include <LibSISCOMComunControles.h>
#include <stdlib.h>
void ValidaSoloNumerosYTamano(QLineEdit *pQLEControl,
			      int pintValorMaximo,
                              int pintNCaracteres,
			      const char *pchrPtrCadDefault,
                              QString pQSTexto)
{
char *lchrPtrTexto;
int liNCaracteres;
        liNCaracteres=pQSTexto.length()-1;

        if(((const char *)pQSTexto)[liNCaracteres]>='0' &&
           ((const char *)pQSTexto)[liNCaracteres]<='9' &&
           (liNCaracteres+1)<=pintNCaracteres)
        {
		if(pintValorMaximo &&
	           atoi((const char *)pQSTexto)>pintValorMaximo)		
		{
		 if(pchrPtrCadDefault )
	           pQLEControl->setText(pchrPtrCadDefault);
		 else
		   pQLEControl->setText("");
		}
	        else
            	pQLEControl->setText(pQSTexto);
        }
        else
        {
         lchrPtrTexto=(char *)(const char *)pQLEControl->text();
         lchrPtrTexto[liNCaracteres]=0;
         pQLEControl->setText(lchrPtrTexto);
        }
	
}
const char *RegresaCadenaDeTexto(QLineEdit *pQLETexto)
{
	return pQLETexto->text().isEmpty() ? "" : pQLETexto->text();
}
