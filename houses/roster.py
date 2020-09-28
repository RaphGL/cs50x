import sqlite3
import sys

if len(sys.argv) != 2:
    print("One argument should be given")
    sys.exit(1)

conn = sqlite3.connect('students.db')
c = conn.cursor()
c.execute('SELECT * FROM students WHERE house=? ORDER BY last, first', sys.argv[1:])
students = c.fetchall()
for student in students:
    student = '|'.join([str(i) for i in student[1:]])
    print(student)
conn.commit()
conn.close()
