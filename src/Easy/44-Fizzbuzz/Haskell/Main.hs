import Data.Foldable

fizzBuzz :: Int -> String
fizzBuzz x
 | x `mod` 15 == 0 = "FizzBuzz"
 | x `mod` 5 == 0 = "Buzz"
 | x `mod` 3 == 0 = "Fizz"
 | otherwise = show x

main :: IO ()
main = for_ [1..100] (putStrLn . fizzBuzz)
-- can also be main = traverse_ (putStrLn . fizzBuzz) [1..100]
