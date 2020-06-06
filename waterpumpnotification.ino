
int total_used = 0;




void setup() 
{
  Particle.subscribe("jonathan_button_press_1321", myHandler);

}

void loop() 
{

    

}


void myHandler(const char *event, const char *data)
{


  if (strcmp(data,"relay-off")==0) 
  {
    
    Particle.publish("jonathan_pump_notification_1123", "off");
    
  }
  else if (strcmp(data,"relay-on")==0) 
  { 
    total_used += 1;
    Particle.publish("jonathan_pump_notification_1123", "on");
  }
  
  
  if ( total_used > 25)
  {
        Particle.publish("jonathan_pump_notification_1123", "check");
  }
}