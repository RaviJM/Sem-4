create table AUTHOR_LIST(
Author_ID varchar(5),
Book_ID varchar(5),
Role varchar(15),
primary key (Author_ID, Book_ID),
foreign key (Author_ID) references AUTHOR(Author_ID),
foreign key (Book_ID) references BOOK(Book_ID)
);
desc AUTHOR_LIST;