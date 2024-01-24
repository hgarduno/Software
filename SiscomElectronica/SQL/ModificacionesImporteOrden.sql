-- Martes 18 de Octubre del 2016 , se agrega 
-- la columna de fecha para , no hacer join con la 
-- tabla de ventas 
alter table ImporteOrden add column fecha  timestamp without time zone;
alter table ImporteOrden add edoventa integer;
