


//Voice Synthetizer
#include <MemoryFree.h> //Biblioteca verificação de memória RAM
//#include <PS2Keyboard.h> //Biblioteca do teclado
#include <SimpleSDAudio.h> //Biblioteca reprodução de audio atravez do cartão SD
#include <LiquidCrystal.h> // Foi removida da bilbioteca toda a programação para LCD's I2C, por conta de compatibilidade do SimpleSDAudio.h com a Wire.h no arduino UNO
#include <avr/pgmspace.h> // Gravação de constantes dentro da memória flash
// pino saida de audio = 9
// ou outros pinos ou são vcc ou são SPI (pesquisar no site do arduino)


//Teclado
//  PS2Keyboard keyboard;                                                           

//LCD
LiquidCrystal lcd(3, 4, 5, 6, 7, 8);  // Pinos do LCD (RS,Enable,D4,D5,D6,D7)

//Declaração das variáveis do replace dentro da flash, de forma a economizar cerca de 800 bytes. Indispensável para o funcionamento no UNO
char buffer_um[11],buffer_dois[14];

//LADO ESQUERDO
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


//LADO DIREITO
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




//Variáveis
char Sil[6];
String  frase,Ssil;  
int i, s;
char c;

void setup(){
  Serial.begin(115200);
  SdPlay.setSDCSPin(10); // pino CS = 10
  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines
  lcd.clear();
//  keyboard.begin(A1,2); // Inicialização do teclado (DataPin, IRQpin)
  if (!SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER )){ //Configuração do SimpleSDAudio
    {lcd.print(F("erro do SD!"));}
    while(1);
   }
   
}
  


  
void loop() { 
  //Iniciando o LCD
  lcd.setCursor(0,0); //Start at character 0 on line 0
  lcd.noAutoscroll();
  lcd.clear();
  lcd.print(F("Digite uma frase"));

/*
 //varredura do teclado até pressonar enter
 // 13 = enter ;  127 = backspace
while(!keyboard.available());
  lcd.clear();
  lcd.setCursor(16,1);
  lcd.autoscroll();
  c=127;
  while(c!=13){  
    if (keyboard.available()) {
    c = keyboard.read();
    if(c==127){
      lcd.noAutoscroll();
      lcd.clear();
      lcd.setCursor(16,1);
      lcd.autoscroll();
      frase="";
    }
    else if(c!=13){
      lcd.write(c);
      frase=frase+c;
    }  
  }
  }
  */
  
  
  while(!Serial.available()) ;
  String frase = Serial.readString();
  
  //Separando a frase
  frase.toUpperCase();  //Deixar a frase toda em caixa alta
  frase = separar(frase);
Serial.println(frase);

   //Reprodução dos fonemas a partir da frase separada
   for(i=0; i<=frase.length(); i++){
     if(frase.charAt(i)=='-' || i=='\0' || frase.charAt(i)==' '){
       Ssil=Ssil+".AFM";  //Adiciona o formato do arquivo
       for(s=0;s<=Ssil.length();s++){  //Transformação da string com o fonema para char
         Sil[s]=Ssil.charAt(s); 
       }       
       SdPlay.setFile(Sil);  //Escolhe o arquivo a ser executado
       Serial.println(Sil);
      Serial.println(Ssil);  
       SdPlay.play(); //Reproduz o arquivo escolhido
       while(!SdPlay.isStopped()); //Para a execução do programa até o arquivo terminar de ser reproduzido
       Ssil="";
       strcpy_P(Sil, "");
       delay(10); // Sem esse delay, ocorre bugs
     }
     else Ssil=Ssil+frase.charAt(i);  //Guardando parte da string (um fonema) em outra string
   }   

    
    frase="";
}



  
String separar(String input){     //Função: separa a frase em sílabas a serem pronunciadas pelo sintetizador
    String frase_separada = "";
    for( i=0 ; i<input.length() ; i++){   //Loop: analisa todas as letras da frase digitada
          frase_separada += input.charAt(i);   //coloca a letra analisada na string da frase separada
          char proxima = input.charAt(i + 1);
          if(input.length() <= i + 1 || input.charAt(i + 1) == ' ') continue;   //Se a letra analisada for a ultima da palavra, será incluida na string e não será analisada
          else if(pertence(input.charAt(i), "RLMNSPCB") && input.length() > i && !IsVogal(proxima)) {  //Casos especiais de separação silábica
                char proxima = input.charAt(i + 1);
                switch(input.charAt(i)){                
                  case 'R':
                    if(proxima != 'R') frase_separada += '-';  // Inclui o segundo R na mesma sílaba. Ex: Barganhar = Bar-ga-nhar
                    break;
                  case 'L':
                    if(proxima != 'H') frase_separada += '-'; //Une as letas L e H na mesma sílaba. Ex: Baralho = Ba-ra-lho
                    break;
                  case'N':
                    if(proxima != 'H') frase_separada += '-'; //Une as letras N e H na mesma sílaba. Ex: Engenharia = En-ge-nha-ri-a
                    break;
                  case 'S':
                    if(proxima != 'S') frase_separada += '-'; // Inclui o segundo S na mesma sílaba. Ex: Assassino = A-ssa-ssi-no
                    break;                    
                  case 'M':
                    frase_separada += '-'; //Termina a vogal depois do M, se depois do M tiver consoante. Ex: 
                    break;
                  case 'P':
                    if(!pertence(proxima, "LRS")) frase_separada += '-'; //Une o P com L, R ou S. Ex: Plagio = Pla-gi-o
                    break;
                  case 'C':
                    if(!pertence(proxima, "HLR")) frase_separada += '-'; //Une C com H, L, R ou S. Ex: Crase = Sacramento = Sa-cra-men-to
                    break;  
                  case 'B':
                    if(!pertence(proxima, "LRS")) frase_separada += '-'; //Ube B com L, R ou S. Ex: Problema = Pro-ble-ma
                    break; //Porque o s pelo amor de deus
            }
          } else if(IsVogal(input.charAt(i))){
            if(!pertence(proxima, "RLMNSZ")||IsVogal(proxima)){  //termina a sílaba se a letra analisada for vogal, mas a próxima letra não é R,L,M,N ou S
              frase_separada += '-';
            }
            else if(input.length()>i+2){
              if(IsVogal(input.charAt(i+2))) frase_separada += '-';
              else{
                switch(proxima){
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

 frase_separada = " " + frase_separada;
 /* Using the string table in program memory requires the use of special functions to retrieve the data.
     The strcpy_P function copies a string from program space to a string in RAM ("buffer"). 
     Make sure your receiving string in RAM  is large enough to hold whatever
     you are retrieving from program space. */
  for (i=0 ; i<=42 ; i++)
  {
    strcpy_P(buffer_um, (char*)pgm_read_word(&(rep_esq[i]))); // Necessary casts and dereferencing, just copy. 
    strcpy_P(buffer_dois, (char*)pgm_read_word(&(rep_dir[i]))); // Guarda a string que está na memória flash no buffer 
    frase_separada.replace(buffer_um,buffer_dois); // replace a partir de constantes da memoria flash
  } 
    
   
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
 
 

