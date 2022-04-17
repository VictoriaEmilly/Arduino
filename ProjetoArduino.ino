//Link do projeto no Tinkercad:
//https://www.tinkercad.com/things/6UQrE074WuT-ra-321211497-parte-2/editel

int sinal=3; //variável do tipo inteira, dizendo a porta usada
float distancia; // variável do tipo decimal
void leitura();

int vermelho=13; //porta 13 está no pino vermelho;
int azul=11; //porta 11 está no pino azul;
int verde=10; //porta 10 está no pino verde; 

void vermelhoFuncao(){
  digitalWrite(azul,LOW);
  digitalWrite(verde,LOW);
  digitalWrite(vermelho,HIGH);
}
void amareloFuncao(){
  digitalWrite(azul,0);
  digitalWrite(verde,50);
  digitalWrite(vermelho,255);
}
void verdeFuncao(){
  digitalWrite(azul,LOW);
  digitalWrite(verde,HIGH);
  digitalWrite(vermelho,LOW);
}

void setup()
{
  Serial.begin(9600);
  pinMode(sinal,OUTPUT); //comece a porta escolhida como saída
  digitalWrite(sinal,LOW); //porta escolhida desliga
  pinMode(verde,OUTPUT);
  pinMode(vermelho,OUTPUT);
  pinMode(azul,OUTPUT);
}
void loop()
{
  leitura();
  distancia=distancia/2; //ida e volta do sinal ultrassonico
  //para saber a distância, lembre-mos que o sinal tem
  //a velocidade do som (340.29m/s)
  distancia=distancia*0.034029; //assim medimos em cm
  Serial.println("Distancia: "); //imprima a distância nos testes
  Serial.println(distancia); //imprima a distância nos testes
  delay(250); //delay para entregar a distância
  
  if(distancia>=3 && distancia<75)
    verdeFuncao();
  else if (distancia>=75 && distancia<150)
    amareloFuncao();
  else
    vermelhoFuncao();
    
    float sinaltemp=analogRead(A4)*5; //converter corrente (mA) e °F em °C
    float TempC=((sinaltemp/1023)-0.5)*100;
  Serial.println("Temperatura: "); //imprima a temperatura nos testes
    Serial.println(TempC); //imprima a temperatura nos testes
    delay(250); //delay para entregar a distância
  
    //leitura de gas
    int sinalgas = analogRead(A5); //leia a porta A5;
    sinalgas=map(sinalgas,300,750,0,100);//remapear os valores
    Serial.println("Gas: "); //imprima a concentração de gás
    Serial.println(sinalgas); //imprima a concentração de gás
    delay(250);
}
void leitura(){
  pinMode(sinal,OUTPUT);//comece desligada 
  digitalWrite(sinal,HIGH); //ligue
  delayMicroseconds(5); // Sinal de ida de 5 microsegundos
  digitalWrite(sinal,LOW); //desliga
  pinMode(sinal,INPUT); //receba sinal
  distancia=pulseIn(sinal,HIGH); //recebido entrar na entrada 3
}
