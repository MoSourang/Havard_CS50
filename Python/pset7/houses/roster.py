import csv
import sys
from cs50 import SQL


db = SQL("sqlite:///students.db")

if  2 < len(sys.argv) > 2:
    print('Please provide a valid house name')

else:
    house_name = sys.argv[1]
    results = db.execute ("SELECT first , middle, last, birth FROM students WHERE house= ? ORDER BY last , first", house_name )

    for r in results:
        if r["middle"] == "NULL":
            print(r["first"],r["last"], ",", "born", r["birth"])
        else:
             print(r["first"], r["middle"], r["last"], ",", "born", r["birth"])








