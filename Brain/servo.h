#pragma once

class servo {

  public:
    void init();
    void write();
    int read();

  public:
    void emergency();
};
