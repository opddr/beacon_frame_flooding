#include <iostream>
#include <tins/tins.h>
#include <unistd.h>


using namespace std;
using namespace Tins;



int main(int argc,char **argv)
{
	if(argc != 2)
	{
		printf("USAGE : ./test1 <interface>");
		exit(1);
	}

	Dot11Beacon beacon1,beacon2,beacon3;

	beacon1.addr1(Dot11::BROADCAST);
	beacon1.addr2("00:01:02:03:04:05");
	beacon1.addr3(beacon1.addr2());
	beacon1.ssid("strange ap 1");
	beacon1.ds_parameter_set(8);
	beacon1.supported_rates({ 1.0f, 5.5f, 11.0f });
	beacon1.rsn_information(RSNInformation::wpa2_psk());

	
	beacon2.addr1(Dot11::BROADCAST);
	beacon2.addr2("06:07:08:09:0a:0b");
	beacon2.addr3(beacon2.addr2());
	beacon2.ssid("strange ap 2");
	beacon2.ds_parameter_set(8);
	beacon2.supported_rates({ 1.0f, 5.5f, 11.0f });
	beacon2.rsn_information(RSNInformation::wpa2_psk());


	beacon3.addr1(Dot11::BROADCAST);
	beacon3.addr2("0:10:20:30:40:50");
	beacon3.addr3(beacon3.addr2());
	beacon3.ssid("strange ap ");
	beacon3.ds_parameter_set(8);
	beacon3.supported_rates({ 1.0f, 5.5f, 11.0f });
	beacon3.rsn_information(RSNInformation::wpa2_psk());



	RadioTap tap1,tap2,tap3;
	tap1.inner_pdu(beacon1);
	tap2.inner_pdu(beacon2);
	tap3.inner_pdu(beacon3);


	PacketSender sender;

	
	NetworkInterface iface(argv[1]);
	while(1)
	{	
		usleep(10000);
		sender.send(tap1,iface);
		sender.send(tap2,iface);
		sender.send(tap3,iface);		
	}

}
