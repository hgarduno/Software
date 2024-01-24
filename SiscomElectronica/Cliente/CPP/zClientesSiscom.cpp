#include <zClientesSiscom.h>
#include <zClienteSiscom.h>
#include <zSiscomRegistro.h>

zClientesSiscom::zClientesSiscom(zSiscomRegistros *pzSisRegsClientes)
{
  Clientes(pzSisRegsClientes); 
}

void zClientesSiscom::Clientes(zSiscomRegistros *pzSisRegsClientes)
{
zSiscomRegistro *lzSisRegCliente;
for(lzSisRegCliente=pzSisRegsClientes->Primer();
    lzSisRegCliente;
    lzSisRegCliente=pzSisRegsClientes->Siguiente())
{
    (*this) << Cliente(lzSisRegCliente);
}
}
zClienteSiscom *zClientesSiscom::Cliente(zSiscomRegistro *pzSisRegCliente)
{
 zClienteSiscom *lzCliSiscom=new zClienteSiscom(pzSisRegCliente);
 return lzCliSiscom;
}
zClienteSiscom *zClientesSiscom::Cliente(int pintNCliente)
{
   return (zClienteSiscom *)(*this)[pintNCliente];
}

