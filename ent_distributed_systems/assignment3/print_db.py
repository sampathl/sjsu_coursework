import pickledb

file_name=['assignment3_3000.db','assignment3_3001.db','assignment3_3002.db','assignment3_3003.db']

for file_n in file_name:
    db=pickledb.load(file_n,False)
    print(file_n)
    print("foo {}".format(db.get("foo")))
    print("bar {}".format(db.get("bar")))