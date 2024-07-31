#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl;
    cout << "**************************************" << endl;
    
    cout << "Escolha o seu nivel de dificuldade: " <<endl;
    cout << " Facil (F), Medio (M) ou Dificil (D)" <<endl;

    char dificuldade;
    cin >> dificuldade;
    int numero_tentativas;

    if (dificuldade == 'F'){
        numero_tentativas = 15;
    }
    else if (dificuldade == 'M'){
        numero_tentativas = 10;
    }
    else {
        numero_tentativas = 5;
    }
    

    srand(time(NULL));
    const int numero_secreto = rand() % 100;
    cout << "Numero secreto: " << numero_secreto << endl;
    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= numero_tentativas; tentativas++)
    {
        int chute;
        cout << "Tentativas " << tentativas << endl;
        cout <<  "Qual eh o seu chute?";
        cin >> chute;
        double pontos_perdidos = abs(chute - numero_secreto)/2.0;
        pontos = pontos - pontos_perdidos;

        cout << "O valor do seu chute eh: " << chute << endl;
        bool acertou = chute == numero_secreto;
        bool maior = chute > numero_secreto; 

        if(acertou){
            cout << "Parabens!!" << endl;
            nao_acertou = false;
            break;
        }
        else if (maior){
            cout << "Seu numero foi maior que o numero secreto." << endl;
        }
        else{
            cout << "Seu numero foi menor que o numero secreto." << endl;
        }
    }
    cout << "Fim de jogo" << endl;
    if(nao_acertou){
        cout << "Voce perdeu!! burro :)" << endl;

    }
    else{
        cout << "Voce acertou o numero secreto em " << tentativas << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi de " << pontos << " pontos." << endl;
    }
    
}