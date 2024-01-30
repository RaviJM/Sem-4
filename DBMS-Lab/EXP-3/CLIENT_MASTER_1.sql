use ravidb;
create table CLIENT_MASTER_1 (
CLIENTNO varchar(6) primary key,
NAME varchar(20) not null,
ADDRESS1 varchar(30),
ADDRESS2 varchar(30),
CITY varchar(15),
PINCODE int(8),
STATE varchar(15),
BALDUE decimal(10,2),
constraint c_chk check(CLIENTNO like 'C%')
);
desc CLIENT_MASTER_1;