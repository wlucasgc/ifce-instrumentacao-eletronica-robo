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
                //servo2_angulo = (servo2_angulo < 0) ? (0) : (servo2_angulo);            
                //servo2_angulo = (servo2_angulo > 150) ? (150) : (servo2_angulo);
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
    
            Serial.println("***************************************************");
    
        }

        comando = "";
        executar = false;
    }

    mover_robo();       //Move o robô na direção indicada pelo comando    
    
    delay(10);
}

//=======================================================================================================================
