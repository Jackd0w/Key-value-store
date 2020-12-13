#include <iostream>
using namespace std;

class NameDataSet 
{
    public:
        char first_name[128];
        char second_name[128];
        int credit_card;
};

int main() {
    NameDataSet dns;
    dns.credit_card = 12564;
    cin >> dns.first_name;
    cin >> dns.second_name;
    cout << dns.first_name << "  " << dns.second_name << endl;
    return 0;
}