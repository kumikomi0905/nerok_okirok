void setup() {
  // put your setup code here, to run once:

}

int mode;

void loop() {
  // put your main code here, to run repeatedly:
 Button(int button_pin, BTN_MODE mode, void*function);


}


modeChangePush(int mode)void{
//デジタルピン？番のスイッチが押された場合にはモード設定に入る
        if(chatteringCut_pullupPin(2)){
            mode++;
            if(3<mode) mode=0;
        }

            
//デジタルピン？番のスイッチが押された場合にはモードチェンジ設定する
        if(mode && chatteringCut_pullupPin(3)){

            switch (mode){
                case 1:
                 
                  break;
                case 2:
                 
                  break;
                case 3:
                  
                  break;
            }
        }
}
