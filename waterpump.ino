
int relay = D13;


void setup() 
{

  pinMode(relay,OUTPUT); 
  digitalWrite(relay,HIGH);
  
  Particle.subscribe("jonathan_button_press_1321", myHandler);

}


void loop() 
{

}


void myHandler(const char *event, const char *data)
{

    
  if (strcmp(data,"relay-off")==0) 
  {
    digitalWrite(relay,HIGH);

  }
  else if (strcmp(data,"relay-on")==0) 
  { 

    digitalWrite(relay,LOW);

  }
  
}