const int LED = 13;
const int LONG = 3000;
const int SHORT = 500;

void setup()
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}
void on(int time)
{
    digitalWrite(LED, HIGH);
    delay(time);
    digitalWrite(LED, LOW);
    delay(SHORT);
}
void harfS()
{
    Serial.print("s ");
    for (int i = 1; i <= 3; i++)
    {
        on(SHORT);
    }
    delay(LONG);
}
void harfO()
{
    Serial.print("o ");
    for (int i = 1; i <= 3; i++)
    {
        on(LONG);
    }
    delay(LONG);
}
void loop()
{
    harfS();
    harfO();
    harfS();
    Serial.println();
    delay(1000);
}