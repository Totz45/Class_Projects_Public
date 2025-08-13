create database DVD_company;

use DVD_company;

show tables;

-- ------------------ branch --------------------
create table branch
(branch_num numeric(8,0),
street varchar(20),
city varchar(15),
state varchar(2) check (state in ('AK', 'AL', 'AR', 'AZ', 'CA', 'CO', 'CT', 'DE', 'FL', 'GA', 'HI', 'IA', 'ID', 'IL', 'IN', 'KS', 'KY', 'LA', 'MA', 'MD', 'ME', 'MI', 'MN', 'MO', 'MS', 'MT', 'NC', 'ND', 'NE', 'NH', 'NJ', 'NM', 'NV', 'NY', 'OH', 'OK', 'OR', 'PA', 'RI', 'SC', 'SD', 'TN', 'TX', 'UT', 'VA', 'VT', 'WA', 'WI', 'WV', 'WY')), -- IPS code to identify U.S. state,
zip_code numeric(5,0),
telephone_num numeric(12,0) not null,
primary key (branch_num));


-- ------------------ staff --------------------
create table staff
(staff_num numeric(8,0),
name varchar(35) not null,
position varchar(20),
salary numeric(8,2),
primary key(staff_num)
);


-- ------------------ DVD --------------------
create table dvd
(catalog_num numeric(6,0) unique,
title varchar(20),
category varchar(8) check (category in ('Action', 'Adult', 'Children', 'Drama', 'Horror', 'Sci-fi')),
main_actor varchar(35),
director varchar(35),
primary key (catalog_num, title)
);


-- ------------------ employed --------------------
create table employed
(staff_num numeric(8,0), 
branch_num numeric(8,0), 
start_date date not null,
end_date date,
primary key (staff_num, branch_num),
foreign key (staff_num) references staff(staff_num),
foreign key (branch_num) references branch(branch_num)
);


-- ------------------ manager --------------------
create table manager
(staff_num numeric(8,0) not null unique, 
branch_num numeric(8,0), 
primary key (staff_num, branch_num),
foreign key (staff_num) references employed(staff_num),
foreign key (branch_num) references employed(branch_num)
);


-- ------------------ copy --------------------
create table copy
(dvd_num numeric(5,0) unique, 
branch_num numeric(8,0), 
catalog_num numeric(6,0),
title varchar(20),
status varchar(1) check (status in ('R','S')), -- R for rented, S for in stock
daily_rental numeric(3,0) check ((daily_rental >= 0) and (daily_rental < 10)),
primary key (dvd_num, title, daily_rental),
foreign key (branch_num) references branch(branch_num),
foreign key (catalog_num, title) references dvd(catalog_num, title)
);


-- ------------------ member --------------------
create table member
(member_num numeric(5,0) unique, 
first_name varchar(20) not null, 
last_name varchar(20), 
street varchar(20),
city varchar(15) not null,
state varchar(2) check (state in ('AK', 'AL', 'AR', 'AZ', 'CA', 'CO', 'CT', 'DE', 'FL', 'GA', 'HI', 'IA', 'ID', 'IL', 'IN', 'KS', 'KY', 'LA', 'MA', 'MD', 'ME', 'MI', 'MN', 'MO', 'MS', 'MT', 'NC', 'ND', 'NE', 'NH', 'NJ', 'NM', 'NV', 'NY', 'OH', 'OK', 'OR', 'PA', 'RI', 'SC', 'SD', 'TN', 'TX', 'UT', 'VA', 'VT', 'WA', 'WI', 'WV', 'WY')), -- IPS code to identify U.S. state,
zip_code numeric(5,0),
register_date date not null,
primary key (member_num, first_name, last_name)
);


-- ------------------ rent --------------------
create table rent
(rental_num numeric(6,0) unique, 
member_num numeric(5,0),
first_name varchar(20), 
last_name varchar(20), 
dvd_num numeric(5,0), 
title varchar(20),
daily_rental numeric(3,0),
rental_date datetime not null,
return_date datetime,
primary key (rental_num),
foreign key (member_num, first_name, last_name) references member(member_num, first_name, last_name),
foreign key (dvd_num, title, daily_rental) references copy(dvd_num, title, daily_rental)
);
