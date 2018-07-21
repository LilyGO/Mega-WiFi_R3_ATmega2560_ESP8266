 void setup()
{
  Serial3.begin(115200);
  pinMode(13,OUTPUT);
  delay(500);
  Serial3.println("AT+CIPMUX=1");
  delay(2000);
  Serial3.println("AT+CIPSERVER=1,5000");
  delay(2000);
  Serial3.println("AT+CIPSTO=3600");
  delay(2000);
}

void loop()
{
   while(Serial3.available())
  {
    char Rdata;
    Rdata=Serial3.read();
    if(Rdata=='A'|Rdata=='a')
    {
      digitalWrite(13,HIGH);
      delay(50);
    }
    else if(Rdata=='B'|Rdata=='b')
    {
      digitalWrite(13,LOW);
      delay(10);
      digitalWrite(13,HIGH);
      delay(10);
      digitalWrite(13,LOW);
    }
    else
    {
      digitalWrite(13,LOW);
    }
  }

}