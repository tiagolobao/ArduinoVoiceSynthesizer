
//Voice Synthetizer
#include <SimpleSDAudio.h> //Biblioteca reprodutora de Audio
#include <LiquidCrystal.h> //Biblioteca para o display LCD
#include <avr/pgmspace.h> // Gravação de constantes dentro da memória flash
#include <PS2Keyboard.h> //Biblioteca do teclado

// pino saida de audio = 44 ARDUINO MEGA e 9 ARDUINO UNO (com o bridge temos um segundo pino que é o 10)
// ou outros pinos ou são vcc ou são SPI (pesquisar no site do arduino)

PS2Keyboard keyboard; //Necessário para o funcionamento do teclado USB

//Declaração das variáveis do replace dentro da flash, de forma a economizar cerca de 800 bytes. Indispensável para o funcionamento no UNO
char buffer_um[11],buffer_dois[14];

//LADO ESQUERDO------------------------------------------
prog_char rep_esq0[] PROGMEM = "QU-E"; 
prog_char rep_esq1[] PROGMEM = "QU-I"; 
prog_char rep_esq2[] PROGMEM = "QU-O"; 
prog_char rep_esq3[] PROGMEM = "GU-E"; 
prog_char rep_esq4[] PROGMEM = "GU-I";
prog_char rep_esq5[] PROGMEM = "GU-O";

prog_char rep_esq6[] PROGMEM = "çA";
prog_char rep_esq7[] PROGMEM = "çE";
prog_char rep_esq8[] PROGMEM = "çI";
prog_char rep_esq9[] PROGMEM = "çO";
prog_char rep_esq10[] PROGMEM = "çU";

prog_char rep_esq11[] PROGMEM = "PA-RA-DO-X";
prog_char rep_esq12[] PROGMEM = "A-BA-CA-X";

prog_char rep_esq13[] PROGMEM = " E-X";
prog_char rep_esq14[] PROGMEM = "A-XI";
prog_char rep_esq15[] PROGMEM = "O-XI";
prog_char rep_esq16[] PROGMEM = "HE-X";
prog_char rep_esq17[] PROGMEM = "E-XO";
prog_char rep_esq18[] PROGMEM = "E-XU";
prog_char rep_esq19[] PROGMEM = "E-XI";
prog_char rep_esq20[] PROGMEM = "U-XI";

prog_char rep_esq21[] PROGMEM = "X";
prog_char rep_esq22[] PROGMEM = " R";
prog_char rep_esq23[] PROGMEM = " S";

prog_char rep_esq24[] PROGMEM = "CA";
prog_char rep_esq25[] PROGMEM = "CE";
prog_char rep_esq26[] PROGMEM = "CI";
prog_char rep_esq27[] PROGMEM = "CO";
prog_char rep_esq28[] PROGMEM = "CU";

prog_char rep_esq29[] PROGMEM = "-GE";
prog_char rep_esq30[] PROGMEM = "-GI";
prog_char rep_esq31[] PROGMEM = "GUE";
prog_char rep_esq32[] PROGMEM = "GUI";

prog_char rep_esq33[] PROGMEM = "-H";
prog_char rep_esq34[] PROGMEM = " H";

prog_char rep_esq35[] PROGMEM = "N-R";
prog_char rep_esq36[] PROGMEM = "N-S";
prog_char rep_esq37[] PROGMEM = "SSS";
prog_char rep_esq38[] PROGMEM = "A-O\0";
prog_char rep_esq39[] PROGMEM = "-C-";
prog_char rep_esq40[] PROGMEM = "N-";
prog_char rep_esq41[] PROGMEM = "-U\0";
prog_char rep_esq42[] PROGMEM = "-ZP";


//LADO DIREITO-------------------------------------------
prog_char rep_dir0[] PROGMEM = "KE"; 
prog_char rep_dir1[] PROGMEM = "KI"; 
prog_char rep_dir2[] PROGMEM = "KO"; 
prog_char rep_dir3[] PROGMEM = "GUE"; 
prog_char rep_dir4[] PROGMEM = "GUI";
prog_char rep_dir5[] PROGMEM = "GUO";

prog_char rep_dir6[] PROGMEM = "SSA";
prog_char rep_dir7[] PROGMEM = "SSE";
prog_char rep_dir8[] PROGMEM = "SSI";
prog_char rep_dir9[] PROGMEM = "SSO";
prog_char rep_dir10[] PROGMEM = "SSU";

