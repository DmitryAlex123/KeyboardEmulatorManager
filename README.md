# KeyboardEmulatorManager
Программа управления эмулятором клавиатуры, а также приемом данных по локальной сети.

При запуске инициализирует соединение с эмулятором клавиатуры.
Слушает порт 1010, по принятии какого либо байта исполнит команду отправки массива данных на эмулятор клавиатуры.

НЕ ЗАБУДЬТЕ УКАЗАТЬ ДОСТУП К libusb-1.0 В СВОЙСТВАХ ПРОЕКТА

Объяснение что к чему: https://youtu.be/uVVuiN60hYE (24:40)
