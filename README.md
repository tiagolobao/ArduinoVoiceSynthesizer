# ArduinoVoiceSynthesizer
A Voice Synthesizer that uses, an Arduino, an amplifier and a SD Card

Um sintetizador de voz que utiliza um Arduino, um amplificador, e um cartão SD. Esse projeto veio de uma atividade de Pesquisa e Extensão que tem como objetivo gerar tecnologias assistivas de baixo custo.

Para explicações do código, leia o Wiki

-----------Pastas----------
  -> Code (Código)
  Essa pasta contém arquivos zip das bibliotecas usadas no projeto e a sketch arduino.
  -> Docs (Documentos)
  Contém todas os documentos envolvidos no projeto como listagem das sílabas e justificativas sociais
  -> PCI (Placa de circuito impresso)
  Contém todas os arquvios de squemático e board (Eagle). Próxima versão virá com Protoboard (Fritzing)
  -> Audio
  Contém todos os arquivos de audio .wav
  
---------Autores-----------
Grupo PET-Elétrica.
Líder: Tiago Lobão
Contibuições no código: Victor Hugo Magalhães, Vitor Invenção, Ryan Teixeira, Péricles Oliveira.
Contribuições do protótipo: Rafael Matos.

---------BUGS----------
Essa versão ainda é beta e contém alguns bugs a serem corrigidos antes de ser construído.
1 - Um cartão SD possui um limite de arquivos gravados no diretório root. Possivelmente necessita de uma modificação no código da biblioteca "SimpleSDAudio" para os audios serem guardados em uma pasta específica.
2 - A amplificação não funciona muito bem. Ele foi pegado do site: "http://www.tecmundo.com.br/area-42/38717-area-42-como-fazer-um-amplificador-de-som-portatil-video-.htm"
3 - A separação das sílabas não está perfeita. A ideia é ir incrementando a partir das necessidades.

  
