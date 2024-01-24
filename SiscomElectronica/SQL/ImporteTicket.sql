
select * 
from ticketimpreso  inner join 
	ImpresionTicketTotal using(idventa)
where fecha::date='2018-05-29'
