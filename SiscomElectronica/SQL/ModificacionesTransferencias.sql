create table EstadoTransferencia(IdEstado integer unique,
				 Estado varchar(128));
create table Transferencias(IdExpendio integer references Empresas(IdEmpresa),
			   IdTransferencia integer unique,
			   IdEstado	integer references EstadoTransferencia(IdEstado),
			   FechaHora timestamp without time zone);
alter table transfierematerial add column idtransferencia integer references transferencias(IdTransferencia);

insert into estadoTransferencia values(0,'Exitoso');
insert into estadoTransferencia values(1,'No hay Conexion al Expendio');

