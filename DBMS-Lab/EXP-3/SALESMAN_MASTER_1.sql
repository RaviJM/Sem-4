create table SALESMAN_MASTER_1(
SALESMANNO varchar(6) primary key,
SALESMANNAME varchar(20) not null,
ADDRESS1 varchar(30) not null,
ADDRESS2 varchar(30),
CITY varchar(20),
PINCODE int(8),
STATE varchar(20),
SALAMT real(8,2) not null,
TGTTOGET decimal(6,2) not null,
YTDSALES double(6,2) not null,
REMARKS varchar(60),
constraint sno_chk check(SALESMANNO like 'S%'),
constraint samt_chk check(SALAMT != 0),
constraint tgt_chk check(TGTTOGET != 0)
);
desc SALESMAN_MASTER_1;