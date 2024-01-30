create table BOOK(
Book_ID varchar(5) primary key,
Book_Title varchar(100) not null,
Copies int check(Copies > 2),
constraint b_id_chk check(Book_ID like "B%")
);
desc BOOK;