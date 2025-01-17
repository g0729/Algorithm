SELECT
    F.FLAVOR
FROM 
    FIRST_HALF F
JOIN
    (
        SELECT
            FLAVOR,
            SUM(TOTAL_ORDER) AS TOTAL_ORDER
        FROM
            JULY
        GROUP BY
            FLAVOR
        
    ) AS J
ON
    F.FLAVOR = J.FLAVOR
ORDER By
    (F.TOTAL_ORDER + J.TOTAL_ORDER)  DESC
LIMIT
    3