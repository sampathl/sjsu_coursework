import requests
import asyncio

async def request_call(iteration):
  output= requests.get('https://webhook.site/eb1f2c16-1c23-4223-a849-f467ead1cbc1')
  print("call {} at {}".format(iteration+1,output.headers['date']))

async def main():
  for i in range(3):
      asyncio.ensure_future(request_call(i))

loop=asyncio.get_event_loop()
loop.run_until_complete(main())
loop.close()
