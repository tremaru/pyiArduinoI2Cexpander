#  Данный пример читает аналоговый уровень с вывода модуля.
                                        # $ Строки со знаком $ являются необязательными.
                                        #
from pyiArduinoI2Cexpander import *     #   Подключаем библиотеку для работы с расширителем выводов.
from time import sleep                  #   Подключаем функцию sleep из модуля time 
ext = pyiArduinoI2Cexpander(0x08)       #   Объявляем объект ext для работы с функциями
                                        #    модуля pyiArduinoI2Cexpander.
sleep(.5)                               # 
ext.pinMode(4, INPUT, ANALOG)           # $ Конфигурируем вывод 4 на работу в качестве аналогового входа.
                                        #
while True:                             # 
  pin4 = ext.analogRead(4);             #   Читаем аналоговый уровень с вывода №4 в переменную «pin4».
  print("Pin_4="+str(pin4)              # 
        +".\tДля выхода "               #
        "нажмите ctrl+c")               #   Выводим значени в stdout
  sleep(.1)                             # $ Ждём десятую долю секунды, чтоб не захламлять stdout.
                                                                    #
#   ПРИМЕЧАНИЕ:                                                     #
#   Для проверки работы скетча подключите потенциометр к 4 выводу.  #
#   Аналоговый уровень считывается из АЦП модуля и может принимать  #
#   значение от 0 (0В) до 4095 (3,3В).                              #
#   По умолчанию, значения АЦП усредняются, это подавляет скачки    #
#   показаний но увеличивает их инерционность, для отключения       #
#   или изменения усреднения обратитесь к функции analogAveraging() #
