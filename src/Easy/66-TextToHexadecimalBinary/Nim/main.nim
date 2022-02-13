import std/[
  strformat,
  strutils,
  unicode
]

func toBin(int: int): string =
  var int = int

  while int > 0:
    result.add( $(int mod 2) )
    int = int div 2

  result.reversed()

func toBin(string: string): string =
  for char in string:
    result.add( char.int.toBin() )

func insertSpaces(string: string, every: int = 4): string =
  string.reversed().insertSep(' ', every)

let input = readLine(stdin)

echo fmt"Text in binary {input.toBin().insertSpaces()}"
echo fmt"Text in hexadecimal: 0x{input.toHex().insertSpaces()}"
