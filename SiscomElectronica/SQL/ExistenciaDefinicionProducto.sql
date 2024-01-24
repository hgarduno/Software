select cveproducto,existencia,cantidad
from DefinicionTiposProducto as a  inner join
     existenciaexpendiobodegas as b using(cveproducto)
where 
      -- idproducto=1488141064   -- Entrenador 4550
      -- idproducto=1502933255   -- PCTOS1AM-N
      -- idproducto=1503333500   -- PCTOS1V-R
      -- idproducto=1503314265   -- PAQFTEVAR
      -- idproducto=1486462714   -- PAQPUNTOSC3
       idproducto=1535645927   -- PLACA48 
order by cveproducto
