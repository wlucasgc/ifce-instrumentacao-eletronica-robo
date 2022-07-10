//=======================================================================================================================
//BIBLIOTECAS
//=======================================================================================================================

#include <Arduino.h>                  //lib para as funções padrão do Arduino
#include "L298N.h"

//=======================================================================================================================
//CONSTRUTOR 1
//=======================================================================================================================

L298N::L298N() {
    configurado_e = false;
    configurado_d = false;
}

//=======================================================================================================================
//CONSTRUTOR 2
//=======================================================================================================================

L298N::L298N(int e1, int e2, int eV, int d3, int d4, int dV) {
    setMotorEsquerda(e1, e2, eV);
    setMotorDireita(d3, d4, dV);
}

//=======================================================================================================================
//CONFIGURA O MOTOR DA ESQUERDA
//=======================================================================================================================

void L298N::setMotorEsquerda(int e1, int e2, int eV) {
    pino_e1 = e1;
    pino_e2 = e2;
    pino_eV = eV;
    velocidade_e = 255;
    
    pinMode(pino_e1, OUTPUT);
    pinMode(pino_e2, OUTPUT);
    pinMode(pino_eV, OUTPUT);

    digitalWrite(pino_e1, LOW);
    digitalWrite(pino_e2, LOW);
    analogWrite(pino_eV, velocidade_e);
    
    configurado_e = true;
}

//=======================================================================================================================
//CONFIGURA O MOTOR DA DIREITA
//=======================================================================================================================

void L298N::setMotorDireita(int d3, int d4, int dV) {
    pino_d3 = d3;
    pino_d4 = d4;
    pino_dV = dV;
    velocidade_d = 255;
    
    pinMode(pino_d3, OUTPUT);
    pinMode(pino_d4, OUTPUT);
    pinMode(pino_dV, OUTPUT);

    digitalWrite(pino_d3, LOW);
    digitalWrite(pino_d4, LOW);
    analogWrite(pino_dV, velocidade_d);
    
    configurado_d = true;
}

//=======================================================================================================================
//CONFIGURA A VELOCIDADE DO MOTOR DA ESQUERDA
//=======================================================================================================================

void L298N::setVelocidadeMotorEsquerda(int ve) {
    velocidade_e = ve;
    analogWrite(pino_eV, velocidade_e);
}

//=======================================================================================================================
//CONFIGURA A VELOCIDADE DO MOTOR DA DIREITA
//=======================================================================================================================

void L298N::setVelocidadeMotorDireita(int vd) {
    velocidade_d = vd;
    analogWrite(pino_dV, velocidade_d);
}

//=======================================================================================================================
//CONFIGURA A VELOCIDADE DE AMBOS OS MOTORES
//=======================================================================================================================

void L298N::setVelocidade(int vel) {
    setVelocidadeMotorEsquerda(vel);
    setVelocidadeMotorDireita(vel);
}

//=======================================================================================================================
//PARAR
//=======================================================================================================================

void L298N::parar() {
    if(configurado_e) {
        digitalWrite(pino_e1, HIGH);
        digitalWrite(pino_e2, HIGH);
        analogWrite(pino_eV, velocidade_e);
    }

    if(configurado_d) {
        digitalWrite(pino_d3, HIGH);
        digitalWrite(pino_d4, HIGH);
        analogWrite(pino_dV, velocidade_d);
    }
}

//=======================================================================================================================
//PARA FRENTE
//=======================================================================================================================

void L298N::frente() {
    if(configurado_e) {
        digitalWrite(pino_e1, HIGH);
        digitalWrite(pino_e2, LOW);
        analogWrite(pino_eV, velocidade_e);
    }

    if(configurado_d) {
        digitalWrite(pino_d3, LOW);
        digitalWrite(pino_d4, HIGH);
        analogWrite(pino_dV, velocidade_d);
    }
}

//=======================================================================================================================
//PARA TRÁS
//=======================================================================================================================

void L298N::tras() {
    if(configurado_e) {
        digitalWrite(pino_e1, LOW);
        digitalWrite(pino_e2, HIGH);
        analogWrite(pino_eV, velocidade_e);
    }

    if(configurado_d) {
        digitalWrite(pino_d3, HIGH);
        digitalWrite(pino_d4, LOW);
        analogWrite(pino_dV, velocidade_d);
    }
}

//=======================================================================================================================
//PARA A ESQUERDA
//=======================================================================================================================

void L298N::esquerda() {
    if(configurado_e) {
        digitalWrite(pino_e1, LOW);
        digitalWrite(pino_e2, HIGH);
        analogWrite(pino_eV, velocidade_e);
    }

    if(configurado_d) {
        digitalWrite(pino_d3, LOW);
        digitalWrite(pino_d4, HIGH);
        analogWrite(pino_dV, velocidade_d);
    }
}

//=======================================================================================================================
//PARA A DIREITA
//=======================================================================================================================

void L298N::direita() {
    if(configurado_e) {
        digitalWrite(pino_e1, HIGH);
        digitalWrite(pino_e2, LOW);
        analogWrite(pino_eV, velocidade_e);
    }

    if(configurado_d) {
        digitalWrite(pino_d3, HIGH);
        digitalWrite(pino_d4, LOW);
        analogWrite(pino_dV, velocidade_d);
    }
}

//=======================================================================================================================
//PARA FRENTE-ESQUERDA
//=======================================================================================================================

void L298N::frente_esquerda() {
    if(configurado_e) {
        digitalWrite(pino_e1, HIGH);
        digitalWrite(pino_e2, HIGH);
        analogWrite(pino_eV, HIGH);
    }

    if(configurado_d) {
        digitalWrite(pino_d3, LOW);
        digitalWrite(pino_d4, HIGH);
        analogWrite(pino_dV, velocidade_d);
    }
}

//=======================================================================================================================
//PARA FRENTE-DIREITA
//=======================================================================================================================

void L298N::frente_direita() {
    if(configurado_e) {
        digitalWrite(pino_e1, HIGH);
        digitalWrite(pino_e2, LOW);
        analogWrite(pino_eV, velocidade_e);
    }

    if(configurado_d) {
        digitalWrite(pino_d3, HIGH);
        digitalWrite(pino_d4, HIGH);
        analogWrite(pino_dV, HIGH);
    }
}

//=======================================================================================================================
//PARA TRÁS-ESQUERDA
//=======================================================================================================================

void L298N::tras_esquerda() {
    if(configurado_e) {
        digitalWrite(pino_e1, HIGH);
        digitalWrite(pino_e2, HIGH);
        analogWrite(pino_eV, HIGH);
    }

    if(configurado_d) {
        digitalWrite(pino_d3, HIGH);
        digitalWrite(pino_d4, LOW);
        analogWrite(pino_dV, velocidade_d);
    }
}

//=======================================================================================================================
//PARA TRÁS-DIREITA
//=======================================================================================================================

void L298N::tras_direita() {
    if(configurado_e) {
        digitalWrite(pino_e1, LOW);
        digitalWrite(pino_e2, HIGH);
        analogWrite(pino_eV, velocidade_e);
    }

    if(configurado_d) {
        digitalWrite(pino_d3, HIGH);
        digitalWrite(pino_d4, HIGH);
        analogWrite(pino_dV, HIGH);
    }
}

//=======================================================================================================================
