const int SENSOR = A0;
const int LED = 13;
const float ESIK = 30.0;
const int N = 10;
float olcumler[N];
int indeks = 0;
bool doldu = false;

void setup()
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}
float sicaklikOku()
{
    int ham = analogRead(SENSOR);
    float volt = ham * 5.0 / 1023.0;
    return (volt - 0.5) * 100.0;
}
void loop()
{
    olcumler[indeks] = sicaklikOku();
    indeks = (indeks + 1) % N;
    if (indeks == 0)
        doldu = true;

    int adet = doldu ? N : indeks;
    float toplam = 0;
    for (int i = 0; i < adet; i++)
    {
        toplam += olcumler[i];
    }
    float ortalama = toplam / adet;

    if (ortalama > ESIK)
    {
        digitalWrite(LED, HIGH);
    }
    else
    {
        digitalWrite(LED, LOW);
    }
    Serial.print("{\"sıcaklik\":");
    Serial.print(ortalama, 1);
    Serial.print(",\"led\":");
    Serial.print(ortalama > ESIK ? "yandi" : "sondu");
    Serial.println("}");
    delay(200);
}