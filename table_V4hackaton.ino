#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define TRIG_PIN 3
#define ECHO_PIN 2
#define WATER_SENSOR_PIN A7
#define DISTANCE_ERR 0
#define DISTANCE_BOUND 20
#define WET_BOUND 150
#define TABLE_WET 11
#define TABLE_BUSY 22
#define TABLE_FREE 33

double distance;
double duration = 0;
double last_distance = 0;
int wet=0; //water sensor 

int msg[1];
RF24 radio(9,10);
const uint64_t pipe = 0x544D52687CLL;

void setup()
{
    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(WATER_SENSOR_PIN, INPUT);    
    
    radio.begin();
    radio.openWritingPipe(pipe);
    pinMode(13, OUTPUT);//nrf
    pinMode(7, INPUT);//nrf
    radio.setChannel(1);
    radio.setCRCLength(RF24_CRC_16);
    radio.setPALevel(0);
    radio.setDataRate(RF24_250KBPS); 
    Serial.println("P_variant= " +(String)radio.isPVariant());//1
    Serial.println("DataRate= " +(String)radio.getDataRate());//2
    Serial.println("PALevel= " +(String)radio.getPALevel());//0
    Serial.println("start");
}
 
void loop()
{
    wet = analogRead(WATER_SENSOR_PIN);
    
    digitalWrite(TRIG_PIN, HIGH); // impuls 10 us TRIG 
    delayMicroseconds(10);        
    digitalWrite(TRIG_PIN, LOW);  
    
    duration = pulseIn(ECHO_PIN, HIGH, 15000); //ECHO pulse time [us]
    distance = duration/58;  //  calc to -> [cm]
    
    Serial.println((String)distance+"    "+(String)wet); //debug :)
    
    if (distance == DISTANCE_ERR)
    {
        distance = last_distance;
    }
    
    if(wet > WET_BOUND)
    {
        msg[0] = TABLE_WET;
        radio.write(msg, 1);
        Serial.println("Table is wet!!!");
    }
    else if(distance < DISTANCE_BOUND)
    {
        msg[0] = TABLE_BUSY;
        radio.write(msg, 1);
        Serial.println("Table is  busy!!!");
    }
    else if(distance > DISTANCE_BOUND)
    {
        msg[0] = TABLE_FREE;
        radio.write(msg, 1);
        Serial.println("Table is  free");
    }
    last_distance = distance;
}
