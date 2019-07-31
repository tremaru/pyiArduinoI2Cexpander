# Данный пример меняет адрес модуля на указанный в newAddress.     # * Строки со звёздочкой являются необязательными.
                                                                   #
from pyiArduinoI2Cexpander import *                                #   Подключаем библиотеку для работы с расширителем выводов.
import sys                                                         # 
from time import sleep                                             # 
gpio = pyiArduinoI2Cexpander()                                     #   Объявляем объект gpio для работы с функциями и методами библиотеки iarduino_I2C_Expander, указывая адрес модуля на шине I2C.
                                                                   #   Если при объявлении объекта указать адрес, например, gpio(0xBB), то пример будет работать с тем модулем, адрес которого был указан.
if len(sys.argv) < 2:                                              # 
  print("Недостаточно аргументов.\
  Для работы с программой введите: python3 " + sys.argv[0] +\
  " <новый_адрес_модуля>") 
elif gpio.begin():                                                 #   Инициируем работу с расширителем выводов.
  print("На шине I2C найден модуль с адресом ", end='')            #
  print(hex(gpio.getAddress()), end='')                            #   Выводим текущий адрес модуля.
  print(" который является расширителем выводов")                  #
  if gpio.changeAddress(int(sys.argv[1])):                         #   Меняем адрес модуля на newAddress.
    print("Адрес модуля изменён на ", end='')                      #
    print(hex(gpio.getAddress()))                                  #   Выводим текущий адрес модуля.
  else:                                                            #
    print("Адрес модуля изменить не удалось!")                     #
else:                                                              #
  print("Расширитель выводов не найден!")                          #
                                                                   #
#  ПРИМЕЧАНИЕ:                                                     #
#  Данный скетч демонстрирует не только возможность смены адреса   #
#  на указанный в переменной newAddress, но и обнаружение, и вывод #
#  текущего адреса модуля на шине I2C.                             #
