WITH TEMP AS (
    SELECT 
        CAR_ID
    FROM
        CAR_RENTAL_COMPANY_RENTAL_HISTORY
    WHERE
        START_DATE BETWEEN '2022-08-01' AND '2022-10-31'
    GROUP BY
        CAR_ID
    HAVING
        COUNT(*) >= 5
)
SELECT
    MONTH(START_DATE) AS MONTH,
    C.CAR_ID,
    COUNT(*) AS RECORDS
FROM
    CAR_RENTAL_COMPANY_RENTAL_HISTORY C
JOIN
    TEMP T
ON 
    C.CAR_ID = T.CAR_ID
WHERE
    START_DATE BETWEEN '2022-08-01' AND '2022-10-31'
GROUP BY 
    MONTH(START_DATE),
    C.CAR_ID
ORDER BY 
    MONTH(START_DATE) ASC, 
    C.CAR_ID DESC;