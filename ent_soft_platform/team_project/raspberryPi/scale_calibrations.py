# This script will calibrate the weight sensors for the cat scale and the food scale
# Scripts will read the data from hx711 sensor, zero them out to get an offset
# then you will set the ratio depending a well known weight. Process will walk you 
# through when you need to add the known weight each scale and the weight in 
# pounds or grams.
#
# GPIO pins used:
# Cat scale  - DOUT = 6, SCK = 5
# Food scale - DOUT = 21, SCK = 20

from hx711_python_2 import HX711                # import the class HX711
import RPi.GPIO as GPIO         		# import GPIO
import time
import sys

try:
        # create objects which represents the hx711 sensors
        hx_cat = HX711(dout_pin=6, pd_sck_pin=5, gain_channel_A=64, select_channel='A')
	hx_food = HX711(dout_pin=21, pd_sck_pin=20, gain_channel_A=64, select_channel='A')
       
	# reset both sensors
	result = hx_cat.reset()
	result2 = hx_food.reset()

        if result && result2:
		print('Ready to calibrate')
        else:
                print('not ready')
		if (not result):
			print('check hardware for cat scale')
		else:
			print('check hardware for food scale')
		sys.exit()

	# tare the scales
        hx_cat.zero(times=99)
	hx_food.zero(times=99)

        # calibrate cat scale with known weight in pounds
	raw_input('Put known weight on cat scale and then press Enter')
        data = hx_cat.get_data_mean(times=99)

        if data != False:
                known_weight = raw_input('Write how many pounds it was and press Enter: ')
                try:
                        value = float(known_weight)
                        print(str(value) + ' lbs')
                except ValueError:
                        print('Expected integer or float and I have got: '\
                                        + str(known_weight))

                # set scale ratio
                # automatically takes care of the unit we want
                ratio = data / value
                hx_cat.set_scale_ratio(scale_ratio=ratio)
                print('Ratio for cat scale is set to ' + str(ratio))
        else:
                raise ValueError('Cannot calculate mean value. Try debug mode.')

	# repeat the calibration process with the food scale
	# this time with known weight in grams
	raw_input('Put known weight on food scale and then press Enter')
        data = hx_food.get_data_mean(times=99)

        if data != False:
                known_weight = raw_input('Write how many grams it was and press Enter: ')
                try:
                        value = float(known_weight)
                        print(str(value) + ' grams')
                except ValueError:
                        print('Expected integer or float and I have got: '\
                                        + str(known_weight))

                ratio = data / value    # calculate the ratio for channel A and gain 64
                hx_food.set_scale_ratio(scale_ratio=ratio)   # set ratio for current channel
                print('Ratio is set to ' + str(ratio))
        else:
                raise ValueError('Cannot calculate mean value. Try debug mode.')

        # get the actual reading from hx711 sensors
	# this should be really close to the known weight
	print('Current weight on the cat scale in pounds is: ')
        print(str(hx_cat.get_weight_mean(99)) + ' lbs')
	print('Current weight on the food scale in grams is: ')
        print(str(hx_food.get_weight_mean(99)) + ' g')

except (KeyboardInterrupt, SystemExit):
        print('Exiting...')

finally:
        GPIO.cleanup()

