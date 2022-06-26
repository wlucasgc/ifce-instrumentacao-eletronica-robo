//=======================================================================================================================
//BIBLIOTECAS
//=======================================================================================================================

#include <Servo.h>
#include <SoftwareSerial.h>

#include "L298N.h"
//#include "MyServo.h"

//=======================================================================================================================
//DEFINIÇÕES
//=======================================================================================================================

//O modo de comunicação determina por qual meio serão recebidos os comandos (0: Modo Serial | 1: Modo Bluetooth)
#define MODO 1

//Pinos para a comunicação Bluetooh
#define RX 12
#define TX 13

//Motor da esquerda
#define IN1 10
#define IN2 9
#define ENA 11

//Motor da direita
#define IN3 8
#define IN4 7
#define ENB 6

//Servo motores
#define SERVO1_PIN 2
#define SERVO2_PIN 3
#define SERVO3_PIN 4
#define SERVO4_PIN 5

//=======================================================================================================================
//OBJETOS
//=======================================================================================================================

SoftwareSerial bluetooth(RX, TX);

L298N motores;

Servo servo1,
      servo2,
      servo3,
      servo4;

//=======================================================================================================================
//VARIÁVEIS GLOBAIS
//=======================================================================================================================

int direcao = 0,
    velocidade = 0,
    servo1_angulo = 90,
    servo2_angulo = 90,
    servo3_angulo = 90,
    servo4_angulo = 90;

//=======================================================================================================================
//FUNÇÕES
//=======================================================================================================================

String getValorDoComando(String comando, String valor);
void mover_robo();
void mover_braco();
void servoWrite(Servo servo, int angulo);

//=======================================================================================================================
//SETUP
//=======================================================================================================================

void setup(){
    Serial.begin(9600);                           //Inicia a comunicação Serial

    Serial.println("************************************");
    Serial.println("IFCE Campus Limoeiro do Norte");
    Serial.println("Tecnologia em Mecatrônica Industrial");
    Serial.println("Instrumentação Eletrônica");
    Serial.println("Projeto Robótica Educacional: Robô-Manipulador");
    Serial.println("Equipe: André");
    Serial.println("        Gideão");
    Serial.println("        José Daniel");
    Serial.println("        Marlon");
    Serial.println("        Weber Lucas");
    Serial.println("************************************");
    delay(1000);
    
    //bluetooth.begin(9600);                          //Inicia a comunicação Bluetooth
    if (MODO){
        bluetooth.begin(38400);                       //Inicia a comunicação Bluetooth
        Serial.println("> Iniciando em Modo Bluetooth...");
    }

    else {
        Serial.println("> Iniciando em Modo Serial...");
    }
    delay(500);
    
    motores.setMotorEsquerda(IN1, IN2, ENA);      //Configura o motor do lado esquerdo
    motores.setMotorDireita(IN3, IN4, ENB);       //Configura o motor do lado direito
    Serial.println("> Motores DC:     OK");
    delay(500);
    
    servo1.attach(SERVO1_PIN);
    servo2.attach(SERVO2_PIN);
    servo3.attach(SERVO3_PIN);
    servo4.attach(SERVO4_PIN);

    servo1.write(servo1_angulo);
    servo2.write(servo2_angulo);
    servo3.write(servo3_angulo);
    servo4.write(servo4_angulo);
    
    Serial.println("> Servo motores:  OK");
    delay(500);

    Serial.println("> Tudo pronto!");
    Serial.println("************************************");
}

//=======================================================================================================================
//LOOP
//=======================================================================================================================

