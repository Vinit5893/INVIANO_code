// -------------------------------------------------------------------------- //
// INVIANO - Invisible Piano - Musical Instrument for Kids (Age : 2+ to 12-). //
// -------------------------------------------------------------------------- //

// ---------------------------------------------------------------- //
// Define the different frequencies that will be used in "INVIANO". //
// ---------------------------------------------------------------- //
#define c4 261.63
#define d 293.67
#define e 329.63
#define f 349.23
#define g 392.0
#define a 440.0
#define b 493.88
#define c5 523.25

// --------------------------------------------------------------- //
// -------------------------- Play Tone -------------------------- //
// --------------------------------------------------------------- //

// Predefined set of tones
int i;
int speakerPin = 4;
const float marry[] = {e, d, c4, d, e, e, e, d, d, d, e, g, g, e, d, c4, d, e, e, e, e, d, d, e, d, c4};

// -------- Another melody -------- //
// const float melody[] = {c4, d, e, f, g, a, b, c5};
// const int noteDurations[] = {4, 4, 4, 4, 4, 4, 4, 4};

// const int quarterNote = 1000; // 1 second for a quarter note
// const int halfNote = 2 * quarterNote; // 2 seconds for a half note
//
//// Playtone Function //
// void playTone(float frequency, long duration) {
//   // Calculate the period of the note (in microseconds)
//   float period = 1000000.0 / frequency;
//
//   // Calculate the delay half the period
//   int delayTime = period / 2.0;
//
//   // Loop for the desired duration
//   for (long i = 0; i < duration * 1000L; i += period) {
//     digitalWrite(speakerPin, HIGH);
//     delayMicroseconds(delayTime);
//     digitalWrite(speakerPin, LOW);
//     delayMicroseconds(delayTime);
//   }
// }

// ----------------------------------------------------------------- //
// --------- Distance Declaration for 8 different notes ------------ //
// ----- based on the distance captured from Ultrasonic sensor, ---- //
// --- these variables will be updated with Integer type output. --- //
// ----------------------------------------------------------------- //
int Sa1 = 0;
int Re = 0;
int Ga = 0;
int Ma = 0;
int Pa = 0;
int Dha = 0;
int Ni = 0;
int Sa2 = 0;
int mo = 0;
int ch = 0;

// ----------------------------------------------------------------------------------------- //
// Declaration of Intermediate boolean variables of different note for ON/OFF functionality. //
// ----------------------------------------------------------------------------------------- //
bool on1 = 0;
bool on2 = 0;
bool on3 = 0;
bool on4 = 0;
bool on5 = 0;
bool on6 = 0;
bool on7 = 0;
bool on8 = 0;

// ------------------------------------------------- //
// External dependent variables for selecting modes. //
// ------------------------------------------------- //
bool power = 0;
bool play = 0;
bool songmode = 0;
bool song0 = 0;
bool song1 = 0;
bool song2 = 0;

// ---------------------------------------------------------- //
// Function for Calculating Distance using Ultrasonic sensor. //
// ---------------------------------------------------------- //
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

// ------------------------------------------------ //
// Declaration of the modes (INPUT/OUTPUT) of pins. //
// ------------------------------------------------ //
void setup()
{
  Serial.begin(9600);

  pinMode(speakerPin, OUTPUT); // Set the speakerPin as an OUTPUT
  pinMode(13, OUTPUT);
  pinMode(13, INPUT);
  pinMode(12, OUTPUT);
  pinMode(12, INPUT);
  pinMode(11, OUTPUT);
  pinMode(11, INPUT);
  pinMode(10, OUTPUT);
  pinMode(10, INPUT);
  pinMode(9, OUTPUT);
  pinMode(9, INPUT);
  pinMode(8, OUTPUT);
  pinMode(8, INPUT);
  pinMode(7, OUTPUT);
  pinMode(7, INPUT);
  pinMode(6, OUTPUT);
  pinMode(6, INPUT);

  pinMode(5, OUTPUT);
  pinMode(5, INPUT); // modes
}

