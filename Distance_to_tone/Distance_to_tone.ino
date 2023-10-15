const int triggerPin = 12;
const int echoPin = 11;
const int speaker = 10;
int distance;

int USDistCm(int triggerPin, int echoPin)
{
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    // Reads the echo pin, and returns the sound wave travel time in microseconds. //
    return (0.01723 * pulseIn(echoPin, HIGH)); // in cm
}

void setup()
{
    Serial.begin(9600);

    pinMode(triggerPin, OUTPUT); // Set the speakerPin as an OUTPUT
    pinMode(echoPin, INPUT);
    pinMode(speaker, OUTPUT);

}

void loop()
{

    distance = USDistCm(triggerPin, echoPin);


    Serial.println(distance);

    if (distance <= 10 && distance > 5)
    {
        tone(speaker, 600, 1000);
    }
    else if (distance <= 20 && distance > 10)
    {
        tone(speaker, 450, 1000);
    }
    else if (distance <= 30 && distance > 20)
    {
        tone(speaker, 400, 1000);
    }
    else if (distance <= 40 && distance > 30)
    {
        tone(speaker, 350, 1000);
    }
    else if (distance <= 50 && distance > 40)
    {
        tone(speaker, 300, 1000);
    }
    else if (distance <= 60 && distance > 50)
    {
        tone(speaker, 250, 1000);
    }
    else if (distance <= 70 && distance > 60)
    {
        tone(speaker, 200, 1000);
    }
    else if (distance <= 80 && distance > 70)
    {
        tone(speaker, 150, 1000);
    }
    else if (distance <= 90 && distance > 80)
    {
        tone(speaker, 50, 1000);
    }
    else
    {
        noTone(speaker);
    }

    delay(1000);
}
