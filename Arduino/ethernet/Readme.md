### pin
Ethernet Shield use 
* **pin 10, 11, 12, 13** to connect
* **pin 4** for sd card
* we cannot use them for general IO

<br>
<br>

```
#include<SPI.h>
#include<Ethernet.h>

int led = 8;
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
EthernetServer server(80);
IPAddress ip(192, 168, 0, 20);

String readString;

void setup() {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    Ethernet.begin(mac, ip);
    server.begin();

    Serial.print("Server is at ");
    Serial.println(Ethernet.localIP());
}

void loop() {
    // listening from incoming client
    EthernetClient client = server.available();

    if(client)
    {
        Serial.println("New client");
        while(client.connected())
        {
            if(client.available())
            {
                char c = client.read();
                //Serial.print(c);

                if(readString.length() < 100)
                {
                  readString += c;
                }

                // receive a complete request
                // reset webpage and work
                if(c == '\n')
                {
                    Serial.print(readString);
                    client.println("HTTP/1.1 200 OK");
                    client.println("Connection-Type: text/html");
                    client.println("Connection: close");
                    client.println("Refresh: 5");
                    client.println();
                     
                    client.println("<!DOCTYPE html>");
                    client.println("<html>");
                    client.println("<head>");
                    client.println("<title> Haleon </title>");
                    client.println("</head>");
                    
                    client.println("<body style = background-color:tomato>");
                    
                    client.println("<a href = \" btnon-on  \" > <button> Button on </button> </a>");
                    client.println("<a href = \" btnoff-off \" > <button> Button off </button> </a> ");
                    
                    client.print("<p> Analog Read A0 = ");
                    int sensor = analogRead(A0);
                    client.print(sensor);
                    client.println(" </p> <br>");

                    
                    client.println("</body>");
                    client.println("</html>");
                    
                    delay(1);
                    client.stop();

                    if(readString.indexOf("btnon") > 0)
                        digitalWrite(led, HIGH);
                    if(readString.indexOf("btnoff") > 0)
                        digitalWrite(led,LOW);

                    readString = "";
                }
            }
          
        }
    }
    

}
```
<br><br>

### refresh page

```
client.println("HTTP/1.1 200 OK");
client.println("Connection-Type: text/html");
client.println("Connection: close");
client.println("Refresh: 5");
client.println();
                     
```



