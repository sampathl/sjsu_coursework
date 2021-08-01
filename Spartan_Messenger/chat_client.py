from concurrent import futures
import time
import sys
import grpc
import chat_pb2
import chat_pb2_grpc

def client_adduser(stub,client_name,client_request):
    server_return = stub.add_User(chat_pb2.user_info(user_name=client_name,receiving_user=client_request))
    print(server_return)
   

def run_client():
    
    channel= grpc.insecure_channel('localhost:5000')
    stub=chat_pb2_grpc.spartan_MessengerStub(channel)
    empty1= chat_pb2.empty()
    stub.test(empty1)
    #print('Connected to Spartan server on port 5000')
    if len(sys.argv)==2: 
        client_name=sys.argv[1]
    else:
        client_name= str(input('Please enter your name: ')).lower()
    if bool(client_name):
        client_request=str(input('Please enter the friend you want to talk to \
else please enter "group" for group chat :'))
        if client_request=="":
            print("please enter a valid name or group next time")
            sys.exit()
    client_adduser(stub,client_name,client_request)


if __name__ == '__main__':
    run_client()