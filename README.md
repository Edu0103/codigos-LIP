# Projetos de LIP
Códigos de LIP do Primeiro Período de Ciência da Computação PUC Minas


## Primeiro Projeto
    Semafóro desenvolvido no Tinkercad
 
[Link do Tinkercad do Primeiro Projeto](https://www.tinkercad.com/things/f7EutT0Msqc-atividadepraticalipentrega1)


---

## Segundo Projeto
[Link do Tinkercad do Segundo Projeto](https://www.tinkercad.com/things/aGBwLaMACdQ-segundoprojetolipeduardokairo?sharecode=Tf7oIhUKdS5-SgAp4PKof7lSQHyLcMjI9o6JHlQcX0k)


# Estufa Sustentável 🌿
**ODS 2: Fome Zero e Agricultura Sustentável**

## Integrantes
* **Eduardo Henrique Mendes Torres**
* **Kairo Viana de Paula**

---

## Problema Real
Muitas plantações sofrem com a falta de controle das condições ambientais, como temperatura, luminosidade e umidade do solo. Isso pode prejudicar o crescimento das plantas e causar desperdício de água, energia e recursos naturais.

Além disso, pequenos produtores nem sempre têm acesso a sistemas de monitoramento automatizados e sustentáveis.

---

## Descrição Técnica

### Componentes

**Entradas (Sensores)**
1.  **Sensor de temperatura:** Mede a temperatura interna da estufa.
2.  **Fotoresistor (Luminosidade):** Avalia a intensidade da luz solar no ambiente.
3.  **Sensor de umidade do solo:** Indica se o solo está seco ou úmido o suficiente para as plantas.
4.  **Sensor de proximidade:** Verifica se há algo se aproximando da plantação à noite.

**Saídas (Atuadores)**
1.  **Lâmpada:** Acende quando for noite e algo se aproximar.
2.  **Buzzer:** Emite som quando executa algum motor ou se algo se aproximar.
3.  **Motor:**
    * Ativa ventilação (se temperatura alta).
    * Rega automaticamente (se umidade baixa).

---

## Funcionamento do Sistema

O sistema opera com a seguinte lógica de automação:

* **Controle de Temperatura:** Se a temperatura ultrapassar **30°C**, o sistema de ventilação é ativado (motor).
* **Irrigação Inteligente:** Se a umidade do solo estiver baixa, o sistema de irrigação é ativado (motor).
* **Segurança:** Se for noite e o sensor de proximidade detectar algo, um sinal sonoro (buzzer) é emitido e as luzes acendem.
* **Alertas:** Quando o sistema de irrigação ou ventilação está ligado, um aviso sonoro é emitido.

---

##  Impacto Esperado

* **Aumento da produtividade:** Mantém condições ideais de cultivo sem supervisão constante.
* **Sustentabilidade:** Reduz o desperdício de água e energia, operando apenas quando necessário.
* **Acessibilidade:** Facilita o uso de tecnologia por pequenos produtores e hortas urbanas.
* **Conclusão:** O projeto promove uma produção de alimentos mais eficiente, autônoma e ambientalmente responsável.

---




## Terceiro Projeto
    Desenvolvimento de um estacionamento inteligente

## Quarto Projeto
    Jogo Simon Genius com Tinkercad
[Link do Tinkercad do Quarto Projeto](https://www.tinkercad.com/things/9JdulAaZWOB-projetosimongeniuslip?sharecode=PUGadxTMy5cJrOw8mx5o0BQT-qKsUPg0dYkqFXaNbgg)



## Quinto Projeto

# Estufa Sustentável (Arduino Shield)
**ODS 2: Fome Zero e Agricultura Sustentável**

Este projeto visa automatizar o monitoramento de estufas agrícolas, garantindo condições ideais de cultivo e economizando recursos naturais.

---

## Integrantes
* **Bruno Ricardo Resende Assis** 
* **Eduardo Henrique Mendes Torres** 
* **Henrique Pimenta Krueger** 
* **Kairo Viana de Paula** 

---

## O Problema
Muitas plantações sofrem com a falta de controle das condições ambientais (temperatura, luminosidade e umidade).Isso prejudica o crescimento das plantas e gera desperdício de água e energia. Pequenos produtores raramente têm acesso a tecnologias de monitoramento acessíveis.

---

## Descrição Técnica

### Hardware e Componentes
O projeto utiliza um **Arduino** com **Multi Function Shield**.

**Entradas (Sensores)**
* **Fotoresistor (LDR - A4):** Mede a intensidade da luz solar.
* **Sensor de Umidade do Solo (A5):** Indica se o solo precisa de rega.
* **Sensor de Proximidade (PIR - D9):** Detecta movimento para segurança.

**Saídas (Atuadores/Simulação)**
* **LED 1:** Indica detecção de presença (Segurança).
* **LED 2:** Indica solo seco (Sistema de Irrigação ativo).
* **LED 3:** Indica ambiente escuro (Iluminação artificial ativa).
* **Display/Serial:** Monitoramento em tempo real dos valores.

---

## Lógica de Funcionamento

1.  **Irrigação Automática:** Se a umidade do solo for menor que o limite (ex: 550), o sistema aciona a irrigação (simulado pelo LED 2).
2.  **Iluminação Inteligente:** Se a luminosidade natural baixar (ex: < 400), a luz artificial é ligada (simulado pelo LED 3).
3.  **Sistema de Segurança:** Se for detectado movimento, o sistema alerta (simulado pelo LED 1).

---