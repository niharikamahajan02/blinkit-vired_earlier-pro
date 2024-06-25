
-- Top-selling books in descending order by quantity sold
SELECT
    B.title AS book_title,
    A.author_name,
    SUM(OD.quantity) AS total_sold
FROM  Books AS B
JOIN  Authors AS A ON B.author_id = A.author_id
JOIN  OrderDetails AS OD ON B.book_id = OD.book_id
GROUP BY  B.title, A.author_name
ORDER BY  total_sold DESC
LIMIT 10; -- Adjust the limit as needed

