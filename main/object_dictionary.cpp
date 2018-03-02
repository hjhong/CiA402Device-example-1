

#include <iostream>
#include <math.h>

#include "TestPort.h"
#include "CanBusPort.h"
#include "Cia402device.h"
#include "CiA301CommPort.h"
#include "SocketCanPort.h"


using namespace std;

int main(int argc, char *argv[])
{

    ///prepare ports
    /// Open a port address with a PortBase Object
    //TestPort port;
    //CanBusPort port;
    SocketCanPort p1("can0");
    uint16_t status;

    ///Then instantiate a 301 communications object for that address
    //CiA301CommPort coms(port.getPortFileDescriptor());

    ///Create a joint and give a canopen id, and a 301port (by constructor)
    //CiA402Device j1(2,&p1);
    CiA301CommPort c1(&p1,2);

    const vector<uint8_t> address={0x7E,0x60};
    const vector<uint8_t> value={0xC0};
    cout<<"num"<<c1.WriteSDO(address,value)<<endl;
          //cout<<c1.WriteSDO(address,value)<<endl;








    return 0;

}
