"""Dict = {'Roll_No': '16/001', 'Name': 'Arav', 'Course': 'BTech'}

print("Dict[RO11_NO]=", Dict['Roll_No'])

print("Dict[NAME] =", Dict['Name'])

print("Dict[COURSE]=", Dict['Course'])

Dict['Marks'] = 95 # new entry

print("Dict [MARKS] = ", Dict['Marks'])

Dict['Course'] = 'BCA'

print("Dict[COURSE]", Dict['Course']) #entry updated """






"""Dict = {'Roll_No': '16/001', 'Name': 'Arav', 'Course': 'BTech'}

print("Name is: ", Dict.pop('Name')) # returns Kane)

print("Dictionary after popping Name is: ", Dict)

print("Marks is:", Dict.pop('Marks', 10)) # returns default value

print("Dictionary after popping Marks is: ", Dict)

print("Randomly popping any item: ",Dict.popitem())

print("Dictionary after random popping is: ", Dict)

print("Aggregate is:", Dict.pop('Aggr')) # generates error

print("Dictionary after popping Aggregate is: ", Dict)"""






"""Students = {'Shiv': {'CS':90, 'DS':89, 'CSA':92},

'Sadhvi': {'CS':91, 'DS':87, 'CSA':94},

'Krish': {'CS':93, 'DS':92, 'CSA':88}}

for key, val in Students.items():

    print(key, val)"""





d = {"k1": [1, 2, 3], "tricky": ["oh", "man", "inception", {"target": [1, 2, 3, "hello"]}]}
print(d["tricky"][3]["target"][3])