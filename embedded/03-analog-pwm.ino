const int LED = 9;
const int LDR = A1;

void setup()
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}
void loop()
{
    int deger = analogRead(LDR);
    int parlaklik = map(deger, 0, 1023, 255, 0);
    analogWrite(LED, parlaklik);
    Serial.print("Isik: ");
    Serial.println(LDR);
    Serial.print("Parlaklik: ");
    Serial.println(parlaklik);
}