#include <bits/stdc++.h>
using namespace std;

int main()
{
    string name;
    cout << "Please insert your's input file (don't type .txt): ";
    cin >> name;
    fstream incheck;
    incheck.open(name + ".txt");
    while (!incheck.is_open())
    {
        cout << "There was no this file, reinsert it again!!\n";
        cout << "Please insert your's input file (don't type .txt): ";
        cin >> name;
        incheck.close();
        incheck.open(name + ".txt");
    }

    ifstream input(name + ".txt");
    string oname;
    oname = name + " out_0";

    while (1)
    {
        fstream check;
        check.open(oname + ".txt");
        if (!check.is_open())
        {
            break;
        }

        string tmp;
        int pos = oname.find("_", 0);
        tmp = oname.substr(pos + 1, oname.size());
        int now = atoi(tmp.c_str());
        now++;
        tmp = to_string(now);
        oname = oname.substr(0, pos + 1);
        oname = oname + tmp;
        check.close();
    }

    ofstream output(oname + ".txt");
    srand(time(NULL));
    vector<string> n;
    string tmp;
    while (input >> tmp)
    {
        n.push_back(tmp);
    }
    int a = n.size();
    vector<int> same_check;
    for (int i = 0; i < 5; i++)
    {
        int output_index = rand() % a;

        for (int j = 0; j < same_check.size(); j++)
        {
            if (same_check[j] == output_index)
            {
                output_index = rand() % a;
                j = -1;
            }
        }
        same_check.push_back(output_index);
        output << n[output_index] << " ";
    }
    cout << "\n";
    input.close();
    output.close();
    incheck.close();
    return 0;
}