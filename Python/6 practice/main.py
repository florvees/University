import csv

with open("Titanic.csv", "r") as file:
    data = list(csv.reader(file, delimiter=','))
    print(data)