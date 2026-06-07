char vib_read;
int vib_pin = 7;

void init_vib()
{
  pinMode(vib_pin,INPUT);
}

bool read_vibration()
{
  vib_read = digitalRead(vib_pin);
  if(vib_read == 1)
  {
    return true;
  }
  else
  {
    Serial.println("No Vibration");
    return false;
  }
}

