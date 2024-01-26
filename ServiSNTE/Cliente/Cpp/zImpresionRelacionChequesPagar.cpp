#include <zImpresionRelacionChequesPagar.h>
#include <zRelacionChequesPagar.h>
#include <zSiscomCampo.h>
#include <string.h>
zImpresionRelacionChequesPagar::zImpresionRelacionChequesPagar(zRelacionChequesPagar *pzRelacionChequesPagar):
						zRelCheqPagar(pzRelacionChequesPagar)
{
Encabezado();
}


void zImpresionRelacionChequesPagar::Encabezado()
{
   (*this) 								<< 
   RegistroEncabezado("Sistema","Relacion de Cheques a Pagar")	 	<<
   RegistroEncabezado("NombreSistema","SERVISNTE") 			<<
   RegistroEncabezado("Fecha","08-08-2016") 				<<
   RegistroEncabezado("Hora","Hora:8:00") 					<<
   RegistroEncabezado("NoCheque","No Cheque") 					<<
   RegistroEncabezado("ImporteCheque","Imp. Cheque") 		<<
   RegistroEncabezado("Apli","Aplicacion") 				<<
   RegistroEncabezado("Saldo","Saldo") 					<<
   RegistroEncabezado("Costo","Costo")					<<
   RegistroEncabezado("ImportePago","Imp. Pago");
}

zSiscomRegistro *zImpresionRelacionChequesPagar::RegistroEncabezado(const char *pchrPtrCampo,
						   const char *pchrPtrDato)
{
 zSiscomRegistro *lzSisRegCampo;
 lzSisRegCampo=new zSiscomRegistro;
 (*lzSisRegCampo) << new zSiscomCampo(pchrPtrCampo,(const unsigned char *)pchrPtrDato);
 return lzSisRegCampo;
}
zRelacionChequesPagar *zImpresionRelacionChequesPagar::RelacionChequesPagar()
{
 return zRelCheqPagar;
}
