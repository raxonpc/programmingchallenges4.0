const limit = 100

for i in 1 .. limit:
  echo if i mod 3 == 0 and i mod 5 == 0:
    "FizzBuzz"
  elif i mod 3 == 0:
    "Fizz"
  elif i mod 5 == 0:
    "Buzz"
  else:
    $i
