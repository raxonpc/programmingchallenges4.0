import std/[
  strformat,
  sequtils,
  unicode,
  tables
]

let input = readLine(stdin)

echo "Occurences:"

#[
what happens here:
runes is an iterator, that turns input, a utf-8 encoded string to return codepoints instead of bytes,
toSeq maps it into a sequence (dynamic array)
toCountTable maps it into a CountTable (a hashmap that has a value and the occurences of it)
.pairs() returns immutable tuples of values
(letter, times) is a tuple destruction kinda thing, like `const auto[letter, times]` in C++

fmt"" is a special format syntax thing with string interpolation
]#

for (letter, times) in toCountTable(toSeq(runes(input))).pairs(): 
 echo fmt"Character: [{letter}] occured {times} times."
