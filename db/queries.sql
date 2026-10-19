-- 1. Последние 10 записей показаний
SELECT *
FROM readings
ORDER BY n DESC, id DESC
LIMIT 10;

-- 2. Минимум, среднее и максимум каждого датчика
SELECT sensor,
       MIN(value) AS minimum,
       ROUND(AVG(value), 2) AS average,
       MAX(value) AS maximum
FROM readings
GROUP BY sensor;

-- 3. Все события по порядку
SELECT *
FROM events
ORDER BY n, id;