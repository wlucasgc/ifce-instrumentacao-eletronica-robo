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

#include <Servo.h>
#include <SoftwareSerial.h>
#include "L298N.h"

//=======================================================================================================================
//DEFINIÇÕES
//=======================================================================================================================

//O modo de comunicação determina por qual meio serão recebidos os comandos (0: Modo Serial | 1: Modo Bluetooth)
#define MODO 1

//Pinos para a comunicação Bluetooh
#define RX A4
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
