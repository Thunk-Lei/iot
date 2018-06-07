int pinRelay = 2; //管脚D3连接到继电器模块的信号脚  
  
void setup() {  
  pinMode(pinRelay, OUTPUT); //设置pinRelay脚为输出状态  
}  
  
void loop() {
   digitalWrite(pinRelay, HIGH);//输出HIGH电平,继电器模块闭合  
   delay(2000); //等待5000毫秒  
   digitalWrite(pinRelay, LOW);//输出LOW电平,继电器模块断开  
   delay(5000); //等待8000毫秒  
}
