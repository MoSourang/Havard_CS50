import csv
import sys
STR_num = 1

## Variable Declariation
STR = []
STR_num = 1
STR_long = {}

## declaration of temp vairable
STR_counter = 0
STR_index = 0
STR_list = []
start = 0

## Checking to make sure that the user provided a valid input
if len(sys.argv) < 3:
    print('Please provide a valid input')

## Open data.csv and read content into memory, saving the first line of the file into a variable dna_data
else:
        dna_data = open(sys.argv[1], 'r')
        dna_reader = csv.reader(dna_data)
        STR = next(dna_reader)

## Removing null terminator from current STR sequence
        for s in range(len(STR)):
            STR[s] =  STR[s].replace('\n', '')

## Open and read individial dna sequence .. text file format
        f = open(sys.argv[2])
        sequences = f.read()

## outer loop for each STR seqeunce, excluding the name field
        for i in range(len(STR) - 1):

## rest all temp vairable
            STR_list = []
            STR_index = 0
            STR_counter = 0
## innner loop to count the STR repeats at each point in the DNA sequence
            for i in range(len(sequences)):
                if sequences.find(STR[STR_num], i, i + ((len(STR[STR_num])))) >= 1:
                    STR_counter = 0
                    start = sequences.find(STR[STR_num], i, i + ((len(STR[STR_num]))))
                    for s in range(round((len(sequences) / len(STR[STR_num]) - 1))):
                        if STR[STR_num] in sequences[start: start + (len(STR[STR_num]))]:
                            STR_counter += 1
                            start += len(STR[STR_num])
                else:
                    STR_list.insert(STR_index , STR_counter)
                    STR_index += 1

                start = 0
## Updating dictionary to store the longest STR of the current DNA sequence
            STR_long.update({STR[STR_num]: max(STR_list)})
            STR_num +=1

## check if the current DNA sequence matches any person
f.close()
dna_data.close()
match_count = 0


##find the matches in the sequences

with open(sys.argv[1], 'r') as dna_data:
    dna_reader = csv.DictReader(dna_data)

    for d in dna_reader:
        for STR , COUNT in STR_long.items():
            if int(COUNT) == int(d[STR]):
                match_count +=1

        if match_count == len(STR_long):
            print(d['name'])
            sys.exit(0)

        else:
            match_count = 0

print('No Match')

