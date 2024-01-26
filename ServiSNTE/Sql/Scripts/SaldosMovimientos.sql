insert into conceptosentradas select idconceptosexistencias 
from conceptosexistencias
where conceptos like '%ENTRADA%' or
      conceptos like '%VENTA%';


insert into conceptossalidas select idconceptosexistencias 
from conceptosexistencias
where conceptos like '%SALIDA%';

insert into TipoVentaConceptoEntrada values(1,2205);
insert into TipoVentaConceptoEntrada values(2,2210);

insert into meses values(1,'Enero');
insert into meses values(2,'Febrero');
insert into meses values(3,'Marzo');
insert into meses values(4,'Abril');
insert into meses values(5,'Mayo');
insert into meses values(6,'Junio');
insert into meses values(7,'Julio');
insert into meses values(8,'Agosto');
insert into meses values(9,'Septiembre');
insert into meses values(10,'Octubre');
insert into meses values(11,'Noviembre');
insert into meses values(12,'Diciembre');
