# 🚗 Arduino Reverse Alarm System

This project consists of a simple reverse alarm system built using Arduino and an ultrasonic sensor. It was designed to simulate how a car's reverse parking sensor works by detecting how close an object is and activating visual and audible alerts accordingly.

## 🔧 How does it work?

1. An ultrasonic sensor measures the distance between itself and a nearby object.
2. The shorter the distance, the faster the system responds.
3. A red LED and a buzzer are activated to simulate an alarm.
4. As the object gets closer, the LED and buzzer blink more rapidly to indicate danger.

## 🧰 Components Used

- Arduino UNO board
- HC-SR04 Ultrasonic sensor
- Red LED
- Buzzer
- 220 Ohm resistor
- Jumper wires and breadboard
  
## 🎯 Objective

The goal of this project is to replicate the behavior of a car’s reverse alarm system using a low-cost and easy-to-build Arduino circuit. It aims to visually and audibly alert the user when an object is too close, providing a functional prototype for learning and experimentation.

##  🧐 Program Usage

1. We declare the variables, which in this case are global variables.
   ```
   float tiempo;
   float distancia;
   ```
2. We declare the input and output pins. Each pinMode is configured for a specific function.
  ```
  pinMode(4,OUTPUT); // Trigger
  pinMode(A5,INPUT); // Echo
  pinMode(7,OUTPUT); // LED
  pinMode(8,OUTPUT); // Buzzer
  Serial.begin(9600);
  ```

3. Pin 4 will be used for the trigger. What we want is to create a pause for each trigger pulse, and that's why we're using the delayMicroseconds function. This function provides a delay in microseconds.

   ```
    digitalWrite(4,LOW);
    delayMicroseconds(20);
    digitalWrite(4,HIGH); 
    delayMicroseconds(10);
    digitalWrite(4,LOW);
   ```
   
 4. To calculate the variable "distancia", we will use the pulseIn() function to measure the time it takes for the signal to leave the sensor, bounce off the object, and return. We also need the speed at which the signal travels, and in this case, we will use the speed of sound: 0.03432 centimeters per microsecond.
    
    pulseIn(A5, HIGH) means that the timer will stop when pin A5 receives the signal that was sent out.

     We are going to divide the total distance by two because it’s the same when the signal is sent and when it returns. If you divide 0.03432 by two, you get 0.01716, and we simply multiply that by the value returned by the pulseIn() function and that value is in the variable "tiempo".

     ```
    tiempo = pulseIn(A5,HIGH);
    distancia = 0.01716 * tiempo;
    ```

5. If the variable distance has a value less than 100, it means the object is within the sensor's detectable range. Additionally, the distance variable determines how fast or slow the buzzer and LED will turn on and off. The closer the object is, the faster the buzzer and LED will blink. Conversely, the farther the object is, the slower the buzzer and LED will blink — and this is reflected in the delay used within the condition.
   
  ```
   if(distancia<100)
  {
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    delay(distancia*10);
                 
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    delay(distancia*10);
      
  }
```
## 📹 Demo Video

[![Arduino Reverse Alarm System](https://img.youtube.com/vi/ID_DEL_VIDEO/maxresdefault.jpg)](https://www.youtube.com/watch?v=uwe0xuG34Eg)

