from cs50 import get_string
import math

count_l = 0
count_w = 1
count_s = 0
grade = 0
## Prompt the user for textual input
text = get_string('Please enter text: ')

## Count the # of letters in text
for l in range(len(text)):
    if text[l].isalpha():
        count_l += 1

## Count the # of words in text
for w in range(len(text)):
    if ' ' in text[w]  or '  ' in text[w]:
        count_w += 1

## count the # of sentence in text
for s in range(len(text)):
    if "?" in text[s] or '!' in text[s] or '.' in text[s]:
        count_s += 1

L =  (count_l/count_w) * 100
S =  (count_s/count_w) * 100

grade = round(0.0588 * L - 0.296 * S - 15.8)

if grade < 1:
    print('Before Grade ' f'1')

elif  grade > 16:
    print("Grade " f'16+')

else:
    print('Grade ' f'{grade}')

