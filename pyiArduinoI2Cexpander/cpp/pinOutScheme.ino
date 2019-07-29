// Данный пример меняет физическую схему выходов модуля.            // * Строки со звёздочкой являются необязательными.
                                                                    //
#include <Wire.h>                                                   // * Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <iarduino_I2C_Expander.h>                                  //   Подключаем библиотеку для работы с расширителем выводов.
iarduino_I2C_Expander gpio(0x09);                                   //   Объявляем объект gpio для работы с функциями и методами библиотеки iarduino_I2C_Expander, указывая адрес модуля на шине I2C.
                                                                    //   Если объявить объект без указания адреса (iarduino_I2C_Expander gpio;), то адрес будет найден автоматически.
void setup(){                                                       //
    delay(500);                                                     // * Ждём завершение переходных процессов связанных с подачей питания.
//  Готовим модуль к работе:                                        //
    gpio.begin();                                                   //   Инициируем работу с расширителем выводов.
    gpio.pinMode(0, OUTPUT, DIGITAL);                               // * Конфигурируем вывод 0 на работу в качестве цифрового выхода.
    gpio.pinMode(1, OUTPUT, DIGITAL);                               // * Конфигурируем вывод 1 на работу в качестве цифрового выхода.
    gpio.pinMode(2, OUTPUT, ANALOG);                                // * Конфигурируем вывод 2 на работу в качестве аналогового выхода.
    gpio.pinMode(3, OUTPUT, ANALOG);                                // * Конфигурируем вывод 3 на работу в качестве аналогового выхода.
    gpio.pinOutScheme(0, OUT_PUSH_PULL);                            // * Конфигурируем выход 0 на работу по двухтактной схеме.
    gpio.pinOutScheme(1, OUT_OPEN_DRAIN);                           //   Конфигурируем выход 1 на работу по схеме с общим стоком.
    gpio.pinOutScheme(2, OUT_PUSH_PULL);                            // * Конфигурируем выход 2 на работу по двухтактной схеме.
    gpio.pinOutScheme(3, OUT_OPEN_DRAIN);                           //   Конфигурируем выход 3 на работу по схеме с общим стоком.
//  gpio.pinPull(1, PULL_UP);                                       //   Раскомментируйте строку для подтяжки вывода 1 до уровня Vcc.
//  gpio.pinPull(3, PULL_UP);                                       //   Раскомментируйте строку для подтяжки вывода 3 до уровня Vcc.

}                                                                   //
                                                                    //
void loop(){                                                        //
    gpio.digitalWrite(0, HIGH);                                     //   Устанавливаем высокий      логический уровень на выводе 0.
    gpio.digitalWrite(1, HIGH);                                     //   Устанавливаем высокий      логический уровень на выводе 1.
    gpio.analogWrite (2, 4094);                                     //   Устанавливаем максимальный аналоговый уровень на выводе 2.
    gpio.analogWrite (3, 4094);                                     //   Устанавливаем максимальный аналоговый уровень на выводе 3.
    delay(500);                                                     //   Ждём пол секунды.
    gpio.digitalWrite(0, LOW);                                      //   Устанавливаем низкий       логический уровень на выводе 0.
    gpio.digitalWrite(1, LOW);                                      //   Устанавливаем низкий       логический уровень на выводе 1.
    gpio.analogWrite (2, 1  );                                      //   Устанавливаем минимальный  аналоговый уровень на выводе 2.
    gpio.analogWrite (3, 1  );                                      //   Устанавливаем минимальный  аналоговый уровень на выводе 3.
    delay(500);                                                     //   Ждём пол секунды.
}                                                                   //
                                                                    //
//  ПРИМЕЧАНИЕ:                                                     //
//  Для проверки работы скетча подключите 4 светодиода к выводам.   //   Двухтактная схема подключает к выходу либо Vcc, либо GND.
//  Если светодиоды подключить анодами к выводам модуля, а катодами //   Схема с общим стоком либо подключает, либо отключает GND.
//  к выводу GND, то светодиоды на выводах 0 и 2 будут работать,    //
//  а светодиоды подключённые к выводам 1 и 3 работать не будут.    //
//  Для того что бы заработали светодиоды на 1 и 3 выводах модуля   //
//  эти выводы нужно подтянуть до уровня Vcc, это можно сделать     //
//  с помощью функции pinPull() или установив внешние подтягивающие //
//  резисторы, при этом Вы можете задать логический уровень выхода. //
//  Яркость свечения светодиодов через резисторы резко снизится.    //
