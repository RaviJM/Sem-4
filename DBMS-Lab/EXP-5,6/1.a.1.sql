use ravidb;
create table Supplier(
scode varchar(5) primary key,
sname varchar(15),
scity varchar(15),
turnover decimal(10,2)
);
desc Supplier;