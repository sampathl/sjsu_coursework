import csv
def line_data(csv_file):
    file_data = csv.DictReader(open(csv_file))
    for entries in file_data:
        yield entries['Year'] + entries['Cause Name'] + entries['State'] , entries['Year'] +','+ entries['113 Cause Name'] +','+ entries['Cause Name'] +','+ entries['State'] +','+ entries['Deaths'] +','+ entries['Age-adjusted Death Rate']
