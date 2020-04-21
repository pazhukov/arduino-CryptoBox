import requests
import serial
    
DATA = ''
API_KEY = 'APIKEY'
serialPort = serial.Serial(port = 'COM8', baudrate = 9600, bytesize = 8, timeout = 2, stopbits = serial.STOPBITS_ONE)

# Get BTC Price
r = requests.get('https://min-api.cryptocompare.com/data/price?fsym=BTC&tsyms=USD&api_key=' + API_KEY)
json = r.json();
price = json['USD']
DATA = DATA + "BTC" + str(price) + "|"

# Get ETH Price
r = requests.get('https://min-api.cryptocompare.com/data/price?fsym=ETH&tsyms=USD&api_key=' + API_KEY)
json = r.json();
price = json['USD']
DATA = DATA + "ETH" + str(price) + "|"

# Send to Adruino
serialPort.write(DATA.encode('ascii'))
