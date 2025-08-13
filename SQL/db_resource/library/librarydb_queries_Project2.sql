-- -- CSC 3300-002, Fall 2024, Project2
-- -- The due date for this project is 10/16/2024 at 11:59pm
-- Tate Finley

-- Compose SQL queries to retrieve the following data from the University database.
-- 1. Card numbers, names (first, middle, last), and borrowing dates of library members who have kept a book for more than two weeks.
select  m.card_no, first_name, middle_name, last_name, date_borrowed
from member as m natural join borrow as b
where date_returned >= date_add(date_borrowed, INTERVAL 14 DAY) or date_returned is null;
-- 2. Card numbers, names (first, middle, last) of library members who have never borrowed a book.
select  m.card_no, first_name, middle_name, last_name
from member as m
where m.card_no not in (select card_no from borrow) and m.card_no is not null;
-- 3. ISBNs and titles of books borrowed on September 22, 2003.
select bk.ISBN, bk.title
from borrow as br natural join copy as c natural join book as bk
where date_borrowed like '2003-09-22%';
-- 4. ISBNs and titles of books written by multiple authors.
select b.ISBN, b.title
from book as b natural join book_author as ba natural join author as a
group by b.ISBN, b.title
having count(ba.ISBN) > 1;
-- 5. ISBNs and titles of books authored by Thomas Connolly.
select b.ISBN, b.title
from book as b natural join book_author as ba natural join author as a
where first_name = 'Thomas' and last_name = 'Connolly';
-- 6. ISBNs and titles of books borrowed by member 331.
select bk.ISBN, bk.title
from borrow as br natural join copy as c natural join book as bk
where card_no = '331';
-- 7. Card numbers of members who renewed a book twice but still have not returned it.
select card_no
from member natural join borrow
where renewals_no = '2' and date_returned is null;
-- 8. Members (card number, first name, middle name, last name) along with their total number of borrowed book copies.
select  m.card_no, first_name, middle_name, last_name, count(b.card_no)
from member as m natural left join borrow as b
group by m.card_no, first_name, middle_name, last_name;
-- 9. ISBNs and titles of books, along with the number of copies owned by the library.
with library(ISBN, num_copies) as (select ISBN, count(barcode) from copy group by ISBN) 
select book.ISBN, title, num_copies
from book, library
where book.ISBN = library.ISBN
group by ISBN, title, num_copies;
-- 10. Card numbers, names (first, middle, last), and addresses of members whose library cards will expire within the next 30 days.
select  card_no, first_name, middle_name, last_name, street, city, state, apt_no, zip_code
from member
where card_exp_date <= date_add(date(now()), INTERVAL 30 DAY) and card_exp_date > date_add(date(now()), INTERVAL 0 DAY);
-- 11. Total amount of money received by the library from late book returns.
with total(days_late) as (select (datediff(date_returned,date_borrowed) - 14) as days_late from borrow where datediff(date_returned,date_borrowed) -14 > 0)
select sum(days_late*0.25) as cents_owed
from total;
-- 12. Card numbers, names (first, middle, last) of members who borrowed more non-fiction books than fiction books.
select  m.card_no, first_name, middle_name, last_name
from member as m
natural join borrow as b
natural join copy as c
natural join book as bk
natural left join genre as gn
group by m.card_no, first_name, middle_name, last_name
having sum(case when gn.genre_id = (select g.genre_id from genre as g where type = '1' and bk.genre_id = g.genre_id) then 1 else 0 end) 
> sum(case when gn.genre_id = (select g.genre_id from genre as g where type = '0' and bk.genre_id = g.genre_id) then 1 else 0 end);
-- 13. Most popular book genre(s).
select name
from genre natural join book
group by name
having count(book.genre_id) = (select max(genre_count) from (select count(genre_id) as genre_count from book group by genre_id) as genre_count);
-- 14. Barcode, ISBN, title, and borrowing count for every book copy, including those never borrowed.
select copy.barcode, copy.ISBN, book.title, count(copy.barcode)
from book natural join copy natural join borrow
group by copy.barcode, copy.ISBN, book.title
union
select copy.barcode, copy.ISBN, book.title, 0
from book natural join copy where copy.barcode not in (select barcode from borrow);
-- 15. Barcode, ISBN, title, and condition of the book copy(ies) borrowed most frequently.
select copy.barcode, copy.ISBN, book.title, copy.comment
from book natural join copy natural join borrow
group by copy.barcode, copy.ISBN, book.title, copy.comment
having count(copy.barcode) = (select max(borrow_count) from (select count(barcode) as borrow_count from borrow group by barcode) as borrow_count);

-- Improvements to library database
-- 1. Include a daily late fee attribute for members who do not return the book by the renewal date and a purchasing price attribute for members who have purchased their borrowed books both located in the book table. 
-- 2. Include an integrity constraint for the borrow table, renewals_no attribute to check if a book has been borrowed no more than two times to adhere to the library rules as given in the project assignment.