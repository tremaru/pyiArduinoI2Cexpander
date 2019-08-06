# Данный пример ищет модули на шине и выводит информацию о них.
                                          #
import smbus                              # Подключаем модуль шины smbus(i2c)
choices = {                               # Создаём список устройств
0x01: "кнопкой",                          # Если значение 1, значит это кнопка.
0x02: "светодиодом",                      # Если значение 2, значит это RGB светодиод.
0x03: "потенциометром",                   # Если значение 3, значит это потенциометр.
0x04: "звукоизлучателем",                 # Если значение 4, значит это звукоизлучатель.
0x05: "датчиком DHT",                     # Если значение 5, значит это датчик владности и температуры.
0x06: "датчиком света",                   # Если значение 6, значит это датчик света.
0x07: "расширителем выводов",             # Если значение 7, значит это датчик света.
0x08: "LED матрицей",                     # Если значение 8, значит это светодиодная матрица.
0x0A: "реле на 2 канала",                 # Если значение A, значит это электромеханическое реле на 2 канала.
0x0B: "реле на 4 канала",                 # Если значение B, значит это твердотельное реле на 4 канала.
0x0C: "силовым ключём 4 N",               # Если значение C, значит это силовой ключ на 4 N-канала.
0x0D: "силовым ключём 4 P",               # Если значение D, значит это силовой ключ на 4 P-канала.
0x0E: "силовым ключём 4 N",               # Если значение E, значит это силовой ключ на 4 N-канала, с измерением тока.
0x0F: "силовым ключём 4 P"                # Если значение F, значит это силовой ключ на 4 P-канала, с измерением тока.
}                                         #
try:                                      #
  bus = smbus.SMBus(1)                    # Пробуем открыть файл шины i2c
except FileNotFoundError:                 # Если файл не найден
  print("Шина i2c не включена. Запустите\
        `raspi-config` и включите шину.") # Выводим сообщение в stdout
except:                                   # Если любая другая ошибка
  print("неизвестная ошибка")             # Выводим сообщение в stdout
else:                                     # Если ошибок не найдено
  for i in range(7, 127):                 # Проходим по всем доступным адресам на шине I2C ...
    try:                                  # Пробуем вывести адрес
      bus.write_quick(i)                  # устройства на шину
    except OSError:                       # Если устройства с текущим адресом не на шине
      continue                            # Возвращаемся в начало цикла for со следующим адресом
    except:                               # Если любая другая ошибка
      print("неизвестная ошибка")         # Выводим сообщение в stdout
    else:                                 # Если устройство найдено
      print("Устройство с адресом\
            %#.2X" % i, end='')           # Выводим адрес в stdout
      k = bus.read_i2c_block_data(i, 0x04)                # Читаем регистры, начиная с 4
      if k[2]>>1 == i and (k[3]==0xc3 
                          or k[3]==0x3c): # Если значение второго элемента массива k совпадает с адресом устройства, а в третьем элементе хранится идентификатор 0xC3 (модуль Metro), или 3С (модуль Flash), то ...
        print(" является ", end='')                       # Выводим текст в stdout
        model = choices.get(k[0], 
              "неизвестным модулем")      # Cравниваем модель модуля со списком, если ничего не совпало - записываем в model строку по умолчанию
        print("%s с версией прошивки %d."
               % (model, k[1]))           # Выводим модель и версию в stdout
      else:                               # Выводим текст, если устройство не опознано 
        print(" не опознано")             # или на шине два устроойства с одним адресом
