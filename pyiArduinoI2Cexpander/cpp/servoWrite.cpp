// Данный пример позволяет устанавливать угол сервопривода.         // * Строки со звёздочкой являются необязательными.
                                                                    //
#include "iarduino_I2C_Expander.h"                                  //   Подключаем библиотеку для работы с расширителем выводов.
iarduino_I2C_Expander gpio(0x09);                                   //   Объявляем объект gpio для работы с функциями и методами библиотеки iarduino_I2C_Expander, указывая адрес модуля на шине I2C.

void loop(void);
                                                                    //   Если объявить объект без указания адреса (iarduino_I2C_Expander gpio;), то адрес будет найден автоматически.
int main(){                                                         //
//Готовим модуль к работе:                                          //
  gpio.begin();                                                     //   Инициируем работу с расширителем выводов.
  gpio.pinMode(3, OUTPUT, SERVO);                                   // * Конфигурируем вывод 3 на работу в качестве выхода для сервопривода.
  loop();
}                                                                   //
                                                                    //
void loop(){                                                        //
  while(1){
    gpio.servoWrite(3, 0);                                          //   Поворачиваем сервопривод в угол 0°.
    delay(500);                                                     //   Ждём пол секунды.
    gpio.servoWrite(3, 90);                                         //   Поворачиваем сервопривод в угол 90°.
    delay(500);                                                     //   Ждём пол секунды.
    gpio.servoWrite(3, 180);                                        //   Поворачиваем сервопривод в угол 180°.
    delay(500);                                                     //   Ждём пол секунды.
  }
}                                                                   //
                                                                    //
//  ПРИМЕЧАНИЕ:                                                     //
//  Для проверки работы скетча подключите сервопривод к 3 выводу.   //
//  По умолчанию библиотека работает с сервоприводами у которых     //
//  угол поворота равен 180°. Для работы с другими сервоприводами   //
//  задайте их параметры используя функцию servoAttach().           //
//  Управление сервоприводами осуществляется с помощью сигнала ШИМ. //
//  Обращение к функции servoWrite() приводит к смене частоты ШИМ   //
//  в значение 50 Гц на всех выводах поддерживающих ШИМ: 0,1,2,3.   //
//  Значит если сконфигурировать любой другой вывод, поддерживающий //
//  ШИМ, на работу в качестве аналогового выхода, его сигнал так же //
//  снизится до 50 Гц.                                              //