# Tarefa_AnimacoesEmLeds5x5_U4C3
Tarefa referente à configuração de teclado matricial para combinar animações utilizando a matriz de Leds 5x5 do BitDogLab.

Participantes 

# Tarefa de animações utilizando matriz de LEDs 5x5 e teclado matricial 4x4

Este projeto utiliza o simulador de eletrônica Wokwi, juntamente com o Visual Studio Code, utilizados para implementar as teclas de um teclado matricial 4x4 para controlar animações em uma matriz de LEDs RGB 5x5, utilizando o microcontrolador RP2040 presente na Raspberry Pi Pico W que é integrada à placa didática BitDogLab.

## Link do vídeo da atividade 2.

A colocar

## Funcionalidades

- Animações da **matriz de LEDs 5x5** para cada tecla do teclado 4x4.
- Acionamento do **buzzer** para emissão de sinal sonoro na animação.

## Componentes Simulados

1. **Teclado matricial 4x4**.
2. **Matriz de LEDs RGB 5x5**.
3. **Buzzer**.
4. **Placa Raspberry Pi Pico W**.

## Dependências do Projeto

Para desenvolver o projeto foram necessários os seguintes recursos e ferramentas:

1. **Ambiente de Desenvolvimento**:
   - **Visual Studio Code (VS Code)** configurado com:
     - Extensão do **Wokwi**.
     - Configuração do **Pico SDK**.