prog_char rep_dir11[] PROGMEM = "PA-RA-DO-C-SS";
prog_char rep_dir12[] PROGMEM = "A-BA-CA-CH";

prog_char rep_dir13[] PROGMEM = " E-Z";
prog_char rep_dir14[] PROGMEM = "A-C-SSI";
prog_char rep_dir15[] PROGMEM = "O-C-SSI";
prog_char rep_dir16[] PROGMEM = "E-C-SS";
prog_char rep_dir17[] PROGMEM = "E-C-SS0";
prog_char rep_dir18[] PROGMEM = "E-C-SSU";
prog_char rep_dir19[] PROGMEM = "E-ZI";
prog_char rep_dir20[] PROGMEM = "U-SSI";

prog_char rep_dir21[] PROGMEM = "CH";
prog_char rep_dir22[] PROGMEM = " RR";
prog_char rep_dir23[] PROGMEM = " SS";

prog_char rep_dir24[] PROGMEM = "KA";
prog_char rep_dir25[] PROGMEM = "SSE";
prog_char rep_dir26[] PROGMEM = "SSI";
prog_char rep_dir27[] PROGMEM = "KO";
prog_char rep_dir28[] PROGMEM = "KU";

prog_char rep_dir29[] PROGMEM = "-JE";
prog_char rep_dir30[] PROGMEM = "-JI";
prog_char rep_dir31[] PROGMEM = "GE";
prog_char rep_dir32[] PROGMEM = "GI";

prog_char rep_dir33[] PROGMEM = "-";
prog_char rep_dir34[] PROGMEM = " ";

prog_char rep_dir35[] PROGMEM = "N-RR";
prog_char rep_dir36[] PROGMEM = "N-SS";
prog_char rep_dir37[] PROGMEM = "SS";
prog_char rep_dir38[] PROGMEM = "AO\0";
prog_char rep_dir39[] PROGMEM = "-KI-";
prog_char rep_dir40[] PROGMEM = "M-";
prog_char rep_dir41[] PROGMEM = "L\0";
prog_char rep_dir42[] PROGMEM = "S-P";

PROGMEM const char *rep_esq[43] = 	
{   
  rep_esq0, rep_esq1, rep_esq2, rep_esq3, rep_esq4, rep_esq5, rep_esq6, rep_esq7, rep_esq8, rep_esq9, rep_esq10, rep_esq11, rep_esq12, rep_esq13, rep_esq14, rep_esq15, rep_esq16,
  rep_esq17, rep_esq18, rep_esq19, rep_esq20, rep_esq21, rep_esq22, rep_esq23, rep_esq24, rep_esq25, rep_esq26, rep_esq27, rep_esq28, rep_esq29, rep_esq30, rep_esq31, rep_esq32,
  rep_esq33, rep_esq34, rep_esq35, rep_esq36, rep_esq37, rep_esq38, rep_esq39, rep_esq40, rep_esq41, rep_esq42
   };

PROGMEM const char *rep_dir[43] = 	 
{   
  rep_dir0, rep_dir1, rep_dir2, rep_dir3, rep_dir4,rep_dir5, rep_dir6, rep_dir7, rep_dir8, rep_dir9, rep_dir10, rep_dir11, rep_dir12, rep_dir13, rep_dir14, rep_dir15, rep_dir16,
  rep_dir17, rep_dir18, rep_dir19, rep_dir20, rep_dir21, rep_dir22, rep_dir23, rep_dir24, rep_dir25, rep_dir26, rep_dir27, rep_dir28, rep_dir29, rep_dir30, rep_dir31, rep_dir32,
  rep_dir33, rep_dir34, rep_dir35, rep_dir36, rep_dir37, rep_dir38, rep_dir39, rep_dir40, rep_dir41, rep_dir42,
   };

int i,p,L;
char Sil[16], c;
String frase, Ssil="";
LiquidCrystal lcd(0 ,1, 3, 4, 5, 6);  // Pinos do LCD (RS,Enable,D4,D5,D6,D7)
boolean flag;

