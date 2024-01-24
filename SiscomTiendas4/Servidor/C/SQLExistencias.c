#include <SQLExistencias.h>
#include <string.h>
#include <stdlib.h>

void SQLExistenciaProductos(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[1024];

sprintf(lchrArrSQL,
"								\
select a.existencia,						\
       a.existenciamin,						\
       b.idproducto,						\
       b.clave,							\
       b.dsc as dscproducto,					\
       d.idfamilia,						\
       d.familia						\
from inventario as a inner join					\
     producto as b using(idProducto) inner join			\
     famproducto as c using(idProducto) inner join		\
     familia as d using(idFamilia)				\
order by a.existencia,clave desc				\
");
EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
