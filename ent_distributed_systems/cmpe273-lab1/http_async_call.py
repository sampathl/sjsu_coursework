import requests
import asyncio

async def main():
    loop = asyncio.get_event_loop()

    call1 = loop.run_in_executor(None, requests.get, 'https://webhook.site/eb1f2c16-1c23-4223-a849-f467ead1cbc1')
    call2 = loop.run_in_executor(None, requests.get, 'https://webhook.site/eb1f2c16-1c23-4223-a849-f467ead1cbc1')
    call3 = loop.run_in_executor(None, requests.get, 'https://webhook.site/eb1f2c16-1c23-4223-a849-f467ead1cbc1')
    #print(call1)
    date1 = await call1
    date2 = await call2
    date3 = await call3

    print(date1.headers['date'])
    print(date2.headers['date'])
    print(date3.headers['date'])

print("asyncronous")
loop=asyncio.get_event_loop()
loop.run_until_complete(main())
loop.close()
## reference chrisitan answer from "https://stackoverflow.com/questions/22190403/how-could-i-use-requests-in-asyncio"
