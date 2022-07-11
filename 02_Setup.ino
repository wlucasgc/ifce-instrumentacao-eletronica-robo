//=======================================================================================================================
//SETUP
//=======================================================================================================================

void setup(){
    Serial.begin(9600);                   //Inicia a comunicação Serial

    Serial.println("***************************************************");      //Apresentação
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

    if (MODO){                           //Verifica se os comandos serão recebidos via Bluetooth ou via Serial (debug)
        //bluetooth.begin(9600);         //Inicia a comunicação Bluetooth (velocidade padrão)
        bluetooth.begin(38400);          //Inicia a comunicação Bluetooth
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
    
    servo1.attach(SERVO1_PIN);                    //Configura o servo 1
    servo2.attach(SERVO2_PIN);                    //Configura o servo 2
    servo3.attach(SERVO3_PIN);                    //Configura o servo 3
    servo4.attach(SERVO4_PIN);                    //Configura o servo 4

    Serial.println("> Servo motores:  OK");
    delay(500);

    Serial.println("> Tudo pronto!");
    Serial.println("***************************************************");
    
}

//=======================================================================================================================
