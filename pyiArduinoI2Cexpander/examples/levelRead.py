# Данный пример читает логический уровень с аналогового входа.     # * Строки со звёздочкой являются необязательными.
                                                                   #
from pyiArduinoI2Cexpander import *                                #   Подключаем библиотеку для работы с расширителем выводов.
from time import sleep                                             # 
gpio = pyiArduinoI2Cexpander()                                     #   Объявляем объект gpio для работы с функциями и методами библиотеки iarduino_I2C_Expander, указывая адрес модуля на шине I2C.
                                                                   #   Если объявить объект без указания адреса (gpio = iarduino_I2C_Expander()), то адрес будет найден автоматически.
gpio.pinMode(4, INPUT, ANALOG)                                     # * Конфигурируем вывод 4 на работу в качестве аналогового входа.
gpio.levelWrite(512)                                               #   Устанавливаем аналоговый уровень разделяющий уровень логического 0 от 1.
gpio.levelHyst (12)                                                # * Устанавливаем гистерезис аналогового уровня.
                                                                   #   В данном случае аналоговый сигнал от 512+12 до 4096 будет воспринят как 1.
                                                                   #                   аналоговый сигнал от 0 до 512-12 будет воспринят как 0.
                                                                   #                   аналоговый сигнал от 512-12 до 512+12 не изменит логический уровень.
while True:                                                        # 
  pin4 = gpio.levelRead(4)                                         #   Читаем логический уровень с вывода №4 в переменную «pin4».
  print("Pin_4="+str(pin4)+"\t\t\t Нажмтие ctrl+c для выхода")     #
  sleep(.1)                                                        # * Ждём десятую долю секунды, чтоб не захламлять stdout.
                                                                   #
#  ПРИМЕЧАНИЕ:                                                     #
#  Для проверки работы скетча подключите потенциометр к 4 выводу.  #
#  Чтение логического уровня с выводов сконфигурированных как      #
#  аналоговые входы, позволяет работать с логикой отличной от 3,3В #
#  В этом примере за логическую 1 принимается сигнал > 0,4125 В.   #