void setup() {
  SdPlay.setSDCSPin(7); // Define o pino CS = 7
  lcd.begin(16,2);   // inicializando o lcd de 16 caracteres e 2 linhas 
  lcd.setCursor(0,0); //Seta o cursor na posição 0 , 0
  lcd.clear(); //Limpa a tela LCD
  keyboard.begin(8,2); // Inicialização do teclado (DataPin, IRQpin)
  if (!SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO_BRIDGE | SSDA_MODE_AUTOWORKER)) //Configuração do SimpleSDAudio
    {lcd.print("Erro no SD!"); //Mensagem de erro printada no LCD caso não consiga inicializar
    while(1); //Loop infinito por conta do erro, obrigando a pessoa a resetar
  } 
}
  
void loop() { 
  lcd.begin(16,2);   // Inicializa o LCD, que possui 16 colunas e 2 linhas
  lcd.setCursor(0,0); //Começa o cursor na posição 0 e 0
  lcd.clear(); //Limpa a tela LCD
  lcd.print("Escreva Frase:"); // Escreve na tela LCD, para indicar que o software já esta inicializado
    
   ReadKeyboard();  //Função de ler frase do teclado a ser reproduzida
   frase.toUpperCase();  //Deixar a variável frase toda em caixa alta 
   frase = separar(frase); //Roda a função para separar sílabas
  
   ReproduzirFrase(); //Função que reproduz a frase digitada
   
   frase=""; //Reinicia a variável para ser utilizada novamente
}


  //varredura do teclado até pressonar enter 
 // Código ASCII => 13 = enter ;  127 = backspace
void ReadKeyboard(){
  while(!keyboard.available()); //Enquanto nenhuma tecla do teclado for pressionada não faça nada  
  p=0; //As variáveis p e L indicam a posição atual do cursor (p = coluna e L = linha)
  L=0;
  lcd.clear();
  lcd.setCursor(p,0); 
  c=127;
  while(c!=13){
    flag=0;
    //leitura do teclado
    if (keyboard.available()) {
    //Verificação de caso especial da posição do cursor
    if (p==0 && L==1){ //Volta linha quando pressionado backspace e a segunda linha estiver vazia
      p=16;
      L=0;
      flag=1;
    }
    if (p==16 && L==0 && flag==0) { //pula para segunda linha caso a primeira esteja toda preenchida
      p=0;
      L=1;
    }  
    if (p==17 && L==1){ //reproduzir caso ultrapasse o limite do display LCD
      break;
    }
    if (p==-1 && L==0){ //Remoção de bug quando o usuário apertar backspace sem nada escrito
      p=0;
    }
    c = keyboard.read(); //c é a variável que guarda o caracter digitado
    lcd.setCursor(p,L);
    if(c==127 && p!=0){ //para apagar um caractere
      dobackspace();
    }
    else if(c!=13 && c!=127){ //para escrever um caractere na tela e guardar o caractere na string frase
      lcd.write(c);
      frase=frase+c;
      p++;
    }  
    }
  }

}


   //Reprodução dos fonemas a partir da frase separada
void ReproduzirFrase(){   
   for(int n=0; n<=frase.length();n++){
     if(frase.charAt(n)!='-' && frase.charAt(n)!=' ' && frase.charAt(n)!='\0'){
            Ssil=Ssil+frase.charAt(n);  //Guardando parte da string (um fonema) em outra string
     }
     if(frase.charAt(n)=='-' || n==frase.length() || frase.charAt(n)==' '){
              Ssil=Ssil+".AFM";
              for(int s=0;s<=Ssil.length();s++){  //Transformação da string com o fonema para char
               Sil[s]=Ssil.charAt(s); 
              }
              
              SdPlay.setFile(Sil);  //Escolhe o arquivo a ser executado  
              SdPlay.play(); //Reproduz o arquivo escolhido
              while(!SdPlay.isStopped()); //Para a execução do programa até o arquivo terminar de ser reproduzido
              Ssil="";
              delay(10);
   }

   }
}