// ---------------------------------------------------------------------- //
// Main loop - program to Activale/Play INVIANO along with prebuilt tones //
// ---------------------------------------------------------------------- //
void loop()
{

  // ------ Fetching the Ultrasonic Function and getting the distance values ------ //
  Sa1 = USDistCm(13, 13);
  Re = USDistCm(12, 12);
  Ga = USDistCm(11, 11);
  Ma = USDistCm(10, 10);
  Pa = USDistCm(9, 9);
  Dha = USDistCm(8, 8);
  Ni = USDistCm(7, 7);
  Sa2 = USDistCm(6, 6);

  mo = USDistCm(5, 5); // mode selection

  delay(100);

  // ----------- switch ON (Hover on each sensor to turn ON intermediate variables with distance limitations) ----------- //
  if (Sa1 > 5 && Sa1 < 20)
  {
    on1 = 1;
  }
  if (Re > 5 && Re < 20)
  {
    on2 = 1;
  }
  if (Ga > 5 && Ga < 20)
  {
    on3 = 1;
  }
  if (Ma > 5 && Ma < 20)
  {
    on4 = 1;
  }
  if (Pa > 5 && Pa < 20)
  {
    on5 = 1;
  }
  if (Dha > 5 && Dha < 20)
  {
    on6 = 1;
  }
  if (Ni > 5 && Ni < 20)
  {
    on7 = 1;
  }
  if (Sa2 > 5 && Sa2 < 20)
  {
    on8 = 1;
  }

  // -------- Verification Done --------//
  //  Serial.print(Sa1);
  //  Serial.println("  Sa1  ");
  //  Serial.print(on1);
  //  Serial.println("  On1  ");
  //  Serial.println(" ");
  //
  //  Serial.print(Re);
  //  Serial.println("  Re  ");
  //  Serial.print(on2);
  //  Serial.println("  On2  ");
  //  Serial.println(" ");

  // ----------- switch ON Pattern (Wave on each sensor to turn ON INVIANO) ------------ //
  if (on1 && on2 && on3 && on4 && on5 && on6 && on7 && on8)
  {
    power = 1;
  }
  else
  {
    power = 0;
  }

  // ---------------------------- power on mode ----------------------------- //
  if (power == 1)
  {
    if ((mo < 25 && mo > 0) || songmode == 1)
    {
      songmode = 1;
      play = 0;

      if ((ch < 25 && ch > 0)) // song mode - acting as Latch to remember the mode selected. //
      {
        songs(1, 0, 0);
      }
      else if (ch < 35 && ch > 27)
      {
        songs(0, 1, 0);
      }
      else if ((ch < 45 && ch > 37))
      {
        songs(0, 0, 1);
      }
    }


//---------------------------------------playmode---------------------------------------//

    else if ((mo < 50 && mo > 25) || play == 1) // play mode - acting as Latch to remember the mode selected. //
    {
      play = 1;
      songmode = 0;

      // Tone generation based on the distance of different sensors and their corresponding assigned frequencies //
      if (Sa1 > 2 && Sa1 < 30)
      {
        tone(speakerPin, c4, 100);
      }

      if (Re > 2 && Re < 30)
      {
        tone(speakerPin, d, 100);
      }

      if (Ga > 2 && Ga < 30)
      {
        tone(speakerPin, e, 100);
      }

      if (Ma > 2 && Ma < 30)
      {
        tone(speakerPin, f, 100);
      }

      if (Pa > 2 && Pa < 30)
      {
        tone(speakerPin, g, 100);
      }

      if (Dha > 2 && Dha < 30)
      {
        tone(speakerPin, a, 100);
      }

      if (Ni > 2 && Ni < 30)
      {
        tone(speakerPin, b, 100);
      }

      if (Sa2 > 2 && Sa2 < 30)
      {
        tone(speakerPin, c5, 100);
      }
    }
  }
}

void songs(song0, song1, song2)
{
  if (song0 == 1) // song mode - acting as Latch to remember the mode selected. //
  {
    song0 = 1;
    song1 = 0;
    song2 = 0;
    play = 0;

    for (i = 0; i <= 26; i++)
    {
      tone(speakerPin, marry[i], 1000);
    }
  }
  else if (song1 == 1)
  {
    song0 = 0;
    song1 = 1;
    song2 = 0;
    play = 0;

    for (i = 0; i <= 26; i++)
    {
      tone(speakerPin, marry[i], 1000);
    }
  }
  else if (song2 == 1)
  {
    song0 = 0;
    song1 = 0;
    song2 = 1;
    play = 0;

    for (i = 0; i <= 26; i++)
    {
      tone(speakerPin, marry[i], 1000);
    }
  }
}

unsigned long previousTime = micros(); // or millis()
long timeInterval = 800;

void setup() { }

void loop() {
  unsigned long currentTime = micros(); // or millis()

  // Enter the If block only if at least 800 micros (or millis) has passed since last time
  if (currentTime - previousTime > timeInterval) {
    // do action
    previousTime = currentTime;
  }
}

if (dist <= 50 || dist <= curr_dist){

  store the curr_dist = dist;
  if (dist > curr_dist){

  }
}












// Variables to store the distance and speed
float distance = 0.0;
float speed = 0.0;
float duration =0.0;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Set the trigger pin as an output and the echo pin as an input
  pinMode(7, OUTPUT);
  pinMode(7, INPUT);
  
  // Set the trigger pin to low initially
  digitalWrite(7, LOW);
}

void loop() {
  
  digitalWrite(7, LOW);
  delayMicroseconds(2);
  digitalWrite(7, HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);

  // Reads the echo pin, and returns the sound wave travel time in microseconds. //
  duration = pulseIn(7, HIGH);
  
  distance = (0.01723 * duration); // in cm
  
  // Calculate the speed (in cm/s)
  speed = distance / (duration / 1000000.0); // Convert duration to seconds
  
  // Print the distance and speed to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm\tSpeed: ");
  Serial.print(speed);
  Serial.println(" cm/s");
  
  // Delay before the next measurement
  delay(1000); // Adjust this delay as needed
}


void maxdist()
{
  if (ultrasonicdist == 0  || ultrasonicdist >= 1000){
    //no obstacle;
    if (ultrasonicdist < 50);
    prev_dist = ultrasonicdist;
      if (ultrasonicdist < prev_dist) {
        valmin1 = ultrasonicdist;


        
      }

  }
  {


  }
}


