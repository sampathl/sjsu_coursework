# This script will be run by cron job, it will drive the motor to drop the
# food for the cat. It will verify that food has been dropped, take the weight
# of the cat and send data to the database.

from hx711_python_2 import HX711
import RPi.GPIO as GPIO
import time
from time import sleep
import sys
import datetime

# ensure that we have the amount of cat food passed in
if len(sys.argv) != 2:
	print 'Not the correct number of arguments!'
	print 'Must pass in the amount of food to feed the cat in grams'
	sys.exit()

# set GPIO pins to Broadcom SOC channel
GPIO.setmode(GPIO.BCM)

# motor driver GPIO pins and setup
Motor1A = 13
Motor1B = 19
Motor1E = 26

GPIO.setup(Motor1A,GPIO.OUT)
GPIO.setup(Motor1B,GPIO.OUT)
GPIO.setup(Motor1E,GPIO.OUT)

# scale ratio's from scale calibration script
# if CatBistro device is moved, calibrate again and use the new scale ratios
# perhaps we should use environment variables so we don't have to hardcode the ratios
cat_scale_ratio = 42376.0506539
food_scale_ratio = 69.0968380257

# hx711 objects for each scale
hx_cat  = HX711(dout_pin=6, pd_sck_pin=5, gain_channel_A=64, select_channel='A')
hx_food = HX711(dout_pin=21, pd_sck_pin=20, gain_channel_A=64, select_channel='A')

# tare the scales
hx_cat.zero(times=10)
hx_food.zero(times=10)

# set the scale ratio
hx_cat.set_scale_ratio(scale_ratio=cat_scale_ratio)
hx_food.set_scale_ratio(scale_ratio=food_scale_ratio)

# get amount of food to feed the cat
feed_amount = float(sys.argv[1])
food_weight = 0

# feed the cat, ensure that motor motor pours food out if it gets stuck
while (food_weight <= 1):
	print "Turning motor on"
	GPIO.output(Motor1A,GPIO.HIGH)
	GPIO.output(Motor1B,GPIO.LOW)
	GPIO.output(Motor1E,GPIO.HIGH)

	# one rotation of motor is approximately 2 seconds long
	# one rotation provides approximately 12 grams of food
	number_of_rotations = feed_amount / 12.0
	sleep(2 * number_of_rotations)
 
	print "Stopping motor"
	GPIO.output(Motor1E,GPIO.LOW)
	
	# delay for food to make its way to the food bowl
	sleep(3)
	
	# measure how much food, in grams, was poured into the food bowl
	# '99' represents the number of samples taken from hx711
	food_weight = hx_food.get_weight_mean(99)

# take the weight of the cat in pounds
cat_weight = 0

while (cat_weight < 1):
	# cat may not eat immediately when food is poured, take measurements every 10 seconds
	sleep(10)
	cat_weight = hx_cat.get_weight_mean(99)

# get the current time
date = datetime.datetime.now().isoformate()

# TODO: send data to server in the following format
# {
# "feedername": "Patio-1",
# "feedtime" : "2012-04-23T18:25:43.511Z",
# "feedwt": 23,
# "lastfeedtime": "2012-04-23T18:25:43.511Z",
# "lastfoodwt": 10,
# "catwt": 17
# }

# clean up all GPIO pins
finally:
	GPIO.cleanup()

