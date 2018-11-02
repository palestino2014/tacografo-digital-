int Analog_Eingang = A0; // X-axis-signal
int Digital_Eingang = 13; // Button
unsigned long time;
unsigned long time1 = 0;
unsigned long time2 = 0;
float vFinal = 0;
#define PI 3.14

//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup ()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  
  pinMode (Analog_Eingang, INPUT);
  pinMode (Digital_Eingang, INPUT);       
  Serial.begin (9600); // Serielle output with 9600 bps
}  

void loop ()
{
  float Analog;
  int Digital;
  unsigned long timeSegundos; 
  time = millis();  
  float deltaTempo;
  float velocidade;
  float raio= 15;
  float comprimento=2*PI*raio; 
  float comprimento4 = comprimento/4;
  
  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(0, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("Rodabras Rodas");
  lcd.setCursor(0, 1);
  lcd.print("V = ");
  lcd.print(vFinal);
  lcd.print(" CM/S"); 
  
  // Current value will be read and converted to the voltage
  Analog = analogRead (Analog_Eingang) * (5.0 / 1023.0); 
  Digital = digitalRead (Digital_Eingang);
  timeSegundos = time/1000;
    
  // and outputted here
  Serial.print("Tempo 1=> ");
  Serial.println (timeSegundos);
  Serial.print ("Tempo 2 => ");      
  Serial.println(time2/1000); 
  Serial.println("==============="); 
  Serial.println(vFinal);
  
  while(Digital==0)
  {
      time2 = millis();
      Serial.print ("Tempo 1=> ");
      Serial.println (timeSegundos);
      Serial.print ("Tempo 2 => ");      
      Serial.println(time2/1000);       
      Analog = analogRead(Analog_Eingang)*(5.0/1023.0); 
      Digital = digitalRead(Digital_Eingang);
      Serial.println(vFinal); 
      delay(200);           
  }  
  Serial.print("Tempo 1=> ");
  Serial.println(timeSegundos);
  Serial.print("Tempo 2 => ");      
  Serial.println(time2/1000);
  Serial.println("#################");
  if (time < time2)  
       {
          deltaTempo = ((time2-time)/1000);
          Serial.println("Variacao do Tempo (S)");
          Serial.println(deltaTempo);
          Serial.println("Velocidade (cm/s)");
          vFinal = ((comprimento4)/(deltaTempo+3));
          Serial.println(vFinal); 
               
          lcd.clear();
          //Posiciona o cursor na coluna 3, linha 0;
          lcd.setCursor(0, 0);
          //Envia o texto entre aspas para o LCD
          lcd.print("VarT = ");
          lcd.print(deltaTempo+3);
          lcd.print(" S");
          lcd.setCursor(0, 1);
          lcd.print("Calculando..."); 
          delay(3000);
        }  
           delay(200); 
 }   
 
