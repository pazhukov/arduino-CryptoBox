#include <QuadDisplay2.h>

QuadDisplay qd(9);

float btc_price;
float eth_price;

bool btc_up;
bool eth_up;

void setup()
{
  qd.begin();
  
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);

  btc_price = 0;
  eth_price = 0;
  
  btc_up = false;
  eth_up = false;

  Serial.begin(9600);  
}

void loop()
{  
   
  if (Serial.available() > 0) {
      
    String a = Serial.readString();

    while(a.indexOf("|") != -1) {
      if(a.indexOf("|") > -1) {
        String new_a = a.substring(0, a.indexOf("|"));
        a.replace(new_a + "|", "");       
        if (new_a.indexOf("BTC") != -1) {     
          new_a.replace("BTC", ""); 
          float price = new_a.toFloat();
          if(price >= btc_price) {
            btc_up = true;
          } else {
            btc_up = false;
          }
          btc_price = price;
        } else if (new_a.indexOf("ETH") != -1) {
          new_a.replace("ETH", "");   
          float price = new_a.toFloat();
          if(price >= eth_price) {
            eth_up = true;
          } else {
            eth_up = false;
          }
          eth_price = price;
        }           
      }      
    }
  }

  digitalWrite(7, LOW);
  digitalWrite(6, LOW);  

  if(btc_price > 0) {
    qd.displayDigits(QD_b, QD_t, QD_c, QD_NONE); 
    delay(1000);
    if (btc_up == true) {
      led_up();
    } else {
      led_down();
    }    
    qd.displayFloat(btc_price, 0); 
    delay(2000);
  }

  digitalWrite(7, LOW);
  digitalWrite(6, LOW);    
  
  if(eth_price > 0) {
    qd.displayDigits(QD_E, QD_t, QD_h, QD_NONE); 
    delay(1000);
    if (eth_up == true) {
      led_up();
    } else {
      led_down();
    }     
    qd.displayFloat(eth_price, 1); 
    delay(2000);    
  }
  

}

void led_up() {
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW); 
}

void led_down() {
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);   
}
