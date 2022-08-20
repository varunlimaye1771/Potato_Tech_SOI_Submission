# Potato_Tech_SOI_Submission

## Hardware/Structural design information
- Plastic chassis x1
- Wheels x2
- Castor wheel x1
- Nuts and bolts M3X30, M3X12
- Ultrasound sensor holder

## Parts list, Bill of Materials
- IR Sensor: Rs. 32 
- Ultrasound sensor HC-SR04: Rs. 68
- Bluetooth module HC-05: Rs. 282
- Arduino UNO R3: Rs. 650
- DC geared motor: Rs. 65
- 7.4V lithium ion battery 2200 mAh: Rs. 500 
- Flip switch
- L293D motor driver: Rs. 121
### Total Cost of kit provided: Rs. 2000

## Observations, failed attempt records, test data, etc.
### 1st Prototype 
- 2 Ultrasonic Sensors were used.
- The rover failed to move in a straight line.
- It wasn't able to execute a perfect 90 degree turn.
 #### Initial alogorithm:
- The bot follows the direction heirarchy left > front > right
- If no obstacle is encountered on the left, the bot turns left.
- If an obstacle is encountered on the left but the forward direction does not have any obstacle, the bot moves forward.
- If both the left and forward directions are blocked, the bot takes a right turn.
- In case the right direction has an obstacle too, the bot turns right again and moves forward (effectively taking a U-turn).
> Credits: Ganesh Karamsetty
### 2nd Prototype
- One of the ultrasonic sensors did not work.
- The bluetooth was only compatible with 5V and not 3.3V supply.
### 3rd prototype
- The castor wheel was not functioning smoothly
- The provided ultrasound sensor and bluetooth module were drawing more power than expected.
- Algorithm: 
### 4th prototype
- Combination of an Ultrasonic and an IR Sensor  
 #### Final algorithm:
- The bot checks for a wall by using the IR Sensor mounted on the left side.
- When it encounters a wall, the bot moves to the right by a small angle using its left wheel.
- It then tries to find the wall again. Using its right wheel, it rotates slightly to the left until the IR sensor detects the wall again.
- The Ultrasonic Sensor detects any obstacle present in the front. The bot goes around the obstacle, treating it as a wall.
> Credits: Rudra

### Assembly, Setup and Calibration Instructions
- Arrange the components as shown in the circuit diagram and complete the necessary connections. The circuit diagrams and Arduino Bluetooth Controller app screenshots can be found in the Wiki section of our repository.
- Connect the Arduino board to the laptop, disconnect the tx and rx pins of the bluetooth module and upload the code.
- Disconnect the Arduino board from laptop and connect the tx and rx pins of bluetooth module.
- Turn the switch on, connect the bluetooth module with phone.
- Calibrate the bluetooth app as shown in the attached image.
- Now the rover is ready for some action!


## Credits, citations and references:
- YouTube: For looking up maze solving models
- Tinkercad: For circuit design
- Arduino (https://www.arduino.cc/reference/en): For looking up functioning of Ultrasound Sensor, Bluetooth Module, IR Sensor and Motor Driver
- Arduino Bluetooth Controller
