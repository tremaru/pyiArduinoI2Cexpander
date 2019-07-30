//	Библиотека для работы с расширителем выводов: http://iarduino.ru/
//  Версия: 1.0.1
//  Последнюю версию библиотеки Вы можете скачать по ссылке: http://iarduino.ru/
//  Подробное описание функции бибилиотеки доступно по ссылке: https://wiki.iarduino.ru/
//  Библиотека является собственностью интернет магазина iarduino.ru и может свободно использоваться и распространяться!
//  При публикации устройств или скетчей с использованием данной библиотеки, как целиком, так и её частей,
//  в том числе и в некоммерческих целях, просим Вас опубликовать ссылку: http://iarduino.ru
//  Автор библиотеки: Панькин Павел.
//  Если у Вас возникли технические вопросы, напишите нам: shop@iarduino.ru

#ifndef iarduino_I2C_Expander_h																											//
#define iarduino_I2C_Expander_h																											//
																																		//
#include		"iarduino_I2C_Expander_PI.h"																							//	Подключаем файл iarduino_I2C_Matrix_8x8_I2C.h - для работы с шиной I2C		(используя функции структуры iI2C)
#include <string.h>
																																		//
#define			DEF_CHIP_ID1			0x3C																							//	ID линейки чипов - константа для всех чипов Flash (позволяет идентифицировать принадлежность чипа к линейке).
#define			DEF_CHIP_ID2			0xC3																							//	ID линейки чипов - константа для всех чипов Metro (позволяет идентифицировать принадлежность чипа к линейке).
#define			DEF_MODEL				0x07																							//	Идентификатор модели - константа.
//				Адреса регистров модуля:																								//
#define			REG_FLAGS_0				0x00																							//	Адрес регистра флагов управления для чтения.
#define			REG_BITS_0				0x01																							//	Адрес регистра битов  управления для чтения и записи.
#define			REG_FLAGS_1				0x02																							//	Адрес регистра флагов управления для чтения.
#define			REG_BITS_1				0x03																							//	Адрес регистра битов  управления для чтения и записи.
#define			REG_MODEL				0x04																							//	Адрес регистра содержащего номер типа модуля.
#define			REG_VERSION				0x05																							//	Адрес регистра содержащего версию прошивки.
#define			REG_ADDRESS				0x06																							//	Адрес регистра содержащего текущий адрес модуля на шине I2C. Если адрес указан с флагом IF-PIN-ADDRES то адрес установится (и запишется в регистр) только при наличии 1 на входе PIN_ADDRES.
#define			REG_CHIP_ID				0x07																							//	Адрес регистра содержащего ID линейки чипов. По данному ID можно определить принадлежность чипа к линейки iarduino.
#define			REG_FREQUENCY_L			0x08																							//	Адрес регистра частоты ШИМ в Гц (младший байт).
#define			REG_FREQUENCY_H			0x09																							//	Адрес регистра частоты ШИМ в Гц (старший байт).
#define			REG_LEVEL_L				0x0A																							//	Адрес регистра хранящего значение срабатывания битов регистра «REG_DIGITAL» для выводов сконфигурированных как аналоговые входы (младший байт).
#define			REG_LEVEL_H				0x0B																							//	Адрес регистра хранящего значение срабатывания битов регистра «REG_DIGITAL» для выводов сконфигурированных как аналоговые входы (старший байт).
#define			REG_HYSTERESIS_L		0x0C																							//	Адрес регистра хранящего гистерезис (±) уровня регистра «REG_LEVEL» (младший байт).
#define			REG_HYSTERESIS_H		0x0D																							//	Адрес регистра хранящего гистерезис (±) уровня регистра «REG_LEVEL» (старший байт). Пример: «REG_HYSTERESIS»=0x00CD, «REG_LEVEL»=0x07FF, значит «REG_DIGITAL»=0 при ADC <= 0x07FF-0x00CD, «REG_DIGITAL»=1 при ADC >= 0x07FF+0x00CD.
#define			REG_AVERAGING			0x0E																							//	Адрес регистра хранящего коэффициент усреднения показаний АЦП (0-нет...255-макс).
#define			REG_DIRECTION			0x10																							//	Адрес регистра каждый бит которого управляет направлением работы вывода: 0-вход; 1-выход.
#define			REG_TYPE				0x11																							//	Адрес регистра каждый бит которого управляет типом вывода: 0-логический; 1-аналоговый.
#define			REG_PULL_UP				0x12																							//	Адрес регистра каждый установленный бит которого включает внутренний подтягивающий резистор на выводе.
#define			REG_PULL_DOWN			0x13																							//	Адрес регистра каждый установленный бит которого включает внутренний прижимающий   резистор на выводе.
#define			REG_OUT_MODE			0x14																							//	Адрес регистра каждый бит которого управляет режимом работы схемы выхода: 0-двухтактная схема; 1-схема с открытым стоком.
#define			REG_DIGITAL				0x15																							//	Адрес регистра каждый бит которого устанавливает логический уровень на выходе и читает логический уровень со входа (если вывод работает как вход, то запись бита будет проигнорирована).
#define			REG_WRITE_HIGH			0x16																							//	Адрес регистра каждый установленный бит которого приводит к установке того же бита в регистре «REG_DIGITAL».
#define			REG_WRITE_LOW			0x17																							//	Адрес регистра каждый установленный бит которого приводит к сбросу    того же бита в регистре «REG_DIGITAL».
#define			REG_ANALOG				0x18																							//	Адрес регистра аналоговых значений (младший байт вывода 0).
																																		//
