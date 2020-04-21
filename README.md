# Arduino-CryptoBox

Arduino-CryptoBox проект позволяет отображаться данные о цене криптовалюты BTC и ETH, используя данные от https://cryptocompare.com.
Сам девайс собран из комплектующих от Амперка.РУ:
- Iskra Neo https://amperka.ru/product/iskra-neo
- Troyka Slot Shield v2 https://amperka.ru/product/arduino-troyka-slot-shield
- Slot Box https://amperka.ru/product/structor-slot-box
- Светодиод 5 мм (красный и зеленый) https://amperka.ru/product/troyka-5mm-led-module
- Четырёхразрядный индикатор v2 https://amperka.ru/product/troyka-quad-display

Для работы с индикатором необходимо подключить бибиотеку https://github.com/amperka/QuadDisplay2

Для передачи данных используется COM порт, на который с помощью скрипта Python отправляется на Arduino в виде ленты сообщения, которая 
содержит цены и вид цены. Скрипт должен запускать с определенной периодичностью, если цена с прошлой передачи изменилась в большую 
сторону, то будет включаться зеленый светодиод, иначе - красный.

