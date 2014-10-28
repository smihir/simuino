/*  Servuino is a Arduino Simulator Engine
    Copyright (C) 2012  Benny Saxen

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>. 
*/



//====================================
char *int2bin(int num, int pad)
// Example: printf("%s\n", int2bin(i, 8));
//====================================
{
  char *str = (char*)malloc(sizeof(char) * (pad+1));
  if (str) 
    {
      str[pad]='\0';
      while (--pad>=0) 
	{
	  str[pad] = num & 1 ? '1' : '0';
	  num >>= 1;
	}
    } 
  else 
    {
      printf("int2bin:No string\n");
    }
  return str;
}

//====================================
int setRange(int board)
//====================================
{
  max_steps = SCEN_MAX;
  max_loops = MAX_LOOPS;

  max_digVal = 1;
  min_digVal = 0;
  
  max_anaVal = 1023;
  min_anaVal = 0;

  max_pwm    = 255;
  min_pwm    = 0;

  if(board == UNO)
    {
      max_totPin = MAX_PIN_DIGITAL_UNO + MAX_PIN_ANALOG_UNO;

      max_digPin = MAX_PIN_DIGITAL_UNO;
      min_digPin = 0;

      max_anaPin = MAX_PIN_ANALOG_UNO;
      min_anaPin = 0;

      max_irPin = MAX_PIN_IR_UNO;
      min_irPin = 0;
    }
  if(board == MEGA)
    {
      max_totPin = MAX_PIN_DIGITAL_MEGA + MAX_PIN_ANALOG_MEGA;

      max_digPin = MAX_PIN_DIGITAL_MEGA;
      min_digPin = 0;

      max_anaPin = MAX_PIN_ANALOG_MEGA;
      min_anaPin = 0;

      max_irPin = MAX_PIN_IR_MEGA;
      min_irPin = 0;
    }

  inrpt[0] = IR0;
  inrpt[1] = IR1;
  inrpt[2] = IR2;
  inrpt[3] = IR3;
  inrpt[4] = IR4;
  inrpt[5] = IR5;

  return(max_totPin);
}
//====================================
int checkRange(int mode,const char check[],int value)
//====================================
{
  int i,j,minx,maxx,res;
  char temp[120],message[180];

  if(mode==HEAL)
    res = value;
  else
    res = S_OK;


  // PWM pins
  if(strstr(check,"pwmpin") != NULL)
    {
      strcpy(message,"Allowed PWM Pins: 3,5,6,9,10,11");
      if(g_boardType == UNO)
	{
	  if(value != 3 && value != 5 && value != 6 && value != 9 && value != 10 && value != 11) 
	    {
	      sprintf(temp,"%s - %d",message,value);
	      errorLog(temp,value);
	      return(S_NOK);
	    }
	  else
	    return(S_OK);
	}
      if(g_boardType == MEGA)
	{
	  if(value < 0 || value > 13) 
	    {
	      sprintf(temp,"%s - %d",message,value);
	      errorLog(temp,value);
	      return(S_NOK);
	    }
	  else
	    return(S_OK);
	}

    }

  // set ranges
  if(strstr(check,"digval") != NULL)
    {
      strcpy(message,"Digital Value");
      maxx = max_digVal;
      minx = min_digVal;
    }
  else if(strstr(check,"anaval") != NULL)
    {
      strcpy(message,"Analog Value");
      maxx = max_anaVal;
      minx = min_anaVal;
    }
  else if(strstr(check,"pwmval") != NULL)
    {
      strcpy(message,"PWM Value");
      maxx = max_pwm;
      minx = min_pwm;
    }
  else if(strstr(check,"digpin") != NULL)
    {
      strcpy(message,"Digital Pin");
      maxx = max_digPin;
      minx = min_digPin;
    }
  else if(strstr(check,"anapin") != NULL)
    {
      strcpy(message,"Analog Pin");
      maxx = max_anaPin;
      minx = min_anaPin;
    }
  else if(strstr(check,"step") != NULL)
    {
      strcpy(message,"Step out of range");
      maxx = max_steps;
      minx = 1;
    }
  else if(strstr(check,"loop") != NULL)
    {
      strcpy(message,"Loop out of range");
      maxx = max_loops;
      minx = 0;
    }
  else if(strstr(check,"interrupt") != NULL)
    {
      strcpy(message,"Interrupt out of range");
      maxx = max_irPin;
      minx = min_irPin;
    }
  else
    {
      strcpy(message,"Undefined Range Control");
      maxx = 0;
      minx = 0;
    }

  // evaluate
  if(maxx == 0 && minx == 0)
    {
      sprintf(temp,"Unknown:%s",message);
      errorLog(temp,value);
      res = S_NOK;
    }
  else if(value > maxx)
    {
      sprintf(temp,"%s %d >",message,value);
      errorLog(temp,maxx);
      if(mode==HEAL)
	res = maxx;
      else
	res = S_NOK;
    }
  else if(value < minx)
    {
      sprintf(temp,"%s %d <",message,value);
      errorLog(temp,minx);
      if(mode==HEAL)
	res = minx;
      else 
	res = S_NOK;
    }

  return(res);
}


// End of file