#define			BIT_DIR					0x80																							//	Бит массива «arrMode» указывающий на то что вывод сконфигурирован на выход.
#define			BIT_TYP					0x40																							//	Бит массива «arrMode» указывающий на то что вывод сконфигурирован как аналоговый.
#define			BIT_PUP					0x20																							//	Бит массива «arrMode» указывающий на то что вывод подтянут до уровня Vcc.
#define			BIT_PDN					0x10																							//	Бит массива «arrMode» указывающий на то что вывод прижат к уровню GND.
#define			BIT_SCH					0x08																							//	Бит массива «arrMode» указывающий на то что вывод работает по схеме с открытым стоком.
																																		//
#ifndef			LOW																														//	digitalWrite( низкий логический уровень )
#define			LOW						0																								//
#endif																																	//
																																		//
#ifndef			HIGH																													//	digitalWrite( высокий логический уровень )
#define			HIGH					1																								//
#endif																																	//
																																		//
#ifndef			INPUT																													//	pinMode( вывод работает на вход )
#define			INPUT					0																								//
#endif																																	//
																																		//
#ifndef			OUTPUT																													//	pinMode( вывод работает на выход )
#define			OUTPUT					1																								//
#endif																																	//
																																		//
#ifndef			DIGITAL																													//	pinMode( цифровой вывод )
#define			DIGITAL					2																								//
#endif																																	//
																																		//
#ifndef			ANALOG																													//	pinMode( аналоговый вывод )
#define			ANALOG					3																								//
#endif																																	//
																																		//
#ifndef			SERVO																													//	pinMode( вывод для сервопривода )
#define			SERVO					4																								//
#endif																																	//
																																		//
#ifndef			OUT_PUSH_PULL																											//	pinOutScheme( использовать двухтактную схему выхода )
#define			OUT_PUSH_PULL			5																								//
#endif																																	//
																																		//
#ifndef			OUT_OPEN_DRAIN																											//	pinOutScheme( использовать схему выхода с открытым стоком )
#define			OUT_OPEN_DRAIN			6																								//
#endif																																	//
																																		//
#ifndef			PULL_UP																													//	pinPull( включить внутренний подтягивающий резистор )
#define			PULL_UP					7																								//
#endif																																	//
																																		//
#ifndef			PULL_DOWN																												//	pinPull( включить внутренний прижимающий резистор )
#define			PULL_DOWN				8																								//
#endif																																	//
																																		//
#ifndef			PULL_NO																													//	pinPull( без внутренних резисторов )
#define			PULL_NO					0xFF																							//
#endif																																	//
																																		//
#ifndef			ALL_PIN																													//	Выбор всех выводов для функций: pinMode(), pinPull(), pinOutScheme(), digitalWrite(), digitalRead(), analogWrite(), levelRead(), servoAttach(), servoWrite(), servoWriteMicroseconds().
#define			ALL_PIN					0xFF																							//	Единственная функция которой нельзя указывать све выводы: analogRead()
#endif																																	//
																																		//
