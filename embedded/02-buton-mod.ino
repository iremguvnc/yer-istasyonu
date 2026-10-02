const int LED = 13;
const int BUTON = 2;
int mod = 0;
int oncekiButon = HIGH;

unsigned long sonBasma = 0;
unsigned long sonYakma = 0;
bool ledAcik = false;

void setup()
{
    pinMode(LED, OUTPUT);
    pinMode(BUTON, INPUT_PULLUP);
    Serial.begin(9600);
}
void loop()
{
    int buton = digitalRead(BUTON);
    if (oncekiButon == HIGH && buton == LOW && millis() - sonBasma > 50)
    {
        mod = (mod + 1) % 3;
        sonBasma = millis();
        Serial.print("mod: ");
        Serial.println(mod);
    }
    oncekiButon = buton;
    if (mod == 0)
    {
        digitalWrite(LED, LOW);
    }
    else if (mod == 1)
    {
        digitalWrite(LED, HIGH);
    }
    else
    {
        if (millis() - sonYakma >= 300)
        {
            sonYakma = millis();
            ledAcik = !ledAcik;
            digitalWrite(LED, ledAcik);
        }
    }
}