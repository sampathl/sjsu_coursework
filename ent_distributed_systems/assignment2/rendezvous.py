import math
import sys
from csv_reader import line_data
from hashlib import md5
from requester import Request

REPLICAS=2
connections = {}
servers = ['http://localhost:5000','http://localhost:5001','http://localhost:5002', 'http://localhost:5003']
class Rendezvous():
    
    def __init__(self):
        
        shards = self.create_shards(REPLICAS)
        self.shards = shards
        hashed_shards = [hash_key(shard) for shard in shards]
        hashed_shards.sort()
        self.hashed_shards = hashed_shards
        self.ring = {hash_key(shard): shard.split("-")[1] for shard in shards}

    @staticmethod
    def create_shards(replicas):
        
        shards = []
        for shard_num in range(replicas):
            for server in servers:
                shards.append("{0}-{1}".format(shard_num, server))
        return shards

    @staticmethod
    def merge_hashes(hased_key, shard_inf):
        merged_hashes=(((hased_key | 1) * (shard_inf | 1)) % (2**64))
        return merged_hashes

    def find_shard(self, key):

        hased_key = hash_key(key)
        combined = [(self.merge_hashes(hased_key, hash_shard), self.ring[hash_shard]) for hash_shard in self.hashed_shards]
        sort_combined = sorted(combined)
        return [host for _, host in sort_combined[:1]][0]
    
def hash_key(key):
        
    m = md5(key.encode())
    hashed_key = int(m.hexdigest(), 16)
    return hashed_key

def send_requests(data_file):
    
    entries = 0
    map = Rendezvous()
    post_data = line_data(data_file)
    for server in servers:
        connections[server] = Request(server)
    for key, value in post_data:
        hashed_key=str(hash_key(key))
        mapped_server= map.find_shard(key)
        connections[mapped_server].post_entries(dict([(hashed_key, value)]))
        entries += 1
    print('Uploaded all {} entries.\n Verifying the data.'.format(entries))
    #str_f="Uploaded all"+ str(entries)+" entries.\n Verifying the data.\n"
    #with open('consistent_output', 'a') as f:
        #f.write(str_f)
    for connection in connections.values():
        print("GET {}\n".format(connection.get_host()))
        #str_f="GET"+str(connection.get_host())
        #with open('consistent_output.txt', 'a') as f:
            #f.write(str_f)
        connection.get_entries()
        


if __name__ == "__main__":
    if len(sys.argv) > 1:
        data_file = sys.argv[1]
        send_requests(data_file)
    else:
        print("Please provide data file name as arguments\nThankyou")
        sys.exit()