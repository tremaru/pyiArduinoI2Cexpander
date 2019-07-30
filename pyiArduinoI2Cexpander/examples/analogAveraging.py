#/ Данный пример меняет усреднение АЦП при чтении аналоговых данных.# * Строки со звёздочкой являются необязательными.
                                                                    #
from pyiArduinoI2Cexpander import *                                 #   Подключаем библиотеку для работы с расширителем выводов.
from time import sleep
gpio = pyiArduinoI2Cexpander(0x09)                                  #   Объявляем объект gpio для работы с функциями и методами библиотеки iarduino_I2C_Expander, указывая адрес модуля на шине I2C.
                                                                    #   Если объявить объект без указания адреса (iarduino_I2C_Expander gpio;), то адрес будет найден автоматически.
gpio.analogAveraging(255)                                           #   Указываем максимальный коэффициент усреднения показаний АЦП.
gpio.pinMode(4, INPUT, ANALOG)                                      # * Конфигурируем вывод 4 на работу в качестве аналогового входа.
                                                                    #
while True:                                                         # 
  pin4 = gpio.analogRead(4)                                         #   Читаем аналоговый уровень с вывода №4 в переменную «pin4».
  print("Pin_4="+str(pin4)+".\t Для выхода нажмите ctrl+c")         #
  sleep(.1)                                                         # * Ждём десятую долю секунды, чтоб не захламлять монитор последовательного порта.
                                                                    #
#   ПРИМЕЧАНИЕ:                                                     #
#   Для проверки работы скетча подключите потенциометр к 4 выводу.  #
#   Коэффициент усреднения АЦП задаётся функцией analogAveraging()  #
#   которая в качестве аргумента принимает значение от 0 до 255.    #
#   По умолчанию 127. Усреднение применяется для всех выводов.      #
#   Чем выше коэффициент усреднения, тем плавнее будут меняться     #
#   показания считанных аналоговых уровней.                         #
#   Для отключения усреднения укажите значение 0 или 1.             #