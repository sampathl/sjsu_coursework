Description:

	This is a brief description of the hardware and software used for the CatBistro prototype device. License info, setup steps, and referecense are also included.

Hardware (high level):

	One Raspberry Pi 3 Model B
	One 10kg load cell for cat scale
	One 1kg load cell for food scale
	Two HX711 analog to digital converter / load cell amplifier
	One L293DNE motor driver
	Three C batteries
	A breadboard to make connections easier

	Our prototype used PetMate Automatic Cat Feeder frame and DC motor

Software:

	Requires Python 2.7
	scale_calibrations.py is used during set up to calibrate both food and cat scales
	hx711_python_2.py includes class definition needed to control HX711
	catBistro.py script will automatically get called from cron job that is scheduled
	
	Requires Nodejs 4.0.0. or higher
	app.js will communicate with MongoDB running remote on AWS server
	Will keep listening for any new shceduling events and will also send analytcal data 
	like cat's last seen weight received from Catdeefer.
	require $ npm install before running for firsttime

License:

	License for HX711 code from the following git repository:
	https://github.com/gandalf15/HX711

CatBistro device setup steps:

	1) Add dry food to the CatBistro hopper.
	2) Plug in device into wall outlet
	3) Calibrate scales
		python scale_calibrations.py
	4) Hardware portion is done :) Whenever a feeding is scheduled, catBistro.py script will run.

References used for hardware and code:

	Useful image with GPIO pins for Raspberry Pi Model B:
	https://www.raspberrypi-spy.co.uk/wp-content/uploads/2012/06/Raspberry-Pi-GPIO-Layout-Model-B-Plus-rotated-2700x900.png

	Using load cells and hx711 with Raspberry Pi:
	https://tutorials-raspberrypi.com/digital-raspberry-pi-scale-weight-sensor-hx711/

	Controlling DC motor using Raspberry Pi:
	https://business.tutsplus.com/tutorials/controlling-dc-motors-using-python-with-a-raspberry-pi--cms-20051

