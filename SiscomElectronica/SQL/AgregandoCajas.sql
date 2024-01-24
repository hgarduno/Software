insert into Cajas values(2,'127.0.0.1','XPS HGarduno');
insert into EstadoControlesCaja 
select 2,idcontrol,0
from controlesventa;
