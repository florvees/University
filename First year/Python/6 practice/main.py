import csv
from random import sample
from os import makedirs


def show(reading_mode, lines_amount, file_data):
    if lines_amount == '':
        lines_amount = 5

    lines_amount = int(lines_amount)
    if len(file_data) - 1 < 5:
        reading_mode = 'top'
        print('Not enough lines')

    lines_lenght = list()
    for i in range(0, len(file_data[0])):
        one_line = list()
        for j in range(0, lines_amount):
            one_line.append(len(str(file_data[j][i])))
        lines_lenght.append(one_line)

    if reading_mode == 'top' or reading_mode == '':
        for i in range(0, lines_amount + 1):
            for j in range(0, len(file_data[0])):
                print(str(file_data[i][j]).center(max(lines_lenght[j])), end=' ')
            print("\n")

    if reading_mode == 'bottom':
        file_data.append(file_data[0])
        for i in reversed(range(len(file_data) - lines_amount - 1, len(file_data))):
            for j in range(0, len(file_data[0])):
                print(str(file_data[i][j]).center(max(lines_lenght[j])), end=' ')
            print("\n")

    if reading_mode == 'random':
        rrdata = sample(file_data[1:], lines_amount)
        rrdata.insert(0, file_data[0])
        for i in range(0, lines_amount + 1):
            for j in range(0, len(file_data[0])):
                print(str(rrdata[i][j]).center(max(lines_lenght[j])), end=' ')
            print("\n")


def type_definer(input_data):
    try:
        int(input_data)
        return 'int'
    except:
        pass
    try:
        float(input_data)
        return 'float'
    except:
        pass
    return 'string'


def info(input_file):
    print(f'{len(input_file) - 1}x{len(input_file[0])}')
    for i in range(len(input_file[0])):
        data_amount = 0
        data_type = ''
        for j in range(len(input_file) - 1):
            if type_definer(input_file[j][i]) == 'float':
                data_type = 'float'
            if input_file[j][i] != '':
                data_amount += 1
        if data_type != 'float':
            data_type = type_definer(input_file[j][i])
            print(input_file[0][i], data_amount, data_type)


def del_nan(file_data):
    cleaned_list = list()
    for i in range(0, len(file_data)):
        if '' not in file_data[i]:
            cleaned_list.append(file_data[i])
    return cleaned_list


def make_ds(file_data):
    num = int((len(data) - 1) * 0.7)
    rdata = sample(data[1:], len(data) - 1)
    makedirs('workdata/learning')
    makedirs('workdata/testing')
    train = open('workdata/learning/train.csv', 'w', newline='')
    test = open('workdata/testing/test.csv', 'w', newline='')
    writer_70 = csv.writer(train)
    writer_30 = csv.writer(test)
    writer_70.writerow(data[0])
    writer_30.writerow(data[0])
    for i in range(num):
        writer_70.writerow(rdata[i])
    for j in range(num, len(data) - 1):
        writer_30.writerow(rdata[j])


with open("Titanic.csv", "r") as file:
    data = list(csv.reader(file, delimiter=','))
    show('bottom', 10, data)
    info(data)
    # before using the function below, make sure that workdata directory does not exist
    # make_ds(data)

