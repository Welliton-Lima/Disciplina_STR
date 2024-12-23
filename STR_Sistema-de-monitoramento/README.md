# Simulador de Sistema de Monitoramento em Tempo Real para Poço de Gás e Óleo

Este projeto é um **simulador de sistema de monitoramento em tempo real** desenvolvido em **C++** utilizando o **FreeRTOS** para gerenciar as tarefas em tempo real.

---

## 🎯 Objetivo do Projeto

O sistema simula a operação em tempo real de sensores e controladores para:
- **Monitorar variáveis críticas**
- **Gerenciar alarmes** em situações de emergência.
- **Executar ações automatizadas** como desligamento de válvulas e controle de fluxo.
- **Exibir dados em tempo real** no terminal.

---

## 🛠️ Funcionalidades

- **Coleta e Processamento de Dados**:
  - Simulação de sensores com geração de valores em tempo real.
- **Gerenciamento de Tarefas**:
  - Uso do FreeRTOS para agendamento de tarefas periódicas.
- **Gestão de Alarmes**:
  - Detecção de condições críticas e acionamento de alarmes.
- **Simulação de Ações**:
  - Controle de atuadores como válvulas e bombas.
- **Visualização em Tempo Real**:
  - Dados exibidos no terminal para análise.

---

## 🚀 Como executar

### Pré-requisitos

1. **Visual Studio Code**:
   - Baixe e instale o [Visual Studio Code](https://code.visualstudio.com/).
   - Configure as extensões de C/C++.

2. **FreeRTOS**:
   - Baixe a última versão do [FreeRTOS](https://www.freertos.org/).
   - Inclua os arquivos necessários na pasta do projeto.

3. **Compilador C++**:
   - GCC ou qualquer compilador compatível com o ambiente configurado no VS Code.

4. **Código-fonte**:
   - Clone ou baixe este repositório:
     ```bash
     git clone https://github.com/Welliton-Lima/simulador-monitoramento-poco.git
     ```

---

### Passos para Configurar e Executar

1. **Configurar o ambiente**:

2. **Compilar o projeto**:

3. **Executar o simulador**:

---
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Hello World Example

Starts a FreeRTOS task to print "Hello World".

(See the README.md file in the upper level 'examples' directory for more information about examples.)

## How to use example

Follow detailed instructions provided specifically for this example. 

Select the instructions depending on Espressif chip installed on your development board:

- [ESP32 Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/stable/get-started/index.html)
- [ESP32-S2 Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/get-started/index.html)


## Example folder contents

The project **hello_world** contains one source file in C language [hello_world_main.c](main/hello_world_main.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt` files that provide set of directives and instructions describing the project's source files and targets (executable, library, or both). 

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── example_test.py            Python script used for automated example testing
├── main
│   ├── CMakeLists.txt
│   ├── component.mk           Component make file
│   └── hello_world_main.c
├── Makefile                   Makefile used by legacy GNU Make
└── README.md                  This is the file you are currently reading
```

For more information on structure and contents of ESP-IDF projects, please refer to Section [Build System](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html) of the ESP-IDF Programming Guide.

## Troubleshooting

* Program upload failure

    * Hardware connection is not correct: run `idf.py -p PORT monitor`, and reboot your board to see if there are any output logs.
    * The baud rate for downloading is too high: lower your baud rate in the `menuconfig` menu, and try again.

## Technical support and feedback

Please use the following feedback channels:

* For technical queries, go to the [esp32.com](https://esp32.com/) forum
* For a feature request or bug report, create a [GitHub issue](https://github.com/espressif/esp-idf/issues)

We will get back to you as soon as possible.
