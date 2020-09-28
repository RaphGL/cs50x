import csv
import sqlite3
import sys

if len(sys.argv) > 2:
    print("Only one argument should be given")
    sys.exit(1)

with open('characters.csv', 'r') as csv_file:
    table = csv.reader(csv_file)
    conn = sqlite3.connect(sys.argv[1])
    c = conn.cursor()
    for row in table:
        length = len(row[0].split(' '))
        temp_row = row[0].split(' ') + row[1:]
        if length == 2:
            c.execute('INSERT INTO students (first, last, house, birth) VALUES (?, ?, ?, ?)', temp_row)
        elif length == 3:
            c.execute('INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)', temp_row)
    conn.commit()
    conn.close()
