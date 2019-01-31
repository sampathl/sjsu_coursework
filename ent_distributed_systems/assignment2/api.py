from flask import Flask
from flask_restful import reqparse, abort, Api, Resource, request
import sys
import json


app = Flask(__name__)
api = Api(app)
parser = reqparse.RequestParser()

datastore = []
req_json = {}
port=0
class Datastore(Resource):
    
    def get(self):
        
        req_json["num_entries"] = str(len(datastore))
        req_json["entries"] = datastore
        #print(req_json["entries"])
        #print("http://localhost:{}".format(port))
        return req_json

    def post(self):
        if not request.json:
            abort(400)
        entry = request.json
        datastore.append(entry)
        #print(entry)
        return 201

api.add_resource(Datastore, '/api/v1/entries')



if __name__ == '__main__':
    if len(sys.argv) > 1:
        port = sys.argv[1]
        app.run(port = port, debug=True)
    else:
        print("Please provide port number as arguments \nThankyou")
        sys.exit()
        