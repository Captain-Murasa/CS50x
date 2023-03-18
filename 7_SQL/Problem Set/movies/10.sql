SELECT DISTINCT name
FROM directors
JOIN movies ON movies.id = directors.movie_id
JOIN people ON people.id = directors.person_id
WHERE movie_id IN (
    SELECT movie_id
    FROM ratings
    WHERE rating >= 9.0
);