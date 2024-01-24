create table Impresoras(IdImpresora integer unique,Impresora varchar(28));
create table PuntosVenta(IdPuntoVenta integer unique,DireccionIp varchar(20),Maquina varchar(20));
create table ImpresoraPuntoVenta(IdImpresora integer references Impresoras(IdImpresora),
				 IdPuntoVenta integer references PuntosVenta(IdPuntoVenta));

