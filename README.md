
CONFIGURAÇÃO DO AMBIENTE
==========================

1) Baixe e instale o ambiente Arduino para seu sistema operacional.
   O seguinte URL leva a uma página que lhe diz como fazer isso.

   http://arduino.cc/en/Guide/HomePage

   Para o Debian, você pode apenas fazer um "apt-get install arduino".

2) Instale a versão mais recente da biblioteca Ethernet, contendo assíncrona
   soquetes (Asocket).
   a) Faça o download do arquivo zip "Ethernet.zip" de
      http://code.google.com/p/kegger/
   b) Descompacte o arquivo baixado arquivo, chamado "Ethernet.zip", de modo que o diretório
      "Ethernet" substitui o diretório correspondente no diretório onde o Arduino
      mantém suas bibliotecas.

3) Instale a biblioteca "Streaming", o que não é distribuído como padrão com o
   Software Arduino. A biblioteca vivo não é utilizado por si só Agentuino, mas é
   utilizado pela aplicação de demonstração.
   a) Baixe o arquivo de biblioteca (um arquivo zip) a partir de
      http://arduiniana.org/libraries/streaming/
   b) Descompacte o arquivo zip baixado em um diretório chamado "Streaming", dentro
      o diretório onde Arduino mantém suas bibliotecas (/ usr / share / arduino / bibliotecas
       no Linux).

4) Instale a biblioteca MemoryFree.h.
   a) O código fonte está no Arduino Playground:
      http://www.arduino.cc/playground/Code/AvailableMemory
   b) Faça um diretório "MemoryFree" no diretório onde Arduino mantém suas bibliotecas.
   c) Neste novo diretório, crie um arquivo "MemoryFree.h", que contém o código de
      a seção intitulada "MemoryFree.h:" na página web parque infantil.
   d) criar também um arquivo "MemoryFree.cpp", no mesmo diretório, que contém o código
      da seção intitulada "MemoryFree.cpp:" na página web parque infantil.
   e) Criar um subdiretório chamado "exemplos", dentro do diretório "MemoryFree".
   f) Criar um subdiretório chamado "freeMemory", dentro do diretório "exemplos".
   g) Neste novo diretório "freeMemory", crie um arquivo "FreeMemory.pde", contendo
      o código da seção intitulada "Exemplo esboço:" na página web parque infantil.

INSTALAÇÃO Argentino biblioteca a partir de SVN
====================================

5) Confira o repositório SVN agentuino

      svn checkout http://agentuino.googlecode.com/svn/trunk/ Agentuino

6) Instale a biblioteca, ligando o seu diretório de desenvolvimento Agentuino ser um sub
   diretório do diretório onde Arduino mantém suas bibliotecas
   (/ usr / share / arduino / bibliotecas no Linux).

7) Agora você pode desenvolver, em seu diretório home, como usuário regular. O Arduino
   ambiente não parecem gostar de escrever esboços para o exemplo da biblioteca
   diretórios, alegando que eles são, quando eles não são somente leitura. Daí você terá que
   use um editor de texto diferente para editar o código. Compilar e uploas-lo a partir do
   arduino ambiente, como para qualquer outro exemplo de esboço.

Alternativamente, você pode fazer o checkout do diretório Agentuino diretamente no diretório bibliotecas, mas então você está trabalhando fora de seu diretório home.


Instalação e execução de ESBOÇO DA AMOSTRA Argentino
=================================================

Execute o esboço amostra Agentuino selecionando a opção do menu
Arquivo> Exemplos> Agentuino> agente, de dentro do ambiente arduino, e enviá-lo


Testando o exemplo SNMP AGENTE
=============================

8) Instale a ferramenta snmpget de net-snmp (em Debian "apt-get install snmp")

9) Personalize o IP no exemplo esboço Agentuino.

10) Carregar o exemplo esboço Agentuino.

11) Executar uma consulta SNMP, por exemplo:
      snmpget -v -c 1 192.168.1.100 público 1.3.6.1.2.1.1.4.0
    A corda da comunidade, endereço IP e OID devem corresponder aos valores no código-fonte
    do exemplo esboço Agentuino.
12) No Agent_House_test_temp.ino altere os parametros de conexão do arduino com sua rede local, configure os OIDS seguindo o padrão abaixo :
static char sysHumSensor[] PROGMEM   = "1.3.6.1.2.1.1.9.0";  // read-only  (Integer)

a verificação do referido IOD

  if ( strcmp_P(oid, sysTempSensor ) == 0 ) {
      // handle sysDescr (set/get) requests
      if ( pdu.type == SNMP_PDU_SET ) {
        // response packet from set-request - object is read-only
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = SNMP_ERR_READ_ONLY;
      } else {
        // response packet from get-request - locDescr
        int chk = DHT11.read(DHT11PIN);
        Serial.println(DHT11.temperature);
        Serial.println(DHT11.humidity);
        status = pdu.VALUE.encode(SNMP_SYNTAX_INT, DHT11.temperature);
        pdu.type = SNMP_PDU_RESPONSE;
        pdu.error = status;
      }
      //
      #ifdef DEBUG
        Serial << F("Valor Temperatura ... ") << DHT11.temperature << F(" ") << pdu.VALUE.size << endl;
      #endif
    }
    
    Dúvidas jj.alvesneto92@gmail.com
