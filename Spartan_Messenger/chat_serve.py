from concurrent import futures
import grpc
import time
import chat_pb2
import chat_pb2_grpc

class spartan_MessengerServicer(chat_pb2_grpc.spartan_MessengerServicer):
    def __init__(self):
        self.user_list=[] # user list with internal structure of [user_name,receiving_user]
        self.chat_list=[] # chat_list with internal struct of [user_name,receiving_user, message]
        self.user_index=[] # index storing for individual user [user_name, last_index]
    
    def test(self,request,context):
        return chat_pb2.empty()

    def add_User(self, request, context):
        print("sampath Lakkaraju")
        for i in self.user_list:
            print("1")
            if request.user_name == i[0]:
                print("2")
                return chat_pb2.empty() #chat_pb2.status(status_info='not_available')
            else:
                print("3")
                user_temp=[request.user_name, request.receiving_user]
                print("4")
                self.user_list.append(user_temp)
                print('New user {} has been added'.format(user_temp[0]))
                print("5")
                user_temp=[request.user_name,0]
                self.user_index.append(user_temp)
                user_temp.clear()
                print("6")
                return chat_pb2.empty()#chat_pb2.status(status_info='Welcome to Spartan messenge')


def run_server():
        #Adding threads to server to run asynchronous 
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
        # Adding the spartan_messengerServicer class to the server
    chat_pb2_grpc.add_spartan_MessengerServicer_to_server(
        spartan_MessengerServicer(),server)
        # Assigning the port 5000 to the server
    server.add_insecure_port('[::]:5000')
        # starting the server
    server.start()
    while True:
        try:
            time.sleep(3600)
        except(SystemExit,KeyboardInterrupt):
            print('[Spartan] Server Shutdown')
            server.stop(0)
            break



if __name__ == '__main__':
   
   run_server() 