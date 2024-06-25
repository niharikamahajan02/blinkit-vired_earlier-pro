SELECT  SUM(OD.subtotal) AS total_revenue
FROM Orders AS O
JOIN OrderDetails AS OD ON O.order_id = OD.order_id
WHERE O.order_date BETWEEN 'start_date' AND 'end_date'; -- Replace start_date and end_date with your desired period
