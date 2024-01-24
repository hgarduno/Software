delete from estadospedido where idedopedido in(1,2);
--insert into EstadosPedido values(0,'Pedido registrado');
insert into EstadosPedido values(1,'Pago verificado');
insert into EstadosPedido values(2,'Pedido preparado para envio');
insert into EstadosPedido values(3,'Pedido entregado a la paqueteria');
insert into AccionEstadoPedido values(0,'Verificar Pago');
insert into AccionEstadoPedido values(1,'Poner Pedido');
insert into AccionEstadoPedido values(2,'Programar recoleccion');
insert into AccionEstadoPedido values(3,'Enviar guia al cliente');

