# Данный пример меняет логические уровни на выводе модуля.        # * Строки со звёздочкой являются необязательными.
                                                                  #
from pyiArduinoI2Cexpander import *                               #   Подключаем библиотеку для работы с расширителем выводов.
from time import sleep                                            # 
gpio = pyiArduinoI2Cexpander(0x09)                                #   Объявляем объект gpio для работы с функциями и методами библиотеки iarduino_I2C_Expander, указывая адрес модуля на шине I2C.
                                                                  #   Если объявить объект без указания адреса (iarduino_I2C_Expander gpio ), то адрес будет найден автоматически.
gpio.pinMode(7, OUTPUT, DIGITAL)                                  # * Конфигурируем вывод 7 на работу в качестве цифрового выхода.
print("Моргаем светодиодом. Нажмите ctrl+c для выхода")           #
while True:                                                       # 
  gpio.digitalWrite(7, HIGH)                                      #   Устанавливаем высокий логический уровень на выводе 7.
  sleep(.5)                                                       #   Ждём пол секунды.
  gpio.digitalWrite(7, LOW)                                       #   Устанавливаем низкий логический уровень на выводе 7.
  sleep(.5)                                                       #   Ждём пол секунды.
                                                                  #
#  ПРИМЕЧАНИЕ:                                                    #
#  Для проверки работы скетча подключите светодиод к 7 выводу.    #
