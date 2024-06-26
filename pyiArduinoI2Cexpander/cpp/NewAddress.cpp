// Данный пример меняет адрес модуля на указанный в argv[1].        // * Строки со звёздочкой являются необязательными.
                                                                    //
                                                                    //
#include <iostream>                                                 // 
#include "../iarduino_I2C_Expander.h"                                  //   Подключаем библиотеку для работы с расширителем выводов.
iarduino_I2C_Expander gpio;                                         //   Объявляем объект gpio для работы с функциями и методами библиотеки iarduino_I2C_Expander.
                                                                    //   Если при объявлении объекта указать адрес, например, gpio(0xBB), то пример будет работать с тем модулем, адрес которого был указан.
int main(int argc, char** argv){                                    //
  if (argc < 2) {
    std::cout << "Недостаточно аргументов.\
      Для работы с программой введите: " << argv[0] <<\
      " <новый_адрес_модуля>" << '\n';
    goto exit;
  }
  if (gpio.begin()){                                                //   Инициируем работу с расширителем выводов.
    std::cout << "На шине I2C найден модуль с адресом 0x";          //
    std::cout << std::hex << int(gpio.getAddress());                //   Выводим текущий адрес модуля.
    std::cout << " который является расширителем выводов\n";        //
      if (gpio.changeAddress(atoi(argv[1]))){                          //   Меняем адрес модуля на newAddress.
        std::cout << "Адрес модуля изменён на 0x";                  //
        std::cout << std::hex << int(gpio.getAddress()) << '\n';    //   Выводим текущий адрес модуля.
      } else {                                                      //
        std::cout << "Адрес модуля изменить не удалось!" << '\n';   //
      }                                                             //
  } else {                                                          //
    std::cout << "Расширитель выводов не найден!" << '\n';          //
  }                                                                 //
exit:
  return 1;
}                                                                   //
                                                                    //
//  ПРИМЕЧАНИЕ:                                                     //
//  Данный скетч демонстрирует не только возможность смены адреса   //
//  на указанный в переменной newAddress, но и обнаружение, и вывод //
//  текущего адреса модуля на шине I2C.                             //
