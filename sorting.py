PATH = "build\Data.txt"
data_list = []


with open(PATH, 'r') as f:
    data_list = f.readlines()