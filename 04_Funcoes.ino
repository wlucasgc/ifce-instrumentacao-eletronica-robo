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

//=======================================================================================================================
//MOVIMENTA O SERVO DE FORMA MAIS SUAVE
//=======================================================================================================================

void servoWrite(Servo servo, int angulo) {
    int anguloAtual;
     
    anguloAtual = servo.read();

    if(anguloAtual < angulo) {
        for(int i = anguloAtual; i <= angulo ; i++) {
            servo.write(i);
            delay(10);
        }
    }

    if(anguloAtual > angulo) {
        for(int i = anguloAtual; i >= angulo ; i--) {
            servo.write(i);
            delay(10);
        }
    }
}

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
*/

//=======================================================================================================================
