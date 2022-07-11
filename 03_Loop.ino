//=======================================================================================================================
//LOOP
//=======================================================================================================================

void loop(){
    static unsigned long tempo = 0;                        //Variável que irá guardar o tempo decorrido em milissegundos
    static String comando = "";                            //Variável que irá guardar o comando recebido
    char c = ' ';                                          //Variável que irá ler o comando recebido caracter por caracter
    bool executar = false;                                 //Variável que identifica se o comando foi finalizado para poder ser executado

    if(millis() - tempo >= 10) {                           //Executa a cada 10 milissegundos
        if (MODO) {
            while(bluetooth.available() && !executar) {    //Faz a leitura do Bluetooth
                c = bluetooth.read();                      //Lê o Bluetooth caracter por caracter
                comando += c;                              //Concatena o caracter ao comando
                
                if(c == ';') executar = true;              //Caso receba um caracter ';', o comando foi finalizado e pode ser executado
            }
        }
    
        else {
            while(Serial.available() && !executar) {      //Faz a leitura da Serial até receber um caracter ';'
                c = Serial.read();                        //Lê a Serial caracter por caracter
            
                if(c != '\n') comando += c;               //Concatena o caracter ao comando (ignora o caracter '\n')
                if(c == ';') executar = true;             //Caso receba um caracter ';', o comando foi finalizado e pode ser executado
            }
        }
        
        if(executar) {                                    //Executa o comando recebido               
            Serial.println("Comando:    " + comando);     //Imprime o comando recebido
                
            if(comando.length() == 7) {                                     //Verifica se é um comando válido (um comando válido possui 7 caracteres)  
                if(comando.startsWith("con:")) {                            //Verifica se o comando inicia com "con:" (conexão com o aplicativo)
                    Serial.println("Conectado ao aplicativo!");             //Imprime na Serial a resposta
                    bluetooth_enviar("OK"); 
                }
                
                else if(comando.startsWith("dir:")) {                       //Verifica se o comando inicia com "dir:" (direção do robô)
                    comando.replace("dir:", "");                            //Remove a identificação do componente do comando deixando apenas o valor
                    direcao = comando.toInt();                              //Converte o valor para um número inteiro
                    Serial.println("Direção:    " + String(direcao));       //Imprime na Serial o comando interpretado 
                }
        
                else if(comando.startsWith("vel:")) {                       //Verifica se o comando inicia com "vel:" (velocidade do robô)
                    comando.replace("vel:", "");                            //Remove a identificação do componente do comando deixando apenas o valor
                    velocidade = comando.toInt();                           //Conver o valor para um número inteiro
                    Serial.println("Velocidade: " + String(velocidade));    //Imprime na Serial o comando interpretado
                }
        
                else if(comando.startsWith("s1:")) {                                    //Verifica se o comando inicia com "s1:" (servo 1)
                    comando.replace("s1:", "");                                         //Remove a indentificação do componente do comando deixando apenas o valor
                    servo_para_mover = 1;                                               //Identifica qual servo será controlado
                    servo1_estado = comando.toInt();                                    //Converte o valor para um número inteiro

                    if(servo1_estado == 1) Serial.println("Decrementar Servo 1");       //Imprime na Serial o comando interpretado
                    else if(servo1_estado == 2) Serial.println("Incrementar Servo 1");
                    else Serial.println("Parar Servo 1");
                }
        
                else if(comando.startsWith("s2:")) {                                    //Verifica se o comando inicia com "s2:" (servo 2)
                    comando.replace("s2:", "");                                         //Remove a identificação do componente do comando deixando apenas o valor
                    servo_para_mover = 2;                                               //Identifica qual servo será controlado
                    servo2_estado = comando.toInt();                                    //Converte o valor para um número inteiro
                    
                    if(servo2_estado == 1) Serial.println("Decrementar Servo 2");       //Imprime na Serial o comando interpretado
                    else if(servo1_estado == 2) Serial.println("Incrementar Servo 2");
                    else Serial.println("Parar Servo 2");
                }
                
                else if(comando.startsWith("s3:")) {                                    //Verifica se o comando inicia com "s3:" (servo 3)
                    comando.replace("s3:", "");                                         //Remove a identificação do componente do comando deixando apenas o valor
                    servo_para_mover = 3;                                               //Identifica qual servo será controlado
                    servo3_estado = comando.toInt();                                    //Converte o valor para um número inteiro
                    
                    if(servo3_estado == 1) Serial.println("Decrementar Servo 3");       //Imprime na Serial o comando interpretado
                    else if(servo3_estado == 2) Serial.println("Incrementar Servo 3");
                    else Serial.println("Parar Servo 3");
                }
        
                else if(comando.startsWith("s4:")) {                                    //Verifica se o comando inicia com "s4:" (servo 4)
                    comando.replace("s4:", "");                                         //Remove a identificação do componente do comando deixando apenas o valor
                    servo_para_mover = 4;                                               //Identifica qual servo será controlado
                    servo4_estado = comando.toInt();                                    //Converte o valor para um número inteiro
                    
                    if(servo4_estado == 1) Serial.println("Decrementar Servo 4");       //Imprime na Serial o comando interpretado
                    else if(servo4_estado == 2) Serial.println("Incrementar Servo 4");
                    else Serial.println("Parar Servo 4");
                }
        
                Serial.println("***************************************************");
                
            }
    
            comando = "";     //Reseta a variável comando após o comando ter sido executado
        }
    
        tempo = millis();     //Captura o tempo atual em milissegundos
    }

    mover_robo();             //Move o robô na direção indicada pelo comando    
    mover_braco();            //Move o braço para a posição indicada pelo comando
}

//=======================================================================================================================
