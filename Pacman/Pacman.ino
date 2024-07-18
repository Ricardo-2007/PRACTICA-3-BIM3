/*
 
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB4AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Matrix led pacman
   Dev: Ricardo Andres Rodriguez de León-2023100
   Fecha: 24 de mayo
*/
#include <LedControl.h> 

#define din_matrix 3 
#define cs_matrix  2 
#define clk_matrix 4 
#define ch_A0      A0

int valor = 0;
int tiempo_espera;

LedControl PacmanMatrix = LedControl(din_matrix, clk_matrix, cs_matrix,1);

// variables
byte pacman_boca_abierta[8] = {
  B00111100,
  B01000010,
  B10010100,
  B10001000,
  B10001000,
  B10000100,
  B01000010,
  B00111100
};

byte pacman_boca_cerrada[8] = { 
  B00111100,
  B01000010,
  B10000001,
  B10001111,
  B10001111,
  B10000001,
  B01000010,
  B00111100

};

void setup(){
 Serial.begin(9600);
 PacmanMatrix.shutdown(0, false); 
 PacmanMatrix.setIntensity(0, 15);
 PacmanMatrix.clearDisplay(0);
 Serial.println("uso de la matriz led");
 
  
}

void loop(){
 valor = analogRead(ch_A0);   
 tiempo_espera = map(valor,0,1023,50,1500);
 Pacmanabierto();
 delay(tiempo_espera);
 Pacmancerrado();
 delay(tiempo_espera);
 

}


void Pacmanabierto(){
for(int i=0; i<8; i++)
 {
 PacmanMatrix.setRow(0,i,pacman_boca_abierta[i]);
 }  
}


void Pacmancerrado(){
for(int i=0; i<8; i++)
 {
 PacmanMatrix.setRow(0,i,pacman_boca_cerrada[i]);
 }  
}
