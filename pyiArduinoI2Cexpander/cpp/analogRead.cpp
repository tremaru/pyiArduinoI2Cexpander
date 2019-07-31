// Данный пример читает аналоговый уровень с вывода модуля.         // * Строки со звёздочкой являются необязательными.
                                                                    //
#include "iarduino_I2C_Expander.h"                                  //   Подключаем библиотеку для работы с расширителем выводов.
#include <iostream>
#include <string>
iarduino_I2C_Expander gpio(0x09);                                   //   Объявляем объект gpio для работы с функциями и методами библиотеки iarduino_I2C_Expander, указывая адрес модуля на шине I2C.
                                                                    //   Если объявить объект без указания адреса (iarduino_I2C_Expander gpio;), то адрес будет найден автоматически.
void loop();

int main(){                                                         //
  delay(500);                                                       // * Ждём завершение переходных процессов связанных с подачей питания.
//Готовим модуль к работе:                                          //
  gpio.begin();                                                     //   Инициируем работу с расширителем выводов.
  gpio.pinMode(4, INPUT, ANALOG);                                   // * Конфигурируем вывод 4 на работу в качестве аналогового входа.
  loop();
}                                                                   //
                                                                    //
void loop(){                                                        //
  while(1){
    uint16_t pin4 = gpio.analogRead(4);                             //   Читаем аналоговый уровень с вывода №4 в переменную «pin4».
    std::cout << "Pin_4="+std::to_string(pin4) << '\n';             //
    delay(100);                                                     // * Ждём десятую долю секунды, чтоб не захламлять stdout.
  }
}                                                                   //
                                                                    //
//  ПРИМЕЧАНИЕ:                                                     //
//  Для проверки работы скетча подключите потенциометр к 4 выводу.  //
//  Аналоговый уровень считывается из АЦП модуля и может принимать  //
//  значение от 0 (0В) до 4095 (3,3В).                              //
//  По умолчанию, значения АЦП усредняются, это подавляет скачки    //
//  показаний но увеличивает их инерционность, для отключения       //
//  или изменения усреднения обратитесь к функции analogAveraging() //
