SELECT AVG(rating) as Avg_rating
FROM ratings
JOIN  movies
 ON movie_id = id
WHERE year = 2012