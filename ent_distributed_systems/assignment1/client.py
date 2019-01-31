import threading
import sys
from time import sleep
import grpc
import group_chat_pb2
import group_chat_pb2_grpc


port = 3000
User_name = ''

class Client:

    def __init__(self, u: str):

        User_name = u
        self.userslist = []
        with grpc.insecure_channel("localhost:" + str(port)) as channel:
            chat_stub = group_chat_pb2_grpc.ChatServerStub(channel)
            print("[Spartan] Connected to Spartan Server at port {}.".format(port))     
            threading.Thread(target=self.__listen_for_messages, args=[chat_stub], daemon=True).start()
            self.send_message(chat_stub)

        
    def __listen_for_messages(self, chat_stub):
        for message in chat_stub.New_messege(group_chat_pb2.Blank()):
            if (message.name!= User_name):
                print("[{}] {}".format(message.name, message.note))
        
    def add_user(self, chat_stub):
        ur = group_chat_pb2.User()
        ur.name = User_name
        chat_stub.New_user(ur)

    def send_message(self, chat_stub):
        while(True):
            try:
                m = input('[{}] >'.format(User_name))
                if m is not '':
                    n = group_chat_pb2.Message()
                    n.name = User_name
                    n.note = m
                    chat_stub.Send_messge(n)
            except KeyboardInterrupt:
                print("*******thank you" )
                sys.exit()
            

if __name__ == '__main__':
    if len(sys.argv)== 1:
        print("Please add username after the file name to start the client ")
        sys.exit()
    elif len(sys.argv)== 2:
        User_name = sys.argv[1]
    elif len(sys.argv)>2:
        print("Too many users please check") 
    c = Client(User_name)