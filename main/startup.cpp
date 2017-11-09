

#include <iostream>


#include "TestPort.h"
#include "CanBusPort.h"
#include "Cia402device.h"
#include "CiA301CommPort.h"

using namespace std;

int main(int argc, char *argv[])
{


    ///prepare ports
    /// Open a port address with a PortBase Object
    //TestPort port;
    CanBusPort port;

    ///Then instantiate a 301 communications object for that address
    //CiA301CommPort coms(port.getPortFileDescriptor());

    ///Create a joint and give a canopen id, and a 301port (by constructor)
    CiA402Device j1(1,port.getPortFileDescriptor());

    ///Check the status of the device
    //j1.CheckStatus();
    j1.SwitchOn();
    j1.FlushBuffer();

    double pos= j1.GetPosition();
    cout << "pos: " << pos << endl;


    return 0;
}