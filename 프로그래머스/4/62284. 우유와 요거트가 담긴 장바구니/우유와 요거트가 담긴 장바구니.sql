SELECT
    CART_ID
FROM
    CART_PRODUCTS
GROUP BY
    CART_ID
HAVING
    CASE
        WHEN MAX(
            CASE WHEN NAME ="Milk" THEN 1 ELSE 0 END
        ) = 1 THEN True
        ELSE FALSE
    END AND
    CASE
        WHEN MAX(
            CASE WHEN NAME ="Yogurt" THEN 1 ELSE 0 END
        ) = 1 THEN True
        ELSE FALSE
    END
ORDER BY
    CART_ID