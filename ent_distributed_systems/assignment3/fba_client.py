from twisted.internet.protocol import DatagramProtocol
from twisted.internet import reactor
import sys
import socket


class MulticastPingClient(DatagramProtocol):

    def startProtocol(self):
        # Join the multicast address, so we can receive replies:
        self.transport.joinGroup("228.0.0.5")
        # Send to 228.0.0.5:8005 - all listeners on the multicast address
        # (including us) will receive this message.
        port=3000
        if len(sys.argv)>1:
            port=int(sys.argv[1])
            #print(port)
        #datagram_1=('Client: Ping').encode()
        messages = ['foo:$10','bar:$30','foo:$20','bar:$20','foo:$30','bar:$10']
        for message in messages:
            datagram_1=(message).encode()
            self.transport.write(datagram_1, ("228.0.0.5", port))
        

    def datagramReceived(self, datagram, address):
        datagram_2=datagram.decode()
        #print(datagram_2)
        #print(address)
        #ip=address[0]
        port_rec=address[1]
        print ("From node at {} received:{} ".format(port_rec,datagram_2))


if __name__=='__main__':
    port=3000
    if len(sys.argv)>1:
        port=int(sys.argv[1])
    reactor.listenMulticast(8004, MulticastPingClient(), listenMultiple=True)
    #this port needs to be specified
    reactor.run()