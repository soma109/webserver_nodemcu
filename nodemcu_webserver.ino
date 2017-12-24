#include <ESP8266WiFi.h>

 

    const char* ssid = "IOTPROJECT";

    const char* password = "987654321";

 

    String readStrings = "";

 

    int pin1 = D0;

    int pin2 = D1;

    int pin3 = D2;

    int pin4 = D3;

 

    WiFiServer server(80);

 

    void setup() {

      Serial.begin(115200);

      delay(10);

   

      pinMode(pin1,OUTPUT);

      pinMode(pin2,OUTPUT);

      pinMode(pin3,OUTPUT);

      pinMode(pin4,OUTPUT);

   

      // Connect to WiFi network

      Serial.println();

      Serial.println();

      Serial.print("Connecting to ");

      Serial.println(ssid);

   

      WiFi.begin(ssid, password);

   

      while (WiFi.status() != WL_CONNECTED) {

        delay(500);

        Serial.print(".");

      }

      Serial.println("");

      Serial.println("WiFi connected");

   

      // Start the server

      server.begin(); //

      Serial.println("Server started");

 

      // Print the IP address

      Serial.println(WiFi.localIP());

 

    }

 

    void loop() {

      // put your main code here, to run repeatedly:

      WiFiClient client = server.available();

   

      if(client){

      Serial.println("Yes client");

   

        while(client.connected()){

           if(client.available()){

            char c = client.read();

         

         

           if(readStrings.length() < 100){

             readStrings += c;

           }

     

            if(c=='\n'){

                Serial.println(readStrings);

                client.print("HTTP/1.1 200 OK\r\n"); //send new page

                client.print("Content-Type: text/html\r\n\r\n");

                client.print("<!DOCTYPE HTML>\r\n");

                client.print("<HTML>\r\n");//html tag

                client.print("<HEAD>\r\n"); //

    //            client.print("<meta http-equiv='refresh' content='10'/>\r\n");

             

                client.print("<TITLE>NodeMCU Project</TITLE>\r\n");

                client.print("</HEAD>\r\n");

                client.print("<BODY>\r\n");

                client.print("<H1>NodeMCU Web Server Project</H1>\r\n");

                client.print("<hr />\r\n");

                client.print("<br />\r\n");

                client.print("<H2>Based on ESP8266 ESP8266-12E</H2>\r\n");

                client.print("<br />\r\n");

                client.print("<a href=\"/?button1on\"><font color = \"green\">LED 1 On</font></a>\r\n");

                client.print("<a href=\"/?button1off\"><font color = \"red\">LED 1 Off</font></a><br />\r\n"); 

                client.print("<br />\r\n");   

                client.print("<a href=\"/?button2on\"><font color = \"green\">LED 2 On</font></a>\r\n");

                client.print("<a href=\"/?button2off\"><font color = \"red\">LED 2 Off</font></a><br />\r\n"); 

                client.print("<br />\r\n");

                client.print("<a href=\"/?button3on\"><font color = \"green\">LED 3 On</font></a>\r\n");

                client.print("<a href=\"/?button3off\"><font color = \"red\">LED 3 Off</font></a><br />\r\n"); 

                client.print("<br />\r\n");

                client.print("<a href=\"/?button4on\"><font color = \"green\">LED 4 On</font></a>\r\n");

                client.print("<a href=\"/?button4off\"><font color = \"red\">LED 4 Off</font></a><br />\r\n"); 

                client.print("<br />\r\n");

                client.print("<br />\r\n");

                client.print("<a href=\"/?buttonallon\"><font color = \"green\">           LED ALL On           </font></a>\r\n");

                client.print("<br />\r\n");

                client.print("<br />\r\n");

                client.print("<a href=\"/?buttonalloff\"><font color = \"red\">           LED ALL off          </font></a>\r\n");

                client.print("<br />\r\n");

                client.print("</BODY>\r\n");

                client.print("</HTML>\n");// ปิด tag

             

                delay(1);

             

                client.stop();

             

             

             

                if(readStrings.indexOf("?button1on") > 0){

                  Serial.println("1 on");

                  digitalWrite(pin1,HIGH);

                }

             

                if(readStrings.indexOf("?button1off") >0){

                  Serial.println("1 off");

                  digitalWrite(pin1,LOW);

                }

             

                if(readStrings.indexOf("?button2on") >0){

                  Serial.println("2 on");

                  digitalWrite(pin2,HIGH);

                }

                if(readStrings.indexOf("?button2off")>0){

                  Serial.println("2 off");

                  digitalWrite(pin2,LOW);

                }

                if(readStrings.indexOf("?button3on")>0){

                  digitalWrite(pin3,HIGH);

                  Serial.println("3 on");

                }

                if(readStrings.indexOf("?button3off")>0){

                  digitalWrite(pin3,LOW);

                  Serial.println("3 off");

                }

                if(readStrings.indexOf("?button4on")>0){

                  digitalWrite(pin4,HIGH);

                  Serial.println("4 on");

                }

                if(readStrings.indexOf("?button4off")>0){

                  digitalWrite(pin4,LOW);

                  Serial.println("4 off");

                }

                if(readStrings.indexOf("?buttonallon")>0){

                  digitalWrite(pin1,HIGH);

                  digitalWrite(pin2,HIGH);

                  digitalWrite(pin3,HIGH);

                  digitalWrite(pin4,HIGH);

                }

                if(readStrings.indexOf("?buttonallof")>0){

                  digitalWrite(pin1,LOW);

                  digitalWrite(pin2,LOW);

                  digitalWrite(pin3,LOW);

                  digitalWrite(pin4,LOW);

                }

              readStrings = "";

            }//if(c == '\n')

           }//if(client.available())

          }//while(client.connected())

        }//if(client)

      }//void loop()



