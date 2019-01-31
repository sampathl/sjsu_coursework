from twisted.internet.protocol import DatagramProtocol
from twisted.internet import reactor
import sys
import socket
import pickledb
import os.path


PORTS= [3000,3001,3002,3003]
THIS_P=0
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

def print_db(file_name):
    print("Updated data in {} to:".format(file_name))
    new_db=pickledb.load(db_name,False)
    print("foo {}".format(new_db.get("foo")))
    print("bar {}".format(new_db.get("bar"))) 

def get_value(strg):
    index=strg.find(':')
    key=str(strg[:index])
    if db.get(key):
        return str(key+':$'+str(db.get(key)))
    else:
        return False

class MulticastPingPong(DatagramProtocol):

    def startProtocol(self):
        """
        Called after protocol has started listening.
        """
        # Set the TTL>1 so multicast will cross router hops:
        self.transport.setTTL(5)
        # Join a specific multicast group:
        self.transport.joinGroup("228.0.0.5")

    def datagramReceived(self, datagram, address):
        datagram_1=datagram.decode()
        ip=address[0]
        port_rec=address[1]
        
        db_name='assignment3_'+str(THIS_P)+'.db'   
        if port_rec in PORTS:
            print ("From node at {} received:{} ".format(port_rec,datagram_1))
            #print("port{}".format(PORTS))
            set_value(datagram_1)
            #print("Updated to {}".format(get_value(datagram_1)))
            db.dump()
            print_db(db_name)
        else:  
            print ("Received:{} from client".format(datagram_1)) 
            check=PORTS.copy()
            if THIS_P in PORTS:
                check.remove(THIS_P)
            #print("port{} check{}".format(PORTS,check))
            set_value(datagram_1)
            for port in check:
                address_new=(ip,port)
                self.transport.write((datagram_1).encode(), address_new)
            datagram_2=(get_value(datagram_1)).encode()
            #   print("this is working")
            self.transport.write(datagram_2, address)
            db.dump()
            print_db(db_name)


# We use listenMultiple=True so that we can run MulticastServer.py and
# MulticastClient.py on same machi"ne:

if __name__=='__main__':
    port=3000
    if len(sys.argv)>1:
        port=int(sys.argv[1])
    THIS_P=port
    db_name='assignment3_'+str(port)+'.db'
    print(db_name)
    db=pickledb.load(db_name,False)
    if os.path.isfile(db_name):
        db.deldb()
    db.dump() # empty db
    reactor.listenMulticast(port, MulticastPingPong(),listenMultiple=True)
    reactor.run()