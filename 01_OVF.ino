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
    velocidade = 2,
    servo1_angulo = 90,
    servo2_angulo = 90,
    servo3_angulo = 90,
    servo4_angulo = 90;

//=======================================================================================================================
//FUNÇÕES
//=======================================================================================================================

String getValorDoComando(String comando, String valor);
void mover_robo();
void servoWrite(Servo servo, int angulo);

//=======================================================================================================================