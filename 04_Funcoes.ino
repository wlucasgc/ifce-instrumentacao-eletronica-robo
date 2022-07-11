//=======================================================================================================================
//MOVE O ROBÔ
//=======================================================================================================================

void mover_robo() {
    motores.setVelocidade(map(velocidade, 1, 3, 150, 255));                
    
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

void mover_braco() {
    switch(servo_para_mover) {
        case 1: servo_write(servo1, servo1_estado); break;      //Comando para o servo 1
        case 2: servo_write(servo2, servo2_estado); break;      //Comando para o servo 2
        case 3: servo_write(servo3, servo3_estado); break;      //Comando para o servo 3
        case 4: servo_write(servo4, servo4_estado); break;      //Comando para o servo 4
    }
}

//=======================================================================================================================
//MOVIMENTA O SERVO
//=======================================================================================================================

void servo_write(Servo servo, int estado) {
    static unsigned long tempo = 0;
    int angulo,
        passo = 1;
   
    if(millis() - tempo >= 25) {
        switch(estado) {
            case 1:                                               //Decrementa o ângulo do servo
                angulo = servo.read() - passo;
                angulo = (angulo <= 0) ? (0) : (angulo);
                servo.write(angulo);
            break;

            case 2:                                               //Incrementa o ângulo do servo
                angulo = servo.read() + passo;
                angulo = (angulo >= 180) ? (180) : (angulo);
                servo.write(angulo);
            break;    
        }

        tempo = millis();
    }
}

//=======================================================================================================================
//ENVIA UMA MENSAGEM ATRAVÉS DO BLUETOOTH
//=======================================================================================================================

void bluetooth_enviar(String mensagem) {
    for(int i = 0 ; i < mensagem.length() ; i++) {
        bluetooth.write(mensagem.charAt(i));
        delay(10);  
    }
}

//=======================================================================================================================


/*
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
*/
