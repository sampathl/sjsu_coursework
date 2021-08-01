import datetime
import requests

for iteration in range(3):
    output= requests.get('https://webhook.site/eb1f2c16-1c23-4223-a849-f467ead1cbc1')
    print("call {} at {}".format(iteration+1,output.headers['date']))
