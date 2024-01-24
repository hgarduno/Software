create table MotivoInventario(
		idMotivo integer unique ,
		Descripcion varchar(128));


insert into MotivoInventario values(0,'Desajuste Sistema, Existencia Fisica');
insert into MotivoInventario values(1,'Inicio Semestre');

create table ProgramaInventario(idMotivo integer
				references Motivoinventario(idmotivo),
				idInventario integer unique,	
				FechaInicio date,
				FechaFin    date,	
				Descripcion text);

alter table inventario add column idinventario integer 
                        references ProgramaInventario (idinventario);

insert into ProgramaInventario values(0,0,'2011-09-22','2011-09-22','Inventario por desajuste');


create table DesajusteInventario(
		cveproducto varchar(50) references Productos(cveproducto),
		ExistenciaFisica numeric(10,2),
		ExistenciaSistema numeric(10,2),
		ExistenciaAjuste  numeric(10,2),
		Fecha date,
		Hora time);

