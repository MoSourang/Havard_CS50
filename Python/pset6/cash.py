from cs50 import get_float
from cs50 import get_int
import math

## initializing variable
Q, D, N, P, = 0 , 0 , 0 , 0
total = 0
change = -1
## prompting the users user for change input

while change <= 0:
      change = (get_float('Changed Owed: ') * 100)

## check for num of quater
if change >= 25:
    Q = change / 25
    change = change % 25

## check for num of dime
if change >= 10:
    D = change / 10
    change = change % 10

## check for num of nickle
if change >= 5:
    N = change / 5
    change = change % 5

## check for num of pennies

P = change
total = Q + D + N + P
print(math.floor(total))

