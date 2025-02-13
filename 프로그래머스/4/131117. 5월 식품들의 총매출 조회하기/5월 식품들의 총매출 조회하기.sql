WITH TEMP AS (
    SELECT
        PRODUCT_ID,
        SUM(AMOUNT) AS AMOUNT
    FROM
        FOOD_ORDER
    WHERE
        PRODUCE_DATE LIKE "2022-05%"
    GROUP BY
        PRODUCT_ID
)

SELECT
    B.PRODUCT_ID,
    PRODUCT_NAME,
    B.PRICE * R.AMOUNT AS TOTAL_SALES
FROM
    FOOD_PRODUCT B
JOIN
    TEMP R
ON
    B.PRODUCT_ID = R.PRODUCT_ID
ORDER BY
    TOTAL_SALES DESC,
    B.PRODUCT_ID ASC
    