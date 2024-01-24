
drop table TotalBolsa;
drop table Cambio;
drop table TotalCaja;
drop table CierreCaja;
drop table Denominaciones;

create table Denominaciones(IdDenominacion integer unique ,
			    Denominacion numeric(5,2));

create table CierreCaja(IdCierre integer unique,
			Fecha date,
			TotalCaja	numeric(11,2),
			Cambio		numeric(10,2),
			TotalBolsa	numeric(10,2));


create table TotalCaja(IdCierre integer unique  references CierreCaja(IdCierre),
			IdDenominacion integer references Denominaciones(IdDenominacion),
			Cantidad	integer,
			Importe		numeric(10,2),
			primary key(IdCierre,IdDenominacion));


create table Cambio(IdCierre integer unique references CierreCaja(IdCierre),
			IdDenominacion integer references Denominaciones(IdDenominacion),
			Cantidad	integer,
			Importe		numeric(10,2),
			primary key(IdCierre,IdDenominacion));


create table TotalBolsa(IdCierre integer unique references CierreCaja(IdCierre),
			IdDenominacion integer references Denominaciones(IdDenominacion),
			Cantidad	integer,
			Importe		numeric(10,2),
			primary key(IdCierre,IdDenominacion));
