import csv
import sys
from cs50 import SQL

db = SQL("sqlite:///students.db")


### check commmand line agr

if  2 < len(sys.argv) > 2:
    print('Please provide a csv file name')

### Open CSV file based on user provided input

else:

    with open(sys.argv[1], "r") as students_data:
        reader = csv.DictReader(students_data)

        for row in reader:

## insert data into students databaese

            if row['name'].count(" ") == 1:
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(? , ? , ? ,?, ?)",
                row['name'].split(" ")[0], 'NULL', row['name'].split(" ")[1], row['house'],row['birth'])

            else:
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(? , ? , ? ,?, ?)",
                row['name'].split(" ")[0], row['name'].split(" ")[1], row['name'].split(" ")[2],row['house'],row['birth'])


