alter table ambientetimbrado add column RazonSocial text;
alter table empresas add column regimenfiscal integer references regimenfiscal(regimen);
