#define outMin 0 // Lowest output pin
#define outMax 13  // Highest output pin
#define maxDelay 100 // Maxium Delay for the lights
#define noLights 2   // No of lights 
int step;            // Global variable
void setup()
{ 
 step = outMax;
for(int i=outMin; i<=outMax; i++)
{
  pinMode(i, OUTPUT);
}
}

void loop()
{
  
  for(int i=outMin; i<=step-noLights;i++){
    for(int l=0; l<noLights;l++){
      digitalWrite(i+l,1);
  }
    delay(maxDelay);
    for(int l=0; l<noLights;l++){
      digitalWrite(i+l,0);
  }
       
    
  }
  if(step >= 1)
  {
    hold(step);
  }
  else
  {
    delay(maxDelay+400);
    for(int j =outMin; j<=outMax;j++)
    {
      digitalWrite(j,0);
    }    step = outMax;
  }
}

void hold(int p)
{
  for(int k=0; k<noLights ; k++){
    digitalWrite(p-k,1);
  }
  step-=noLights; 
}
