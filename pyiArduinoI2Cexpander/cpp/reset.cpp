// Данный пример демонстрирует программную перезагрузку модуля.     // * Строки со звёздочкой являются необязательными.
                                                                    //
#include "../iarduino_I2C_Expander.h"                               //   Подключаем библиотеку для работы с расширителем выводов.
iarduino_I2C_Expander gpio(0x09);                                   //   Объявляем объект gpio для работы с функциями и методами библиотеки iarduino_I2C_Expander, указывая адрес модуля на шине I2C.
                                                                    //   Если объявить объект без указания адреса (iarduino_I2C_Expander gpio;), то адрес будет найден автоматически.
int main(){                                                         //
//Готовим модуль к работе:                                          //
  gpio.begin();                                                     //   Инициируем работу с расширителем выводов.
  gpio.pinMode(3, OUTPUT, ANALOG);                                  // * Конфигурируем вывод 3 на работу в качестве аналогового выхода.
  gpio.analogWrite(3, 2047);                                        //   Устанавливаем на 3 выводе уровень равный половине от максимума.
  delay(2000);                                                      //   Ждём две секунды.
  gpio.reset();                                                     //   Перезагружаем модуль.
}                                                                   //
                                                                    //
//  ПРИМЕЧАНИЕ:                                                     //
//  Для проверки работы скетча подключите светодиод к 3 выводу.     //
//  Сконфигурировав вывод №3 в режим аналогового выхода и подав на  //
//  него аналоговый уровень, светодиод включится. Но через две сек. //
//  после его включения произойдёт перезагрузка модуля и все выводы //
//  переконфигурируются в значение по умолчанию (цифровые входы),   //
//  что приведёт к исчезновению аналогового уровня с вывода №3 и,   //
//  как следствие, отключению светодиода.                           //