class iarduino_I2C_Expander{																											//
	public:																																//
	/**	Конструктор класса **/																											//
		iarduino_I2C_Expander						(uint8_t address=0){																//	Конструктор класса													(Параметр: адрес расширителя на шине I2C, если не указан (=0), то адрес будет определён).
													if(address>0x7F){ address>>=1; }													//	Корректируем адрес, если он указан с учётом бита RW.
							valAddrTemp		=		address;																			//	Сохраняем переданный адрес расширителя.
							objI2C			=		new iarduino_I2C;																	//	Переопределяем указатель objI2C на объект производного класса iarduino_I2C.
		}																																//
	/**	Пользовательские функции **/																									//
		bool				begin					(void														);						//	Объявляем  функцию инициализации расширителя						(Параметр:  отсутствует).
		bool				changeAddress			(uint8_t													);						//	Объявляем  функцию смены адреса модуля на шине I2C					(Параметр:  новый адрес модуля).
		bool				reset					(void														);						//	Объявляем  функцию перезагрузки модуля								(Параметр:  отсутствует).
		uint8_t				getAddress				(void														){ return valAddr;	}	//	Определяем функцию возвращающую текущий адрес модуля на шине I2C	(Параметр:  отсутствует).
		uint8_t				getVersion				(void														){ return valVers;	}	//	Определяем функцию возвращающую текущую версию прошивки модуля		(Параметр:  отсутствует).
		void				pinMode					(uint8_t , uint8_t , uint8_t=DIGITAL							);						//	Объявляем  функцию конфигурирования вывода							(Параметры: номер вывода, направление работы, [тип сигнала]).
		void				pinPull					(uint8_t , uint8_t											);						//	Объявляем  функцию подключения к выводу внутренних резисторов 		(Параметры: номер вывода, резистор).
		void				pinOutScheme			(uint8_t , uint8_t											);						//	Объявляем  функцию выбора схемы выхода 								(Параметры: номер вывода, схема).
		void				digitalWrite			(uint8_t , uint8_t											);						//	Объявляем  функцию установки на выводе логичекого уровня	 		(Параметры: номер вывода, логический уровень).
		uint8_t				digitalRead				(uint8_t 													);						//	Объявляем  функцию чтения логичекого уровня с вывода		 		(Параметр:  номер вывода).
		void				analogWrite				(uint8_t , uint16_t											);						//	Объявляем  функцию установки на выводе аналогового уровня	 		(Параметры: номер вывода, аналоговый уровень).
		uint16_t			analogRead				(uint8_t													);						//	Объявляем  функцию чтения аналогового уровня с вывода		 		(Параметр:  номер вывода).
		void				analogAveraging			(uint8_t 													);						//	Объявляем  функцию установки коэффициента усреднения показаний АЦП	(Параметры: коэффициент).
		void				levelWrite				(uint16_t													);						//	Объявляем  функцию установки аналогового уровня для levelRead()		(Параметр:  аналоговый уровень).
		bool				levelRead				(uint8_t 													);						//	Объявляем  функцию чтения логичекого уровня с аналогового вывода	(Параметры: номер вывода).
		void				levelHyst				(uint16_t													);						//	Объявляем  функцию установки гистерезиса для функции levelRead()	(Параметр:  гистерезис).
		void				freqPWM					(uint16_t													);						//	Объявляем  функцию установки частоты ШИМ							(Параметр:  частота в Гц).
		void				servoAttach				(uint8_t , uint16_t , uint16_t , int16_t=0 , int16_t=180	);						//	Объявляем  функцию конфигурирования вывода для сервопривода			(Параметры: номер вывода, минимальная ширина импульса, максимальная ширина импульса, [минимальный угол, максимальный угол]).
		void				servoWrite				(uint8_t , int16_t											);						//	Объявляем  функцию установки угла поворота сервопривода		 		(Параметры: номер вывода, угол поворота).
		void				servoWriteMicroseconds	(uint8_t , uint16_t											);						//	Объявляем  функцию установки длительности импульсов для сервопривода(Параметры: номер вывода, длительность импульсов).
    void        changeBus(const char*);
    long        map(long, long, long, long, long);
	private:																															//
	/**	Внутренние переменные **/																										//
		uint8_t				valAddrTemp		=		0;																					//	Определяем переменную для хранения адреса модуля на шине I2C который был указан, но не был проверен.
		uint8_t				valAddr			=		0;																					//	Определяем переменную для хранения адреса модуля на шине I2C.
		uint8_t				valVers			=		0;																					//	Определяем переменную для хранения версии прошивки модуля.
		uint16_t			valFreqPWM;																									//	Объявляем  переменную для хранения установленной частоты ШИМ.
		uint8_t				data[16];																									//	Объявляем  массив     для хранения получаемых/передаваемых данных.
		uint8_t				arrMode[8];																									//	Объявляем  массив     для хранения режима работы выводов			(Каждый байт массива отвечает за один вывод и состоит из битов BIT_DIR, BIT_TYP, BIT_PUP, BIT_PDN, BIT_SCH).
		int16_t				arrServ[4][4];																								//	Объявляем  массив     для хранения соотношений длительности импульсов к углу поворота сервопривода на 0...4 выводе.
		iarduino_I2C_BASE*	objI2C;																										//	Объявляем  указатель  на  объект полиморфного класса iarduino_I2C_BASE, но в конструкторе данного класса этому указателю будет присвоена ссылка на производный класс iarduino_I2C.
	/**	Внутренние функции **/																											//
		bool				_readBytes				(uint8_t	, uint8_t										);						//	Объявляем  функцию чтения данных в  массив  data					(Параметры:  номер первого регистра, количество байт).
		bool				_writeBytes				(uint8_t	, uint8_t, uint8_t=0							);						//	Объявляем  функцию записи данных из массива data					(Параметры:  номер первого регистра, количество байт, номер первого элемента массива data).
};																																		//
																																		//
#endif																																	//
