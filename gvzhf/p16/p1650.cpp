#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, days, travels;
    map<string, int> answer;
    map<string, uint64_t> money_by_name;
    map<string, uint64_t> money_by_city;
    map<string, string> city_by_name;
    map<uint64_t, set<string>> city_by_money;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name, city;
        uint64_t money;
        cin >> name >> city >> money;
        city_by_name[name] = city;
        money_by_name[name] = money;
        city_by_money[money_by_city[city]].erase(city);
        money_by_city[city] += money;
        city_by_money[money_by_city[city]].insert(city);
    }
    cin >> days >> travels;
    int since = 0;
    string max_city = (city_by_money.rbegin()->second.size() == 1) ? *city_by_money.rbegin()->second.begin() : "";
    for (int i = 0; i < travels; i++) {
        int day;
        string name, city;
        cin >> day >> name >> city;
        string ocity = city_by_name[name];
        city_by_money[money_by_city[ocity]].erase(ocity);
        if (!city_by_money[money_by_city[ocity]].size()) city_by_money.erase(money_by_city[ocity]);
        city_by_money[money_by_city[city]].erase(city);
        if (!city_by_money[money_by_city[city]].size()) city_by_money.erase(money_by_city[city]);

        money_by_city[ocity] -= money_by_name[name];
        money_by_city[city] += money_by_name[name];

        city_by_money[money_by_city[ocity]].insert(ocity);
        city_by_money[money_by_city[city]].insert(city);

        city_by_name[name] = city;
        uint64_t max_money = city_by_money.rbegin()->first;
        if (city_by_money[max_money].size() == 1) {
            if (*city_by_money[max_money].begin() != max_city) {
                answer[max_city] += day - since;
                since = day;
                max_city = *city_by_money[max_money].begin();
            }
        } else {
            answer[max_city] += day - since;
            since = day;
            max_city = "";
        }
    }
    answer[max_city] += days - since;
    for (auto it = answer.begin(); it != answer.end(); ++it) {
        if (it->first != "" && it->second) cout << it->first << ' ' << it->second << endl;
    }
    return 0;
}