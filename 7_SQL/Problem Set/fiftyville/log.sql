-- Keep a log of any SQL queries you execute as you solve the mystery.

-- 1. To get some information about the theft
-- SELECT description
--   FROM crime_scene_reports
--  WHERE year = 2021 AND month = 7 AND day = 28;

-- Keywords: 10:15am, 3 witnesses, bakery

-- 2. To get more info from witnesses' transcript
-- SELECT transcript
--   FROM interviews
--  WHERE year = 2021 AND month = 7 AND day = 28;

-- Keywords: Mr.Windibank-France, car, Emma's bakery, Leggett Street-withdraw money,
-- phone call-less than 1 minute, eailiest flight tommorrow, Robert and Patrick, Paris, German

-- 3. To see the ATM's log
-- SELECT account_number
--   FROM atm_transactions
--  WHERE year = 2021 AND month = 7 AND day = 28
--        AND atm_location = 'Leggett Street'
--        AND transaction_type = 'withdraw';

-- Get some transaction numbers

-- 4. To get more info from bakery
-- SELECT license_plate
--   FROM bakery_security_logs
--  WHERE year = 2021 AND month = 7 AND day = 28
--        AND hour = 10 AND minute BETWEEN 5 AND 25;

-- Get some car license plates

-- 5. To get more info from calls
-- SELECT caller, receiver, duration
--   FROM phone_calls
--  WHERE year = 2021 AND month = 7 AND day = 28
--        AND duration <= 60;

-- Get some phone calls log.

-- 6. To get more info from flights
-- SELECT id, origin_airport_id, destination_airport_id
--   FROM flights
--  WHERE year = 2021 AND month = 7 AND day = 29;

-- Get some ids.
-- id:18, 23, 36, 43, 53
-- Origin:8 destination: 6, 11, 4, 1, 9

-- 7. To get more info from airports
-- SELECT *
-- FROM airports
-- WHERE id in (6,11,4,1,9);

-- Get some info about airports

-- 8. Use the flight_id to get passport_number
-- SELECT passport_number
--   FROM passengers
--  WHERE flight_id IN (
--     SELECT id
--       FROM flights
--      WHERE year = 2021 AND month = 7 AND day = 29
-- );

-- 9. Use all the evidence to get the thief's name
SELECT name
  FROM people
 WHERE phone_number IN (
    SELECT caller
      FROM phone_calls
     WHERE year = 2021 AND month = 7 AND day = 28
           AND duration <= 60
) AND passport_number IN (
      SELECT passport_number
        FROM passengers
       WHERE flight_id IN (
             SELECT id
               FROM flights
              WHERE year = 2021 AND month = 7 AND day = 29
       )
) AND license_plate IN (
      SELECT license_plate
        FROM bakery_security_logs
       WHERE year = 2021 AND month = 7 AND day = 28
             AND hour = 10 AND minute BETWEEN 5 AND 25
) AND id IN (
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number
          FROM atm_transactions
         WHERE year = 2021 AND month = 7 AND day = 28
               AND atm_location = 'Leggett Street'
               AND transaction_type = 'withdraw'
    )
);

-- Get two names: Bruce and Diana, We know that the thief is male, so Bruce is the thief.

-- 10. Get the city where the thief went to
SELECT city
  FROM airports
 WHERE id = (
       SELECT destination_airport_id
         FROM flights
        WHERE id = (
              SELECT flight_id
                FROM passengers
               WHERE passport_number = (
                     SELECT passport_number
                       FROM people
                      WHERE name = 'Bruce'
               )
        )
);

-- Get the city name: New York City

-- 11. Get the accomplice's name
SELECT name
  FROM people
  WHERE phone_number = (
        SELECT receiver
          FROM phone_calls
         WHERE year = 2021 AND month = 7 AND day = 28
               AND duration <= 60
               AND caller in (
                   SELECT phone_number
                    FROM people
                    WHERE name = 'Bruce'
               )
  );

-- Get the accomplice's name: Robin