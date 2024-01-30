create table PRODUCT_MASTER_1(
PRODUCTNO varchar(6) primary key,
DESCRIPTION varchar(15) not null,
PROFITPERCENT decimal(4,2) not null,
UNITMEASURE varchar(10) not null,
QTYONHAND int(8) not null,
REORDERLVL int(8) not null,
SELLPRICE decimal(8,2) not null,
COSTPRICE decimal(8,2) not null,
constraint PN_chk check(PRODUCTNO like 'P%')
);
desc PRODUCT_MASTER_1;