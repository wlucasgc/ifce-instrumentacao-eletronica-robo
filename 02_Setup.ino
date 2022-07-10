//=======================================================================================================================
//SETUP
//=======================================================================================================================

void setup(){
    Serial.begin(9600);                           //Inicia a comunicação Serial

    Serial.println("***************************************************");
    Serial.println("IFCE Campus Limoeiro do Norte");
    Serial.println("Curso:      Tecnologia em Mecatrônica Industrial");
    Serial.println("Disciplina: Instrumentação Eletrônica");
    Serial.println("Projeto:    Robótica Educacional - Robô-Manipulador");
    Serial.println("Equipe:     André Luis de Oliveira Targino");
    Serial.println("            Gideão Ferreira de Sousa");
    Serial.println("            José Daniel da Silva");
    Serial.println("            Marlon da Silva Maia");
    Serial.println("            Weber Lucas Guimarães Chaves");
    Serial.println("***************************************************");
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
    Serial.println("***************************************************");
    
}

//=======================================================================================================================
