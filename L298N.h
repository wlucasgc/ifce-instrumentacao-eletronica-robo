//=======================================================================================================================
//DIRETIVAS
//=======================================================================================================================

#ifndef L298N_H
#define L298N_H

//=======================================================================================================================
//DECLARAÇÃO
//=======================================================================================================================

class L298N {
    private:
        bool configurado_e, configurado_d;
        
        int pino_e1,
            pino_e2,
            pino_eV;
    
        int pino_d3,
            pino_d4,
            pino_dV;

         int velocidade_e,
             velocidade_d;
             
    public:
        L298N();
        L298N(int e1, int e2, int eV, int d3, int d4, int dV);

        void setMotorEsquerda(int e1, int e2, int eV);
        void setMotorDireita(int d3, int d4, int dV);

        void setVelocidadeMotorEsquerda(int ve);
        void setVelocidadeMotorDireita(int vd);
        void setVelocidade(int vel);
        
        void parar();
        void frente();
        void tras();
        void direita();
        void esquerda();

        void frente_esquerda();
        void frente_direita();
        void tras_esquerda();
        void tras_direita();
};

#endif

//=======================================================================================================================
