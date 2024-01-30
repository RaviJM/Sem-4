use ravidb;
create table AUTHOR (
Author_ID varchar(5) primary key,
Lastname varchar(15) not null,
Firtsname varchar(15) not null,
Email varchar(40),
City varchar(15),
Country varchar(15)
);
desc AUTHOR;