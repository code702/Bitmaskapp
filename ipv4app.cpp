//Learning to work with bits
#include <iostream>

using namespace std;

bool doesHostBelongToIPv4(unsigned int ipv4, unsigned int host, unsigned int mask)
{
    auto subnetMask = 0xFFFFFFFF << (32 - mask);
    ipv4 &= subnetMask;
    host &= subnetMask;
    return ipv4 == host;
}

int main()
{
    unsigned int firstIPv4{}, secondIPv4{}, thirdIPv4{}, fourthIPv4{}, mask{};
    unsigned int firstHost{}, secondHost{}, thirdHost{}, fourthHost{};
    cout << "IPv4. Please enter first octet:";
    cin >> firstIPv4;
    cout << "IPv4. Please enter second octet:";
    cin >> secondIPv4;
    cout << "IPv4. Please enter third octet:";
    cin >> thirdIPv4;
    cout << "IPv4. Please enter fourth octet:";
    cin >> fourthIPv4;
    cout << "IPv4. Please enter mask:";
    cin >> mask;

    cout << "Host. Please enter first octet:";
    cin >> firstHost;
    cout << "Host. Please enter second octet:";
    cin >> secondHost;
    cout << "Host. Please enter third octet:";
    cin >> thirdHost;
    cout << "Host. Please enter fourth octet:";
    cin >> fourthHost;

    unsigned int resultIpv4 = (firstIPv4 << 24) + (secondIPv4 << 16) + (thirdIPv4 << 8) + fourthIPv4;
    unsigned int resultHost = (firstHost << 24) + (secondHost << 16) + (thirdHost << 8) + fourthHost;

    if (doesHostBelongToIPv4(resultIpv4, resultHost, mask))
    {
        cout << "The provided host belongs to the IPv4." << endl;
    }
    else
    {
        cout << "The provided host doesn`t belong to the IPv4." << endl;
    }

    return 0;
}
