from cs50 import get_string
from cs50 import get_int

## variable declaration


Height = get_int('Please enter Size:')
space = Height - 1
draw = 1
while Height not in range(1,9):
     Height = get_int('Please enter Size:')

### creating a rows based on Height
for i in range(Height):
### printing spaces based on height - 1
        for j in range(space):
            print(' ' , end='')
### printing # based incrementation of draw
        for e in range(draw):
            print('#', end= '')
        print('\n', end='')
###
        space = space - 1
        draw = draw + 1




