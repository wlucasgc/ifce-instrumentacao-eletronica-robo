//=======================================================================================================================
//APRESENTAÇÃO
//=======================================================================================================================

//IFCE Campus Limoeiro do Norte
//Curso:      Tecnologia em Mecatrônica Industrial
//Disciplina: Instrumentação Eletrônica
//Projeto:    Robótica Educacional - Robô-Manipulador
//Equipe:     André Luis de Oliveira Targino
//            Gideão Ferreira de Sousa
//            José Daniel da Silva
//            Marlon da Silva Maia
//            Weber Lucas Guimarães Chaves
    
//=======================================================================================================================
//BIBLIOTECAS
//=======================================================================================================================

#include <Servo.h>                //Biblioteca para controle dos servo motores
#include <SoftwareSerial.h>       //Biblioteca para comunicação via Bluetooth
#include "L298N.h"                //Biblioteca desenvolvida para controle dos motores DC utilizando o driver L298N

//=======================================================================================================================
//DEFINIÇÕES
//=======================================================================================================================

#define MODO 1          //O modo de comunicação determina por qual meio serão recebidos os comandos
                        //(0: Modo Serial | 1: Modo Bluetooth)

#define RX A4           //Pino RX (será ligado ao TX do módulo bluetooth)
#define TX 13           //Pino TX (será ligado ao RX do módulo bluetooth - é necessário um divisor de tensão)

#define IN1 10          //Pinos de controle do motor da esquerda
#define IN2 9             
#define ENA 11

#define IN3 8           //Pinos de controle do motor da direita
#define IN4 7
#define ENB 6

#define SERVO1_PIN 2    //Pinos de controle dos servo motores que compõem o braço
#define SERVO2_PIN 3
#define SERVO3_PIN 4
#define SERVO4_PIN 5

//=======================================================================================================================
