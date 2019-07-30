# Данный пример позволяет задавать параметры сервопривода.         # * Строки со звёздочкой являются необязательными.
                                                                   #
from pyiArduinoI2Cexpander import *                                #   Подключаем библиотеку для работы с расширителем выводов.
from time import sleep                                             #
gpio = pyiArduinoI2Cexpander(0x09)                                 #   Объявляем объект gpio для работы с функциями и методами библиотеки iarduino_I2C_Expander, указывая адрес модуля на шине I2C.
                                                                   #
gpio.pinMode(0, OUTPUT, SERVO)                                     # * Конфигурируем вывод 0 на работу в качестве выхода для сервопривода.
gpio.pinMode(1, OUTPUT, SERVO)                                     # * Конфигурируем вывод 1 на работу в качестве выхода для сервопривода.
gpio.pinMode(2, OUTPUT, SERVO)                                     # * Конфигурируем вывод 2 на работу в качестве выхода для сервопривода.
gpio.pinMode(3, OUTPUT, SERVO)                                     # * Конфигурируем вывод 3 на работу в качестве выхода для сервопривода.
gpio.servoAttach(0,  500, 2500,    0,  180)                        #   Определяем параметры серпопривода, с углом поворота 180°, подключённого к выводу 0.
gpio.servoAttach(1,  900, 2100,    0,   90)                        #   Определяем параметры серпопривода, с углом поворота 90°,  подключённого к выводу 1.
gpio.servoAttach(2, 1320, 1600, -100, +100)                        #   Определяем параметры серпопривода, постоянного вращения,  подключённого к выводу 2.
gpio.servoAttach(3, 1100, 1700, -100, +100)                        #   Определяем параметры серпопривода, постоянного вращения,  подключённого к выводу 3.
                                                                   #   Назначение аргументов функции servoAttach() см. внизу скетча.
                                                                   #
while True:                                                        #
  gpio.servoWrite(0,   0)                                          #   Поворачиваем сервопривод в минимальный угол.
  gpio.servoWrite(1,   0)                                          #   Поворачиваем сервопривод в минимальный угол.
  gpio.servoWrite(2, -60)                                          #   Заставляем медленно вращаться сервопривод против часовой стрелки.
  gpio.servoWrite(3, -60)                                          #   Заставляем медленно вращаться сервопривод против часовой стрелки.
  sleep(.5)                                                        #   Ждём пол секунды.
  gpio.servoWrite(0,  90)                                          #   Поворачиваем сервопривод в среднее положение.
  gpio.servoWrite(1,  45)                                          #   Поворачиваем сервопривод в среднее положение.
  gpio.servoWrite(2,   0)                                          #   Останавливаем сервопривод постоянного вращения.
  gpio.servoWrite(3,   0)                                          #   Останавливаем сервопривод постоянного вращения.
  sleep(.5)                                                        #   Ждём пол секунды.
  gpio.servoWrite(0, 180)                                          #   Поворачиваем сервопривод в максимальный угол.
  gpio.servoWrite(1,  90)                                          #   Поворачиваем сервопривод в максимальный угол.
  gpio.servoWrite(2, +60)                                          #   Заставляем медленно вращаться сервопривод по часовой стрелке.
  gpio.servoWrite(3, +60)                                          #   Заставляем медленно вращаться сервопривод по часовой стрелке.
  sleep(.5)                                                        #   Ждём пол секунды.
                                                                   #
#  ПРИМЕЧАНИЕ:                                                     #
#  Для проверки работы скетча подключите сервоприводы к выводам.   #
#  Параметры сервоприводов задаются из их datasheet.               #
#  Функция servoAttach() принимает до 5 аргументов:                #
#  1 - номер вывода к которому подключён сервопривод.              #
#  2 - минимальная  ширина импульсов ШИМ в микросекундах.          #
#  3 - максимальная ширина импульсов ШИМ в микросекундах.          #
#  4 - угол или значение соответствующее минимальной  ширине имп.  #
#  5 - угол или значение соответствующее максимальной ширине имп.  #
#  ПРИМЕР:                                                         #
#  Сервопривод с углом поворота в 45° подключён к 3 выводу модуля. #
#  При 0° ширина ШИМ = 600мкс, при 45° ширина ШИМ = 2300мкс.       #
#  gpio.servoAttach(3, 600, 2300, 0, 45)                           #
#  gpio.servoWrite(3, угол от 0 до 45° )                           #

