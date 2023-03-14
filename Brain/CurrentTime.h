#pragma once

class CurrentTime {

  private:
    int espNumber;            //espのピン番号
    int realTime;             //RTCのピン番号


  public:
    int Time_Check();
    void setrealTime();
    int send_CurrentTime();

}



#endif
