WITH TEMP AS (SELECT
    B.HISTORY_ID,
    B.CAR_ID,
    CAR_TYPE,
    DAILY_FEE,
    DATEDIFF(END_DATE,START_DATE)+1 AS DAYS,
    CASE
        WHEN DATEDIFF(END_DATE,START_DATE) +1 >= 90 THEN "90일 이상"
        WHEN DATEDIFF(END_DATE,START_DATE) +1 >= 30 THEN "30일 이상"
        WHEN DATEDIFF(END_DATE,START_DATE) +1 >= 7 THEN "7일 이상"
        ELSE "0"
    END AS DURATION_TYPE  
FROM
    CAR_RENTAL_COMPANY_RENTAL_HISTORY B
JOIN
    (
        SELECT
            CAR_ID,DAILY_FEE,CAR_TYPE
        FROM
            CAR_RENTAL_COMPANY_CAR
        WHERE
            CAR_TYPE ="트럭"
    ) AS R
ON
    B.CAR_ID = R.CAR_ID
),  TEMP2 AS (
    SELECT
        *
    FROM 
        CAR_RENTAL_COMPANY_DISCOUNT_PLAN
    UNION ALL
    SELECT
        19999999 AS PLAN_ID,
        "트럭" AS CAR_TYPE,
        "0" AS DURATION_TYPE,
        0 AS DISCOUNT_RATE
)
# SELECT * FROM TEMP
SELECT
    HISTORY_ID,
    ROUND(DAYS * DAILY_FEE * ((100-DISCOUNT_RATE)*0.01),0) AS FEE
FROM
    TEMP B
JOIN
    TEMP2 R
ON
    B.CAR_TYPE = R.CAR_TYPE AND B.DURATION_TYPE = R.DURATION_TYPE
ORDER BY
    FEE DESC, HISTORY_ID DESC
    