2. **Simulador Wokwi**: 
   - O [Wokwi](https://wokwi.com) deve ser integrado ao ambiente de desenvolvimento **VS Code** para realizar a simulação e execução dos códigos.

3. **Kit de Desenvolvimento Pico SDK**:
   - Configurado para compilar e carregar os códigos em C para a simulação da placa Raspberry Pi Pico W.

---

## Desenvolvedores 

- [Arilson Oliveira](https://github.com/ArilsonOliveira)
- [Ísis Menezes](https://github.com/intermediatesystemis)
- [Jacson Santos](https://github.com/jhacksonh)
- [João Sacerdote](https://github.com/JoaogSacerdote)
- [Lucas Silva](https://github.com/silvaluccs)
- [Luiz Rosario](https://github.com/luizzrosario)
- [Mateus Cavalcanti](https://github.com/mateusjrcavalcanti)

---

## Configuração de Hardware

### Pinos Definidos

- **Matriz de LEDs RGB 5x5**: GPIO 7
- **Buzzer**: GPIO 21
- **Teclado Matricial**:
  - Colunas: GPIOs 4, 8, 9 e 16
  - Linhas: GPIOs  17, 18, 19 e 20

---

## Estrutura do Projeto 

```plaintext

├── includes                
│   ├── draws
|   |   ├── chuva.h
|   |   ├── colorico.h
|   |   ├── contagem.h
|   |   ├── embarcatech.h
|   |   ├── girafa.h
|   |   ├── ledsBrancos.h
|   |   ├── leds_verde.h
|   |   ├── pacman.h
|   |   ├── pato.h
|   |   ├── raio.h
|   |   ├── rosto.h
|   ├── utils
|   |   ├── buzzer.h
|   |   ├── configGpios.h
|   |   ├── leds.h
|   |   ├── tecladoMatricial4x4.h
├── pios
├── src
|   ├── draws
|   |   ├── chuva.c
|   |   ├── colorico.c
|   |   ├── contagem.c
|   |   ├── embarcatech.c
|   |   ├── girafa.c
|   |   ├── ledsBrancos.c
|   |   ├── leds_verde.c
|   |   ├── pacman.c
|   |   ├── pato.c
|   |   ├── raio.c
|   |   ├── rosto.c
|   ├── utils
|   |   ├── buzzer.c
|   |   ├── configGpios.c
|   |   ├── leds.c
|   |   ├── tecladoMatricial4x4.c
├── .gitignore
├── CMakeLists.txt
├── README.md
├── diagram.json
├── libraries.txt
├── main.c
├── pico_sdk_import.cmake
├── wokwi-project.txt
├── wokwi.toml             
```

---

## Estrutura do Código

### Bibliotecas Utilizadas

- `stdio.h`: Entrada e saída padrão para debug.
- `pico/stdlib.h`: Biblioteca padrão da Raspberry Pi Pico.
- `hardware/pwm.h`: Para controle de PWM (usado no buzzer).
- `hardware/clocks.h`: Para configuração do clock.
- Bibliotecas específicas:
  - `configGpios.h`: Configuração dos pinos GPIO.
  - `tecladoMatricial4x4.h`: Funções para o teclado matricial.
  - `leds.h`: Controle de LEDs.
  - `buzzer.h`: Controle do buzzer.
  - `pacman.h`, `colorido.h`, `rosto.h`, `pato.h`, `girafa.h`, `chuva.h`, `embarcatech.h`, `contagem.h`, `ledsBrancos.h`, `raio.h` e `leds_verde.h`: Implementações relacionadas a teclas específicas para executar animação na matriz de LEDs.

---

## Principais Funções

### 1. `main()`: Controle Principal

- Inicializa periféricos e entra em um loop contínuo para monitorar o teclado.
- Ações baseadas nas teclas pressionadas:
  - **Tecla `0`**: Mostra uma animação de contagem de 1 a 5.
  - **Tecla `1`**: Faz uma animação de chuva de pixels.
  - **Tecla `2`**: Mostra animação da palavra "embarcatech" deslizando para a esquerda.
  - **Tecla `3`**: Faz a animação de um raio.
  - **Tecla `4`**: Mostra a animação do Pacman juntamente com o som do jogo e os fantasmas do jogo. 
  - **Tecla `5`**: 
  - **Tecla `6`**: Mostra um rosto feliz e um rosto triste.
  - **Tecla `7`**: Faz a animação de girafas passando.     
  - **Tecla `8`**: Faz a animação de patos em um lago.
  - **Tecla `9`**: São mostradas diferentes cores na matriz de LEDs.
   - **Tecla `A`**: .
  - **Tecla `B`**:  Todos os LEDs são ligados na cor azul, 
   no nível de intensidade de 100% da luminosidade máxima .
  - **Tecla `C`**: Todos os LEDs são ligados na cor vermelha, 
   no nível de intensidade de 80% da luminosidade máxima.
  - **Tecla `D`**: Todos os LEDs são ligados na cor verde, 
   no nível de intensidade de 50% da luminosidade máxima.
  - **Tecla `#`**: Faz animação de cascata com os LEDs na cor branca.
  - **Tecla `*`**: Aplica reboot para modo de gravação.
    
---

### 2. `controlar_leds()`: Controlar LEDs

Essa função tem como objetivo controlar os LEDs RGB (vermelho, verde e azul) conectados à matriz de LEDs 5x5. Ela permite acionar ou desligar cada cor de LED de forma independente.

### 3. Funções para Controle do Buzzer

Este conjunto de funções permite controlar um buzzer conectado ao microcontrolador para tocar notas musicais utilizando PWM (Pulse Width Modulation). As funções permitem acionar o buzzer, controlar a frequência das notas e a duração das mesmas.

#### **1. Função: `controlar_buzzer()`**

Esta função ativa ou desativa o buzzer utilizando PWM.

#### **2. Função: `tocar_nota()`**

Essa função é responsável por gerar uma nota musical no buzzer, configurando sua frequência e duração, utilizando PWM (Pulse Width Modulation).

#### **3. Função: `tocar()`**

Essa função é responsável por tocar uma sequência de notas musicais em um buzzer, utilizando a função `tocar_nota` para gerar cada nota com base na frequência e na duração fornecidas.

### 4. `detectar_tecla()`: Controlar o teclado matricial

Essa função é responsável por detectar qual tecla foi pressionada em um teclado matricial 4x4. Ela percorre as linhas e colunas do teclado, verificando se uma tecla foi acionada, e retorna o caractere correspondente à tecla pressionada.

### 5. `inicializar_perifericos()`: Inicializar periféricos

Essa configura os periféricos utilizados no sistema, como LEDs (vermelho, verde e azul), o buzzer, e as linhas e colunas de um teclado matricial. Além disso, configura a frequência de operação do buzzer e as funcionalidades dos pinos associados.

