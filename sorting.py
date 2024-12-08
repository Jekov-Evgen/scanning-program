PATH = "build\Data.txt"
data_list = []
result = []


with open(PATH, 'r') as f:
    data_list = f.readlines()

for data in data_list:
    if data.find("not") != -1:
        continue
    else:
        result.append(data)
        
print(result)