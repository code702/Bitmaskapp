//Learning to work with bits
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool doesHostBelongToIPv4(unsigned int ipv4, unsigned int host, unsigned int prefix)
{
    auto subnetMask = 0xFFFFFFFF << (32 - prefix);
    return (ipv4 & subnetMask) == (host & subnetMask);
}

vector<unsigned int> strToVectorIpv4(string strIpv4)
{
    string firstIpv4Str{};
    string secondIpv4Str{};
    string thirdIpv4Str{};
    string fourthIpv4Str{};
    string prefStr{};

    auto iterFirstPeriod = find(begin(strIpv4), end(strIpv4), '.');
    copy(begin(strIpv4), end(strIpv4), back_inserter(firstIpv4Str));
    unsigned int firstIPv4 = stoi(firstIpv4Str);

    auto iterSecondPeriod = find(iterFirstPeriod + 1, end(strIpv4), '.');
    copy(iterFirstPeriod + 1, iterSecondPeriod, back_inserter(secondIpv4Str));
    unsigned int secondIPv4 = stoi(secondIpv4Str);

    auto iterThirdPeriod = find(iterSecondPeriod + 1, end(strIpv4), '.');
    copy(iterSecondPeriod + 1, iterThirdPeriod, back_inserter(thirdIpv4Str));
    unsigned int thirdIPv4 = stoi(thirdIpv4Str);

    auto iterSlash = find(iterThirdPeriod + 1, end(strIpv4), '/');
    copy(iterThirdPeriod + 1, iterSlash, back_inserter(fourthIpv4Str));
    unsigned int fourthIPv4 = stoi(fourthIpv4Str);

    copy(iterSlash + 1, end(strIpv4), back_inserter(prefStr));
    unsigned int prefix = stoi(prefStr);

    vector<unsigned int> vect{ firstIPv4, secondIPv4, thirdIPv4, fourthIPv4, prefix };

    return vect;
}

vector<unsigned int> strToVectorHost(string strHost)
{
    string firstHostStr{};
    string secondHostStr{};
    string thirdHostStr{};
    string fourthHostStr{};

    auto iterFirstPeriod = find(begin(strHost), end(strHost), '.');
    copy(begin(strHost), end(strHost), back_inserter(firstHostStr));
    unsigned int firstHost = stoi(firstHostStr);

    auto iterSecondPeriod = find(iterFirstPeriod + 1, end(strHost), '.');
    copy(iterFirstPeriod + 1, iterSecondPeriod, back_inserter(secondHostStr));
    unsigned int secondHost = stoi(secondHostStr);

    auto iterThirdPeriod = find(iterSecondPeriod + 1, end(strHost), '.');
    copy(iterSecondPeriod + 1, iterThirdPeriod, back_inserter(thirdHostStr));
    unsigned int thirdHost = stoi(thirdHostStr);

    copy(iterThirdPeriod + 1, end(strHost), back_inserter(fourthHostStr));
    unsigned int fourthHost = stoi(fourthHostStr);

    vector<unsigned int> vect{ firstHost, secondHost, thirdHost, fourthHost };

    return vect;
}

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cout << "Correct using: " << endl
            << "ipv4app <Ipv4/prefix> <host IP>" << endl;
        return 0;
    }

    string strIpv4 = argv[1];
    string strHost = argv[2];

    vector<unsigned int> vectIpv4{ strToVectorIpv4(strIpv4) };
    unsigned int firstIPv4 = vectIpv4.at(0);
    unsigned int secondIPv4 = vectIpv4.at(1);
    unsigned int thirdIPv4 = vectIpv4.at(2);
    unsigned int fourthIPv4 = vectIpv4.at(3);
    unsigned int prefix = vectIpv4.at(4);

    vector<unsigned int> vectHost{ strToVectorHost(strHost) };
    unsigned int firstHost = vectHost.at(0);
    unsigned int secondHost = vectHost.at(1);
    unsigned int thirdHost = vectHost.at(2);
    unsigned int fourthHost = vectHost.at(3);

    unsigned int resultIpv4 = (firstIPv4 << 24) | (secondIPv4 << 16) | (thirdIPv4 << 8) | fourthIPv4;
    unsigned int resultHost = (firstHost << 24) | (secondHost << 16) | (thirdHost << 8) | fourthHost;

    if (doesHostBelongToIPv4(resultIpv4, resultHost, prefix))
    {
        cout << "The provided host belongs to the IPv4." << endl;
    }
    else
    {
        cout << "The provided host doesn`t belong to the IPv4." << endl;
    }

    return 0;
}
