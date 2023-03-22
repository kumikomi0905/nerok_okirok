#pragma once

class CurrentTime
{
  private:
   int espNumber;
   int realTime;
   
   public:
   int Time_Check();
   void setrealTime();
   int send_CurrentTime();
   
};   
