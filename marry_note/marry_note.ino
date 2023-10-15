#define c4 261.63
#define d 293.67
#define e 329.63
#define f 349.23
#define g 392.0
#define a 440.0
#define b 493.88
#define c5 523.25
int i;

const float marry[] = {e, d, c4, d, e, e, e, d, d, d, e, g, g, e, d, c4, d, e, e, e, e, d, d, e, d, c4};
const int speaker = 10;
void setup() {
  // put your setup code here, to run once:
      pinMode(speaker, OUTPUT);

}

void loop() {
for (i = 0; i <= 26; i++)
    {
      tone(speaker, 2*marry[i], 500);
      delay (500);
      noTone(speaker);
      delay (10);
   
    }

}
