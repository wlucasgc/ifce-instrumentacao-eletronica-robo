//=======================================================================================================================
//OBJETOS
//=======================================================================================================================

SoftwareSerial bluetooth(RX, TX);     //Objeto responsável pela comunicação via Bluetooth

L298N motores;                        //Objeto responsável pelo controle dos motores DC ligados ao driver L298N

Servo servo1,                         //Objeto responsável pelo controle do servo 1 do braço
      servo2,                         //Objeto responsável pelo controle do servo 2 do braço
      servo3,                         //Objeto responsável pelo controle do servo 3 do braço
      servo4;                         //Objeto responsável pelo controle do servo 4 do braço

//=======================================================================================================================
//VARIÁVEIS GLOBAIS
//=======================================================================================================================

int direcao = 0,                      //Variável que armazena a direção que o robô deve se mover
    velocidade = 2,                   //Variável que armazena a velocidade do robô (espera valores de 1 a 3)
    servo_para_mover = 0,             //Variável que identifica qual servo está sendo controlado neste momento
    servo1_estado = 0,                //Variável que identifica o estado do servo 1 (parado, decrementando ou incrementando o ângulo)
    servo2_estado = 0,                //Variável que identifica o estado do servo 2 (parado, decrementando ou incrementando o ângulo)
    servo3_estado = 0,                //Variável que identifica o estado do servo 3 (parado, decrementando ou incrementando o ângulo)
    servo4_estado = 0;                //Variável que identifica o estado do servo 4 (parado, decrementando ou incrementando o ângulo)

//=======================================================================================================================
//FUNÇÕES
//=======================================================================================================================

//String getValorDoComando(String comando, String valor);
void mover_robo();                              //Move o robô para a direção desejada
void mover_braco();                             //Move o os servos que compõem o braço para a posição desejada
void servo_write(Servo servo, int estado);      //Movimenta o servo de forma suave

//=======================================================================================================================
