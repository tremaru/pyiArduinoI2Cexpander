# distutils: language = c++
# cython: language_level = 3
#encoding = utf-8
DEF_CHIP_ID1 = 0x3C
DEF_CHIP_ID2 = 0xC2
DEF_MODEL = 0x07
#Адреса регистров модуля:
REG_FLAGS_0 = 0x00
REG_BITS_0 = 0x01
REG_FLAGS_1 = 0x02
REG_BITS_1 = 0x03
REG_MODEL = 0x04
REG_VERSION = 0x05
REG_ADDRESS = 0x06
REG_CHIP_ID = 0x07
REG_FREQUENCY_L = 0x08
REG_FREQUENCY_H = 0x09
REG_LEVEL_L = 0x0A
REG_LEVEL_H = 0x0B
REG_HYSTERESIS_L = 0x0C
REG_HYSTERESIS_H = 0x0D
REG_AVERAGING = 0x0E
REG_DIRECTION = 0x10
REG_TYPE = 0x11
REG_PULL_UP = 0x12
REG_PULL_DOWN = 0x13
REG_OUT_MODE = 0x14
REG_DIGITAL = 0x15
REG_WRITE_HIGH = 0x16
REG_WRITE_LOW = 0x17
REG_ANALOG = 0x18
BIT_DIR = 0x80
BIT_TYP = 0x40
BIT_PUP = 0x20
BIT_PDN = 0x10
BIT_SCH = 0x08
LOW = 0
HIGH = 1
INPUT = 0
OUTPUT = 1
DIGITAL = 2
ANALOG = 3
SERVO = 4
OUT_PUSH_PULL = 5
OUT_OPEN_DRAIN = 6
PULL_UP = 7
PULL_DOWN = 8
PULL_NO = 0xFF
ALL_PIN = 0xFF

from iarduino_I2C_Expander cimport iarduino_I2C_Expander

cdef class pyiArduinoI2Cexpander:
	cdef iarduino_I2C_Expander c_expander

	def __cinit__(self, address=None):
		if address is not None:
			self.c_expander = iarduino_I2C_Expander(address)
			self.c_expander.begin()
		else:
			self.c_expander = iarduino_I2C_Expander()
			self.c_expander.begin()

	def begin(self):
		return self.c_expander.begin()

	def changeAddress(self, unsigned char newAddr):
		return self.c_expander.changeAddress(newAddr)

	def reset(self):
		return self.c_expander.reset()

	def getAddress(self):
		return self.c_expander.getAddress()

	def getVersion(self):
		return self.c_expander.getVersion()

	def pinMode(self, unsigned char pin, unsigned char io_dir, unsigned char io_type=DIGITAL):
		if io_type is not DIGITAL:
			self.c_expander.pinMode(pin, io_dir, io_type)
		else:
			self.c_expander.pinMode(pin, io_dir, DIGITAL)

	def pinPull(self, unsigned char pin, unsigned char pull):
		self.c_expander.pinPull(pin, pull)

	def pinOutScheme(self, unsigned char pin, unsigned char mode):
		self.c_expander.pinOutScheme(pin, mode)

	def digitalWrite(self, unsigned char pin, unsigned char level):
		self.c_expander.digitalWrite(pin, level)

	def digitalRead(self, unsigned char pin):
		return self.c_expander.digitalRead(pin)

	def analogWrite(self, unsigned char pin, unsigned short level):
		self.c_expander.analogWrite(pin, level)

	def analogRead(self, unsigned char pin):
		return self.c_expander.analogRead(pin)

	def analogAveraging(self, unsigned char coefficient):
		self.c_expander.analogAveraging(coefficient)

	def levelWrite(self, unsigned short level):
		self.c_expander.levelWrite(level)

	def levelRead(self, unsigned char pin):
		return self.c_expander.levelRead(pin)

	def levelHyst(self, unsigned short hysteresis):
		self.c_expander.levelHyst(hysteresis)

	def freqPWM(self, unsigned short frequency):
		self.c_expander.freqPWM(frequency)

	def servoAttach(self, unsigned char pin, unsigned short width_min, unsigned short width_max, unsigned short angle_min, unsigned short angle_max):
		self.c_expander.servoAttach(pin, width_min, width_max, angle_min, angle_max)

	def servoWrite(self, unsigned char pin, unsigned short angle):
		self.c_expander.servoWrite(pin, angle)

	def servoWriteMicroseconds(self, unsigned char pin, unsigned short width):
		self.c_expander.servoWriteMicroseconds(pin, width)
