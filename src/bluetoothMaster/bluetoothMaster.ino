#define DEBUG true


void setup() {
    
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(38400);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  sendData("AT+RST\r\n", 2000, false); // resetare modul
  sendData("AT+CWMODE=2\r\n", 1000, false); // configurare ca
  //access point
  sendData("AT+CIFSR\r\n", 1000, DEBUG); // cite?te adresa IP
  sendData("AT+CWSAP?\r\n", 2000, DEBUG); // cite?te informa?ia 
  //SSID (nume re?ea)
  sendData("AT+CIPMUX=1\r\n", 1000, false); // configurare
  //conexiuni multiple
  sendData("AT+CIPSERVER=1,80\r\n", 1000, false); // pornire
  //server pe port 80
}
void loop() {
  if (Serial1.available()) {
    digitalWrite(12,0);
    digitalWrite(13,0);
      if (Serial1.find("+IPD,")) {
        delay(500);
        int connectionId = Serial1.read() - 48; // functia
        //read() returneazã valori zecimale ASCII
        // si caracterul ‘0’ are codul ASCII 48
        String webpage = "<h1>Control Buttons for Robots</h1><a href=\"/l0\"><button>UP</button></a>";
        String cipSend = "AT+CIPSEND=";
        cipSend += connectionId;
        cipSend += ",";
        webpage += "<a href=\"/l1\"><button>DOWN</button></a>";
        webpage += "<a href=\"/l2\"><button>LEFT</button></a>";
        webpage += "<a href=\"/l3\"><button>RIGHT</button></a>";
        cipSend += webpage.length();
        cipSend += "\r\n";
        sendData(cipSend, 100, DEBUG);
        sendData(webpage, 150, DEBUG);

        String closeCommand = "AT+CIPCLOSE=";
        closeCommand += connectionId; //se adaugã
        //identificatorul conexiunii
        closeCommand += "\r\n";
        sendData(closeCommand, 300, DEBUG);
      }
   }
   digitalWrite(11,LOW);
}

String sendData(String command, const int timeout, boolean debug)
{
  String response = "";
  Serial1.print(command); // trimite comanda la esp8266
  long int time = millis();
  while ((time + timeout) > millis()) {
    while (Serial1.available()) {
      char c = Serial1.read(); // cite?te caracter urmãtor
      response += c;
    }
  }
  if (response.indexOf("/l2") != -1) {
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    digitalWrite(11,HIGH);
    Serial2.write('0');
    //down
  }
  if (response.indexOf("/l3") != -1) {
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    Serial2.write('1');
    //up
  }
  if (response.indexOf("/l0") != -1) {
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(11,HIGH);
    Serial2.write('2');
    //right
  }
  if (response.indexOf("/l1") != -1) {
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    digitalWrite(11,HIGH);
    Serial2.write('3');
    //left
  }
  if (debug) {
    Serial.print(response);
  }
   return response;
}
