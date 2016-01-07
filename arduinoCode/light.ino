int pin = 2;

void setup() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    Serial.begin(9600);
    while (!Serial.available()) {
    }
}

int input;

void loop() {
    input = Serial.read();
    if (input==49) {
        digitalWrite(pin, HIGH);
        delay(1000);
        digitalWrite(pin, LOW);
        delay(1000);
    }
}
