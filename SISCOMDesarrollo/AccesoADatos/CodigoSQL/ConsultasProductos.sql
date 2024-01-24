select a.*,b.intExistencia 
from Compra as a,Inventario as b
where a.chrCveProducto=b.chrCveProducto and 
      (a.dteFechaCompra>='2002-09-11' and a.dteFechaCompra<='2002-09-12') and
      (a.chrCveProducto='4000' or a.chrCveProducto='4001')
