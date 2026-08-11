-- Write your PostgreSQL query statement below
WITH D AS (SELECT * , (ROW_NUMBER() OVER( PARTITION BY CUSTOMER_ID ORDER BY order_date  )) AS RK FROM DELIVERY)
SELECT 
ROUND(100*SUM(
    CASE 
    WHEN ORDER_DATE=customer_pref_delivery_date THEN 1 ELSE 0 END
)/COUNT(*)::NUMERIC,2) AS immediate_percentage
 FROM D WHERE RK=1;