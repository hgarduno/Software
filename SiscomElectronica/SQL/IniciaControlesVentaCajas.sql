insert into ControlesVenta values(0,'QACabecera','Encabezado');
insert into ControlesVenta values(1,'QAEliminaProd','Elimina Productos');
insert into ControlesVenta values(2,'QAJgsSep','Cotiza X Juegos Separados');
insert into ControlesVenta values(3,'QAJgs','Cotiza X Juegos');
insert into ControlesVenta values(4,'QACCliente','Cambia El Cliente');


insert into EstadoControlesCaja
select idcaja,idcontrol,0
from cajas ,
    controlesventa

