//Learning to work with bits
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool doesHostBelongToIPv4(unsigned int ipv4, unsigned int host, unsigned int prefix)
{
    auto subnetMask = 0xFFFFFFFF << (32 - prefix);
    return (ipv4 & subnetMask) == (host & subnetMask);
}

unsigned int ipv4StrToUint(const char* strIpv4, unsigned int& prefix)
{
    unsigned int firstIPv4{}, secondIPv4{}, thirdIPv4{}, fourthIPv4{};
    sscanf_s(strIpv4, "%d.%d.%d.%d/%d", &firstIPv4, &secondIPv4, &thirdIPv4, &fourthIPv4, &prefix);
    return (firstIPv4 << 24) | (secondIPv4 << 16) | (thirdIPv4 << 8) | fourthIPv4;
}

unsigned int hostStrToUint(const char* strHost)
{
    unsigned int firstHost{}, secondHost{}, thirdHost{}, fourthHost{};
    stringstream sHost(strHost);
    char period{};
    sHost >> firstHost >> period >> secondHost >> period >> thirdHost >> period >> fourthHost;
    return (firstHost << 24) | (secondHost << 16) | (thirdHost << 8) | fourthHost;
}

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cout << "Correct using: " << endl
            << "ipv4app <Ipv4/prefix> <host IP>" << endl;
        return 0;
    }

    unsigned int  prefix{};
    unsigned int ipv4Result = ipv4StrToUint(argv[1], prefix);

    if (doesHostBelongToIPv4(ipv4Result, hostStrToUint(argv[2]), prefix))
    {
        cout << "The provided host belongs to the IPv4." << endl;
    }
    else
    {
        cout << "The provided host doesn`t belong to the IPv4." << endl;
    }

    return 0;
}