String separar(String input){     //Função: separa a frase em sílabas a serem pronunciadas pelo sintetizador
    String frase_separada = "";
    for(i=0 ; i<input.length() ; i++){   //Loop: analisa todas as letras da frase digitada
          frase_separada += input.charAt(i);   //coloca a letra analisada na string da frase separada
          if(input.length() <= i + 1 || input.charAt(i + 1) == ' ') continue;   //Se a letra analisada for a ultima da palavra, será incluida na string e não será analisada
          else if(pertence(input.charAt(i), "RLMNSPCB") && input.length() > i) {  //Casos especiais de separação silábica
                char proxima = input.charAt(i + 1);
                switch(input.charAt(i)){                
                  case 'R':
                    if(proxima != 'R' && !IsVogal(proxima)) frase_separada += '-';  // Inclui o segundo R na mesma sílaba. Ex: Carro = Ca-rro
                    break;
                  case 'L':
                    if(proxima != 'H' && !IsVogal(proxima)) frase_separada += '-'; //Une as letas L e H na mesma sílaba. Ex: Baralho = Ba-ra-lho
                    break;
                  case'N':
                    if(proxima != 'H' && !IsVogal(proxima)) frase_separada += '-'; //Une as letras N e H na mesma sílaba. Ex: Engenharia = En-ge-nha-ri-a
                    break;
                  case 'S':
                    if(proxima != 'S' && !IsVogal(proxima)) frase_separada += '-'; // Inclui o segundo S na mesma sílaba. Ex: Assassino = A-ssa-ssi-no
                    break;                    
                  case 'M':
                    if(!IsVogal(proxima)) frase_separada += '-'; //Termina a vogal depois do M, se depois do M tiver consoante. Ex: 
                    break;
                  case 'P':
                    if(!pertence(proxima, "LRS") && !IsVogal(proxima)) frase_separada += '-'; //Une o P com L, R ou S. Ex: Plagio = Pla-gi-o
                    break;
                  case 'C':
                    if(!pertence(proxima, "HLR") && !IsVogal(proxima)) frase_separada += '-'; //Une C com H, L, R ou S. Ex: Crase = Sacramento = Sa-cra-men-to
                    break;  
                  case 'B':
                    if(!pertence(proxima, "LRS") && !IsVogal(proxima)) frase_separada += '-'; //Ube B com L, R ou S. Ex: Problema = Pro-ble-ma
                    break; //Porque o s pelo amor de deus
            }
          } else if(IsVogal(input.charAt(i))){
            if(!pertence(input.charAt(i+1), "RLMNSZ")||IsVogal(input.charAt(i+1))){  //termina a sílaba se a letra analisada for vogal, mas a próxima letra não é R,L,M,N ou S
              frase_separada += '-';
            }
            else if(input.length()>i+2){
              char letraC = input.charAt(i+1);
              if(IsVogal(input.charAt(i+2))) frase_separada += '-';
              else{
                switch(letraC){
                  case 'R':
                    if(input.charAt(i+2)=='R') frase_separada += '-'; 
                    break;
                  case 'L':
                    if(input.charAt(i+2)=='H') frase_separada += '-';
                    break;
                  case'N':
                    if(input.charAt(i+2)=='H') frase_separada += '-';
                    break;
                  case 'S':
                    if(input.charAt(i+2)=='S') frase_separada += '-';
                    break;                    
                } 
               }
              }
            }
          }
          
    // ajudando a identificar inícios de palavra since agora
    frase_separada = " " + frase_separada;
    //Substituição das sílabas ou letras pela sua pronuncia
     for (i=0 ; i<=42 ; i++)
  {
    strcpy_P(buffer_um, (char*)pgm_read_word(&(rep_esq[i]))); // Guarda a string que está na memória flash no buffer
    strcpy_P(buffer_dois, (char*)pgm_read_word(&(rep_dir[i]))); //  Procedimento padrão para cópia de uma constante para o buffer
    frase_separada.replace(buffer_um,buffer_dois); // replace a partir de constantes da memoria flash
  } 
    
    frase_separada.substring(2); //Não lembro porque isso está aqui, mas vai que da merda se tirar. Preferi deixar.
    
    return frase_separada;
 }
 
 boolean IsVogal(char letra){                    //Função: Verifica se a letra é vogal
  String consoantes = "AEIOU";
  boolean is = consoantes.indexOf(letra) > -1;
  return is;
 }
 
 boolean pertence(char letra, String conjunto){  //Função: Verifica se a letra pertence a um conjunto de letras específicas
  boolean is = conjunto.indexOf(letra) > -1;
  return is;
 }
 
 
 //Função para dar backspace
 void dobackspace(){
  p--;
  lcd.setCursor(p,L);
  lcd.write(' ');
  lcd.setCursor(p,L);
  frase=frase.substring(0,frase.length()-1);
 }
