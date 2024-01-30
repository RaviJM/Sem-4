create table Supplier_Part(
scode varchar(5),
pcode varchar(5),
qty int,
constraint fk1 foreign key(scode) references Supplier(scode),
constraint fk2 foreign key(pcode) references Part(pcode)
);
desc Supplier_Part;