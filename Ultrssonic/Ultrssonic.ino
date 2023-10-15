
// Declaration of trigger and echo pins

int trigPin = 12;

int echoPin = 11;

 

// declaration of variables going to be used for the program

int distance1 = 0;

int distance2 = 0;

int measured_speed = 0;

long duration = 0;

int distance = 0;

 

void setup()

{

    // Setting trigger pin as OUTPUT

    pinMode(trigPin, OUTPUT);
    pinMode(8, OUTPUT);

 

    // Setting echoPin as INPUT

    pinMode(echoPin, INPUT);

 

    // Starts the serial communication at baud rate 9600

    Serial.begin(19200); 

}

 

void loop()

{

    // Measuring distance 1

    distance1 = ultrasonicRead(); // calls ultrasoninicRead()

    delay(2000);                  // gives delay of 1 second

    distance2 = ultrasonicRead(); // calls ultrasoninicRead() function below

 

    // Formula to calculate speed from distance1 and distance2

    // We are dividing it by 1, since the time interval between the two distance measurement is 1000 ms or 1 second

    measured_speed = (distance1 - distance2) / 2.0;
    Serial.print("distance1 :");
    Serial.print(distance1);  
    Serial.print("\t distance2 :");
    Serial.print(distance2); 
    Serial.print("\t Speed in cm/s :");
    Serial.println(measured_speed);
 

    // Displaying the speed value on the serial monitor
    if (measured_speed >= 100 && measured_speed <= 300){
      tone(8,257 ,500);
    }

}

 

// Function declaration to measure the distance based on the working principle of ultrasonic sensor

 

float ultrasonicRead()

{

    // Sets the trigPin on HIGH state for 10 micro seconds

    digitalWrite(trigPin, HIGH);

    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

 

    // Waits for the amount of time echoPin remains high and records the duration of the same

    duration = pulseIn(echoPin, HIGH);

    // Calculates the distance based on the speed of sound in ambient air 

    // and divide it by two since the sound traveled twice - once to the object and then back

    distance = duration * 0.034 / 2;

 

    // returning measured distance

    return distance;

}