void loop(){
    static String comando = ""; 
    String comando_aux = "";
    char c = ' ';    
    bool executar = false;

    if (MODO) {
        while(bluetooth.available() && !executar) {    //Faz a leitura do Bluetooth até receber um caracter ';'
            c = bluetooth.read();                     
            comando += c;
            
            if(c == ';') executar = true; 
        }
    }

    else {
        while(Serial.available() && !executar) {      //Faz a leitura da Serial até receber um caracter ';'
            c = Serial.read();
        
            if(c != '\n') comando += c;
            if(c == ';') executar = true;
        }
    }
    
    if(executar) {                                    //Executa o comando recebido               

        Serial.println("Comando:    " + comando);
            
        if(comando.length() == 7) {
  
            if(comando.startsWith("dir:")) {
                comando.replace("dir:", "");
                direcao = comando.toInt();
                Serial.println("Direção:    " + String(direcao));
            }
    
            else if(comando.startsWith("vel:")) {
                comando.replace("vel:", "");
                velocidade = comando.toInt();
                Serial.println("Velocidade: " + String(velocidade));
            }
    
            else if(comando.startsWith("s1:")) {
                comando.replace("s1:", "");
                servo1_angulo = comando.toInt();
                servoWrite(servo1, servo1_angulo);
                Serial.println("Servo 1:    " + String(servo1_angulo));
            }
    
            else if(comando.startsWith("s2:")) {
                comando.replace("s2:", "");
                servo2_angulo = comando.toInt();
                servo2_angulo = (servo2_angulo < 0) ? (0) : (servo2_angulo);            
                servo2_angulo = (servo2_angulo > 150) ? (150) : (servo2_angulo);
                servoWrite(servo2, servo2_angulo);
                Serial.println("Servo 2:    " + String(servo2_angulo));
            }
            
            else if(comando.startsWith("s3:")) {
                comando.replace("s3:", "");
                servo3_angulo = comando.toInt();
                servoWrite(servo3, servo3_angulo);
                Serial.println("Servo 3:    " + String(servo3_angulo));  
            }
    
            else if(comando.startsWith("s4:")) {
                comando.replace("s4:", "");
                servo4_angulo = comando.toInt();
                servoWrite(servo4, servo4_angulo);
                Serial.println("Servo 4:    " + String(servo4_angulo));  
            }
    
            Serial.println("************************************");        
        }

        comando = "";
        executar = false;
    }

    mover_robo();       //Move o robô na direção indicada pelo comando    
    //mover_braco();      //Move o braço para a posição indicada pelo comando

    delay(10);
}

//=======================================================================================================================
//FUNÇÕES
//=======================================================================================================================

//=======================================================================================================================
//EXTRAI OS VALORES DO COMANDO RECEBIDO E GRAVA NAS RESPECTIVAS VARIÁVEIS
//=======================================================================================================================

String getValorDoComando(String comando, String valor) {
    
    if(valor.equals("direcao")) {
        return(comando.substring(0, 2));
    }

    if(valor.equals("velocidade")) {
        return(comando.substring(3, 4));
    }

    if(valor.equals("servo1")) {
        return(comando.substring(5, 8));
    }

    if(valor.equals("servo2")) {
        return(comando.substring(9, 12));
    }

    if(valor.equals("servo3")) {
        return(comando.substring(13, 16));
    }

    if(valor.equals("servo4")) {
        return(comando.substring(17, 20));
    }
}

//=======================================================================================================================
//MOVE O ROBÔ
//=======================================================================================================================

void mover_robo() {    
    switch(direcao) {
        case 1: motores.frente_esquerda(); break;
        case 2: motores.frente(); break;
        case 3: motores.frente_direita(); break;
        case 4: motores.esquerda(); break;
        case 6: motores.direita(); break;
        case 7: motores.tras_esquerda(); break;
        case 8: motores.tras(); break;
        case 9: motores.tras_direita();break;
        default: motores.parar(); break;
    }
}

//=======================================================================================================================
//MOVE O BRAÇO DO ROBÔ
//=======================================================================================================================

void mover_braco() {
    /*
    static unsigned long tempo = 0;
    int passo = 2,
        intervalo = 50;
        
    if(millis() - tempo > intervalo) {
        servoWrite(servo1, servo1_angulo, passo);
        servoWrite(servo2, servo2_angulo, passo);
        servoWrite(servo3, servo3_angulo, passo);
        servoWrite(servo4, servo4_angulo, passo);
        tempo = millis();
    }
    */
}

//=======================================================================================================================
//MOVIMENTA O SERVO DE FORMA MAIS SUAVE
//=======================================================================================================================

void servoWrite(Servo servo, int angulo) {
    int anguloAtual;
     
    anguloAtual = servo.read();

    if(anguloAtual < angulo) {
        for(int i = anguloAtual; i <= angulo ; i++) {
            servo.write(i);
            delay(10);
        }
    }

    if(anguloAtual > angulo) {
        for(int i = anguloAtual; i >= angulo ; i--) {
            servo.write(i);
            delay(10);
        }
    }
}

//=======================================================================================================================
