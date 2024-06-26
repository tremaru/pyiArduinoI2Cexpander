# Данный пример меняет физическую схему выходов модуля.
                                        # $ Строки со знаком $ являются необязательными.
from pyiArduinoI2Cexpander import *     #   Подключаем модуль для работы с расширителем выводов.
from time import sleep                  #   Импортируем функцию ожидания из модуля времени 
ext = pyiArduinoI2Cexpander(0x08)       #   Объявляем объект ext для работы с функциями модуля pyiArduinoI2Cexpander, указывая адрес модуля на шине I2C.
                                        #   Если объявить объект без указания адреса (pyiArduinoI2Cexpander()), то адрес будет найден автоматически.
ext.pinMode(0, OUTPUT, DIGITAL)         # $ Конфигурируем вывод 0 на работу в качестве цифрового выхода.
ext.pinMode(1, OUTPUT, DIGITAL)         # $ Конфигурируем вывод 1 на работу в качестве цифрового выхода.
ext.pinMode(2, OUTPUT, ANALOG)          # $ Конфигурируем вывод 2 на работу в качестве аналогового выхода.
ext.pinMode(3, OUTPUT, ANALOG)          # $ Конфигурируем вывод 3 на работу в качестве аналогового выхода.
ext.pinOutScheme(0, OUT_PUSH_PULL)      # $ Конфигурируем выход 0 на работу по двухтактной схеме.
ext.pinOutScheme(1, OUT_OPEN_DRAIN)     #   Конфигурируем выход 1 на работу по схеме с общим стоком.
ext.pinOutScheme(2, OUT_PUSH_PULL)      # $ Конфигурируем выход 2 на работу по двухтактной схеме.
ext.pinOutScheme(3, OUT_OPEN_DRAIN)     #   Конфигурируем выход 3 на работу по схеме с общим стоком.
#ext.pinPull(1, PULL_UP)                #   Раскомментируйте строку для подтяжки вывода 1 до уровня Vcc.
#ext.pinPull(3, PULL_UP)                #   Раскомментируйте строку для подтяжки вывода 3 до уровня Vcc.
                                        #
print("Проверяем выводы. "              # 
      "Нажмите ctrl+c для выхода")      #
while True:                             # 
  ext.digitalWrite(0, HIGH)             #   Устанавливаем высокий логический уровень на выводе 0.
  ext.digitalWrite(1, HIGH)             #   Устанавливаем высокий логический уровень на выводе 1.
  ext.analogWrite (2, 4094)             #   Устанавливаем максимальный аналоговый уровень на выводе 2.
  ext.analogWrite (3, 4094)             #   Устанавливаем максимальный аналоговый уровень на выводе 3.
  sleep(.5)                             #   Ждём пол секунды.
  ext.digitalWrite(0, LOW)              #   Устанавливаем низкий логический уровень на выводе 0.
  ext.digitalWrite(1, LOW)              #   Устанавливаем низкий логический уровень на выводе 1.
  ext.analogWrite (2, 1  )              #   Устанавливаем минимальный аналоговый уровень на выводе 2.
  ext.analogWrite (3, 1  )              #   Устанавливаем минимальный аналоговый уровень на выводе 3.
  sleep(.5)                             #   Ждём полсекунды.
                                        #
#  ПРИМЕЧАНИЕ:                                                     #
#  Для проверки работы скетча подключите 4 светодиода к выводам.   #   Двухтактная схема подключает к выходу либо Vcc, либо GND.
#  Если светодиоды подключить анодами к выводам модуля, а катодами #   Схема с общим стоком либо подключает, либо отключает GND.
#  к выводу GND, то светодиоды на выводах 0 и 2 будут работать,    #
#  а светодиоды подключённые к выводам 1 и 3 работать не будут.    #
#  Для того что бы заработали светодиоды на 1 и 3 выводах модуля   #
#  эти выводы нужно подтянуть до уровня Vcc, это можно сделать     #
#  с помощью функции pinPull() или установив внешние подтягивающие #
#  резисторы, при этом Вы можете задать логический уровень выхода. #
#  Яркость свечения светодиодов через резисторы резко снизится.    #
