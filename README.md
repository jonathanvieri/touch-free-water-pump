```
import Hardware
import RPi.GPIO as GPIO
import smtplib
import time
import ssl


# setup

GPIO.setmode(GPIO.BCM)

# Water Pump
RELAY = Hardware.Relay(12, False)

# Ultrasonic Sensor
TRIG = 23
ECHO = 24

GPIO.setup( TRIG, GPIO.OUT)
GPIO.setup( ECHO, GPIO.IN)


# Functions

def Distance():
    GPIO.output(TRIG, False)
    time.sleep(2)
    
    GPIO.output(TRIG, True)
    time.sleep(0.0001)
    GPIO.output(TRIG, False)
    
    while GPIO.input(ECHO)==0:
        time_start = time.time()
    
    while GPIO.input(ECHO)==1:
        time_stop = time.time()
        
    time_duration = time_stop - time_start 
    distance = time_duration * 17150
    distance = round(distance, 2)
    
    return distance
	
	
def pump_water(relay, input):

	if ( (input > 0) and (input <= 20)):		
		relay.on()
		print("Water is being pumped")
	
	else:
		relay.off()
		print("Water is no longer pumped")

		
def main():
	input = Distance()
    pump_water(RELAY, input)
	
	
while True:
	time.sleep(0.5)
	main()
  ```
