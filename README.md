#  Projeto: Simulador de Sistema Solar Inteligente com LCD I2C

Este projeto simula o funcionamento de um sistema de energia solar utilizando Arduino, com o objetivo de representar, de forma simplificada, como a geração de energia pode ser monitorada e controlada automaticamente com base na intensidade da luz solar.
link do wokwi: https://wokwi.com/projects/434037762993451009
---

##  Funcionalidades

- Leitura da **intensidade solar** por meio de um potenciômetro.
- Verificação automática da viabilidade de carregamento com base em um **limiar mínimo**.
- Exibição de mensagens dinâmicas em um **display LCD 20x4** via comunicação **I2C**.
- Indicação visual do carregamento por meio de um **LED**.
- Simulação de estados do sistema: **carregando**, **desligado por baixa luz**, e **modo noturno**.

---

##  Componentes Utilizados

- Arduino Uno (simulador ou físico)
- Potenciômetro (simula intensidade solar)
- LCD 20x4 com interface I2C
- LED (indicador de carregamento)
- Resistores e fios de conexão

---

##  Conexões

| Componente        | Pino no Arduino |
|-------------------|-----------------|
| Potenciômetro SIG | A0              |
| LED               | D9              |
| LCD I2C SDA       | A4              |
| LCD I2C SCL       | A5              |
| LCD I2C VCC       | 5V              |
| LCD I2C GND       | GND             |

---

##  Lógica de Funcionamento

1. O Arduino lê o valor do potenciômetro (0 a 1023).
2. Se o valor for maior que **500**, o sistema considera que há luz suficiente:
   - O LED é aceso.
   - O LCD exibe mensagens de carregamento e status ideal.
3. Se o valor for **0**, o sistema entra em **modo noturno**.
4. Caso contrário, indica que a luz é insuficiente e o sistema permanece desligado.

---

##  Visualização no LCD

As seguintes mensagens são mostradas dinamicamente:

- Nível de luz atual.
- Estado do sistema:
  - `CARREGANDO`
  - `DESLIGADO`
  - `MODO NOTURNO`
- Indicadores de condição da luz (ideal ou insuficiente).

---
