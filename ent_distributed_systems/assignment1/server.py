from concurrent import futures
import sys
import grpc
import time

import group_chat_pb2
import group_chat_pb2_grpc



class ChatServicer(group_chat_pb2_grpc.ChatServerServicer):

    def __init__(self):
        self.history = []
        self.new_messege = 0
        self.users = []
        

    def New_messege(self, request_itrator, context):
        new_messege = 0
        
        while True:
            while new_messege < len(self.history):
                n = self.history[new_messege] # group_chat_pb2 will be recorded
                new_messege += 1
                yield n

    def Send_messge(self, request: group_chat_pb2.Message, context):
        self.history.append(request)  
        print("[{}] {}.".format(request.name, request.note))
        return group_chat_pb2.Blank()       

    def New_user(self, request: group_chat_pb2.User, context):
        # Add user to users list
        self.users.append(request) 
        return group_chat_pb2.Blank()          

  
if __name__ == '__main__':
    port = 3000
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=16))
    group_chat_pb2_grpc.add_ChatServerServicer_to_server(ChatServicer(), server)
    #group_chat_pb2_grpc.add_UserServicer_to_server(UserServicer(), server)
    print("Spartan server started on port {}.".format(port))   
    server.add_insecure_port('[::]:' + str(port))
    server.start()
    while(True):
        try:
            time.sleep(3600)
        except(SystemExit, KeyboardInterrupt):
            server.stop(0)
            print("Thank you")
            sys.exit()
