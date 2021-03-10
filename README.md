# Scytale

This project implements three ancient ciphers in the C programming language. This project is for fun and to learn some new coding design patterns. It does not provide any real security. The three ciphers implemented are the **Caesar Cipher**, **Vigenere Cipher**, and the **Polybius Cipher**.

## Caesar Cipher

This substitution cipher uses a one byte key to transform the plain text into cipher text. To encrypt, the value of the key is added to each letter and that result is used as the cipher text.

Here is an example using the English alphabet and a key = 23:

||||||||||||||||||||||||||||
|---|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|**Plain Text**|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z
|**Cipher Text**|X|Y|Z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|

To decrypt, simply use the same key and subtract it from each letter of the cipher text to recreate the original plain text.

## Vigenere Cipher

This substitution cipher uses a key of unlimited length to transform the plain text into cipher text. It is best described as a unlimited length Caesar Cipher. If the key is shorter than the plain text, then after each letter has been used from the key, it will wrap back around to the begining of the key.

For instance, if the plaintext is *attack at dawn* and the key is 1234, then the resulting plaintext will be:
|               |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|---------------|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|**Plain Text** | a | t | t | a | c | k |   | a | t |   | d | a | w | n |
|**Key**        | 1 | 2 | 3 | 4 | 1 | 2 |   | 3 | 4 |   | 1 | 2 | 3 | 4 |
|**Cipher Text**| b | v | w | e | d | m |   | d | x |   | e | c | z | r |

Similar to the Caesar Cipher, to decrypt simply use the same key and subtract the value from each letter to generate the original plain text.

## Polybius Cipher

The last implemented cipher is the polybius cipher. This cipher uses a table to substitute a pair of numbers for each letter in the plain text. Each letter is replaced by its location in the table by the number for the row, then the number for the column. For instance, using the English alphabet in a 5 x 6 rectangle:

| |1|2|3|4|5|6|
|---|---|---|---|---|---|---|
|**1**| A | B | C | D | E | F |
|**2**| G | H | I | J | K | L |
|**3**| M | N | O | P | Q | R |
|**4**| S | T | U | V | W | X |
|**5**| Y | Z |   |   |   |   |

To encode the message *attack at dawn*:

11 42 42 11 13 25 11 42 14 11 45 32

To decode the cipher text, use the same table and replace each pair of digits with the letter they correspond to.
