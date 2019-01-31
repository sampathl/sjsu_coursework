import pickledb
db=pickledb.load('new.db',False)


def set_value(strg):
    index=strg.find(':')
    key=str(strg[:index])
    value=int(strg[index+2:])
    if db.get(key):
        old_value=db.get(key)
        new_value=old_value+value
        db.set(key,new_value)
    else:
        db.set(key,value)

messages = ['foo:$10','bar:$30','foo:$20','bar:$20','foo:$10','bar:$10']
for message in messages:
    set_value(message)


"""
set_value("foo:$10")
#db.set('foo',300)
db.set('bar',300)"""
print(db.get('foo'))
new=db.get('foo')
print(db.get('bar'))
#print(db.dump())