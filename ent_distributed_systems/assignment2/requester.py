import json
import re
import http.client

class Request():
    def __init__(self, host):
        
        self.headers = {'Content-type': 'application/json'}
        pattern = '(?:http.*://)?(?P<host>[^:/ ]+).?(?P<port>[0-9]*).*'
        match = re.search(pattern,host)
        self.connection = http.client.HTTPConnection(match.group('host'), match.group('port'))
        self.host = host

    def post_entries(self, data):
        self.connection.request('POST', '/api/v1/entries', json.dumps(data), self.headers)
        response = self.connection.getresponse()
        #print("this {}".format(response.read().decode()))
        print(response.read().decode())
        #return str(response.read().decode())
    
    def get_entries(self):
        self.connection.request('GET', '/api/v1/entries')
        response = self.connection.getresponse()
        print(str(response.read().decode()))
        str_f=str(response.read().decode())
        with open('consistent_output.txt', 'a') as f:
            f.write(str_f)
        #return str(response.read().decode())
    
    def get_host(self):
        return self.host
    
        