

SELECT DISTINCT name
FROM people
WHERE people.id IN
(
    SELECT stars.movie_id
    FROM stars
    WHERE movie_id in (
        SELECT movies.id
        FROM movies
        WHERE year = 2004
)
)
ORDER BY birth ASC


