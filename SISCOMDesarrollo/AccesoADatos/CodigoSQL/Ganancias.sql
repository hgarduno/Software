select sum( (-a.numprccompra+b.numprcunitario)*b.intCantidad ) as Ganancia , a.chrCveProducto,
       sum(b.intCantidad) as NoDisVendidos 
from compra as a,venta as b 
where a.chrcveproducto=b.chrCveProducto 
--and 
--      a.numprccompra=( select max(numprccompra) from compra  where chrcveproducto=a.ChrCveProducto ) and 
--			 a.chrCveProducto=b.chrCveProducto 
group by a.chrCveProducto

